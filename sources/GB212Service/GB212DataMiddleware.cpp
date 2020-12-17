#include "GB212DataMiddleware.h"
#include <json.h>
#include "pub.h"
#include "ConfigY.h"
#include "ConfigYWriter.h"
#include <my_log.h>

GB212DataMiddleware::GB212DataMiddleware()
{
	
}

void GB212DataMiddleware::ReqRep(const ProtoRequest& req, ProtoResponse& res)
{
#if 1
	{
		std::lock_guard<std::mutex> lck(mtx_);
		FILE* f = fopen("./rx.log", "a+");
		if (f) {
			String ss = "[" + Math::Date::getnow() + "]\r\n" + req.body;
			if (req.body[req.body.size() - 1] != '\n') {
				ss += "\r\n";
			}
			fwrite(ss.data(), 1, ss.size(), f);
			fclose(f);
		}
	}
#endif
	// ��utf8ת��gb2312(ascii)
	//String body = Math::Tools::from_utf8(req.body);
	const String& body = req.body;

	// parse gb212 format data
	GB212::GB212Array arr;
	GB212::Parser(arr, body);
	// ʵʱ�����£�����
	for (auto& i : arr) {
		if (i.valid()) {
			// ʵʱ����, ���ûظ����� , ����
			if (i.is_data()) {
				task_real_data(i, res);
			}
			// ���ͽ�������
			//publish_package(req, i.full, i.data.MN, i.data.ST, emPackType::Data);

		}
		else {
			// ������������
			task_heart_package(i, req, res);
		}
	}

}

void GB212DataMiddleware::task_real_data(const GB212& gb, ProtoResponse& res)
{
	auto qn = gb.data.QN;
	auto cn = gb.data.CN;
	auto st = gb.data.ST;
	auto mn = gb.data.MN;
	auto DataTime = gb.data.CPs.DataTime;
	// ���ÿͻ���ID
	res.Ids.emplace_back(mn);
	res.ST = st;
	// ������Ϣ�ظ�
	if (gb.is_need_reply()) {
		res.bodys.emplace_back(gb.data_res("9014").toString());
	}
	// ��ȡ���ݶζ���
	auto items = gb.data.CPs.Value;
	// ��ȡ����ʱ��
	const String date1 = DataTime.substr(0, 8);
	const String date2 = DataTime.substr(8, 6);

	// ��config.yaml�ļ��ж�ȡ����豸���ؽ�����OCEC������ɫ�ף���MNֵ
	sig_log lg;
	ConfigY	cfg_(lg);
	String  cfgpath_;
	ConfigOpt cfg_opt_;
	// get config 
	if (!cfg_.GetConfig(cfg_opt_, cfgpath_.c_str())) {
		return;
	}
	auto& info = cfg_opt_;
	String strMetalMN = info.mns.metal;
	String strOcecMN = info.mns.ocec;
	String strIonMN = info.mns.ion;

	int32 year, month, day, hour, minute, second;
	Math::Tools::to_int(year, date1.substr(0, 4));
	Math::Tools::to_int(month, date1.substr(4, 2));
	Math::Tools::to_int(day, date1.substr(6, 2));
	Math::Tools::to_int(hour, date2.substr(0, 2));
	Math::Tools::to_int(minute, date2.substr(2, 2));
	Math::Tools::to_int(second, date2.substr(4, 2));

	Uint8Array d1, d2;

	// ���������GB212Э�鱨�Ĵ洢��ModbusUnitData��(set)
	// ����CN��ֵ
	int iCN = 2011;
	Math::Tools::to_int(iCN, cn);

	// ����items�е�������
	for (auto& item : items) {
		std::string strCode = item.first;
		if (strCode == "DataTime") {
			continue;
		}
		// �����ֵ
		float val = 0.0f;
		// ���ݱ�ǣ�N��B�ȣ�
		String strMark = "N";

		for (auto& jt : item.second) {
			std::string strKey = jt.first;
			std::string strVal = jt.second;
			if (strKey == "Flag") 
			{
				strMark = strVal;
			}
			else if (strKey == "Rtd" || strKey == "Avg")
			{
				Math::Tools::to_float(val, strVal);
			}
			//if (cn == "2011")
			//{
			//	// 126-Rtd=24.771,126-Flag=N;
			//	if (strKey == "Flag") {
			//		strMark = strVal;
			//	}
			//	else if (strKey == "Rtd") {
			//		// Rtd��ʵʱֵ
			//		Math::Tools::to_float(val, strVal);
			//	}
			//}
			//else if (cn == "2051" || cn == "2061")
			//{
			//	// 121-Min=0.220,121-Avg=0.000,121-Max=0.000;
			//	// Avg��ƽ��ֵ
			//	if (strKey == "Avg")
			//	{
			//		Math::Tools::to_float(val, strVal);
			//	}
			//}
		}

	}
}

void GB212DataMiddleware::task_heart_package(const GB212& gb, const ProtoRequest& req, ProtoResponse& res)
{
	String id;
	auto i0 = gb.full.find("##");
	auto i00 = gb.full.find("MN=");
	// get mn
	size_t i1;
	if (i00 != String::npos) {
		i1 = gb.full.find(";", i00);
	}
	else {
		i1 = gb.full.find("\r\n", i0);
	}
	if (i00 != String::npos) {
		id = gb.full.substr(i00 + 3, i1 - i00 - 3);
	}
	else if (i0 != String::npos) {
		id = gb.full.substr(i0 + 2, i1 - i0 - 2);
	}
	// get st
	String st;
	size_t i2 = gb.full.find("ST=");
	size_t i21 = gb.full.find(";", i2);
	if (i2 != String::npos && i21 != String::npos) {
		st = gb.full.substr(i2 + 3, i21 - i2 - 3);
	}

	// ���ÿͻ���ID
	if (id.size()) {
		res.Ids.emplace_back(id);
	}
	if (st.empty()) {
		st = req.ST;
	}
	// ���ͱ�����Ϣ
	// publish_package(req, gb.full, id, st, emPackType::Heart);
}

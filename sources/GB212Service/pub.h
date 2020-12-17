#pragma once

#include <type.h>

/**
* ���ݵı��״̬
*/
enum class DataMark {
	N = 0,		// ������������
	B = 1,		// ���в���,�������ڱ���ʱ����
	BB = 2,		// ���Ӳ���,����������һֱû������ͨ�ųɹ�ʱ����
	W = 3,		// �ȴ����ݻָ�,������ͨ�ųɹ����ڳ��������������ڻ�δ����ʱ������
	H = 4,		// ��Ч���ݲ���
	HSp = 5,	// ���ݳ�����
	LSp = 6,	// ���ݳ�����
	PZ = 7,		// �����(����)
	PS = 8,		// ��ȼ��(�߱�)
	AS = 9,		// ���ȼ��
	CZ = 10,	// ���У׼(У��)
	CS = 11,	// ���У׼(У׼)
	Re = 12,	// �����ز������ݴ��ı��
	ZNi = 15,	// �������
	SNi = 16,	// ��������
	IEr = 17,	// ʾֵ���
	RPD = 18,	// ���̾��ܶ�
	DZS = 19,	// 24h���Ư�ƺ�����Ư��
	TSL = 30,	// ���У׼
	UNKNOWN = 40	// ����
};

// ���λת������
static DataMark covertMark(String strMark)
{
	DataMark res = DataMark::N;
	if ("N" == strMark)
	{
		res = DataMark::N;
	}
	else if ("B" == strMark)
	{
		res = DataMark::B;
	}
	else if ("BB" == strMark)
	{
		res = DataMark::BB;
	}
	else if ("W" == strMark) {
		res = DataMark::W;
	} 
	else if ("H" == strMark) {
		res = DataMark::H;
	}
	else if ("HSp" == strMark) {
		res = DataMark::HSp;
	}
	else if ("LSp" == strMark) {
		res = DataMark::LSp;
	}
	else if ("PZ" == strMark) {
		res = DataMark::PZ;
	}
	else if ("PS" == strMark) {
		res = DataMark::PS;
	}
	else if ("AS" == strMark) {
		res = DataMark::AS;
	}
	else if ("CZ" == strMark) {
		res = DataMark::CZ;
	}
	else if ("CS" == strMark) {
		res = DataMark::CS;
	}
	else if ("Re" == strMark) {
		res = DataMark::Re;
	}
	else if ("ZNi" == strMark) {
		res = DataMark::ZNi;
	}
	else if ("SNi" == strMark) {
		res = DataMark::SNi;
	}
	else if ("IEr" == strMark) {
		res = DataMark::IEr;
	}
	else if ("RPD" == strMark) {
		res = DataMark::RPD;
	}
	else if ("DZS" == strMark) {
		res = DataMark::DZS;
	}
	else if ("TSL" == strMark) {
		res = DataMark::TSL;
	}
	else {
		res = DataMark::UNKNOWN;
	}
	
	return res;
}
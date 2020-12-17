#pragma once
#include <type.h>


namespace network
{
	struct ProtoRequest {
		String		address;	// Զ�̵�ַ
		uint16		port;	  // Զ�̶˿�
		String		body;	  // ��������
		StringArray Ids;		  // Զ�̱�ʶ
		String		ST;
	};

	struct ProtoResponse {
		StringArray Ids;			// Զ�̱�ʶ
		StringArray bodys;	// ��Ӧ����
		String		ST;
	};

	class DataSink
	{
	public:
		// "����-�ظ�"ģʽ
		virtual void ReqRep(const ProtoRequest& req, ProtoResponse& res) = 0;

	};

	class MgrInterface {
	public:
		// ���ݷ���
		virtual bool write_data(const String& clientid, const String& req) = 0;
	};
}


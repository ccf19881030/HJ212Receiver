#pragma once
#include <my_signal.h>
#include "net.h"
#include "GB212.h"
using namespace network;
#include <mutex>

class GB212DataMiddleware : public DataSink
{
public:
	GB212DataMiddleware();
	virtual void ReqRep(const ProtoRequest& req, ProtoResponse& res) override;

protected:
	void task_real_data(const GB212& gb, ProtoResponse& res);

	void task_heart_package(const GB212& gb, const ProtoRequest& req, ProtoResponse& res);

	enum emPackType { Unknown, Heart, Data, All };
	// pack_type���ݰ�����, 0-δ֪, 1-����, 2-����, 3-����
public:
	std::mutex mtx_;
};


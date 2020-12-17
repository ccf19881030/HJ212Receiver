#pragma once
#include <my_signal.h>
#include "net.h"
#include "GB212.h"
using namespace network;
#include <mutex>


class DataMiddleware : public DataSink
{
public:
	void set_ttl(const int32 ttl);

	void set_type(const String& ptype);

	virtual void ReqRep(const ProtoRequest& req, ProtoResponse& res) override;

protected:
	void task_real_data(const GB212& gb, ProtoResponse& res);

	void task_heart_package(const GB212& gb, const ProtoRequest& req, ProtoResponse& res);

	enum emPackType { Unknown, Heart, Data, All };
	// pack_type���ݰ�����, 0-δ֪, 1-����, 2-����, 3-����
	void publish_package(const ProtoRequest& req, const String& body, const String& clientid, const String& st, const emPackType pack_type);

public:
	// MQ���ͽӿ�
	sig_pub		signal_pub_;
	// Redis����API
	sig_set		signal_set_;
	sig_setex	signal_setex_;
	sig_hset	signal_hset_;
	sig_hget	signal_hget_;
	sig_hgetall	signal_hgetall_;
	sig_expire	signal_expire_;

	int32 ttl_ = -1;

	String ptype_;

	std::mutex mtx_;
};


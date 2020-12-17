#pragma once
#include <type.h>
#include <my_log.h>
#include <func.h>
#include "MainService.h"
#include <mutex>

class MainApp : public my_log
{
public:
	MainApp(int argc, char* argv[]);
	~MainApp();

	// ���з���, basync��ʾ�Ƿ��첽����ͬ������
	void run(bool basync = false);

	// ֹͣ����
	void stop();

protected:
	// ��ʼ������
	void init();

	// ��������ں���
	void start();

	// ��־��Ϣ�ص�����
	void slot_log(const char * file, const char * func, long line, log_level level, bool need_send, const char * msg);

	// set current work dir
	bool set_work_dir(const char* exe_path);

private:
	sig_log			sig_log_;
	// ���߳�
	Thread			thread_main_;
	// ���߳̽�����־
	volatile bool	brun_main_ = false;

	MainService		main_serv_;

	std::mutex		mtx_log_;
};


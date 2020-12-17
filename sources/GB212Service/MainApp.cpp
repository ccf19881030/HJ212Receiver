#include "MainApp.h"
#include <fstream>
#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif


MainApp::MainApp(int argc, char* argv[])
	: my_log(sig_log_)
	, main_serv_(sig_log_, argc, argv)
{
	// ���õ�ǰ·��
	set_work_dir(argv[0]);
}


MainApp::~MainApp()
{
	stop();
}

// ���з���, basync��ʾ�Ƿ��첽����ͬ������
void MainApp::run(bool basync /*= false*/)
{
	brun_main_ = true;
	thread_main_ = Thread([this]() {
		init();
		start();
	});
	if (!basync) {
		while (brun_main_) {
			msleep(1);
		}
	}
}

// ֹͣ����
void MainApp::stop()
{
	brun_main_ = false;
	// ����ֹͣ
	main_serv_.stop();

	// �ȴ�
	if (thread_main_.joinable()) {
		thread_main_.join();
	}
}

// ��ʼ������
void MainApp::init()
{
	// ������־�ص�����
	this->set_log_cb(std::bind(&MainApp::slot_log, this, std::placeholders::_1,
		std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6));
}


// ��������ں���
void MainApp::start()
{
	main_serv_.start();
}

// ��־��Ϣ�ص�����
void MainApp::slot_log(const char * file, const char * func, long line, log_level level, bool need_send, const char * msg)
{
#ifdef WIN32
	const char* file2 = strrchr(file, '\\') + 1;
#else
	const char* file2 = strrchr(file, '/') + 1;
#endif
	// ��־��ӡ��ʾ����־��¼�洢
	char str[4096];
	snprintf(str, sizeof(str) - 1, "[%s][%d]%s:%ld %s: %s\r\n", Math::Date::getnow().c_str(), level, file2, line, func, msg);
	if (level != debug)
	{
		printf(str);
	}
	std::lock_guard<std::mutex> locker(mtx_log_);
#ifdef WIN32
	Math::File::mk_dirs("./log/");
	String filename = "./log/system_" + Math::Date::getnow("%04d%02d%02d") + ".log";
#else
	Math::File::mk_dirs("../log/");
	String filename = "../log/gb212rx_" + Math::Date::getnow("%04d%02d%02d") + ".log";
#endif
	std::ofstream out(filename, std::ios::out | std::ios::app);
	if (out) {
		out.write(str, std::strlen(str));
	}

// 	if (need_send) 
// 	{
// 		// ������־
// 
// 	}
// 	if (need_stor)
// 	{
// 		// �洢
// 	}
}

bool MainApp::set_work_dir(const char* exe_path)
{
#ifdef _WIN32
	std::string path = exe_path;
	std::string curr = path.substr(0, path.find_last_of("\\"));
	SetCurrentDirectory(curr.c_str());
#else
	char path[256];
	int len = readlink("/proc/self/exe", path, sizeof(path) - 1);
	if (len)
	{
		const char* p = strrchr(path, '/');
		if (p)
		{
			path[p - path] = '\0';
			return chdir(path) != -1;
		}
	}
#endif
	return false;
}

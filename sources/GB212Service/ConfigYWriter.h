#pragma once
#include <type.h>
#include <my_log.h>
#include <yaml-cpp/yaml.h>
#include "cnfYDefine.h"
#include <fstream>


class ConfigY : public my_log
{
#ifdef WIN32
#define DEFAULT_FILE "./config/config.yaml"
#else
#define DEFAULT_FILE "../config/config.yaml"
#endif
public:
	ConfigY(sig_log& lg) : my_log(lg) {}

	// ���������ļ�·��
	void SetFilePath(const String& path) {
		path_ = path;
	}

	// ��ȡ�����ļ�·��
	String GetFilePath() {
		return path_;
	}

	// ��ȡ�����ļ�����
	template<typename T>
	bool GetConfig(T& _return, const char* file = nullptr) {
		const char* path = (file == nullptr || strlen(file) == 0) ? path_.c_str() : file;
		try {
			if (strlen(path) == 0) throw std::exception(std::logic_error("config file path is empty."));
			YAML::Node doc = YAML::LoadFile(path);
			_return = doc.as<T>();
			return true;
		}
		catch (const YAML::Exception& e) {
			EmitLog(error, "YAML: %s", e.what());
		}
		return false;
	}

	// д���������ݵ��ļ�
	template<typename T>
	bool SetConfig(const T& content, const char* file = nullptr) {
		const char* path = (file == nullptr || strlen(file) == 0) ? path_.c_str() : file;
		try {
			if (strlen(path) == 0) throw std::exception(std::logic_error("config file path is empty."));
			YAML::Node doc;
			doc = content;
			std::ofstream fout(path);
			fout << doc;
			return true;
		}
		catch (const YAML::Exception& e) {
			EmitLog(error, "YAML: %s", e.what());
		}
		return false;
	}

private:
	String path_ = DEFAULT_FILE;
};
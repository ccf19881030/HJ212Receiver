#pragma once
// ��д��
#include <boost/thread/thread.hpp>

typedef boost::shared_mutex RWMutex;
// ����
typedef boost::shared_lock<boost::shared_mutex> ReadLocker;
// д��
typedef boost::unique_lock<boost::shared_mutex> WriteLocker;

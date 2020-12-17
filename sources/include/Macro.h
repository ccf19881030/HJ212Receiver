#ifndef _XM_NEW_MACRO_H_
#define _XM_NEW_MACRO_H_

#define macroStr(s) #s

// ��ȡ16λ���ݵĸ�8λ
#define GET16H(d)		((d)>>8&0xff)
// ��ȡ16λ���ݵĵ�8λ
#define GET16L(d)		((d)&0xff)
// ͨ���ߵ�8λ����16λ����
#define GET16T(h,l)		(((h)<<8&0xff00)|((l)&0xff))
// ����16λ���ݵĸߵ�8λ��ȡ����
#define GET16S(d)		GET16T(GET16L(d),GET16H(d))

#define GET32H(d)		((d)>>16&0xffff)
#define GET32L(d)		((d)&0xffff)


// ��ȡ��������
#define VAR(w) #w

// ��ȡ��ǰ����ֵ
#define Minute(a) a % 3600 / 60
// ��ȡ��ǰ���ӵ�ʱ���
#define MinuteTime(a) a / 60 * 60

// ��־������Ϣ
#define WriteLog(level, str) log(MODULE_NAME,__FUNCTION__,__LINE__,level,str)

// ��־�ȼ�
enum LogLevel1
{
	LDEBUG = 1,
	LINFO,
	LWARN,
	LERROR,
	LQC = 8,
	LSAMPLE,
};

#endif
#ifndef _XM_DATA_FORAMT_DEFINE_H_
#define _XM_DATA_FORAMT_DEFINE_H_
#include "type_def.h"


/************************************************************************/
/* �豸����ID                                                            */
/************************************************************************/
enum class DeviceType {
	ignore = 0,
	SO2 = 1,
	NO = 2,
	CO = 3,
	O3 = 4,
	PM10 = 5,
	PM25 = 6,
	PM10_25 = 7,
	PM1 = 8,
	TSP = 9,
	QX = 10,	// ��������
	VIS = 11,	// �ܼ���
	CALI = 12,	// У׼��
	ZERO = 13,	// ������
	H2S = 14,	// ����
	ATM = 15,	// ��̿��
	INM = 16,	// �Ƕ���
	ASAS = 17,	// ��������
	NOy = 18,	// NOy
	NH3 = 19,	// NH3
	GHG = 20,	// ��������
	ATPS = 21,	// �����ȶ���
	VOC = 22,	// VOCs
	CTRL = 23,	// ����ģ��
	UVRM = 24,	// UV�����
	CEILO = 25,		// �Ƹ���
	ENV = 26,		// վ������
	OCEC = 27,		// OCEC
	MYMT = 28,		// �ؽ���
	SOCA = 29,		// ����������
	SPHM = 30,		// ̫����ȼ�
	CH4 = 32,		// ����
	QXEX = 101,		// �����ۺ�
	PAN = 102,		// PAN
	GJGP = 103,		// ������
	C = 105,		// ̿��

};


inline bool is_have_act(const DeviceType dt) {
	return (dt == DeviceType::SO2 || dt == DeviceType::NO || dt == DeviceType::CO || dt == DeviceType::O3 ||
		dt == DeviceType::PM10 || dt == DeviceType::PM25 || dt == DeviceType::PM10_25 || dt == DeviceType::PM1 || dt == DeviceType::TSP);
}

inline bool is_have_two(const DeviceType dt) {
	return is_have_act(dt) || dt == DeviceType::VOC;
}

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
	PA = 31,	// ���ܶ����
	PF = 40,	// ������-�������
	PME = 41,	// ������-ĤƬ���
	PT = 42,	// ������-�¶�ѹ�����
	PCS = 43,	// ������-��ϴ����ͷ
	OT = 50,	// �Զ�����
};

inline String mark2Str(const DataMark mark){
	switch (mark) {
	case DataMark::N:
		return "N";
	case DataMark::B:
		return "B";
	case DataMark::BB:
		return "BB";
	case DataMark::W:
		return "W";
	case DataMark::H:
		return "H";
	case DataMark::HSp:
		return "HSp";
	case DataMark::LSp:
		return "LSp";
	case DataMark::PZ:
		return "PZ";
	case DataMark::PS:
		return "PS";
	case DataMark::AS:
		return "AS";
	case DataMark::CZ:
		return "CZ";
	case DataMark::CS:
		return "CS";
	case DataMark::Re:
		return "Re";
	case DataMark::ZNi:
		return "ZNi";
	case DataMark::SNi:
		return "SNi";
	case DataMark::IEr:
		return "IEr";
	case DataMark::RPD:
		return "RPD";
	case DataMark::DZS:
		return "DZS";
	case DataMark::TSL:
		return "TSL";
	case DataMark::PA:
		return "PA";
	case DataMark::PF:
		return "PF";
	case DataMark::PME:
		return "PME";
	case DataMark::PT:
		return "PT";
	case DataMark::PCS:
		return "PCS";
	case DataMark::OT:
		return "OT";
	default:
		break;
	}
	return "N";
}

/************************************************************************/
/* �豸����״��                                                          */
/************************************************************************/
enum class RunState {
	NotRun = 0,		// ����δ����
	Normal,			// һ������
	NotOpen,		// δ����
	NotResponse,	// ����Ӧ
	InvalidData,	// ��Ч������
	InvalidDriver,	// ��Ч��������δ����
	DataNotUpdate,	// ����δ����
};

// �豸�������״̬
enum class DeviceOutputState {
	UnKnown = 0,	// Ĭ�ϱ��
	Standard = 1,	// ��׼״��
	Actual = 2,		// ʵ��״��
	QxActual = 6,	// �������
};

/**
* �����������������
* RealTimeʵʱ����; State״̬��; Alarm������
*/
enum class ParamterType {
	RealTime = 1,	// ʵʱ����
	State = 2,		// ״̬����
	Alarm = 3,		// ��������
};


/************************************************************************/
/* ������key                                                            */
/************************************************************************/
struct ParamterKey {
	ParamterKey(const ParamterType t, int d) :type(t), id(d){}
	ParamterKey(int t, int d) :ParamterKey(static_cast<ParamterType>(t), d) {}
	bool operator<(const ParamterKey& o) const{
		return (this->type < o.type) || ((this->type == o.type) && (this->id < o.id));
	}
	ParamterType type;	// ��������
	int id;				// ����ID
};


/************************************************************************/
/* ��������                                                          */
/************************************************************************/
struct  ParamterValue
{
	ParamterValue(float value) :val(value){}
	union 
	{
		float	val;	// �豸������
		int32	ival = 0;
	};
	
};
// �豸������map�ṹ
typedef std::map<ParamterKey, ParamterValue> DeviceParamterMap;


/**
* �����������
*/
struct ParamterInfo {
	std::string	param_name;
	std::string	param_unit;
	std::string	value_min;
	std::string	value_max;
	bool	hint = false;
	int		point_num = 0;
	int critical_time = 0;
	int sub_show = 0;
	int state_key = 0;
	std::string state_desc;
};


/************************************************************************/
/* �豸���Ͳ�����������                                                   */
/************************************************************************/
typedef std::map<DeviceType, std::map<int, ParamterInfo>> DeviceTypeParamObj;


/************************************************************************/
/*  �豸ʶ��key                                                          */
/************************************************************************/
struct DriverKey
{
	DriverKey() :code("00000000"), number(0){}
	DriverKey(const std::string& code, int number) :code(code), number(number){}
	DriverKey(const DeviceType type, int number) : number(number) {
		char str[10];
		std::sprintf(str, "0000%02d00", type);
		this->code = str;
	}
	DriverKey(const int type, int number) : DriverKey(static_cast<DeviceType>(type), number) {}
	DriverKey(const char* code, int number) :code(code), number(number){}
	bool operator<(const DriverKey& o)const{
		return (this->code < o.code) || ((this->code == o.code) && (this->number < o.number));
	}
	int id() const {
		return DriverKey::id(type(), number);
	}
	static inline int id(int type, int number) {
		return ((number << 8) & 0xFF00) | (type & 0xFF);
	}
	int type() const {
		if (code.size() < 8)
			return 0;
		return std::stoi(code, 0, 16) >> 8 & 0xFF;
	}
	const char* operator()() const {
		return code.c_str();
	}
	std::string	code;	// �豸��32λ����
	int			number;	// ͬ���͵�ʵ��ID��
};

typedef std::vector<DriverKey> DriverKeyArray;


/**
* ����ʵ����
*/
struct TypeKey {
	TypeKey(){}
	TypeKey(int t, int n) : type(static_cast<DeviceType>(t)), number(n){}
	bool operator<(const TypeKey& o)const{
		return (this->type < o.type) || ((this->type == o.type) && (this->number < o.number));
	}
	DeviceType type = DeviceType::SO2;	// �豸����
	int number = 0;			// ʵ����������
};
typedef std::vector<TypeKey> TypeKeyArray;

/**
* ��ѯ����������
*/
enum QueryType {
	Second,
	OneMinute,
	FiveMinute,
	OneHour,
	OrigHour,
	OneDay,
};


// �������ݽṹ
struct AlarmItem {
	AlarmItem(const DriverKey& k, const ParamterKey& p) : key(k),pkey(p), happen_date(), resume_date(), confirm_date(){}
	DriverKey key;
	ParamterKey pkey;
	std::string happen_date;
	double happen_value = 0;
	int8 overrun_type = 0;
//	bool is_overrun_critical = false;
	bool resumed = false;
	std::string resume_date;
	double resume_value = 0;
	bool confirm = false;
	std::string confirm_date;
};
typedef std::vector<AlarmItem> AlarmItemArray;

// �������������ṹ
struct AlarmDetailItem {
	std::string DeviceCode;
	int DeviceNumber = 0;
	std::string DeviceTypeName;
	std::string DeviceManuName;
	std::string DeviceModelName;
	ParamterType pType;
	std::string pName;
	std::string happen_date;
	double happen_value = 0;
	int8 overrun_type = 0;
	bool resumed = false;
	std::string resume_date;
	double resume_value = 0;
	bool confirm = false;
	std::string confirm_date;
};
typedef std::vector<AlarmDetailItem> AlarmDetailItemArray;


/************************************************************************/
/*  �豸����                                                             */
/************************************************************************/
struct DeviceValue 
{
	DeviceValue(){}
	DeviceValue(const DriverKey& key) :key(key){}
	DriverKey			key;			// �豸������ʶ��
	std::string			timestamp_str;	// ���ݲɼ���ʱ�䣬�ַ���
	std::string			mark;			// ���ݵı�ʶ��Ϣ
	DeviceParamterMap	paramter;		// �豸��������
};


/**
* ���������������
*/
struct DeviceInfo{
	int	type_slave = 0;
	std::string	type_id;
	std::string	type_name;
	int type_used = 0;

	std::string	manu_id;
	std::string	manu_name;
	std::string	manu_code;

	std::string	dev_code;
	int	dev_number = 0;
	std::string	dev_model;

	std::map<int, ParamterInfo> real;
	std::map<int, ParamterInfo> state;
	std::map<int, ParamterInfo> alarm;
};

/**
 * ������������ѹ�����¶�                                                                      
*/
struct PTState 
{
	PTState() { memset(this,0,sizeof(*this)); }
	int Pid;	// ѹ����Ӧ��id��
	int Tid;	// �¶ȶ�Ӧ��id��
	char Punit[20]; // ѹ�������λ
	char Tunit[20]; // �¶������λ
};
// �豸��ѹ���¶�״̬��Ϣ
typedef std::map<std::string, PTState> DevicePTState;


/************************************************************************/
/* ���ݲ�ѯ��¼                                                          */
/************************************************************************/
typedef std::map<int, double> ItemData;
#define NULL_VALUE -1001
#define DEFMARK		""
struct QueryItemData 
{
	QueryItemData() 
		: date(), PM10(NULL_VALUE), PM25(NULL_VALUE), SO2(NULL_VALUE), CO(NULL_VALUE), O3(NULL_VALUE), VIS(NULL_VALUE)
		, PM10_mark(DEFMARK), PM25_mark(DEFMARK)
		, SO2_mark(DEFMARK), NO_mark(DEFMARK), CO_mark(DEFMARK), O3_mark(DEFMARK)
		, QX_mark(DEFMARK), VIS_mark(DEFMARK), ENV_mark(DEFMARK) {
		NO.insert(std::make_pair(1, NULL_VALUE));
		NO.insert(std::make_pair(2, NULL_VALUE));
		NO.insert(std::make_pair(3, NULL_VALUE));
		QX.insert(std::make_pair(1, NULL_VALUE));
		QX.insert(std::make_pair(2, NULL_VALUE));
		QX.insert(std::make_pair(3, NULL_VALUE));
		QX.insert(std::make_pair(4, NULL_VALUE));
		QX.insert(std::make_pair(5, NULL_VALUE));
		QX.insert(std::make_pair(6, NULL_VALUE));
		QX.insert(std::make_pair(7, NULL_VALUE));
		ENV.insert(std::make_pair(1, NULL_VALUE));
		ENV.insert(std::make_pair(2, NULL_VALUE));
	}
	QueryItemData(const std::string& d) 
		: date(d), PM10(NULL_VALUE), PM25(NULL_VALUE), SO2(NULL_VALUE), CO(NULL_VALUE), O3(NULL_VALUE), VIS(NULL_VALUE)
		, PM10_mark(DEFMARK), PM25_mark(DEFMARK)
		, SO2_mark(DEFMARK), NO_mark(DEFMARK), CO_mark(DEFMARK), O3_mark(DEFMARK)
		, QX_mark(DEFMARK), VIS_mark(DEFMARK), ENV_mark(DEFMARK) {
		NO.insert(std::make_pair(1, NULL_VALUE));
		NO.insert(std::make_pair(2, NULL_VALUE));
		NO.insert(std::make_pair(3, NULL_VALUE));
		QX.insert(std::make_pair(1, NULL_VALUE));
		QX.insert(std::make_pair(2, NULL_VALUE));
		QX.insert(std::make_pair(3, NULL_VALUE));
		QX.insert(std::make_pair(4, NULL_VALUE));
		QX.insert(std::make_pair(5, NULL_VALUE));
		QX.insert(std::make_pair(6, NULL_VALUE));
		QX.insert(std::make_pair(7, NULL_VALUE));
		ENV.insert(std::make_pair(1, NULL_VALUE));
		ENV.insert(std::make_pair(2, NULL_VALUE));
	}
	std::string date;
	double PM10;
	double PM25;
	double SO2;
	ItemData NO;
	double CO;
	double O3;
	ItemData QX;
	double VIS;
	ItemData ENV;
	// ���ݱ��
	std::string PM10_mark;
	std::string PM25_mark;
	std::string SO2_mark;
	std::string NO_mark;
	std::string CO_mark;
	std::string O3_mark;
	std::string QX_mark;
	std::string VIS_mark;
	std::string ENV_mark;
};

// ��һ�������ݼ�¼
struct QueryOneItem 
{
	QueryOneItem() :date(), mark(DEFMARK), samples(0) {}
	QueryOneItem(const std::string& d):date(d),mark(DEFMARK), samples(0) {}
	std::string date;
	std::string mark;
	int32 samples;
	ItemData data;
};


#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/trim.hpp>
/************************************************************************/
/* ��Ϣ����                                                                     */
/************************************************************************/
class MessageTopic
{
public:
	MessageTopic() :province(), city(), area(), stationCode(), dataType(), devType(), devDataType(), reserve()
	{

	}
	MessageTopic(const std::string& in) 
	{
		std::vector<std::string> result;
		boost::split(result, in, boost::is_any_of("/"), boost::token_compress_off);
		if (result.size())
		{
			try {
				int iPos = 0;
				if (result.at(0).empty()){
					iPos = 1;
				}
				province = result.at(iPos++);
				city = result.at(iPos++);
				area = result.at(iPos++);
				stationCode = result.at(iPos++);
				dataType = result.at(iPos++);
				devType = result.at(iPos++);
				devDataType = result.at(iPos++);
				reserve = result.at(iPos++);
			}
			catch (std::exception&) {

			}
		}
	}
	std::string out(bool has_header = true)
	{
		return (has_header ? ("/" + province) : province) + "/" + city + "/" + area +"/" + stationCode
			+"/" + dataType  +"/" + devType  +"/" + devDataType + "/" + reserve;
	}

	std::string		province;	// ��hubei��
	std::string 	city;		// (xiaogan)
	std::string 	area;		// (xiaonan)
	std::string		type;		// վ������(EAMS, SEAMS)
	std::string 	stationCode;	// (SS420984099)
	std::string 	dataType;	// (���������ݣ���־���ݣ���������)
	std::string 	devType;	// (all, SO2, NO, CO)
	std::string 	devDataType;	// (Сʱ�����ӣ�����)
	std::string 	reserve;	// ����
};


/************************************************************************/
/* ���ƵĿ��Ʋ���                                                        */
/************************************************************************/
enum ControlOperation
{
	ControlStd = 0x0100,
	ControlCalStd = 0x0101,
	ControlZero = 0x0200,
	ControlCalZero = 0201,
};

enum ControlObject
{
	ObjectZero = 0,
	ObjectSO2 = 1,
	ObjectNOx = 2,
	ObjectO3 = 3,
	ObjectCO = 4,
};

/**
* �����ʿ���������
*/
enum ControlTask {
	ZeroCheck = 0,				// �����
	ZeroCalibrate,				// ���У׼
	SpanCheck,					// ��ȼ��
	SpanCalibrate,				// ���У׼
	ZeroNoise = 13,				// �������
	SpanNoise,					// ��������
	IndicationError,			// ʾֵ���
	RangePrecisionDeviation,	// ���̾��ܶ�
	Drift24hZeroSpan,			// 24h���Ư�ƺ�24h����Ư��
	MultiPonitCalibrate,		// ���У׼
	PrecisionAudit,				// ���ܶ����
};

enum class ControlDataType {
	TotalTask = 0,		// ��������
	ZeroCheck,			// �����
	SpanCheck,			// ��ȼ��
	ZeroNoise,			// �������
	SpanNoise,			// ��������
	Indication,			// ʾֵ���
	IndicationZero,		// ʾֵ���0
	Precision20,		// 20%���̾��ܶ�
	Precision80,		// 80%���̾��ܶ�
	Drift24hZero,		// 24Сʱ���Ư��
	Drift24hSpan20,		// 24Сʱ20%����Ư��
	Drift24hSpan80,		// 24Сʱ80%����Ư��
	MultiPointSpan,		// ���У׼
	PrecisionAuditZero,	// ���ܶ����0
	PrecisionAudit,		// ���ܶ����
};

enum class ControlResult {
	TaskInvalid = 0,	// ������Ч
	DataInvalid = 1,	// ������Ч
	Unqualified = 2,	// ���ϸ�
	Qualified = 3,		// �ϸ�
	Waiting = 10,		// �ȴ���,��ʱ����
	Running = 11,		// ���ڽ�����
	Finished = 12,		// ��ɵ�
	Canceled = 13,		// ��ȡ����
	Timeout = 14,		// ��ʱ��
};

/**
* �ʿ�����Ĳ���
*/
struct ControlTaskParam {
	float FullRange = 500;			// ������Ũ��ֵ,һ��Ϊ500ppb
	int GasFlow = 5000;				// ����,һ��Ϊ5000ml
	int ConcPercent = 80;			// ����Ũ�Ȱٷֱ�,Ĭ��Ϊ80%
	int ZeroStableTime = 5;			// ͨ�����ﵽ�ȶ���ʱ��(����)
	int Span10PerStableTime = 15;	// ͨ10%Ũ�ȱ�׼���嵽���ȶ���ʱ��(����)
	int Span20PerStableTime = 15;	// ͨ20%Ũ�ȱ�׼���嵽���ȶ���ʱ��(����)
	int Span40PerStableTime = 15;	// ͨ40%Ũ�ȱ�׼���嵽���ȶ���ʱ��(����)
	int Span50PerStableTime = 15;	// ͨ50%Ũ�ȱ�׼���嵽���ȶ���ʱ��(����)
	int Span60PerStableTime = 15;	// ͨ60%Ũ�ȱ�׼���嵽���ȶ���ʱ��(����)
	int Span80PerStableTime = 15;	// ͨ80%Ũ�ȱ�׼���嵽���ȶ���ʱ��(����)
	int ReserveStableTime = 15;		// ͨ�����嵽���ȶ���ʱ��(����)(������)
	int ExperimentNumber = 3;		// ����ʵ��Ĵ���
	int ResumeSampleTime = 2;		// ������ָ��������ȶ���ʱ��(����)
};


	
struct ControlParam 
{
	ControlParam():begin_time(1), before_time(3), stable_time(30), after_time(2)
	, conc(400), flow(5000){}
	int begin_time = 1;		// ׼��ʱ��,��
	int before_time = 3;		// �ʿ�ǰ����ʱ��,��
	int stable_time = 15;	// �ʿع���ʱ��,����
	int after_time = 2;		// �ʿغ���ʱ��,��
	int conc = 400;				// ͨ��Ũ��,��λppb,CO(ppm)
	int flow = 5000;			// ͨ������,��λml
};

/************************************************************************/
/* ��ʱ��������ļ�¼״̬                                                 */
/************************************************************************/
enum class TaskTimerState {
	Waiting = 0,
	Finished = 1,
	Timeout = 2,
	Canceled = 3,
};

/************************************************************************/
/* ��ʱ����Ĳ���                                                         */
/************************************************************************/
struct TaskTimerItem 
{
	int uid = 0;
	DeviceType type;
	int number = 0;
	ControlTask task;
	std::string date;
};
typedef std::vector<TaskTimerItem> TaskTimerList;


/**
* �����������Ʋ���
* �ɼ�Ƶ��, ���͵������QOS, �ʿ���Ӧ��ʱ��
*/
struct DriverControlConfig{
	ControlParam zero;				// ����
	ControlParam zeroCal;			// ����
	ControlParam span;				// �߱�
	ControlParam spanCal;			// �̱�
};



/************************************************************************/
/* ���ƹ����еĴ���                                                       */
/************************************************************************/
enum ControlError
{
	ControlFinished,
	ControlModuleError = 1,
	DynamicGenerateGasError			= 0x1001,
	AnalyticalChangeNoSample		= 0x1002, 
	DynamicStopGenerateGasError		= 0x1004,
	AnalyticalResumeSample			= 0x1008,
};


// �ʿصĽ��
struct QCTaskResult{
	float val = 0;			// ������ļ�����
	ControlResult rc;		// ������ķ��Ͻ��
};

// ÿ���ʿ������������
struct QCTaskProcess{
	std::map<std::string,float> processData;	// ������Ĺ�������
	std::vector<QCTaskResult> result;			// ������Ľ����
};

// �ʿ�����Ĳ���
struct QCTaskItem{
	std::string code;
	int32 number = 0;		// �豸����ʵ��
	DeviceType devType;		// �豸����
	int32 envTaskType;		// ��������[����1,�ֳ�2,�ƻ�3,4�ֹ�]
	ControlTask qcType;		// �ʿ�����
	std::string startDate;	// ��ʼʱ��
	std::string endDate;		// ����ʱ��
	int32 completedCount = 0;	// ��ɴ���
	std::map<int32,QCTaskProcess> data;	// ��������б�����, <���������,��������>
	ControlResult state;	//����״̬
	ControlTaskParam param;	// ����
	int32 uid = 0;	// ��¼��ʶ
};
typedef std::vector<QCTaskItem> QualityControlTask;

struct QualityTaskDataItem 
{
	// tb_task_data(devType INT,number INT,qcType INT,date VARCHAR(20),stdValue float,actValue float)
	DeviceType devType;
	int number;
	ControlTask qcType;
	ControlDataType qcDataType;
	std::string date;
	double stdValue;
	double actValue;
};
typedef std::vector<QualityTaskDataItem> QualityTaskData;


// ѡȡ�����ݵ�
struct StablePoint {
	double stdval;	// �趨ֵ
	double val;		// ���ֵ
	string datetime; // ����ʱ���
};
// ����ֶ��ʿصĲ���
struct ManualQCParam {
	DeviceType devType;	// �豸����
	ControlTask qcType;	// �ʿ�����
	string startDate;	// ��ʼʱ��
	string endDate;		// ����ʱ��
	std::vector<StablePoint> point;
};

// �豸����״̬
struct DevRunStatus 
{
	DriverKey key;
	bool run = false;
	RunState state;
};

// �豸����״̬
struct DeviceStatus : public DevRunStatus
{
	std::string			date;
	std::string			mark;
	std::map<int32, double>	real;		// �豸��������
};
typedef std::vector<DeviceStatus> DeviceStatusArray;

// վ������״̬
struct NodeStatus
{
	bool StoreReal;
	bool StoreMinute;
	bool StoreHour;
	DeviceStatusArray row;
};


// ��������-ֻ�������ֵ
struct QuerySecondItem
{
	std::string date;
	std::string mark;
	std::map<int32, double>  data;
};


// �ز����ݸ�ʽ
typedef std::map<std::string, std::map<int32, double>> HistoryData;

// �û�Ȩ�ޱ�
enum AuthorityLevel {
	None = 0,
	ROOT = 1,
	Admin,
	Users,
};

struct User {
	int32 UserId;
	std::string UserName;
	std::string UserPasswd;
	AuthorityLevel level;
	bool Freeze;
};

// ��Ȩ����
enum AuthorityType {
	unknown = 0,	// δ֪״̬
	Trial = 1,		// ���������
	License			// license�ļ���Ȩ
};

// �����Ȩ��Ϣ
struct AuthorityInfo {
	AuthorityType type;
	std::string code;
	std::string pccode;
	std::string install_date;
	std::string license_date;
	int32 license_days;
	bool is_authority;
};

// �ϴ�XML�ļ�����
struct StationConfig {
	StationConfig() {
		memset(this, 0, sizeof(*this));
	}
	std::string sender;
	std::string cityname;
	std::string citycode;
	std::string districtname;
	std::string districtcode;
	std::string stationname;
	std::string stationcode;
	std::string stationattribute;
	std::string longitude;
	std::string latitude;
	std::string admincode;
	std::string timetype;
	std::string timecode;
	bool enable;		// �Ƿ�����
	std::string dir;		// ���Ŀ¼
};


// �쳣��Ϣ
struct ExceptionContext
{
	ExceptionContext():code(0), str() {}
	ExceptionContext(int32 c,const std::string& s):code(c),str(s) {}
	ExceptionContext(const std::string& s):code(0),str(s) {}
	int32 code;
	std::string str;
};

// �ֶ���Ǽ�¼
struct ManualMark
{
	int id;				// ��¼ID
	int type;			// ������� 1Ϊ�ֶ����,2Ϊ��ʱ���
	DeviceType devType;	// �豸����
	DataMark oldMark;	// ���ǰ
	DataMark newMark;	// ��Ǻ�
	DataMark renewMark;	// �ָ���
	String startDate;	// �������
	String endDate;		// ��������
	String code32;		// �豸����
	String content;		// ��ע��Ϣ
};
typedef std::vector<ManualMark> ManualMarkArray;


// ��ʱԤ���
struct TimeMarkItem 
{
	int32 tid;
	DeviceType devType;	// �豸����
	DataMark newMark;	// �������
	string startDate;	// ��ʼʱ��
	string endDate;		// ����ʱ��
	string content;		// ˵����Ϣ
};
typedef std::vector<TimeMarkItem> TimeMarkArray;


/**
* �����������
*/
struct TransferParamDesc {
	TransferParamDesc() :pk(ParamterType::RealTime,0){}
	TypeKey tk;		// �豸
	ParamterKey pk;	// ����
	string name;	// ����
	string format;	// ���ݸ�ʽ
};
typedef std::vector<TransferParamDesc> TransferParamDescArray;


#endif

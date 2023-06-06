#include "ControlProcess.h"
// ------------------------------------------------------------------------------------------
using namespace std;
using namespace uniset;
// ------------------------------------------------------------------------------------------

ControlProcess::ControlProcess(uniset::ObjectId id, xmlNode* cnode):
	ControlProcess_SK(id, cnode),
	delay_sensorInfo(uniset_conf()->getIntProp(cnode, "overrun_delay_msec"))
{	
	inc_sensor_ai = 2;

	if( cnode == NULL )
		throw Exception( myname + ": FAILED! not found confnode in confile!" );

	if( delay_sensorInfo < 0 )
	    delay_sensorInfo = 0;
}
// ------------------------------------------------------------------------------------------
ControlProcess::~ControlProcess()
{
}
// ------------------------------------------------------------------------------------------
ControlProcess::ControlProcess():
	ControlProcess_SK()
{
	cout << myname << ": init failed!!!!!!!!!!!!!!!"<< endl;
	throw Exception();
}
// ------------------------------------------------------------------------------------------
void ControlProcess::sensorInfo( const SensorMessage *sm )
{
	if (sm->id == Start_Timer)
	{
		if (in_Start_Timer)
			askTimer(tmSensorInfo, delay_sensorInfo, -1);
		else
			askTimer(tmSensorInfo, 0, -1);
	}

	if (sm->id == Sensor_AI)
	{
		out_Threshold_High = (in_Sensor_AI > 90);
		out_Threshold_Low = (in_Sensor_AI < 10);
	}
}
// ------------------------------------------------------------------------------------------
void ControlProcess::timerInfo( const TimerMessage *tm )
{
	if( tm->id == tmSensorInfo )
	{
		out_Sensor_AI_Out += inc_sensor_ai;

		if (out_Sensor_AI_Out > 100)
		{
			out_Sensor_AI_Out = 100;
			inc_sensor_ai = -2;
		}
		else if (out_Sensor_AI_Out < 0)
		{
			out_Sensor_AI_Out = 0;
			inc_sensor_ai = 2;
		}
	}
}
// ------------------------------------------------------------------------------------------

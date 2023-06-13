#include "ControlProcess.h"
// ------------------------------------------------------------------------------------------
using namespace std;
using namespace uniset;
// ------------------------------------------------------------------------------------------



ControlProcess::ControlProcess(uniset::ObjectId id, xmlNode* cnode):
	ControlProcess_SK(id, cnode),
	CheckWatherLevelTimer(uniset_conf()->getIntProp(cnode, "overrun_delay_msec"))
{	
	cout << "ControlProcess" << endl; 
	IncrementWatherLevel = 2; 

	if( cnode == NULL ) 
		throw Exception( myname + ": FAILED! not found confnode in confile!" );

	if( CheckWatherLevelTimer < 0 )
	    CheckWatherLevelTimer = 0;
}
// ------------------------------------------------------------------------------------------
ControlProcess::~ControlProcess()
{
}
// ------------------------------------------------------------------------------------------
ControlProcess::ControlProcess()
{
	cout << myname << ": init failed!!!!!!!!!!!!!!!"<< endl;
	throw Exception();
}
// ------------------------------------------------------------------------------------------
void ControlProcess::sensorInfo( const SensorMessage *sm )   
{
	std::cout << "sensorInfo function " << sm->id << endl; 
	if (sm->id == Start_Timer)   
	{
		if (in_Start_Timer){   
			askTimer(tmSensorInfo, CheckWatherLevelTimer, -1);   
		}
		else
			askTimer(tmSensorInfo, 0, -1);
	}

	if (sm->id == Sensor_AI)    // Sensor_AI
	{
		out_Threshold_High = (in_Sensor_AI > 90);  
		cout << out_Threshold_High << endl; 
		out_Threshold_Low = (in_Sensor_AI < 10);
	}
}
// ------------------------------------------------------------------------------------------
void ControlProcess::timerInfo( const TimerMessage *tm )
{
	if( tm->id == tmSensorInfo )
	{
		out_Sensor_AI_Out += IncrementWatherLevel;
		std::cout << out_Sensor_AI_Out << endl; 
		if (out_Sensor_AI_Out > 100)
		{
			out_Sensor_AI_Out = 100;
			IncrementWatherLevel = -2;
		}
		else if (out_Sensor_AI_Out < 0)
		{
			out_Sensor_AI_Out = 0;
			IncrementWatherLevel = 2;
		}
	}
}
// ------------------------------------------------------------------------------------------

#include "ControlProcess.h"
#include "settings.h"
// ------------------------------------------------------------------------------------------
using namespace std;
using namespace uniset;
// ------------------------------------------------------------------------------------------

ControlProcess::ControlProcess(uniset::ObjectId id, xmlNode *cnode) : ControlProcess_SK(id, cnode),
																	  StartTimerDelay(uniset_conf()->getIntProp(cnode, "overrun_delay_msec"))
{
	
	IncrementWaterLevel = 2;

	if (cnode == NULL)
		throw Exception(myname + ": FAILED! not found confnode in confile!");

	if (StartTimerDelay < 0)
		StartTimerDelay = 0;
}
// ------------------------------------------------------------------------------------------
ControlProcess::~ControlProcess()
{
}
// ------------------------------------------------------------------------------------------
ControlProcess::ControlProcess()
{
	mycrit << myname << ": init failed!!!!!!!!!!!!!!!" << endl;
	throw Exception();
}
// ------------------------------------------------------------------------------------------
void ControlProcess::sensorInfo(const SensorMessage *sm)
{

	// ЗАПУСК ПРОЦЕССА
	if(sm->id == StartProcess)
	{
		
 		myinfo<< "Start  ControlProcess"<< endl;
		if (in_StartProcess){
			
			myinfo << "Process is running" << endl;
			flagStartProcess = true;
		}
		else{
			cout << "Process stopped" << endl;
			flagStartProcess = false;
		}
	}
	else{
		
	}
	// ЗАПУСК WaterLevel
	if (flagStartProcess){
		if (sm->id == WaterLevel){
			myinfo<<"Water level is " << in_WaterLevel <<endl;	
		}
		else{
			
		}
	}
	else{

	}
}
// ------------------------------------------------------------------------------------------
void ControlProcess::step(){

	// Установка флагов
	out_LevelIsHigh = (in_WaterLevel > LevelIsHighThreshold); 
	//cout<< in_WaterLevel << "  " << LevelIsHighThreshold << endl;
	out_LevelIsCritHigh = (in_WaterLevel > LevelIsCritLosThreshold);   
	out_LevelIsLow = (in_WaterLevel < LevelIsLowThreshold);    
	out_LevelIsCritLow = (in_WaterLevel < LevelIsCritLosThreshold);  

	if(flagStartProcess){
		if(in_WaterLevel > FullLevelThreshold){
			out_SwitchOnIncLevelPump = false;
			out_SwitchOffIncLevelPump = true;
			out_SwitchOffDecLevelPump = false;
			out_SwitchOnDecLevelPump = true;
			//Создать еще датчик для сигнала 
		}else if(in_WaterLevel < EmptyLevelThreshold){
			out_SwitchOnDecLevelPump = false;
			out_SwitchOffDecLevelPump = true;
			out_SwitchOffIncLevelPump = false;
			out_SwitchOnIncLevelPump = true;
		}		
	}else{
			out_SwitchOnDecLevelPump = false;
			out_SwitchOffDecLevelPump = true;
			out_SwitchOnIncLevelPump = false;
			out_SwitchOffIncLevelPump = true;
	}
}
// ------------------------------------------------------------------------------------------
void ControlProcess::timerInfo(const TimerMessage *tm)
{
	
}
// ------------------------------------------------------------------------------------------

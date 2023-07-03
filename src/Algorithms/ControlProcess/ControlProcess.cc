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

    // Verification of LevelIsHighThreshold
	if(LevelIsHighThreshold <= 0){
        throw Exception( myname + ":LevelIsHighThreshold <= 0!" );
    }
	// Verification of LevelIsCritHighThreshold
	if(LevelIsHighThreshold <= 0){
        throw Exception( myname + ":LevelIsCritHighThreshold <= 0!" );
    }
	// Verification of LevelIsLowThreshold
	if(LevelIsLowThreshold < 0){
        throw Exception( myname + ":LevelIsLowThreshold < 0!" );
    }
	// Verification of LevelIsCritLosThreshold
	if(LevelIsCritLosThreshold <= 0){
        throw Exception( myname + ":LevelIsCritLosThreshold <= 0!" );
    }
	// Verification of FullLevelThreshold
	if(FullLevelThreshold < 0){
        throw Exception( myname + ":FullLevelThreshold < 0!" );
    }
	// Verification of EmptyLevelThreshold
	if(EmptyLevelThreshold <= 0){
        throw Exception( myname + ":EmptyLevelThreshold <= 0!" );
    }

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
			flagStartProcess = 1;
		}
		else{
			myinfo << "Process stopped" << endl;
			flagStartProcess = 0;
		}
	}
	else{
		
	}
	// ЗАПУСК WaterLevel
	if (flagStartProcess){
		if (sm->id == WaterLevel){
			myinfo << "in_WaterLevel " << in_WaterLevel << endl;	
			
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
	out_LevelIsCritHigh = (in_WaterLevel > LevelIsCritLosThreshold);   
	out_LevelIsLow = (in_WaterLevel < LevelIsLowThreshold);    
	out_LevelIsCritLow = (in_WaterLevel < LevelIsCritLosThreshold);  

	// StartProcess
	if(flagStartProcess){
		if(in_WaterLevel > LevelIsHighThreshold){
			out_SwitchOnIncLevelPump = false;
			out_SwitchOffIncLevelPump = true;
			out_SwitchOffDecLevelPump = false;
			out_SwitchOnDecLevelPump = true;

			
		}else if(in_WaterLevel < LevelIsLowThreshold){
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

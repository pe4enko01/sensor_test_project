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
	mycrit << myname << ": ControlProcess init failed!!!!!!!!!!!!!!!" << endl;
	throw Exception();
}
// ------------------------------------------------------------------------------------------
void ControlProcess::sensorInfo(const SensorMessage *sm)
{

	// ЗАПУСК ПРОЦЕССА
	if(sm->id == StartProcess)
	{	
		myinfo << myname << "----------------------------------------------------------------------------"<< endl;
		myinfo<< "(ControlProcess)_Start of process controlling the swiching on/off of the pumps in the tankers."<< endl;
 		myinfo<< "----------------------------------------------------------------------------"<< endl;

		if (in_StartProcess){
			myinfo<< "----------------------------------------------------------------------------"<< endl;
			myinfo<< "(ControlProcess)_Pumps in tankers is ON. (ControlProcess)"<< endl;
			myinfo<< "----------------------------------------------------------------------------"<< endl;

			flagStartProcess = 1;
		}
		else{
			myinfo<< "----------------------------------------------------------------------------"<< endl;
			myinfo<< "(ControlProcess)_Pumps in tankers is OFF. (ControlProcess)"<< endl;
			myinfo<< "----------------------------------------------------------------------------"<< endl;
			flagStartProcess = 0;
		}
	}
	else{
		myinfo<< "----------------------------------------------------------------------------"<< endl;
		myinfo<< "Stop of process controlling the swiching on/off of the pumps in the tanker1. (ControlProcess)"<< endl;
 		myinfo<< "----------------------------------------------------------------------------"<< endl;
	}
	// ЗАПУСК WaterLevel
	if (flagStartProcess){
		if (sm->id == WaterLevel){
			
		}
		else{
			
		}
	}
	else{

	}
}
// ------------------------------------------------------------------------------------------
void ControlProcess::step(){
	
	// StartProcess
	if(flagStartProcess){
		if(in_WaterLevel > FullLevelThreshold){
			out_SwitchOnIncLevelPump = false;
			out_SwitchOffIncLevelPump = true;
			out_SwitchOffDecLevelPump = false;
			out_SwitchOnDecLevelPump = true;

			
		}else if(in_WaterLevel < EmptyLevelThreshold){
			out_SwitchOnDecLevelPump = false;
			out_SwitchOffDecLevelPump = true;
			out_SwitchOffIncLevelPump = false;
			out_SwitchOnIncLevelPump = true;
		}		
	
		if(in_WaterLevel >= 910 ){
			isLevelHight = 1;
		}else if(in_WaterLevel <= 890){
			isLevelHight = 0;
		}
		
		

		if(in_WaterLevel <= 10 ){
			isLevelLow = 1;
		}else if(in_WaterLevel 	>= 20){
			isLevelLow = 0;
		}

		if(isLevelLow == 1){
			myinfo << "------- Water level is Low! -------" << "Water level is " << in_WaterLevel << " (ControlProcess)" << endl;
		}else if(isLevelHight == 1){
			myinfo << "------- Water level is  Hight! -------" << "Water level is  " << in_WaterLevel << " (ControlProcess)" << endl;
		}else if(isLevelLow == 0){
			myinfo << "Water level is  " << in_WaterLevel  << " (ControlProcess)" << endl;
		}else if(isLevelHight == 0){
			myinfo << "Water level is  " << in_WaterLevel  << " (ControlProcess)" << endl;
		}			

		// Установка флагов
		out_LevelIsHigh = isLevelHight; 
		//out_LevelIsCritHigh = (in_WaterLevel > LevelIsCritLosThreshold);   
		out_LevelIsLow = isLevelLow;   
		//out_LevelIsCritLow = (in_WaterLevel < LevelIsCritLosThreshold); 
	
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

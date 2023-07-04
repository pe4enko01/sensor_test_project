
#include "ImitatorTank.h"

// ------------------------------------------------------------------------------------------
using namespace std;
using namespace uniset;
// ------------------------------------------------------------------------------------------

ImitatorTank::ImitatorTank(uniset::ObjectId id, xmlNode* cnode):
	ImitatorTank_SK(id, cnode),
	CheckWaterLevelTimer(uniset_conf()->getIntProp(cnode, "overrun_delay_msec"))
{	
	cout << "ImitatorTank Constructor" << endl; 
	IncrementWaterLevel = 2; 

	if( cnode == NULL ) 
		throw Exception( myname + ": FAILED! not found confnode in confile!" );

    // Verification of varialbles
    if(TankSize <= 0){
        throw Exception( myname + ":Tank size <= 0!" );
    }
    // Verification of LevelIncSpeed
    if(LevelIncSpeed < 0){
        throw Exception( myname + ":LevelIncSpeed < 0!" );
    }
    // Verification of LevelDecSpeed
    if(LevelDecSpeed < 0){
        throw Exception( myname + ":LevelDecSpeed < 0!" );
    }

	if( CheckWaterLevelTimer < 0 )
	    CheckWaterLevelTimer = 0;
}
// ------------------------------------------------------------------------------------------
ImitatorTank::~ImitatorTank()
{
}
// ------------------------------------------------------------------------------------------
ImitatorTank::ImitatorTank()
{
	cout << myname << ": init failed!!!!!!!!!!!!!!!"<< endl;
	throw Exception();
}
// ------------------------------------------------------------------------------------------
void ImitatorTank::sensorInfo( const SensorMessage *sm )   
{
    //включение/выключение насосов
	if(sm->id == SwitchOnIncLevelPump){
        
        if(in_SwitchOnIncLevelPump){
            is_SwitchOnIncLevelPump = 1;
        }else{
            is_SwitchOnIncLevelPump = 0;
        }
    } 
    if(sm->id == SwitchOffIncLevelPump){
       if(in_SwitchOffIncLevelPump){
            is_SwitchOffIncLevelPump = 1;
        }else{
            is_SwitchOffIncLevelPump = 0;
        }
    } 
    if(sm->id == SwitchOffDecLevelPump){
       if(in_SwitchOffDecLevelPump){
            is_SwitchOffDecLevelPump = 1;
        }else{
            is_SwitchOffDecLevelPump = 0;
        }
    } 
    if(sm->id == SwitchOnDecLevelPump){
        
       if(in_SwitchOnDecLevelPump){
            is_SwitchOnDecLevelPump = 1;
        }else{
            is_SwitchOnDecLevelPump= 0;
        }
    }       
}
  
// ------------------------------------------------------------------------------------------
void ImitatorTank::step(){
    //Pump off
    if(is_SwitchOnIncLevelPump == 0 && 
    is_SwitchOffIncLevelPump == 1 && 
    is_SwitchOffDecLevelPump == 0 && 
    is_SwitchOnDecLevelPump == 1
    ){
        iniImitator = true;
        IncLevelPump = false;
        DecLevelPump = true;  
    }

    //Pump on
    if(is_SwitchOnDecLevelPump  == 0 && 
    is_SwitchOffDecLevelPump  == 1 && 
    is_SwitchOffIncLevelPump  == 0 && 
    is_SwitchOnIncLevelPump == 1
    ){
        iniImitator = true;
        DecLevelPump = false;
        IncLevelPump = true;
        
    }

    if(iniImitator){ // initialization of imitator
        if(IncLevelPump){ 
            
            out_WaterLevel = out_WaterLevel + LevelIncSpeed;
        }else if(DecLevelPump){
            
            out_WaterLevel = out_WaterLevel - LevelDecSpeed;
        }
    }

    
}   


void ImitatorTank::timerInfo(const TimerMessage *tm)
{
	
}

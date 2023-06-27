
#include "ImitatorTank.h"

// ------------------------------------------------------------------------------------------
using namespace std;
using namespace uniset;
// ------------------------------------------------------------------------------------------


bool flag;
bool is_SwitchOnIncLevelPump = false;
bool is_SwitchOffIncLevelPump  = false;
bool is_SwitchOffDecLevelPump = false;
bool is_SwitchOnDecLevelPump = false;
int initWaterLevel = 0;


ImitatorTank::ImitatorTank(uniset::ObjectId id, xmlNode* cnode):
	ImitatorTank_SK(id, cnode),
	CheckWaterLevelTimer(uniset_conf()->getIntProp(cnode, "overrun_delay_msec"))
{	
	cout << "ControlProcess" << endl; 
	IncrementWaterLevel = 2; 

	if( cnode == NULL ) 
		throw Exception( myname + ": FAILED! not found confnode in confile!" );

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
	cout << "WaterLevel is changed " << out_WaterLevel << endl;
	
	if(sm->id == SwitchOnIncLevelPump){
        cout << "SwitchOnIncLevelPump " << in_SwitchOnIncLevelPump << endl;
        if(in_SwitchOnIncLevelPump){
            is_SwitchOnIncLevelPump = true;
        }else{
            is_SwitchOnIncLevelPump = false;
        }
    } 
    if(sm->id == SwitchOffIncLevelPump){
       if(in_SwitchOffIncLevelPump){
            is_SwitchOffIncLevelPump = true;
        }else{
            is_SwitchOffIncLevelPump = false;
        }
    } 
    if(sm->id == SwitchOffDecLevelPump){
       if(in_SwitchOffDecLevelPump){
            is_SwitchOffDecLevelPump = true;
        }else{
            is_SwitchOffDecLevelPump = false;
        }
    } 
    if(sm->id == SwitchOnDecLevelPump){
        
       if(in_SwitchOnDecLevelPump){
            is_SwitchOnDecLevelPump = true;
        }else{
            is_SwitchOnDecLevelPump= false;
        }
    } 

    if(is_SwitchOnIncLevelPump == false && 
    is_SwitchOffIncLevelPump == false && 
    is_SwitchOffDecLevelPump == false && 
    is_SwitchOnDecLevelPump == false
    ){
        out_WaterLevel = 0;
    }

    if(is_SwitchOnIncLevelPump == true && 
    is_SwitchOffIncLevelPump == false && 
    is_SwitchOffDecLevelPump == true && 
    is_SwitchOnDecLevelPump == false
    ){
        out_WaterLevel = out_WaterLevel - LevelDecSpeed;
    }

    if(is_SwitchOnIncLevelPump == false && 
    is_SwitchOffIncLevelPump == true && 
    is_SwitchOffDecLevelPump == false && 
    is_SwitchOnDecLevelPump == true
    ){
        out_WaterLevel = out_WaterLevel + LevelIncSpeed;
    }

        
}
   
 
// ------------------------------------------------------------------------------------------

void ImitatorTank::timerInfo(const TimerMessage *tm)
{
	
}

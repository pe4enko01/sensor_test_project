#pragma once
#include "ControlProcess.h"
#include "State.h"

void PupmOnState::init(){
    controlprocess->PumpDryOff();
    controlprocess->PumpFillOn();
}

void PupmOnState::processLogic(){
    if(!controlprocess->start){
        State* newstate = new PumpNetralState();
        controlprocess->setState(newstate);
    }
    if(controlprocess->level > 910){
        State* newstate = new PupmOffState();
        controlprocess->setState(newstate);
    }

}
#pragma once
#include "ControlProcess.h"
#include "State.h"

void PumpNetralState::init(){
    controlprocess->PumpDryOff();
    controlprocess->PumpFillOff();
}

void PumpNetralState::processLogic(){
    if(controlprocess->start){
        State* newstate = new PupmOnState();
        controlprocess->setState(newstate);
    }
}

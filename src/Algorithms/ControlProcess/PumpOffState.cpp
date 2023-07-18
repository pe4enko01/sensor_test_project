#pragma once
#include "ControlProcess.h"
#include "State.h"


void PupmOffState::init(){
    controlprocess->PumpFillOff();
    controlprocess->PumpDryOn();
}

void PupmOffState::processLogic(){
    // if(!controlprocess->start){
    //     State* newstate = new PumpNetralState();
    //     controlprocess->setState(newstate);
    // 
}
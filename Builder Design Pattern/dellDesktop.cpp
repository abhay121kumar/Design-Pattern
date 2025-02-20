#include "dellDesktopBuilder.h"

void DellDesktopBuilder::buildMonitor(){
    desktop -> setMonitor("Dell Monitor");
}

void DellDesktopBuilder :: buildKeyBoard(){
    desktop -> setKeyBoard("Dell KeyBoard");
}

void DellDesktopBuilder :: buildSpeaker(){
    desktop -> setSpeaker("Dell Speaker");
}

void DellDesktopBuilder :: buildRam(){
    desktop -> setRam("Dell Ram");
}

void DellDesktopBuilder :: buildProcessor(){
    desktop -> setProcessor("Dell Processor");
}
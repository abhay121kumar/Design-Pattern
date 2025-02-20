#include "HpDesktopBuilder.h"

void HpDesktopBuilder::buildMonitor(){
    desktop -> setMonitor("HP Monitor");
}

void HpDesktopBuilder :: buildKeyBoard(){
    desktop -> setKeyBoard("HP KeyBoard");
}

void HpDesktopBuilder :: buildSpeaker(){
    desktop -> setSpeaker("HP Speaker");
}

void HpDesktopBuilder :: buildRam(){
    desktop -> setRam("HP Ram");
}

void HpDesktopBuilder :: buildProcessor(){
    desktop -> setProcessor("HP Processor");
}


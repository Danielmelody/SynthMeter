//
// Created by huyiming on 15-5-23.
//

#ifndef MYGAME_DATABASEHELPER_H
#define MYGAME_DATABASEHELPER_H

#include "audio/include/SimpleAudioEngine.h"

using namespace CocosDenshion;



class DataBaseHelper {
public:
    static DataBaseHelper* getInstance();
    void Record(char song, int id);
};


#endif //MYGAME_DATABASEHELPER_H

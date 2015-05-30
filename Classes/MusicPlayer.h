//
// Created by huyiming on 15-5-23.
//

#ifndef MYGAME_MUSICPLAYER_H
#define MYGAME_MUSICPLAYER_H

#include <cstdio>

#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
#include "sqlite3.h"
#include "PreDefines.h"

using namespace std;
using namespace cocos2d;
using namespace CocosDenshion;

class MusicManager: public Node {
public:

    bool init()override;

    void startRecord(string song);

    void postToRecord(string input);

    void startPlay(string song);

    void playThisFrame(void *,int,char **,char **);

    inline string getCurrentValue(){ return  value;}

    CREATE_FUNC(MusicManager);

private:

    void updatePlaying(float dt);

    void updateRecording(float dt);

private:
    sqlite3 *songs;
    int step;
    string value,song;
    char* errmsg;
};


#endif //MYGAME_MUSICPLAYER_H

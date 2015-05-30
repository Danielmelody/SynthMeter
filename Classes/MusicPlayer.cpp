//
// Created by huyiming on 15-5-23.
//

#include "MusicPlayer.h"
#include <string>


void MusicManager::startRecord(string song) {
    if(SQLITE_OK == sqlite3_open("song.db",&songs)){
        SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/001.mp3");
    }
    this->schedule(schedule_selector(MusicManager::updateRecording),1/60);

    step = 0;

}

void MusicManager::startPlay(string song) {
    if(SQLITE_OK == sqlite3_open("song.db",&songs)){
        SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/001.mp3");
    }
    this->schedule(schedule_selector(MusicManager::updatePlaying),1/60);

    step = 0;
}

void MusicManager::updatePlaying(float dt) {
    step++;

    stringstream ss;
    ss<<step;
    string sstep = ss.str();
    string sentence = "select from "+song+"while step = "+sstep;
    if(SQLITE_OK != sqlite3_exec(songs,sentence.c_str(),MusicManager::playThisFrame,NULL,&errmsg)){
        log("error sql select:%s",errmsg);
    }
}

void MusicManager::playThisFrame(void *params,int n_column,char **column_value,char **column_name) {
    value = *column_value;
}


void MusicManager::postToRecord(string input) {
    if(strlen(input.c_str()) != PRESS_NUM){
        log("try to record %d to %d",strlen(input.c_str()),PRESS_NUM);
        exit(1);
    }

    value = input;

}

void MusicManager::updateRecording(float dt) {
    step++;

    stringstream ss;
    ss<<step;
    string sstep = ss.str();
    string sentence = "insert into "+song+"(step,value) values("+sstep+","+value+")";

    if(SQLITE_OK != sqlite3_exec(songs,sentence.c_str(),NULL,NULL,&errmsg)){
        log("error sql insert:%s",errmsg);
    }
}



#include <jni.h>
#include "wusong_com_guoluapplication_MainActivity.h"
#include<stdlib.h>
#include <stdio.h>
//Log日志
#include <android/log.h>
#define LOG_TAG "System.out"
//int __android_log_print(int prio, const char* tag, const char* fmt, ...)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


int pressure = 20;
JNIEXPORT void JNICALL Java_wusong_com_guoluapplication_MainActivity_jniChangeGuolu
  (JNIEnv * env, jobject jobj){
        LOGE("开始修改progress");
        while(1){
            sleep(1000);
            pressure++;
            pressure = pressure%70;

            LOGE("C progress == %d",pressure);
        }
  };

int getProgress(){
    int temp = rand()%30;
    return pressure+ temp;
}

  JNIEXPORT jint JNICALL Java_wusong_com_guoluapplication_MainActivity_getProgress
    (JNIEnv * env, jobject jobj){
        pressure = getProgress();
        return pressure;

    };

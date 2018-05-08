//
// Created by SongUp on 2018/4/29.
//
#include "wusong_com_ccalljava_Jni.h"
#include<stdio.h>
#include<stdlib.h>

//Log日志
#include <android/log.h>
#define LOG_TAG "System.out"
//int __android_log_print(int prio, const char* tag, const char* fmt, ...)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

/**
* 让C代码调用java代码中的add(int x, int y)
*/

JNIEXPORT jint JNICALL Java_wusong_com_ccalljava_Jni_callBackAdd
  (JNIEnv * env, jobject jobj, jint ji1, jint ji2){
    //1.得到字节码文件
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = (*env)->FindClass(env, "wusong/com/ccalljava/Jni");
    //2.得到方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID methodId = (*env)->GetMethodID(env, jclazz, "add", "(II)I");
    //3.实例化该方法
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobjCall = (*env)->AllocObject(env, jclazz);
    //4.调用方法
    //jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
     jint result = (*env)->CallIntMethod(env, jobjCall, methodId, ji1, ji2);

     LOGE("x+y = %d", result);

     return result;

  };

  JNIEXPORT jint JNICALL Java_wusong_com_ccalljava_Jni_callBackCheckPass
    (JNIEnv * env, jobject jobj, jstring oriStri){
        //1.得到字节码
        jclass jclazz = (*env)->FindClass(env, "wusong/com/ccalljava/Jni");
        //得到方法
        jmethodID methodId = (*env)->GetMethodID(env, jclazz, "checkPass", "(Ljava/lang/String;)I" );
        //实例化方法
        jobject jobjCall = (*env)->AllocObject(env, jclazz);
        //调用方法
        int result = (*env)->CallIntMethod(env, jobjCall, methodId, oriStri);
        LOGE("判断密码是否正确：%d", result);

        return 10;
    };

    JNIEXPORT jstring JNICALL Java_wusong_com_ccalljava_Jni_callBackChangeStr
      (JNIEnv * env, jobject jobj, jstring jstr){
        //1.得到字节码文件
            //jclass      (*FindClass)(JNIEnv*, const char*);
            jclass jclazz = (*env)->FindClass(env, "wusong/com/ccalljava/Jni");
            //2.得到方法
            //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
            jmethodID methodId = (*env)->GetMethodID(env, jclazz, "changeStr", "(Ljava/lang/String;)V");
            //3.实例化该方法
            //jobject     (*AllocObject)(JNIEnv*, jclass);
            jobject jobjCall = (*env)->AllocObject(env, jclazz);
            //4.调用方法
            //jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
             (*env)->CallVoidMethod(env, jobjCall, methodId, jstr);

             LOGE("Java_wusong_com_ccalljava_Jni_callBackChangeStr  执行完毕");

//jstring     (*NewStringUTF)(JNIEnv*, const char*);
            jstring str = (*env)->NewStringUTF(env, "123432ewrfdsaf");

             return str;
      };

//typedef const struct JNINativeInterface* JNIEnv;
JNIEXPORT void JNICALL Java_wusong_com_ccalljava_Jni_callBackSayHello
  (JNIEnv * env, jobject jobj, jstring jstr){
  //1.得到字节码文件
      //jclass      (*FindClass)(JNIEnv*, const char*);
      jclass jclazz = (*env)->FindClass(env, "wusong/com/ccalljava/Jni");
      //2.得到静态方法
      //jmethodID GetStaticMethodID(jclass clazz, const char* name, const char* sig)
      jmethodID methodId = (*env)->GetStaticMethodID(env, jclazz, "SayHello", "(Ljava/lang/String;)V");
      //3.调用静态方法
      //void        (*CallStaticVoidMethod)(JNIEnv*, jclass, jmethodID, ...);
       (*env)->CallStaticVoidMethod(env, jclazz, methodId, jstr);

       LOGE("Java_wusong_com_ccalljava_Jni_callBackSayHello  执行完毕");
  };

  void Java_wusong_com_ccalljava_MainActivity_show
   (JNIEnv * env, jobject jobj, jstring jstr){
        //1.得到字节码文件
       //jclass      (*FindClass)(JNIEnv*, const char*);
       jclass jclazz = (*env)->FindClass(env, "wusong/com/ccalljava/MainActivity");
       //2.得到方法
       //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
       jmethodID methodId = (*env)->GetMethodID(env, jclazz, "showToast", "()V");
       //3.实例化该方法
       //jobject     (*AllocObject)(JNIEnv*, jclass);
       //jobject jobjCall = (*env)->AllocObject(env, jclazz);
       //4.调用方法
       //jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
        (*env)->CallVoidMethod(env, jobj, methodId);
        LOGE("Java_wusong_com_ccalljava_Jni_callBackChangeStr  执行完毕");
   }




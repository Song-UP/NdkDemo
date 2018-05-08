//
// Created by SongUp on 2018/4/25.
//
#include "wusong_com_javacallc_Jni.h"

/**
 * 把一个jstring转换成一个c语言的char* 类型.
 */
char* _JString2CStr(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"GB2312");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if(alen > 0) {
        rtn = (char*)malloc(alen+1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba,0);
    return rtn;
}

JNIEXPORT jint JNICALL Java_wusong_com_myapplication425_Jni_add
  (JNIEnv * env, jobject jobj, jint ji1, jint ji2){
        int result = ji1 + ji2;
        return result;
  };



  JNIEXPORT jstring JNICALL Java_wusong_com_myapplication425_Jni_addString
    (JNIEnv * env, jobject jobj, jstring str){

        char* ch1  = _JString2CStr(env, str);  //字符串转char*
        char* ch2 = "I am from C";
        strcat(ch1, ch2);  //字符串拼接
 //       (*NewStringUTF)(JNIEnv*, const char*);
        return (*env)->NewStringUTF(env, ch1);
    };

    JNIEXPORT jintArray JNICALL Java_wusong_com_myapplication425_Jni_changeArray
          (JNIEnv * env, jobject jobj, jintArray jintArr){
         // jsize       (*GetArrayLength)(JNIEnv*, jarray);   Jni 数组得到长度
            jsize len = (*env)->GetArrayLength(env, jintArr);

            //jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);  Jni int数组转 C指针
            jint* jint = (*env)->GetIntArrayElements(env, jintArr, JNI_FALSE);
            int i;
            for(i = 0; i< len; i++){
                *(jint+i) += 10;
            }
            return jintArr;
    };

    JNIEXPORT jint JNICALL Java_wusong_com_myapplication425_Jni_checkPass
      (JNIEnv * env, jobject jobj, jstring jstr){
      //char* _JString2CStr(JNIEnv* env, jstring jstr)
          char* ch = _JString2CStr(env, jstr);
          char* orien = "123456";
//        int strcmp(char *str1, char *str2);
          int a = strcmp(orien, ch);
          if(a == 0){
                return 200;
          }else{
                return 400;
          }
      };


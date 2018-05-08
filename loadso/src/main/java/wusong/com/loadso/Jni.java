package wusong.com.loadso;

/**
 * Created by SongUp on 2018/4/23.
 */

public class Jni {
    static {
        System.loadLibrary("Hello");
    }
    public native String sayHello();
}

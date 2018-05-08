package wusong.com.javacallc;

/**
 * Created by SongUp on 2018/4/25.
 */

public class Jni {
    static {
        System.loadLibrary("Hello");
    }

    public native int add(int a, int b);

    public native String addString(String aa);

    public native int[] changeArray(int[] arr);

    public native int checkPass(String str);
}

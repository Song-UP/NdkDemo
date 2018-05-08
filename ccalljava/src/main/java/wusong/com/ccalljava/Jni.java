package wusong.com.ccalljava;

import android.util.Log;
import android.widget.Toast;

/**
 * Created by SongUp on 2018/4/28.
 */

public class Jni {
    static {
        System.loadLibrary("Hello");
    }

    private static final String TAG = Jni.class.getSimpleName();
    /**
     * 当执行这个方法时，去让C调用java的方法
     */
    public native int callBackAdd(int a, int b);
    public native String callBackChangeStr(String ori);
    public native int[] callBackChangeArr(int[] arr);
    public native int callBackCheckPass(String pass);
    public native void callBackSayHello(String pass);

    public int add(int x, int y){
        Log.d(TAG, "x+y = "+(x+y));
        return (x+y);
    }
    public void changeStr(String ori){
        ori += "add from Java";
        Log.d(TAG, "newStr = "+ori);
    }

    public void ChangeArr(int[] arr){
        StringBuffer buffer = new StringBuffer();
        for (int i = 0; i<arr.length; i++){
            buffer.append(arr[i]).append(",");
        }
        Log.d(TAG, "newStr = "+buffer.toString());
    }

    public int checkPass(String password){
        int chectInt = 400;
        if ("123456".equals(password))
            chectInt =200;
        Log.d(TAG, "是否正确：" + chectInt);

        Toast.makeText(MyApplication.SINGLE, "是否正确：" + chectInt, Toast.LENGTH_SHORT).show();

        return chectInt;
    }

    //静态方法
    public static void SayHello(String oriStr){
        oriStr += "I am from Jni";
        Log.d(TAG, oriStr);
    }

}

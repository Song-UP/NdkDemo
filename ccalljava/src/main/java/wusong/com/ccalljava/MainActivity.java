package wusong.com.ccalljava;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Jni jni = new Jni();
        jni.callBackAdd(1,99);
        jni.callBackCheckPass("12343545767");
        jni.callBackChangeStr("I am from Java ");

        jni.callBackSayHello("I am from Java ");

        show();
    }

    public native void  show();

    public void showToast(){
        Toast.makeText(this, "我是由 C 调用弹出的", Toast.LENGTH_SHORT).show();
    }

}

package wusong.com.guoluapplication;

import android.os.SystemClock;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    GuoluView guoluView;
    static {
        System.loadLibrary("Hello");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        guoluView = (GuoluView) findViewById(R.id.guoluview);

    }

    public void changeGuoluView(int y){
        int hei = guoluView.getHeight() -  y*guoluView.getHeight()/70;

        Log.d("TAG", "hei = "+hei);
        guoluView.setDy(hei);
    }


    public void click(View view) {

//        new Thread(){
//            @Override
//            public void run() {
//                super.run();
//                jniChangeGuolu();
//            }
//        }.start();

        new Thread(){
            @Override
            public void run() {
                super.run();

                while (true){
                    SystemClock.sleep(1000);
                    int progress = getProgress();
                    Log.d("TAG","Java pregress == "+progress);
                    guoluView.setDy(progress);


                }

            }
        }.start();
    }

    public native void jniChangeGuolu();
    public native int getProgress();

}

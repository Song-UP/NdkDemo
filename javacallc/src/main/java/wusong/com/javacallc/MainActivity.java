package wusong.com.javacallc;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    TextView resultTv;
    Jni jni = new Jni();
    int[] intArr = new int[10];
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        resultTv = (TextView) findViewById(R.id.resultTv);

        for (int i = 0; i<intArr.length; i++){
            intArr[i] = i;
        }

    }

    public void add(View view) {
        int id = view.getId();
        switch (id){
            case R.id.addInt:
                resultTv.setText(jni.add(1,99)+"");
                break;
            case R.id.addStr:
                resultTv.setText(jni.addString("I am from Java + "));
                break;
            case R.id.changeArray:
                StringBuffer buffer = new StringBuffer();
                int[] intArr02 = jni.changeArray(intArr);
                for (int a = 0; a<intArr02.length; a++){
                    buffer.append(intArr02[a]).append(",  ");
                }
                resultTv.setText(buffer.toString());
                break;
            case R.id.checkPass:
                resultTv.setText("比较的结果是："+jni.checkPass("123456"));
        }

    }
}


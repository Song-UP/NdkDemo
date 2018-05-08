package wusong.com.ccalljava;

import android.app.Application;

/**
 * Created by SongUp on 2018/4/29.
 */

public class MyApplication extends Application {
    public static MyApplication SINGLE;
    @Override
    public void onCreate() {
        super.onCreate();

        SINGLE = this;
    }
}

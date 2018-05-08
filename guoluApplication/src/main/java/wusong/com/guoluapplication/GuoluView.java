package wusong.com.guoluapplication;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.view.View;

/**
 * Created by SongUp on 2018/5/7.
 */

public class GuoluView extends View {
    Paint paint = new Paint();

    int dy =0;
    public GuoluView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        if (dy > getHeight() *0.95){
            paint.setColor(Color.RED);
            paint.setTextSize(50);
            canvas.drawText("刚哥快跑", 0, getHeight(),paint);
            return;
        }

        paint.setColor(Color.GRAY);
        canvas.drawRect(new Rect(0,0,canvas.getWidth(), canvas.getHeight()),paint);
        paint.setColor(Color.GREEN);
        if (dy > getHeight() *0.8f)
            paint.setColor(Color.YELLOW);
        dy  = this.getHeight() -dy;
        canvas.drawRect(new Rect(0, dy, canvas.getWidth(), canvas.getHeight()),paint);
    }

    public  void  setDy(int dy){
        this.dy =this.getHeight()*dy/70;
        this.postInvalidate();
    }
}

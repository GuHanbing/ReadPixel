//
//  Tools-ReadPixel.cpp
//  ReadPixel
//
//  Created by Messier on 2017/10/27.
//

#include "Tools-ReadPixel.hpp"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
using namespace cv;
using namespace std;

/*------------------------------------------------------/
 /功能：鼠标处理事件函数
 /event:鼠标事件  x,y: 鼠标当前坐标 flag:
 /param：函数指针 
 /------------------------------------------------------*/

static void OnMouseClick(int event, int x, int y, int flag, void* param = NULL);

void setRead(const string & winName,Pixel & p)
{
    setMouseCallback(winName, OnMouseClick, &p);
}


static void OnMouseClick(int event, int x, int y, int flag, void* param /* = NULL */)
{
    Mat frame=((Pixel *)param)->mat;
    Mat HSVframe;
    static Rect rect(-1, -1, -1, -1);  //ROI
    static Point Origin(-1, -1);     //起点
    cvtColor(frame, HSVframe, COLOR_BGR2HSV);
    //左键按下，且不移动
    if (event == CV_EVENT_LBUTTONDOWN )
    {
        ((Pixel *)param)->x=x;
        ((Pixel *)param)->y=y;
        ((Pixel *)param)->H=HSVframe.at<Vec3b>(y,x)[0];
        ((Pixel *)param)->S=HSVframe.at<Vec3b>(y,x)[1];
        ((Pixel *)param)->V=HSVframe.at<Vec3b>(y,x)[2];
        ((Pixel *)param)->B=frame.at<Vec3b>(y,x)[0];
        ((Pixel *)param)->G=frame.at<Vec3b>(y,x)[1];
        ((Pixel *)param)->R=frame.at<Vec3b>(y,x)[2];
        cout<<"pixel("<<x<<','<<y<<')'<<endl;
        cout<<"H:"<<((Pixel *)param)->H<<' ';
        cout<<"S:"<<((Pixel *)param)->S<<' ';
        cout<<"V:"<<((Pixel *)param)->V<<endl;
        cout<<"B:"<<((Pixel *)param)->B<<' ';
        cout<<"G:"<<((Pixel *)param)->G<<' ';
        cout<<"R:"<<((Pixel *)param)->R<<endl<<endl;
    }
    if (event == CV_EVENT_RBUTTONDOWN )
    {
        ((Pixel *)param)->stop=true;
    }
    
}



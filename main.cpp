#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include<iostream>
using namespace cv;
using namespace std;
bool selectFlag = false;  //
/*------------------------------------------------------/
 /功能：鼠标处理事件函数
 /event:鼠标事件  x,y: 鼠标当前坐标 flag:
 /param：函数指针
 /------------------------------------------------------*/
void OnMouseMove(int event, int x, int y, int flag, void* param = NULL);


Mat frame,HSVframe;
bool stop=false;
void on_Matching(Mat g_srcImage, Mat g_templateImage);
int main()
{
    int video;
    cout<<"input No of Video:"<<endl;
    cin>>video;
    VideoCapture cap(video);
    if (!cap.isOpened())
    {
        return -1;
    }
    
    cap>>frame;
    cvtColor(frame, HSVframe, COLOR_BGR2HSV);
    namedWindow("选择目标", 1);
    setMouseCallback("选择目标", OnMouseMove, NULL);
    imshow("选择目标", HSVframe);
    
    while (!stop)
    {
        cap>>frame;
        cvtColor(frame, HSVframe, COLOR_BGR2HSV);
        imshow("选择目标", frame);
        waitKey(30);
    }
    return 0;
}


void OnMouseMove(int event, int x, int y, int flag, void* param /* = NULL */)
{
   
    static Rect rect(-1, -1, -1, -1);  //ROI
    static Point Origin(-1, -1);     //起点
    //左键按下，且不移动
    if (event == CV_EVENT_LBUTTONDOWN )
    {
        cout<<"H:"<<(int)HSVframe.at<Vec3b>(y,x)[0]<<endl;
        cout<<"S:"<<(int)HSVframe.at<Vec3b>(y,x)[1]<<endl;
        cout<<"V:"<<(int)HSVframe.at<Vec3b>(y,x)[2]<<endl;
        cout<<"B:"<<(int)frame.at<Vec3b>(y,x)[0]<<endl;
        cout<<"G:"<<(int)frame.at<Vec3b>(y,x)[1]<<endl;
        cout<<"R:"<<(int)frame.at<Vec3b>(y,x)[2]<<endl;
    }
    if (event == CV_EVENT_RBUTTONDOWN )
    {
        stop=true;
    }
    
}


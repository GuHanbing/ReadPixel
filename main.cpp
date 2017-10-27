#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include<iostream>
#include<string>
using namespace cv;
using namespace std;

#define WINDOW_NAME "目标图像"
/*------------------------------------------------------/
 /功能：鼠标处理事件函数
 /event:鼠标事件  x,y: 鼠标当前坐标 flag:
 /param：函数指针
 /------------------------------------------------------*/
void OnMouseMove(int event, int x, int y, int flag, void* param = NULL);
bool selectFlag = false;

Mat frame,HSVframe;
bool stop=false;
void on_Matching(Mat g_srcImage, Mat g_templateImage);
int main()
{
    int choice=0;
    int video=0;
    VideoCapture cap;
    cout<<"video(input:0) or image(input:1)?"<<endl;
    cin>>choice;
    
    if(choice==1)          //显示图像
    {
        cout<<"input filename:"<<endl;
        string file;
        cin>>file;
        frame=imread(file);
        if(frame.rows==0)
        {
            cout<<"can't find"<<endl;
            return -1;
        }
    }
    else                 //显示视频
    {
        cout<<"input No of Video:"<<endl;
        cin>>video;
        cap.open(video);
        if (!cap.isOpened())
        {
            cout<<"Open camera failed."<<endl;
            return -1;
        }
        cap>>frame;
    }
    
    cvtColor(frame, HSVframe, COLOR_BGR2HSV);
    namedWindow(WINDOW_NAME, 1);
    setMouseCallback(WINDOW_NAME, OnMouseMove, NULL);
    imshow(WINDOW_NAME, HSVframe);
    
    while (!stop)
    {
        if(choice==0)
        {
            cap>>frame;
            cvtColor(frame, HSVframe, COLOR_BGR2HSV);
        }
        imshow(WINDOW_NAME, frame);
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


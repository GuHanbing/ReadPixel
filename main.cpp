#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include<iostream>
using namespace cv;
using namespace std;


Mat SrcImg;              //输入图像

bool selectFlag = false;  //
/*------------------------------------------------------/
 /功能：鼠标处理事件函数
 /event:鼠标事件  x,y: 鼠标当前坐标 flag:
 /param：函数指针
 /------------------------------------------------------*/
void OnMouseMove(int event, int x, int y, int flag, void* param = NULL);


Mat frame;
int expectNum=2;
void on_Matching(Mat g_srcImage, Mat g_templateImage);
int main()
{
    VideoCapture cap(1);
    if (!cap.isOpened())
    {
        return -1;
    }
    
    cap>>frame;
    cvtColor(frame, SrcImg, COLOR_BGR2HSV);
    namedWindow("选择目标", 1);
    setMouseCallback("选择目标", OnMouseMove, NULL);
    imshow("选择目标", SrcImg);
    bool stop=false;
    while (1)
    {
        cap>>frame;
        cvtColor(frame, SrcImg, COLOR_BGR2HSV);
        imshow("选择目标", frame);
        if (waitKey(30) == 'c')
            stop = true;
    }
    waitKey(0);
    return 0;
}


void OnMouseMove(int event, int x, int y, int flag, void* param /* = NULL */)
{
   
    static Rect rect(-1, -1, -1, -1);  //ROI
    static Point Origin(-1, -1);     //起点
    //左键按下，且不移动
    if (event == CV_EVENT_LBUTTONDOWN )
    {
        cout<<"H:"<<(int)SrcImg.at<Vec3b>(y,x)[0]<<endl;
        cout<<"S:"<<(int)SrcImg.at<Vec3b>(y,x)[1]<<endl;
        cout<<"V:"<<(int)SrcImg.at<Vec3b>(y,x)[2]<<endl;
        cout<<"B:"<<(int)frame.at<Vec3b>(y,x)[0]<<endl;
        cout<<"G:"<<(int)frame.at<Vec3b>(y,x)[1]<<endl;
        cout<<"R:"<<(int)frame.at<Vec3b>(y,x)[2]<<endl;
    }
    
}


#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include<iostream>
#include<string>
#include "Tools-ReadPixel.hpp"
using namespace cv;
using namespace std;

#define WINDOW_NAME "目标图像（右键退出）"


bool stop=false;
int main()
{
    Mat frame,HSVframe;
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
    namedWindow(WINDOW_NAME, 1);
    imshow(WINDOW_NAME, frame);
    Pixel p;
    p.mat=frame;
    setRead(WINDOW_NAME,p);
    while (!p.stop)
    {
        if(choice==0)
        {
            cap>>frame;
           
        }
        imshow(WINDOW_NAME, frame);
        waitKey(30);
    }
    return 0;
}




//
//  Tools-ReadPixel.hpp
//  ReadPixel
//
//  Created by Messier on 2017/10/27.
//

#ifndef Tools_ReadPixel_hpp
#define Tools_ReadPixel_hpp
#include <opencv2/core/core.hpp>
typedef struct
{
    int x;
    int y;
    int R;
    int G;
    int B;
    int H;
    int S;
    int V;
    cv::Mat  mat;
    
    bool stop;
}Pixel;
void setRead(const std::string & winName,Pixel & p);



#endif /* Tools_ReadPixel_hpp */


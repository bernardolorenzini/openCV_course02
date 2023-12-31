//
//  main.cpp
//  OpenCV_Course02
//
//  Created by Bernardo Lorenzini on 25/07/23.
//


#include <iostream>
#include <string>
#include <core.hpp>
#include <imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

using namespace std;
using namespace cv;
/*
int main(int, char**){
std::cout << "Main Started!\n";

VideoCapture cap(0); // open the default camera
if(!cap.isOpened()) // check if we succeeded
return -1;
for(;;){
Mat frame;
cap >> frame; // get a new frame from camera
imshow("Webcam Video", frame);
if(waitKey(30) >= 0) break;
}
// the camera will be deinitialized automatically in VideoCapture destructor
return 0;
}
*/
void webcam();
void imageToGray();

int main(){
    
    webcam();
    
    return 0;
}


// --------------------- WEBCAN --------------------------

void webcam(){
    

    VideoCapture cap(0);
    
    Mat img;
    Mat imgGray;
    
    while(true){
        
        cap.read(img);
        
        
        imshow("Image",img);
        waitKey(0);

    }
    
}

// --------------------- importing imsges --------------------------
void image(){
    
    string path = "/Users/bernardolorenzini/Documents/estudos_teste/OpenCV_Course02/OpenCV_Course02/Resources/test.png";
    Mat img = imread(path);
    
    imshow("Image",img);
    waitKey(0);
    
}

// ---------------------  imAges 2 gray  and blur--------------------------



void imageToGray(){
    
    Mat imgGrayt;

    Mat imgBlur;
    Mat imgCanny;

    string path = "/Users/bernardolorenzini/Documents/estudos_teste/OpenCV_Course02/OpenCV_Course02/Resources/test.png";
    Mat imgIn = imread(path);
    imshow("Image",imgIn);

    cvtColor(imgIn, imgGrayt, COLOR_BGR2GRAY);
    imshow("gray",imgGrayt);

    GaussianBlur(imgIn, imgBlur, Size(7,7), 5,0);
    imshow("blur",imgBlur);
    
    Canny(imgBlur, imgCanny,50,150);
    imshow("canny",imgCanny);

    waitKey(0);
    
}

// --------------------- importing videos --------------------------
void videos(){
    
    string path = "/Users/bernardolorenzini/Documents/estudos_teste/OpenCV_Course02/OpenCV_Course02/Resources/test_video.mp4";
    VideoCapture cap(path);
    
    Mat img = imread(path);
    
    while(true){
        
        cap.read(img);
        
        
        imshow("Image",img);
        waitKey(20);
    }
}

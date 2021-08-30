#include <iostream>
#include <memory>
#include <stdio.h>
// OPENCV
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
// TORCH
#include <torch/script.h>
#include <torch/torch.h>

#define DEFAULT_HEIGHT 720
#define DEFAULT_WIDTH 1280
#define IMG_SIZE 512

using namespace std;
using namespace cv;


int main() {
  // Set torch module
  cout << "OpenCV version : " << CV_VERSION << endl;

  cout << "Major version : " << CV_MAJOR_VERSION << endl;

  cout << "Minor version : " << CV_MINOR_VERSION << endl;

  cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;

  // OPENCV
  cv::VideoCapture cap;
  cv::Mat frame;
  cap.open("../videos/driving.mp4");

  if (!cap.isOpened()) {
    std::cerr << "\nCannot open video\n";
  }
  while(1){
    Mat frame;
    // Capture frame-by-frame
    cap >> frame;
    // If the frame is empty, break immediately
    if (frame.empty())
      break;
    // Display the resulting frame
    imshow( "Frame", frame );
    // Press  ESC on keyboard to exit
    char c=(char)waitKey(25);
    if(c==27)
      break;
  }
  // When everything done, release the video capture object
  cap.release();
  // Closes all the frames
  destroyAllWindows();   
  return 0;

}


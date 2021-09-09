#include "convert.h"
#include <iostream>
#include <torch/script.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>


using namespace torch;

int main() {
    
    Tensor x;
    x = torch::rand({1,3,256,256}, torch::kCUDA);

    
    //Tensor tensor = output.Tensor;
    
    cv::Mat new_image1 = torchTensortoCVMat(x);

    Tensor tensor_2 = CVMatToTensor(new_image1);
    cv::imwrite("../Image/image.jpg",new_image1);

    std::cout << tensor_2 << std::endl;
    return 0;
}


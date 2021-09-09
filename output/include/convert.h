#pragma once

#include <iostream>
#include <torch/script.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>


cv::Mat torchTensortoCVMat(torch::Tensor& tensor)
    {
        tensor = tensor.squeeze().detach();
        tensor = tensor.permute({1, 2, 0}).contiguous();
        tensor = tensor.mul(255).clamp(0, 255).to(torch::kU8);
        tensor = tensor.to(torch::kCPU);
        int64_t height = tensor.size(0);
        int64_t width = tensor.size(1);
        cv::Mat mat = cv::Mat(cv::Size(width, height), CV_8UC3, tensor.data_ptr<uchar>());
        return mat.clone();
    }

torch::Tensor CVMatToTensor(cv::Mat mat)
{
    std::cout << "converting cvmat to tensor\n";
    cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
    cv::Mat matFloat;
    mat.convertTo(matFloat, CV_32F, 1.0 / 255);
    auto size = matFloat.size();
    auto nChannels = matFloat.channels();
    auto tensor = torch::from_blob(matFloat.data, {1, size.height, size.width, nChannels});
    return tensor.permute({0, 3, 1, 2});
}


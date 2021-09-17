#pragma once

#include <iostream>
#include <torch/torch.h>

struct NetImpl : torch::nn::Module {
  NetImpl()
      : 
        conv1(torch::nn::Conv2dOptions(3, 10, /*kernel_size=*/5)),
        bn1(torch::nn::BatchNorm2d(10)),
        conv2(torch::nn::Conv2dOptions(10, 20, /*kernel_size=*/5)),
        bn2(torch::nn::BatchNorm2d(20)),
        fc1(320, 50),
        fc2(50, 2) {
    register_module("conv1", conv1);
    register_module("bn1", bn1);
    register_module("conv2", conv2);
    register_module("bn2", bn2);
   // register_module("conv3", conv3);
    
    register_module("fc1", fc1);
    register_module("fc2", fc2);
  }
    torch::Tensor forward(torch::Tensor x) {
    x = torch::relu(torch::max_pool2d(conv1->forward(x), 2));
    x = torch::batch_norm(bn1->forward(x), bn1W,bnBias1W,bnmean1W,bnvar1W,true,0.9,0.001,true);
    x = torch::relu(torch::max_pool2d(conv2->forward(x), 2));
    x = torch::batch_norm(bn2->forward(x), bn2W,bnBias2W,bnmean2W,bnvar2W,true,0.9,0.001,true);
    x = x.view({-1, 320});
     x = torch::relu(fc1->forward(x));
    x = torch::dropout(x, /*p=*/0.5, /*training=*/is_training());
    x = fc2->forward(x);
    return torch::log_softmax(x, /*dim=*/1);
  }
  torch::Tensor bn1W;
  torch::Tensor bnBias1W;
  torch::Tensor bnmean1W;
  torch::Tensor bnvar1W;
  torch::nn::BatchNorm2d bn1;
  torch::Tensor bn2W;
  torch::Tensor bnBias2W;
  torch::Tensor bnmean2W;
  torch::Tensor bnvar2W;
  torch::nn::BatchNorm2d bn2;

  torch::nn::Conv2d conv1;
  torch::nn::Conv2d conv2;

//  torch::nn::Conv2d conv3;
  torch::nn::Linear fc1;
  torch::nn::Linear fc2;
};

TORCH_MODULE(Net);

#include "network.h"

#include <iostream>
#include <torch/torch.h>

using namespace torch;

int main() {
    Net network(50,10);
    network->to(torch::kCUDA);
    std::cout << network ;
    Tensor x, output;
    x = torch::rand({2,50}, torch::kCUDA);
    output = network->forward(x);
    std::cout << output;
}

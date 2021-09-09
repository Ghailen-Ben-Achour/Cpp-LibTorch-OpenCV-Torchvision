# C++-LibTorch-OpenCV-Torchvision
This is a tutorial on how to set up a C++ project using LibTorch (PyTorch C++ API), OpenCV and Torchvision. This project has been tested on Ubuntu 18.04.

------
## CUDA & cuDNN

The first step is to install the latest version of CUDA. This allows us to use the GPU in our experiments. You can download CUDA 11.4 [here](https://developer.nvidia.com/cuda-downloads).
After downloading and installing CUDA you can check its version as well as other information by running this command:
```bash
nvidia-smi
```

CUDA Deep Neural Network library (cuDNN) should then be downloaded using this [link](https://developer.nvidia.com/cudnn).

------
## LibTorch
Install libTorch (C++ DISTRIBUTIONS OF PYTORCH) [here](https://pytorch.org/). Select the adequate OS, C++ language as well as the CUDA version. The image below shows the LibTorch used is this project.

![Image](https://github.com/Ghailen-Ben-Achour/Cpp-LibTorch-OpenCV-Torchvision/blob/main/images/libtorch.png)

To test Libtorch with GPU enabled access the ```gpu``` directory. First, change the ```CMAKE_PREFIX_PATH``` in the ```CMakeLists.txt``` file to your Libtorch installation directory and then run the following commands.
```bash
mkdir build && cd build
cmake ..
make
./torchtest
```
The program should return a Cuda tensor.
You can also test Libtorch by building a simple network and running an inference on gpu. You can find an example of the project inside ```network``` folder.

------
## OpenCV
To install C++ OpenCV on Linux you can follow this [link](https://docs.opencv.org/4.5.0/d7/d9f/tutorial_linux_install.html). To test OpenCV installation you can access to ```opencv``` folder. First, edit the ```CMakeLists.txt``` file and change the ```CMAKE_PREFIX_PATH``` to your Libtorch installation path. ```OPENCV_EXTRA_MODULES_PATH``` should also be changed to your opencv installation directory. You can then run the following commands.
```bash
mkdir build && cd build
cmake ..
make
./main
```
The program should be able to read the ```.mp4``` video.

------
## Torchvision
To install ```torchvision``` you need to clone [this](https://github.com/pytorch/vision) repository and follow the C++ API instructions. In ```torchvision``` folder you can find a simple project in which we load a built in resnet18 architecture. Following the previous steps, you should change the paths and run the following commands.
```bash
mkdir build && cd build
cmake ..
make
./torch-demo
```

You should get two outputs on CPU & GPU.

------
## Torch::Tensor to cv::MAT

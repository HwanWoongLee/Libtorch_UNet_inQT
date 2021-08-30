## Libtorch_UNet_inQT
+ QT Project
+ UNet
+ Libtorch (Pytorch C API)
+ Deep Leaning, Image Segmentation

## Version
+ OS : Windows10
+ VS : VS2019
+ OpenCV : 4.5.2
+ CUDA : 10.2
+ Libtorch : CUDA 10.2 (Release, Debug)

## Usage Example
I used the MVTEC anomaly detection dataset.  
Link : https://www.mvtec.com/company/research/datasets/mvtec-ad/

### Dataset folder organization
+ dataset
  + carpet
    + train
      + image
      + mask
    + val
      + image
      + mask

__You have to match the name of the mask and image file as follows.__  
+ in image folder
  + *somename_0.png* (or .jpg, .bmp, ...)  
  + *somename_1.png* 
  + *somename_2.png* 
  + ...
+ in mask folder
  + *somename_0_mask.png* (or .jpg, .bmp, ...)  
  + *somename_1_mask.png* 
  + *somename_2_mask.png* 
  + ...

### Dataset Load
![1](https://user-images.githubusercontent.com/20108771/131289808-b283d1de-ebe2-46a5-b887-f513fe75559d.png)


### Labeling Tool
![2](https://user-images.githubusercontent.com/20108771/131289821-066e0071-f010-48fd-ba0b-34e12e57ac52.png)


### Train
![3](https://user-images.githubusercontent.com/20108771/131289840-a9c1bea5-0ccd-4d41-b52e-4a3db2d44078.png)


### Test
![4](https://user-images.githubusercontent.com/20108771/131289850-4039c739-f859-4a22-9a5f-c0dd8c510138.png)



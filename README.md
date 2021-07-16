## Pytorch_UNet_inQT
+ QT Project
+ UNet
+ Pytorch
+ Libtorch (C++)
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
![datasetload](https://user-images.githubusercontent.com/20108771/125877483-0a6c75af-c61b-4854-a2f6-885672d67719.PNG)


### Ladbeling Tool
![labeling](https://user-images.githubusercontent.com/20108771/125878038-1e4490df-af27-4fd8-9864-183a8fa5f136.PNG)


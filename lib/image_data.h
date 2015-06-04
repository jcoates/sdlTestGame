// image header: represents interface to an image
//
// Created by Joshua Coates on 6/3/15.
//

#ifndef TESTSTRUCTUREDGAME_IMAGE_DATA_H
#define TESTSTRUCTUREDGAME_IMAGE_DATA_H

#include <string>

class ImageData {
private:
    const std::string image;
    const int img_width;
    const int img_height;
    const int num_frames;
    const int frame_width;
    const int frame_height;
public:
    ImageData(std::string image, int w, int h);
    ImageData(std::string image, int w, int h,
              int num_frames, int frame_w, int frame_h);
    ImageData(const ImageData& other);
    const std::string get_image();
    const int get_img_width();
    const int get_img_height();
    const int get_num_frames();
    const int get_frame_width();
    const int get_frame_height();
};

#endif //TESTSTRUCTUREDGAME_IMAGE_DATA_H

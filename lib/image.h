//
// Created by Joshua Coates on 6/3/15.
//

#ifndef TESTSTRUCTUREDGAME_IMAGE_H
#define TESTSTRUCTUREDGAME_IMAGE_H

#include "image_data.h"

class Image {
private:
    int x;
    int y;
    int cur_frame;
    ImageData *img_data;
public:

    Image(ImageData *img_data, int x, int y);

    Image(ImageData *img_data, int x, int y, int cur_frame);

    //Getters:
    int get_x();

    int get_y();

    int get_cur_frame();

    // Access to the underlying ImageData
    int get_frame_width();

    int get_frame_height();

    const std::string *get_path();

    int get_img_width();

    int get_img_height();

    //Setters:
    void set_x(int x);

    void set_y(int y);

    void set_cur_frame(int f);
};

#endif //TESTSTRUCTUREDGAME_IMAGE_H

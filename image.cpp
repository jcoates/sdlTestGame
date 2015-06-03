// image.cpp : source for getters/setters/constructor for image representation
//
// Created by Joshua Coates on 6/3/15.
//

#include "image.h"

Image::Image(ImageData img_data, int x, int y) :
        ImageData(img_data.get_image(), img_data.get_img_width(), img_data.get_img_height()),
        x(x),
        y(y),
        cur_frame(0) { }


Image::Image(ImageData img_data, int x, int y, int cur_frame) :
        ImageData(img_data.get_image(),
                  img_data.get_img_width(),
                  img_data.get_img_height(),
                  img_data.get_num_frames(),
                  img_data.get_frame_width(),
                  img_data.get_frame_height()),
        x(x),
        y(y),
        cur_frame(cur_frame) { }

//Getters:
int Image::get_x() {
    return x;
}

int Image::get_y() {
    return y;
}

int Image::get_cur_frame() {
    return cur_frame;
}

//Setters:
void Image::set_x(int x) {
    x = x;
}

void Image::set_y(int y) {
    y = y;
}

void Image::set_cur_frame(int f) {
    cur_frame = f;
}

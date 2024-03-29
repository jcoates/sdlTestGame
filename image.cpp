// image.cpp : source for getters/setters/constructor for image representation
//
// Created by Joshua Coates on 6/3/15.
//

#include "image.h"

Image::Image(ImageData *i, int i_x, int i_y) {
    img_data = i;
    x = i_x;
    y = i_y;
    cur_frame = 0;
}

Image::Image(ImageData *i, int i_x, int i_y, int frame) {
    img_data = i;
    x = i_x;
    y = i_y;
    cur_frame = frame;
}

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

//Access to underlying ImageData
int Image::get_frame_width() {
    return img_data->get_frame_width();
}

int Image::get_frame_height() {
    return img_data->get_frame_height();
}

const std::string *Image::get_path() {
    return img_data->get_path();
}

int Image::get_img_width() {
    return img_data->get_img_width();
}

int Image::get_img_height() {
    return img_data->get_img_height();
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

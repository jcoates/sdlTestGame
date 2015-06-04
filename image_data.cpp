// image_data.cpp: actual code for constructor/getters for image_data objects
//
// Created by Joshua Coates on 6/3/15.
//

#include "image_data.h"

ImageData::ImageData(std::string image, int w, int h) : image(image),
                                                        img_width(w),
                                                        img_height(h),
                                                        num_frames(1),
                                                        frame_width(w),
                                                        frame_height(h) { }

ImageData::ImageData(std::string image, int w, int h, int num_f, int frame_w, int frame_h) : image(image),
                                                                                             img_width(w),
                                                                                             img_height(h),
                                                                                             num_frames(num_f),
                                                                                             frame_width(frame_w),
                                                                                             frame_height(frame_h) { }

const std::string ImageData::get_image() {
    return image;
}

const int ImageData::get_img_width() {
    return img_width;
}

const int ImageData::get_img_height() {
    return img_height;
}

const int ImageData::get_num_frames() {
    return num_frames;
}

const int ImageData::get_frame_width() {
    return frame_width;
}

const int ImageData::get_frame_height() {
    return frame_height;
}
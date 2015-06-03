//
// Created by Joshua Coates on 6/3/15.
//

#ifndef TESTSTRUCTUREDGAME_IMAGE_H
#define TESTSTRUCTUREDGAME_IMAGE_H

#include "image_data.h"

class Image : public ImageData {
private:
    int x;
    int y;
    int cur_frame;
public:
    Image(ImageData img_data, int x, int y);

    Image(ImageData img_data, int x, int y, int cur_frame);

    //Getters:
    int get_x();

    int get_y();

    int get_cur_frame();

    //Setters:
    void set_x(int x);

    void set_y(int y);

    void set_cur_frame(int f);
};

#endif //TESTSTRUCTUREDGAME_IMAGE_H

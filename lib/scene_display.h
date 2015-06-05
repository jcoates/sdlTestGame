//
// Created by Joshua Coates on 6/3/15.
//

#ifndef TESTSTRUCTUREDGAME_SCENE_H
#define TESTSTRUCTUREDGAME_SCENE_H

#include <list>
#include "image.h"

class SceneDisplay {
private:
    Image background;
    std::list<Image> images;
public:
    SceneDisplay(Image bg);
    SceneDisplay(Image bg, std::list<Image> imgs);
    Image* get_bg();
    std::list<Image> *get_imgs();
    void add_image(Image new_img);
    void set_imgs(std::list<Image> imgs);
};

#endif //TESTSTRUCTUREDGAME_SCENE_H

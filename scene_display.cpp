// scene.cpp : includes definition of getters/setters/etc
//
// Created by Joshua Coates on 6/3/15.
//

#include "scene_display.h"

SceneDisplay::SceneDisplay(Image bg) : background(bg) { }

SceneDisplay::SceneDisplay(Image bg, std::list<Image> imgs) : background(bg), images(imgs) { }

Image *SceneDisplay::get_bg() {
    return &background;
}

std::list<Image> *SceneDisplay::get_imgs() {
    return &images;
}

void SceneDisplay::add_image(Image new_img) {
    images.push_back(new_img);
}

void SceneDisplay::set_imgs(std::list<Image> imgs) {
    images = imgs;
}

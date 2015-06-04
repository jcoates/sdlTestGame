// scene.cpp : includes definition of getters/setters/etc
//
// Created by Joshua Coates on 6/3/15.
//

#include "scene.h"

Scene::Scene(Image bg) : background(bg) { }

Scene::Scene(Image bg, std::list<Image> imgs) : background(bg), images(imgs) { }

Image Scene::get_bg() {
    return background;
}

std::list<Image> *Scene::get_imgs() {
    return &images;
}

void Scene::add_image(Image new_img) {
    images.push_back(new_img);
}

void Scene::set_imgs(std::list<Image> imgs) {
    images = imgs;
}

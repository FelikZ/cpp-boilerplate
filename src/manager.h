#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include "stdafx.h"
using namespace tbb;
using namespace std;
using namespace cv;
using namespace dlib;

class Manager {
private:
    concurrent_queue<Mat> frames_to_process;
    concurrent_queue<Mat> frames_to_render;

public:
    Manager() {}
    ~Manager() {}
    void start();
    void render();
    void process();
    void camera();
};

void Manager::start()
{
    frontal_face_detector detector = get_frontal_face_detector();
    for (auto i = 0; i < 10000; i++) {
        parallel_invoke(
            [&]() { this->camera(); },
            [&]() { this->process(); },
            [&]() { this->render(); });
        this_thread::sleep_for(1ms);
    }
}

void Manager::render()
{
    Mat dest;
    if (!frames_to_render.try_pop(dest)) {
        return;
    }

    wcout << "0 " << endl;
}

void Manager::process()
{
    Mat dest;
    if (!frames_to_process.try_pop(dest)) {
        return;
    }
    wcout << "- " << endl;

    frames_to_render.push(dest);
}

void Manager::camera()
{
    Mat frame(Size(0, 0), CV_16U);
    frames_to_process.push(frame);
    wcout << "+ ";
}

#endif
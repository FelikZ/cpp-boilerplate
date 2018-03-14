// TasksParallel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace tbb;
using namespace std;
using namespace cv;
using namespace dlib;

class Main {
    Main() {}
    ~Main() {}
};

concurrent_queue<Mat> frames_to_process;
concurrent_queue<Mat> frames_to_render;

void render()
{
    Mat dest;
    if (!frames_to_render.try_pop(dest)) {
        return;
    }

    wcout << "0 " << endl;
}

void process()
{
    Mat dest;
    if (!frames_to_process.try_pop(dest)) {
        return;
    }
    wcout << "- " << endl;

    frames_to_render.push(dest);
}

void camera()
{
    Mat frame(Size(0, 0), CV_16U);
    frames_to_process.push(frame);
    wcout << "+ ";
}

int main()
{
    frontal_face_detector detector = get_frontal_face_detector();
    for (auto i = 0; i < 10000; i++) {
        parallel_invoke(camera, process, render);
        this_thread::sleep_for(1ms);
    }

    return 0;
}

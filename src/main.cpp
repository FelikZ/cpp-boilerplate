// TasksParallel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
using namespace cv;
using namespace dlib;
using namespace stlab;

class Main {
    sender<Mat> frames_to_process_send;
    receiver<Mat> frames_to_process_receive;

    sender<Mat> frames_to_render_send;
    receiver<Mat> frames_to_render_receive;

public:
    Main()
    {
        tie(frames_to_process_send, frames_to_process_receive) = channel<Mat>(default_executor);
        tie(frames_to_render_send, frames_to_render_receive) = channel<Mat>(default_executor);

        auto hold = frames_to_process_receive | [&](Mat dest) { process(dest); };
        auto hold2 = frames_to_render_receive | [&](Mat dest) { render(dest); };

        // It is necessary to mark the receiver side as ready, when all connections are
        // established
        frames_to_process_receive.set_ready();
        frames_to_render_receive.set_ready();

        frontal_face_detector detector = get_frontal_face_detector();
        for (auto i = 0; i < 10000; i++) {
            camera();
            this_thread::sleep_for(1ms);
        }
    }
    ~Main() {}
    void render(Mat dest)
    {
        wcout << dest.rows << " " << endl;
    }

    void process(Mat dest)
    {
        wcout << "- " << endl;
        frames_to_render_send(dest);
    }

    void camera()
    {
        Mat frame(Size(0, 0), CV_16U);
        frames_to_process_send(frame);
        wcout << "+ ";
    }
};

int main()
{
    Main m;
    return 0;
}

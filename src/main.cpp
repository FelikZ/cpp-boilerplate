// TasksParallel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace tbb;
using namespace std;

class Main {
  Main() {}
  ~Main() {}
};

struct Mat {
  int width;
  int height;
};

concurrent_queue<Mat> frames_to_process;
concurrent_queue<Mat> frames_to_render;

void render() {
  Mat dest;
  if (!frames_to_render.try_pop(dest)) {
    return;
  }

  wcout << "0 " << endl;
}

void process() {
  Mat dest;
  if (!frames_to_process.try_pop(dest)) {
    return;
  }
  wcout << "- " << endl;

  frames_to_render.push(dest);
}

void camera() {
  Mat frame = {0, 0};
  frames_to_process.push(frame);
  wcout << "+ ";
}

int main() {
  for (auto i = 0; i < 10000; i++) {
    parallel_invoke(camera, process, render);
    this_thread::sleep_for(1ms);
  }

  return 0;
}

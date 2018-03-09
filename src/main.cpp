// TasksParallel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace concurrency;
using namespace std;

void render() { wcout << "Render" << endl; }

void process() { wcout << "Process" << endl; }

void camera() { wcout << "Camera" << endl; }

int wmain() {
  for (auto i = 0; i < 10; i++) {
    task<void> t(render);
    task<void> t2(process);
    task<void> t3(camera);
  }

  this_thread::sleep_for(2s);
}

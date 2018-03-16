// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#pragma warning(push)
#pragma warning(disable : 4180)
#ifdef _WIN32
#include <sdkddkver.h>
#endif

#include <dlib/image_processing/frontal_face_detector.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <tbb/concurrent_queue.h>
#include <tbb/parallel_invoke.h>
#include <tbb/task_group.h>
#pragma warning(pop)

// TODO: reference additional headers your program requires here

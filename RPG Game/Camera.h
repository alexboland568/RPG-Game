#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <tuple>

class Camera
{

public:

	std::tuple<int, int> getPos(int x, int y, int w, int h, int px, int py, int display_width, int display_height);
};

#endif
#pragma once
#include "Vector.h"
#include "Ray.h"

class Camera
{
public:
	Camera(Vector eyePos ,Vector canvasOrgin,Vector canvasVertical ,Vector canvasHorizontal) 
	{
		orgin = eyePos;
		lower_left_corner = canvasOrgin;
		horizontal = canvasHorizontal;
		vertical = canvasVertical;
	}
	Ray getRay(float u, float v) { return Ray(orgin, lower_left_corner + horizontal * u + vertical * v); };
	Vector orgin;
	Vector lower_left_corner;
	Vector horizontal;
	Vector vertical;
};
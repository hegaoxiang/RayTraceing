#pragma once
#include "Vector.h"
#include "Ray.h"

#define PI 3.1415926
class Camera
{
public:
	Camera(float vfov,float aspect_ratio) 
	{
		float distant = 1;

		float theta = vfov * PI / 180;
		float half_height = tanf(theta / 2) * distant;
		float half_width = aspect_ratio * half_height;

		orgin = Vector(0, 0, 0);
		lower_left_corner = Vector(-half_width, -half_height, -distant);
		horizontal = Vector(2 * half_width, 0, 0);
		vertical = Vector(0, 2 * half_height, 0);
	}
	//第一个参数u是水平上的比例，第二个是竖直上的比例
	Ray getRay(float u, float v) { return Ray(orgin, lower_left_corner + horizontal * u + vertical * v - orgin); };
	Vector orgin;
	Vector lower_left_corner;
	Vector horizontal;
	Vector vertical;
};
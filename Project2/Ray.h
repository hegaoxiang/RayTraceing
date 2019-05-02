#pragma once

#include "Vector.h"

class Ray
{
public:
	Ray() {}

	//注意，第二个应该传的是方向方向方向。
	Ray(const Vector& orgin, const Vector& direction) { o = orgin; d = direction; }
	Vector origin() const { return o; }
	Vector direction() const { return d; }
	Vector point_at_parameter(float t) const { return o + t * d; }
private:
	Vector o;
	Vector d;
};

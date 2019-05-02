#pragma once

#include "Vector.h"

class Ray
{
public:
	Ray() {}
	Ray(const Vector& orgin, const Vector& direction) { o = orgin; d = direction; }
	Vector origin() const { return o; }
	Vector direction() const { return d; }
	Vector point_at_parameter(float t) const { return o + t * d; }
private:
	Vector o;
	Vector d;
};

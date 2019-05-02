#pragma once
#include <math.h>
#include <stdlib.h>
#include <iostream>

#include <math.h>
#include <stdlib.h>
#include <iostream>

class Vector {


public:
	Vector() {}
	Vector(float e0, float e1, float e2) { e[0] = e0; e[1] = e1; e[2] = e2; }
	inline float x() const { return e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }
	inline float r() const { return e[0]; }
	inline float g() const { return e[1]; }
	inline float b() const { return e[2]; }

	inline const Vector& operator+() const { return *this; }
	inline Vector operator-() const { return Vector(-e[0], -e[1], -e[2]); }
	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; };

	inline Vector& operator+=(const Vector &v2);
	inline Vector& operator-=(const Vector &v2);
	inline Vector& operator*=(const Vector &v2);
	inline Vector& operator/=(const Vector &v2);
	inline Vector& operator*=(const float t);
	inline Vector& operator/=(const float t);

	inline float length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
	inline float squared_length() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }
	inline void make_unit_vector();


	float e[3];
};



inline std::istream& operator>>(std::istream &is, Vector &t) {
	is >> t.e[0] >> t.e[1] >> t.e[2];
	return is;
}

inline std::ostream& operator<<(std::ostream &os, const Vector &t) {
	os << t.e[0] << " " << t.e[1] << " " << t.e[2];
	return os;
}

inline void Vector::make_unit_vector() {
	float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k; e[1] *= k; e[2] *= k;
}

inline Vector operator+(const Vector &v1, const Vector &v2) {
	return Vector(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline Vector operator-(const Vector &v1, const Vector &v2) {
	return Vector(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline Vector operator*(const Vector &v1, const Vector &v2) {
	return Vector(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline Vector operator/(const Vector &v1, const Vector &v2) {
	return Vector(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline Vector operator*(float t, const Vector &v) {
	return Vector(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline Vector operator/(Vector v, float t) {
	return Vector(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}

inline Vector operator*(const Vector &v, float t) {
	return Vector(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline float dot(const Vector &v1, const Vector &v2) {
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline Vector cross(const Vector &v1, const Vector &v2) {
	return Vector((v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
		(-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
		(v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
}


inline Vector& Vector::operator+=(const Vector &v) {
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}

inline Vector& Vector::operator*=(const Vector &v) {
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	e[2] *= v.e[2];
	return *this;
}

inline Vector& Vector::operator/=(const Vector &v) {
	e[0] /= v.e[0];
	e[1] /= v.e[1];
	e[2] /= v.e[2];
	return *this;
}

inline Vector& Vector::operator-=(const Vector& v) {
	e[0] -= v.e[0];
	e[1] -= v.e[1];
	e[2] -= v.e[2];
	return *this;
}

inline Vector& Vector::operator*=(const float t) {
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

inline Vector& Vector::operator/=(const float t) {
	float k = 1.0 / t;

	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
	return *this;
}

inline Vector unit_vector(Vector v) {
	return v / v.length();
}
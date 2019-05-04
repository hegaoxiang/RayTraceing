#include <iostream>
#include <fstream>
#include "Camera.h"

using namespace std;

float hitSphere(const Vector& center, float radius, const Ray& r)
{
	Vector o_minus_c = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(r.direction(), o_minus_c);
	float c = dot(o_minus_c, o_minus_c) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	
	if (discriminant < 0)
		return -1.0;
	else
		return  (-b - sqrt(discriminant)) / (2.0 * a);
}

Vector color(Ray ray)
{
	float t = hitSphere(Vector(0, 0, -1), 0.5, ray);
	if (t > 0)
	{
		Vector n =  unit_vector(ray.point_at_parameter(t) - Vector(0, 0, -1));
		return 0.5 * (n + Vector(1, 1, 1));
	}
		
	Vector unit_direction = unit_vector(ray.direction());
	t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * Vector(1.0, 1.0, 1.0) + t * Vector(0.5,0.7,1.0);
}
int main()
{
	int nx = 400;
	int ny = 200;

	#pragma region do something about ppm 
	ofstream outtfile("test.ppm", ios::trunc);
	if (!outtfile.is_open())
	{
		cout << "can not open the file\n";
		return 0;
	}
	outtfile << "P3\n" << nx << " " << ny << "\n255\n";
	#pragma endregion
	
	Camera camera(Vector(0, 0, 0), Vector(-2, -1, -1), Vector(0, 2, 0), Vector(4, 0, 0));
	
	//from left to right
	//from top to bottom
	for (int y = 0; y < ny; y++)
	{
		for (int x = 0; x < nx; x++)
		{
			float u = (float)x / (float)nx;
			float v = (float)y / (float)ny;
			Ray ray = camera.getRay(u, v);
			Vector col = color(ray);
			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);
			int ib = int(255.99 * col[2]);
			outtfile << ir << " " << ig << " " << ib << endl;
		}
	}
	return 0;
}
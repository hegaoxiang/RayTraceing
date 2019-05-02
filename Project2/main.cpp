#include <iostream>
#include <fstream>
#include "Camera.h"

using namespace std;

Vector color(Ray ray)
{
	Vector unit_direction = unit_vector(ray.direction());
	float t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * Vector(1.0, 1.0, 1.0) + t * Vector(0.0,0.0,0.0);
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
}
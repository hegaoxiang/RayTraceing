#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int nx = 200;
	int ny = 100;

	ofstream outtfile("test.ppm", ios::trunc);
	if (!outtfile.is_open())
	{
		cout << "can not open the file\n";
		return 0;
	}
	outtfile << "P3\n" << nx << " " << ny << "\n255\n";

	for (int y = 0; y < ny; y++)
	{
		for (int x = 0; x < nx; x++)
		{
			int ir = int(255.99 * ((float)y / (float)ny));
			int ig = int(255.99 * ((float)x / (float)nx));
			int ib = int(255.99 * 0.2f);
			outtfile << ir << " " << ig << " " << ib << endl;
		}
	}
}
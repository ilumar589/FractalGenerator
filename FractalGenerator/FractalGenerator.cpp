// FractalGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "Bitmap.h"

using namespace std;
using namespace CaveOfProgramming;

int main()
{
	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap{ WIDTH, HEIGHT };

	double min{ 999999 };
	double max{ -999999 };

	for (int x = 0; x <= WIDTH; x++)
	{
		for (int y = 0; y <= HEIGHT; y++)
		{
			double xFractal{ (x - WIDTH / 2) * 2.0 / WIDTH };
			double yFractal{ (y - HEIGHT / 2) * 2.0 / HEIGHT };

			if (xFractal < min)
			{
				min = xFractal;
			}

			if (xFractal > max)
			{
				max = xFractal;
			}
		}
	}

	cout << min << ", " << max << endl;

	bitmap.write("test.bmp");

    cout << "Finished!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

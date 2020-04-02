#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <bits/stdc++.h>
using namespace std;

inline complex<double> fun(complex<double> &z, complex<double> &c)
{
  return (pow(z, 2) + c);
}

const double rmi = -1.5;
const double rma = 2;
const double imi = -1;
const double ima = 1;
int max_iters = 20;

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Julia set";
	}

public:
	bool OnUserCreate() override
	{
    // Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
    if (true) {
      double dX = (rma - rmi) / (ScreenWidth());
      double dY = (ima - imi) / (ScreenHeight());
      complex<double> c(rmi + dX * (double)GetMouseX(), imi + dY * (double)GetMouseY());
      // called once per frame
      for (int x = 0; x < ScreenWidth(); x++)
        for (int y = 0; y < ScreenHeight(); y++)
        {
          complex<double> z(rmi + dX * (double)x, imi + dY * (double)y);
          int iters = 0;
          while (abs(z) < 2 && iters < max_iters)
          {
            z = fun(z, c);
            iters++;
          }
          if (iters == max_iters)
            Draw(x, y, olc::Pixel(0, 0, 0));
          else
          {
            int color = (int)255.0 * (double(max_iters - iters) / double(max_iters));
            Draw(x, y, olc::Pixel(color, color, color));
          }
        }
    } 
    return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(1000, 1000, 1, 1))
		demo.Start();

	return 0;
}

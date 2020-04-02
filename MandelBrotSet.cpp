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
int max_iters = 1;
int lastClock = 0;

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Mandelbrot set";
	}

public:
	bool OnUserCreate() override
	{
    // Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
    if (clock() - lastClock > CLOCKS_PER_SEC / max_iters) {
      double dX = (rma - rmi) / (ScreenWidth());
      double dY = (ima - imi) / (ScreenHeight());
      // called once per frame
      for (int x = 0; x < ScreenWidth(); x++)
        for (int y = 0; y < ScreenHeight(); y++)
        {
          complex<double> c(rmi + dY * x, imi + dY * y);
          complex<double> z(0, 0);
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
      lastClock = clock();
      max_iters++;
      cout<<"MAX ITERS = "<<max_iters<<endl;
    }
    return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(400, 400, 2, 2))
		demo.Start();

	return 0;
}

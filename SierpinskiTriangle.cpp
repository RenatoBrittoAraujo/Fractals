#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <bits/stdc++.h>
using namespace std;

class Example : public olc::PixelGameEngine
{
public:
  Example()
  {
    sAppName = "Sierpinski triangle";
  }

  double px = double(ScreenWidth()) / 2.0;
  double py = double(ScreenHeight()) / 2.0;
  vector<pair<double, double>> pts;

public:
  bool OnUserCreate() override
  {
    for (int x = 0; x < ScreenWidth(); x++)
    {
      for (int y = 0; y < ScreenHeight(); y++)
      {
        Draw(x, y);
      }
    }
    pts = {
      {1.0, 1.0},
      {ScreenWidth() - 1, 1.0},
      {double(ScreenWidth()) / 2.0, ScreenHeight() - 1.0}
    };
    return true;
  }

  bool OnUserUpdate(float fElapsedTime) override
  {
    Draw((int)px, (int) py, olc::BLACK);
    const pair<double, double> &tg = pts[rand() % 3];
    px = (px + tg.first) / 2.0;
    py = (py + tg.second) / 2.0;
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

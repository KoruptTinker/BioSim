#ifndef CREATURES_H
#define CREATURES_H
#include <string>
#include <utility>
#include "grid.h"

class creatures{
  public:
    creatures();
    creatures(std::string gene, grid universe);
    std::pair<int, int> getLocation();
    std::string getGene();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void setLocation(int x, int y);
    void setGene(std::string gene);
    void move(grid universe);
    int getRenderX(int w);
    int getRenderY(int h);

  private:
    int x;
    int y;
    std::string gene;
};
#endif
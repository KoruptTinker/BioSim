#include <string>
#include <utility>
#include "grid.h"

class creatures{
  public:
    creatures();
    creatures(int x, int y, std::string gene);
    std::pair<int, int> getLocation();
    std::string getGene();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void setLocation(int x, int y);
    void setGene(std::string gene);
    void move(grid universe);

  private:
    int x;
    int y;
    std::string gene;
};
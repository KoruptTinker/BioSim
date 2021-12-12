#ifndef GRID_H
#define GRID_H

class grid{
  public:
    grid();
    int** getWorld();
    void setWorld(int** world);
    bool checkEmpty(int x, int y);
    void setOccupied(int x, int y);
    void setFree(int x, int y);

  private: 
    int** world;
};

#endif
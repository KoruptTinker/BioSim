#include "./headers/grid.h"

grid::grid(){
  this->world = new int*[128];

  for(int i = 0; i<128 ;i++){
    this->world[i]= new int[128];
  }
  for(int i = 0 ; i < 128 ; i++){
    for(int j = 0 ; j < 128 ; j++){
      this->world[i][j] = 0;
    }
  }
}

int** grid::getWorld(){
  return this->world;
}

void grid::setWorld(int** world){
  this->world = world;
}

bool grid::checkEmpty(int x, int y){
  if(x < 128 && y < 128){
    return this->world[x][y] == 0;
  }
  return false;
}

void grid::setOccupied(int x, int y){
  if(x < 128 && y < 128){
    this->world[x][y] = 1;
  }
}

void grid::setFree(int x, int y){
  if(x < 128 && y < 128){
    this->world[x][y] = 0;
  }
}


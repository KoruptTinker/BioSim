#include "./headers/creatures.h"
#include "./headers/movement.h"
#include <string>
#include <utility>
#include <iostream>

creatures::creatures(){
  this->x = 0;
  this->y = 0;
  this->gene = "";
}

creatures::creatures(std::string gene, grid universe){
  this->gene = gene;
  int generatedX = 0, generatedY = 0;
  while(!universe.checkEmpty(generatedX, generatedY)){
    generatedX = (int)(((double) rand() / RAND_MAX)*127);
    generatedY = (int)(((double) rand() / RAND_MAX)*127);
  }
  this->x = generatedX;
  this->y = generatedY;
  universe.setOccupied(generatedX, generatedY);
}

std::pair<int, int> creatures::getLocation(){
  return std::make_pair(this->x, this->y);
}

std::string creatures::getGene(){
  return this->gene;
}

int creatures::getX(){
  return this->x;
}

int creatures::getY(){
  return this->y;
}

void creatures::setX(int x){
  if(x < 128 && x >= 0){
      this->x = x;
  }
}

void creatures::setY(int y){
  if(y < 128 && y >= 0){
    this->y = y;
  }
}

void creatures::setLocation(int x, int y){
  this->x = x;
  this->y = y;
}

void creatures::setGene(std::string gene){
  this->gene = gene;
}

void creatures::move(grid universe){
  double moveDecision = ((double) rand() / (RAND_MAX));
  if(moveDecision >= 0.5){
    direction directionDecision = (direction)(((double) rand() / RAND_MAX)*4);
    switch(directionDecision){
      case LEFT:
        if(universe.checkEmpty(this->x - 1, this-> y)){
          universe.setFree(this->x, this-> y);
          this->setX(this->x - 1);
          universe.setOccupied(this->x , this-> y);
        }
        break;
      case RIGHT:
        if(universe.checkEmpty(this->x + 1, this-> y)){
          universe.setFree(this->x, this-> y);
          this->setX(this->x + 1);
          universe.setOccupied(this->x , this-> y);
        }
        break;
      case UP: 
        if(universe.checkEmpty(this->x, this-> y - 1)){
          universe.setFree(this->x, this-> y);
          this->setY(this->y - 1);
          universe.setOccupied(this->x , this-> y);
        }
        break;
      case DOWN: 
        if(universe.checkEmpty(this->x, this-> y + 1)){
          universe.setFree(this->x, this-> y);
          this->setY(this->y + 1);
          universe.setOccupied(this->x , this-> y);
        }
        break;
    }
  }
}

int creatures::getRenderX(int w){
  return (int)(((double) this->x / 127)*w); 
}

int creatures::getRenderY(int h){
  return (int)(((double) this->y / 127)*h);
}
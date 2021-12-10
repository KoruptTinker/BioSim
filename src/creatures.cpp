#include "./headers/creatures.h"
#include <string>
#include <utility>

creatures::creatures(){
  this->x = 0;
  this->y = 0;
  this->gene = "";
}

creatures::creatures(int x, int y, std::string gene){
  this->x = x;
  this->y = y;
  this->gene = gene;
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
  this->x = x;
}

void creatures::setY(int y){
  this->y = y;
}

void creatures::setLocation(int x, int y){
  this->x = x;
  this->y = y;
}

void creatures::setGene(std::string gene){
  this->gene = gene;
}
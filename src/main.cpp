#include "./headers/movement.h"
#include "./headers/creatures.h"
#include "./headers/grid.h"
#include "./libraries/CImg.h"
#include <iostream>
#include <vector>

#define w 512
#define h 512
#define r 2
#define populationCount 1000

int main(){
  grid universe = *(new grid());
  creatures* population[populationCount];
  for(int i = 0; i < populationCount; i++){
    population[i] = new creatures("", universe);
  }
  cimg_library::CImgList<unsigned char> simulation;
  unsigned char blueGreen[] = {255, 100, 0};
  for(int step = 0; step < 2000; step++){
    cimg_library::CImg<unsigned char> simStep(w, h, 1, 3, 255);
    for(int i = 0; i < populationCount; i++){
      population[i]->move(universe);
      simStep.draw_circle(population[i]->getRenderX(w), population[i]->getRenderY(h), r, blueGreen);
    }
    simulation.push_back(simStep);
  }
  std::cout<<"saving video"<<std::endl;
  simulation.save_video("output.mp4", 25, "H264");
  std::cout<<"Saved video"<<std::endl;
}
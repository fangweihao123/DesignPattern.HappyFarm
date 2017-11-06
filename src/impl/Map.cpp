#include "Map.h"
#include "SimplePlayerController.h"
#include "Pasture.h"
#include "Farm.h"
#include "Orchard.h"
#include <iostream>
#include <random>
#include <ctime>

Map::Map() : player({0, 0}) {
    std::cout << "Map initialized\n";
    player.get().setController(new SimplePlayerController(&player.get()));
    srand((unsigned) time(nullptr));
    int times = rand() % 8 + 7;
    for (int i = 0; i < times; ++i) {
        generateScene();
    }
}

Map::~Map() {
    for (auto i : scenes) {
        delete i;
    }
}

void Map::eachScene(SceneStrategy *strategy) {
    std::cout << "class:Map method:eachScene\n";
    for (auto i : scenes) {
        strategy->act(i);
    }
}

void Map::eachScene(std::function<void(Scene *)> fn) {
    std::cout << "class:Map method:eachScene\n";
    for (auto i : scenes) {
        fn(i);
    }
}

void Map::generateScene(void) {
    std::cout << "class:Map method:generateScene\n";
	int randNum = rand();
    if (randNum % 3 == 0) {
        scenes.push_back(new Farm);
    } else if(randNum % 3 ==1 ){
        scenes.push_back(new Pasture);
		//std::cout<<"2222\n";
    }else{
		scenes.push_back(new Orchard);
		//std::cout<<"111\n";
    }
}

 #include "Scene.h"
#include "Entity.h"
#include "Decorator.h"
#include "Animal.h"
#include <iostream>

class SceneGenerateDecoratee : public Decoratee {
public:
    SceneGenerateDecoratee(Scene* sce) : scene(sce) {}
    virtual ~SceneGenerateDecoratee() = default;
    virtual void act(void);
private:
    Scene* scene;										//将Decoratee与Scene绑定起来
};

void SceneGenerateDecoratee::act(void) {
    std::cout << "class:SceneGenerateDecoratee method:act\n";
    scene->realGenerate();
}

class SceneCloneDecoratee : public Decoratee{
public:
	SceneCloneDecoratee(Scene* sce) : scene(sce) {}
	virtual ~SceneCloneDecoratee() = default;
	virtual void act(void);
private:
	Scene* scene;
};

void SceneCloneDecoratee::act(void){
	std::cout<<"class:SceneCloneDecoratee method:act\n";
	scene->realClone();
}

Scene::~Scene() {
    for (auto i : entities) {
        delete i;
    }
    delete generateDecorator;
}

void Scene::realGenerate(void) {
    std::cout << "class:Scene method:realGenerate\n";
    notifyObservers();
    auto newbie = this->spawn();
    newbie->attach(this);
    entities.push_back(newbie);					//在这里讲生成的新物体放入到vector中
}

void Scene::realClone(void){
	std::cout<<"class:Scene method:realClone\n";
	int length = entities.size();
	for(int i=0;i<length;i++){
		entities.push_back(entities[i]->clone());
	}
}

void Scene::generate(void) {
    std::cout << "class:Scene method:generate\n";
    auto dec = new SceneGenerateDecoratee(this);
    generateDecorator->act(dec);
    delete dec;
}

void Scene::clone(void){
	std::cout<<"class:Scene method:clone\n";
	auto dec = new SceneCloneDecoratee(this);
	generateDecorator->act(dec);
	delete dec;
}


Entity* Scene::remove(int id) {
    std::cout << "class:Scene method:remove\n";
    if (id <= 0 || id > entities.size()) {
        return nullptr;
    }
    auto entity = entities[id - 1];
    entities.erase(entities.cbegin() + id - 1);
    entity->detach(this);
    return entity;
}

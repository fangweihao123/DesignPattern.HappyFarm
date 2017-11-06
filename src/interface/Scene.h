//
// Scene.h
// 场景类，场景是农场、牧场等类型的基类
//
#ifndef SCENE_H
#define SCENE_H

#include "Observable.h"
#include "Decorator.h"
#include <functional>
#include <vector>
#include <string>

class Entity;

// 场景应该保持独立，位置信息不在场景内部   王应该是写CPP的高手
class Scene : public Observable {
public:
    // 利用移动语义构造 name，也只需要一次复制，参数没有必要使用 const 引用
    Scene(std::string n, Decorator* dec = new Decorator,Decorator* dec2 = new Decorator) :
        name(n), generateDecorator(dec),cloneDecorator(dec2) {}

    // 基类需要的析构函数
    virtual ~Scene();

    // 获取名字
    const std::string& getName() const {
        return name;
    }

    // 每个场景都是一个抽象的工厂，生产某种类型的生物
    void generate(void);
	
	//clone 当前可以克隆的animal
	void clone(void);

    // 生成生物的具体逻辑由子类提供，构成模版方法模式 在子类里面写spawn的方法
    virtual Entity* spawn(void) = 0;

	void realClone(void);
	
    // 实际生成并添加生物的操作，公开的 generate 函数是装饰器封装之后的方法
    void realGenerate(void);

    // 获取类别名称
    virtual const char* typeName() const = 0;

    // 遍历每个实体
    void eachEntity(std::function<void(Entity*)> fn) {
        for (auto i : entities) {
            fn(i);
        }
    }

    // 获取其中的某一个
    Entity* remove(int id);

private:
    // 每个场景都具有一个独立的名字
    std::string name;

    // 场景对于其中的实体具有所有权关系	Scene 中有entity
    std::vector<Entity*> entities;

protected:
    // 装饰器
    Decorator* generateDecorator;
	Decorator* cloneDecorator;
};

class SceneStrategy {
public:
    virtual void act(Scene* scene) = 0;
};

#endif // SCENE_H

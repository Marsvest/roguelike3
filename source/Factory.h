#pragma once
#include <memory>
#include "Actor.h"
#include "Config.h"

using std::shared_ptr;
using std::make_shared;

// Общий класс фабрики
class Factory {
	
public:
	Config c;
	string cn;

	Factory(string className) : c(Config()), cn(className){}

	virtual shared_ptr<Actor> createActor(Vec pos) = 0;
};


// Класс фабрики для создания игрока
class KnightFactory : public Factory {
public:
	KnightFactory() : Factory("Knight") {}

	virtual shared_ptr<Actor> createActor(Vec pos) {
		return make_shared<Knight>(pos,
			c.Get<int>(cn, "hp"),
			c.Get<int>(cn, "damage"),
			c.Get<int>(cn, "maxHp"),
			c.Get<int>(cn, "mana"),
			c.Get<int>(cn, "maxMana"),
			c.Get<string>(cn, "sym")[0]);
	}
};

// Класс фабрики для создания принцессы
class PrincessFactory : public Factory {
public:
	PrincessFactory() : Factory("Princess") {}

	virtual shared_ptr<Actor> createActor(Vec pos) {
		return make_shared<Princess>(pos,
			c.Get<int>(cn, "hp"),
			c.Get<int>(cn, "damage"),
			c.Get<int>(cn, "maxHp"),
			c.Get<int>(cn, "mana"),
			c.Get<int>(cn, "maxMana"),
			c.Get<string>(cn, "sym")[0]);
	}
};

// Класс фабрики для создания зомби
class ZombieFactory : public Factory {
public:
	ZombieFactory() : Factory("Zombie") {}

	virtual shared_ptr<Actor> createActor(Vec pos) {
		return make_shared<Zombie>(pos,
			c.Get<int>(cn, "hp"),
			c.Get<int>(cn, "damage"),
			c.Get<int>(cn, "maxHp"),
			c.Get<int>(cn, "mana"),
			c.Get<int>(cn, "maxMana"),
			c.Get<string>(cn, "sym")[0]);
	}
};

// Класс фабрики для создания дракона
class DragonFactory : public Factory {
public:
	DragonFactory() : Factory("Dragon") {}

	virtual shared_ptr<Actor> createActor(Vec pos) {
		return make_shared<Dragon>(pos,
			c.Get<int>(cn, "hp"),
			c.Get<int>(cn, "damage"),
			c.Get<int>(cn, "maxHp"),
			c.Get<int>(cn, "mana"),
			c.Get<int>(cn, "maxMana"),
			c.Get<string>(cn, "sym")[0]);
	}
};

// Класс фабрики для создания аптечек
class AidKitFactory : public Factory {
public:
	AidKitFactory() : Factory("AidKit") {}

	virtual shared_ptr<Actor> createActor(Vec pos) {
		return make_shared<AidKit>(pos,
			c.Get<int>(cn, "restoreHp"),
			c.Get<string>(cn, "sym")[0]);
	}
};

// Класс фабрики для создания непробиваемых стен
class WallFactory : public Factory {
public:
	WallFactory() : Factory("Wall") {}

	virtual shared_ptr<Actor> createActor(Vec pos) {
		return make_shared<Wall>(pos,
			c.Get<string>(cn, "sym")[0]);
	}
};

// Класс фабрики для создания пробиваемой стены
class BreakableWallFactory : public Factory {
public:
	BreakableWallFactory() : Factory("BreakableWall") {}

	virtual shared_ptr<Actor> createActor(Vec pos) {
		return make_shared<BreakableWall>(pos,
			c.Get<int>(cn, "hp"),
			c.Get<string>(cn, "sym")[0]);
	}
};
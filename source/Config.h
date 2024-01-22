#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
#include "Actor.h"

using nlohmann::json;
using std::string;
using std::vector;
using std::ifstream;
using std::shared_ptr;
using std::make_shared;

class Config {
	json j, m;


public:
	Config() { ifstream("config.json") >> j; }

	// Импорт тумана из конфига
	std::pair<int, bool> GetFog() {
		ifstream("config.json") >> j;

		return{ j["FOG"]["distance"].get<int>() ,j["FOG"]["enable"].get<bool>() };
	}

	// Импорт общий темплейт для импорта из конфига
	template <typename T>
	T Get(string className, string paramName){
		
		return j[className][paramName].get<T>();
	}

	// Импорт карты
	json GetMapConf() {
		ifstream("mapConfig.json") >> m;
		return m;
	}
};
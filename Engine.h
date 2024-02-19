#pragma once
#include "Actor.h"
#include <list>

class Engine
{
	int frame_rate;
	std::list<Actor> actors; //все объекты на локации
	
public:
	Engine(int frame_rate_ = 60) : frame_rate(frame_rate_) {}

	void Update(); //отвечает за обновление информации об объектах

	void add_object(Fruit fruit);
};
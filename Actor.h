#pragma once

#include <SFML\Graphics.hpp>
#include "Object.h"
#include "Animator.h"
#include <list>

enum TYPES
{
	OBJECT,
	FRUIT
};

class Actor //класс, с которым будет работать движок, в нём персонаж объединяется с анимациями
{
	sf::Sprite sprite;
	Object *body = nullptr;
	Animator anim = Animator(sprite);
	std::list<Animator::Animation> animations;
	TYPES type;
public:
	
	Actor(TYPES type_, float mass, float max_health, float strength = 0.f);

	void add_animation(std::string name, std::string path, sf::Time duration, bool looping, sf::Vector2i const& start, sf::Vector2i const& size, unsigned int frames, unsigned int lines);

	~Actor();
};
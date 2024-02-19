#pragma once

#include <SFML\Graphics.hpp>
#include "Fruit.h"
#include "Animator.h"
#include <string>

//auto& walk_right_anim = anim.create_animation("walk_right", "images\\apple_animation.png", sf::seconds(0.5), true);
//walk_right_anim.add_frames(sf::Vector2i(0, 0), sf::Vector2i(48, 48), 6, 1);

enum TYPES
{
	OBJECT,
	FRUIT
};

class Actor
{
	sf::Sprite sprite;
	Object *body;
	Animator anim = Animator(sprite);
	TYPES type;
public:

	Actor(TYPES type_, float mass, float max_health, float strength = 0.f);

	void set_animation(std::string name, std::string path, sf::Time duration, bool looping, sf::Vector2f start, sf::Vector2f size, int frames, int lines);
};
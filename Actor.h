#pragma once

#include <SFML\Graphics.hpp>
#include "Body.h"
#include "Animator.h"
#include <list>
#include <map>


class Actor //класс, с которым будет работать движок, в нём персонаж объединяется с анимациями
{
	sf::Sprite& sprite;
	Body *body = nullptr;
	Animator anim;
	std::list<Animator::Animation> animations;
	std::map<int, std::string> relations;

public:
	
	Actor(sf::Sprite& sprite_, TYPES type_, float mass, float max_health, float strength = 0.f);

	void add_animation(std::string name, std::string path, sf::Time duration, bool looping, sf::Vector2i const& start, sf::Vector2i const& size, unsigned int frames, unsigned int lines);

	void create_relations(std::string name, Object::OBJECT_STATES state);

	void create_relations(std::string name, Fruit::FRUIT_STATES state);

	Body* get_obj_ptr();

	void Update(sf::Time dt);

	~Actor();
};
#include "Actor.h"

Actor::Actor(TYPES type_, float mass, float max_health, float strength)
{
	type = type_;
	if (type == TYPES::FRUIT)
	{
		body = new Fruit(mass, max_health, strength);
		return;
	}
	else if (type == TYPES::OBJECT)
	{
		body = new Object(mass, max_health);
		return;
	}
	body = nullptr;
	print_info("Wrong type in Actor constructor");
}

void Actor::add_animation(std::string name, std::string path, sf::Time duration, bool looping, sf::Vector2i start, sf::Vector2i size, int frames, int lines)
{
	Animator::Animation animation = anim.create_animation(name, path, duration, looping);
	animation.add_frames(start, size, frames, lines);
	animations.push_back(animation);
}

Actor::~Actor()
{
	delete body;
}
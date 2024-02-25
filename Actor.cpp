#include "Actor.h"

Actor::Actor(sf::Sprite& sprite_, TYPES type_, float mass, float max_health, float strength) : sprite(sprite_), anim(Animator(sprite_))
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
	else
	{
		body = nullptr;
		print_info("Wrong type in Actor constructor");
	}
}

void Actor::add_animation(std::string name, std::string path, sf::Time duration, bool looping, sf::Vector2i const& start, sf::Vector2i const& size, unsigned int frames, unsigned int lines)
{
	auto& animation = anim.create_animation(name, path, duration, looping);
	animation.add_frames(start, size, frames, lines);
	animations.push_back(animation);
}

void Actor::create_relations(std::string name, Object::OBJECT_STATES state)
{
	relations.insert(std::pair<int, std::string>(state, name));
}

void Actor::create_relations(std::string name, Fruit::FRUIT_STATES state)
{
	relations.insert(std::pair<int, std::string>(state, name));
}

Object* Actor::get_obj_ptr()
{
	if (type == TYPES::FRUIT)
		return dynamic_cast<Fruit*>(body);
	else if (type == TYPES::OBJECT)
		return body;
}

void Actor::Update(sf::Time dt)
{
	if (body->changed)
	{
		body->changed = false;
		int i = -1;
		if (type == TYPES::FRUIT)
			i = dynamic_cast<Fruit*>(body)->stands_count - 1;
		else if (type == TYPES::OBJECT)
			i = body->stands_count - 1;
		while (i >= 0)
		{
			if (dynamic_cast<Fruit*>(body)->stands[i])
			{
				anim.switch_animation(relations[i]);
				i = -1; //выходим из цикла
			}
			i--;
		}
	}
	anim.Update(dt);
}

Actor::~Actor()
{
	delete body;
}
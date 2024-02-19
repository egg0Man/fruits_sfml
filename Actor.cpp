#include "Actor.h"

Actor::Actor(TYPES type_, float mass, float max_health, float strength)
{
	type = type_;
	if (type == TYPES::FRUIT)
	{
		body = new Fruit(mass, max_health, strength);
	}
	else if (type == TYPES::OBJECT)
	{
		body = new Object(mass, max_health);
	}
}
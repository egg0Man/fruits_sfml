#include "Fruit.h"

Object::Object(float mass_, float max_health) : MASS(mass_), MAX_HEALTH(max_health) 
{
	health = MAX_HEALTH;
	x = 0;
	y = 0;
}

bool Object::is_alive()
{
	return health > 0;
}

void Object::put_damage(int damage)
{
	health -= (damage > 0) ? damage : 0;
}

void Object::move(int dx, int dy)
{
	x += dx;
	y += dy;
}

void Object::set_coord(int new_x, int new_y)
{
	x = new_x;
	y = new_y;
}

Fruit::Fruit(float mass_, float max_health_, float strength_) : Object::Object(mass_, max_health_), STRENGTH(strength_) {}
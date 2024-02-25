#include "Object.h"

Object::Object(float mass_, float max_health) : MASS(mass_), MAX_HEALTH(max_health) 
{
	health = MAX_HEALTH;
	x = 0;
	y = 0;
	for (int i = 0; i < stands_count; i++)
		stands[i] = false;
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

void Object::set_stand(OBJECT_STATES stand, bool value)
{
	if (stand < stands_count and stand >= 0)
	{
		stands[int(stand)] = value;
		changed = true;
		return;
	}
	print_info("Incorrect stand number");
}

Object::~Object()
{
	delete[] stands;
}

Fruit::Fruit(float mass_, float max_health_, float strength_) : Object::Object(mass_, max_health_), STRENGTH(strength_) 
{
	for (int i = 0; i < stands_count; i++)
		stands[i] = false;
}

void Fruit::set_stand(FRUIT_STATES stand, bool value)
{
	if (stand < stands_count and stand >= 0)
	{
		stands[int(stand)] = value;
		changed = true;
		return;
	}
	print_info("Incorrect stand number");
}

Fruit::~Fruit()
{
	delete[] stands;
}
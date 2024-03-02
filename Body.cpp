#include "Body.h"

Body::Body(TYPES type, float mass, float max_health, float strength)
{
	if (type == TYPES::OBJECT)
	{
		obj = new Object(mass, max_health);
	}
	else if (type == TYPES::FRUIT)
	{
		obj = new Fruit(mass, max_health, strength);
	}
	else
	{
		print_info("wrong type");
	}
}

bool Body::get_state(int number)
{
	if (number >= 0 and number < obj->get_states_count())
		return obj->get_state(number);
	print_info("wrong number");
	return false;
}

const bool* Body::get_all_state()
{
	return obj->get_all_states();
}

int Body::get_states_count() 
{
	return obj->get_states_count();
}

void Body::set_state(int number, bool val) 
{
	if (number >= 0 and number < obj->get_states_count())
	{
		obj->set_state(number, val);
		changed = true;
	}
	else
		print_info("wrong number of state");
}

void Body::set_full_state(bool* states, int size) 
{
	if (size != obj->get_states_count())
	{
		print_info("wrong size of states buf");
	}
	else
	{
		for (int i = 0; i < size; i++)
			set_state(i, states[i]);
	}
}

bool Body::is_alive()
{
	return obj->is_alive();
}

void Body::move(int dx, int dy)
{
	obj->x += dx;
	obj->y += dy;
}

void Body::set_coord(int new_x, int new_y)
{
	obj->x = new_x;
	obj->y = new_y;
}

Body::~Body() 
{
	delete obj;
}
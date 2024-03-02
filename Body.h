#pragma once

#include "Object.h"

enum TYPES
{
	OBJECT,
	FRUIT
};

class Body
{
	Object* obj = nullptr;

public:

	bool changed = false;

	Body(TYPES type, float mass, float max_health, float strength = 0.f); 

	bool get_state(int number);

	const bool* get_all_state();

	int get_states_count();

	void set_state(int number, bool val);

	void set_full_state(bool* states, int size);

	bool is_alive();

	void move(int dx, int dy);

	void set_coord(int new_x, int new_y);

	~Body();
};
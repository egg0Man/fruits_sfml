#pragma once
#include "General.h"

class Object //терпильный объект, который просто получает иногда урон
{
	float health;
public:
	const float MASS;
	const float MAX_HEALTH;
	int x, y;

	enum OBJECT_STATES //перечисление, созданное для удобства использования состояний
	{
		DESTROYED,
		GET_DAMAGE
	};
	int stands_count = 2;
	bool* object_states = new bool[stands_count]{false, false}; //состояние, в которых может находиться объект

	Object(float mass_, float max_health_);

	virtual bool is_alive();

	virtual void put_damage(int damage);

	virtual void move(int dx, int dy);

	virtual void set_coord(int new_x, int new_y);

	virtual void set_stand(OBJECT_STATES stand, bool value);

	~Object();
};

class Fruit : public Object //может дать по роже
{
public:
	enum FRUIT_STATES
	{
		MOVE_LEFT,
		MOVE_UP,
		MOVE_RIGHT,
		MOVE_DOWN,
		STAND_LEFT,
		STAND_RIGHT,
		HIT_LEFT,
		HIT_RIGHT,
		DEAD
	};
	const float STRENGTH;
	int stands_count = 9;
	bool* fruit_states = new bool[stands_count];

	void set_stand(FRUIT_STATES stand, bool value);

	Fruit(float mass_, float max_health_, float strength_);

	~Fruit();
};
#pragma once
#include "General.h"

class Object //терпильный объект, который просто получает иногда урон
{
	float health;
public:
	const float MASS;
	const float MAX_HEALTH;
	int x, y;

	bool changed = false;

	enum OBJECT_STATES //перечисление, созданное для удобства использования состояний
	{
		GET_DAMAGE,
		DESTROYED
	};
	static const int stands_count = 2;
	bool* stands = new bool[stands_count]{false, false}; //состояние, в которых может находиться объект

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
	//порядок важен, чем больше номер, тем приоритетнее состояние(то есть при одновременном ударе и движении, удар будет в приоритете)
	enum FRUIT_STATES
	{
		MOVE_DOWN,
		MOVE_UP,
		MOVE_LEFT,
		MOVE_RIGHT,
		STAND_LEFT,
		STAND_RIGHT,
		HIT_LEFT,
		HIT_RIGHT,
		DEAD
	};
	const float STRENGTH;
	static const int stands_count = 9;
	bool* stands = new bool[stands_count];

	void set_stand(FRUIT_STATES stand, bool value);

	Fruit(float mass_, float max_health_, float strength_);

	~Fruit();
};
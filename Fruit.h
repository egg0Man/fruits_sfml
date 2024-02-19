#pragma once

class Object //терпильный объект, который просто получает иногда урон
{
	float health;
public:
	const float MASS;
	const float MAX_HEALTH;
	int x, y;

	Object(float mass_, float max_health_);

	virtual bool is_alive();

	virtual void put_damage(int damage);

	virtual void move(int dx, int dy);

	virtual void set_coord(int new_x, int new_y);
};

class Fruit : public Object //может дать по роже
{
public:
	const float STRENGTH;

	Fruit(float mass_, float max_health_, float strength_);
};
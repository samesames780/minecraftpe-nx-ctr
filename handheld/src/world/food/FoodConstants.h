#ifndef NET_MINECRAFT_WORLD_FOOD__FoodConstants_H__
#define NET_MINECRAFT_WORLD_FOOD__FoodConstants_H__

//package net.minecraft.world.food;

class FoodConstants
{
public:
    static const int MAX_FOOD = 20;
	// number of game ticks to change health because of food
    static const int HEALTH_TICK_COUNT = 80;
	static const int HEALTH_TICK_COUNT_SIMPLE = 5;
    static const int HEAL_LEVEL = 18;

	// hunger: ticks between losing 1 food point (600 ticks = ~30s at 20tps)
	static const int EXHAUST_TICK_COUNT = 600;
	// hunger: ticks between starvation damage once food hits 0
	static const int STARVE_TICK_COUNT = 80;
	// starvation won't bring health below this value
	static const int MIN_STARVE_HEALTH = 1;
};

#endif /*NET_MINECRAFT_WORLD_FOOD__FoodConstants_H__*/

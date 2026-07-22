#ifndef NET_MINECRAFT_WORLD_FOOD__SimpleFoodData_H__
#define NET_MINECRAFT_WORLD_FOOD__SimpleFoodData_H__

//package net.minecraft.world.food;

class FoodItem;
class Player;

class SimpleFoodData
{
public:
    SimpleFoodData();

    void eat(int food);
    void eat(FoodItem* item);

    void tick(Player* player);

    int getFoodLevel() const { return foodLevel; }
private:
	int foodLevel;
	int exhaustionTimer;
	int starveTimer;
};

#endif /*NET_MINECRAFT_WORLD_FOOD__SimpleFoodData_H__*/

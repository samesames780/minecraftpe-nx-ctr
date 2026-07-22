#include "SimpleFoodData.h"
#include "FoodConstants.h"
#include "../item/FoodItem.h"
#include "../entity/player/Player.h"

SimpleFoodData::SimpleFoodData()
:	foodLevel(FoodConstants::MAX_FOOD),
	exhaustionTimer(0),
	starveTimer(0)
{
}

void SimpleFoodData::eat( int food ) {
	foodLevel = Mth::Min(food + foodLevel, FoodConstants::MAX_FOOD);
}

void SimpleFoodData::eat( FoodItem* item ) {
	eat(item->getNutrition());
}

void SimpleFoodData::tick( Player* player ) {
	if (foodLevel > 0 && player->isHurt()) {
		const int healAmount = foodLevel;// / 2;
		player->heal(healAmount);
		foodLevel = 0;
		/*
		if (!level->isClientSide) {
			player->heal(healAmount);
		} else {
			SetHealthPacket packet(SetHealthPacket::HEALTH_MODIFY_OFFSET - healAmount);
			level->raknetInstance->send(packet);
		}
		*/
	}

	// Hunger drain over time: every EXHAUST_TICK_COUNT ticks, lose 1 food point.
	if (foodLevel > 0) {
		starveTimer = 0;
		if (++exhaustionTimer >= FoodConstants::EXHAUST_TICK_COUNT) {
			exhaustionTimer = 0;
			foodLevel--;
		}
	} else {
		// Starvation: once food hits 0, deal periodic damage down to a minimum HP,
		// same pattern as drowning damage in Mob::baseTick (hurt(NULL, dmg)).
		exhaustionTimer = 0;
		if (++starveTimer >= FoodConstants::STARVE_TICK_COUNT) {
			starveTimer = 0;
			if (player->health > FoodConstants::MIN_STARVE_HEALTH) {
				player->hurt(NULL, 1);
			}
		}
	}
}

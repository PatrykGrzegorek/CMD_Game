#include "head.h"


std::vector <HeroCard> giveHeroCard() {
	std::vector <HeroCard> allHeroCard;
	allHeroCard.push_back(HeroCard(100, "Gold Card", 25));
	allHeroCard.push_back(HeroCard(101, "Buff Dmg Card", 1));
	return allHeroCard;
}

std::vector <MapCard> giveMapCard() {
	std::vector <MapCard> allMapCard;
	allMapCard.push_back(MapCard(1, "Slime Card", "Slime"));
	allMapCard.push_back(MapCard(2, "Wampire Card", "Wampire"));
	allMapCard.push_back(MapCard(3, "Zombie Card", "Zombie"));
	return allMapCard;
}



void useMapCard(int id, char& previous) {
	switch (id) {
	case 1: {
		previous = 'S';
		break;
	}
	case 2: {
		previous = 'W';
		break;
	}
	case 3: {
		previous = 'Z';
		break;
	}
	}
}
void useHeroCard(int id, Player& player, Player& champion) {
	switch (id) {
	case 100: {
		player.setGold(player.getGold() + 25);
		break;
	}
	case 101: {
		champion.setDmg(champion.getDmg() + 1);
		break;
	}
	}

}
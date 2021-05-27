#include "head.h"


std::vector <HeroCard> giveHeroCard() {
	std::vector <HeroCard> allHeroCard;
	allHeroCard.push_back(HeroCard(100, "Zlota Karta", 25));
	allHeroCard.push_back(HeroCard(101, "Karta Ataku", 1));
	return allHeroCard;
}

std::vector <MapCard> giveMapCard() {
	std::vector <MapCard> allMapCard;
	allMapCard.push_back(MapCard(1, "Karta Slime", "Slime"));
	allMapCard.push_back(MapCard(2, "Karta Wampira", "Wampire"));
	allMapCard.push_back(MapCard(3, "Zombie Karta", "Zombie"));
	return allMapCard;
}

std::vector <MapHeroCard> giveMapHeroCard() {
	std::vector <MapHeroCard> allMapHeroCard;
	allMapHeroCard.push_back(MapHeroCard(50, "Karta Gor", 3, "Zombie"));
	return allMapHeroCard;
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
		player.setGold(player.getGold() + 10);
		break;
	}
	case 101: {
		champion.setDmg(champion.getDmg() + 1);
		break;
	}
	}

}


bool putElOnMap(char(&map)[12][21], int yMap, int xMap, char el) {
	for (int i = 0; i < yMap; i++) {
		for (int j = 0; j < xMap; j++) {
			if (map[i][j] == ' ') {
				map[i][j] = el;
				return true;
			}
		}
	}
	return false;
}

void useMapHeroCard(int id, Player& player, Player& champion, char& previous, char(&map)[12][21], int yMap, int xMap) {
	switch (id) {
	case 50: {
		char el = 'g';
		if (putElOnMap(map, yMap, xMap, el)) {
			champion.setHpMax(champion.getHpMax() + 3);
			previous = 'Z';
		}
		break;
	}
	}

}
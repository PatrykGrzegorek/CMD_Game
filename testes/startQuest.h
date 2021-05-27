#pragma once

struct Card {
	int id;
	std::string nameCard;
	Card() : id(0), nameCard("") {

	}
	Card(int _id, std::string _name) : id(_id), nameCard(_name) {

	}
};

struct HeroCard : public Card {
	int valueAction;
	HeroCard() : Card(), valueAction(0) {};
	HeroCard(int _id, std::string _name, int _value) : Card(_id, _name), valueAction(_value){

	}
};

struct MapCard : public Card {
	std::string nameEnemy;
	MapCard() : Card(), nameEnemy("") {};
	MapCard(int _id, std::string _name, std::string _nameE) : Card(_id, _name), nameEnemy(_nameE) {

	}
};

struct MapHeroCard : public Card {
	int valueAction;
	std::string nameEnemy;
	MapHeroCard() : Card(), valueAction(0), nameEnemy("")  {};
	MapHeroCard(int _id, std::string _name, int _value, std::string _nameE) : Card(_id, _name), valueAction(_value), nameEnemy(_nameE) {

	}
};

void useMapCard(int, char&);
void useHeroCard(int, Player&, Player&);
void useMapHeroCard(int, Player&, Player&, char&, char(&map)[12][21], int, int);
std::vector <HeroCard> giveHeroCard();
std::vector <MapCard> giveMapCard();
std::vector <MapHeroCard> giveMapHeroCard();



int actionQuest(int, char(&map)[12][21], int, int, int, int, Player &, Player &, std::vector <HeroCard>&, std::vector <MapCard>&, std::vector <MapHeroCard>&);
void displayArea(Player, Character);
void attackEnemy(Player&, Character);
void attackOur(Player, Character&);


void openInventory(std::vector <HeroCard>&, std::vector <MapCard>&, std::vector <MapHeroCard>&, char&, Player&, Player&, char(&map)[12][21], int, int);
void loadQuestMap(int lv, char(&map)[12][21], int, int);
void showQuestMap(char(&map)[12][21], int, int, int, int, Player, Player);
void moveQuest(char(&map)[12][21], int, int, int&, int&, char&, char&, Player&, Player&, int, int&, std::vector <HeroCard>&, std::vector <MapCard>&, std::vector <MapHeroCard>&);
void startQuest(Player&, Player, int);
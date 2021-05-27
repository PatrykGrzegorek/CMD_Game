#include "head.h"

static bool isMove = false;

void loadQuestMap(int lv, char(&map)[12][21], int yMap, int xMap) {
	std::fstream fMap;
	fMap.open("textFiles/mapQuest"+std::to_string(lv)+".txt", std::ios::in);
	if (fMap.good())
	{
		for (int i = 0; i < yMap; i++) {
			for (int j = 0; j < xMap; j++) {
				map[i][j] = fMap.get();
			}
		}
	}

	fMap.close();
}

void showQuestMap(char(&map)[12][21], int yMap, int xMap, int y, int x, Player player, Player champion) {
	system("cls");
	std::cout << "Zamknij gre: x \n";
	std::cout << "Inventory: i \n";
	std::cout << "Twoje statystyki: \n Wybrana postac: " << player.getName() << "| Gold: " << player.getGold() << "| Level: " << player.getLevel() << "| Exp: " << player.getExp() << "/" << player.getMaxExp() << "\n";
	std::cout << "Zdrowie: " << champion.getHp() << "/" << champion.getHpMax() << "| Obrazenia: " << champion.getDmg() << "| Predkosc ataku: " << (float)champion.getAs() / 100;
	std::cout << "| Pancerz: " << champion.getDef() << "| Unik: " << (float)champion.getDodge() / 100 << "\n\n";
	map[y][x] = 'x';
	for (int i = 0; i < yMap; i++) {
		for (int j = 0; j < xMap; j++) {
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

void moveQuest(char(&map)[12][21], int yMap, int xMap, int& y, int& x, char& previous, char& fromMove, Player& player, Player& champion, int lv, int& win, std::vector <HeroCard>& eqHeroCard, std::vector <MapCard>& eqMapCard, std::vector <MapHeroCard>& eqMapHeroCard) {
	using namespace std::literals::chrono_literals;
	while (!isMove) {
		if (fromMove != 'N' && map[y + 1][x] != ' ' && (int(map[y + 1][x]) == 46 || (int(map[y + 1][x]) < 91 && int(map[y + 1][x]) > 64) || int(map[y+1][x]) == 111 )) {
			fromMove = 'S';
			map[y][x] = previous;
			previous = map[y + 1][x];
			if (map[y + 1][x] != '.') {
				if (actionQuest(lv, map, yMap, xMap, y + 1, x, player, champion, eqHeroCard, eqMapCard, eqMapHeroCard) == 0) {
					win = 0;
					break;
				}
			}
			y++;
		}
		else if (fromMove != 'E' && map[y][x+1] != ' ' && (int(map[y][x + 1]) == 46 || (int(map[y][x + 1]) < 91 && int(map[y][x + 1]) > 64) || int(map[y][x + 1]) == 111)) {
			fromMove = 'W';
			map[y][x] = previous;
			previous = map[y][x + 1];
			if (map[y][x + 1] != '.') {
				if (actionQuest(lv, map, yMap, xMap, y, x + 1, player, champion, eqHeroCard, eqMapCard, eqMapHeroCard) == 0) {
					win = 0;
					break;
				}
			}
			x++;
		}
		else if (fromMove != 'S' && map[y - 1][x] != ' ' && (int(map[y - 1][x]) == 46 || (int(map[y - 1][x]) < 91 && int(map[y - 1][x]) > 64) || int(map[y-1][x]) == 111)) {
			fromMove = 'N';
			map[y][x] = previous;
			previous = map[y - 1][x];
			if (map[y - 1][x] != '.') {
				if (actionQuest(lv, map, yMap, xMap, y - 1, x, player, champion, eqHeroCard, eqMapCard, eqMapHeroCard) == 0) {
					win = 0;
					break;
				}
			}
			y--;
		}
		else if (fromMove != 'W' && map[y][x-1] != ' ' && (int(map[y][x - 1]) == 46 || (int(map[y][x - 1]) < 91 && int(map[y][x - 1]) > 64) || int(map[y][x - 1]) == 111)) {
			fromMove = 'E';
			map[y][x] = previous;
			previous = map[y][x - 1];
			if (map[y][x-1] != '.') {
				if (actionQuest(lv, map, yMap, xMap, y, x - 1, player, champion, eqHeroCard, eqMapCard, eqMapHeroCard) == 0) {
					win = 0;
					break;
				}
			}
			x--;
		}
		showQuestMap(map, yMap, xMap, y, x, player, champion);
		std::this_thread::sleep_for(0.1s);
	}
}

void openInventory(std::vector <HeroCard>& eqHeroCard, std::vector <MapCard>& eqMapCard, std::vector <MapHeroCard>& eqMapHeroCard, char& previous, Player& player, Player& champion, char(&map)[12][21], int yMap, int xMap){
	system("cls");
	int idCard;
	std::cout << "Wyjscie z inventory: 0\n\n";
	std::cout << "Twoje karty do uzycia:\n";
	std::cout << "Karty do postawienia na mapie:\n";
	for (int i = 1; i <= eqMapCard.size(); i++) {
		std::cout <<i<<". "<< eqMapCard[i-1].nameCard << std::endl;
	}
	std::cout << "Karty do konsumpcji:\n";
	for (int i = 0; i < eqHeroCard.size(); i++) {
		std::cout <<i+ eqMapCard.size()+1 <<". "<< eqHeroCard[i].nameCard << std::endl;
	}
	std::cout << "Kardy dodatkowych pol:\n";
	for (int i = 0; i < eqMapHeroCard.size(); i++) {
		std::cout << i + eqMapCard.size() + eqHeroCard.size() + 1 << ". " << eqMapHeroCard[i].nameCard << std::endl;
	}
	std::cout << "\n\nUwaga pierwszy typ kart zamienia pole pod Toba np ognisko-o na przecinika smile-S:\n\n";
	std::cout << "Podaj id karty ktorej chcesz uzyc: ";
	std::cin >> idCard;
	while (std::cin.fail() || idCard > eqHeroCard.size() + eqMapCard.size() + eqMapHeroCard.size() || idCard < 0)
	{
		std::cout << "Wprowadziles bledne dane" << std::endl;

		std::cin.clear();
		std::cin.ignore(1000, '\n');

		std::cout << "Wprowadz dane ponownie:\n";
		std::cin >> idCard;
	}
	if (idCard) {
		if (idCard > eqMapCard.size() + eqHeroCard.size()) {
			useMapHeroCard(eqMapHeroCard[idCard - eqMapCard.size() - eqHeroCard.size() - 1].id, player, champion, previous, map, yMap, xMap);
			auto itr = eqMapHeroCard.begin();
			eqMapHeroCard.erase(itr + idCard - eqMapCard.size() - eqHeroCard.size() - 1);
		}
		else if (idCard > eqMapCard.size()) {
			useHeroCard(eqHeroCard[idCard-eqMapCard.size()-1].id, player, champion);
			auto itr = eqHeroCard.begin();
			eqHeroCard.erase(itr + idCard - eqMapCard.size() - 1);
		}
		else {
			useMapCard(eqMapCard[idCard-1].id, previous );
			auto itr = eqMapCard.begin();
			eqMapCard.erase(itr + idCard - 1);
		}
	}
	else {
		return;
	}
}

void startQuest(Player& player, Player champion, int lv) {
	
	std::vector <HeroCard> eqHeroCard;
	eqHeroCard.push_back(HeroCard(101, "Buff Dmg Card", 1));
	eqHeroCard.push_back(HeroCard(100, "Gold Card", 25));
	std::vector <MapCard> eqMapCard;
	eqMapCard.push_back(MapCard(1, "Slime Card", "Slime"));
	std::vector <MapHeroCard> eqMapHeroCard;
	eqMapHeroCard.push_back(MapHeroCard(50, "Karta Gor", 3, "Zombie"));

	const static int yMap = 12, xMap = 21;
	char map[yMap][xMap];
	loadQuestMap(lv, map, yMap, xMap);
	int x, y;
	int win = 1;
	char previous='o', fromMove; //from move z gory na dol S, z dolu do gory N, z prawej do lewej W, z lewej do prawej E
	for (int i = 0; i < yMap; i++) {
		for (int j = 0; j < xMap; j++) {
			if (map[i][j] == 'o') {
				y = i; x = j;
				previous = 'o';
			}
		}
	}

	char ch = ' ';
	bool game = true;

	while (game) {
		isMove = false;
		showQuestMap(map, yMap, xMap, y, x, player, champion);
		std::thread moving(moveQuest, std::ref(map), yMap, xMap, std::ref(y), std::ref(x), std::ref(previous), std::ref(fromMove), std::ref(player), std::ref(champion), lv, std::ref(win), std::ref(eqHeroCard), std::ref(eqMapCard), std::ref(eqMapHeroCard));
		if (!win) {
			std::cout << "Umarles, wcisnij X\n";
			return;
		}
		
		ch = _getch();
		isMove = true;
		moving.join();
		switch (ch) {
		case 'i': {
			openInventory(eqHeroCard, eqMapCard, eqMapHeroCard, previous, player, champion, map, yMap, xMap);
			break;
		}
		case 'x': {
			return;
			break;
		}
		default: {break; }
		}

	}
	
}
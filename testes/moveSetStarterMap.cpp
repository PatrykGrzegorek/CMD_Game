#include "head.h"

void loadStarterMap(char(&map)[10][23], int yMap, int xMap) {
	std::fstream fMap;
	fMap.open("textFiles/map.txt", std::ios::in);
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

void shopA(Player& player) {
	bool shoping = true;
	char ch;
	int cost, hpcost;
	while (shoping) {
		system("cls");
		std::cout << "Witaj w moim sklepie poszukiwaczu przygod!! \n";
		std::cout << "Czym moge sluzyc? \n\n";
		std::cout << "Twoja ilosc zlota: " << player.getGold() << "\n";
		cost = 5+3*(player.getDmgBuff() + (player.getAsBuff()/5));
		std::cout << "Koszt ulepszania: " << cost << "\n";
		std::cout << "(wcisnij 1): Zwieksz moj atak. +1(" << player.getDmgBuff() << ")\n";
		std::cout << "(wcisnij 2): Zwieksz moj speed atack. +0.05(" << player.getAsBuff() << ")\n\n";
		hpcost = 5 + 3 * (player.getHpMaxBuff() / 4);
		std::cout << "Koszt ulepszania: " << hpcost << "\n";
		std::cout << "(wcisnij 5): Zwieksz moje hp. +4%(" << player.getHpMaxBuff() << "%)\n";
		std::cout << "(wcisnij x): 'Wyjdz ze sklepu'. \n";
		ch = _getch();
		switch (ch) {
		case '1': {
			if (player.spendGold(cost)) {
				player.setDmgByBuff(player.getDmgBuff() + 1);
			}
			break;
		}
		case '2': {
			if (player.spendGold(cost)) {
				player.setAsByBuff(player.getAsBuff() + 5);
			}
			break;
		}
		case '5': {
			if (player.spendGold(hpcost)) {
				player.setHpMaxByBuff(player.getHpMaxBuff() + 4);
			}
			break;
		}
		case 'x': {
			shoping = false;
		}
		default: {break; }
		}
	}
}
void shopO(Player& player) {
	bool shoping = true;
	char ch;
	int cost;
	while (shoping) {
		system("cls");
		std::cout << "Witaj w moim sklepie poszukiwaczu przygod!! \n";
		std::cout << "Czym moge sluzyc? \n\n";
		std::cout << "Twoja ilosc zlota: " << player.getGold() << "\n";
		if (player.getName() == "Bjorn Zelaznoboki") {
			cost = 5 + 2 * (player.getDmgBuff() + player.getDefBuff());
			std::cout << "Koszt ulepszania: " << cost << "\n\n";
			std::cout << "(wcisnij 1): Zwieksz moj atak. +1(" << player.getDmgBuff() << ")\n";
			std::cout << "(wcisnij 2): Zwieksz moj pancerz. +1(" << player.getDefBuff() << ")\n";
		}
		else {
			cost = 5 + 2 * (player.getAsBuff() + player.getDodgeBuff());
			std::cout << "Koszt ulepszania: " << cost << "\n\n";
			std::cout << "(wcisnij 1): Zwieksz moja predkosc ataku. +0.05(" << player.getAsBuff() << ")\n";
			std::cout << "(wcisnij 2): Zwieksz moja zdolnosc uniku. +1(" << player.getDodgeBuff() << ")\n";
		}
		std::cout << "(wcisnij x): 'Wyjdz ze sklepu'. \n";
		ch = _getch();
		switch (ch) {
		case '1': {
			if (player.spendGold(cost)) {
				if (player.getName() == "Bjorn Zelaznoboki") {
					player.setDmgByBuff(player.getDmgBuff() + 1);
				}
				else {
					player.setAsByBuff(player.getAsBuff() + 5);
				}
			}
			break;
		}
		case '2': {
			if (player.spendGold(cost)) {
				if (player.getName() == "Bjorn Zelaznoboki") {
					player.setDefByBuff(player.getDefBuff() + 1);
				}
				else {
					player.setDodgeByBuff(player.getDodgeBuff() + 1);
				}
				break;
			}
		}
		case 'x': {
			shoping = false;
			break;
		}
		default: {break; }
		}
	}
}
void shopD(Player& player) {
	bool shoping = true;
	char ch;
	int cost;
	while (shoping) {
		system("cls");
		std::cout << "Witaj w moim sklepie poszukiwaczu przygod!! \n";
		std::cout << "Czym moge sluzyc? \n\n";
		std::cout << "Twoja ilosc zlota: " << player.getGold() << "\n\n";
		cost = 5 + 3 * (player.getDodgeBuff() + player.getDefBuff());
		std::cout << "Koszt ulepszania: " << cost << "\n\n";
		std::cout << "(wcisnij 1): Zwieksz moj pancerz. +1("<< player.getDefBuff()<<")\n";
		std::cout << "(wcisnij 2): Zwieksz moja zdolnosc uniku. +1%(" << player.getDodgeBuff() << ")\n";
		std::cout << "(wcisnij x): 'Wyjdz ze sklepu'. \n";
		ch = _getch();
		switch (ch) {
		case '1': {
			if (player.spendGold(cost)) {
				player.setDefByBuff(player.getDefBuff() + 1);
			}
			break;
		}
		case '2': {
			if (player.spendGold(cost)) {
				player.setDodgeByBuff(player.getDodgeBuff() + 1);
			}
			break;
		}
		case 'x': {
			shoping = false;
		}
		}
	}
}

int startQuest(Player player) {
	bool shoping = true;
	char ch;
	while (shoping) {
		system("cls");
		std::cout << "Wybierz trudnosc przygody na ktora chcesz wyruszyc. \n";
		std::cout << "Dostepne poziomy \n\n";
		std::cout << "(wcisnij 1): I\n";
		if (player.getLevel() > 2) {
			std::cout << "(wcisnij 2): II\n";
		}
		std::cout << "(wcisnij x): 'Wroc do wioski'. \n\n\n";
		std::cout << "(Kolejne poziomy odblokuja sie po osiagnieciu odpowiednego levelu.) \n";
		ch = _getch();
		switch (ch) {
		case '1': {
			return 1;
			break;
		}
		case '2': {
			if (player.getLevel() > 2) {
				return 2;
			}
			break;
		}
		case 'x': {
			shoping = false;
			return 0;
		}
		default: {break; }
		}
	}
}

int moveSetStarterMap(Player &player){
	int action=0;
	const static int yMap = 10, xMap = 23;
	char map[yMap][xMap];
	loadStarterMap(map, yMap, xMap);
	int x = 19, y = 5;

	char character = 'w';
	bool game = true;

	while (game) {
		system("cls");
		std::cout <<"Ruch: wsad. Zamknij gre: x \n";
		std::cout << "Twoje statystyki: \n Wybrana postac: " << player.getName() << "| Gold: " << player.getGold() << "| Level: " << player.getLevel() << "| Exp: " << player.getExp() << "/" << player.getMaxExp()<<"\n";
		std::cout<<"Maksymalne zdrowie: " << player.getHpMax() << "| Obrazenia: " << player.getDmg() << "| Predkosc ataku: " << (float)player.getAs() / 100;
		std::cout << "| Pancerz: " << player.getDef() << "| Unik: " << (float)player.getDodge()/100<<"\n\n";
		map[y][x] = 'x';
		for (int i = 0; i < yMap; i++) {
			for (int j = 0; j < xMap; j++) {
				std::cout << map[i][j];
			}
			std::cout << std::endl;
		}
		map[y][x] = ' ';
		character = _getch();
		switch (character) {
		case 'w': {
			moveW(y, x, yMap, xMap, map, player);
			break;
		}
		case 's': {
			moveS(y, x, yMap, xMap, map, player);
			break;
		}
		case 'a': {
			moveA(y, x, yMap, xMap, map, player);
			break;
		}
		case 'd': {
			moveD(y, x, yMap, xMap, map, player, action);
			if (action) {
				return action;
			}
			break;
		}
		case 'x': {
			game = false;
			return 0;
			break;
		}
		default: {
			break;
		}
		}
	}
}

void moveW(int& y, int x, int yMap, int xMap, char map[10][23], Player& player) {
	if (y != 0 && map[y - 1][x] == ' ' ) {
		y--;
	}
	else if(map[y - 1][x] == 'A') {
		shopA(player);
	}
}

void moveS(int& y, int x, int yMap, int xMap, char map[10][23], Player& player) {
	if (y != yMap - 1 && map[y + 1][x] == ' ') {
		y++;
	}
	else if (map[y + 1][x] == 'D') {
		shopD(player);
	}
}

void moveA(int y, int& x, int yMap, int xMap, char map[10][23], Player& player) {
	if (x != 0 && map[y][x - 1] == ' ') {
		x--;
	}
	else if (map[y][x - 1] == 'O') {
		shopO(player);
	}
}

void moveD(int y, int& x, int yMap, int xMap, char map[10][23], Player player, int& action) {
	if (x != xMap - 1 && map[y ][x + 1] == ' ') {
		x++;
	}
	else if (map[y][x + 1] == '=') {
		action = startQuest(player);
	}
}
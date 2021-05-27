#include "head.h"

int main() {
	Player player = Player();
	int id;
	setupGame();
	//checkDatabase();
	int task;
	bool menu = true, runGame = true;
	while (menu) {
		std::cout << "Menu (wpisz id):\n";
		std::cout << "1 Logowanie\n";
		std::cout << "2 Rejestracja\n";
		std::cout << "3 Wyjscie\n";
		std::cin >> task;
		while (std::cin.fail())
		{
			std::cout << "Wprowadziles bledne dane" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');

			std::cout << "Wprowadz dane ponownie: ";
			std::cin >> task;
		}
		switch (task) {
		case 1: {
			login(player, id);
			menu = false;
			break;
		}
		case 2: {
			registration();
			system("cls");
			printf("Rejestracja zakonczona.\n\n");
			menu = false;
			runGame = false;
			break;
		}
		case 3: {
			menu = false;
			runGame = false;
			break;
		}
		default: {
			break;
		}
		}
	}
	while (runGame) {
		task = moveSetStarterMap(player);
		if (task) {
			startQuest(player, player, task);
		}
		else {
			saveGame(player, id);
			break;
		}
	}
	


}
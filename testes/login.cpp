#include "head.h"


bool login(Player &player, int &myid) {
	sqlite3* db;
	sqlite3_stmt* stmt;
	sqlite3_open("consolegame.db", &db);
	std::string query = "";
	int login;
	std::string password, check;
	bool checkR = true, checkCheck = true;
	int mylogin;
	const char* mypassword;
	const unsigned char* nameHero;
	bool isFalse = true;
	system("cls");
	while (checkCheck) {
		std::cout << "Podaj swoj PIN: ";
		std::cin >> login;
		while (std::cin.fail() || login > 9999 || login < 1000)
		{
			std::cout << "Wprowadziles bledne dane" << std::endl;

			std::cin.clear();
			std::cin.ignore(1000, '\n');

			std::cout << "Wprowadz dane ponownie:";
			std::cin >> login;
		}
		std::cout << "Podaj swoje haslo: ";
		std::cin >> password;

		query = "select * from account where login=" + std::to_string(login);
		sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);
		while (sqlite3_step(stmt) != SQLITE_DONE) {
			myid = sqlite3_column_int(stmt, 0);
			mylogin = sqlite3_column_int(stmt, 1);
			mypassword = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
			if (login == mylogin && password == mypassword) {
				isFalse = false;
				checkCheck = false;




				sqlite3_reset(stmt);
				query = "select * from player where id=" + std::to_string(myid);
				sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);
				sqlite3_step(stmt);
				player = Player(sqlite3_column_int(stmt, 1), sqlite3_column_int(stmt, 2), sqlite3_column_int(stmt, 3), sqlite3_column_int(stmt, 4), sqlite3_column_int(stmt, 5), sqlite3_column_int(stmt, 6), (std::string)reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7)),
					sqlite3_column_int(stmt, 8), sqlite3_column_int(stmt, 9), sqlite3_column_int(stmt, 10), sqlite3_column_int(stmt, 11), sqlite3_column_int(stmt, 12), sqlite3_column_int(stmt, 13), sqlite3_column_int(stmt, 14));
				break;
			}
		}
		if (isFalse) {
			printf("Nie poprawne dane podaj ponownie");
		}
		sqlite3_reset(stmt);
		sqlite3_finalize(stmt);
	}
	sqlite3_close(db);
}

void registration() {
	char* error;
	sqlite3* db;
	sqlite3_stmt* stmt;
	sqlite3_open("consolegame.db", &db);
	std::string query = "";
	int login;
	std::string password, check;
	bool checkR = true, checkCheck = true;
	system("cls");
	while (checkR) {
		while (checkCheck) {
			checkCheck = false;
			std::cout << "Podaj swoj PIN(1000-9999): ";
			std::cin >> login;
			while (std::cin.fail() || login>9999 || login<1000)
			{
				std::cout << "Wprowadziles bledne dane" << std::endl;

				std::cin.clear();
				std::cin.ignore(1000, '\n');

				std::cout << "Wprowadz dane ponownie:";
				std::cin >> login;
			}
			query = "select count(*) from account where login=" + std::to_string(login);
			sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);
			sqlite3_step(stmt);
			if (sqlite3_column_int(stmt, 0) != 0) {
				checkCheck = true;
				std::cout << "PIN zajety \n";
			}
		}

		checkCheck = true;
		while (checkCheck) {
			std::cout << "Podany login to: " << login << std::endl;
			std::cout << "Czy potwierdzasz? t - tak/ n - nie ";
			std::cin >> check;
			if (check == "T" || check =="t") {
				checkR = false;
				break;
			}
			else if (check == "N" || check == "n") {
				break;
			}
		}
	}
	system("cls");
	checkR = true;
	while (checkR) {
		std::cout << "Podaj swoje haslo: ";
		std::cin >> password;
		while (checkCheck) {
			system("cls");
			std::cout << "Podaj ponownie haslo: ";
			std::cin >> check;
			if (check == password) {
				checkR = false;
				break;
			}
			else{
				std::cout << "Haslo nie jest takie samo\n";
				break;
			}
		}
	}
	system("cls");
	std::cout << "Czy chcesz przerwac tworzenie konta?\n";
	std::cout << "t - tak/ n - nie\n";
	std::cin >> check;
	if (check == "T" || check == "t") {
		return;
	}


	system("cls");
	int champ;
	std::cout << "Wybierz klase postaci. Wpisujac jego id \n";
	std::cout << "1 Bjorn Zelaznoboki. \n";
	std::cout << "2 Sasuke Uzumaki. \n";
	std::cin >> champ;
	while (std::cin.fail())
	{
		std::cout << "Wprowadziles bledne dane" << std::endl;

		std::cin.clear();
		std::cin.ignore(1000, '\n');

		std::cout << "Wprowadz dane ponownie:";
		std::cin >> champ;
	}
	
	sqlite3_prepare_v2(db, "select * from account", -1, &stmt, 0);
	sqlite3_step(stmt);
	int key = sqlite3_column_int(stmt, 0)+1;
	sqlite3_reset(stmt);
	sqlite3_finalize(stmt);
	
	query = "insert into account VALUES("+std::to_string(key)+",'"+std::to_string(login)+"','"+password+"')";
	int rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &error);
	if (rc != SQLITE_OK) {
		std::cout << "error: " << error;
	}
	if (champ == 1) {
		query = "insert into player VALUES(" + std::to_string(key) + "," + std::to_string(1) + "," + std::to_string(50) + "," + std::to_string(5) + ","
			+ std::to_string(70) + "," + std::to_string(1) + "," + std::to_string(1) + ", 'Bjorn Zelaznoboki'," + std::to_string(0) + "," + std::to_string(0) + ","
			+ std::to_string(0) + "," + std::to_string(0) + "," + std::to_string(0) + "," + std::to_string(0) + "," + std::to_string(100)+")";
	}
	else {
		query = "insert into player VALUES(" + std::to_string(key) + "," + std::to_string(1) + "," + std::to_string(50) + "," + std::to_string(5) + ","
			+ std::to_string(70) + "," + std::to_string(1) + "," + std::to_string(1) + ", 'Sasuke Uchiha'," + std::to_string(0) + "," + std::to_string(0) + ","
			+ std::to_string(0) + "," + std::to_string(0) + "," + std::to_string(0) + "," + std::to_string(0) + "," + std::to_string(100) + ")";
	}
	rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &error);
	if (rc != SQLITE_OK) {
		std::cout << "error: " << error;
	}
	sqlite3_close(db);

	delete error;
}



void saveGame(Player player, int id) {
	char* error;
	sqlite3* db;
	sqlite3_open("consolegame.db", &db);
	std::string sql;
	const char* data = "Callback function called";
	/* Create merged SQL statement */
	sql = "UPDATE player set level="+std::to_string(player.getLevel())+", hpB=" + std::to_string(player.getHpBasic()) + ", dmgB=" + std::to_string(player.getDmg()) + ", asB=" + std::to_string(player.getAs())+", "\
		"defB=" + std::to_string(player.getDef()) + ", dodgeB=" + std::to_string(player.getDodge()) + ", exp=" + std::to_string(player.getExp()) + ", hpP=" + std::to_string(player.getHpMaxBuff()) + ", "\
		"dmgP=" + std::to_string(player.getDmgBuff()) + ", asP=" + std::to_string(player.getAsBuff()) + ", defP=" + std::to_string(player.getDefBuff()) + ", dodgeP=" + std::to_string(player.getDodgeBuff()) + ", "\
		"gold=" + std::to_string(player.getGold()) + " where id = "+std::to_string(id)+";";
	int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &error);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", error);
		sqlite3_free(error);
	}
	else {
		fprintf(stdout, "Zapisano\n");
	}

	sqlite3_close(db);
	delete error;
	delete data;
}
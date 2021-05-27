#include "head.h"

static bool isFight = true;
static int hpH = 40, hp;
void displayArea(Player champion, Character enemy){
	system("cls");
	std::cout << "Walka\n\n";
	std::cout << champion.getName() << "| Level: " << champion.getLevel();
	std::cout << "| zdrowie: " << champion.getHp() << "/" << champion.getHpMax() << "| Obrazenia: " << champion.getDmg() << "| Predkosc ataku: " << (float)champion.getAs() / 100;
	std::cout << "| Pancerz: " << champion.getDef() << "| Unik: " << (float)champion.getDodge() / 100 << "\n\n";
	std::cout << enemy.getName() << "| Level: " << enemy.getLevel();
	std::cout << "| zdrowie: " << enemy.getHp() << "/" << enemy.getHpMax() << "| Obrazenia: " << enemy.getDmg() << "| Predkosc ataku: " << (float)enemy.getAs() / 100;
	std::cout << "| Pancerz: " << enemy.getDef() << "| Unik: " << (float)enemy.getDodge() / 100 << "\n\n";
}

void attackEnemy(Player& champion, Character enemy) {
	using namespace std::literals::chrono_literals;
	hpH = champion.getHp();
	int ran;
	while (hpH > 0) {
		int x = 1000/((float)enemy.getAs() / 100);
		std::this_thread::sleep_for(std::chrono::milliseconds(x));
		ran = (std::rand() % 100) + 1;
		if (ran < enemy.getDodge()) {
			std::string text = "Bohater unik\n";
			std::cout << text;
		}
		else {
			if (isFight) {
				if (enemy.getDmg() < champion.getDef()) {
					hp = hp;
				}
				else {
					hpH = hpH - enemy.getDmg() + champion.getDef();
				}
			}
			else {
				break;
			}
			std::string text = "Bohater hp " + std::to_string(hpH) + "\n";
			std::cout << text;
		}
	}
	isFight = false;
	return;
}
void attackOur(Player champion, Character& enemy) {
	hp = enemy.getHp();
	int ran;
	using namespace std::literals::chrono_literals;
	while (hp > 0) {
		int x = 1000/((float)champion.getAs() / 100);
		std::this_thread::sleep_for(std::chrono::milliseconds(x));
		ran = (std::rand() % 100) + 1;
		if (ran < enemy.getDodge()) {
			std::string text = enemy.getName() + " unik\n";
			std::cout << text;
		}
		else {
			if (isFight) {
				if (champion.getDmg() < enemy.getDef()) {
					hp = hp;
				}
				else {
					hp = hp - champion.getDmg() + enemy.getDef();
				}
				std::string text = enemy.getName() + " hp " + std::to_string(hp) + "\n";
				std::cout << text;
			}
			else {
				break;
			}
			
		}
		if(hpH <= 0 ) {
			break;
		}
	}
	isFight = false;
	return;
}

int actionQuest(int lv, char(&map)[12][21], int yMap, int xMap, int y, int x, Player& player, Player& champion, std::vector <HeroCard>& eqHeroCard, std::vector <MapCard>& eqMapCard, std::vector <MapHeroCard>& eqMapHeroCard){
	char a = map[y][x];
	if (a == 'o') {
		int x = champion.getHpMax() - champion.getHp();
		if (x < 10) {
			
			champion.setHp(champion.getHpMax());
		}
		else {
			champion.setHp(champion.getHp() + 10);
		}
		return 1;
	}
	else {
		srand(time(NULL));
		int ran;
		isFight = true;

		sqlite3* db;
		sqlite3_stmt* stmt;
		std::string query = "";
		sqlite3_open("consolegame.db", &db);
		std::cout << map[y][x]<<"\n";
		std::string ch[1];
		ch[0] = map[y][x];
		std::cout << ch[0] << "\n";
		query = "select * from enemy where name like '" + ch[0]+ "%';";
		std::cout << query << "\n";
		int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);

		sqlite3_step(stmt); 
		Character enemy(lv, sqlite3_column_int(stmt, 1), sqlite3_column_int(stmt, 2), sqlite3_column_int(stmt, 3), sqlite3_column_int(stmt, 4), sqlite3_column_int(stmt, 5), (std::string)reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
		enemy.updateStatsLevel();
		displayArea(champion, enemy);
		std::thread attE(attackEnemy, std::ref(champion), enemy);
		attackOur(champion, enemy);
		sqlite3_reset(stmt);
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		isFight = false;

		using namespace std::literals::chrono_literals;

		if (hpH <= 0 && !isFight) {
			if (attE.joinable()) {
				attE.join();
			}
			std::cout << "Umarles wcisnij X albo wyjdziesz z gry\n";
			player.setExp(0-(player.getExp()/2));
			player.setGold(player.getGold() / 4);
			return 0;
		}
		else if (!isFight) {
			if (attE.joinable()) {
				attE.join();
			}
			std::cout << "Pokonales przeciwnika\n";
			std::vector <MapCard> allMapCard = giveMapCard();
			std::vector <HeroCard> allHeroCard = giveHeroCard();
			std::vector <MapHeroCard> allMapHeroCard = giveMapHeroCard();
			int box = (allMapCard.size() + allHeroCard.size() + allMapHeroCard.size())+2;
			ran = std::rand() % box + 1;
			if (ran <= allMapCard.size()) {
				std::cout << "\n\n Drop: " << allMapCard[ran - 1].nameCard << "\n\n";
				eqMapCard.push_back(allMapCard[ran-1]);
			}
			else if (ran <= allHeroCard.size() + allMapCard.size()) {
				std::cout << "\n\n Drop: " << allHeroCard[ran - allMapCard.size() - 1].nameCard << "\n\n";
				eqHeroCard.push_back(allHeroCard[ran - allMapCard.size() -1]);
			}
			else if (ran <= allHeroCard.size() + allMapCard.size() + allMapHeroCard.size()) {
				std::cout << "\n\n Drop: " << allMapHeroCard[ran - allMapCard.size() - allHeroCard.size() - 1].nameCard << "\n\n";
				eqMapHeroCard.push_back(allMapHeroCard[ran - allMapCard.size() - allHeroCard.size() - 1]);
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			champion.setHp(hpH);
			player.setExp(enemy.getLevel() * 2);
			player.setGold(player.getGold() + (enemy.getLevel() * 3));
			return 1;
		}

	}
}

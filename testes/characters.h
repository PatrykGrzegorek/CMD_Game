#pragma once

class Character {
	int level;
	int hp, hpMax;
	int dmg;
	int as;
	int def;
	int dodge;
	std::string name;
public:
	Character(int, int, int, int, int, int, std::string);

	int getLevel();
	int getHpMax();
	int getHp();
	int getDmg();
	int getAs();
	int getDef();
	int getDodge();
	std::string getName();

	virtual void setLevel(int);
	virtual void updateStatsLevel();
	void setHpMax(int);
	void setHp(int);
	void setDmg(int);
	void setAs(int);
	void setDef(int);
	void setDodge(int);
};

class Player : public Character{
	int maxExp;
	int exp;
	int hpBuff, hpBasic;
	int dmgBuff;
	int asBuff;
	int defBuff;
	int dodgeBuff;
	int gold;
public:
	Player() :
		Character(0, 0, 0, 0, 0, 0, ""), hpBasic(0),
		maxExp(0), exp(0), hpBuff(0), dmgBuff(0), asBuff(0), defBuff(0), dodgeBuff(0), gold(0) {
	}

	Player(int, int, int, int, int, int, std::string, int, int, int, int, int, int, int);

	int getMaxExp();
	int getExp();
	int getGold();

	int getHpMaxBuff();
	int getHpBasic();
	int getDmgBuff();
	int getAsBuff();
	int getDefBuff();
	int getDodgeBuff();

	void setExp(int);
	void setGold(int);

	void setLevel(int);
	void updateStatsLevel();
	void setHpMaxByBuff(int);
	void setHpBasic(int);
	void setDmgByBuff(int);
	void setAsByBuff(int);
	void setDefByBuff(int);
	void setDodgeByBuff(int);
	bool spendGold(int);

	void setPlayer();
};
#include "head.h"

Character::Character(int _level, int _hpBasic, int _dmgBasic, int _asBasic, int _defBasic, int _dodgeBasic, std::string _name) :
	level(_level), hp(_hpBasic), hpMax(_hpBasic), dmg(_dmgBasic),
	as(_asBasic + _level), def(_defBasic), dodge(_dodgeBasic), name(_name){
}

int Character::getLevel() {
	return level;
}
int Character::getHpMax() {
	return hpMax;
}
int Character::getHp() {
	return hp;
}
int Character::getDmg() {
	return dmg;
}
int Character::getAs() {
	return as;
}
int Character::getDef() {
	return def;
}
int Character::getDodge() {
	return dodge;
}
std::string Character::getName() {
	return name;
}

void Character::setLevel(int i) {
	level += i;
}
void Character::updateStatsLevel() {
	hp = hp + hp*2*level;
	hpMax = hp;
	dmg = dmg + 1.79*level;
	as = as + 2*level;
}
void Character::setHpMax(int i) {
	hpMax = i;
}
void Character::setHp(int i) {
	hp = i;
}
void Character::setDmg(int i) {
	dmg = i;
}
void Character::setAs(int i) {
	as = i;
}
void Character::setDef(int i) {
	def = i;
}
void Character::setDodge(int i) {
	dodge = i;
}

Player::Player(int _level, int _hpBasic, int _dmgBasic, int _asBasic, int _defBasic, int _dodgeBasic, std::string _name,
				int _exp, int _hpBuff, int _dmgBuff, int _asBuff, int _defBuff, int _dodgeBuff, int _gold):
				Character(_level, _hpBasic, _dmgBasic, _asBasic, _defBasic, _dodgeBasic, _name), hpBasic(_hpBasic),
				maxExp(15 * _level + 4 * _level * _level),exp(_exp), hpBuff(_hpBuff), dmgBuff(_dmgBuff), asBuff(_asBuff), defBuff(_defBuff), dodgeBuff(_dodgeBuff), gold(_gold){
}

int Player::getMaxExp() {
	return maxExp;
}
int Player::getExp() {
	return exp;
}
int Player::getGold() {
	return gold;
}
int Player::getHpMaxBuff() {
	return hpBuff;
}
int Player::getHpBasic() {
	return hpBasic;
}
int Player::getDmgBuff() {
	return dmgBuff;
}
int Player::getAsBuff() {
	return asBuff;
}
int Player::getDefBuff() {
	return defBuff;
}
int Player::getDodgeBuff() {
	return dodgeBuff;
}
void Player::setLevel(int i) {
	Character::setLevel(i);
	updateStatsLevel();
}
void Player::updateStatsLevel() {
	maxExp = 15 * getLevel() + 4 * getLevel() * getLevel();
	hpBasic = hpBasic + hpBasic * 0.07 * getLevel();
	setHpMaxByBuff(hpBuff);
	setDmg(getDmg() + 1.1 * getLevel());
	setDmgByBuff(dmgBuff);
	setAs(getAs() + 1 * getLevel());
	setAsByBuff(asBuff);
}
void Player::setExp(int i) {
	exp += i;
	while (exp >= maxExp) {
		exp = exp - maxExp;
		setLevel(1);
	}
}
void Player::setGold(int i) {
	gold = i;
}
void Player::setHpMaxByBuff(int i) {
	hpBuff = i;
	int x = getHpBasic() + (getHpBasic() * ((float)hpBuff / 100));
	setHpMax(x);
}
void Player::setHpBasic(int i) {
	hpBasic = i;
}
void Player::setDmgByBuff(int i) {
	dmgBuff = i;
	int x = getDmg() + 1;
	setDmg(x);
}
void Player::setAsByBuff(int i) {
	asBuff = i;
	int x = getAs() + 1;
	setAs(x);
}
void Player::setDefByBuff(int i) {
	defBuff = i;
	int x = getDef() + 1;
	setDef(x);
}
void Player::setDodgeByBuff(int i) {
	dodgeBuff = i;
	int x = getDodge() + 1;
	setDodge(x);
}
bool Player::spendGold(int i) {
	if (i <= getGold()) {
		setGold(getGold()-i);
		return true;
	}
	return false;
}

void Player::setPlayer() {
	int x = getDmg() + dmgBuff;
	setDmg(x);
	x = getAs() + asBuff;
	setAs(x);
	x = getDef() + defBuff;
	setDef(x);
	x = getDodge() + dodgeBuff;
	setDodge(x);
}

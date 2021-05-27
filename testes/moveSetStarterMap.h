#pragma once

void loadStarterMap(char(&map)[10][23], int yMap, int xMap);
void shopA(Player&);
void shopO(Player&);
void shopD(Player&);
int startQuest(Player);
int moveSetStarterMap(Player&);
void moveW(int&, int, int, int, char map[10][23], Player&);
void moveS(int&, int, int, int, char map[10][23], Player&);
void moveA(int, int&, int, int, char map[10][23], Player&);
void moveD(int, int&, int, int, char map[10][23], Player, int&);
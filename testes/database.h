#pragma once

static int callbackC(void* NotUsed, int argc, char** argv, char** azColName);
static int callbackRUD(void* data, int argc, char** argv, char** azColName);
void checkDatabase();
void setupGame();
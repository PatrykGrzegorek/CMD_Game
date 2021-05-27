#include "head.h"


static int callbackC(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

static int callbackRUD(void* data, int argc, char** argv, char** azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void checkDatabase() {
	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	std::string sql;
	const char* data = "Callback function called";

	/* Open database */
	rc = sqlite3_open("consolegame.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sql = "SELECT * from enemy";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callbackRUD, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}

	/* Create SQL statement */
	sql = "SELECT * from account";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callbackRUD, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}

	/* Create SQL statement */
	sql = "SELECT * from player";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql.c_str(), callbackRUD, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}
	printf("\n\n dupa \n\n"); 
	//sql = "select count(*) from account";
	sql = "select * from enemy where name like 'S%';";
	rc = sqlite3_exec(db, sql.c_str(), callbackRUD, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}

	// query = "select * from account where name like '" + ch[0] + "%';";
	delete data;
	delete zErrMsg;
	sqlite3_close(db);
}

void setupGame() {
	char* error;
	sqlite3* db;
	sqlite3_stmt* stmt;
	std::string query = "";
	sqlite3_open("consolegame.db", &db);
	int rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS account(id INT, login INT, password TEXT);", NULL, NULL, &error);
	if (rc != SQLITE_OK) {
		std::cout << "error: " << error;
	}

	rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS enemy(id INT, hp INT, dmg INT, ats INT, def INT, dodge INT, name TEXT);", NULL, NULL, &error);
	if (rc != SQLITE_OK) {
		std::cout << "error: " << error;
	}
	sqlite3_prepare_v2(db, "select id from enemy where id=1", -1, &stmt, 0);
	if (sqlite3_step(stmt) == SQLITE_DONE) {
		query = "insert into enemy VALUES(1, 10, 5, 100, 1, 0, 'Slime')";
		rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &error);
		if (rc != SQLITE_OK) {
			std::cout << "error: " << error;
		}

		query = "insert into enemy VALUES(2, 1, 5, 1000, 0, 20, 'Wampire')";
		rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &error);
		if (rc != SQLITE_OK) {
			std::cout << "error: " << error;
		}

		query = "insert into enemy VALUES(3, 30, 5, 50, 3, 0, 'Zombie')";
		rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &error);
		if (rc != SQLITE_OK) {
			std::cout << "error: " << error;
		}
	}

	rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS player(id INT, level INT, hpB INT, dmgB INT, asB INT, defB INT, dodgeB INT, name TEXT, exp INT, hpP INT, dmgP INT, asP INT, defP INT, dodgeP INT, gold INT);", NULL, NULL, &error);
	if (rc != SQLITE_OK) {
		std::cout << "error: " << error;
	}
	sqlite3_reset(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);
	delete error;
}

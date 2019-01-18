//
//  SqliteUtils.cpp
//  staitstics
//
//  Created by 王玉彬 on 2019/1/16.
//  Copyright © 2019 王玉彬. All rights reserved.
//

#include "SqliteUtils.h"


int SqliteUtils::open() {
    rc = sqlite3_open(dbName.c_str(), &db);
    if( rc ){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return -1;
    }else{
        printf("Opened database successfully\n");
    }
    return 0;
}

SqliteUtils::SqliteUtils(std::string dbName)
:db(nullptr),zErrMsg(nullptr),rc(0), dbName(dbName){
}

SqliteUtils::~SqliteUtils() {
    if (db != nullptr) {
        sqlite3_close(db);
    }
}

int SqliteUtils::createTable() { 
    /* Create SQL statement */
    char *sql = "CREATE TABLE COMPANY("  \
    "ID INT PRIMARY KEY     NOT NULL," \
    "NAME           TEXT    NOT NULL," \
    "AGE            INT     NOT NULL," \
    "ADDRESS        CHAR(50)," \
    "SALARY         REAL );";
    
    return exec(sql);
}

int SqliteUtils::callback(void *NotUsed, int argc, char **argv, char **azColName) { 
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int SqliteUtils::exec(const char *sql) { 
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return -1;
    }else{
        fprintf(stdout, "Table created successfully\n");
    }
    return 0;
}




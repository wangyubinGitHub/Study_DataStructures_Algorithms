//
//  SqliteUtils.h
//  staitstics
//
//  Created by 王玉彬 on 2019/1/16.
//  Copyright © 2019 王玉彬. All rights reserved.
//

#ifndef SqliteUtils_h
#define SqliteUtils_h

#include <sqlite3.h>
#include <string>

class SqliteUtils {
private:
    const std::string dbName;
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
public:
    SqliteUtils(std::string dbName);
    ~SqliteUtils();
    int open();
    int createTable();
    static int callback(void *NotUsed, int argc, char** argv, char** azColName);
    int exec(const char* sql);
};

#endif /* SqliteUtils_h */

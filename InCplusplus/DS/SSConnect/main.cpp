#include <iostream>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>

using namespace std;

int main()
{
    RETCODE error;
    HENV env;
    HDBC conn;

    SQLAllocEnv(&env);
    SQLAllocConnect(env, &conn);
    SQLConnect(conn, "ODBCSQLSeRVER", SQL_NTS, "", SQL_NTS, "", SQL_NTS);
    return 0;
}

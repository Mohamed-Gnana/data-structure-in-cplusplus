#include <stdio.h>
#include <stdlib.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <windows.h>

int main()
{
    RETCODE error;
    HENV env; /* environment */
    HDBC conn; /* database connection */
    SQLAllocEnv(&env);
    SQLAllocConnect(env, &conn);
    SQLConnect(conn,"SERVER=ODBCSQLSERVER", SQL NTS, "", SQL NTS,
    "", SQL NTS);
    return 0;
}

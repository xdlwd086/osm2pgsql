#include <libpq-fe.h>
#include <cstring>
#include <cstdlib>

#include "pgsql.hpp"
#include "buffer.hpp"

int main(int argc, char *argv[]) {
    buffer sql;
    escape(sql, "farmland");
    return strcmp(sql.buf, "farmland") != 0;
}
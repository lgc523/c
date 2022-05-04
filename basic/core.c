#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

#define BOOL_TRUE 1
#define BOOL_FALSE 0
#define typename(x) _Generic((x),                    \
                             unsigned short          \
                             : "unsigned short int", \
                               unsigned long         \
                             : "unsigned long int",  \
                               default               \
                             : "unknown")

typedef enum
{
    HOST,
    IP
} IP_ADDR_TYPE;

typedef struct
{
    size_t id;
    uint16_t port;
    bool closed;
    IP_ADDR_TYPE addr_type;
    union
    {
        char host_name[256];
        char ip[24];
    };
} CONN;

inline static const char *findAddr(const CONN *pip)
{
    assert(pip != NULL);
    return pip->addr_type == HOST ? pip->host_name : pip->ip;
}

int main(int argc, char *argv[])
{
    static_assert(sizeof(CONN) <= 0x400, "this size of CONN object exceeds limit.");
    const CONN conns[] = {
        [2] = {1, 8080, BOOL_TRUE, IP, {.ip = "127.0.0.1"}},
        [0] = {2, 8080, BOOL_FALSE, IP, {.ip = "192.168.1.1"}},
        {3, 8080, BOOL_FALSE, HOST, {.host_name = "http://localhost/"}}};

    for (size_t i = 0; i < (sizeof(conns) / sizeof(CONN)); ++i)
    {
        printf(
            "Port: %d\n"
            "Host/Addr: %s\n"
            "Internal type of `id` is: %s\n\n",
            conns[i].port,
            findAddr(&conns[i]),
            typename(conns[i].id));
    }
    return EXIT_SUCCESS;
}
//gcc core.c -o corec -Wall && ./corec
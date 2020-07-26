#include <stdio.h>
#include <string.h>

char *f(int m) // Should probably return a const char *f
{
    char buf[6]; // Cant return string defined as local variable in this way as stored on stack. The variable is released when function execution finished.
                 // Should allocate to heap instead using malloc - (char *)malloc(7 * sizeof(char))
    int x;       // Assigned garbage value as not initialised

    if (m == 1 && x--) // AND condition is irrelevant as x contians garbarge value. Will always execute given 1 arg.
    {
        strcpy(buf, "AAAAAA"); // Buf not large enough to store 6 chars + null char '\0'.
        return buf;
    }
    else if (m == 2)
    {
        char *msg = (char *)malloc(100); // Unneccesarily large as we know msg will be 6 chars. (char *)malloc(7 * sizeof(char))
        strcpy(msg, "BBBBBB");
        return msg;
    }
}

int main(int argc, char **argv)
{
    char *m;
    m = f(argc);
    putchar(m[0]);
    return 0;
}
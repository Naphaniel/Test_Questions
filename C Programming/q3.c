#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_bytes(unsigned char *, int);
void reverse_string(char *);

int main(void)
{
    unsigned char buf[6] = "hello";
    reverse_bytes(buf, 5);
    return 0;
}

// T.C O(N), S.C O(N).
void reverse_bytes(unsigned char *buf, int n)
{
    char *bit_string = (char *)malloc(n * 8 + 1);
    bit_string[0] = '\0';
    for (int i = 0; i < n; i++)
    {
        char ch = buf[i];
        for (int j = 7; j >= 0; --j)
        {
            if (ch & (1 << j))
            {
                strcat(bit_string, "1");
            }
            else
            {
                strcat(bit_string, "0");
            }
        }
    }
    printf("%s\n", bit_string);
    reverse_string(bit_string);
    printf("%s\n", bit_string);

    // If wanting to alter buffer with appropriate character values from bitstring.
    // char current_byte[9];
    // int i = 0;
    // for (int bit = 0; bit < (8 * n + 1); bit++)
    // {
    //     if (bit % 8 == 0 && bit != 0)
    //     {
    //         buf[i] = (char)strtol(current_byte, 0, 2);
    //         i++;
    //     }
    //     current_byte[bit % 8] = bit_string[bit];
    // }
}

// T.C O(N), S.C O(1)
void reverse_string(char *start)
{
    if (!start)
        return;
    char *end = start;
    while (*end)
        ++end;
    --end;

    while (start < end)
    {
        char s = *start, e = *end;
        *end = s;
        *start = e;

        start++;
        end--;
    }
}

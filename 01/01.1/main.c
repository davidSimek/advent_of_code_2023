#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        puts("You have to pass one argument.");
        return -1;
    }

    int sum = 0;
    int index = 0;
    int lastOnThisLine = 0;
    bool foundOne = false;

    char current = 'a';
    while (true) {

        current = argv[1][index];
        bool isDigit = isdigit(current);
        if (current == 0) {
            sum += lastOnThisLine;
            break;
        }

        if (current == '\n') {
            sum += lastOnThisLine;
            lastOnThisLine = 0;
            foundOne = false;
        } else if (isDigit && !foundOne) {
            lastOnThisLine = current - '0';
            sum += (current - '0') * 10;
            foundOne = true;
        } else if (isDigit) {
            lastOnThisLine = current - '0';
        }
        index++;
    }
    printf("Answer is: %d", sum);
    return 0;
}

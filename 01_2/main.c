#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getValue(char* position);

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


    char* current = argv[1];
    while (true) {
        int currentValue = getValue(current);
        if (*current == 0) {
            sum += lastOnThisLine;
            break;
        }
        bool isNumber = currentValue != -1;

        if (*current == '\n') {
            sum += lastOnThisLine;
            lastOnThisLine = 0;
            foundOne = false;
        } else if (isNumber && !foundOne) {
            lastOnThisLine = currentValue;
            sum += currentValue * 10;
            foundOne = true;
        } else if (isNumber) {
            lastOnThisLine = currentValue;
        }
        //printf("Position is %p\n", current);
        // printf("this number was: %d\n", currentValue);
        current++;
    }
    printf("Answer is: %d\n", sum);
    return 0;
}

int getValue(char* current) {

    char* values[] = {
        "zero ",
        "one  ",
        "two  ",
        "three",
        "four ",
        "five ",
        "six  ",
        "seven",
        "eight",
        "nine "
    };

    bool canBe[] = {
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
    };

    if (isdigit(*current)) {
        return *current - '0';
    }

    // printf(" 0  1  2  3  4  5  6  7  8  9\n");
    // per character in current
    for (int i = 0; i < 5; i++) {
        if (*current == 0 || *current == '\n') {
            return -1;
        }

        // breaks if found
        if (canBe[0] == true && i == 4)
            break;
        if (canBe[1] == true && i == 3)
            break;
        if (canBe[2] == true && i == 3)
            break;
        if (canBe[4] == true && i == 4)
            break;
        if (canBe[5] == true && i == 4)
            break;
        if (canBe[6] == true && i == 3)
            break;
        if (canBe[9] == true && i == 4)
            break;
 
        // per value in values
        for (int j = 0; j < 10; j++) {
            if (current[i] != values[j][i] && values[j][i] != ' ') {
                // printf(" %c ", current[i]);
                canBe[j] = false;
            } else {
                // printf("[%c]", current[i]);
            }
        }
        // puts("\n");
    }

    for (int i = 0; i < 10; i++) {
        if (canBe[i])
            return i;
    }
    return -1;
}

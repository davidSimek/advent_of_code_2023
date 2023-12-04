#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum{
    Game,
    Id,
    Amount,
    Color
} State;

void skipToNextSpace(char* string, int* i);
int getNumber(char* string, int* index);

int main(int argc, char *argv[])
{
    const int RED_MAX     = 12;
    const int GREEN_MAX   = 13;
    const int BLUE_MAX    = 14;


    if (argc != 2) {
        puts("You have to provide one argument");
        return -1;
    }

    // bool redPulled   = false;
    // bool greenPulled = false;
    // bool bluePulled  = false;
    // int currentId;
    
    int smallestRed = 0;
    int smallestGreen = 0;
    int smallestBlue = 0;

    int sumOfPowers = 0;

    int i = 0;
    int currentAmount;
    char* currentString = argv[1];
    State state = Game;
    while (true) {
        char current = currentString[i];
        
        if (current == 0) {
            puts("End");
            break;
        }

        switch (state) {
            case Game:
                skipToNextSpace(currentString, &i);
                state = Id;
                break;
            case Id:
                // currentId = getNumber(currentString, &i);
                // printf("Game: %d\n", currentId);
                skipToNextSpace(currentString, &i);
                state = Amount;
                break;
            case Amount:
                if (currentString[i] == '\n') {
                    i++;
                    
                    sumOfPowers += smallestRed * smallestGreen * smallestBlue;

                    smallestRed   = 0;
                    smallestGreen = 0;
                    smallestBlue  = 0;
                    state = Game;
                    // puts("end of game");
                    // redPulled   = false;
                    // greenPulled = false;
                    // bluePulled  = false;
                } else {
                    currentAmount = getNumber(currentString, &i);
                    // printf("Amount: %d\t", currentAmount);
                    skipToNextSpace(currentString, &i);
                    state = Color;
                }
                break;
            case Color:
                // if (redPulled && greenPulled && bluePulled) {
                //     redPulled   = false;
                //     greenPulled = false;
                //     bluePulled  = false;
                // }
                                
                if (current == 'r' && currentAmount > smallestRed) {
                    smallestRed = currentAmount;
                }
                if (current == 'g' && currentAmount > smallestGreen) {
                    smallestGreen = currentAmount;
                }
                if (current == 'b' && currentAmount > smallestBlue) {
                    smallestBlue = currentAmount;
                }
                
                // printf("Color: %c \n", current);
                // if (redPulled) {
                //     printf("red   [X]\n");
                // } else {
                //     printf("red   [ ]\n");
                // }
                // if (greenPulled) {
                //     printf("green [X]\n");
                // } else {
                //     printf("green [ ]\n");
                // }
                // if (bluePulled) {
                //     printf("blue  [X]\n");
                // } else {
                //     printf("blue  [ ]\n");
                // }
                skipToNextSpace(currentString, &i);
                state = Amount;
                break;
        }
        
    }
    // printf("Sum of ids is: %d", idSum);
    printf("sum of powers is: %d", sumOfPowers);
    return 0;
}

void skipToNextSpace(char* string, int* i) {
    while (true) {
        (*i)++;
        if (string[*i] == ' ') {
            (*i)++;
            break;
        }

        if (string[*i] == 0 || string[*i] == '\n') {
            break;
        }
    }
}

int getNumber(char* string, int* index) {
    int i = *index;
    int sum = 0;
    while (true) {
        char number = string[i];
        if (!isdigit(number)) {
            break;
        }
        sum *= 10;
        sum += (number - '0');
        i++;
    }
    return sum;
}

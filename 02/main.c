#include <stdio.h>
#include <stdbool.h>

typedef enum{
    Game,
    Line,
    Amount,
    Color
} State;

void skipToNextSpace(char* string, int* i);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        puts("You have to provide one argument");
        return -1;
    }

    // first byte that meatters is always 9th
    int i = 0;
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
                state = Line;
                break;
            case Line:
                skipToNextSpace(currentString, &i);
                state = Amount;
                break;
            case Amount:
                if (currentString[i] == '\n') {
                    i++;
                    puts("end of game");
                    state = Game;
                } else {
                    printf("Amount: %c ", current);
                    skipToNextSpace(currentString, &i);
                    state = Color;
                }
                break;
            case Color:
                printf("Color: %c \n", current);
                skipToNextSpace(currentString, &i);
                state = Amount;
                break;
        }
    }
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

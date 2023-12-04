#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int getSizeOfLine(char* string);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        puts("You have to provide 1 argument.");
        return -1;
    }

    char* buffer = argv[1];
    int sizeOfLine = getSizeOfLine(buffer);
    int sizeOfBuffer = strlen(buffer);
    int lines = 1
    return 0;
}

int getSizeOfLine(char* string) {
    int i = 0;
    while (true) {
        if (string[i] == '\n' || string[i] == 0) {
            return i;
        }
        i++;
    }
}

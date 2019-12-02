#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    size_t LENGTH = 200;

    int intcode[LENGTH];

    FILE * file;
    file = fopen("input", "r");

    for (size_t i = 0; i < LENGTH; i++)
    {
        int line = fscanf(file, "%d,", &intcode[i]);
        if (line == EOF) { break; }
    }

    // restore program state
    intcode[1] = 12;
    intcode[2] = 2;

    for (int i = 0; i < LENGTH;)
    {
        int opcode = intcode[i];
        int a = intcode[i + 1];
        int b = intcode[i + 2];
        int c = intcode[i + 3];

        switch (opcode)
        {
            case 1:
                intcode[c] = intcode[a] + intcode[b];
                i += 4;
                break;

            case 2:
                intcode[c] = intcode[a] * intcode[b];
                i += 4;
                break;

            case 99:
                printf("Program finished. position 0 -> %d\n", intcode[0]);
                return 0;

            default:
                printf("Something went wrong! opcode %d\n", opcode);
                return opcode;
        }
    }

    return 0;
}


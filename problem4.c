#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    size_t LENGTH = 200;
    int OUTPUT = 19690720;

    int intcode[LENGTH];

    FILE * file;
    file = fopen("input", "r");
    for (size_t i = 0; i < LENGTH; i++)
    {
        int line = fscanf(file, "%d,", &intcode[i]);
        if (line == EOF) { break; }
    }

    // cycle tempcode state (bruteforce)
    for (size_t noun = 0; noun < 100; noun++)
    {
        for (size_t verb = 0; verb < 100; verb++)
        {
            // reset tempcode
            int * tempcode = malloc(LENGTH * sizeof(intcode[0]));
            memcpy(tempcode, intcode, LENGTH * sizeof(intcode[0]));

            // initialize tempcode
            tempcode[1] = noun;
            tempcode[2] = verb;

            // run tempcode
            for (int i = 0; i < LENGTH;)
            {
                int opcode = tempcode[i];
                int a = tempcode[i + 1];
                int b = tempcode[i + 2];
                int c = tempcode[i + 3];

                switch (opcode)
                {
                    case 1:
                        tempcode[c] = tempcode[a] + tempcode[b];
                        i += 4;
                        break;

                    case 2:
                        tempcode[c] = tempcode[a] * tempcode[b];
                        i += 4;
                        break;

                    case 99:
                        // printf("Program finished. position 0 -> %d\n", \
                        //     tempcode[0]); /* too noisy */
                        
                        if (tempcode[0] == OUTPUT)
                        {
                            // format answer with no spaces, no commas. e.g. 1202
                            printf("(%ld, %ld) -> %d\n", noun, verb, OUTPUT);
                            return 0;
                        }

                        i = LENGTH;
                        break;

                    default:
                        printf("Something went wrong! opcode %d\n", opcode);
                        return opcode;
                }
            }
        }
    }

    return 0;
}


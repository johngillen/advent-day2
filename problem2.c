#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int sum = 0;

    FILE * file;
    file = fopen("input", "r");

    for (;;)
    {
        int side[3];
        int line = fscanf(file, "%dx%dx%d", &side[0], &side[1], &side[2]);
        if (line == EOF) { break; }

        sum += area(side);
    }
    
    printf("Total length of ribbon: %d\n", sum);
    return 0;
}

int area(int s[])
{
    sort(s, 3);    
    return (2 * (s[0]) + 2 * s[1]) + (s[0] * s[1] * s[2]);
}

void sort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
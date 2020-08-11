#include <stdio.h>

//to find the related position
int FindLRU(int time[], int n)
{
    int i, minimum = time[0], pos = 0;

    for (i = 0; i < n; ++i)
    {
        if (minimum > time[i])
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int frams, pages, fram[frams], page[pages], flag1, flag2, counter = 0, time[frams], faults = 0, pos, i, j;
    printf("\nEnter number of frams : ");
    scanf("%d", &frams);

    printf("\nEnter number of pages : ");
    scanf("%d", pages);

    printf("\nEnter reference string: ");

    for (int i = 0; i < pages; i++)
    {
        scanf("%d", &page[i]);
    }

    for (int i = 0; i < frams; i++)
    {
        fram[i] = -1;
    }

    for (int i = 0; i < pages; i++)
    {
        flag1 = flag2 = 0;

        for (int j = 0; j < frams; j++)
        {
            if (fram[j] == page[i])
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 0;
                break;
            }
        }
        if (flag1 == 0)
        {
            for (j = 0; j < pages; ++j)
            {
                if (fram[j] == -1)
                {
                    counter++;
                    faults++;
                    fram[j] = page[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            pos = FindLRU(time, frams);
            counter++;
            faults++;
            fram[pos] = page[i];
            time[pos] = counter;
        }
        printf("\n");
        for (j = 0; j < fram; ++j)
        {
            printf("%d\t", fram[j]);
        }
    }
}
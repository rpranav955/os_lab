#include <stdio.h>

#define MAX_PAGES 50
#define MAX_FRAMES 10

int frames[MAX_FRAMES] = {0};
int time[MAX_FRAMES] = {0};

int counter = 0;
int faults = 0;

void printTable(int page, int f, int hit)
{
    printf("%d\t", page);
    for (int i = 0; i < f; i++)
    {
        if (frames[i] == 0)
        {
            printf("-\t");
        }
        else
        {
            printf("%d\t", frames[i]);
        }
    }
    if (hit)
    {
        printf("Hit\n");
    }
    else
    {
        printf("Miss\n");
    }
}

int findLRU(int f)
{
    int min = time[0], pos = 0;
    for (int i = 0; i < f; i++)
    {
        if (time[i] < min)
        {
            min = time[i];
            pos = i;
        }
    }

    return pos;
}

int main()
{
    int p, f;
    printf("Enter the number of pages: ");
    scanf("%d", &p);

    int pages[p];
    printf("Enter the page sequance string: ");
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    printf("\nPages\t");
    for (int i = 0; i < f; i++)
    {
        printf("Frame%d\t", i + 1);
    }
    printf("Status\n");

    for (int i = 0; i < p; i++)
    {
        counter++;
        int found = 0;
        for (int j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                printTable(pages[i], f, 1);
                time[j] = counter;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            int pos = findLRU(f);
            frames[pos] = pages[i];
            time[pos] = counter;
            printTable(pages[i], f, 0);
            faults++;
        }
    }

    printf("\nNumber of Faults: %d\n", faults);

    return 0;
}

#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter the number of proc: ");
    scanf("%d", &n);
    printf("Enter the number of res: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m], need[n][m], finish[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the alloc res for P%d: \n", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter the max res for P%d: \n", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available %d resources: ", m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    for (int i = 0; i < n; i++)
    {
        finish[i] = 0;
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int count = 0;
    int safeSeq[n];

    while (count < n)
    {
        int found = 0;
        for (int i = 0; i < n; i++)
        {
            if (finish[i] != 1)
            {
                int j;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        break;
                    }
                }
                if (j == m)
                {
                    for (int k = 0; k < m; k++)
                    {
                        avail[k] += alloc[i][k];
                    }
                    finish[i] = 1;
                    safeSeq[count++] = i;
                    found = 1;
                }
            }
        }
        if (found != 1)
        {
            printf("IT IS UNDER UNSAFE SEQUANCE\n");
            return 0;
        }
    }

    printf("THERE IS A SAFE SEQUANCE: ");
    for (int i = 0; i < n; i++)
    {
        printf("P%d ", safeSeq[i]);
    }
    return 0;
}

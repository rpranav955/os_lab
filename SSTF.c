#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, total = 0, head;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int req[n], visited[n];

    printf("Enter the %d requests: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter the value of head: ");
    scanf("%d", &head);

    printf("\nStep\tFrom\tTo\tDistance\n");
    printf("---------------------------------------\n");
    for (int step = 0; step < n; step++)
    {
        int min = 99999, index;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int dist = abs(head - req[i]);
                if (min > dist)
                {
                    min = dist;
                    index = i;
                }
            }
        }
        total += min;
        printf("%d\t%d\t%d\t%d\n", step + 1, head, req[index], min);
        head = req[index];
        visited[index]++;
    }
    printf("---------------------------------------\n");
    printf("\nTotal Distance Covered: %d\n", total);

    return 0;
}

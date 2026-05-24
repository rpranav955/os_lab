// C SCAN

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, total = 0, head, step = 1;
    printf("Enter the total number of requests: ");
    scanf("%d", &n);

    int req[n], visited[n];

    printf("Enter the requests (should be between 0 - 199):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    // sort the requests
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (req[j] > req[j + 1])
            {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    printf("Enter locaiton of head: ");
    scanf("%d", &head);

    printf("\nStep\tFrom\tTo\tDist.\n");
    printf("------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && req[i] > head)
        {
            int dist = abs(req[i] - head);
            printf("%d\t%d\t%d\t%d\n", step++, head, req[i], dist);
            head = req[i];
            visited[i]++;
        }
    }

    printf("%d\t%d\t199\t%d\t<- Move till end\n", step++, head, 199 - head);
    total += 199 - head;
    head = 199;
    printf("%d\t%d\t0\t%d\t<- Move to begining\n", step++, head, 199);
    total += 199;
    head = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && req[i] > head)
        {
            int dist = abs(req[i] - head);
            printf("%d\t%d\t%d\t%d\n", step++, head, req[i], dist);
            head = req[i];
            visited[i]++;
        }
    }
    printf("------------------------------\n");
    printf("Total Distance Covered: %d\n", total);
    return 0;
}

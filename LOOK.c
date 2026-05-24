// look

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, total = 0;

    printf("Enter the total number of requests: ");
    scanf("%d", &n);

    int req[n], visited[n], step = 1;

    printf("Enter the %d Requests:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter your header location: ");
    scanf("%d", &head);

    // sort the req array
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

    printf("\nStep\tFrom\tTo\tDist\n");
    printf("-----------------------------\n");
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && req[i] > head)
        {
            int dist = abs(req[i] - head);
            printf("%d\t%d\t%d\t%d\n", step++, head, req[i], dist);
            visited[i]++;
            head = req[i];
            total += dist;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (!visited[i] && req[i] < head)
        {
            int dist = abs(req[i] - head);
            printf("%d\t%d\t%d\t%d\n", step++, head, req[i], dist);
            visited[i]++;
            head = req[i];
            total += dist;
        }
    }
    printf("-----------------------------\n");

    printf("Total Distance Covered: %d\n", total);

    return 0;
}

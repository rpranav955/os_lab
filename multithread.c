// multithreading
// calculate mean, median and standard deviation

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>

int numbers[50], n;

float mean = 0, median = 0, SD = 0;

void *calc_mean()
{
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum += numbers[i];
    }
    mean = sum / n;
    printf("\nMean: %.2f", mean);

    pthread_exit(NULL);
}
void *calc_median()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int temp = numbers[j];
            numbers[j] = numbers[j + 1];
            numbers[j + 1] = temp;
        }
    }

    if (n % 2 == 0)
    {
        median = (numbers[n / 2 - 1] + numbers[n / 2]) / 2;
    }
    else
    {
        median = numbers[n / 2];
    }
    printf("\nMedian: %.2f", median);

    pthread_exit(NULL);
}
void *calc_SD()
{
    double variance_sum = 0;
    for (int i = 0; i < n; i++)
    {
        variance_sum += pow(numbers[i] - mean, 2);
    }
    SD = sqrt(variance_sum / n);
    printf("\nSD: %.2f\n", SD);

    pthread_exit(NULL);
}

int main()
{
    printf("Enter the count of numbers: ");
    scanf("%d", &n);

    printf("Enter the numbers: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, calc_mean, NULL);
    pthread_create(&t2, NULL, calc_median, NULL);
    pthread_join(t1, NULL);
    pthread_create(&t3, NULL, calc_SD, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}

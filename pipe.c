#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>

int main()
{

    int fd[2];
    pid_t pid;
    double a, b, c;
    double four_ac, b2, discriminant, result;

    printf("Enter the value of a, b, c:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (pipe(fd) == -1)
    {
        printf("pipe failed\n");
        return 1;
    }

    pid = fork();
    if (pid == -1)
    {
        printf("fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        close(fd[0]);

        four_ac = 4 * a * c;
        write(fd[1], &four_ac, sizeof(four_ac));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);

        read(fd[0], &four_ac, sizeof(four_ac));
        close(fd[0]);

        b2 = b * b;

        discriminant = b2 - four_ac;

        if (discriminant < 0)
        {
            printf("NEGATIVE DISCRIMINANT %.2lf\nRESULT would be IMAGINARY", discriminant);
        }
        else
        {
            result = sqrt(discriminant);
            printf("POSITIVE DISCRIMINANT %.2lf\nRESULT:%.2lf", discriminant, result);
        }
    }

    return 0;
}

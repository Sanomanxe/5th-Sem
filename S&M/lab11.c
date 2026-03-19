#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    int i, j, run = 10;
    float x, iat, st, awt, pcu;
    float wt = 0, it = 0;
    
    // Changed data (you can modify these)
    float mean = 9.0, sd = 1.2;
    float mue = 9.0, sigma = 1.0;
    
    float sb = 0.0, se = 0.0, cit = 0, cat = 0, cwt = 0;

    srand(time(0));  // better random values

    printf("\nIAT     CAT     SB     ST     SE     CWT     CIT\n");

    for(j = 1; j <= run; ++j)
    {
        float sum = 0;

        // Generate IAT (normal distribution approx)
        for(i = 1; i <= 12; ++i)
        {
            x = (float)rand() / RAND_MAX;
            sum += x;
        }
        iat = mean + sd * (sum - 6.0);
        cat = cat + iat;

        // Server busy or idle
        if(cat <= se)
        {
            sb = se;
            wt = se - cat;
            cwt += wt;
        }
        else
        {
            sb = cat;
            it = sb - se;
            cit += it;
        }

        sum = 0;

        // Generate service time
        for(i = 1; i <= 12; ++i)
        {
            x = (float)rand() / RAND_MAX;
            sum += x;
        }
        st = mue + sigma * (sum - 6.0);

        se = sb + st;

        printf("\n%6.2f %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f",
               iat, cat, sb, st, se, cwt, cit);
    }

    awt = cwt / run;
    pcu = ((cat - cit) * 100.0) / cat;

    printf("\n\nAverage waiting time = %6.2f", awt);
    printf("\nPercentage capacity utilization = %6.2f\n", pcu);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)                                                            // This function only supports non-negative number convertion
{
    double num, final = 0.0, temp2;
    int base, i, temp1;
    int bit[20];
    for(i = 0; i < 20; i++)
        bit[i] = 0;
    printf("Please enter the decimal number:\n");
    scanf("%lf", &num);
    printf("And then the base:\n");
    scanf("%d", &base);
    for(i = 0, temp1 = (int)(floor(num)); ; i++)
    {
         bit[i] = temp1 % base;
         final += bit[i] * pow(10, i);
         temp1 /= base;
         if(temp1 == 0)
             break;
    }
    for(i = 0; i < 20; i++)
        bit[i] = 0;
    for(i = 0, temp2 = num - (int)(floor(num)); i < 20; i++)
    {
        bit[i] = (int)(floor(temp2 * base));
        final += bit[i] * pow(10, -i - 1);
        temp2 = temp2 * base - bit[i];
        if(temp2 == 0)
            break;

    }
    printf("%.8lf\n", final);
    return 0;
}

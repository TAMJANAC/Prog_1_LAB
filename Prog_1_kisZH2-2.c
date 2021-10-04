#include <stdio.h>

int main()
{
    int stat[100] = {0};
    int n;

    while(scanf("%d", &n) == 1)
    {
        stat[n/10]++;
    }

    for(int i = 0; i < 100; i++)
    {
        if(stat[i] != 0) 
        printf("%d - %d: %ddb\n",i*10, ((i+1)*10)-1,  stat[i]);

    }

    return 0;
}

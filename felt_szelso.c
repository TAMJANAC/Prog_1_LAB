#include <stdio.h>

int main(void)
{
    int n, Nneg, kpoz;
    int bneg = 0;
    int bpoz = 0;
   
   
    while(scanf("%d", &n) == 1)
    {
        if(n < 0) 
        {
            if(bneg == 0) Nneg = n;
            if(bneg == 1 && n > Nneg) Nneg = n;
            bneg = 1;
        };

        if(n > 0)
        {
            if(bpoz == 0) kpoz = n;
            if(bpoz == 1 && n < kpoz) kpoz = n;
            bpoz = 1;
        }

    };
    

    if(Nneg == 0 || bneg == 0) printf("---");
    else printf("%d", Nneg);

    if(kpoz == 0 || bpoz == 0) printf(" ---\n");
    else printf(" %d\n", kpoz);

    return 0;
}

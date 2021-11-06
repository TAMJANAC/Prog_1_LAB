#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} bool;

bool isin(int t[], int n, int iscont)
{
    for(int i = 0; i<n; i++)
    {
        if(t[i] == iscont) return TRUE;
    }
    return FALSE;
}

int common_members(int t1[], int n1, int t2[], int n2)
{
    int common = 0;

    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            if(t1[i] == t2[j]) common++;
        }
    }

    return common;
}

int* intersection(int t1[], int n1, int t2[], int n2, int* outpsize)
{
    int* outputarray = (int*)malloc(sizeof(int)*common_members(t1, n1, t2, n2));

    for(int i = 0, j = 0; i < n1; i++)
    {
        if(isin(t2, n2, t1[i]) == TRUE) 
        {
            outputarray[j] = t1[i];
            j++;
        }
    }

    *outpsize = common_members(t1, n1, t2, n2);

    return outputarray;
}


int main()
{

    int t2[] = {1, 3, 6, 9, 12, 15, 18};
    int t1[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    int common = common_members(t1, 9, t2, 7);
    int intersize;
    int* inters = intersection(t1, 9, t2, 7, &intersize);
    
    bool b = isin(t2,7, 19);
    for(int i = 0; i < intersize; i++)
    {
        printf("%d\n", inters[i]);
    }

    free(inters); 
    return 0;
}

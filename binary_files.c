typedef struct _point_listelem {
    double x, y, z;
    struct _point_listelem* next;
} point_listelem;

#include <stdio.h>
#include <stdlib.h>

void save(char filename[], point_listelem* head)
{
    FILE* fp = fopen(filename, "wb");
    if(fp == NULL) perror("A file megnyitasa sikertelen");

    point_listelem* itr = head;

    while(itr != NULL)
    {
        double puff[3] = {itr->x, itr->y, itr->z};
        fwrite(puff,sizeof(double),3, fp);
        itr=itr->next;
    }
    if(fclose(fp) != 0) perror("A file bezarasa sikertelen");
}

point_listelem* restore(char filename[])
{
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL) perror("A file megnyitasa sikertelen");

    point_listelem *head = (point_listelem*)malloc(sizeof(point_listelem));
    head -> next = NULL;
    point_listelem *tail = head;

    double puffer[3];
    while(fread(puffer, sizeof(double), 3, fp) > 0)
    {
    
        if(tail == head)
        {
         tail->x = puffer[0];
         tail->y = puffer[1];
         tail->z = puffer[2];
         tail->next = (point_listelem*)malloc(sizeof(point_listelem));
         tail = tail->next;
         tail->next = NULL;
        }
        else{
        tail->x = puffer[0];
        tail->y = puffer[1];
        tail->z = puffer[2];
        tail->next = (point_listelem*)malloc(sizeof(point_listelem));
        tail = tail->next;
        tail->next = NULL;
        }
    }
    tail = head;

    while(tail->next->next != NULL) tail = tail->next;
    free(tail->next->next);
    tail->next = NULL;
  
    if(fclose(fp) != 0) perror("A file bezarasa sikertelen");
    return head;
}

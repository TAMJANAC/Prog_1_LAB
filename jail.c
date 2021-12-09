typedef struct{
    int nok;
    int ferfiak;
}cella;

int jail(int cella_nyers[])
{
    int const cellakszama = 10;
    cella cellak[10] = {0};

    for(int i = 0; i < 10; i++)
    {
        if(i%2 == 0) cellak[i].ferfiak = cella_nyers[i];
        else cellak[i].nok = cella_nyers[i];
    }

    int i = 0, j = 9;
    int k = 0;

    while(i <= j){
    while(k < 10)
    {
        if(cellak[i].nok + cellak[i].ferfiak == 10) i++; //Elso nem tele
        if(cellak[j].nok + cellak[j].ferfiak == 0) j--; //Utolso nem ures
        k++;
    }
    k=0;

    if(i >= j) break;


    if(j%2 == 0)
    {
        cellak[j].ferfiak--;
        cellak[i].ferfiak++;
    }
    else{
        cellak[j].nok--;
        cellak[i].nok++;
    }
    }

    int nem_sajat = 0;
    for(i = 0; cellak[i].ferfiak != 0 || cellak[i].nok != 0; i++)
    {
        if(i % 2 == 0)
        {
            if(cellak[i].nok != 0) nem_sajat+= cellak[i].nok;
        }
        else{
            if(cellak[i].ferfiak != 0) nem_sajat+= cellak[i].ferfiak;
        }
    }

    
    return nem_sajat;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct player
{
    char name[30];
    //char nation[30];
    char league[30];
    //char team[30];
    //char position[30];
    int age;
    //int height;
    //int number;
}Player;

void Add(Player * arr, int * pnum);
void Delete(Player * arr, int * pnum);
void Print_List(Player * arr, int pnum);    //* X
void Search(Player * arr, int * pnum);
void Save(Player * arr, int pnum);          //* X
void Load(Player * arr, int * pnum);

Player arr[100];
int pnum = 0;

void main(void)
{
    int m;

    system("clear");
    printf("Player management program!\n\n");
    while(1)
    {
        printf("----------menu----------\n");
        printf("1. Add player\n");
        printf("2. Delete player\n");
        printf("3. Print player list\n");
        printf("4. Search player\n");
        printf("5. Save data\n");
        printf("6. Load data\n");
        printf("7. Exit program\n");
        printf(">>Select : ");
        scanf("%d", &m);
        fflush(stdin);
        switch(m)
        {
            case 1:
                Add(arr, &pnum);    //&
                break;              //
            case 2:
                Delete(arr, &pnum);
                break;
            case 3:
                Print_List(arr, pnum);
                break;
            case 4:
                Search(arr, &pnum);
                break;
            case 5:
                Save(arr, pnum);
                break;
            case 6:
                Load(arr, &pnum);
                break;
            case 7:
                printf("\n-> Program has been closed!\n\n");
                return;
                break;
            default:
                printf("\n-> Please enter the correct menu!\n\n");
                break;
        }
    }
}

void Add(Player * arr, int * pnum)      //int
{
    char name[30];
    char league[30];
    int age;
    int i, l;          //

    system("clear");
    printf("\n--------------------Add player--------------------\n\n");

    printf("name : ");
    scanf("%s", name);
    printf("league : 1.Pre/2.La/3.Serie/4.Bunde\n");
    printf(">>Select : ");
    scanf("%d", &l);
    fflush(stdin);
    switch(l)
    {
        case 1:
            strcpy(league, "Pre");
            break;
        case 2:
            strcpy(league, "La");
            break;
        case 3:
            strcpy(league, "Serie");
            break;
        case 4:
            strcpy(league, "Bunde");
            break;
        default:
            strcpy(league, "No");
            break;
    }
    printf("age : ");
    scanf("%d", &age);

    strcpy(arr[*pnum].name, name);
    strcpy(arr[*pnum].league, league);
    arr[*pnum].age = age;
    (*pnum)++;
}

void Delete(Player * arr, int * pnum)
{
    char name[30];
    int i, j;

    system("clear");
    printf("\n----------Delete player----------\n\n");
    
    printf("name : ");
    scanf("%s", name);

    for(i=0 ; i<*pnum ; i++)
    {
        if(strcmp(arr[i].name, name) == 0)      //i
        {
            for(j=i+1 ; j<*pnum ; j++)
            {
                strcpy(arr[j-1].name, arr[j].name);
                strcpy(arr[j-1].league, arr[j].league);
                arr[j-1].age = arr[j].age;
            }
            (*pnum)--;      //
            return;         //
        }
    }

    printf("\n-> There is no such name!\n\n");      //
}

void Print_List(Player * arr, int pnum)
{
    int i;

    system("clear");
    printf("\n----------Print player list-----------\n\n");

    for(i=0 ; i<pnum ; i++)
    {
        printf("player %d\n", i+1);
        printf("name : %s\n", arr[i].name);
        printf("league : %s\n", arr[i].league);
        printf("age : %d\n\n", arr[i].age);
    }
}

void Search(Player * arr, int * pnum)
{
    char name[30];
    int i = 0;

    system("clear");
    printf("\n----------Search player----------\n\n");

    printf("name : ");
    scanf("%s", name);

    for(i=0 ; i<*pnum ; i++)
    {
        if(strcmp(arr[i].name, name) == 0)          //i
        {
            printf("\nrecognized player\n");
            printf("name : %s\n", arr[i].name);
            printf("league : %s\n", arr[i].league);
            printf("age : %d\n", arr[i].age);
            return;     //
        }
    }

    printf("\n-> There is no such name!\n\n");      //
}

void Save(Player * arr, int pnum)
{
    int i;
    FILE *fp = fopen("data.txt", "wt");
    if(fp == NULL)
    {
        return;
    }

    for(i=0 ; i<pnum ; i++)
    {
        fprintf(fp, "%s\n", arr[i].name);
        fprintf(fp, "%s\n", arr[i].league);
        fprintf(fp, "%d\n\n", arr[i].age);
    }

    system("clear");
    printf("\n-> Saved Data!\n\n");
}

void Load(Player * arr, int * pnum)
{
    FILE *fp = fopen("data.txt", "rt");
    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        fscanf(fp, "%s", arr[*pnum].name);
        fscanf(fp, "%s", arr[*pnum].league);
        fscanf(fp, "%d", &arr[*pnum].age);  //&

        if(feof != 0)       //
            break;          //
        (*pnum)++;
    }

    system("clear");
    printf("\n-> Loded data!\n\n");
}


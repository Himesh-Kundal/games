#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

int randomNum(int n){
    srand(time(NULL));
    return rand()%n;
}

int shoot(char p[],int *n, int* num)
{
    char choice;
    printf("%s type y to shoot yourself: ",p);
    scanf(" %c",&choice);
    if (choice=='y'){
        if ((*num)==(*n)){ 
            printf("%s Died\n",p);
            return 1;
        }
        else 
        {
            (*num)++;
            printf("%s lived\n",p);
//          printf("%d\n",*num);
            return 0;
        }
    }
    else 
    {
        if ((*num)==(*n)){ 
            printf("%s Died\n",p);
            return 1;
        }
        else 
        {
            (*num)++;
            printf("%s lived\n",p);
//          printf("%d\n",*num);
            return 0;
        }
    }

}

void play (char Players[2][100])
{
    int n =randomNum(6)+1;
 //   printf("n=%d\n",n);
    int num=1;
    int p1_dead=0;
    int p2_dead=0;
 //   printf("Name of Players are: %s %s\n",Players[0], Players[1]);
    for(int i=0;i<6;i++)
    {
        p1_dead=shoot(Players[0],&n,&num);
        if (p1_dead) break;
        p2_dead=shoot(Players[1],&n,&num);
        if (p2_dead) break;
    }
 //   printf("Game ended\n");
    
}

int main()
{
    char Players[2][100];
    printf("Welcome to Russian Roullete. Its a 2 Player Game.\n");
    printf("Player 1 will be the first one to try!\n");
    printf("Enter name of Player 1\n");
    scanf("%s",Players[0]);
    printf("Enter name of Player 2\n");
    scanf("%s",Players[1]);

    play (Players);


    return 0;
}
#include<stdio.h>
#include<stdlib.h>


void printgrid(char a[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%c ",a[i][j]);
        }
        printf("\n");
    }
}

void check(char a[3][3],char x)
{
    int flag = 0;
    for(int i=0;i<3;i++)
    {
        if( (a[i][0]==x) && (a[i][1]==x)&&(a[i][2]==x))
        {
            printf("%c WON!!\n",x);
            exit(0);
        }
    }

    for(int i=0;i<3;i++)
    {
        if( (a[0][i]==x) && (a[1][i]==x)&&(a[2][i]==x))
        {
            printf("%c WON!!\n",x);
            exit(0);
        }
    }

    if ((a[0][0]==x) && (a[1][1]==x) && (a[2][2]==x))
        {
            printf("%c WON!!\n",x);
            exit(0);
        }

    if ((a[0][2]==x) && (a[1][1]==x) && (a[2][0]==x))
        {
            printf("%c WON!!\n",x);
            exit(0);
        }

    int lol = 0;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if (a[i][j]=='-') lol=1;
        }
    }

    if(!lol) 
    {
        printf("DRAW!!\n");
        exit(0);
    }
}

void enter(char a[3][3],char x)
{
    int m,n;
    printf("player %c Enter position: ",x);
    scanf("%d %d",&m,&n);
    while(m<1 || m>3 || n<1 || n>3)
    {
        printf("Invalid input, player %c Enter position again.",x);
        scanf("%d %d",&m,&n);
    }


    if ( a[m-1][n-1] == '-')
        a[m-1][n-1] = x;
    else 
    {
        printf("Invalid position\n");
        enter( a, x);
    }
}

void play(char a[3][3])
{
    while (1)
    {
        enter(a,'X');
        printgrid(a);
        check(a,'X');

        enter(a,'O');
        printgrid(a);
        check(a,'O');
    }
}

int main()
{
    char a[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            a[i][j] ='-';
        }
    }

    printgrid(a);
    play(a);



    return 0;
}
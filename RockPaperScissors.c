#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int randomNum(int n){
    srand(time(NULL));
    return rand()%n;
}

void choose();

void ask(){
    printf("\nWanna Play Again?(y/n)");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') return choose();
    else if (choice == 'n' || choice == 'N') return ;
}

void choose(){
    int choice=69;
    while (choice<0||choice>2){
    printf("Choose Rock(0),Paper(1) or Scissors(2)\n");
    scanf("%d", &choice);
    }
    int num=randomNum(3);
    printf("\n");
    if (num == 0) printf("The computer chose Rock.\n");
    else if (num == 1) printf("The computer chose Paper.\n");
    else if (num == 2) printf("The computer chose Scissors.\n");

    if ((num-choice)==0) printf("Its a Tie\n");
    else if ((num-choice)==1||(num-choice)==-2) printf("You Lost\n");
    else if ((num-choice)==2||(num-choice)==-1) printf("You Win\n");
    ask();
}

int main(){
    printf("Welcome to Rock Paper and Scissors.\n");
    choose();
    return 0;
}

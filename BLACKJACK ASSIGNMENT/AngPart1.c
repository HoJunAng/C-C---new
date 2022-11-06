#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define getName(var) #var

int Deck[52];
int ShuffledDeck[52];
int income1;
int income2;
int income3;
int income4;
int income5;
int bet1;
int bet2;
int bet3;
int bet4;
int bet5;
int incomedealer;
int balance1;
int balance2;
int balance3;
int balance4;
int balance5;
int balancedealer;
void betturn1();
void playturn1();
void initdeck();
void checkAce(int v1, int v2, int *a1);
void result();
void shuffledeck();
int play(int p);
void rank(int a, int);


int main(){
  
    char str[6];
    printf("Hello! My name is BlackJackBot (creative, I know!).\nToday is either going to be your luckiest day, or your worse day known to man kind...\n*cough cough* Let's move on! Enter play if you wann play! Enter quit if you wanna quit!\n");
    scanf("%5s", &str);
    if(strcmp(str, "quit") == 0){
      printf("Thanks for playing!");
      exit(0);
    }
    else if (strcmp(str, "play") == 0){
      int p;
      printf("Enter the number of players that are playing! (2-6 players only please!)\n");
      scanf("%d", &p);
      if(p<7 && p>1)
        play(p);
      else
        printf("Wrong input, please restart the code!");
        exit(0);
      }
    else
      printf("Wrong input, please restart the code!\n");
      exit(0);
}

int play(int p){

  printf("Everyone starts with $50 dollars, hurray!!!");

  if(p == 2){
    int balance1 = 50;
    int balancedealer = 50;
    while(balance1>0){
        betturn1();
        initdeck();
        shuffledeck();
        playturn1();
    }
    while(balancedealer>0){
        playturndealer();
    }
    
    if(balancedealer<0){
      printf("PLAYERS WIN! NICE JOB!!!");
      exit(0);
    }
    else if (balance1<0)
      printf("DEALER WINS! LUCKY DAY FOR THE HOUSE TODAY!!!");
      exit(0);
  }

  else if(p == 3){
    int balance1 = 50;
    int balance2 = 50;
    int balancedealer = 100;

    while(balance1>0){
        betturn1();
        initdeck();
        shuffle();
        playturn1();
    }
    while(balance2>0){
        betturn2();
        playturn2();
    }
    while(balancedealer>0){
      playturndealer();
    }

    if(balancedealer<0){
      printf("PLAYERS WIN! NICE JOB!!!");
      exit(0);
    }
    else if (balance1<0 && balance2<0)
      printf("DEALER WINS! LUCKY DAY FOR THE HOUSE TODAY!!!");
      exit(0);

  }

  else if(p == 4){
    int balance1 = 50;
    int balance2 = 50;
    int balance3 = 50;
    int balancedealer = 150;

    while(balance1>0){
        betturn1();
        initdeck();
        shuffle();
        playturn1();
    }
    while(balance2>0){
        betturn2();
        playturn2();
    }
    while(balance3>0){
      betturn3();
      playturn3();
    }
    while(balancedealer>0){
      playturndealer();
    }

    printf("Aww, you  lost :(. Better luck next time pal!");
    if(balancedealer<0){
      printf("PLAYERS WIN! NICE JOB!!!");
      exit(0);
    }
    else if (balance1<0 && balance2<0 && balance3<0)
      printf("DEALER WINS! LUCKY DAY FOR THE HOUSE TODAY!!!");
      exit(0);
  }

  else if(p == 5){
    int balance1 = 50;
    int balance2 = 50;
    int balance3 = 50;
    int balance4 = 50;
    int balancedealer = 200;

    while(balance1>0){
        betturn1();
        initdeck();
        shuffle();
        playturn1();
    }
    while(balance2>0){
        betturn2();
        playturn2();
    }
    while(balance3>0){
      betturn3();
      playturn3();
    }
    while(balance4>0){
      betturn4();
      playturn4();
    }
    while(balancedealer>0){
      playturndealer();
    }

    if(balancedealer<0){
      printf("PLAYERS WIN! NICE JOB!!!");
      exit(0);
    }
    else if (balance1<0 && balance2<0 && balance3<0 && balance4<0)
      printf("DEALER WINS! LUCKY DAY FOR THE HOUSE TODAY!!!");
      exit(0);
  }
  
  else if (p == 6){
    int balance1 = 50;
    int balance2 = 50;
    int balance3 = 50;
    int balance4 = 50;
    int balance5 = 50;
    int balancedealer = 250;
  
    while(balance1>0){
        betturn1();
        initdeck();
        shuffle();
        playturn1();
    }
    while(balance2>0){
        betturn2();
        playturn2();
    }
    while(balance3>0){
      betturn3();
      playturn3();
    }
    while(balance4>0){
      betturn4();
      playturn4();
    }
    while(balance5>0){
      betturn5();
      playturn5();
    }
    while(balancedealer>0){
      playturndealer();
    }

    if(balancedealer<0){
      printf("PLAYERS WIN! NICE JOB!!!");
      exit(0);
    }
    else if (balance1<0 && balance2<0 && balance3<0 && balance4<0 && balance5<0)
      printf("DEALER WINS! LUCKY DAY FOR THE HOUSE TODAY!!!");
      exit(0);
  }

  else
    printf("Somethig went wrong, please restart the code!");
    exit(0);

}

void betturn1(){
    int bet1;
    printf("Alrighty! Enter how much you would wat to bet for Player 1!\n(Make sure it's more than zero and it's within your balance range or you have to restart the code again!)\n");
    scanf("%d", &bet1);
    while(bet1 > balance1 || bet1 <=0){
        if(bet1 > balance1 || bet1 <= 0){
            printf("Incorrect input, please restart the code!");
            exit (0);
        }
        else{
            printf("Incorrect input, please restart the code!\n");
            exit(0);
        }
    }
    balance1 -= bet1;
    printf("You've made a bet of %d. Good luck!\n", bet1);
    income1 = bet1;      
}

void betturn2(){
    int bet2;
    printf("Alrighty! Enter how much you would wat to bet for Player 2!\n(Make sure it's more than zero and it's within your balance range or you have to restart the code again!)\n");
    scanf("%d", &bet2);
    while(bet2 > balance2 || bet2 <=0){
        if(bet2 > balance2 || bet2 <= 0){
            printf("Incorrect input, please restart the code!");
            exit (0);
        }
        else{
            printf("Incorrect input, please restart the code!\n");
            exit(0);
        }
    }
    balance2 -= bet2;
    printf("You've made a bet of %d. Good luck!\n", bet2);
    income2 = bet2;      
}

void betturn3(){
    int bet3;
    printf("Alrighty! Enter how much you would wat to bet Player 3!\n(Make sure it's more than zero and it's within your balance range or you have to restart the code again!)\n");
    scanf("%d", &bet3);
    while(bet3 > balance3 || bet3 <=0){
        if(bet3 > balance3 || bet3 <= 0){
            printf("Incorrect input, please restart the code!");
            exit (0);
        }
        else{
            printf("Incorrect input, please restart the code!\n");
            exit(0);
        }
    }
    balance3 -= bet3;
    printf("You've made a bet of %d. Good luck!\n", bet3);
    income3 = bet3;      
}

void betturn4(){
    int bet4;
    printf("Alrighty! Enter how much you would wat to bet Player 4!\n(Make sure it's more than zero and it's within your balance range or you have to restart the code again!)\n");
    scanf("%d", &bet4);
    while(bet4 > balance4 || bet4 <=0){
        if(bet4 > balance4 || bet4 <= 0){
            printf("Incorrect input, please restart the code!");
            exit (0);
        }
        else{
            printf("Incorrect input, please restart the code!\n");
            exit(0);
        }
    }
    balance4 -= bet4;
    printf("You've made a bet of %d. Good luck!\n", bet4);
    income4 = bet4;      
}

void betturn5(){
    int bet5;
    printf("Alrighty! Enter how much you would wat to bet Player 5!\n(Make sure it's more than zero and it's within your balance range or you have to restart the code again!)\n");
    scanf("%d", &bet5);
    while(bet5 > balance5 || bet5 <=0){
        if(bet5 > balance5 || bet5 <= 0){
            printf("Incorrect input, please restart the code!");
            exit (0);
        }
        else{
            printf("Incorrect input, please restart the code!\n");
            exit(0);
        }
    }
    balance5 -= bet5;
    printf("You've made a bet of %d. Good luck!\n", bet5);
    income5 = bet5;      
}

int hit(int *i){
  int a = ShuffledDeck[*i];
  *i = *i +1;
  return a;
}

void initdeck(){
    int i=0;
    for(i;i<52;i++){
        Deck[i] = i+1;  
    }
}

void shuffledeck(){
  srand(time(NULL));
  int i = 0;
  for(i; i<52; i++){
    ShuffledDeck[i] = Deck[i];
  }
  int i=0;
  for(i=52-1; i>0; i--){
    int j = rand() % (i+1);
    int n = ShuffledDeck[i];
    ShuffledDeck[i] = ShuffledDeck[j];
    ShuffledDeck[j] = n;
  }
}

int cval(int b){
    int a;
    if(((b%13)+1)<10)
        a = b%13+1;
    else 
        a = 10;
    return a;
}

char *csuit(int b){
    b = b%4;
    switch(b){
        case 0 :
            return "Hearts";
        case 1 :
            return "Clubs";
        case 2 :
            return "Diamonds";
        case 3 :
            return "Spades";
    }
}

char *cface(int b){
    b = b%13+1;
    char *outcome;
    switch(b){
        case 1 :
            outcome = "Ace";
            break;
        case 2 :
            outcome = "Two";
            break;
        case 3 :
            outcome = "Three";
            break;
        case 4 :
            outcome = "Four";
            break;
        case 5 :
            outcome = "Five";
            break;
        case 6 :
            outcome = "Six";
            break;
        case 7 :
            outcome = "Seven";
            break;
        case 8 :
            outcome = "Eight";
            break;
        case 9 :
            outcome = "Nine";
            break;
        case 10 :
            outcome = "Ten";
            break;
        case 11 :
            outcome = "Jack";
            break;
        case 12 :
            outcome = "Queen";
            break;
        case 13 :
            outcome = "King";
    }
    return outcome;
}

void playturn1(){
    int garbage=0; // garbage value
     
    int a1 = hit(&garbage); // hit(int *i = &inc)
    char *acs1 = csuit(a1);
    char *acf1 = cface(a1);
    int acv1 = cval(a1);

    printf("Let's start! You got a %s of %s worth %d, and ", acf1, acs1, acv1);

    int a2 = hit(&garbage);
    char *acs2 = csuit(a2);
    char *acf2 = cface(a2);
    int acv2 = cval(a2);

    printf("a %s of %s worth %d.\n", acf2, acs2, acv2);

    int d1 = hit(&garbage);
    char *dcs1 = csuit(d1);
    char *dcf1 = cface(d1);
    int dcv1 = cval(d1);

    printf("The dealer's face up card is a %s of %s worth %d.\n", dcf1, dcs1, dcv1);

    int d2 = hit(&garbage);
    char *dcs2 = csuit(d2);
    char *dcf2 = cface(d2);
    int dcv2 = cval(d2);

    int player1total = acv1 + acv2;
    int dealertotal = dcv1;

    checkAce(acv1, acv2, &player1total);

    printf("You have a total of %d points, and the dealer has %d.\n", player1total, dealertotal);  

    if(player1total == 21){
        printf("Congrats! You got a blackjack!! Your payout is 2:1, %d.\n", income1*2);
        balance1 += (income1*2);
    }else{
        char input[6];
        scanf("%5s", input);
        // you stopped here!!!
        while(strcmp(input,"stand") != 0){
            if(strcmp(input,"hit") == 0){
                int a3 = hit(garbage);
                char *acs3 = csuit(a3);
                char *acf3 = cface(a3);
                int acv2 = cval(a3);
                player1total += acv2;
                printf("You got a %s of %s worth %d.\n", acf3, acs3, acv2);
                if(player1total < 21){
                    if(acv2==1){
                        if(player1total+10 == 21){
                            player1total += 10;
                            printf("Congrats! You got 21! Payout is 2-to-1.\n");
                            balance1 += (income1*2);                         
                            break;
                        }else{
                            int input;
                            printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
                            scanf("%d",&input);
                            if(input == 11)
                                player1total += 10;
                        }
                    }
                }else if(player1total == 21){
                    printf("Congrats! You got 21!\n");
                    break;
                }else{
                    printf("Oh no, you've busted with %d. Try Again!\n", player1total);
                    break;
                }
            }else
                printf("Wrong input, please restart the code!\n");
            printf("Your new total is %d.\n", player1total);
            scanf("%5s", input);
        }
    }

    if(player1total < 21){

        printf("The dealer's flips a %s of %s worth %d.\n", dcf2, dcs2, dcv2);
        dealertotal += dcv2;
        if(dcv2 == 1){
            if(dealertotal+11 < 21)
                dealertotal += 10;
        }

        if(dealertotal >= 16){
            printf("The dealer stands with %d.\n", dealertotal);
        }

        while(dealertotal < 16){
            int d3 = hit(&garbage);
            char *dcs3 = csuit(d3);
            char *dcf3 = cface(d3);
            int dcv3 = cval(d3);
            dealertotal += dcv3;
            printf("The dealer got a %s of %s worth %d.\n", dcf3, dcs3, dcv3);
            if(dealertotal < 16){
                if(dcv3==1){
                    if(dealertotal+11<21)
                        dealertotal += 10;
                }
            }else if(dealertotal == 21){
                printf("The dealer just got 21.\n");
                break;
            }else if(dealertotal > 21){
                printf("The dealer busted with %d! You win!\n", dealertotal);
                break;
            }else{
                printf("The dealer stands with %d.\n", dealertotal);
                break;
            }
            printf("The dealer's new total is %d.\n", dealertotal);
        }
        if(dealertotal<player1total){
            printf("You beat the dealer! Your payout is %d.\n", (int)(income1*1.5)); 
            balance1 += (income1*1.5);
        }else if(dealertotal==player1total){
            printf("Its a tie! Push pot, 1-to-1 payout of %d.\n", income1);
            balance1 += income1;
        }else if(dealertotal>player1total && dealertotal <= 21){
            printf("Oh no! Looks like the dealer won. Try again!\n");   
        }else{
            printf("You beat the dealer! Your payout is %d.\n", (int)(income1*1.5)); 
            balance1 += (income1*1.5);
        }
    }
    if(balance1 > 0)
        printf("Your new balance is %d.\n", balance1);
}

void playturn2(){}

void playturn3(){}

void playturn4(){}

void playturn5(){}

void dealerturn(){}

void checkAce(int v1, int v2, int *a1){
    if(v1 == 1 || v2 == 1){
        int input;
        if(v1 == 1 && v2 == 1){
            v1 = 11;
            v2 = 1;
            *a1 = 12;
            printf("Since you got 2 Aces, we set one to be worth 11 and the other to be worth 1.\n");
        }else if(v1 == 1 || v2 == 1){
            if(v1+10+v2 == 21)
                *a1 == 21;
            else{
                printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
                scanf("%d",&input);
                if(input == 11)
                    *a1 += 10;
            }
        }
    }
}
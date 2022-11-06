4.c
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include <time.h>
    
    int Deck[52];
    int ShuffledDeck[52];
    int balance1 = 50;
    int balance2 = 50;
    int balance3 = 50;
    int balance4 = 50;
    int balance5 = 50;
    void playturn1();
    void initdeck();
    void checkAce(int v1, int v2, int *a1);
    void result();
    void shuffledeck();
    int play(int p);
    
    int main(){
      
        int input2;
        printf("Hello! My name is BlackJackBot (creative, I know!).\nToday is either going to be your luckiest day, or your worse day known to man kind...\n*cough cough* Let's move on! Type 1 play if you wanna play! Type 2 quit if you wanna quit!\n");
        scanf("%d", &input2);
        if(input2 == 2){
          printf("Thanks for playing!");
          exit(0);
        }
        else if (input2 == 1){
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
      int balancedealer = (p-1) * 50;
      printf("Everyone starts with $50 dollars, hurray!!!\n");

      if(p == 2){
        while(balance1>0){
            initdeck();
            shuffledeck();
            playturn1();
        }
        if(balance1<=0){
            printf("GAME OVER! DEALER WON!!!");
            exit(0);
        }

      }
        printf("Somethig went wrong, please restart the code!");
        exit(0);
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
        int i=0;
        for(i;i<52;i++){
            ShuffledDeck[i] = Deck[i];
        }
        i=0;
        for(i=52-1;i>0;i--){
            int j = rand()%(i+1);
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
    
    void playturn1(){

        printf("Alright, it's Player's 1 turn!\n");
        printf("Your current balance is $%d.\n", balance1);
        printf("You've made a bet of $5. Good luck!\n\n");

        int garbage=0; // garbage value
        int a1 = hit(&garbage); // hit(int *i = &inc)
        char *acs1 = csuit(a1);
        char *acf1 = cface(a1);
        int acv1 = cval(a1);
        
        printf("You got a %s of %s worth %d, and ", acf1, acs1, acv1);
        
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
    
        printf("You have a total of %d points, and the dealer has %d.\n(type 1 to draw a card, or type 2 to end your turn!)\n", player1total, dealertotal);  
    
        if(player1total == 21){

            printf("Congrats! You got a blackjack!");
            balance1 += 5;
        }
        
        else{

            int input;
            scanf("%d", &input);

            while(input != 2){

                if(input = 1){

                    int a3 = hit(&garbage);
                    char *acs3 = csuit(a3);
                    char *acf3 = cface(a3);
                    int acv2 = cval(a3);
                    player1total += acv2;
                    printf("You got a %s of %s worth %d.\n", acf3, acs3, acv2);

                    if(player1total <= 21){
                        
                        if(acv2==1){

                            int input;
                            printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
                            scanf("%d",&input);
                            if(input == 11)
                            player1total += 10;
                        }                    
                    }

                    else if(player1total >21){
                        
                    printf("Oh no, you've busted with %d. Try Again!\n", player1total);
                        balance1 -= 5;
                        break;
                    }

                    else{

                    printf("Wrong input, please restart the code!\n");
                    exit(0);
                    }

                    printf("Your new total is %d.\n", player1total);
                    scanf("%d", &input);
                }
            }
        }

        if(player1total <= 21){

            printf("The dealer's flips a %s of %s worth %d.\n", dcf2, dcs2, dcv2);
            dealertotal += dcv2;

            if(dcv2 == 1){

                if(dealertotal+11 < 21)
                    dealertotal += 10;
            }
    
            if(dealertotal >= 16)
                printf("The dealer stands with %d.\n", dealertotal);
    
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

                printf("You beat the dealer! You gained $5!\n");
                balance1 += 5;
            }

            else if(dealertotal==player1total)
                printf("Its a tie! Push pot, no one wins anything!");
            
            else if(dealertotal>player1total && dealertotal <= 21){
               
                printf("Oh no! Looks like the dealer won. Goodbye $5... Try again!\n"); 
                balance1 -= 5;  
            }
            
            else{

                printf("You beat the dealer! Your payout is $5.\n"); 
                balance1 += 5;
            }
        }
    }
  
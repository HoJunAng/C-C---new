#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#define getName(var) #var

int input; // for inputs from users to either play, quit, hit, stand, or choose which ace. 
int Deck[52];
int ShuffledDeck[52];
int player1total;
int player2total;
int player3total;
int player4total;
int player5total;
int dealertotal;
int balance1 = 10;
int balance2 = 5;
int balance3 = 50;
int balance4 = 50;
int balance5 = 50;
int balancedealer;
int BalanceNumber = -6;
int PositionNumber = 6;
int position1;
int position2;
int position3;
int position4;
int position5;
int blackjack1 = 1;
int bust1 = 1;
int blackjack2 = 1;
int bust2 = 1;
int blackjack3 = 1;
int bust3 = 1;
int blackjack4 = 1;
int bust4 = 1;
int blackjack5 = 1;
int bust5 = 1;
int bustdealer = 1;
int dcv1;
int garbage;
void playturn1();
void playturn2();
void playturn3();
void playturn4();
void playturn5();
void playturndealer();
void initdeck();
void checkAce(int v1, int v2, int *a1);
void result();
void shuffledeck();
int play(int p);
    
int main(){
    
    // to ask the user if they want to play or quit the game
    printf("Hello! My name is BlackJackBot (creative, I know!).\nToday is either going to be your luckiest day, or your worse day known to man kind...\n*cough cough* Let's move on! Type 1 play if you wanna play! Type 2 quit if you wanna quit!\n");
    scanf("%d", &input);

    if(input == 2){ // quit function
        
        printf("Thanks for playing!");
        exit(0);
    }

    else if(input == 1){ // play function

        int p; // to ask how many players are playing
        printf("Enter the number of players that are playing! (2-6 players only please!)\n");
        scanf("%d", &p);

        if(p<7 && p>1) // to ensure it's between 2-6 players
            play(p);

        else{ /* This code will be added multiple times so that the code won't break when the input is wrong from the user.
                 If the input is wrong, all players must restart the code in order to play again. */

            printf("Wrong input, please restart the code!");
            exit(0);
        }
    }

    else{

        printf("Wrong input, please restart the code!\n");
        exit(0);
    }
}

int play(int p){
    
    balancedealer = (p-1) * 50;
    printf("All players starts with $50! And the dealer starts with %d!\n", balancedealer);
    if(p == 2){

        while(balance1 > 0 && balancedealer > 0){
            
            initdeck();
            shuffledeck();
            playturn1();
            playturndealer();
        }

        if(balance1<=0){
            printf("GAME OVER! DEALER WON!!!\n");
            printf("1st Place: Dealer\n2ndP Place: Player 1\n");
            exit(0);
        }
        if(balancedealer<=0){
            printf("GAME OVER! PLAYERS WON!!!\n");
            printf("1st Place: Player 1\n2ndP Place: Dealer\n");
            exit(0);
        }
    }

    else if(p == 3){

        while((balance1>0 || balance2>0) && balancedealer>0){
            
            initdeck();
            shuffledeck();

            if(balance1>0)
                playturn1();
            if(balance2>0)
                playturn2();
            playturndealer();
        }

        if(balancedealer<=0){
            printf("PLAYERS WIN! NICE JOB!!!\n");
            if(balance1>=balance2){
                printf("1st Place: Player 1\n2nd Place: Player 2\n3rd Place: Dealer\n");
                exit(0);
            }
            else if(balance1<=balance2){
                printf("1st Place: Player 2\n2nd Place: Player 1\n3rd Place: Dealer\n");
                exit(0);
            }
        }

        else if(balance1<=0 && balance2<=0){
            printf("DEALER WINS! LUCKY DAY FOR THE HOUSE TODAY!!!\n");
            if(position1<position2){
                printf("1st Place: Dealer\n2nd Place: Player 1\n3rd Place: Player 2\n");
                exit(0);
            }
            else if(position1>position2){
                printf("1st Place: Dealer\n2nd Place: Player 2\n3rd Place: Player 1\n");
                exit(0);
            }
        }
    }

    else if(p == 4){

        while((balance1>0 || balance2>0 || balance3>0) && balancedealer>0){
            
            initdeck();
            shuffledeck();

            if(balance1>0)
                playturn1();
            if(balance2>0)
                playturn2();
            if(balance3>0)
                playturn3;
            playturndealer();
        }

        if(balancedealer<=0){
            printf("PLAYERS WIN! NICE JOB!!!\n");
            if(balance1>=balance2 && balance2>=balance3){
                printf("1st Place: Player 1\n2nd Place: Player 2\n3rd Place: Player 3\n4th Place: Dealer");
                exit(0);
            }
            else if(balance1>=balance2 && balance3>=balance2){
                printf("1st Place: Player 1\n2nd Place: Player 3\n3rd Place: Player 2\n4th Place: Dealer");
                exit(0);
            }

            else if(balance2>=balance1 && balance1>=balance3){
                printf("1st Place: Player 2\n2nd Place: Player 1\n3rd Place: Player 3\n4th Place: Dealer");
                exit(0);
            }
            else if(balance2>=balance1 && balance3>=balance1){
                printf("1st Place: Player 2\n2nd Place: Player 3\n3rd Place: Player 1\n4th Place: Dealer");
                exit(0);
            }

            else if(balance3>=balance1 && balance1>=balance2){
                printf("1st Place: Player 3\n2nd Place: Player 1\n3rd Place: Player 2\n4th Place: Dealer");
                exit(0);
            }
            else if(balance3>=balance1 && balance2>=balance1){
                printf("1st Place: Player 3\n2nd Place: Player 2\n3rd Place: Player 1\n4th Place: Dealer");
                exit(0);
        }
        }

        else if(balance1<=0 && balance2<=0){
            printf("DEALER WINS! LUCKY DAY FOR THE HOUSE TODAY!!!\n");
            if(position1<position2){
                printf("1st Place: Dealer\n2nd Place: Player 1\n3rd Place: Player 2\n");
                exit(0);
            }
            else if(position1>position2){
                printf("1st Place: Dealer\n2nd Place: Player 2\n3rd Place: Player 1\n");
                exit(0);
            }
        }
    }
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


        blackjack1 = 0;
        bust1 = 0;
        printf("Alright, it's Player's 1 turn!\n");
        printf("Your current balance is $%d.\n", balance1);
        printf("The Dealer's balance is $%d.\n", balancedealer);

        garbage=0; // garbage value
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
        dcv1 = cval(d1);
        
        printf("The dealer's face up card is a %s of %s worth %d.\n", dcf1, dcs1, dcv1);
        
        player1total = acv1 + acv2;
        dealertotal = dcv1;
        
        checkAce(acv1, acv2, &player1total);
        
        printf("You have a total of %d points, and the dealer has %d.\n(type 1 to draw a card, or type 2 to end your turn!)\n", player1total, dealertotal);  
        
        if(player1total == 21){

            printf("Congrats! You got a blackjack! Dealer losses $5, and you gained $5!");
            balance1 += 5;
            balancedealer -=5;
            blackjack1 = 1;
        }
            
        else{

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

                            printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
                            scanf("%d",&input);
                            if(input == 11)
                            player1total += 10;
                        
                            if(player1total >21){
                                
                                printf("Oh no, you've busted with %d. You lost $5 while the Dealer gains $5!\n", player1total);
                                balance1 -= 5;
                                balancedealer +=5;
                                bust1 = 1;

                                if(balance1<=0){
                                    printf("Aww, Player 1 lost...");
                                    balance1=BalanceNumber;
                                    BalanceNumber--;
                                    position1 = PositionNumber;
                                    PositionNumber--;
                                    blackjack1 = 1;
                                    bust1 = 1;
                                }

                                break;
                            }   
                        }                    
                    }

                    else if(player1total >21){
                            
                    printf("Oh no, you've busted with %d. You lost $5 while the Dealer gains $5!\n", player1total);
                    balance1 -= 5;
                    balancedealer +=5;
                    bust1 = 1;

                    if(balance1<=0){
                        printf("Aww, Player 1 lost...");
                        balance1=BalanceNumber;
                        BalanceNumber--;
                        position1 = PositionNumber;
                        PositionNumber--;
                        blackjack1 = 1;
                        bust1 = 1;
                    }

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
    }

void playturn2(){
    
        blackjack2 = 0;
        bust2 = 0;
        printf("Alright, it's Player's 2 turn!\n");
        printf("Your current balance is $%d.\n", balance2);
        printf("The Dealer's balance is $%d.\n", balancedealer);

        garbage=0; // garbage value
        int b1 = hit(&garbage); // hit(int *i = &inc)
        char *bcs1 = csuit(b1);
        char *bcf1 = cface(b1);
        int bcv1 = cval(b1);
            
        printf("You got a %s of %s worth %d, and ", bcf1, bcs1, bcv1);
            
        int b2 = hit(&garbage);
        char *bcs2 = csuit(b2);
        char *bcf2 = cface(b2);
        int bcv2 = cval(b2);
        
        printf("a %s of %s worth %d.\n", bcf2, bcs2, bcv2);
        printf("The dealer's face up card is a %s of %s worth %d.\n", bcf1, bcs1, bcv1);
        
        player2total = bcv1 + bcv2;
        
        checkAce(bcv1, bcv2, &player2total);
        
        printf("You have a total of %d points, and the dealer has %d.\n(type 1 to draw a card, or type 2 to end your turn!)\n", player2total, dealertotal);  
        
        if(player2total == 21){

            printf("Congrats! You got a blackjack! Dealer losses $5, and you gained $5!");
            balance2 += 5;
            balancedealer -=5;
            blackjack2 = 1;
        }
            
        else{

            scanf("%d", &input);

            while(input != 2){

                if(input = 1){

                    int b3 = hit(&garbage);
                    char *bcs3 = csuit(b3);
                    char *bcf3 = cface(b3);
                    int bcv2 = cval(b3);
                    player2total += bcv2;
                    printf("You got a %s of %s worth %d.\n", bcf3, bcs3, bcv2);

                    if(player2total <= 21){
                            
                        if(bcv2==1){

                            printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
                            scanf("%d",&input);
                            if(input == 11)
                            player2total += 10;

                            if(player2total >21){
                            
                                printf("Oh no, you've busted with %d. You lost $5 while the Dealer gains $5!\n", player2total);
                                balance2 -= 5;
                                balancedealer +=5;
                               

                                if(balance2<=0){
                                    printf("Aww, Player 2 lost...");
                                    balance2=BalanceNumber;
                                    BalanceNumber--;
                                    position2 = PositionNumber;
                                    PositionNumber--;
                                    blackjack2 = 1;
                                    bust2 = 1;
                                }
                                break;
                            }
                        }                    
                    }

                    else if(player2total >21){
                            
                    printf("Oh no, you've busted with %d. You lost $5 while the Dealer gains $5!\n", player2total);
                    balance2 -= 5;
                    balancedealer +=5;
                    bust2 = 1;

                    if(balance2<=0){
                        printf("Aww, Player 2 lost...");
                        balance2=BalanceNumber;
                        BalanceNumber--;
                        position2 = PositionNumber;
                        PositionNumber--;
                        blackjack2 = 1;
                        bust2 = 1;
                    }
                    break;
                    }

                    else{

                    printf("Wrong input, please restart the code!\n");
                    exit(0);
                    }

                    printf("Your new total is %d.\n", player2total);
                    scanf("%d", &input);
                }
            }
        }
    }

void playturndealer(){
    bustdealer = 0;
    if(bust1 == 1 && bust2 == 1 && bust3 == 1 && bust4 == 1 && bust5 == 1)
        printf("Well, everyone busted before the dealer... Anyways, let's move on to the next game!\n");

    else if(dealertotal == 21){

        printf("Congrats! You got a blackjack! All Players who doesn't have a blackjack losses! Sadge...\n");
        if(blackjack1 == 0){
            balance1 -= 5;
            balancedealer +=5;

            if(balance1<=0){
                printf("Aww, Player 1 lost...");
                balance1 = BalanceNumber;
                BalanceNumber--;
                position1 = PositionNumber;
                PositionNumber--;
                blackjack1 = 1;
                bust1 = 1;
            }
        }
        if(blackjack2 == 0){
            balance2 -= 5;
            balancedealer +=5;
            
            if(balance2<=0){
                printf("Aww, Player 2 lost...");
                balance2 = BalanceNumber;
                BalanceNumber--;
                position2 = PositionNumber;
                PositionNumber--;
                blackjack2 = 1;
                bust2 = 1;
            }
        }    
        if(blackjack3 == 0){
            balance3 -= 5;
            balancedealer +=5;

            if(balance3<=0){
                printf("Aww, Player 3 lost...");
                balance3 = BalanceNumber;
                BalanceNumber--;
                position3 = PositionNumber;
                PositionNumber--;
                blackjack3 = 1;
                bust3 = 1;
            }
        }
        if(blackjack4 == 0){
            balance4 -= 5;
            balancedealer +=5;

            if(balance4<=0){
                printf("Aww, Player 4 lost...");
                balance4 = BalanceNumber;
                BalanceNumber--;
                position4 = PositionNumber;
                PositionNumber--;
                blackjack4 = 1;
                bust4 = 1;
            }
        }
        if(blackjack5 == 0){
            balance5 -= 5;
            balancedealer +=5;

            if(balance5<=0){
                printf("Aww, Player 5 lost...");
                balance5 = BalanceNumber;
                BalanceNumber--;
                position5 = PositionNumber;
                PositionNumber--;
                blackjack5 = 1;
                bust5 = 1;
            }
        }
        
        if(blackjack1 == 1 && blackjack2 == 1 && blackjack3 == 1 && blackjack4 == 1 && blackjack5 == 1)
            printf("Well, everyone got a blackjack before the dealer, big yikes for the dealer...\nAnyways, let's move on to the next game!\n");
    }
    
    else{
        printf("Alright, it's the Dealer's turn!\n(Remember, you need to get a total of atleast 17 points as that's the rules.\nIf you don't, rule is broken, and you have to restart the entire game as a punishmen!!!!)\n");
        printf("Your current balance is $%d.\n",  balancedealer);

        if(dcv1==1){

            printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
            scanf("%d",&input);
            if(input == 11)
                dealertotal += 10;
        }

        int d2 = hit(&garbage);
        char *dcs2 = csuit(d2);
        char *dcf2 = cface(d2);
        int dcv2 = cval(d2);
        
        dealertotal = dcv1 + dcv2;
        
        checkAce(dcv1, dcv2, &dealertotal);
        printf("You also got a %s of %s worth %d.\n", dcf2, dcs2, dcv2);
        printf("You have a total of %d points\n(type 1 to draw a card, or type 2 to end your turn!)\n", dealertotal); 
        scanf("%d", &input);

        while(input != 2){

            if(input = 1){

                int d3 = hit(&garbage);
                char *dcs3 = csuit(d3);
                char *dcf3 = cface(d3);
                int dcv2 = cval(d3);
                dealertotal += dcv2;
                printf("You got a %s of %s worth %d.\n", dcf3, dcs3, dcv2);

                if(dealertotal <= 21){
                        
                    if(dcv2==1){

                        printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
                        scanf("%d",&input);
                        if(input == 11)
                            dealertotal += 10;
                        
                        if(dealertotal >21){
                        
                            printf("Oh no, you've busted with %d. All players that didn't bust gains $5 while the Dealer loses $5 each!\n", dealertotal);
                            bustdealer = 1;
                            if(bust1 == 0){
                                balance1 +=5;
                                balancedealer -= 5;
                            }
                            if(bust2 == 0){
                                balance2 +=5;
                                balancedealer -= 5;
                            }
                            if(bust3 == 0){
                                balance3 +=5;
                                balancedealer -= 5;
                            }
                            break;
                        }                    
                    }
                }

                else if(dealertotal >21){
                        
                    printf("Oh no, you've busted with %d. All players that doesn't bust gains $5 while the Dealer loses $5 each!\n", dealertotal);
                    bustdealer = 1;
                    if(bust1 == 0){
                        balance1 +=5;
                        balancedealer -= 5;
                    }
                    if(bust2 == 0){
                        balance2 +=5;
                        balancedealer -= 5;
                    }
                    break;
                }

                else{
                printf("Wrong input, please restart the code!\n");
                exit(0);
                }

                printf("Your new total is %d.\n", dealertotal);
                scanf("%d", &input);
            }
        }
     }

    

    /* initialise bust and blackjack values for all players early on
       and set it to a garbage value so that you only need 1 void dealerturn() function */
    if(bust1 == 0 && blackjack1 == 0 && bustdealer == 0){
        if(dealertotal < 16){
        printf("DEALER HAS LESS THAN 17 POINTS. RULE IS BROKEN, GAME OVER!\nPLEASE RESTART THE CODE TO PLAY AGAIN!!!\n");
        exit(0);
        }
        if(player1total > dealertotal){
            printf("Player 1 wins over dealer! Player 1 gains $5 while dealer losses $5!\n");
            balance1 += 5;
            balancedealer -=5;
        }
        else if(player1total < dealertotal){
            printf("Dealer wins over Player 1! Dealer gains $5 while Player 1 losses $5!\n");
            balance1 -= 5;
            balancedealer += 5;

            if(balance5<=0){
                printf("Aww, Player 1 lost...");
                balance1 = BalanceNumber;
                BalanceNumber--;
                position1 = PositionNumber;
                PositionNumber--;
                blackjack1 = 1;
                bust5 = 1;
            }
        }
        else if(player1total == dealertotal)
            printf("Dealer and Player 1 has the same points, neither wins in this case. PUSH POT!!!\n");
    }

    if(bust2 == 0 && blackjack2 == 0 && bustdealer == 0){
        if(dealertotal < 16){
        printf("DEALER HAS LESS THAN 17 POINTS. RULE IS BROKEN, GAME OVER!\nPLEASE RESTART THE CODE TO PLAY AGAIN!!!\n");
        exit(0);
        }
        if(player2total > dealertotal){
            printf("Player 2 wins over dealer! Player 2 gains $5 while dealer losses $5!\n");
            balance2 += 5;
            balancedealer -=5;
        }
        else if(player2total < dealertotal){
            printf("Dealer wins over Player 2! Dealer gains $5 while Player 2 losses $5!\n");
            balance2 -= 5;
            balancedealer += 5;

            if(balance5<=0){
                printf("Aww, Player 2 lost...");
                balance2 = BalanceNumber;
                BalanceNumber--;
                position2 = PositionNumber;
                PositionNumber--;
                blackjack2 = 1;
                bust2 = 1;
            }
        }
        else if(player1total == dealertotal)
            printf("Dealer and Player 2 has the same points, neither wins in this case. PUSH POT!!!\n");
    }

    if(bust3 == 0 && blackjack3 == 0 && bustdealer == 0){
        if(dealertotal < 16){
        printf("DEALER HAS LESS THAN 17 POINTS. RULE IS BROKEN, GAME OVER!\nPLEASE RESTART THE CODE TO PLAY AGAIN!!!\n");
        exit(0);
        }
        if(player3total > dealertotal){
            printf("Player 3 wins over dealer! Player 3 gains $5 while dealer losses $5!\n");
            balance3 += 5;
            balancedealer -=5;
        }
        else if(player3total < dealertotal){
            printf("Dealer wins over Player 3! Dealer gains $5 while Player 3 losses $5!\n");
            balance3 -= 5;
            balancedealer += 5;

            if(balance3<=0){
                printf("Aww, Player 3 lost...");
                balance3 = BalanceNumber;
                BalanceNumber--;
                position3 = PositionNumber;
                PositionNumber--;
                blackjack3 = 1;
                bust3 = 1;
            }
        }
        else if(player3total == dealertotal)
            printf("Dealer and Player 3 has the same points, neither wins in this case. PUSH POT!!!\n");
    }
    
    if(bust4 == 0 && blackjack4 == 0 && bustdealer == 0){
        if(dealertotal < 16){
        printf("DEALER HAS LESS THAN 17 POINTS. RULE IS BROKEN, GAME OVER!\nPLEASE RESTART THE CODE TO PLAY AGAIN!!!\n");
        exit(0);
        }
        if(player4total > dealertotal){
            printf("Player 4 wins over dealer! Player 4 gains $5 while dealer losses $5!\n");
            balance4 += 5;
            balancedealer -=5;
        }
        else if(player4total < dealertotal){
            printf("Dealer wins over Player 4! Dealer gains $5 while Player 4 losses $5!\n");
            balance4 -= 5;
            balancedealer += 5;

            if(balance4<=0){
                printf("Aww, Player 4 lost...");
                balance4 = BalanceNumber;
                BalanceNumber--;
                position4 = PositionNumber;
                PositionNumber--;
                blackjack4 = 1;
                bust4 = 1;
            }
        }
        else if(player1total == dealertotal)
            printf("Dealer and Player 4 has the same points, neither wins in this case. PUSH POT!!!\n");
    }

    if(bust5 == 0 && blackjack5 == 0 && bustdealer == 0){
        if(dealertotal < 16){
        printf("DEALER HAS LESS THAN 17 POINTS. RULE IS BROKEN, GAME OVER!\nPLEASE RESTART THE CODE TO PLAY AGAIN!!!\n");
        exit(0);
        }
        if(player5total > dealertotal){
            printf("Player 5 wins over dealer! Player 5 gains $5 while dealer losses $5!\n");
            balance5 += 5;
            balancedealer -=5;
        }
        else if(player5total < dealertotal){
            printf("Dealer wins over Player 5! Dealer gains $5 while Player 5 losses $5!\n");
            balance5 -= 5;
            balancedealer += 5;

            if(balance5<=0){
                printf("Aww, Player 5 lost...");
                balance5 = BalanceNumber;
                BalanceNumber--;
                position5 = PositionNumber;
                PositionNumber--;
                blackjack5 = 1;
                bust5 = 1;
            }
        }
        else if(player5total == dealertotal)
            printf("Dealer and Player 5 has the same points, neither wins in this case. PUSH POT!!!\n");
    }
}

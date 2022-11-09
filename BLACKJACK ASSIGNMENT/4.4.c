// if you are planing to read all the comments, good luck my friend!


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>


int input; // for inputs from users to either play, quit, hit, stand, or choose which ace. 
int Deck[52]; // array of numbers that represents the deck of cards
int ShuffledDeck[52]; // same as previous line but shuffled
int player1total; // each player's total points from cards obtained for every round
int player2total;
int player3total;
int player4total;
int player5total;
int dealertotal;
int balance1 = 50; // amount of balance/money of each player
int balance2 = 50;
int balance3 = 50;
int balance4 = 50;
int balance5 = 50;
int balancedealer; // value is declared in int play(p) after user has input the number of players playing
int BalanceNumber = -10;
/* variable that's less than zero, but its modulus must be more than max players playing so 
that it can be used to rank players for situations where some(not all) players goes bankrupt, then dealer goes bankrupt after */
int PositionNumber = 10;
// same concept as previous line but in situations where all players goes bankrupt except for the dealer
int position1;
/* the position number for each player after it goes through a mini-algorithm that
involves doing simple arithmetic to the PositionNumber variable each time a player losses */
int position2;
int position3;
int position4;
int position5;
int blackjack1 = 1;
/* initializing this variable to 1 before the round starts is important as this variable serves 3 purposes
   1. To check that if a player has a blackjack so that the dealer doesn't have to deal with that player for entire current round
   2. If there is a limited amount of players playing (eg. 3 players instead 6), then the dealer is set to not deal with the players that are not playing
   3. If a player losses, then it's blackjack will be set to 1 all the time, and the dealer is set to not deal with that player anymore until the entire game finishes (same concept as 2nd point) */
int bust1 = 1;
/* this variable also serves the same purposes as blackjack1 but with a modification to the first point
   1. To check that if a player has busted so that the dealer doesn't have to deal with that player for entire current round
   2. If there is a limited amount of players playing (eg. 3 players instead 6), then the dealer is set to not deal with the players that are not playing
   3. If a player losses, then it's bust will be set to 1 all the time, and the dealer is set to not deal with that player anymore until the entire game finishes (same concept as 2nd point) */
int blackjack2 = 1;
int bust2 = 1;
int blackjack3 = 1;
int bust3 = 1;
int blackjack4 = 1;
int bust4 = 1;
int blackjack5 = 1;
int bust5 = 1;
int bustdealer = 1; // if dealer bust, then players that haven't bust will automatically win in the current round
int dcv1; // value of first card of dealer will be shown before the dealer's turn
int garbage; // garbage value for selecting a card from the randomised deck
void playturn1(); // turn function for each player
void playturn2();
void playturn3();
void playturn4();
void playturn5();
void playturndealer();
void initdeck(); // creates a new array of deck of unshuffled cards
void shuffledeck(); // shuffles the array of deck of cards 


/* at the start of each player's turn, if the player has an ace from the first 2 cards, this function will check if the other card has a value of 10. If so, then user will get blackjack,
and the user will win the current round. If it's 2 aces instead, then the player's total points is automatically set to 12 points (first ace = 1, second ace = 11).
If it's neither, then it asks the user if the user wants to make the value of the ace to be either a 1 or an 11 */
void checkAce(int v1, int v2, int *a1);


// a function to initiate the number of players for the whole game after the user has input the number of players playing
int play(int p); 


/* a function to obtain a card from the shuffled deck. For every round, the garbage value in int play(int p) will always reset to zero. Since the cards are always randomized for every round, the cards in ShuffledDeck[]
(ShuffledDeck[1],  ShuffledDeck[2],  ShuffledDeck[3],  ShuffledDeck[4], etc) will always be randomised. So resetting it to zero after every round produces the same randomised result */
int hit(int *i){
      int a = ShuffledDeck[*i]; // interger is declared, and this interget represents one of the values inside the randomised array
      *i = *i + 1; // for every time this function is called, the next interger will be the next element from the randomised array
      // the reason for pointer is to add 1 to the garbage value each time the int hit(int *i) fucntion is used
      // I'm not sure why we must use a pointer in this case as if i were to use the garbage value itself without the pointer, it wouln't worked. Need to ask Dr regarding this issue after presentation
      return a; // this will give out the value of the selected element from the randomised array
    }


// function to create a freshly new array of numbers ranging from 0-52, which represents the deck of cards
void initdeck(){
        int i=0;
        for(i;i<52;i++){
            Deck[i] = i+1;  
        }
    }


// shuffles the array of numbers in random orders    
void shuffledeck(){
        srand(time(NULL)); //srand represents the number inside the rand() algorithm, and time(NULL) gets the time that has passes from January 1st 1970 to the current time in seconds
        /* the reason why we want the seed to always be random as oppose of always relying on rand() alone (which is the same as rand(1)) is that rand() is essentially just a complex algorithm that always uses 
        the value of 1 as its seed. Each time rand() is run the next number will alweays be different from the previous number. But if u run this code again, it will always produce the same numbers in the same sequnce
        no matter how many times you run this code. With seed(time(NULL)), the seed of rand() will always be different depending on the time passes, therefore the rand() value will always be diffrent (no matter the sequence)
        every time the code is run over and over again. One limitation however is that if the code is run again after an initial run in a span of less than 1s, its seed value will be the same since time(NULL) calculates the
        time that has passes in seconds only, not microseconds or anything smaller */ 
        
        int i=0;
        for(i;i<52;i++){
            ShuffledDeck[i] = Deck[i];
        }
        i=0; // reset value of i for reuse

        // this function will be better explained in the report, but if you want more detail, here's the link for the video: https://www.youtube.com/watch?v=4zx5bM2OcvA
        for(i=52-1;i>0;i--){
            int j = rand()%(i+1); 
            int n = ShuffledDeck[i];
            ShuffledDeck[i] = ShuffledDeck[j];
            ShuffledDeck[j] = n;
        }
    }


// to assign the value of the cards
int cval(int b){

        int a; // a is redeclared because I want to reuse some variables for no particular reasons

        if(((b%13)+1)<10)
            a = b%13+1;
            /* for all the values, when divided by 13, has a remainder of less than 10 when the remainder is added by 1 (this is so that 0 will be count as 1 as default,
            but user can choose wether they want to make this as a value of 1 or 11 during their turn since this value represents Ace), the remainders will hold its original values to their total points
            (eg. 3 will add 3 points to the player's total, 7 will add 7 points, etc). Essentially, remainders of 1-9 will hold their original values to be added to the player's total */

        else 
            a = 10;
            /* same concept as previous line, but now it's instead for remainders of 10-13 (rememeber that its 13 because 1 was added through the algorithm), these values will always be a value of 10 which is to be added to the player's total.
            This represents the cards of 10, J, Q, K (eg. 12, which represents Q, will still add 10 points to the player's total despite being the number 12) */

        return a; // this will return the "true" card value, which is to be added to the player's total
        
        /* examples of how this works:
        if the interger value obtained from the shuffled array is 46, then once it goes through this algorithm, it will see if its remainder, when divided by 13, followed by an addition of 1, is less than 10. In this case, (46%13)+1 = 8, so 46 will represent the value of 8, and will be added to the player's total.
        Another example is if the value is 24, then after it passes through the algorithm, it will produce (24%13)+1 = 12, which is more than or equal to 10, therefore this value represents Q which has a value of 10 points which will be added to the player's total */
    }


// to assign the suit of the card
char *csuit(int b){
        /* pointer is used again because it has the same problem as int hit(int *i), it just wouldn't work without pointers. But essentially, what it means is this pointer will, after getting a value from the ShuffledDeck[], will point to this
        fucntion which will then select what the name of the card be through a switch-case-return function. This covers the type of the card, also known as the suite */

        b = b%4; // it's remainder, which will be either 0, 1, 2, or 3, will be used to determine if it is a Hearts, Clubs, Diamonds, or Spades respectively. This is to ensure that there's no duplications of suites. More of this will be explained in the report  

        switch(b){ // this will point to the charecters in this switch-case-return function, and will produce one of the outcomes, which is one of the suits, and it assigns this to the the card value
            case 0 :
                return "Hearts"; // returns the corresponding suite
            case 1 :
                return "Clubs";
            case 2 :
                return "Diamonds";
            case 3 :
                return "Spades";
        }
    }


// to assign the number-name of the card    
char *cface(int b){

        /* pointer is used again because it has the same problem as int hit(int *i). Essentially, what it means is this pointer will, after getting a value from the ShuffledDeck[], will point to this
        function which will then select what the name of the card be through a switch-case-break function. This covers the number-name of the card, also known as the face of the card */

        b = b%13+1; // same concept explained in cval(int b), but this time, remainder that passes through the algorithm of values of 10-13 is considered and assigned 
        char *outcome; // outcome is the pointer that will point to the charecters in this switch-case-break function, and will produce one of the outcomes, which is one of the card number-name call faces, and it assigns this to the the card value
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
        return outcome; // returns the corresponding face
    }


// checks if there's a blackjack and double aces for each player before they "hit"
void checkAce(int v1, int v2, int *a1){

        //int v1 is the value of the first card, int v2 is the value of the second card, int *a1 is the pointer that points and changes the player's total since the player's total constantly changes
        if(v1 == 1 || v2 == 1){
            if(v1 == 1 && v2 == 1){

                // if the player has 2 aces on their first 2 cards, I personally set them to be worth 1 and 11, so the player starts off with 12 as their total points
                v1 = 11;
                v2 = 1;
                *a1 = 12;
                printf("Since you got 2 Aces, we set one to be worth 11 and the other to be worth 1.\n");
            }
            
            else if(v1 == 1 || v2 == 1){

                // if the player has only 1 ace

                if(v1+v2+10 == 21)
                    /* if the player has an ace and a card that has a value of 10, then another 10 will be added to make the total points of the player to be 21 at the start of their turn.
                    This means that the player has achived a "blackjack" and will then set off the blackjack algorithm that will be used and explained later on in the code */
                    *a1 == 21;
                    
                else{

                    // if the player doesn't have 2 aces or a blackjack at the begining of their turn on every round, but only 1 ace is obtained, the user can decide wether to make the ace to be a value of 1 or 11
                    printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
                    scanf("%d",&input);
                    if(input == 11)
                        *a1 += 10;
                }
            }
        }
    }


// the introduction to the game
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
        printf("\nEnter the number of players that are playing! (2-3 players only please!)\n");
        scanf("%d", &p);

        if(p<4 && p>1)
        /*to ensure it's between 2-3 players. Can't add the remaining 3 players at the moment due lack of time. The main time consuming part is the ranking of the players,
        and since I can't find a more efficient way, the only way to rank the players (with my current knowledge as I can't find any sources online regarding this matter) is to manually set conditions of every possible outcomes
        (If 4 players, then 3 players will be ranked as the dealer is easy to do so, so 3! = 6. If 5 players, then 4! = 24. If 6 players. then 5! = 120, THAT'S A LOT OF PLAYERS AHHHHHHH ;-;) */
            play(p);

        else{
        /* This code will be added multiple times so that the code won't break when the input is wrong from the user.
        If the input is wrong, all players must restart the code in order to play again */

            printf("Wrong input, please restart the code!");
            exit(0);
        }
    }

    else{

        printf("Wrong input, please restart the code!\n");
        exit(0);
    }
}


/* the maine while() loop that will loop the blackjack game over and over until either all players or the dealer has no balance left.
This fucntion also sets up the proper codes according to the amount of players that are playing */ 
int play(int p){
    
    balancedealer = (p-1) * 50; // sets dealer amount based on number of players that are playing
    printf("\nAll players starts with $50! And the dealer starts with $%d!\n", balancedealer);
    if(p == 2){

        while(balance1 > 0 && balancedealer > 0){

            // main loop fucntion of the entire blackjack game. This loop will go on until either all players or the dealer has no balance left
           
            initdeck(); // after each round, new ddeck of cards are created and shuffled so the cards will always be randomized every round
            shuffledeck();
            garbage=0; // represents the garbage value mentioned, which helps determining the "hit" function to distribute cards to the players
            playturn1(); // fucntion for player's 1 turn
            playturndealer(); // fucntion for player's 2 turn
        }

        if(balance1<=0){

            // once all the players has no more balance, dealer wins, and the game concludes with the ranking
            
            printf("GAME OVER! DEALER WON!!!\n");
            printf("1st Place: Dealer\n2ndP Place: Player 1\n");
            exit(0);
        }
        if(balancedealer<=0){

            //same concept as the previous line, but in this case, is when the dealer has no more balance left, and all the players win
            printf("GAME OVER! PLAYERS WON!!!\n");
            printf("1st Place: Player 1\n2ndP Place: Dealer\n");
            exit(0);
        }
    }

    else if(p == 3){

        while((balance1>0 || balance2>0) && balancedealer>0){
            
            // same concept as previous loop but now with 2 players and the dealer

            initdeck();
            shuffledeck();
            garbage=0;

            if(balance1>0)
                playturn1();
            if(balance2>0)
                playturn2();
            playturndealer();
        }

        if(balancedealer<=0){
            printf("PLAYERS WIN! NICE JOB!!!\n");
            if(balance1>=balance2){

                /* same concept as before for concluding, but how it works now is that the player who has the most money gets 1st place, while the one that has less will get 2nd place.
                But if let's say there is a situation where a player lost all their balance first, then the dealer. In this case, the balance of that player will be set to BalanceNumber (which is -10 as previously mentioned),
                then BalanceNumber-- so that the next player that that lost all their balacnce (but the remanining players hasn't lost all their balances yet) will always have a balance that's less than the previous person in order to assign their rank for conclusion.
                Why did I make this complicated algorithm for only 3 players instead of simply using normal condition "if" fucntions? Because it's design to help tremendously with the ranking of more players playing such as 5 or 6 players.
                But again, this algorithm is already thought of very early on, but there's simply not enough time when it come's to intergrating the code later on when making this project*/

                printf("1st Place: Player 1\n2nd Place: Player 2\n3rd Place: Dealer\n");
                exit(0);
            }
            else if(balance1<=balance2){
                printf("1st Place: Player 2\n2nd Place: Player 1\n3rd Place: Dealer\n");
                exit(0);
            }
        }

        else if(balance1<=0 && balance2<=0){

            /* same concept as before when the dealer wins, but since there's multiple players playing, I've desinged an algorithm that tracks the position of the players depending on who busts first.
            Once a player lost all their balance, their position is set to PositionNumber (which is 10 as previously mentioned), then PositionNumber-- so that the next player who lost all their balance will have a lower position number,
            representing that the first player will always be at a higher rank (which means near last place), while the second player will always be at a lower rank (near first place)

            Example: Let's say Player 1 losses first, so its position1=PositionNumber=10, then PositionNumber--. Then wehen player 2 losses next, position2=PositionNumber=9, then PositionNumber--.
            And since Player 2's position number has a lower value that Player 1's, therefore Player 2 will be ranked 2nd, and Player 1 will be ranked 3rd.
            
            Why is the algorithm this complicated? Again, it's the same reason as previously mentioned, I simply don't have enough time to add the other 3 players into the entire code */

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


// function for Player 1's turn to play
void playturn1(){

        blackjack1 = 0; // set blackjack value to 0 every turn (reason is mentioned previously)
        bust1 = 0; // set bust value to 0 every turn (reason is mentioned previously)
        printf("\nAlright, it's Player's 1 turn!\n");
        printf("Your current balance is $%d.\n", balance1);
        printf("The Dealer's balance is $%d.\n", balancedealer);

        int a1 = hit(&garbage); // hit function for Player 1. This was explained previously, note that garbage will be increase by 1 every time the hit(&garbage) function is used, and will reset to zero at the next round
        char *acs1 = csuit(a1); // all of these funcitons are explained previously
        char *acf1 = cface(a1);
        int acv1 = cval(a1); // function that calculates the value of the card, which is explained previously
            
        printf("You got a %s of %s worth %d, and ", acf1, acs1, acv1);
            
        int a2 = hit(&garbage);
        char *acs2 = csuit(a2);
        char *acf2 = cface(a2);
        int acv2 = cval(a2);
        
        printf("a %s of %s worth %d.\n", acf2, acs2, acv2);
        
        int d1 = hit(&garbage); // this represents one of the dealer's card since one of the dealer's card is faced up
        char *dcs1 = csuit(d1);
        char *dcf1 = cface(d1);
        dcv1 = cval(d1);
        
        printf("The dealer's face up card is a %s of %s worth %d.\n", dcf1, dcs1, dcv1);
        
        player1total = acv1 + acv2; // represents the total points Player 1 has from the card values
        dealertotal = dcv1; // same concept as previous line but for the dealer instead
        
        checkAce(acv1, acv2, &player1total); // fucntion explained previously
        
        printf("You have a total of %d points, and the dealer has %d.\n(type 1 to draw a card, or type 2 to end your turn!)\n", player1total, dealertotal);  
        
        if(player1total == 21){
            
            // condition where Player 1 gets a blackjack

            printf("Congrats! You got a blackjack! Dealer losses $5, and you gained $5!");
            balance1 += 5; // Player 1's gains $5
            balancedealer -=5; // Dealer losses $5
            blackjack1 = 1; // purpose of this is explained previously
        }
            
        else{

            scanf("%d", &input); // if user input is 1, user will draw a card, if user input is 2, user will stand

            while(input != 2){
                
                if(input = 1){

                    int a3 = hit(&garbage);
                    char *acs3 = csuit(a3);
                    char *acf3 = cface(a3);
                    int acv2 = cval(a3);
                    player1total += acv2; // adds another card value to the total points of the player
                    printf("You got a %s of %s worth %d.\n", acf3, acs3, acv2);

                    if(player1total <= 21){
                            
                        if(acv2==1){
                            
                            // if user draws an ace, then they can choose its value to be either 1 or 11

                            printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
                            scanf("%d",&input);
                            if(input == 11)
                            player1total += 10;
                        
                            if(player1total >21){

                                // if Player 1 busts

                                printf("Oh no, you've busted with %d. You lost $5 while the Dealer gains $5!\n", player1total);
                                balance1 -= 5; // Player 1 losses $5
                                balancedealer +=5; // Dealer gains $5
                                bust1 = 1; // purpose of this is already explained previously

                                if(balance1<=0){

                                    // if Player 1 losses early, then it will go through the position algorithm that's mentioned previously
                                    printf("Aww, Player 1 lost...");
                                    balance1=BalanceNumber;
                                    BalanceNumber--;
                                    position1 = PositionNumber;
                                    PositionNumber--;
                                    blackjack1 = 1;
                                    bust1 = 1;
                                }

                                break; // to stop the loop if Player 1 is unable to play anymore for the remainder of the round/entire game
                            }   
                        }                    
                    }

                    else if(player1total >21){
                    
                    // if Player 1 busts with over 21 points
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
                    scanf("%d", &input); // if Player 1 still hasn't bust, then Player 1 is still able to hit in a while loop until either Player 1 busts or when the user has inputed 2, which will then stop this while loop
                }
            }
        }
    }


// function for Player 2's turn to play
void playturn2(){

        // this entire code is essentially the same as void playturn1(), but it's built for Player 2 

        blackjack2 = 0;
        bust2 = 0;
        printf("\n\nAlright, it's Player's 2 turn!\n");
        printf("Your current balance is $%d.\n", balance2);
        printf("The Dealer's balance is $%d.\n", balancedealer);

        int b1 = hit(&garbage);
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


// function for dealer's turn to play
void playturndealer(){

     // this entire code is essentially similar as void playturn1(), but it's built for the dealer with some modifications

    bustdealer = 0;// to let the algorithm know later on that dealer hasn't bust in order to compare the cards with other player's that haven't bust during the entire round
    
    
    if(bust1 == 1 && bust2 == 1 && bust3 == 1 && bust4 == 1 && bust5 == 1)
    // if all players bust before the dealer's turn, then the dealer automatically wins the round
        printf("\nWell, everyone busted before the dealer... Anyways, let's move on to the next game!\n");

    else if(dealertotal == 21){

        // if the dealer has a blackjack

        printf("\nCongrats! You got a blackjack! All Players who doesn't have a blackjack losses! Sadge...\n");
        if(blackjack1 == 0){
            balance1 -= 5;
            balancedealer +=5;

            if(balance1<=0){
                printf("\nAww, Player 1 lost...\n");
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
                printf("\nAww, Player 2 lost...\n");
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
                printf("\nAww, Player 3 lost...\n");
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
                printf("\nAww, Player 4 lost...\n");
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
                printf("\nAww, Player 5 lost...\n");
                balance5 = BalanceNumber;
                BalanceNumber--;
                position5 = PositionNumber;
                PositionNumber--;
                blackjack5 = 1;
                bust5 = 1;
            }
        }
        
        if(blackjack1 == 1 && blackjack2 == 1 && blackjack3 == 1 && blackjack4 == 1 && blackjack5 == 1)
        // if all the players has a blackjack before the dealer's turn, even though the dealer has a blackjack, I've set it so that all the players will win the round except for the dealer
            printf("\nWell, everyone got a blackjack before the dealer, big yikes for the dealer...\nAnyways, let's move on to the next game!\n");
    }
    
    else{

        // if neither of the condition above is true, then the dealer will start to hit or stand

        printf("\nAlright, it's the Dealer's turn!\n(Remember, you need to get a total of atleast 17 points as that's the rules.\nIf you don't, rule is broken, and you have to restart the entire game as a punishment!!!)\n");
        printf("Your current balance is $%d.\n",  balancedealer);

        if(dcv1==1){

            printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
            scanf("%d",&input);
            if(input == 11)
                dealertotal += 10;
        }

        // 2nd card of the dealer since the 1st one is already drawn during Player 1's turn
        int d2 = hit(&garbage);
        char *dcs2 = csuit(d2);
        char *dcf2 = cface(d2);
        int dcv2 = cval(d2);
        
        dealertotal = dcv1 + dcv2; // dealer's current total card points
        
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
                            
                            // condition if dealer busts

                            printf("Oh no, you've busted with %d. All players that didn't bust gains $5 while the Dealer loses $5 each!\n", dealertotal);
                            bustdealer = 1;
                            if(bust1 == 0){

                                // for the players that didn't bust before the dealer, they will each gain $5 while the dealer losses $5 each

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
                    
                    // same bust concept in this case but for an another "else if" statement

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

    if(bust1 == 0 && blackjack1 == 0 && bustdealer == 0){
        
        if(dealertotal < 16){
        /* if the dealer doesn't follow the rules of getting at least 17 of total card points, then the code will be terminated as punishment.
        The reason why I don't set it to automatically draw another card to the dealer's total when the dealer stands with total points that's less than 17 is because I want them to learn the proper way of playing blackjack */
        printf("DEALER HAS LESS THAN 17 POINTS. RULE IS BROKEN, GAME OVER!\nPLEASE RESTART THE CODE TO PLAY AGAIN!!!\n");
        exit(0);

        }
        if(player1total > dealertotal){

            // compares dealer's total with Player 1's, if Player 1 has more, than Player 1 will gain $5 while the dealer loses $5
            printf("Player 1 wins over dealer! Player 1 gains $5 while dealer losses $5!\n");
            balance1 += 5;
            balancedealer -=5;
        }
        else if(player1total < dealertotal){

            // same concept as before but thime, if Dealer has more points, than Player 1 will lose $5 while the dealer gains $5
            printf("Dealer wins over Player 1! Dealer gains $5 while Player 1 losses $5!\n");
            balance1 -= 5;
            balancedealer += 5;

            if(balance1<=0){
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
        // if both  player 1's and dealer's points are the same, then neither will gain or lose $5 for the current round
            printf("Dealer and Player 1 has the same points, neither wins in this case. PUSH POT!!!\n");
    }

    if(bust2 == 0 && blackjack2 == 0 && bustdealer == 0){

        // same as before but for Player 2

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

        // same as before but for Player 3
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

   // so after void playerdealerturn() is done, the program will loop back to the while loop mentioned previously in int playturn(int p) until the conditions for the while loop is not true anymore, which it will then conclude the game 
}

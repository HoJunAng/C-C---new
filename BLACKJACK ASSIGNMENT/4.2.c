void playturn1(){
    int blackjack1 = 0;
    int bust1 = 0;
    printf("Alright, it's Player's 1 turn!\n");
    printf("Your current balance is $%d.\n", balance1);

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
    
    int player1total = acv1 + acv2;
    int dealertotal = dcv1;
    
    checkAce(acv1, acv2, &player1total);
    
    printf("You have a total of %d points, and the dealer has %d.\n(type 1 to draw a card, or type 2 to end your turn!)\n", player1total, dealertotal);  
    
    if(player1total == 21){

        printf("Congrats! You got a blackjack! Dealer losses $5...");
        balance1 += 5;
        balancedealer -=5;
        blackjack1 = 1;
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
                        
                printf("Oh no, you've busted with %d. Dealer gains $5!\n", player1total);
                balance1 -= 5;
                balancedealer +=5;
                bust = 1;
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

    
void playturndealer(){

    printf("Alright, it's the Dealer's turn!\n(Remember, you need to get a total of atleast 17 points as that's the rules.\nIf you don't, rule is broken, and you have to restart the entire game as a punishmen!!!!)");
    printf("Your current balance is $%d.\n", balancedealer);
    
    int d2 = hit(&garbage);
    char *dcs2 = csuit(d2);
    char *dcf2 = cface(d2);
    int dcv2 = cval(d2);
    
    int dealertotal = dcv1 + dcv2;
    
    checkAce(dcv1, dcv2, &dealertotal);
    
    printf("You have a total of %d points\n(type 1 to draw a card, or type 2 to end your turn!)\n", dealertotal);  
    
    if(dealertotal == 21){

        printf("Congrats! You got a blackjack! All Players who doesn't have a blackjack losses! Sadge...");
        if(bj1 == 0){
            balance1 -= 5;
            balancedealer +=5;
        }
    }
        
    else{

        int input;
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

                        int input;
                        printf("You've got an ace. Choose whether you want to make it count as 1 or 11.\n");
                        scanf("%d",&input);
                        if(input == 11)
                            player1total += 10;
                    }                    
                }

                else if(dealertotal >21){
                        
                    printf("Oh no, you've busted with %d. All players that doesn't bust wins!\n", dealertotal);

                    if(bust1 == 0){
                        balance1 +=5;
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

    if(dealertotal < 16){
        printf("DEALER HAS LESS THAN 17 POINTS. RULE IS BROKEN, GAME OVER!\nPLEASE RESTART THE CODE TO PLAY AGAIN!!!\n");
        exit(0);
    }

    /* initialise bust and blackjack values for all players early on
       and set it to a garbage value so that you only need 1 void dealerturn() function */
    if(bust1 == 0 && blackjack == 0){
        if(player1total > dealertotal){
            printf("Player 1 wins over dealer! Player 1 gains $5 while dealer losses $5!\n");
            balance1 += 5;
            balancedealer -=5;
        }
        else if(player1total < dealertotal){
            printf("Dealer wins over Player 1! Dealer gains $5 while Player 1 losses $5!\n");
            balance1 -= 5;
            balancedealer +- 5;
        else if(player1total == dealertotal)
            printf("Dealer and Player 1 has the same points, neither wins in this case. PUSH POT!!!\n");
        }
    }
}
  
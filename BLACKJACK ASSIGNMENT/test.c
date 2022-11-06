#include<stdio.h>
#define getName(var) #var
#include<string.h>



int main(){
    int Player1 = 200;
    int Player2 = 50;
    printf("PLAYERS WIN! NICE JOB!!!\n");
    int d[2]={Player1, Player2};
    for(int i=0; i<2; i++){
        for(int j=i+1; j<2; j++){
            if(d[j]>d[i]){
                int temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
    printf("1st Place: %s\n2nd Place: %s\n3rd Place: Dealer\n", getName(d[0]), getName(d[1]));
}

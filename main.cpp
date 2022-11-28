#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip> 
using namespace std;


int playerHand [4];
int dealerHand [4];
int dealerValue = 0;
int playerValue = 0;
int playerChoice = 0;

int card[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; //Ace's value is eleven; jack, queen, ang king's value is 10.
string cardRanks[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
string playingCards[2][14] = {
{ " |A      | "  ,  " |2      | " ," |3      | " ," |4      | " ," |5      | " ," |6      | " ," |7      | " ," |8      | " ," |9      | " ," |10     | " ," |J      | "  ," |Q      | " ," |K      | " },
{ " |______A| "  ,  " |______2| " ," |______3| " ," |______4| " ," |______5| " ," |______6| " ," |______7| " ," |______8| " ," |______9| " ," |_____10| " ," |______J| "  ," |______Q| " ," |______K| " }

};


    

        

void dealCard(){
    srand(time(NULL));
    for (int  i = 0; i < 2; i++){
        int num = (rand() % 13 - 1);
        playerHand[i] = card[num];
    }
    for (int x = 0; x < 2; x++){
        int num2 = (rand() % 13 - 1);
        dealerHand[x] = card[num2];
    }
}


void printCards(){

    cout << setw(60)<<  "_______ " << "      " << " _______ " << endl;
    cout << setw(61)<< playingCards[0][dealerHand[0]]<< "    " << playingCards[0][dealerHand[1]] << endl;
    cout << setw(60)<< "|       |"  << "      " << "|       |" << endl;
    cout << setw(60)<< "|       |"  << "      " << "|       |" << endl;
    cout << setw(60)<< "|       |"  << "      " << "|       |" << endl;
    cout << setw(61)<< playingCards[1][dealerHand[0]]       << "    " << playingCards[1][dealerHand[1]] << endl;


    cout << setw(60)<<  "_______ " << "      " << " _______ " << endl;
    cout << setw(61)<< playingCards[0][playerHand[0]]<< "    " << playingCards[0][playerHand[1]] << endl;
    cout << setw(60)<< "|       |"  << "      " << "|       |" << endl;
    cout << setw(60)<< "|       |"  << "      " << "|       |" << endl;
    cout << setw(60)<< "|       |"  << "      " << "|       |" << endl;
    cout << setw(61)<< playingCards[1][playerHand[0]]       << "    " << playingCards[1][playerHand[1]] << endl;




    cout << "SYSTEM: "<<"The dealer got " << cardRanks[dealerHand[0]] << " and "  << cardRanks[dealerHand[1]] << endl;
    cout << "SYSTEM: " <<"You got " << cardRanks[playerHand[0]] << " and " << cardRanks[playerHand[1]] << endl;
    

}

void sumValue(){
    for (int x = 0; x < 3; x++){
        
    }
    
}

int main(){
    dealCard();
    printCards();

    if (dealerValue == 21){
        cout << "The dealer has a blackjack. You lost!";
        if (playerValue == 21){
            cout << "You have a blackjack! You won!";
        }
    }
    





}


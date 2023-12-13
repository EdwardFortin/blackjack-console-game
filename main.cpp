#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip> 
#include <windows.h>

using namespace std;

int playerHand [5] = {0};
int dealerHand [5] = {0};
int dealerValue [5] = {0};
int playerValue [5] = {0};
int dealerSum;
int playerSum;
int playerChoice = 0;
int take;
int counter;
int roundEnd;

int card[14] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; //number of cards to be generated randomly
string cardRanks[14] = {"Zero","Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
string playingCards[2][14] = {
{ " |       | " , " |A      | " , " |2      | " , " |3      | " ," |4      | " ," |5      | " ," |6      | " ," |7      | " ," |8      | " ," |9      | " ," |10     | " ," |J      | "  ," |Q      | " ," |K      | " },
{ " |_______| " , " |______A| " , " |______2| " , " |______3| " ," |______4| " ," |______5| " ," |______6| " ," |______7| " ," |______8| " ," |______9| " ," |_____10| " ," |______J| "  ," |______Q| " ," |______K| " }

};


void initializion(){
for (int i = 1; i <= 5; i++) {
    playerHand [i] = 0;
    dealerHand [i] = 0;
    dealerValue [i] = 0;
    playerValue [i] = 0;
}
dealerSum = 0;
playerSum = 0;
playerChoice = 0;
take = 0;
counter = 2;
roundEnd = 0;
}


void homepage(){
        
        system("CLS");
        system("color 0a");
        cout << setw(85) << "=====================================================================" <<endl;
        cout << setw(85)<< "   *    ##### #       #   ##### #   #     #   #   ##### #   #    *   " <<endl;
        cout << setw(85)<< "  * *   #   # #      # #  #     #  #      #  # #  #     #  #    * *  " <<endl;
        cout << setw(85)<< " *   *  ##### #     ##### #     ###       # ##### #     ###    *   * " <<endl;
        cout << setw(85)<< "  * *   #   # #     #   # #     #  #  #   # #   # #     #  #    * *  " <<endl;
        cout << setw(85)<< "   *    ##### ##### #   # ##### #   # ##### #   # ##### #   #    *   " <<endl;
        cout << setw(85)<< "=====================================================================" <<endl;
        cout <<endl;
        cout << setw(80)<< "                            ------------                             " <<endl;	
        cout << setw(80)<< "                               1.Play                                " <<endl;
        cout << setw(80)<< "                            ------------                             " <<endl;
        cout << setw(80)<< "                            ------------                             " <<endl;
        cout << setw(80)<< "                               2.Help                                " <<endl;
        cout << setw(80)<< "                            ------------                             " <<endl;
        cout << setw(80)<< "                            ------------                             " <<endl;
        cout << setw(80)<< "                              3.About                                " <<endl;
        cout << setw(80)<< "                            ------------                             " <<endl;
        cout << setw(80)<< "                            ------------                             " <<endl;	
        cout << setw(80)<< "                               4.Quit                                " <<endl;
        cout << setw(80)<< "                            ------------                             " <<endl;
        
        
        
        

}


void banner(){ 
        system("cls");

        cout << setw(85) << "=====================================================================" <<endl;
        cout << setw(85)<< "   *    ##### #       #   ##### #   #     #   #   ##### #   #    *   " <<endl;
        cout << setw(85)<< "  * *   #   # #      # #  #     #  #      #  # #  #     #  #    * *  " <<endl;
        cout << setw(85)<< " *   *  ##### #     ##### #     ###       # ##### #     ###    *   * " <<endl;
        cout << setw(85)<< "  * *   #   # #     #   # #     #  #  #   # #   # #     #  #    * *  " <<endl;
        cout << setw(85)<< "   *    ##### ##### #   # ##### #   # ##### #   # ##### #   #    *   " <<endl;
        cout << setw(85)<< "=====================================================================" <<endl;
        cout << flush;
}

void deal_playerCard(){ 
    srand(time(NULL));
    for (int  i = 0; i < 2; i++){ //deals player two cards
        int num = (rand() % 13 + 1) ;
        playerHand[i] = card[num];
    }
}

void deal_dealerCard(){
    for (int x = 0; x < 2 ; x++){ //deals dealer two cards
    int num2 = (rand() % 13 + 1);
    dealerHand[x] = card[num2];
    }
}

void deal_playerHitcard(){
    
        playerHand[counter] = (rand() % 13 + 1);

    
}

void print_newLine(){

    for (int i = 0; i < 5; i++){
        cout << endl;
    }
}

void convert_faceCard(){
for (int i = 0; i < 5; i++){
        playerValue[i] = playerHand[i];
        dealerValue[i] = dealerHand[i];
    
        if(playerValue[i] >= 10){
            playerValue [i] = 10;
        }
        if (dealerValue[i] >= 10){
            dealerValue[i] = 10;
        }
    }
}

void process_Ace(){

    for (int i = 0; i < 5; i++){
        if (playerValue[i] == 1){
            playerValue [i] = 11;
        }
        else if (dealerValue[i] == 1){
            dealerValue[i] = 11;
        }
        else if (playerValue[0] == 11 && playerValue[1] == 11){
            playerValue [1] = 1;
        }
        else if (dealerValue[0] == 11 && dealerValue[1] == 11){
            dealerValue [1] = 1;
        }

        if (playerValue[i] == 11 && playerSum > 21){
            playerSum -= 10;
        }else if (dealerValue[i] == 11 && dealerSum > 21){
            dealerSum -= 10;
        }
        
    }       
}    

void print_Playercards(){

    if(playerHand[2] == 0){
        cout << endl;
        cout << endl;
        cout << setw(36)<< "PLAYER: " << playerSum << endl;
        cout << setw(45)<<  "_______ " << "      " << " _______ " << endl;
        cout << setw(46)<< playingCards[0][playerHand[0]]<< "    " << playingCards[0][playerHand[1]] << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << endl;
        cout << setw(46)<< playingCards[1][playerHand[0]]       << "    " << playingCards[1][playerHand[1]] << endl;
    }else if(playerHand[3] == 0){
        cout << endl;
        cout << endl;
        cout << setw(36)<< "PLAYER: " << playerSum << endl;
        cout << setw(45)<<  "_______ " << "      " << " _______ " << "      " << " _______ " << endl;
        cout << setw(46)<< playingCards[0][playerHand[0]]<< "    " << playingCards[0][playerHand[1]] << "    " << playingCards[0][playerHand[2]] << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(46)<< playingCards[1][playerHand[0]]       << "    " << playingCards[1][playerHand[1]] << "    " << playingCards[1][playerHand[2]] << endl;
    }else if(playerHand[4] == 0){
        cout << endl;
        cout << endl;
        cout << setw(36)<< "PLAYER: " << playerSum << endl;
        cout << setw(45)<<  "_______ " << "      " << " _______ " << "      " << " _______ " << "      " << " _______ "  << endl;
        cout << setw(46)<< playingCards[0][playerHand[0]]<< "    " << playingCards[0][playerHand[1]] << "    " << playingCards[0][playerHand[2]] << "    " << playingCards[0][playerHand[3]] << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(46)<< playingCards[1][playerHand[0]]       << "    " << playingCards[1][playerHand[1]] << "    " << playingCards[1][playerHand[2]] << "    " << playingCards[1][playerHand[3]] << endl;
    }else if(playerHand[4] != 0){
        cout << endl;
        cout << endl;
        cout << setw(36)<< "PLAYER: " << playerSum << endl;
        cout << setw(45)<<  "_______ " << "      " << " _______ " << "      " << " _______ " << "      " << " _______ " << "      " << " _______ " << endl;
        cout << setw(46)<< playingCards[0][playerHand[0]]<< "    " << playingCards[0][playerHand[1]] << "    " << playingCards[0][playerHand[2]] << "    " << playingCards[0][playerHand[3]] << "    " << playingCards[0][playerHand[4]]<< endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << "      " << "|       |"<< endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << "      " << "|       |"<< endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << "      " << "|       |"<< endl;
        cout << setw(46)<< playingCards[1][playerHand[0]]       << "    " << playingCards[1][playerHand[1]] << "    " << playingCards[1][playerHand[2]] << "    " << playingCards[1][playerHand[3]] << "    " << playingCards[1][playerHand[4]]<< endl;
    }
}

void sum_Value(){

playerSum = 0;
dealerSum = 0;    

playerSum = playerValue[0] + playerValue[1] + playerValue[2] + playerValue[3] + playerValue[4] + playerValue[5];
dealerSum = dealerValue[0] + dealerValue[1] + dealerValue[2] + dealerValue[3] + dealerValue[4] + dealerValue[5];
}

void print_DealerFirstCard(){

    cout << endl;
    cout << setw(36)<< "DEALER: " << dealerValue[0] << endl;
    cout << setw(45)<<  "_______ " << "      " << " _______ " << endl;
    cout << setw(46)<< playingCards[0][dealerHand[0]]<< "     " << "|       |" << endl;
    cout << setw(45)<< "|       |"  << "      " << "|* * * *|" << endl;
    cout << setw(45)<< "|       |"  << "      " << "| * * * |" << endl;
    cout << setw(45)<< "|       |"  << "      " << "|* * * *|" << endl;
    cout << setw(46)<< playingCards[1][dealerHand[0]]       << "    " << " |_______| " << endl;
    cout << endl;
}


void print_dealerBlackjack(){
    system("CLS");
    banner();
    print_newLine();
    if(dealerHand[2] == 0){
    cout << setw(36)<< "DEALER: " << dealerSum << endl;
    cout << setw(45)<<  "_______ " << "      " << " _______ " << endl;
    cout << setw(46)<< playingCards[0][dealerHand[0]]<< "    " << playingCards[0][dealerHand[1]] << endl;
    cout << setw(45)<< "|       |"  << "      " << "|       |" << endl;
    cout << setw(45)<< "|       |"  << "      " << "|       |" << endl;
    cout << setw(45)<< "|       |"  << "      " << "|       |" << endl;
    cout << setw(46)<< playingCards[1][dealerHand[0]]       << "    " << playingCards[1][dealerHand[1]] << endl;
    cout << endl;

    } else if (dealerHand[3] == 0){
        cout << setw(36)<< "DEALER: " << dealerSum << endl;
        cout << setw(45)<<  "_______ " << "      " << " _______ " << "      " << " _______ " << endl;
        cout << setw(46)<< playingCards[0][dealerHand[0]] << "    " << playingCards[0][dealerHand[1]] << "    " << playingCards[0][dealerHand[2]] <<endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(46)<< playingCards[1][dealerHand[0]]       << "    " << playingCards[1][dealerHand[1]] << "    " << playingCards[1][dealerHand[2]] << endl;
        cout << endl;
    }
    else if (dealerHand[4] == 0){
        cout << setw(36)<< "DEALER: " << dealerSum << endl;
        cout << setw(45)<<  "_______ " << "      " << " _______ " << "      " << " _______ "<< "      " << " _______ " << endl;
        cout << setw(46)<< playingCards[0][dealerHand[0]] << "    " << playingCards[0][dealerHand[1]] << "    " << playingCards[0][dealerHand[2]] << "    " << playingCards[0][dealerHand[3]] <<endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(46)<< playingCards[1][dealerHand[0]]       << "    " << playingCards[1][dealerHand[1]] << "    " << playingCards[1][dealerHand[2]] << "    " << playingCards[1][dealerHand[3]] << endl;
        cout << endl;
    } else{
        cout << setw(36)<< "DEALER: " << dealerSum << endl;
        cout << setw(45)<<  "_______ " << "      " << " _______ " << "      " << " _______ " << "      " << " _______ " << "      " << " _______ " << endl;
        cout << setw(46)<< playingCards[0][dealerHand[0]] << "    " << playingCards[0][dealerHand[1]] << "    " << playingCards[0][dealerHand[2]] << "    " << playingCards[0][dealerHand[3]] << "    " << playingCards[0][dealerHand[4]]<<endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << "      " << "|       |"<< endl;
        cout << setw(45)<< "|       |"  << "      " << "|       |" << "      " << "|       |" << "      " << "|       |" << "      " << "|       |"<< endl;
        cout << setw(46)<< playingCards[1][dealerHand[0]]       << "    " << playingCards[1][dealerHand[1]] << "    " << playingCards[1][dealerHand[2]] << "    " << playingCards[1][dealerHand[3]] << "    " << playingCards[1][dealerHand[4]] << endl;
        cout << endl;
    }
    print_Playercards();
}   

void print_dealerRevealedCard(){

    cout << setw(36)<< "DEALER: " << dealerSum << endl;
    cout << setw(45)<<  "_______ " << "      " << " _______ " << endl;
    cout << setw(46)<< playingCards[0][dealerHand[0]]<< "    " << playingCards[0][dealerHand[1]] << endl;
    cout << setw(45)<< "|       |"  << "      " << "|       |" << endl;
    cout << setw(45)<< "|       |"  << "      " << "|       |" << endl;
    cout << setw(45)<< "|       |"  << "      " << "|       |" << endl;
    cout << setw(46)<< playingCards[1][dealerHand[0]]       << "    " << playingCards[1][dealerHand[1]] << endl;


}

void process_winningCondition(){

    if (playerSum == 21){
        cout << "SYSTEM: " << "You have blackjack! You won!" << endl;
        roundEnd++;
    }else if(dealerSum == 21){
        cout << "SYSTEM: " << "The dealer have blackjack. You lost!" << endl;
        roundEnd++;
    }else if(playerSum == 21 && dealerSum == 21){
        cout << "SYSTEM: " << "PUSH! Dealer and Player have same value." << endl;
        roundEnd++;
    }else if (playerSum > 21){
        cout << "SYSTEM: "<< "BUST! You lost!" << endl;
        roundEnd++;
    }else if (dealerSum > 21){
        cout << "SYSTEM: "<< "Dealer BUST! You win!" << endl;
        roundEnd++;
    }else if(playerSum > dealerSum){
        cout << "SYSTEM: " << "You are closest to 21. You win!" << endl;
        roundEnd++;
    } else if(dealerSum > playerSum && dealerSum < 21){
        cout << "SYSTEM: " << "Dealer is closest to 21. You lost." << endl;
        roundEnd++;
    } else if(dealerSum > 21){
        cout << "SYSTEM: " << "Dealer BUST! You win!" << endl;
        roundEnd++;
    } else if(playerSum == dealerSum){
        cout << "SYSTEM: " << "PUSH! Dealer and Player have same value." << endl;
        roundEnd++;
    }

}

void check_ifBust(){

    if (playerSum > 21){
        cout << "SYSTEM: "<< "BUST! You lost!" << endl;
        roundEnd++;
    
    }
}

void check_ifBlackjack(){
    if (playerSum == 21){
        cout << "SYSTEM: " << "You have blackjack! You won!" << endl;
        roundEnd++;
    }


}

void print_sysMessage(){
    cout << endl;
    cout << endl;
    if(playerHand[2] == 0 && dealerHand[2] == 0){
                cout << "SYSTEM: " << "The dealer got " << cardRanks[dealerHand[0]] << endl;

            }else if(dealerHand[2] == 0){
                cout << "SYSTEM: " << "The dealer got " << cardRanks[dealerHand[0]] << " and " << cardRanks[dealerHand[1]]<< endl;

            }else if(dealerHand[3] == 0){
                cout << "SYSTEM: " << "The dealer got " << cardRanks[dealerHand[0]] << ", " << cardRanks[dealerHand[1]] << " and " << cardRanks[dealerHand[2]] << endl;

            }else if(dealerHand[4] == 0){
                cout << "SYSTEM: " << "The dealer got " << cardRanks[dealerHand[0]] << ", " << cardRanks[dealerHand[1]] << ", " << cardRanks[dealerHand[2]] << " and " << cardRanks[dealerHand[3]] << endl;

            }else if(dealerHand[5] == 0){
                cout << "SYSTEM: " << "The dealer got " << cardRanks[dealerHand[0]] << ", " << cardRanks[dealerHand[1]] << ", " << cardRanks[dealerHand[2]] << ", " << cardRanks[dealerHand[3]] << " and " << cardRanks[dealerHand[4]]<< endl;

            }

    if(playerHand[2] == 0){
                cout << "SYSTEM: " << "You got " << cardRanks[playerHand[0]] << " and " << cardRanks[playerHand[1]]<< endl;

            }else if(playerHand[3] ==0){
                cout << "SYSTEM: " << "You got " << cardRanks[playerHand[0]] << ", " << cardRanks[playerHand[1]] << " and " << cardRanks[playerHand[2]] << endl;

            }else if(playerHand[4] == 0){
                cout << "SYSTEM: " << "You got " << cardRanks[playerHand[0]] << ", " << cardRanks[playerHand[1]] << ", " << cardRanks[playerHand[2]] << " and " << cardRanks[playerHand[3]] << endl;

            }else{
                cout << "SYSTEM: " << "You got " << cardRanks[playerHand[0]] << ", " << cardRanks[playerHand[1]] << ", " << cardRanks[playerHand[2]] << ", " << cardRanks[playerHand[3]] << " and " << cardRanks[dealerHand[4]]<< endl;
            
            }
}


void process_dealer(){
    if(dealerSum <= 16){

        dealerHand[2] = card[rand() % 13 + 1]; //deal another card
        convert_faceCard();
        process_Ace();
        dealerSum += dealerValue[2];
        print_dealerBlackjack();

        if(dealerSum<= 16){
            dealerHand[3] = card[rand() % 13 + 1]; //deal another card
            convert_faceCard();
            process_Ace();
            dealerSum += dealerValue[3];
            print_dealerBlackjack();
            //dealer blackjack with 3 cards

        }       else if(dealerSum == 21){
                        print_dealerBlackjack();
                //output dealer blackjack with 4 cards
                }

    } else if (dealerSum >= 17){

        //calculate player and deaeler value and compare
        convert_faceCard();
        process_Ace();
        print_dealerBlackjack();
        }
}


int main(){
    
    start:
    system("CLS");
    system("color 0a");
    homepage();
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
    case 1:
        do{
        
        system("color 0a");
        system("CLS");
        banner();
        print_newLine();


        initializion();
        deal_playerCard();
        deal_dealerCard();
        convert_faceCard();
        process_Ace();
        sum_Value();
        process_Ace();


        //start of algo
        if (dealerSum == 21){

            print_dealerBlackjack();
            print_sysMessage();
            process_winningCondition();
            goto end;
            //add return to bet or start again prompt
        }

        print_DealerFirstCard(); //prints dealer first card.
        print_Playercards(); //prints player first two cards
        print_sysMessage();
        
        if (playerSum == 21){
            cout << "SYSTEM: " << "You have blackjack! You won!" << endl;
            goto end;
        } 
        
        playerChoice = 0;
        cout << "SYSTEM: " <<"Press 1 if you would like to HIT or Press 2 if you would like to STAND: "; //asks player if they want to HIT or STAND
        cin >> playerChoice;
        if(playerChoice == 1){

            do{ //do while loop for player's choice to HIT (add another card)

                system("CLS");
                banner();
                print_newLine();
                deal_playerHitcard();
                convert_faceCard();
                sum_Value();
                process_Ace();
                sum_Value();
                process_Ace();

                print_DealerFirstCard();
                print_Playercards();
                print_sysMessage();
                check_ifBlackjack();
                check_ifBust();
                
            
                
                if (roundEnd == 1){
                    system("CLS");
                    banner();
                    print_newLine();
                    print_dealerRevealedCard();
                    print_Playercards();
                    print_sysMessage();
                    process_winningCondition();

                goto end;
                }
                
                

            playerChoice = 0;
            counter ++;
            cout << "SYSTEM: " <<"Press 1 if you would like to HIT or Press 2 if you would like to STAND: "; //asks player if they want to HIT or STAND
            cin >> playerChoice;
            }while (playerChoice == 1);
            goto dealerTurn; //if player's wants to STAND (dont add new card) it is now for the dealer's turn.

        }else {  //after player's turn, it is time for the dealer to hit or stand.
                dealerTurn: //laber for the go to function
                process_dealer();
                print_sysMessage();
                process_winningCondition();
            }
            
            end:
            cout << "SYSTEM: " << "Press 1 to restart or press 2 to quit: ";
            cin >> take;
        } while (take == 1);
        goto start;
        break;
    case 2:
        system("color 0a");
        system("cls");
        banner();
        cout << endl;

        cout << setw(45) << R"(
        
                                This is How you play Blackjack:

        Step 1: Place your bet
        - In this step you will put down your bet and remember to bet what your can afford to lose

        Step 2: Get you cards
        -Once you placed your bet, The dealer will give you two cards and the dealer will show one of his/her cards.
        All cards are at face value, except for the King, Queen and Jack which count as 10. 
        Ace will have a value of 11 unless the total value of Player's card are greater than 21 
        the ace value will turn into 1.

        Step 3: Decide when to 'hit'
        -In this case you can press 'hit' to get more cards to get increase value of your hand. 
        Always remember that if you cross 21 you will lose automatically.

        Step 4: 'stand'
        - If you're ready to take the risk press the 'Stand' buttons

        Step 5: 'Win' or 'Lose'
        - In this case we will analyze the cards and the player's who are close to 21 will win
        - If your cards are equal to 21 that's what we called "Blackjack" and the dealer 
        will pays the player one and a half times the amount of their bet.)" << endl;
        
        cout << endl;
        cout << "SYSTEM: " <<"Go back? Y / N: ";
        char menu_choice;
        cin >> menu_choice;
        if (menu_choice == 'Y' || menu_choice == 'y'){
            goto start;
        }
        
        break;

    case 3:
        system("color 0a");
        system("cls");
        banner();
        print_newLine();

        cout << R"( 
                                                ABOUT 



        Blackjack is a gambling game. It is the most popular casino banking game in the world, 
        and it is descended from a global family of casino banking games known as Twenty-One. 

        Blackjack players do not compete with one another. 
        The game is a card-matching game in which each player competes against the dealer. 

        This program was created by a group of Information Technology students 
        who remade the card game as a virtual game
        that is not for gambling or other illegal activities but rather for a school requirement.
        )";

        cout << endl;
        cout << "SYSTEM: " <<"Go back? Y / N: ";
        menu_choice = 0;
        cin >> menu_choice;
        if (menu_choice == 'Y' || menu_choice == 'y'){
            goto start;
        }

        break;
    case 4:
    default:
        break;
    }

    system("pause");
}


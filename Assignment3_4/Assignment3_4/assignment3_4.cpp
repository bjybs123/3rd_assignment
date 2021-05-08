#include <iostream>
#include "node.h"
#include <crtdbg.h>

using namespace std;


int calScore(Link* checkLink)
{
    int score = 0;
    bool Ain = false;
    Node* tempNode = checkLink->getHead();

    while (tempNode)
    {
        if (tempNode->getCard()[1] == '1' && tempNode->getCard()[2] == '0')
            score += 10;
        else
        {
            switch (tempNode->getCard()[1])
            {
            case 'A':   Ain = true; break;
            case '2':   score += 2; break;
            case '3':   score += 3; break;
            case '4':   score += 4; break;
            case '5':   score += 5; break;
            case '6':   score += 6; break;
            case '7':   score += 7; break;
            case '8':   score += 8; break;
            case '9':   score += 9; break;
            case 'J':   score += 10; break;
            case 'K':   score += 10; break;
            case 'Q':   score += 10; break;
            }
        }
        tempNode = tempNode->getNext();
    }
    

    if (Ain == true)
    {
        if (score + 11 < 21)
            score += 11;
        else
            score += 1;
    }

    return score;
}

int main()
{
    Link Deck;
    Link Discard_tray;
    Link Dealer;
    Link Player;

    char* command = new char[100];

    Deck.initial();

    while (true)
    {
        cout << "Command list(game/shuffle/exit)\n";
        cout << "CMD>> ";
        cin >> command;

        if (strcmp(command, "game") == 0)
        {
            if (Deck.getCount() != 52)
            {
                cout << "Not Enough Cards\n";
                continue;
            }
            srand((unsigned int)time(NULL));

            
            
            

            while (true)
            {
                char* bet = new char[10];
                cout << "Command list(bet/end)\n";                      //bet command
                cout << "CMD>> ";
                cin >> bet;

                Dealer.setScore(0);
                Player.setScore(0);

                Deck.pick(&Dealer);
                Dealer.setScore(calScore(&Dealer));
                Deck.pick(&Dealer);
                Dealer.setScore(calScore(&Dealer));
                Deck.pick(&Player);
                Player.setScore(calScore(&Player));
                Deck.pick(&Player);
                Player.setScore(calScore(&Player));

                

                if (strcmp(bet, "bet") == 0)
                {
                    if (Deck.getCount() < 13)
                    {
                        cout << "Not Enough Cards\n";
                        continue;
                    }

                    while (true)
                    {
                        char* hit = new char[10];

                        cout << "Dealer Cards : ";
                        Dealer.print();
                        cout << "cout --> " << Dealer.getScore() << "\n";
                        cout << "Player Cards : ";
                        Player.print();
                        cout << "cout --> " << Player.getScore() << "\n";

                        cout << "Command list(hit/stand)\n";                //hit command
                        cout << "CMD>> ";
                        cin >> hit;

                        if (strcmp(hit, "hit") == 0)                        //hit를 할 경우 카드 추가
                        {
                            Deck.pick(&Player);
                            Player.setScore(calScore(&Player));

                            

                            if (Player.getScore() == Dealer.getScore())
                            {
                                cout << "Draw...\n";
                                Discard_tray.place(&Player);
                                Discard_tray.place(&Dealer);
                                break;
                            }

                            if (Player.getScore() > 21)
                            {

                                cout << "Dealer Cards : ";
                                Dealer.print();
                                cout << "Player Cards : ";
                                Player.print();

                                Discard_tray.place(&Player);
                                Discard_tray.place(&Dealer);
                                cout << "Player Lose!\n";
                                break;
                            }
                        }
                        else if (strcmp(hit, "stand") == 0)
                        {

                            if (Dealer.getScore() <= 16)               //딜러의 카드가 16이하일때 
                            {
                                Deck.pick(&Dealer);
                                Dealer.setScore(calScore(&Dealer));
                            }

                            cout << "Dealer Cards : ";
                            Dealer.print();
                            cout << "Player Cards : ";
                            Player.print();

                            if (Player.getScore() > 21 && Dealer.getScore() <= 21)
                                cout << "Player Lose!\n";
                            else if (Player.getScore() <= 21 && Dealer.getScore() > 21)
                                cout << "Player Win!\n";
                            else if(Player.getScore() > 21 && Dealer.getScore() > 21)
                                cout << "Draw...\n";
                            else
                            {
                                if (Player.getScore() == Dealer.getScore())
                                    cout << "Draw...\n";
                                else if (Player.getScore() > Dealer.getScore())
                                    cout << "Player Win!\n";
                                else if (Player.getScore() < Dealer.getScore())
                                    cout << "Player Lose!\n";
                            }
                            Discard_tray.place(&Player);
                            Discard_tray.place(&Dealer);
                            delete[] hit;
                            break;
                        }
                        else
                        {
                            cout << "Wrong Command!\n";
                        }
                        delete[] hit;
                    }
                    
                }
                else if (strcmp(bet, "end") == 0)
                {
                    Discard_tray.place(&Player);
                    Discard_tray.place(&Dealer);
                    break;
                }
                else
                {
                    cout << "Wrong Command!\n";
                }
                delete[] bet;
            }
        }
        else if(strcmp(command, "shuffle") == 0)
        {

            int num;
            cin >> num;
            while (num)
            {
                
                Deck.place_discard(&Discard_tray, &Dealer);
                Deck.shuffle(&Dealer);
                --num;
            }
            
        }
        else if (strcmp(command, "print") == 0)
        {
            cout << "\n";
            Deck.print();
            cout << "\n";
        }
        else if (strcmp(command, "exit") == 0)
        {
            return 0;
        }
        else
        {
            cout << "Wrong Command!\n";
        }
        
    }

    delete[] command;

    _CrtDumpMemoryLeaks();
    return 0;
}
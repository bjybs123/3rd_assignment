#include <iostream>
#include "node.h"
using namespace std;

int calScore(Link* checkLink)
{
    int score = 0;
    bool Ain = false;
    Node* tempNode = checkLink->getHead();

    while (tempNode)
    {
        switch(tempNode->getCard()[1])
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
        tempNode = tempNode->getNext();
    }

    if (score + 11 < 21)
        score += 11;
    else
        score += 1;
    return score;
}

int main()
{
    Link* Deck = new Link();
    Link* Discard_tray = new Link();
    Link* Dealer = new Link();
    Link* Player = new Link();

    char* command = new char[100];

    Deck->initial();

    while (true)
    {
        cout << "Command list(game/shuffle/exit)\n";
        cout << "CMD>> ";
        cin >> command;

        if (strcmp(command, "game") == 0)
        {
            Deck->pick(Dealer);
            Deck->pick(Dealer);
            Deck->pick(Player);
            Deck->pick(Player);

            char* bet = new char[10];
            cout << "Command list(bet/end)\n";                      //bet command
            cout << "CMD>> ";
            cin >> bet;

            if (strcmp(bet, "bet") == 0)
            {
                while (true)
                {
                    char* hit = new char[10];

                    cout << "Dealer Cards : ";
                    Dealer->qprint();
                    cout << "Player Cards : ";
                    Player->print();


                    cout << "Command list(hit/stand)\n";                //hit command
                    cout << "CMD>> ";
                    cin >> hit;


                    Dealer->setScore(calScore(Dealer));
                    if (Dealer->getScore() <= 16)               //딜러의 카드가 16이하일때 hit
                    {
                        Dealer->pick(Dealer);
                    }
                    Player->setScore(calScore(Player));

                    if (strcmp(hit, "hit") == 0)                        //hit를 할 경우 카드 추가
                    {
                        if (Player->getScore() > 21)
                        {
                            cout << "Player Lose!\n";
                            break;
                        }
                        Deck->pick(Player);
                    }
                    else
                    {
                        if (Player->getScore() > 21 && Dealer->getScore() <= 21)
                            cout << "Player Lose!\n";
                        else if (Player->getScore() <= 21 && Dealer->getScore() > 21)
                            cout << "Player Win!\n";
                        else
                        {
                            if (Player->getScore() == Dealer->getScore())
                                cout << "Draw...\n";
                            else if (Player->getScore() > Dealer->getScore())
                                cout << "Player Win!\n";
                            else if (Player->getScore() < Dealer->getScore())
                                cout << "Player Lose!\n";
                        }

                        Discard_tray->place(Player);
                        Discard_tray->place(Dealer);

                        delete[] hit;
                        delete[] bet;
                        break;
                    }

                }
            }
            else
            {
                
                delete[] bet;
                break;
            }

        }
        else if(strcmp(command, "shuffle") == 0)
        {
            Deck->place_discard(Discard_tray, Dealer);
            int num;
            cin >> num;
            while (num)
            {
                Deck->shuffle(Dealer);
                --num;
            }
        }
        else if (strcmp(command, "print") == 0)
        {
            cout << "\n";
            Deck->print();
            cout << "\n";
        }
        else
        {
            cout << "Wrong Command!\n";
            continue;
        }
    }
    
    

}
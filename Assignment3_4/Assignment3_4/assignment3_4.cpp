#include <iostream>
#include "node.h"
using namespace std;



int main()
{
    Link* Deck = new Link();
    Link* Discard_tray = new Link();
    Link* Dealer = new Link();
    Link* Player = new Link();

    char* command = new char[100];

    while (true)
    {
        cout << "Command list(game/shuffle/exit)\n";
        cout << "CMD>> ";
        cin >> command;

        if (strcmp(command, "game") == 0)
        {
            Deck->initial();
            while (true)
            {
                cout << "Command list(bet/end)\n";
                cout << "CMD>> ";

            }
        }
        else if(strcmp(command, "shuffle") == 0)
        {
            int num;
            cin >> num;
            while (num)
            {
                Deck->shuffle(Dealer);
                --num;
            }
        }
    }
    
    

}
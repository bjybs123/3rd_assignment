#include <iostream>
#include "node.h"
using namespace std;



int main()
{
    Link* Deck = new Link();
    Link* Discard_tray = new Link();
    Link* Dealer = new Link();
    Link* Player = new Link();

    Deck->initial();
    
    Discard_tray->insert("NA", "M");
    Discard_tray->insert("SU", "N");
    Discard_tray->insert("XX", "N");


 
    Deck->place_discard(Discard_tray, Dealer);
    Deck->shuffle(Dealer);
    Deck->shuffle(Dealer);

    Deck->print();
    cout << "deck count : " << Deck->getCount() << "\n";

    cout << "\n\ndelaer\n\n";
    Dealer->print();
    cout << "shuffle completed\n";
    cout << "dealer count : " << Dealer->getCount()  << "\n";

}
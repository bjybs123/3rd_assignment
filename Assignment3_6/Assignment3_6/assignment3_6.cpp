
#include "block.h"
int main()
{
	board* Gboard = new board();
	horse* yut1 = new horse("A1");
	
	Gboard->initial();
	Gboard->goYut(yut1, 20);

	Gboard->printBoard();
	cout << "fin";
	return 0;
}
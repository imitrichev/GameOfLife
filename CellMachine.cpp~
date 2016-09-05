// Example program
#include <iostream>
#include <string>
#include "CellMachine.h"
using namespace std;


int CellMachine::Start(int Width, int Height, Cell cells[][]) {
	Field field = fieldConstructor(Width, Height, cells[][]);
        int i;
        for (i=0;i<100;i++) {
            field.Update();
            field.ShowField();
            if (fiend.AmountOfAlive() <= 0) {
                cout << "Dead."; 
                break;
                return 2;
            }
            sleep(1000);
            
        }
        cout << "Alive!."; 
        return 1;
}




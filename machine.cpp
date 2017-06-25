#include "machine.h"
#include <windows.h>
#include <iostream>

using namespace std;

Machine::Machine()
{
    /* инициализация переменных. все значения, кроме нулевых, выбраны случайно */
    x = new int(0);
    y = new int(0);
    rpm = new int(0);
    maxrpm = new int(1800);
    state = new int(0);
    geom = new Geometric(x, y, rpm, maxrpm, state);
}

Machine::~Machine()
{
    delete geom;
    delete x;
    delete y;
    delete rpm;
    delete state;
}

void Machine::process(int depth)
{
    geom->process(depth);
}

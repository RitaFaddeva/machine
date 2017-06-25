#include <iostream>
#include "machine.h"

using namespace std;

int main(int argc, char *argv[])
{    setlocale(LC_ALL, "rus");
    Machine m;
    m.process(1000);
    return 0;
}

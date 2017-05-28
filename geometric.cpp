#include "geometric.h"
#include <windows.h>
#include <iostream>

// частота дискретизации работы станка (можно изменять, выбрана для примера)
#define FREQUENCY 40

using namespace std;

Geometric::Geometric(int *xp, int *yp, int *rpmp, int *mxrpm, int *st)
{
    /* инициализация переменных. все значения, кроме нулевых, выбраны случайно */
    x = xp;
    y = yp;
    rpm = rpmp;
    maxrpm = mxrpm;
    state = st;
    micmpr = 10;
    drill = 6;
}

Geometric::~Geometric()
{
    state = 0;
}

void Geometric::process(int depth)
{
    *state = 1;                                             // изменения состояния на "в работе"
    *rpm = *maxrpm;                                         // текущее число оборотов на максимум
    double rpt = (double)(*rpm) * FREQUENCY / 60000;        // число оборотов за один "тик" дискретизации
    int end_depth = (int)((double)depth - rpt * micmpr);    // предельная глубина сверления

    while (*x <= end_depth && *state == 1) {                // если модуль контроля ошибок изменит значение переменной состояния в момент обработки детали, то обработка прервется
        Sleep(FREQUENCY);                                   // работа станка занимает какое-то время
        *x += (int)(rpt * micmpr);                          // процесс сверления заключается в изменении координаты X (в данном примере)
        cout << "x:   " << *x << endl;                      // вывод в консоль для наглядности
        cout << "y:   " << *y << endl;
        cout << "rpm: " << *rpm << endl;
    }

    if (*state == 1) {                                      // если программа отработала без ошибок
        Sleep(FREQUENCY);
        *x = depth;                                         // завершение сверления
        *state = 0;                                         // перевод станка в режим ожидания
    }

    *rpm = 0;                                               // остановка вращения
}

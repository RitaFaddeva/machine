#ifndef GEOMETRIC_H
#define GEOMETRIC_H
#include <string>


class Geometric
{
public:
    Geometric(int *xp, int *yp, int *rpmp, int *mxrpm, int *st);
    ~Geometric();
    void process(int depth);    // демонстрационная процедура обработки детали. параметр - в микрометрах
private:
    int *x;                     // координата X сверла
    int *y;                     // координата Y сверла
    int *rpm;                   // текущее число оборотов в минуту
    int *maxrpm;                // максимальное число оборотов в минуту
    int micmpr;                 // число проходимых сверлом микрометров за оборот
    int drill;                  // диаметр сверла в мм
    int *state;                 // переменная состояния. 0 - станок в режиме ожидания,
                                // 1 - в процессе обработки, иначе - код ошибки
};

#endif // GEOMETRIC_H

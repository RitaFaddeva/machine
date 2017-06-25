#ifndef ERRORER_H
#define ERRORER_H
#include "geometric.h"
#include <iostream>
#include <string>
using namespace std;

class errorer{
private:
    int codeexist; //
    int state;
    // это состояние работы


public:
    errorer();
    int i=1;
    int a,b,speed;
    struct codes{    //структура ошибок
     int id;         //идентификатор
     string code;    //сам код
     string desc;   //описание ошибки
    };
    struct data{       //исходные
        int num;       //идентификатор
        int x,y,rpm;  // сами данные
    };

    codes f_code;
    codes s_code;
    codes t_code;


int workstate(int x,int y, int rpm, int k);
int gate(int r);
void codesinf();
 ~errorer();
};

#endif // ERRORER_H

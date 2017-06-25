#include "errorer.h"
#include <iostream>
#include <geometric.h>
#include <string>

using namespace std;

errorer::errorer()
{
}
void errorer::codesinf(){
    f_code.id = 1;
    f_code.code = "000x01";
    f_code.desc = "Некорректное значение параметра х";


    s_code.id = 2;
    s_code.code = "000y01";
    s_code.desc = "Некорректное значение парраметра y";


    t_code.id = 3;
    t_code.code = "000x724";
    t_code.desc = "Неккоретное значение скорости вращения шпиля rpm";
}

int errorer::workstate(int x, int y, int rpm, int k){

    int r =0;
    if (x != k*11) r = 1;
    if (y != 0) r = r+10;
    if (rpm != 1800) r = r+100;

    gate(r);
}

int errorer::gate(int r){


     codesinf();

      switch(r)
         {
          case 1:
            cout<<f_code.code<< ": " << f_code.desc<< endl;
            break;
          case 10:
            cout<<s_code.code<< ": " << s_code.desc<< endl;
            break;
          case 11:
            cout<<f_code.code<< ": " << f_code.desc<<endl;
            cout<<s_code.code<< ": " << s_code.desc<< endl;
            break;
          case 100:
            cout<<t_code.code<< ": " << t_code.desc<< endl;
            break;
          case 101:
            cout<<f_code.code<< ": " << f_code.desc<< endl;
            cout<<t_code.code<< ": " << t_code.desc<< endl;
            break;
          case 110:
            cout<<s_code.code<< ": " << s_code.desc<< endl;
            cout<<t_code.code<< ": " << t_code.desc<< endl;
            break;
          case 111:
            cout<<f_code.code<< ": " << f_code.desc<< endl;
            cout<<s_code.code<< ": " << s_code.desc<< endl;
            cout<<t_code.code<< ": " << t_code.desc<< endl;
            break;
          default:
            cout<<"Ошибок не обнаружено"<<endl;
          break;}
      if (r>0) return 0; else return 1;

      }





//void errorer::srav(){}




// =================================================================
//Evidencia Competencia | Act 2.3
// File: main.cpp
// Author: 
// Santiago Reynaldo Aguilar Vega | A01709030
// Jesus Ramirez Delgado | A01274723
// Date: 18 Octubre 2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include "classes.h"
#include <string>

int main(int argc, char* argv[]) {

  std::ifstream archivo1(argv[1]); 
  std::ofstream archivo2(argv[2]);

  int numElements;
  std::string date, hour, E, pos, prefix, prefixdata;
  int day, month, year;

  archivo1 >> numElements >> prefix;

  std::vector<Reg> reg;

  std::vector<Month> CMonth;

  for (int k = 1; k < 13; k++){
    CMonth.push_back(Month(k));
  };

  std::string month_string[12] = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};

  reg.resize(numElements);

  for (int i = 0; i < reg.size(); i++){

    archivo1 >> date >> hour >> E >> pos;

    month = std::stoi(date.substr(3, 2));

    prefixdata = pos.substr(0, 3);

    if(prefixdata == prefix){
      reg.push_back(Reg(month, E, pos));
    }
  };

  for (int h = 0; h < 12 ; h++){

    CMonth[h].ports(reg);

    archivo2 << month_string[h] << '\n';
    CMonth[h].output(archivo2);
  };

  archivo1.close();
  archivo2.close();

  return 0;
}
// =================================================================
//Evidencia Competencia | Act 2.3
// Author: 
// Santiago Reynaldo Aguilar Vega | A01709030
// Jesus Ramirez Delgado | A01274723
// Date: 18 Octubre 2022
//
// =================================================================

#ifndef REG_H
#define REG_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Reg{
	private:
		int month;
		std::string E;
		std::string pos;

	public:
		Reg(){};
		Reg(int, std::string, std::string);

		int getMonth(){
			return month;
		};

		std::string getE(){
			return E;
		};

		std::string getPos(){
			return pos;
		};
};

Reg::Reg(int month_, std::string E_, std::string pos_)
{
	month = month_;
	E = E_;
	pos = pos_;
}


class Month{
	private:
		int n;
		int Mc;
		int Rc;
		std::vector<Reg> rM;
		std::vector<Reg> rR;

	public:
		Month(int);

		void sumC(int def){
			if (def == 0){
				Mc += 1;
			}
			else if (def == 1){
				Rc += 1;
			}
		};

		int getMc(){
			return Mc;
		};

		int getRc(){
			return Rc;
		};

		void addrM(Reg r_){
			rM.push_back(r_);
		};

		void addrR(Reg r_){
			rR.push_back(r_);
		};

		std::string getPosM(int pos){
			return rM[pos].getPos();
		};

		std::string getPosR(int pos){
			return rR[pos].getPos();
		};

		int getSizeM(){
			return rM.size();
		};

		int getSizeR(){
			return rR.size();
		};

		void output(std::ofstream& out_file){

			if(getMc() > 0){
				out_file << "M " << getMc() << ": ";

				for (int a = 0; a < getSizeM(); a++)
				{
					out_file << getPosM(a) << " ";
				};

				out_file << '\n';
			}

			if(getRc() > 0){
				out_file << "R " << getRc() << ": ";

				for (int b = 0; b < getSizeR(); b++)
				{
					out_file << getPosR(b) << " ";
				};

				out_file << '\n';
			}
		};

		void ports(std::vector<Reg> r_vec){
			for (int j = 0; j < r_vec.size(); j++){
				
				if (r_vec[j].getMonth() == n){

					if (r_vec[j].getE() == "M"){
						
						sumC(0);
						
						addrM(r_vec[j]);
					}
					else if (r_vec[j].getE() == "R"){
						sumC(1);
						addrR(r_vec[j]);
					}
				}
			}
		};
};

Month::Month(int n_)
{
	n = n_;
};

#endif
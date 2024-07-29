/**
* @file Sayi.hpp
* @description Sayi isimli sınıfın tanımlaması yapılmıştır
* @course 1.ogretim B grubu
* @assignment 1.Odev
* @date 26 Ekim - 26 Kasım
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/

#ifndef SAYI_HPP
#define SAYI_HPP

#include "Basamak.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <iomanip> 

using namespace std;


class Sayi
{
	private:
		Basamak* head;
		int size;
		
		Basamak* FindPrevByPosition( int position);
			
	
	public:
		Sayi();
		
		bool isEmpty();
		

		int Count();
		
		const int& first();
		
		const int last();
		
		
		void add(const int item);
		
		
		void insert(int index,const int item);
		
		
		void remove(const int item);
		
		
		void removeAt(int index);
		
		
		int indexOf(const int item);
		
		bool find(const int item);
		
		
		
		void clear();
		

		void print();
		

		int basamak_print(int index);
		

		Basamak* getNodeAt(int index);
      

	    int basamaklariCevir();

		void tersCevir();

		void tekSayilariBasaGetir();
	
		
		~Sayi();



		
		
};


#endif
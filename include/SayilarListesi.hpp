/**
* @file SayilarListesi.hpp
* @description SayilarListesi isimli sınıfın tanımlaması yapılmıştır
* @course 1.ogretim B grubu
* @assignment 1.Odev
* @date 26 Ekim - 26 Kasım
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/
#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP


#include"Dugum.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <iomanip> 

using namespace std;

class SayilarListesi
{
	private:
		Dugum* head;
		int size;
		
		Dugum* FindPrevByPosition( int position);
		
			
	
	public:
		SayilarListesi();
		
		bool isEmpty();

		int Count();
		

		Sayi* getLinkedListInNode(int index);
        
		void add(Sayi* item);
		
		void insert(int index,Sayi* item);
		
		void remove(Sayi* item);
		
		void removeAt(int index);
	
		int indexOf(const Sayi* item); 
		
		bool find(Sayi* item);
		
		void clear();
		

		void print();
		
		~SayilarListesi();
		
};



#endif
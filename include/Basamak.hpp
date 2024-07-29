/**
* @file Basamak.hpp
* @description Basamak düğümünün tanımlaması yapılmıştır
* @course 1.ogretim B grubu
* @assignment 1.Odev
* @date 26 Ekim - 26 Kasım
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/
#ifndef BASAMAK_HPP
#define BASAMAK_HPP

#include <iostream>
using namespace std;






class Basamak
{
	public:
		int item;
		Basamak* next;
	
		Basamak( const int item, Basamak* next=NULL);
	
};

#endif
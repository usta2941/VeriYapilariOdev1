/**
* @file Basamak.cpp
* @description Sayi bağlı listenin düğümü olacak şekilde tasarlanmıştır
* @course 1.ogretim B grubu
* @assignment 1.Odev
* @date 26 Ekim - 26 Kasım
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/


#include "Basamak.hpp"

using namespace std;

Basamak::Basamak( const int item, Basamak* next)
	{
		this->item = item;
		this->next = next;
	};
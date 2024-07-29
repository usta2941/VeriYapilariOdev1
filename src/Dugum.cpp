/**
* @file Dugum.cpp
* @description SayilarListesi adlı bağlı listenin düğümü olacak şekilde tasarlanmıştır
* @course 1.ogretim B grubu
* @assignment 1.Odev
* @date 26 Ekim - 26 Kasım
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/


#include"Dugum.hpp"

using namespace std;


Dugum::Dugum( Sayi* item, Dugum* next)
	{
		this->item = item;
		this->next = next;
	};

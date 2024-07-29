/**
* @file Dugum.hpp
* @description Dugum isimli düğümün tanımlaması yapılmıştır
* @course 1.ogretim B grubu
* @assignment 1.Odev
* @date 26 Ekim - 26 Kasım
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/

#ifndef DUGUM_HPP
#define DUGUM_HPP


#include <iostream>
#include "Sayi.hpp"
using namespace std;


class Dugum
{
    public:
	    Sayi* item;
	    Dugum* next;
	
	    Dugum( Sayi* item, Dugum* next = NULL);
	
};


#endif
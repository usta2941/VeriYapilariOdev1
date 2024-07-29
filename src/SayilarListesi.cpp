/**
* @file SayilarListesi.cpp
* @description SayilarListesi adlı sınıfın metodları tasarlanmıştır
* @course 1.ogretim B grubu
* @assignment 1.Odev
* @date 26 Ekim - 26 Kasım
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/

#include "SayilarListesi.hpp"


Dugum* SayilarListesi::FindPrevByPosition( int position)  // tamam
		{
			if(position<0 || position>size) throw "index out of range";
			
			int index=1;
			
			for( Dugum* itr = head; itr != NULL; itr= itr->next,index++)
			{
				if(position == index) return itr;
			}
			return NULL;
		}

SayilarListesi::SayilarListesi()
		{
			head = NULL;
			size = 0;
		}


bool SayilarListesi::isEmpty()
		{
			return size == 0;
		}

int SayilarListesi::Count()
        { 
			return size;
		}

Sayi* SayilarListesi::getLinkedListInNode(int index)
    {
        	Dugum* current = head;
        	int currentIndex = 0;

        	// SayilarListesi'ni tarayarak hedef index değerine ulaş
        	while (current != nullptr) {
            	if (currentIndex == index) {
                	return current->item; 
            }
            current = current->next;
            currentIndex++;
        }

        return nullptr;
    }

void SayilarListesi::add(Sayi* item) 
		{
			insert(size,item); 
		}

void SayilarListesi::insert(int index,Sayi* item)
		{
			if(index == 0) 
				head = new Dugum(item,head);
			else
			{
				Dugum* prev = FindPrevByPosition(index);
				prev->next = new Dugum(item,prev->next);
			}
			size++;
		}

void SayilarListesi::remove(Sayi* item) 
		{
			int index = indexOf(item);
			removeAt(index);
		}

void SayilarListesi::removeAt(int index)  
		{
			if(size == 0) throw "empty list";
			Dugum* del;
			
			if(index == 0)
			{
				del = head;
				head = head->next;
			}
			else
			{
				Dugum* prev = FindPrevByPosition(index);
				del = prev->next;
				prev->next = FindPrevByPosition(index)->next->next;
			}
			
			delete del;
			size--;
		}

int SayilarListesi::indexOf(const Sayi* item)   
		{
			int index = 0;
			for(Dugum* itr= head; itr != NULL;itr= itr->next,index++)
				if(itr->item == item) return index;
			
			throw "index out of range";
		}

bool SayilarListesi::find(Sayi* item)
		{
			for(Dugum* itr = head; itr!= NULL;itr = itr->next)
			{
				if(itr->item == item)
					return true;
			}
			
			return false;
		}

void SayilarListesi::clear()   
		{
			while(!isEmpty())
				removeAt(0);
		}

void SayilarListesi::print() 
		{ 
			

			for(Dugum* itr = head; itr!= NULL;itr = itr->next)
			{
				
				itr->item->print();
				cout<<"\n"<<"-----------"<<endl;
			}
		}

SayilarListesi::~SayilarListesi()
		{
			clear();
		}
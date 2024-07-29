/**
* @file Sayi.cpp
* @description Sayi isimli bağlı listenin sınıflarına ait metodlar tasarlanmıştır
* @course 1.ogretim B grubu
* @assignment 1.Odev
* @date 26 Ekim - 26 Kasım
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/


#include "Sayi.hpp"


Basamak* Sayi::FindPrevByPosition( int position)
		{
			if(position<0 || position>size) throw "index out of range";
			
			int index=1;
			
			for( Basamak* itr = head; itr != NULL; itr= itr->next,index++)
			{
				if(position == index) return itr;
			}
			return NULL;
		}


Sayi::Sayi()
		{
			head = NULL;
			size = 0;
		}

bool Sayi::isEmpty()
		{
			return size == 0;
		}

int Sayi::Count()
        {
			return size;
		}

const int& Sayi::first()
		{
			if(isEmpty()) throw "Empty List";
			return head->item;
		}

const int Sayi::last()
		{
			if(isEmpty()) throw "Empty List";
			return FindPrevByPosition(size)->item;
		}

void Sayi::add(const int item)
		{
			insert(size,item); 
		}

void Sayi::insert(int index,const int item)
		{
			if(index == 0) 
				head = new Basamak(item,head);
			else
			{
				Basamak* prev = FindPrevByPosition(index);
				prev->next = new Basamak(item,prev->next);
			}
			size++;
		}

void Sayi::remove(const int item)
		{
			int index = indexOf(item);
			removeAt(index);
		}

void Sayi::removeAt(int index)
		{
			if(size == 0) throw "empty list";
			Basamak* del;
			
			if(index == 0)
			{
				del = head;
				head = head->next;
			}
			else
			{
				Basamak* prev = FindPrevByPosition(index);
				del = prev->next;
				prev->next = FindPrevByPosition(index)->next->next;
			}
			
			delete del;
			size--;
		}

int Sayi::indexOf(const int item)
		{
			int index = 0;
			for(Basamak* itr= head; itr != NULL;itr= itr->next,index++)
				if(itr->item == item) return index;
			
			throw "index out of range";
		}

bool Sayi::find(const int item)
		{
			for(Basamak* itr = head; itr!= NULL;itr = itr->next)
			{
				if(itr->item == item)
					return true;
			}
			
			return false;
		}

void Sayi::clear()
		{
			while(!isEmpty())
				removeAt(0);
		}

void Sayi::print()
		{
			

			for(Basamak* itr = head; itr!= NULL;itr = itr->next)
			{
				cout<<itr->item<<" ";
			}
		}


int Sayi::basamak_print(int index)
		{
			if(index == 0)
			{
				return head->item;
			}

			Basamak* itr = head;
			while(index)
			{
				itr = itr->next;
				index--;
			}

			return itr->item;
		}

Basamak* Sayi::getNodeAt(int index)
    {
        Basamak* current = head;
        int currentIndex = 0;

        
        while (current != nullptr) {
            if (currentIndex == index) {
                return current; 
            }
            current = current->next;
            currentIndex++;
        }

       
        return nullptr;
    }
int Sayi::basamaklariCevir()
{
	int birlesmisSayi = 0;

    
    for (int i = 0; i < this->Count(); ++i) 
	{
        birlesmisSayi = birlesmisSayi * 10 + this->basamak_print(i);
    }
	return birlesmisSayi;
}
	

void Sayi::tersCevir()
    {
        Basamak* prev = nullptr;
        Basamak* current = head;
        Basamak* next = nullptr;

        while (current != nullptr)
        {
            next = current->next; // Sonraki düğümü geçici olarak sakla
            current->next = prev; // Düğümü ters çevir

            // İlerle
            prev = current;
            current = next;
        }

        // Başlangıç düğümünü güncelle
        head = prev;
    }

void Sayi::tekSayilariBasaGetir()
   {
       if (head == nullptr || head->next == nullptr) {
            // Liste boş veya tek elemanlı ise işlem yapmaya gerek yok
            return;
        }
 
        Basamak* tempHead = new Basamak(0);
        tempHead->next = head;

        Basamak* current = tempHead;
        Basamak* oddHead = nullptr;
        Basamak* oddTail = nullptr;

        while (current->next != nullptr) {
            if (current->next->item % 2 == 1) {
              
                if (oddHead == nullptr) {
                    oddHead = current->next;
                    oddTail = current->next;
                } else {
                    oddTail->next = current->next;
                    oddTail = oddTail->next;
                }

                
                current->next = current->next->next;
            } else {
               
                current = current->next;
            }
        }

        oddTail->next = tempHead->next;
        head = oddHead;

        //delete tempHead;
    }


Sayi::~Sayi()
		{
			clear();
		}



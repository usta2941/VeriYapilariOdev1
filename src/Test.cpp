/**
* @file Test.cpp
* @description Kodu başlatıp kullanıcıdan alınan komutları yerine getiren dosya
* @course 1.ogretim B grubu
* @assignment 1.Odev
* @date 26 Ekim - 26 Kasım
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/

#include<iostream>
#include"SayilarListesi.hpp"


using namespace std;


void basamaklaraAyirVeYazdir(int sayi,Sayi* basamak) {   // tamam
    int basamakSayisi = static_cast<int>(log10(sayi)) + 1;
    int* basamaklar = new int[basamakSayisi];

    for (int i = basamakSayisi - 1; i >= 0; --i) {
        basamaklar[i] = sayi % 10;
        sayi /= 10;
    }

    
    for (int i = 0; i < basamakSayisi; ++i) {
        //std::cout << basamaklar[i] << " ";
		basamak->add(basamaklar[i]);
    }
    std::cout << std::endl;

    delete[] basamaklar;
}

std::string getLastThreeHexDigitsFromAddress(const void* address) {  
    // Adresi hexadecimal olarak formatlanmış stringe çevir
    std::stringstream ss;
    ss << std::hex << std::setw(sizeof(address) * 2) << std::setfill(' ') << reinterpret_cast<std::uintptr_t>(address);

    // Oluşturulan stringin son 3 karakterini al
    std::string hexString = ss.str();
    return hexString.substr(hexString.length() - 3);
}


void printFormattedOutput(SayilarListesi* sayilarListesi) {    

for(int z = 0; z < sayilarListesi->Count();z++)
{
	std::cout << "##########  ";
	for (int j = 0; j < sayilarListesi->getLinkedListInNode(z)->Count(); j++) {
            std::cout << " ******* ";
        }
        std::cout << std::endl;

	std::cout << "#" << std::setw(8) << std::setfill(' ') << sayilarListesi->getLinkedListInNode(z) << "#  ";
	for (int j = 0; j < sayilarListesi->getLinkedListInNode(z)->Count(); j++) {
            std::cout << " * " << std::setw(4) << std::setfill(' ') << getLastThreeHexDigitsFromAddress(sayilarListesi->getLinkedListInNode(z)->getNodeAt(j)) << "* "; 
        }
        std::cout << std::endl;

	for (int k = 1; k >=1; k--)
		{
		std::cout << "##########  ";
		for (int j = 0; j < sayilarListesi->getLinkedListInNode(z)->Count(); j++) {
            std::cout << " ******* ";
        }
        std::cout << std::endl;
		}





	
	std::cout << "#" << std::setw(8) << std::setfill(' ') << sayilarListesi->getLinkedListInNode(z)->basamaklariCevir() << "#  "; 
	for (int j = 0; j < sayilarListesi->getLinkedListInNode(z)->Count(); j++) {
            std::cout << " * " << std::setw(4) << std::setfill(' ') << sayilarListesi->getLinkedListInNode(z)->basamak_print(j)<< "* "; 
        }
        std::cout << std::endl;

	for (int k = 1; k >=1; k--)
		{
		std::cout << "#--------#  ";
		for (int j = 0; j < sayilarListesi->getLinkedListInNode(z)->Count(); j++) {
            std::cout << " ******* ";
        }
        std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		}

}




}



/* en buyuk sayiyi çıkar*/
void enBuyukCikar(SayilarListesi* sayilarListesi)
{
    

    int *butunSayilar = new int[sayilarListesi->Count()];
    for(int i = 0; i <sayilarListesi->Count();i++)
    {
	    butunSayilar[i] = sayilarListesi->getLinkedListInNode(i)->basamaklariCevir();
    }

    int enBuyukIndex = 0;
    for (int i = 1; i < sayilarListesi->Count(); ++i)
    {
        if (butunSayilar[i] > butunSayilar[enBuyukIndex]) 
        {
            enBuyukIndex = i;
        }
    }

    sayilarListesi->removeAt(enBuyukIndex);

    delete[] butunSayilar;

}



int main() {  // tamam
    std::ifstream dosya("Sayilar.txt"); 

    

    std::string satir;

	SayilarListesi* sayilarListesi = new SayilarListesi();
    while (std::getline(dosya, satir)) {
        std::istringstream satirStream(satir);
        std::string string_sayi;

        while (satirStream >> string_sayi) {
            try {
                int sayi = std::stoi(string_sayi);
				Sayi* basamak = new Sayi();
                basamaklaraAyirVeYazdir(sayi,basamak);
				sayilarListesi->add(basamak);
            } catch (const std::invalid_argument& e) {
               
             
            }
        }
    }

	system("CLS");
	printFormattedOutput(sayilarListesi);
    cout<<endl;

    int userCommand = 0;
	do
    {
        cout<<"1.Tek Basamaklari Basa Al (Bazen hata veriyor ama digerleri calisiyor)"<<endl;
        cout<<"2.Basamaklari Tersle"<<endl;
        cout<<"3.En Buyuk Cikar"<<endl;
        cout<<"4.Cikis"<<endl;

        cin>>userCommand;
        if(userCommand == 1)  /*tek basamakları basa getirir */
        {
	        for(int i = 0; i <sayilarListesi->Count();i++)
	        {
		        sayilarListesi->getLinkedListInNode(i)->tekSayilariBasaGetir();
	        }
            cout<<endl;
            printFormattedOutput(sayilarListesi);

        }
        else if(userCommand == 2)/*  basamakları ters çevirir*/
        {
            cout<<endl;
	        for(int i = 0; i <sayilarListesi->Count();i++)
	        {
	            sayilarListesi->getLinkedListInNode(i)->tersCevir();
	        }   

	        printFormattedOutput(sayilarListesi);
        }
        else if(userCommand == 3) /* En buyuk cıkar*/
        {
            cout<<endl;
            enBuyukCikar(sayilarListesi);
            printFormattedOutput(sayilarListesi);
        }
    }while(userCommand != 4);

    delete sayilarListesi;

    





    


    dosya.close();

    return 0;
}

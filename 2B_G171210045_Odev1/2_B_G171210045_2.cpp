/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI: 2
**				ÖÐRENCÝ ADI: Fatih Aslan
**				ÖÐRENCÝ NUMARASI: G171210045
**				DERS GRUBU: B
****************************************************************************/

#include "stdafx.h"
#include <iostream>                                 //Gerekli kütüphaneler
#include <iomanip>                                  
using namespace std;
int main()
{
	int kucukdeger;                                      // Ýhtiyacýmýz olucak deðerleri tanýmladýk 
	int kucukdegersayac = 0;
	int buyukdeger;
	int buyukdegersayac = 0;
	int ortadegersayac = 0;
	int sayac;
	int dongu1 = 0;
	int dongu2 = 0;
	int grafik;
	char cevap;
	int buyukdegeryildiz;
	int ortadegeryildiz;
	int kucukdegeryildiz;

	while (dongu1 == 0)                                 // Kullanýcýnýn yeni bir deðer girebilmesi için döngü
	{
		while (dongu2 == 0)                                //Eðer küçük deðer büyük deðerden küçük olmassa sonsuz döngü
		{
			cout << "Lutfen kucuk deger ve buyuk deger girin(kucuk deger buyuk degerden kucuk olmali)" << endl;
			cin >> kucukdeger >> buyukdeger;
			if (kucukdeger<buyukdeger)
				(dongu2 = 1);
		}



		for (sayac = 1; sayac<=20; sayac++)                           //Sayaçý 20ye kadar saydýrdým ve böylelikle belli fonksiyonlarda belli 
		{                                                       //sayaçlarý arttýrarak grafiðin çizilmesine yardýmcý oldum
			if (sayac>buyukdeger)
				buyukdegersayac++;


			else if (sayac<=buyukdeger&&sayac>=kucukdeger)
				ortadegersayac++;


			else if (sayac<kucukdeger)
				kucukdegersayac++;
		}
		cout << setw(2) << "1" << setw(kucukdegersayac + ortadegersayac + 1);                         //1,0,-1 yazdýrdýktan sonra yanlarýna ne kadar boþluk
		for (buyukdegeryildiz = 1; buyukdegeryildiz<=buyukdegersayac; buyukdegeryildiz++)         //konulmasý gerektiðini söylüyorum
			cout << "*";                                                                          //ardýndan kaç tane yýldýz girilceðini sayaçtan söylüyorum 
		cout << endl;
		cout << setw(2) << "0" << setw(kucukdegersayac + 1);
		for (ortadegeryildiz = 1; ortadegeryildiz<=ortadegersayac; ortadegeryildiz++)
			cout << "*";
		cout << endl;
		cout << setw(1) << "-1";
		for (kucukdegeryildiz = 1; kucukdegeryildiz<=kucukdegersayac; kucukdegeryildiz++)
			cout << "*";
		cout << endl;

		cout << "Devam etmek istemiyorsan \"h\" yi tusla" << endl;                      //(kullanýcýnýn devam edebilmesi için)
		cin >> cevap;
		if (cevap == 'h')
			(dongu1 = 1);
		else
		{
			(buyukdegersayac = 0);                                                //kullanýcý devam etmek istiyorsa sayaçlarý 
			(ortadegersayac = 0);                                                 //sýfýrlamalýyým yoksayýldýz sayýlarý iki kat fazla olur
			(kucukdegersayac = 0);
			(dongu2 = 0);

		}

	}
	cout << "iyi gunler" << endl;
	system("pause");         // Çalýþtýðýný görebilmek için durdurduk
	return 0;

}

/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI: 2
**				��RENC� ADI: Fatih Aslan
**				��RENC� NUMARASI: G171210045
**				DERS GRUBU: B
****************************************************************************/

#include "stdafx.h"
#include <iostream>                                 //Gerekli k�t�phaneler
#include <iomanip>                                  
using namespace std;
int main()
{
	int kucukdeger;                                      // �htiyac�m�z olucak de�erleri tan�mlad�k 
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

	while (dongu1 == 0)                                 // Kullan�c�n�n yeni bir de�er girebilmesi i�in d�ng�
	{
		while (dongu2 == 0)                                //E�er k���k de�er b�y�k de�erden k���k olmassa sonsuz d�ng�
		{
			cout << "Lutfen kucuk deger ve buyuk deger girin(kucuk deger buyuk degerden kucuk olmali)" << endl;
			cin >> kucukdeger >> buyukdeger;
			if (kucukdeger<buyukdeger)
				(dongu2 = 1);
		}



		for (sayac = 1; sayac<=20; sayac++)                           //Saya�� 20ye kadar sayd�rd�m ve b�ylelikle belli fonksiyonlarda belli 
		{                                                       //saya�lar� artt�rarak grafi�in �izilmesine yard�mc� oldum
			if (sayac>buyukdeger)
				buyukdegersayac++;


			else if (sayac<=buyukdeger&&sayac>=kucukdeger)
				ortadegersayac++;


			else if (sayac<kucukdeger)
				kucukdegersayac++;
		}
		cout << setw(2) << "1" << setw(kucukdegersayac + ortadegersayac + 1);                         //1,0,-1 yazd�rd�ktan sonra yanlar�na ne kadar bo�luk
		for (buyukdegeryildiz = 1; buyukdegeryildiz<=buyukdegersayac; buyukdegeryildiz++)         //konulmas� gerekti�ini s�yl�yorum
			cout << "*";                                                                          //ard�ndan ka� tane y�ld�z girilce�ini saya�tan s�yl�yorum 
		cout << endl;
		cout << setw(2) << "0" << setw(kucukdegersayac + 1);
		for (ortadegeryildiz = 1; ortadegeryildiz<=ortadegersayac; ortadegeryildiz++)
			cout << "*";
		cout << endl;
		cout << setw(1) << "-1";
		for (kucukdegeryildiz = 1; kucukdegeryildiz<=kucukdegersayac; kucukdegeryildiz++)
			cout << "*";
		cout << endl;

		cout << "Devam etmek istemiyorsan \"h\" yi tusla" << endl;                      //(kullan�c�n�n devam edebilmesi i�in)
		cin >> cevap;
		if (cevap == 'h')
			(dongu1 = 1);
		else
		{
			(buyukdegersayac = 0);                                                //kullan�c� devam etmek istiyorsa saya�lar� 
			(ortadegersayac = 0);                                                 //s�f�rlamal�y�m yoksay�ld�z say�lar� iki kat fazla olur
			(kucukdegersayac = 0);
			(dongu2 = 0);

		}

	}
	cout << "iyi gunler" << endl;
	system("pause");         // �al��t���n� g�rebilmek i�in durdurduk
	return 0;

}

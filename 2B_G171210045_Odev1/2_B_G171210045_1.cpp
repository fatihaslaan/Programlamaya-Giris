/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�:1
**				��RENC� ADI:Fatih Aslan
**				��RENC� NUMARASI:G171210045
**				DERS GRUBU:B
****************************************************************************/



#include "stdafx.h"
#include <iostream>                  //gerekli k�t�phaneler
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "turkish");
	int yildiz;
	int a, b;                          //ihtiya� duyuca��m de�erleri tan�mlad�m
	int k;                            //(a,b,k,s) saya� i�levi g�rmektedir bu y�zden uzun adlar�n� yazmad�m
	int s;
	int ucgen;
	int bosluk;
	ucgen = 1;
	bosluk = 5;
	//0 dan 24 e kadar sayd�rd�m ve bu s�rada * bast�rd�m
	for (int kolon = 0; kolon<24; kolon++)                //en �stteki kolon
		cout << "*";
	cout << endl;
	for (int sutun = 0; sutun<4; sutun++)              //g�vde
	{
		if (sutun == 0)
		{
			cout << "*SA� B�LG�SAYAR" << setw(9) << "*";       //g�vdenin ilk ad�m�nda yapmas� gereken
			cout << endl;
		}
		if (sutun == 1)                                         //g�vdenin ilk ad�m�nda ��gen yazd�rmaya ba�l�yoruz      
		{
			//d�ng�y� 5 kez d�nd�rerek h si 5 olan ��gen yapt�m
			for (k = 0; k<5; k++)
			{
				cout << "*";
				for (s = 0; s<bosluk; s++)                         //ne kadar bo�luk b�rak�ca��n� hesapl�yor
				{
					cout << " ";
				}
				{
					for (s = 0; s<ucgen; s++)           // y�ld�z� yaz�yor ama y�ld�z for d�ng�s�n�n sounda artaca��
					{                                              //i�in her seferinde daha fazla y�ld�z yazar
						cout << "*";
					}   //bo�lu�a bi�ilen de�erin iki kat� kadar bo�luk b�rakarak iki ��genin yan yana kalmas�n� sa�l�yor  
					for (s = 0; s<2 * bosluk; s++)                        // di�er y�ld�z� yazmas� i�in aradaki gerekli olucak bo�luk
						cout << " ";

					{
						for (s = 0; s<ucgen; s++)
							cout << "*";
						if (k == 0)
						{
							cout << setw(3);                //k���k y�ld�z i�in
															//k���k y�ld�z�n �st k�sm� i�in 3 kez sayd�r�p * koydurdum 
							for (b = 0; b<3; b++)              //sadece 0 da ve 1 de var
								cout << "*";
							cout << "*";
						}
						if (k == 1)
							cout << setw(5) << "* *";
					}
					if (1<k)                                          // bu y�zden 1 den b�y�k de�erlerde bo�luk var
						cout << setw(bosluk + 1) << "*";



					if (k == 4)                           //��genin alt�ndaki kolon
					{
						cout << endl;
						//0 dan 24e kadar sayd�rarak * bast�rd�m
						for (int i = 0; i<24; i++)
							cout << "*";
					}

					cout << endl;                    //bo�lu�u azalt�p y�ld�z� artt�r�yorum ki ��gen olsun
					(bosluk--);
					ucgen += 2;


				}


			}
		}
		if (sutun == 3)                   //alttaki ��genler i�in
		{
			bosluk = 5;
			ucgen = 1;
			// d�ng�n�n 5 kez d�nmesini sa�lad�m
			for (k = 0; k<5; k++)
			{
				cout << "*";
				//s 0 dan ba�l�yarak bo�lu�un de�eri kadar say�yor
				for (s = 0; s<bosluk; s++)
				{
					cout << " ";
				}
				{                //s 0 dan ba�layarak ��genin de�eri kadar say�yor
					for (s = 0; s<ucgen; s++)
					{
						cout << "*";
					}
					//bo�lu�a bi�ilen de�erin iki kat� kadar bo�luk b�rakarak iki ��genin yan yana kalmas�n� sa�l�yor    
					for (s = 0; s<2 * bosluk; s++)
					{
						if ((k == 0 && (s<5 && s>1)) || (k == 1 && s == 2))//k���k ��geni yazabilmek i�in binevi koordinat sistemiyle yazd�rd�m
							cout << "*";

						else
							cout << " ";
					}
					{
						for (s = 0; s<ucgen; s++)
							cout << "*";
					}


					cout << setw(bosluk + 1) << "*";
					if (k == 4)
					{
						cout << endl;
						for (int kolon = 0; kolon<24; kolon++)           //��genin alt kolonu
							cout << "*";
					}


					cout << endl;
					(bosluk--);
					ucgen += 2;


				}


			}
		}
		if (sutun == 2)
		{
			cout << "*M�HEND�SL��� B�L�M�" << setw(4) << "*";
			cout << endl;
		}

		cout << "*";
		//0 dan 22 ye kadar bo�luk koyuyor
		for (int z = 0; z<22; z++)
			cout << " ";
		cout << "*";
		cout << endl;

	}
	//kolon0 dan 24 e kadar say�yor ve y�ld�z koyuyor
	for (int kolon = 0; kolon<24; kolon++)        // ve son olarak en alt kolon
		cout << "*";

	cout << endl;

	system("pause");

	return 0;
}
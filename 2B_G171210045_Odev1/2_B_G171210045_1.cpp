/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…:1
**				ÖÐRENCÝ ADI:Fatih Aslan
**				ÖÐRENCÝ NUMARASI:G171210045
**				DERS GRUBU:B
****************************************************************************/



#include "stdafx.h"
#include <iostream>                  //gerekli kütüphaneler
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "turkish");
	int yildiz;
	int a, b;                          //ihtiyaç duyucaðým deðerleri tanýmladým
	int k;                            //(a,b,k,s) sayaç iþlevi görmektedir bu yüzden uzun adlarýný yazmadým
	int s;
	int ucgen;
	int bosluk;
	ucgen = 1;
	bosluk = 5;
	//0 dan 24 e kadar saydýrdým ve bu sýrada * bastýrdým
	for (int kolon = 0; kolon<24; kolon++)                //en üstteki kolon
		cout << "*";
	cout << endl;
	for (int sutun = 0; sutun<4; sutun++)              //gövde
	{
		if (sutun == 0)
		{
			cout << "*SAÜ BÝLGÝSAYAR" << setw(9) << "*";       //gövdenin ilk adýmýnda yapmasý gereken
			cout << endl;
		}
		if (sutun == 1)                                         //gövdenin ilk adýmýnda üçgen yazdýrmaya baþlýyoruz      
		{
			//döngüyü 5 kez döndürerek h si 5 olan üçgen yaptým
			for (k = 0; k<5; k++)
			{
				cout << "*";
				for (s = 0; s<bosluk; s++)                         //ne kadar boþluk býrakýcaðýný hesaplýyor
				{
					cout << " ";
				}
				{
					for (s = 0; s<ucgen; s++)           // yýldýzý yazýyor ama yýldýz for döngüsünün sounda artacaðý
					{                                              //için her seferinde daha fazla yýldýz yazar
						cout << "*";
					}   //boþluða biçilen deðerin iki katý kadar boþluk býrakarak iki üçgenin yan yana kalmasýný saðlýyor  
					for (s = 0; s<2 * bosluk; s++)                        // diðer yýldýzý yazmasý için aradaki gerekli olucak boþluk
						cout << " ";

					{
						for (s = 0; s<ucgen; s++)
							cout << "*";
						if (k == 0)
						{
							cout << setw(3);                //küçük yýldýz için
															//küçük yýldýzýn üst kýsmý için 3 kez saydýrýp * koydurdum 
							for (b = 0; b<3; b++)              //sadece 0 da ve 1 de var
								cout << "*";
							cout << "*";
						}
						if (k == 1)
							cout << setw(5) << "* *";
					}
					if (1<k)                                          // bu yüzden 1 den büyük deðerlerde boþluk var
						cout << setw(bosluk + 1) << "*";



					if (k == 4)                           //üçgenin altýndaki kolon
					{
						cout << endl;
						//0 dan 24e kadar saydýrarak * bastýrdým
						for (int i = 0; i<24; i++)
							cout << "*";
					}

					cout << endl;                    //boþluðu azaltýp yýldýzý arttýrýyorum ki üçgen olsun
					(bosluk--);
					ucgen += 2;


				}


			}
		}
		if (sutun == 3)                   //alttaki üçgenler için
		{
			bosluk = 5;
			ucgen = 1;
			// döngünün 5 kez dönmesini saðladým
			for (k = 0; k<5; k++)
			{
				cout << "*";
				//s 0 dan baþlýyarak boþluðun deðeri kadar sayýyor
				for (s = 0; s<bosluk; s++)
				{
					cout << " ";
				}
				{                //s 0 dan baþlayarak üçgenin deðeri kadar sayýyor
					for (s = 0; s<ucgen; s++)
					{
						cout << "*";
					}
					//boþluða biçilen deðerin iki katý kadar boþluk býrakarak iki üçgenin yan yana kalmasýný saðlýyor    
					for (s = 0; s<2 * bosluk; s++)
					{
						if ((k == 0 && (s<5 && s>1)) || (k == 1 && s == 2))//küçük üçgeni yazabilmek için binevi koordinat sistemiyle yazdýrdým
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
						for (int kolon = 0; kolon<24; kolon++)           //üçgenin alt kolonu
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
			cout << "*MÜHENDÝSLÝÐÝ BÖLÜMÜ" << setw(4) << "*";
			cout << endl;
		}

		cout << "*";
		//0 dan 22 ye kadar boþluk koyuyor
		for (int z = 0; z<22; z++)
			cout << " ";
		cout << "*";
		cout << endl;

	}
	//kolon0 dan 24 e kadar sayýyor ve yýldýz koyuyor
	for (int kolon = 0; kolon<24; kolon++)        // ve son olarak en alt kolon
		cout << "*";

	cout << endl;

	system("pause");

	return 0;
}
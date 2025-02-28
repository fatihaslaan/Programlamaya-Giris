/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:1.02
**				ÖĞRENCİ ADI...............:Fatih Aslan
**				ÖĞRENCİ NUMARASI.:G171210045
**				DERS GRUBU…………:1-C
****************************************************************************/

#include "pch.h"
#include <iostream>
#include <string>
#include <locale.h> //türkçe karakter için

using namespace std;


void harf(string cumle);   //fonksiyonları tanımladık
void yazdir();

string cumle; //girilcek cümle
char dizi[8] = { 'a','e','o','u','i','ö','ü','ı' }; // aratmak istediğimiz harfler
char buyukdizi[8] = { 'A','E','O','U','İ','Ö','Ü','I' };
int sayaclar[8]; //her harfin sayacı
int maxharf; // en fazla olan harfin sayısını öğrendik

int main()
{
	setlocale(LC_ALL, "turkish");	//türkçe yi kurduk
	cout << "Sesli harflerini öğrenmek istediğiniz cümleyi girin:";
	getline(cin, cumle); // cümleyi aldık
	cout << endl;
	harf(cumle);
	yazdir();	
}

void harf(string cumle)
{	
	for (int i = 0; i < 8; i++) //dizinin uzunluğu kadar döngü
	{
		for (int j = 0; j < cumle.length(); j++) //cümlenin uzunluğu kadar döngü
		{
			if (cumle[j] == dizi[i] && i < 5|| cumle[j] == buyukdizi[i] &&i<4) //cümlenin içinde sırayla harfleri arıyor 
			{
				sayaclar[i]++;
			}
			else if(cumle[j] ==-104 &&i==4)          //büyük i için
				sayaclar[i]++;
			else if (((cumle[j] == -108)||(cumle[j]==-103))&&i==5)   //aynı anda hem büyüğü hem küçüğü kontrol ediyor
				sayaclar[i]++;                  //türkçe karakteri kurmama rağmen ü ö ve ı girildiğinde string de boş gösterip yandaki değerler çıkıyordu ben de 
			else if ((cumle[j] == -127||cumle[j]==-102)&&i==6)    // ne kadar hoş durmasa da böyle bir yol kullandım yandaki değerler sırasıyla 'ö','ü' ve 'ı' nınkiler
				sayaclar[i]++;
			else if ((cumle[j] == -115||cumle[j]==buyukdizi[i])&&i==7)
				sayaclar[i]++;
		}
		if (sayaclar[i] > maxharf)
			maxharf = sayaclar[i];   //programda gördüğüm kadarıyla en çok olan sesli harfin sayacı isteniyordu
	}
}

void yazdir()
{	
	cout <<endl<< "H   TS ";                               //çıktının ilk kısımları
	for (int i = 1; i <= maxharf; i++)
	{
		cout << i << " ";                     //en çok olan sesli harfin sayısı
	}
	cout << endl;
	for (int j = 0; j < 8; j++)
	{
		cout << dizi[j] << "   " << sayaclar[j] << "  ";                 //sırasıyla harfleri yazdırdık  
		for (int i = 0; i < sayaclar[j]; i++)                            //diziyle sayaclar aynı sırada kaydettiğim için ikisini de aynı anda okuttum
		{
			cout << dizi[j] << " ";
		}
		cout << endl;
	}	
}



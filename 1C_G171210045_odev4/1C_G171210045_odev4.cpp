/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:4
**				ÖĞRENCİ ADI...............:Fatih Aslan
**				ÖĞRENCİ NUMARASI.:G171210045
**				DERS GRUBU…………:1-C
****************************************************************************/
#include "pch.h"
#include <iostream>
#include <string>           //gerekli kütüphaneler

using namespace std;

void baslangic();    //önceden tanımladık

#ifndef Sifre_h
#define Sifre_h
class Sifre
{
public:

	Sifre(char* ilkalfabe, char* sifre)
	{
		alfabe = ilkalfabe;      //girilen alfabeyi kurucuda atadık
		sifrekelimesi = sifre;    //şifremizi atadık
	};

	Sifre()
	{
		char varsayilan[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		alfabe = varsayilan;        //varsayılan alfabe
	};

	char* sifrele(char* sifrelencekmetin) 
	{
		int geciciuzunluk = string(sifrekelimesi).size();  //şifremizin uzunluğunu alıyoruz

		for (size_t i = 0; i < string(sifrelencekmetin).size(); i++)  //her karakteri teker teker şifreliyoruz
		{
			sifrekelimesi[i] = sifrekelimesi[i % geciciuzunluk];//kelimemizin uzunluğu kadar dizi oluşturduk
			sifrelencekmetin[i] = alfabe[(int(sifrelencekmetin[i])-65+int(sifrekelimesi[i]) - 64) % string(alfabe).size()];  //şifremizi ascii codeları sayesinde yapıyoruz
		}
		return sifrelencekmetin;
	};

	char* sifrecoz(char* sifresicozulecekmetin) 
	{
		for (size_t i = 0; i < string(sifresicozulecekmetin).size(); i++) //kelimemizin uzunluğu kadar for
		{
			sifresicozulecekmetin[i] = alfabe[((sifresicozulecekmetin[i] - sifrekelimesi[i] - 1)+ string(alfabe).size())%string(alfabe).size()];   //yine ascii kodlarıyla şifremizi çözüyoruz
		}
		return sifresicozulecekmetin; //çözdükten sonra geri döndürüyoruz
	};	

	void sifrekelimesiata(char* sifre) 
	{
		sifrekelimesi = sifre;  //şifremizi atıyoruz
	}

private:

	char* alfabe;
	char* sifrekelimesi;  //şifre

};
#endif	

char ilkalfabe[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";        //gerekli değişkenlerimiz
char sifre[100];
char metin[100];

int main()
{	
	baslangic();
	Sifre*s = new Sifre(ilkalfabe, sifre);// alfabeyi ve şifreyi veriyoruz
	cout << endl << endl << "Sifrelenmis Metin:" << s->sifrele(metin);        //fonksiyonda verilenleri yazdırıyoruz
	cout << endl << "Sifresi Cozulmus Metin:" << s->sifrecoz(metin) << endl << endl;  //şifreli kelimeyi geri çözüyoruz
}

void baslangic()
{
	cout<< "Lutfen Sifre Icin Bir Alfabe Girin" << endl << "=>";   //başlangıç fonksiyonumuz eğer boş bırakılırsa varsayıla alfabe kullanılacak
	cin >> ilkalfabe;
	cout << endl << "Sifre Girin" << endl << "=>";   //şifre giriyoruz
	cin>>sifre;
	cout << endl << "Sifrelenicek Kelimeyi Girin" << endl << "=>";  //şifrelenicek kelime
	cin>>metin;
};



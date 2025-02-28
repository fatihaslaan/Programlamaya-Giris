/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…:3
**				ÖĞRENCİ ADI:Fatih Aslan
**				ÖĞRENCİ NUMARASI:G171210045
**				DERS GRUBU:B
****************************************************************************/
#include "stdafx.h"                   //gerekli kütüphaneler
#include <iostream>                         
#include <string>                           //string kullanmak için gerekli kütüphane

using namespace std;
void cumlegir();
void cumleozellikleri();                       //gerekli olan fonksiyonlarımızı tanımladık
void noktalama();
void kelimelerharf();
void kelimelersesliharf();
bool palindrommu(string cumle);
void palindrom();
int uzunluk;

struct cumle1
{
	string cumle;                                //cümle yapısı sayesinde kolaylık sağladık
	int kelime = 1;
	int harf = 0;
	int kelimeharf = 0;
	int noktalamasayac = 0;
	int sesliharf = 0;
}c;                                                    //cumle isimli structımızı kolay çağırmak için c ye atadık

int main()
{        
	cumlegir();
	uzunluk = c.cumle.length();                        //fonksiyonlarımızı çağırdık ve cümlenin uzunluğunu uzunluk isimli ögeye aktardık
	cumleozellikleri();
	noktalama();
	kelimelerharf();
	kelimelersesliharf();
	palindrommu(c.cumle);
	if (palindrommu(c.cumle))                                //booldan dönen değer doğruysa veya yanlışsa olcakları belirledik
		cout << "cumle palindromdur" << endl;
	else cout << "cumle palindrom degildir" << endl;
	palindrom();
	system("pause");
	return 0;
}

void cumlegir()
{
	cout << "lutfen bir cumle girin(turkce karakter olmasin ve bitirince bosluk tusuna basin):" << endl;
	getline(cin, c.cumle);                                        //girilen cumleyi string cumleye aktardık
}

void cumleozellikleri()
{
	for (int i = 0; i <uzunluk; i++)                               //cumlenin uzunlugu kadar foru tekrar ettirerek i nin her artışında istenileni arattık
	{

		if (c.cumle[i] != ' ')                   //boşluk dışında bişeye basıldıysa harf sayıyor
		{
			c.harf += 1;
		}
		else if (c.cumle[i] == ' ')             // boşluğa basıldığında kelime sayısını arttırıyor
		{
			c.kelime += 1;
		}

	}
	cout << "cumledeki harf sayisi:" << c.harf << "\n" << "cumledeki kelime sayisi:" << c.kelime - 1 << "\n" << "cumledeki noktalama isaretleri:";
}

void noktalama()
{
	for (int i = 0; i < uzunluk; i++)                     // cümlenin uzunluğu kadar tarattık
	{
		if (c.cumle[i] == '.')                                //her bir noktalama işaretli için sayac saydırdık ve basılmaları durumunda ekrana yazdırdık
			cout << ".";

		if (c.cumle[i] == '?')
			cout << "?";
		
		if (c.cumle[i] == ',')
			cout << ",";
		
		if (c.cumle[i] == '!')
			cout << "!";		
	}
	cout << endl;
}

void kelimelerharf()
{
	int a = 0;                                               //sadece bu fonksiyonda geçerli olan bir değer
	cout << "kelimelerdeki harf sayisi" << endl;
	for (int i = 0; i <uzunluk; i++)
	{

		if (c.cumle[i] == ' ')                                       //boşluk girildiğinde kelimeyi inceliyor
		{
			c.kelimeharf = 0;

			for (int j = 0; j < i - a; j++)                                              //ikinci kelimeye geçtiğinde uzunluktan ilk kelimenin uzunluğunu çıkararak sonuncu kelimenin harfini buluyor
			{
				c.kelimeharf += 1;                                             //kelimedeki harfleri boşluk girilene kadar deniyoruz
			}
			a = i + 1;                                                   // sıradaki harfe geçmesi için a ya inin değerini verdik
			cout << c.cumle[i] << ":" << c.kelimeharf << endl;                      //kelimeyi ve kaç harfi olduğunu gösteriyor
		}
		else cout << c.cumle[i];                                                             //boşluğa basılmadı sürece kelimeyi yazmaya devam ediyor
	}
	cout << endl;
}

void kelimelersesliharf()
{
	int a = 0;
	cout << "kelimelerdeki sesli harf sayisi:" << endl;
	for (int i = 0; i <uzunluk; i++)                  
	{                                                       //cümledeki boşlugu bulmak için cumlenin uzunlugu kadar for dçndürüyoruz
		if (c.cumle[i] == ' ')
		{
			c.sesliharf = 0;
			for (int z = a; z <= i; z++)                               //kelimenin içini tarıyoruz 
			{
				if (c.cumle[z] == 'a' || c.cumle[z] == 'e' || c.cumle[z] == 'i' || c.cumle[z] == 'u' || c.cumle[z] == 'o' || c.cumle[z] == 'A' || c.cumle[z] == 'E' || c.cumle[z] == 'I' || c.cumle[z] == 'U' || c.cumle[z] == 'O')
				{                                        //sesli harf gördüğünde sayacı arttırıyo
					c.sesliharf += 1;
				}
			}
			a = i + 1;                           //bidahaki cümleye gecmesini saglıyoruz
			cout << c.cumle[i] << ":" << c.sesliharf << endl;               //kelimeyi ve kaç tane sesli harfi oldugunu yazıyoruz
		}
		else cout << c.cumle[i];                           //boşluk yoksa kelimeyi yazdırmaya devam ediyor
	}
	cout << endl;
}

bool palindrommu(string cumle)
{
	size_t i = 0;                                     //i ve j ye palindrom olup olmadıklarını test etmek için deger verdik
	size_t j = cumle.length() - 2;
	while (i < j)
	{
		if (cumle[i++] == cumle[j--])                          //j sondan i baştan harflerin aynı olup olmadıgını deniyor
			return true;
		return false;
	}
}

void palindrom()
{
	int sayac = 0;                     //sadece bu fonksiyonda kullanıcagımız ve bize gerekli olan öğeler
	int a = 0;

	cout << "palindrom olan kelimeler:" << endl;
	for (int i = 1; i <= uzunluk; i++)
	{
		if (c.cumle[i] == ' ')                            //diziyi tarayıp boşluk buldugunda kelimeyi inceliyoruz
		{
			while (sayac <i)
			{
				if (c.cumle[sayac] == c.cumle[i - a - 1])          // incelediğimiz kelimenin son harfiyle ilk harfini kontrol ediyo ve ilk harfi arttırıp son harfi azaltarak harfleri kontrol ediyo
					for (sayac; sayac <= i; sayac++)       
					{
						cout << c.cumle[sayac];        //kelimeyi yazdırıyor
						a++;                        // dizinin sonunu azaltarak kelimeyi kontrol etmeye devam ediyo
					}
				sayac = i + 1;          //bi sonraki kelimeye geçmek için
				a = 0;                         //başka kelimeler için sıfırlıyoruz
			}
		}
	}
	cout << endl;
}
/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:1.01
**				ÖĞRENCİ ADI...............:Fatih Aslan
**				ÖĞRENCİ NUMARASI.:G171210045
**				DERS GRUBU…………:1-C
****************************************************************************/


#include "pch.h"
#include <iostream>      //gerekli kütüphanelerimiz

using namespace std;

void kontrol(int deger);
void yildiz();
void bosluk();                //kullanıcağımız fonksiyonlar
void kareciz();            //kareyi mainde tek satırda çizmek için

int uzunluk = 5;       //uzunluğumuzu tanımladık istersek kullanıcıdan da alabiliriz
int yildizsayisi = uzunluk;  //hesaplar
int bosluksayisi = 1;      //boşluk sayısını tanımladık

int main()
{	
	kareciz();    //kareyi fonksiyonla çiziyoruz ki bi daha çizmek istersek fonksiyonu bi kez daha yazmak yeter
}

void kareciz()
{
	for (int i = 0; i < 2 * uzunluk + 1; i++)   //karenin uzunluğu kadar işlem yapıcak
	{
		yildiz();    //karenin ilk yarısında belirli ölçüde yıldız basıyor
		bosluk();    //karenin ortasındaki boşluk sayısını hesaplayıp o kadar boşluk döndürecek
		yildiz();
		kontrol(i);   //değerleri kontrol edip ona göre yıldızları ve boşlukları tekrar hesaplıyor
	}
}

void kontrol(int deger)
{
	if (deger < uzunluk) 
	{
		bosluksayisi=bosluksayisi+2;    //döngünün yerine göre yıldızları arttırıp arttırmamasına veya boşlukları arttırıp azaltması gerekiyor
		yildizsayisi = yildizsayisi - 1;
	}
	else if(deger>=uzunluk)
	{
		bosluksayisi = bosluksayisi - 2;
		yildizsayisi = yildizsayisi + 1;
	}
	cout << endl;
}

void yildiz() 
{
	for (int i = 0; i < yildizsayisi; i++)    //yıldız sayısı kadar yıldız basıcak
	{
		cout << "*";     //yıldız basıcak
	}
}

void bosluk()
{
	for (int i = 0; i < bosluksayisi; i++)//boşluk sayısı kadar boşluk basıcak
	{
		cout << " ";
	}
}

/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…:4
**				ÖĞRENCİ ADI:Fatih Aslan
**				ÖĞRENCİ NUMARASI:G171210045
**				DERS GRUBU:B
****************************************************************************/

#include "stdafx.h"                             //gerekli kütüphaneler
#include<iostream>
#include<ctime>                                 //her seferinde farklı sayı degerleri vermesi için

using namespace std;
int sayac = 0;
const int a = 10;                                        //**koddaki herşeyi a ve b değiştirilip modu ona uygun yazıldıgında çalışıcak şekilde hazırladım**
const int b = 10;                                          
void olustur();
void matrisyaz();                                                //kullanıcağımız fonksiyonları tanımladık
bool elemankontrol(int a);
void sırala();
int dizi[a][b];
int i, j;

int main()
{
	srand(time(0));                     // random verilcek değerleri değiştirmesi için 
	olustur();                                               //matrisimizi oluşturacak fonksiyon
	cout << "Toplam rasgele cagirimm adedi=" << sayac << endl;
	matrisyaz();
	cout << endl << endl << endl << endl;
	sırala();

	system("pause");

	return 0;
}

void olustur()
{
	for (i = 0; i < a; i++)                        //sutun sayısı
	{
		for (j = 0; j < b; j++)                 //satır sayısı
		{
			sayac++;                                      //toplam rasgele çağırma adeti
			dizi[i][j] = rand() % 100 + 1;                      //dizinin inci sutun jnci satırına rasgele elaman atıyor

			if (elemankontrol(dizi[i][j]))                           //attıgı eleman dizide varmı diye kontrol ediyor
			{
				if (j == 0)                       //varsa ve satır degeri sıfırsa bir önceki sutuna gidiyor
				{
					i--;
					j += a;
				}
				else                              //satır degeri 0 degilse bir geri gidiyor ve o satıra tekrar bir deger atamasını istiyor
					j--;
			}
		}
	}
}

void matrisyaz()
{
	cout << "Rasgele olusan ve elemanlari birbirinden farkli olan matris" << endl;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			cout << dizi[i][j] << " ";                                 //matrisi sutun ve satır sayısınca yazdırıyor
		}
		cout << endl;
	}
}

bool elemankontrol(int a)
{
	int kontrol2 = 0;
	for (kontrol2; kontrol2 < j; kontrol2++)                          //eger satır degeri 3 sutun degeri 2yse sadece o satırda 3 e kadar bakıyor
	{
		if (dizi[i][kontrol2] == a)
			return true;
	}

	for (int kontrol1 = 0; kontrol1 < i; kontrol1++)                       //bunun sayesinde her satırda 3 e kadar saymasını önlüyoruz ve önceki satırları komple taramasını istiyoruz
	{
		int satır2 = 0;
		for (satır2; satır2 <b; satır2++)
		{
			if (dizi[kontrol1][satır2] == a)
				return true;
		}
	}

	return false;                                         //eger yukardaki durunmlar sağlanmıyorsa false degerini döndürsün
}

void sırala()
{
	int gecici =0;                                               //bizim geçici değerimiz
	int duzmatris[a*b] = {};                                            //matrisdeki değer sayısı kadar bir düzmatris yaptımki sıralamak kolaylaşsın
	cout << "Buyukten Kucuge Siralanmis Matris" << endl;
	for (int z = 0; z < a*b; z++)                                            //matrisdeki eleman kadar saydırdım ki sıralayabileyim
	{
		for (i = 0; i < a; i++)
		{                                                                            //matrisi arıyor
			for (j = 0; j < b; j++)
			{
				
					if (dizi[i][j]<duzmatris[z-1]||z==0)                                 //eğer z sıfırsa zye henüz bir değer girilmemiştir bu yüzden z 0 ken taramalı
					{                                                                  //eğer z sıfır değilse düz matrisde muhakkak bir eleman vardır z yi azaltmamın sebebi 
							if (dizi[i][j] > gecici)                                     //z nin güncel değerinin sıfır olması ama bir öncekinde bir değer var ve burdada 
							{                                                            //eğer gecicimiz duzmatrisdeki elemandan kücükse tarasın
								gecici = dizi[i][j];                               //eğer o konumdaki değer gecicinin güncel değerinden büyükse artık yeni gecicimiz o
							}
					}
				
				
			}
		}
		duzmatris[z] = gecici;                                                     //z nin güncel değerine gecicimizi aktarıyoruz
		cout << gecici<<" ";
		if (gecici % 10-1 == 0 && gecici !=duzmatris[0])                             //ilk eleman hariç diğer elemanların belli bir düzende alt satıra geçmesini sağlıyoruz
			cout << endl;
		gecici =0;                                                               //ve geçicimizi sıfırlıyoruz ki kaldığı yerden devam etmesin
	}
}

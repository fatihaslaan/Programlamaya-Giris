/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:3
**				ÖĞRENCİ ADI...............:Fatih Aslan
**				ÖĞRENCİ NUMARASI.:G171210045
**				DERS GRUBU…………:1-C
****************************************************************************/
#include "pch.h"
#include <iostream>
#include <iomanip>

using namespace std;

struct Islem
{
private:   //kullanıcının ihtiyaç duymayacağı veriler

	int giris[5][5]={3,2,5,1,4,
					 6,2,1,0,7,       //matrisi tanımladık
					 3,0,0,2,0,
					 1,1,3,2,2,
					 0,3,1,0,0};
	int girisbuyukluk;   //tanımlanan matrisin büyüklüğü
	int cekirdekbuyuklugu; //çekirdek büyüklüğü
	int matrisbuyukluk;   //sonuç matrisinin büyüklüğü
	int **cekirdek;   //dinamik array için bu şekilde cekirdek matrisi tanımladık
	int **matris;     //dinamik matrisi tanımladık
	int kayma;    //kayma

	void olustur()
	{
		cekirdek = new int *[cekirdekbuyuklugu];       //2 boyutlu dinamik array için
		for (size_t i = 0; i < cekirdekbuyuklugu; i++)
		{                                                  //çekirdek matrisimizi oluşturduk
			cekirdek[i] = new int [cekirdekbuyuklugu];
		}
	}
	                                              //bu fonksiyonları mainde çağırmamıza ihtiyaç olmadığı için private da tanımladık
	void sonucmatrisolustur()
	{
		matrisbuyukluk = ((girisbuyukluk - cekirdekbuyuklugu) / kayma) + 1;    //yaptığımız hesapla matrisimizin boyutunu öğrendik
		matris = new int *[matrisbuyukluk];       // sonuç matrisimizi oluşturuyoruz
		for (size_t i = 0; i < matrisbuyukluk; i++)
		{
			matris[i] = new int[matrisbuyukluk];  
		}
		for (size_t i = 0; i < matrisbuyukluk; i++)
		{
			for (size_t j = 0; j < matrisbuyukluk; j++)
			{                                               //yaptığımız işlemde lazım olucağından ilk değerlerini 0 atıyoruz
				matris[i][j] = 0;
			}
		}
	}

	void cekirdekata()
	{
		for (size_t i = 0; i < cekirdekbuyuklugu; i++)
		{
			for (size_t j = 0; j < cekirdekbuyuklugu; j++)
			{
				cout << endl << "cekirdek[" << i << "][" << j << "]=";  //kullanıcıdan çekirdek değerlerini girmesini istiyoruz
				cin >> cekirdek[i][j];
			}
		}
	}

	bool hesaplanirmi()
	{
		int gecici = 0;
		girisbuyukluk = sizeof(giris) / sizeof(giris[0]); //bize verilen matrisin büyüklüğünü bulduk
		gecici = girisbuyukluk - cekirdekbuyuklugu;   //bize verilen matrisin büyüklüğünden çekirdeği çıkartıp
		while (gecici != 0)
		{
			gecici= gecici-kayma;             //sürekli kayma işlemi yaparak matrisin dışına çıkıcakmı diye bakıyoruz
			if (gecici < 0)
				return false;
		}
		return true;
	}

	void hesapla()
	{		
		for (size_t i = 0; (i+cekirdekbuyuklugu) <= girisbuyukluk; i=i+kayma)              //iyi kayma kadar arttırıp i+cekirdek büyüklüğünün girisbüyüklüğünden küçük olmamasına dikkat ediyoruz
		{
			for (size_t j = 0; (j+cekirdekbuyuklugu) <= girisbuyukluk; j=j+kayma)
			{
				for (size_t z = 0; z < cekirdekbuyuklugu; z++)
				{
					for (size_t x = 0; x < cekirdekbuyuklugu; x++)
					{
						matris[i/kayma][j/kayma] =matris[i/kayma][j/kayma]+(giris[i + z][j + x] * cekirdek[z][x]); //sonuç matrisini hesaplıyoruz
					}
				}
			}
		}
	}

	void yaz() 
	{
		cout << endl<<"Sonuc Matrisi:"<<endl;
		for (size_t i = 0; i < matrisbuyukluk; i++)
		{
			for (size_t j = 0; j < matrisbuyukluk; j++)
			{
				cout<<setw(4)<< matris[i][j] << setw(8);    //sonuç matrisini düzenli şekilde yazdırıyoruz
			}
			cout << endl;
		}
	}

public:

	void basla()
	{
		cout << "cekirdek boyutunu giriniz:";
		cin >> cekirdekbuyuklugu;
		olustur();  //çekirdeği oluşturuyoruz
		cout << endl << "kayma miktarini giriniz:";
		cin >> kayma;
		if (hesaplanirmi()) //hesaplanırmı diye bakıyoruz
		{
			cekirdekata();  //çekirdek değerlerini alıyoruz
			sonucmatrisolustur(); //sonuçmatrisi oluşturuyoruz
			hesapla(); //değeri hesaplıyoruz
			yaz(); //ve yazdırıyoruz
		}
		else
			cout << endl << "Hesaplanamaz!";
	}

};

int main()
{
	Islem *i = new Islem(); //islemden bir nesne tanımladık
	i->basla(); //işlemi başlattık
}


/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:2
**				ÖĞRENCİ ADI...............:Fatih Aslan
**				ÖĞRENCİ NUMARASI.:G171210045
**				DERS GRUBU…………:1-C
****************************************************************************/

#include "pch.h"
#include <iostream>
#include <ctime>       //her çalıştığında farklı değer gelmesi için
using namespace std;

const int sutun = 5;     //1 sütündaki eleman sayısı
const int satir = 10;      //1 satırdaki eleman sayısı
char matris[sutun][satir];  //karakter matrisini tanımladık

void randomata();         //matrisi rasgele dolduruyoruz
bool kontrol(char varmi,int csutun,int csatir); // daha önce bu karakter kullanılmışmı diye baktık 
void yazdir();  //matrisi yazdırdık
void sirala();  //matrisi sıraladık

int main()
{
	srand(time(NULL));  //her seferinde farklı karkaterler için
	randomata();  //rasgele doldurduk
	cout << "Tekrarsiz ve Rasgele Dizi:"<<endl;
	yazdir(); //matrisi yazdırdık
	sirala();  //matrisi sıraladık
	cout << "Siralanmis Dizi" << endl;
	yazdir();
}

void randomata()
{
	for (int i = 0; i < sutun; i++) //sütün kadar döndürdük
	{
		for (int j = 0; j < satir; j++) //satır kadar döndürdük
		{
			if (j%2==0)
			{
				matris[i][j] = rand() % 26 + 65; //eğer çüftse büyük harfler
			}
			else
			{
				matris[i][j] = rand() % 26 + 97; //değilse küçük harfler atadık
			}
			if (kontrol(matris[i][j], i, j))  //sutun ve satırı gönderip karakter o sutun veya satır dışında herhangi bi yerde 
			{                              //varsa for döngüsünde bir geri gelerek tekrar atatıyor
				if(j!=0)
					j--;
				else
				{
					i--;
					j += 9;
				}
			}
		}
	}
}

bool kontrol(char varmi,int csutun,int csatir)
{
	for (int i = 0; i < sutun; i++)
	{
		for (int j = 0; j < satir; j++)
		{
			if (matris[i][j] == varmi&&(csutun!=i||csatir!=j))
				return true;                 //o satır veya sutun dışında bir yerde ise tekrar ettiğini anlıyoruz
			if (matris[i][j] == NULL)
				break;
		}
		if (matris[i][0] == NULL)    //eğer matris boşssa direk çıkması için
			break;
	}
	return false;
}

void sirala()
{
	char gecici;      //değiştirmek için geçici bir karakter
	for (int i = 0; i < sutun; i++)
	{
		for (int j = 0; j < satir; j++)
		{
			if (j < satir-1)    //son satır değilse
			{
				if (matris[i][j] > matris[i][j + 1])   //eğer bir sonraki karakter daha küçükse
				{
					gecici = matris[i][j + 1];
					matris[i][j + 1] = matris[i][j];  //yer değiştiriyoruz
					matris[i][j] = gecici;
					i = 0;
					j = -1;   //ve matrisi baştan kontrol ettiriyoruz
				}
			}
			else //satırdaki son elemansa
			{
				if (matris[i + 1][0] != NULL)  //matristeki son eleman değilse
				{
					if (matris[i][j] > matris[i + 1][j - (satir - 1)])    
					{
						gecici = matris[i + 1][j - (satir-1)];
						matris[i + 1][j - (satir - 1)] = matris[i][j];
						matris[i][j] = gecici;
						i = 0;
						j = -1;
					}
				}
			}
		}
	}

}

void yazdir()
{
	for (int i = 0; i < sutun; i++)
	{
		for (int j = 0; j < satir; j++)
		{
			cout << matris[i][j] << " ";  //sırasıyla yazdırıyoruz
		}
		cout << endl;
	}
}


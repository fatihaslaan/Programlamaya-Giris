/****************************************************************************
**					  SAKARYA ÜNİVERSİTESİ
**			      BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				      BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				  PROGRAMLAMAYA GİRİŞ DERSİ
**                     2017-2018 GÜZ DÖNEMİ
**				ÖDEV NUMARASI…:1.PROJE
**				ÖĞRENCİ ADI:Fatih Aslan
**				ÖĞRENCİ NUMARASI:G171210045
**				DERS GRUBU:B
****************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <fstream>       // dosyalama için gerekli kütüphane
#include <string>        //string işlemleri için
#include <string.h>       //stringde satırdan sonrasını okuma için
#include <locale.h>         //türkçe dili için          

using namespace std;
void otelislemleri();                //gereken fonksiyonlarımız
void odaislemleri();
void musteriislemleri();
void odakayitislemleri();
void dizidoldur();                         //dosyadakileri okayarak diziye atar bçylelikle aynı numarayı bidaha girmeyiz
void odakayıtsil();                        //oda silince oda kayıtta varsa onuda siler
void müşterikayıtsil();                    //müşteri silince oda kayıtta varsa onuda siler
int secim = 0;                            // menü geçişleri için
int dongu = 1;                            //dizilerimiz için
int dongu2 = 1;
int dongu3 = 1;
int dongu4 = 1;
char cevap;                      
int odalar[10000];                         //aynı numaraları bidaha girmememiz için gereken diziler
int odalarkayıt[10000];
int müşteriler[10000];
int müşterilerkayıt[10000];
string oku, oku1, oku2, oku3, oku4, oku5, oku6, oku7;       //dosyadan okunulcak stringler
ofstream DosyaYaz;                     //offstreamin adını değiştirdik
ifstream DosyaOku;                       //ifstreamin adını değiştirdik

struct oda {
	string odanumara;                //oda özellikleri
	string odaücret;               
}o;

struct müşteri {
	string müşterinumara;
	string müşteritc;                    //müşteri özellikleri
	string müşteriad;
	string müşterisoyad;
}m;

int main()
{
	setlocale(LC_ALL, "Turkish");
	dizidoldur();                       //dosyadan numaraları çekiyor ve aynı numarayı diziyi kontrol ettiği için giremiyoruz
	otelislemleri();                    //ana fonksiyonumuza giriş
	system("pause");
	return 0;
}

void dizidoldur() 
{
	DosyaOku.open("Odalar.txt");                                            //odalar dosyamızı açıyor ve eğer içieride oda varsa numarasını odalar dizinine aktarıyor
	while (DosyaOku.good() && DosyaOku >> oku6&& DosyaOku >> oku7)
	{
		odalar[dongu] = stoi(oku6.substr(14, (oku6.length() - 14)));                         //burda stoiyle stringi inte çevirdik ve ardından 14. satırdan sonra numaranın uzunluğu
		dongu++;                                                                         //kadar sayıyı numara kabul edip diziye aktarmasını istedik ardından donguyu arttırdıkki
	}                                                                                     //dizinin diğer elemanına geçelim
	DosyaOku.close();                                                                     //dosyamızı kapattık
	DosyaOku.open("Müşteriler.txt");
	while (DosyaOku.good() && DosyaOku >> oku && DosyaOku >> oku1 && DosyaOku >> oku2 && DosyaOku >> oku3)                  //aynı yöntemle müşterinumarasını aldık
	{
		müşteriler[dongu2] = stoi(oku.substr(18, (oku.length() - 18)));
		dongu2++;
	}
	DosyaOku.close();
	DosyaOku.open("OdaKayıt.txt");
	while (DosyaOku.good() && DosyaOku >> oku4&& DosyaOku >> oku5)                                         //aynı yöntemle oda kayıtı aldık
	{
		odalarkayıt[dongu3] = stoi(oku4.substr(14, (oku4.length() - 14)));
		dongu3++;
		müşterilerkayıt[dongu4] = stoi(oku5.substr(16, (oku5.length() - 16)));
		dongu4++;
	}
	DosyaOku.close();
}

void otelislemleri()
{
	cout << "Otel İşlemleri" << endl;
	for (int i = 1; i < 20; i++)
		cout << "-";
	cout << "\n1- Oda İşlemleri" << endl;
	cout << "2- Müşteri İşlemleri" << endl;
	cout << "3- Oda Kayıt İşlemleri" << endl;
	cout << "99- Çıkış" << endl;                                            //menümüz
	cout << "Seçiminiz:";
	cin >> secim;
	switch (secim)
	{
	case 1:
		system("cls");
		odaislemleri();                                 //seçeneklere göre gidilecek fonksiyonlar
		break;
	case 2:
		system("cls");
		musteriislemleri();
		break;
	case 3:
		system("cls");
		odakayitislemleri();
		break;
	case 99:
		break;
	default:
		cout << "Hatalı Seçim" << endl;                //yanlış sayı girilirse
	}
}

void odaislemleri()
{
	cout << "Oda İşlemleri" << endl;
	for (int i = 1; i < 20; i++)
		cout << "-";
	cout << "\n1- Oda Ekle" << endl;
	cout << "2- Oda Sil" << endl;
	cout << "3- Odaları Listele" << endl;
	cout << "99- Üst Menü" << endl;
	cout << "Seçiminiz:";
	cin >> secim;
	switch (secim)
	{
	case 1:
		system("cls");
		DosyaYaz.open("Odalar.txt", ios::app);
		{
			cout << "Oda Numarası :"; cin >> o.odanumara;
			for (int z = 0; z < dongu; z++)               //döngüyü forla arattık
			{
				if (stoi(o.odanumara) != odalar[z])                  //eğer girilen değerle dizideki değer aynı değilse dizinin son elamanı o oluyor
				{
					odalar[dongu] = stoi(o.odanumara);
				}
				else if (stoi(o.odanumara) == odalar[z])            //döngü tamamlanmadan önce eğer bir sayı aynı çıkarsa donguyu hemen sıfırlıyor ve ana fonksiyona geri gönderiyor
				{
					odalar[dongu] = 0;                    
					cout << "Bu oda zaten var!" << endl;
					system("cls");
					DosyaYaz.close();
					otelislemleri();
				}
			}			
			cout << "\nOda Ücreti :"; cin >> o.odaücret;			     //oda ücretini alıyor
			DosyaYaz << "{|OdaNumarası:" << stoi(o.odanumara) << "\t" << "OdaÜcreti:" << stoi(o.odaücret) << "|}" << endl;             //alınan bilgileri dosyayay yazıyor
			cout << "Ekleme Başarılı" << endl;                                                                                      //stoiyle birlikte sayı değeri olup olmadaıklarını kontrol ediyor
			dongu++;                                                                                                             //donguyu diziye yeni numara eklenebilmesi için arttırıyor
			system("cls");
			DosyaYaz.close();
			otelislemleri();
			
		}
		break;
	case 2:
		system("cls");
		DosyaOku.open("Odalar.txt");                                     //odalar textini açıyor ve içeridekileri ekrana veriyor
		while (DosyaOku >> oku6 >> oku7)
			cout << oku6 << "  " << oku7 << endl;
		DosyaOku.close();
		cout << "Hangi odayı silmek istiyorsunuz:";                      
		cin >> secim;
		if (!cin.fail())
		{
			for (int p = 0; p < dongu; p++)                             //odalar dizinini tarıyor
			{
				if (secim == odalar[p])                          //eğer seçip silmek istediğimiz oda varsa
				{
					DosyaYaz.open("Odalar1.txt");            //yeni bi txt açıyor
					while (DosyaYaz.good())
					{
						DosyaOku.open("Odalar.txt");               //önceki texti açıyor
						DosyaOku._Seekbeg;                              //cursoru başa atıyor
						while (DosyaOku.good() && DosyaOku >> oku6 >> oku7) // oku 6 yla oda numarasını oku 7yle oda ücretini öğreniyor
						{
							if (secim != stoi(oku6.substr(14, (oku6.length() - 14))))                   //oda numarasını ortaya çıkartıyo ve eğer seçimimize eşit değilse yeni dosyaya yazıyo
							{                                                                           //eğer eşitse o satırı es geçiyor
								DosyaYaz << oku6 << "  " << oku7 << endl;                                  //ve yeni dosyaya yazıyor
							}
						}
						DosyaYaz.close();
						DosyaOku.close();
					}
					remove("Odalar.txt");                            // eski dosyayı siliyoruz ve yeni oluşturduğumuz textin ismini değiştiriyoruz
					rename("Odalar1.txt", "Odalar.txt");
					dongu = 1;
					dongu2 = 1;                                 //bir oda silindikten sonra dizideki numaraların güncellenmesini sağlıyoruz
					dongu3 = 1;
					dongu4 = 1;
					dizidoldur();
					odakayıtsil();                               //oda eğer kayıtlıysa onuda silmek için gerekli fonksiyona gidiyoruz
				}
			}

			cout << "\nKalan odalar:" << endl;
			DosyaOku.open("Odalar.txt");
			while (DosyaOku >> oku6 >> oku7)                //geriye kalan odaları gösteriyoruz
				cout << oku6 << "  " << oku7 << endl;
			DosyaOku.close();
			cout << "\ndevam etmek istiyormusunuz?(e/h)" << endl;
			cin >> cevap;
			if (cevap == 'e')
			{
				system("cls");
				otelislemleri();
			}
		}
		break;
	case 3:
		DosyaOku.open("Odalar.txt");
		while (DosyaOku >> oku6 >> oku7)
			cout << oku6 << "  " << oku7 << endl;                   //odaları listeliyoruz
		DosyaOku.close();
		cout << "\ndevam etmek istiyormusunuz?(e/h)" << endl;
		cin >> cevap;
		if (cevap == 'e')
		{
			system("cls");
			otelislemleri();
		}
		break;
	case 99:
		system("cls");
		otelislemleri();                       //üst menü
		break;
	default:
		cout << "Hatalı Seçim" << endl;
	}
}

void musteriislemleri()
{
	cout << "Müşteri İşlemleri" << endl;
	for (int i = 1; i < 20; i++)
		cout << "-";
	cout << "\n1- Müşteri Ekle" << endl;
	cout << "2- Müşteri Sil" << endl;
	cout << "3- Müşterileri Listele" << endl;
	cout << "99- Üst Menü" << endl;
	cout << "Seçiminiz:";
	cin >> secim;
	switch (secim)
	{
	case 1:
		system("cls");
		DosyaYaz.open("Müşteriler.txt", ios::app);
		{
			cout << "Müşteri Numarası :"; cin >> m.müşterinumara;
			for (int x = 0; x < dongu2; x++)
			{
				if (stoi(m.müşterinumara) != müşteriler[x])                   //müşteri dizide yoksa ekliyoruz
				{
					müşteriler[dongu2] = stoi(m.müşterinumara);
				}
				else if (stoi(m.müşterinumara) == müşteriler[x])
				{
					müşteriler[dongu2] = 0;
					cout << "Bu müşteri zaten var!" << endl;
					system("cls");
					DosyaYaz.close();
					otelislemleri();
				}
			}
			cout << "\nMüşteri Adı :"; cin >> m.müşteriad;
			cout << "\nMüşteri Soyadı :"; cin >> m.müşterisoyad;
			cout << "\nMüşteri Tc(Tc numarası 0 la başlamamalı ve çift sayıyla bitmelidir.):";cin >> m.müşteritc;             //tc kimlik numarası için gereken birkaç özellik
			if (stoi(m.müşteritc.substr(10, 1)) % 2 == 0 && stoi(m.müşteritc.substr(0, 1)) != 0)             //tc kimlik numarası çift sayıyla bitiyorsa ve sıfırla başlamıyorsa sıkıntı yok
			{
				DosyaYaz << "{|MüşteriNumarası:" << stoi(m.müşterinumara) << "  " << "MüşteriAdı:" << m.müşteriad << "  " << "MüşteriSoyadı:" << m.müşterisoyad << "  " << "MüşteriTc:" << m.müşteritc << "|}" << endl;
				cout << "Ekleme Başarılı" << endl;
				system("cls");                      //ekranı siliyor dosyayı kapatıyor ve üst menüye geçiyor
				dongu2++;
				DosyaYaz.close();
				otelislemleri();
			}
			else 
			{
				cout << "Hatalı Tc numarası" << endl;                                        //tc kimlik numarası istenildiği gibi değil
				müşteriler[dongu2 - 1] = 0;
				system("cls");
				DosyaYaz.close();
				otelislemleri();
			}
		}
	    break;
	case 2:
		system("cls");
		DosyaOku.open("Müşteriler.txt");
		while (DosyaOku >> oku >> oku1 >> oku2 >> oku3)
			cout << oku << "  " << oku1 << "  " << oku2 << "  " << oku3 << endl;              //müşterileri okuyor
		DosyaOku.close();
		cout << "Hangi müşteriyi silmek istiyorsunuz:";
		cin >> secim;
		if (!cin.fail())
		{
			for (int w = 0; w < dongu2; w++)
			{
				if (secim == müşteriler[w])
				{                                               //diziyi tarıyor ve müşteriyi bulduğunda yeni dosya açıp o numaraya eşit olmayan herşeyi yeniye yazıyor
					DosyaYaz.open("Müşteriler1.txt");
					while (DosyaYaz.good())
					{
						DosyaOku.open("Müşteriler.txt");
						DosyaOku._Seekbeg;
						while (DosyaOku.good() && DosyaOku >> oku >> oku1 >> oku2 >> oku3)
						{
							if (secim != stoi(oku.substr(18, (oku.length() - 18))))
							{
								DosyaYaz << oku << "  " << oku1 << "  " << oku2 << "  " << oku3 << endl;
							}
						}
						DosyaYaz.close();
						DosyaOku.close();
					}
					remove("Müşteriler.txt");                           //eski dosyayı siliyoruz ve yenisinin ismini değiştiriyoruz
					rename("Müşteriler1.txt", "Müşteriler.txt");
					dongu = 1;
					dongu2 = 1;
					dongu3 = 1;                                                  //bir müşteri silindikten sonra dizideki numaraların güncellenmesini sağlıyoruz
					dongu3 = 1;
					dongu4 = 1;
					dizidoldur();
					müşterikayıtsil();                           //müşteri kayıtlıysa siliyor
				}
			}
			cout << "\nKalan müşteriler:" << endl;
			DosyaOku.open("Müşteriler.txt");
			while (DosyaOku.good() && DosyaOku >> oku >> oku1 >> oku2 >> oku3)
				cout << oku << "  " << oku1 << "  " << oku2 << "  " << oku3 << endl;                      //kalan müşteriler
			DosyaOku.close();
			cout << "\ndevam etmek istiyormusunuz?(e/h)" << endl;
			cin >> cevap;
			if (cevap == 'e')
			{
				system("cls");
				otelislemleri();
			}
		}
		break;
	case 3:
		DosyaOku.open("Müşteriler.txt");
		while (DosyaOku.good() && DosyaOku >> oku >> oku1 >> oku2 >> oku3)
			cout << oku << "  " << oku1 << "  " << oku2 << "  " << oku3 << endl;
		cout << "\ndevam etmek istiyormusunuz?(e/h)" << endl;                    //müşterileri gösteriyor
		cin >> cevap;
		DosyaOku.close();
		if (cevap == 'e')
		{
			system("cls");
			otelislemleri();
		}
		break;
	case 99:
		system("cls");
		otelislemleri();
		break;
	default:
		cout << "Hatalı Seçim" << endl;
	}
}

void odakayitislemleri()
{
	cout << "Oda Kayıt İşlemleri" << endl;
	for (int i = 1; i < 20; i++)
		cout << "-";
	cout << "\n1- Oda Kayıt Ekle" << endl;
	cout << "2- Oda Kayıt Sil" << endl;
	cout << "3- Oda Kayıtlarını Listele" << endl;
	cout << "99- Üst Menü" << endl;
	cout << "Seçiminiz:";
	cin >> secim;
	switch (secim)
	{
	case 1:
		system("cls");
		DosyaYaz.open("OdaKayıt.txt", ios::app);
		cout << "Hangi odayı kayıt ediceksiniz?" << endl;
		DosyaOku.open("Odalar.txt");
		while (DosyaOku.good() && DosyaOku >> oku6 >>oku7)         //kayıt etmek istediği dosyaları gösteriyoruz
			cout << oku6<< "  " << oku7 << endl;
		DosyaOku.close();
		cout << "\nSeçiminiz:";
		cin >> secim;
		if (!cin.fail()) 
		{
			for (int c = 0; c < dongu3; c++)
			{
				if (secim == odalarkayıt[c])                               //seçilen oda eğer varsa daha önce kaydedilmişse hata veriyor
				{
					cout << "Bu oda zaten kayıtlı" << endl;
					DosyaOku.close();
					DosyaYaz.close();
					system("cls");
					otelislemleri();
				}
			}
			for (int z = 0; z < dongu; z++)
			{
				if (secim == odalar[z])                     //seçilen oda eğer varsa
				{
					odalarkayıt[dongu3] = secim;
					cout << "Hangi müşteriyi kayıt ediceksiniz?" << endl;
					DosyaOku.open("Müşteriler.txt");
					while (DosyaOku.good() && DosyaOku >> oku >> oku1 >> oku2 >> oku3)                     //odaya kayı etmek istediğimiz müşterileri soruyor
						cout << oku << "  " << oku1 << "  " << oku2 << "  " << oku3 << endl;
					DosyaOku.close();
					cout << "\nSeçiminiz:";
					cin >> secim;
					if (!cin.fail()) 
					{
						for (int s = 0; s < dongu4; s++)
						{
							if (secim == müşterilerkayıt[s])                                      //eğer daha önce jaydedilmişsse hata veriyor
							{
								cout << "Bu müşteri zaten kayıtlı" << endl;
								DosyaYaz.close();
								system("cls");
								otelislemleri();
							}
						}
						for (int x = 0; x < dongu2; x++)
						{
							if (secim == müşteriler[x])                               //eğer öyle bir müşteri varsa oda kaydını yazmaya başlıyor
							{
								müşterilerkayıt[dongu4] = secim;
								dongu4++;
								DosyaYaz << "{|OdaNumarası:" << odalar[z] << "  ";
								DosyaYaz << "MüşteriNumarası:" << müşteriler[x] << "|}" << endl;
								dongu3++;
								DosyaYaz.close();
								system("cls");
								otelislemleri();
							}
						}
						cout << "Hata" << endl;
						DosyaYaz.close();
						system("cls");
						otelislemleri();
					}
				}
			}
		}
		break;
	case 2:
		system("cls");
		DosyaOku.open("OdaKayıt.txt");
		while (DosyaOku >> oku4 >> oku5)
			cout << oku4 << "  " << oku5 << endl;
		DosyaOku.close();                          //silmek isteyebileceğimiz oda kayıtlarını gösteriyor
		cout << "Hangi odanın kaydını silmek istiyorsunuz:";
		cin >> secim;
		if (!cin.fail()) 
		{
			for (int p = 0; p < dongu3; p++)
			{
				if (secim == odalarkayıt[p])                      //eğer sileceğimiz oda kaydı gercekten varsa
				{
					DosyaYaz.open("OdaKayıt1.txt");              //yeni text dosyası açıyor
					while (DosyaYaz.good())
					{
						DosyaOku.open("OdaKayıt.txt");
						DosyaOku._Seekbeg;
						while (DosyaOku.good() && DosyaOku >> oku4 >> oku5)
						{                                      //ve silinecek kayıt eski dosyadakine eşit olmayana dek yeni dosyaya yazıyor
							if (secim != stoi(oku4.substr(14, (oku.length() - 14))))
							{
								DosyaYaz << oku4 << "  " << oku5 << endl;
							}
						}
						DosyaYaz.close();
						DosyaOku.close();           //dosyaları kapatıyor
					}
					remove("OdaKayıt.txt");                          //ve yeni ismini güncelleştiriyoruz
					rename("OdaKayıt1.txt", "OdaKayıt.txt");
					dongu = 1;
					dongu2 = 1;
					dongu3 = 1;                                     				//dizi değerlerini güncelliyor
					dongu4 = 1;
					dizidoldur();
				}
			}
			cout << "\nKalan kayıtlar:" << endl;
			DosyaOku.open("Odakayıt.txt");
			while (DosyaOku >> oku4 >> oku5)                           //kalan kayıtları gösteriyor
				cout << oku4 << "  " << oku5 << endl;
			DosyaOku.close();
			cout << "\ndevam etmek istiyormusunuz?(e/h)" << endl;
			cin >> cevap;
			if (cevap == 'e')
			{
				system("cls");
				otelislemleri();
			}
		}
		break;
	case 3:
		DosyaOku.open("OdaKayıt.txt");
		while (DosyaOku.good() && DosyaOku >> oku4 >> oku5)
		{                                                             //kaydedilen odaları gösteriyor
			cout << oku4 << "  " << oku5 << endl;
		}
		DosyaOku.close();
		cout << "\ndevam etmek istiyormusunuz?(e/h)" << endl;
		cin >> cevap;
		if (cevap == 'e')
		{
			system("cls");
			otelislemleri();
		}
		break;
	case 99:
		system("cls");
		otelislemleri();
		break;
	default:
		cout << "Hatalı Seçim" << endl;
	}
}

void odakayıtsil() 
{
	for (int c = 0; c < dongu3; c++)
	{
		if (secim == odalarkayıt[c])
		{                                                             //eğer silinen oda daha önce kaydedilmişsse silme işlemi başlıyor
			DosyaYaz.open("OdaKayıt1.txt");                          
			while (DosyaYaz.good())
			{
				DosyaOku.open("OdaKayıt.txt");
				DosyaOku._Seekbeg;
				while (DosyaOku.good() && DosyaOku >> oku4 >> oku5)                                   //silinmek istenen oda dosyadakine eşit olmadığı sürece yeni dosyaya diğer oda numaralarını yazıyoruz
				{
					if (secim != stoi(oku4.substr(14, (oku4.length() - 14))))
						DosyaYaz << oku4 << "  " << oku5 << endl;
				}
				DosyaYaz.close();
				DosyaOku.close();                       //dosyaları kapatıyoruz
			}
			remove("OdaKayıt.txt");                      //isim değişikliği
			rename("OdaKayıt1.txt", "OdaKayıt.txt");
			dongu = 1;
			dongu2 = 1;
			dongu3 = 1;                            //dizideki numaraların güncellenmesini sağlıyoruz
			dongu4 = 1;
			dizidoldur();            
		}
	}
}

void müşterikayıtsil()
{
	for (int z = 0; z < dongu4; z++)
	{
		if (secim == müşterilerkayıt[z])                           //eğer o müşteri kaydedilmişse silme işlemine başlıyoruz
		{
			DosyaYaz.open("OdaKayıt1.txt");
			while (DosyaYaz.good())
			{
				DosyaOku.open("OdaKayıt.txt");
				DosyaOku._Seekbeg;
				while (DosyaOku.good() && DosyaOku >> oku4 >> oku5)                                  //müşteri numarası silinmek istenene eşit olmayana kadar yeni dosyaya yazıyoruz
				{
					if (secim != stoi(oku5.substr(16, (oku5.length()- 16))))
						DosyaYaz << oku4 << "  " << oku5 << endl;
				}
				DosyaYaz.close();
				DosyaOku.close();                           //dosyaları kapatıyoruz
			}
			remove("OdaKayıt.txt");                                  //isim değişikliği
			rename("OdaKayıt1.txt", "OdaKayıt.txt");
			dongu = 1;
			dongu2 = 1;
			dongu3 = 1;                                     //dizideki numaraların güncellenmesini sağlıyoruz
			dongu3 = 1;
			dongu4 = 1;
			dizidoldur();
		}
	}
}
/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: Proje
**				ÖĞRENCİ ADI...............:Fatih Aslan
**				ÖĞRENCİ NUMARASI.:G171210045
**				DERS GRUBU…………:1-C
****************************************************************************/

#include "pch.h"
#include <iostream>  //gerekli kütüphaneler
#include <Windows.h>

using namespace std;

const int width = 80;
const int length = 20;  //sahnenin genişliği ve uzunluğu
int xp = 0;
int ec=0;         //xp, düşman öldürmesayısı, canımız ve mermi sayısı
int life = 3;
int bulletc = 0;
bool game=true;  //oyunun çalışıp çalışmadığına bakıyor
char screen[width][length];

struct Bullet
{
private:
	int x, y;
	char ch=178;
public:
	void setxy(int x, int y)
	{
		this->x = x + 3;
		this->y = y;    //mermimizin ilk konumu
	}
	void draw()
	{
		if(ch!=' ')
			screen[x][y] = ch;  //ekrana aydetme
	}
	void move()
	{
		x=x+2;   //hareket ettiriyoruz
		if (x == width)  //sahennin sınırına geldimi
			ch = ' ';
		draw();
	}

	bool crash(int x, int y)
	{
		if(ch!=' ')
			if (this->x == x && (this->y == y || this->y == y + 1 || this->y == y + 2))
			{
				ch = ' ';   //mermi hedefi vurduysa yok oluyor
				xp = xp + 100;  //xp artıyor
				ec++;  //öldürdüğümüzdüşman sayısı artıyor
				return true;
			}
		return false;
	}
};

Bullet b[4000];

class Ship
{
private:
	int x, y;	
	char ch;
public:
	Ship()
	{
		x = 1;
		y = length/2-1;
		ch = 177;   //uçağımızilk kurulduğundaki değerler
		draw();
	};

	bool isout(int y)
	{
		if (y==2||y==length-3) //sahnenin dışındamı diye bakıyoruz
			return true;
		return false;
	}

	void draw()
	{
		screen[x][y+2] = ch;
		screen[x + 1][y+1] = ch;
		screen[x+2][y] = ch;
		screen[x+1][y-1] = ch;  //ucağımızı ekrana kaydediyoruz
		screen[x][y-2] = ch;
	};

	void move(bool yukari)
	{
		if (yukari) 
		{
			if(!isout(y-1))  //sınırdamıyız diye bakıyor
				y--;              //yukarıya hareket
		}
		else
		{
			if(!isout(y+1))
				y++;  //aşşağıya hareket
		}
		draw();
	};

	bool crash(int x, int y)
	{
		if (this->x + 1 == x && (this->y == y|| this->y-1 == y || this->y+1 == y))
			return true;                                         //uçağa çarpmavarmı diye bakılıyor
		return false;
	};

	void fire(int c)
	{
		b[c].setxy(x, y);  //ateş ediyoruz ve mermimizin x ve ysini uçağımızınkine göreayarlıyoruz
	};

	void moveb(int c)
	{
		b[c].move();  //mermiyi hareket ettiriyoruz
	}
};

Ship u;

class Object
{
private:
	int x, y;
	char ch;       //objemizle alakalı değişkenler
	void draw() 
	{
		if (ch != ' ') 
		{
			screen[x][y] = ch;
			screen[x + 1][y] = ch;
			screen[x + 2][y] = ch;
			screen[x][y + 1] = ch;        //objemizi char dizisne kaydediyoruz
			screen[x + 2][y + 1] = ch;
			screen[x][y + 2] = ch;
			screen[x + 1][y + 2] = ch;
			screen[x + 2][y + 2] = ch;
		}
	};
public:
	Object()
	{
		y = rand() % (length-4)+1;  //objemizin spawnlanacağı yer
		x = width-4;          //objemizçağrıldığında gelen temel ayarlar
		ch = 177;
	};
	~Object()
	{
		ch = ' ';  //objemizin yıkıcısı
	};
	bool notdeleted() 
	{
		if (ch == ' ')      //objemizin silinip silinmediğine bakıyor
			return false;
		else
			return true;
	};
	bool move()
	{
		x--;  //objemizsola hareket ediyor
		draw();
		if (u.crash(x, y))  //eğer obje uçağa çarptıysa oyun bitiyor
			game = false;
		for (size_t i = 0; i < bulletc; i++)
		{
			if (b[i].crash(x, y))               //mermi objeyi vurmuşmu diye bakıyoruz
				return true;
			if (b[i].crash(x+1, y))
				return true;
			if (b[i].crash(x+2, y))
				return true;
		}
		if (x == 1) 
		{
			ch = ' '; //eğer objeyi vuramadıysak canımız azalıyor ve obje siliniyor
			life--;
		}
		return false;
	};	
};

class Screen //ekranla ilgili işlemler
{
public:

	Screen()               //ekran kuruluyor
	{
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = 0; j < width; j++)
			{
				if (i == 0 || i == length - 1|| j == 0 || j == width - 1)
					screen[j][i] = 178;   //ekranı çizdik
				else
					screen[j][i] = ' ';
			}
		}
	};

	void draw()
	{
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = 0; j < width; j++)
			{
				cout << screen[j][i];  //screen charındaki herşeyi sırayla çizdirdik
			}
			cout << endl;
		}
	};

	void clear()
	{
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = 0; j < width; j++)
			{
				if (!(i == 0 || i == length - 1 || j == 0 || j == width - 1))          //char dizimizi temizliyoruz
					screen[j][i] = ' ';
			}
		}
	};

	void editxy(int x, int y)
	{
		COORD c;
		c.X = x;          //cursorun yeri değişiyor
		c.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	};

	void hidecursor()
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO ci;          //cursoru gizliyoruz
		GetConsoleCursorInfo(out, &ci);
		ci.bVisible = false;
		SetConsoleCursorInfo(out, &ci);
	};	
}; 

Screen s;

Object o[1000];  //objeler dizimiz

void control()
{
	if (GetAsyncKeyState('W') & 0x8000)//basılan tuş w ise
	{
		u.move(true);   //yukarı hareket ediyor
	}
	else if (GetAsyncKeyState('S') & 0x8000)
	{
		u.move(false); //s iseaşşağı
	}
	else if (GetAsyncKeyState('C') & 0x8000)
	{  
		bulletc++; 		//c ise ateşediyor ve mermi sayısını arttırıyor
		u.fire(bulletc - 1); //uçak ateş ediyor
		u.draw(); //ateş ederken uçağı da çiziyoruz
	}
	else
		u.draw();  //tuşa basılmadıysa uçağı çiziyoruz
}

int main()
{
	int often = 10;  //obje oluşmasıklığı
	int objc=1;  //obje sayımız
	int sayac = 0; 
	s.hidecursor();	//cursoru gizliyoruz
	while (game)
	{
		for (int i = 0; i < objc; i++)   //tüm objelerimizi hareket ettiriyoruz
		{
			if (o[i].notdeleted()) 
			{
				if (o[i].move())  //objemizi hareket ettirip çarpışmaolup olmadığına bakıyoruz
				{
					o[i].~Object();  //objemizi yok ediyoruz
				}
			}
		}		
		for (int i = 0; i < bulletc; i++)
		{
			u.moveb(i);  //mermilerimizi hareket ettiriyoruz
		}
		s.draw(); //ekranı çiziyoruz
		s.clear();  //ekranı temizliyoruz
		control();  //tuşa basılıpbasılmadığınıkontrol ediyor
		sayac++;
		if (sayac == often)
		{
			objc++; //aralıklarla yeni engeller çıkıyor
			sayac = 0;
		}
		xp=xp+2;  //hayatta kaldıkçaartan xp
		cout << "SCORE:" << xp << endl << "ENEMY KILLED:" << ec<<endl<<"LIFE:"<<life<<endl; //skorumuz
		Sleep(10);  //bekleme süresi
		s.editxy(0, 0);  //tekrar başadönüyoruz
		if (life == 0)  //eğer canımızkalmamışsa
			game = false;
	}
	system("cls");
	cout << "###########################################" << endl;
	cout << "#----------------YOU LOST-----------------#" << endl;  //oyun bitince çıkan değerler
	cout << "###########################################" << endl;
	cout << "                  STATS                    " << endl;
	cout << "XP:" << xp << endl;
	cout << "ENEMY KILLED:" << ec << endl;
}
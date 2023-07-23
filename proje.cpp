#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class Tarih
{
public:
	Tarih()
	{
		this->gun = 0;
		this->ay = 0;
		this->yil = 0;
	}

	void tarihGir()
	{
		cout << "\n\tgun :";
		cin >> gun;
		cout << "\tay :";
		cin >> ay;
		cout << "\tyil :";
		cin >> yil;
	}
	int gun, ay, yil;
};


class Urun
{
public:
	Urun()
	{
		ifstream dosya_oku("Depo.txt");

		while (!dosya_oku.eof())
		{
			dosya_oku >> urun_kodu >> urunAdi >> UretimTarihi.gun >> UretimTarihi.ay >> UretimTarihi.yil >> sonKullanmaTarihi.gun >> sonKullanmaTarihi.ay >> sonKullanmaTarihi.yil >> kaloriGram >> StokAdet >> fiyat;
		}
		urun_kodu++;
		dosya_oku.close();

	}
	void urunEkle()
	{
		ofstream dosya_yaz("Depo.txt", ios::app);

		cout << "Urun adi giriniz:";
		cin >> urunAdi;

		cout << "Uretim tarihi giriniz:";
		UretimTarihi.tarihGir();

		cout << "sonKullanma tarihi giriniz:";
		sonKullanmaTarihi.tarihGir();

		cout << "kalori gram giriniz:";
		cin >> kaloriGram;

		cout << "Stok adet giriniz:";
		cin >> StokAdet;

		cout << "fiyat giriniz:";
		cin >> fiyat;

		dosya_yaz << "\n"
			<< urun_kodu << " " << urunAdi << " " << UretimTarihi.gun << " " << UretimTarihi.ay << " " << UretimTarihi.yil << " " << sonKullanmaTarihi.gun << " " << sonKullanmaTarihi.ay << " " << sonKullanmaTarihi.yil << " " << kaloriGram << " " << StokAdet << " " << fiyat;

		dosya_yaz.close();
		cout << "\ndosyaya yazmak tamamlandi.\n" << endl;
		urun_kodu++;
	}
	void urunSil()
	{
		gosterme();
		int silen_urun;
		cout << "\nsilenecek urun kodu giriniz: ";
		cin >> silen_urun;
		ifstream dosya_oku("Depo.txt");
		ofstream dosya_yaz("Depo.tmp");

		while (!dosya_oku.eof())
		{
			dosya_oku >> urun_kodu >> urunAdi >> UretimTarihi.gun >> UretimTarihi.ay >> UretimTarihi.yil >> sonKullanmaTarihi.gun >> sonKullanmaTarihi.ay >> sonKullanmaTarihi.yil >> kaloriGram >> StokAdet >> fiyat;

			if (silen_urun != urun_kodu)
			{
				dosya_yaz << "\n"
					<< urun_kodu << " " << urunAdi << " " << UretimTarihi.gun << " " << UretimTarihi.ay << " " << UretimTarihi.yil << " " << sonKullanmaTarihi.gun << " " << sonKullanmaTarihi.ay << " " << sonKullanmaTarihi.yil << " " << kaloriGram << " " << StokAdet << " " << fiyat;

			}
		}

		dosya_yaz.close();
		dosya_oku.close();

		remove("Depo.txt");
		rename("Depo.tmp", "Depo.txt");
	}
	void gosterme()
	{
		system("cls");
		ifstream dosya_oku("Depo.txt");
		cizgiYaz();
		cout << left << "|" << setw(10) << "urun kodu" << "|" << setw(15) << "urun adi" << "|" << setw(14) << "Uretim tarihi" << "|" << setw(19) << "sonKullanma tarihi" << "|" << setw(12) << "kalori Gram" << "|" << setw(10) << "Stok Adet" << "|" << setw(6) << "fiyat" << "|" << endl;
		cizgiYaz();
		while (!dosya_oku.eof())
		{
			dosya_oku >> urun_kodu >> urunAdi >> UretimTarihi.gun >> UretimTarihi.ay >> UretimTarihi.yil >> sonKullanmaTarihi.gun >> sonKullanmaTarihi.ay >> sonKullanmaTarihi.yil >> kaloriGram >> StokAdet >> fiyat;

			cout << left << "|" << setw(10) << urun_kodu << "|" << setw(15) << urunAdi << "|" << setw(3) << UretimTarihi.gun << "/" << setw(3) <<
				UretimTarihi.ay << "/" << setw(6) << UretimTarihi.yil << "|" << setw(3) << sonKullanmaTarihi.gun << "/" << setw(3) << sonKullanmaTarihi.ay <<
				"/" << setw(11) << sonKullanmaTarihi.yil << "|" << setw(12) << kaloriGram << "|" << setw(10) << StokAdet << "|" << setw(6) << fiyat << "|" << endl;
			cizgiYaz();

		}
		dosya_oku.close();
	}
	void guncelleme()
	{
		gosterme();
		int guncelleme_kodu;
		cout << "\nduzeltmek urun kodu giriniz: ";
		cin >> guncelleme_kodu;
		ifstream dosya_oku("Depo.txt");
		ofstream dosya_yaz("Depo.tmp");
		while (!dosya_oku.eof())
		{
			dosya_oku >> urun_kodu >> urunAdi >> UretimTarihi.gun >> UretimTarihi.ay >> UretimTarihi.yil >>
				sonKullanmaTarihi.gun >> sonKullanmaTarihi.ay >> sonKullanmaTarihi.yil >> kaloriGram >> StokAdet >> fiyat;
			if (guncelleme_kodu == urun_kodu)
			{
				cout << "\n ***Yeni bilgiler giriniz*** \n";
				cout << "Urun adi giriniz:";
				cin >> urunAdi;

				cout << "Uretim tarihi giriniz:";
				UretimTarihi.tarihGir();

				cout << "sonKullanma tarihi giriniz:";
				sonKullanmaTarihi.tarihGir();

				cout << "kalori gram giriniz:";
				cin >> kaloriGram;

				cout << "Stok adet giriniz:";
				cin >> StokAdet;

				cout << "fiyat giriniz:";
				cin >> fiyat;

				dosya_yaz << "\n"
					<< urun_kodu << " " << urunAdi << " " << UretimTarihi.gun << " " << UretimTarihi.ay << " " << UretimTarihi.yil << " " << sonKullanmaTarihi.gun << " " << sonKullanmaTarihi.ay << " " << sonKullanmaTarihi.yil << " " << kaloriGram << " " << StokAdet << " " << fiyat;

			}
			else
			{
				dosya_yaz << "\n"
					<< urun_kodu << " " << urunAdi << " " << UretimTarihi.gun << " " << UretimTarihi.ay << " " << UretimTarihi.yil << " " << sonKullanmaTarihi.gun << " " << sonKullanmaTarihi.ay << " " << sonKullanmaTarihi.yil << " " << kaloriGram << " " << StokAdet << " " << fiyat;

			}

		}
		dosya_yaz.close();
		dosya_oku.close();

		remove("Depo.txt");
		rename("Depo.tmp", "Depo.txt");
	}

private:
	void cizgiYaz()
	{
		for (int i = 0; i < 93; i++)
		{
			cout << "-";
		}
		cout << endl;
	}

	int urun_kodu = 1000;
	string urunAdi;
	Tarih UretimTarihi;
	Tarih sonKullanmaTarihi;
	float kaloriGram;
	float StokAdet;
	float fiyat;
};


class Malzeme
{
public:
	void malzemeEkle(int malzeme_kodu)
	{
		string cevap;
		ofstream dosya_yaz("malzeme.txt", ios::app);
		do
		{
			cout << "malzeme adi giriniz:";
			cin >> malzemeAd;
			cout << "malzeme adedi giriniz:";
			cin >> malzemeAdedi;
			dosya_yaz << "\n"
				<< malzeme_kodu << " " << malzemeAd << " " << malzemeAdedi;
			cout << "baska bir malzeme eklemek istermisiniz? [e/E]";
			cin >> cevap;
		} while (cevap == "e" || cevap == "E");
		dosya_yaz.close();
	}

	void malzemeSil(int kod)
	{
		ifstream dosya_oku("malzeme.txt");
		ofstream dosya_yaz("malzeme.tmp");
		while (!dosya_oku.eof())
		{
			dosya_oku >> malzeme_kodu >> malzemeAd >> malzemeAdedi;

			if (kod != malzeme_kodu)
			{
				dosya_yaz << "\n"
					<< malzeme_kodu << " " << malzemeAd << " " << malzemeAdedi;
			}
		}
		dosya_yaz.close();
		dosya_oku.close();

		remove("malzeme.txt");
		rename("malzeme.tmp", "malzeme.txt");
	}

	void guncelleme(int kod)
	{
		ifstream dosya_oku("yemekcesit.txt");
		malzemeSil(kod);
		malzemeEkle(kod);
		dosya_oku.close();
	}

	void gosterme(int kod)
	{
		ifstream dosya_oku("malzeme.txt");
		while (!dosya_oku.eof())
		{

			dosya_oku >> malzeme_kodu >> malzemeAd >> malzemeAdedi;
			if (kod == malzeme_kodu)
				cout << malzemeAd << "*(" << malzemeAdedi << ") ";
		}
	}

private:
	string malzemeAd;
	int malzemeAdedi;
	int malzeme_kodu;
};

class YemekCesit
{
public:
	YemekCesit()
	{
		ifstream dosya_oku("yemekcesit.txt");

		while (!dosya_oku.eof())
		{
			dosya_oku >> YemekCesit_kodu >> yemekAd;
		}
		YemekCesit_kodu++;
		dosya_oku.close();
	}
	void yemekEkle()
	{
		system("cls");
		ofstream dosya_yaz("yemekcesit.txt", ios::app);

		cout << "Yemek adi giriniz:";
		cin >> yemekAd;

		dosya_yaz << "\n"
			<< YemekCesit_kodu << " " << yemekAd;
		dosya_yaz.close();
		malzemeler.malzemeEkle(YemekCesit_kodu);

		cout << "\ndosyaya yazmak tamamlandi.\n" << endl;
		YemekCesit_kodu++;
	}

	void gosterme()
	{
		system("cls");
		ifstream dosya_oku("yemekcesit.txt");
		cizgiYaz();
		cout << left << "|" << setw(16) << "YemekCesit kodu" << "|" << setw(15) << "YemekCesit adi" << "|" << setw(11) << "malzemeler" << endl;
		cizgiYaz();
		while (!dosya_oku.eof())
		{
			dosya_oku >> YemekCesit_kodu >> yemekAd;

			cout << left << "|" << setw(16) << YemekCesit_kodu << "|" << setw(15) << yemekAd << "|";
			malzemeler.gosterme(YemekCesit_kodu);
			cout << endl;

		}
	}

	void yemekSil()
	{
		gosterme();
		int silen_yemek;
		cout << "\nsilenecek yemek kodu giriniz: ";
		cin >> silen_yemek;
		ifstream dosya_oku("yemekcesit.txt");
		ofstream dosya_yaz("yemekcesit.tmp");

		while (!dosya_oku.eof())
		{
			dosya_oku >> YemekCesit_kodu >> yemekAd;

			if (silen_yemek != YemekCesit_kodu)
			{
				dosya_yaz << "\n"
					<< YemekCesit_kodu << " " << yemekAd;
			}
			else
				malzemeler.malzemeSil(YemekCesit_kodu);
		}

		dosya_yaz.close();
		dosya_oku.close();

		remove("yemekcesit.txt");
		rename("yemekcesit.tmp", "yemekcesit.txt");
	}

	void guncelleme()
	{
		int guncelleme_kodu;
		gosterme();

		cout << "\nduzeltmek Yemek kodu giriniz: ";
		cin >> guncelleme_kodu;

		ifstream dosya_oku("yemekcesit.txt");
		ofstream dosya_yaz("yemekcesit.tmp");
		while (!dosya_oku.eof())
		{
			dosya_oku >> YemekCesit_kodu >> yemekAd;

			if (YemekCesit_kodu == guncelleme_kodu)
			{
				cout << "\n ***Yeni bilgiler giriniz*** \n";

				cout << "Yemek adi giriniz:";
				cin >> yemekAd;

				dosya_yaz << "\n"
					<< YemekCesit_kodu << " " << yemekAd;
				malzemeler.guncelleme(YemekCesit_kodu);
			}
			else
			{
				dosya_yaz << "\n"
					<< YemekCesit_kodu << " " << yemekAd;
			}

		}
		dosya_yaz.close();
		dosya_oku.close();

		remove("yemekcesit.txt");
		rename("yemekcesit.tmp", "yemekcesit.txt");
	}


	void PisirilecekYemek(int kod, int sayi)
	{
		int urun_kodu = 1000;
		string urunAdi;
		Tarih UretimTarihi;
		Tarih sonKullanmaTarihi;
		float kaloriGram;
		float StokAdet;
		float fiyat;
		string malzemeAd;
		int malzemeAdedi;
		int malzeme_kodu;
		bool kontrol = true;
		int toplamFiyat = 0;

		ifstream dosya_oku("malzeme.txt");
		ofstream dosya_yaz("gerekliMalzemeler.txt");
		ifstream yemekdosya_oku("yemekcesit.txt");
		while (!yemekdosya_oku.eof())
		{
			yemekdosya_oku >> YemekCesit_kodu >> yemekAd;
			if (YemekCesit_kodu == kod)
				break;
		}

		while (!dosya_oku.eof())
		{

			dosya_oku >> malzeme_kodu >> malzemeAd >> malzemeAdedi;

			if (kod == malzeme_kodu)
			{
				ifstream DepoDosya_oku("Depo.txt");
				ofstream DepoDosya_yaz("Depo.tmp");

				while (!DepoDosya_oku.eof())
				{

					DepoDosya_oku >> urun_kodu >> urunAdi >> UretimTarihi.gun >> UretimTarihi.ay >> UretimTarihi.yil >> sonKullanmaTarihi.gun >> sonKullanmaTarihi.ay >> sonKullanmaTarihi.yil >> kaloriGram >> StokAdet >> fiyat;

					if (urunAdi == malzemeAd)
					{
						if (StokAdet >= malzemeAdedi*sayi)
						{
							kontrol = false;
							DepoDosya_yaz << "\n"
								<< urun_kodu << " " << urunAdi << " " << UretimTarihi.gun << " " << UretimTarihi.ay << " " << UretimTarihi.yil << " " << sonKullanmaTarihi.gun
								<< " " << sonKullanmaTarihi.ay << " " << sonKullanmaTarihi.yil << " " << kaloriGram << " " << StokAdet - malzemeAdedi*sayi << " " << fiyat;

							toplamFiyat += fiyat * malzemeAdedi;
						}
					}
					else
						DepoDosya_yaz << "\n"
						<< urun_kodu << " " << urunAdi << " " << UretimTarihi.gun << " " << UretimTarihi.ay << " " << UretimTarihi.yil << " " << sonKullanmaTarihi.gun << " " << sonKullanmaTarihi.ay << " " << sonKullanmaTarihi.yil << " " << kaloriGram << " " << StokAdet << " " << fiyat;

				}
				DepoDosya_oku.close();
				DepoDosya_yaz.close();
				remove("Depo.txt");
				rename("Depo.tmp", "Depo.txt");

				if (kontrol)
				{
					dosya_yaz << "\n" <<
						malzeme_kodu << " " << malzemeAd << " " << sayi * malzemeAdedi;
				}
				else
				{
					ofstream menu_yaz("menu.txt");
					menu_yaz << "\n" <<
						yemekAd << " " << toplamFiyat << " " << toplamFiyat + 20 << " " << sayi << " " << sayi;
				}
			}
		}




		dosya_yaz.close();
		dosya_oku.close();
	}

private:
	void cizgiYaz()
	{
		for (int i = 0; i < 46; i++)
		{
			cout << "-";
		}
		cout << endl;
	}

	int YemekCesit_kodu = 1000;
	string yemekAd;
	Malzeme malzemeler;
};


int main()
{
	string sec;
	int yemek_Kod;
	int yemekSayisi;
	YemekCesit yemekcesit;
	Urun depo;

	
	do {
		system("cls");
		cout << "(1) Depo \n(2) yemek cesiti \n(3) rapor \n(4) cikis \nbir islem seciniz :";
		cin >> sec;
		if (sec == "1")
		{
			system("cls");
			cout << "(1) urun ekle \n(2) urun guncelle \n(3) urun sil \n(4) liste yazdir \nbir islem seciniz :";
			cin >> sec;
			if (sec == "1")
			{
				depo.urunEkle();
			}
			else if (sec == "2")
			{
				depo.guncelleme();
			}
			else if (sec == "3")
			{
				depo.urunSil();
			}
			else if (sec == "4")
			{
				depo.gosterme();
			}
		}
		else if (sec == "2")
		{
			system("cls");
			cout << "(1) yemek cesiti ekle \n(2) yemek cesiti guncelle \n(3) yemek cesiti sil \n(4) yemek cesiti listesi yazdir \nbir islem seciniz :";
			cin >> sec;
			if (sec == "1")
			{
				yemekcesit.yemekEkle();
			}
			else if (sec == "2")
			{
				yemekcesit.guncelleme();
			}
			else if (sec == "3")
			{
				yemekcesit.yemekSil();
			}
			else if (sec == "4")
			{
				yemekcesit.gosterme();
			}
		}
		else if (sec == "3")
		{
			system("cls");
			cout << "(1) gunluk yapilacak yemekler \n(2) satilacak yemekler \n(3) gunluk raporu\n(4) gerekli malzemeler \nbir islem seciniz :";
			cin >> sec;
			if (sec == "1")
			{
				do
				{
					yemekcesit.gosterme();
					cout << "Lutfen yemegi seciniz.." << "\n YemekCesit kodu :";
					cin >> yemek_Kod;
					cout << "yemek sayisi :";
					cin >> yemekSayisi;
					yemekcesit.PisirilecekYemek(yemek_Kod, yemekSayisi);


					cout << "\nbaska bir yemek Pisirmek istiyormusunuz[e/h] :";
					cin >> sec;
				} while (sec == "e" || sec == "E");
			}
			else if (sec == "2")
			{
				string yemekAd;
				int genelTutar;
				int satisTutar;
				int uretilenYemek;
				int satilanYemek;
					do {
						ifstream menu_oku("menu.txt");
						ofstream menu_yaz("menu.tmp");
						while (!menu_oku.eof())
						{
							menu_oku >> yemekAd >> genelTutar >> satisTutar >> uretilenYemek >> satilanYemek;
							cout << left << "yemek Ad :" << setw(10) << yemekAd << "fiyat :" << setw(10) << satisTutar << "kalan :" << setw(5) << satilanYemek << endl;
						}
						cout << "Bir yemek adi seciniz :";
						cin >> sec;
						menu_oku.close();
						ifstream mmenu_oku("menu.txt");
						while (!mmenu_oku.eof())
						{
							mmenu_oku >> yemekAd >> genelTutar >> satisTutar >> uretilenYemek >> satilanYemek;
							if (yemekAd == sec)
							{
								if(satilanYemek != 0)
									menu_yaz << "\n" <<
										yemekAd << " " << genelTutar << " " << satisTutar << " " << uretilenYemek << " " << satilanYemek - 1;
								else
									menu_yaz << "\n" <<
									yemekAd << " " << genelTutar << " " << satisTutar << " " << uretilenYemek << " " << satilanYemek;
							}
							else
								menu_yaz << "\n" <<
								yemekAd << " " << genelTutar << " " << satisTutar << " " << uretilenYemek << " " << satilanYemek;
						}
						mmenu_oku.close();
						menu_yaz.close();
						remove("menu.txt");
						rename("menu.tmp", "menu.txt");

						cout << "\nbaska bir siparis istiyormusunuz[e/h] :";
						cin >> sec;
					}while (sec == "e" || sec =="E");

			}
			else if (sec == "3")
			{
				/*
				üretilen yemek :
				satılan yemek :
				Maliyet :
				kar :
				kalan yemek :*/
				system("cls");

				int Maliyet = 0;
				int kar = 0;
				string yemekAd;
				int genelTutar;
				int satisTutar;
				int uretilenYemek;
				int satilanYemek;
				cout << "Uretilen yemek :" << endl;
				ifstream menu_oku("menu.txt");
				while (!menu_oku.eof())
				{
					menu_oku >> yemekAd >> genelTutar >> satisTutar >> uretilenYemek >> satilanYemek;
					cout << left << "yemek Ad :" << setw(10) << yemekAd  << "Adet :" << setw(5) << uretilenYemek << endl;
					Maliyet += genelTutar * uretilenYemek;
					kar += satisTutar * (uretilenYemek - satilanYemek);
				}
				menu_oku.close();

				cout << "\nSatilan yemek :" << endl;
				ifstream mmenu_oku("menu.txt");
				while (!mmenu_oku.eof())
				{
					mmenu_oku >> yemekAd >> genelTutar >> satisTutar >> uretilenYemek >> satilanYemek;
					cout << left << "yemek Ad :" << setw(10) << yemekAd << "Adet :" << setw(5) << uretilenYemek - satilanYemek << endl;
				}
				mmenu_oku.close();

				cout << "\nkalan yemek :" << endl;
				ifstream mmmenu_oku("menu.txt");
				while (!mmmenu_oku.eof())
				{
					mmmenu_oku >> yemekAd >> genelTutar >> satisTutar >> uretilenYemek >> satilanYemek;
					cout << left << "yemek Ad :" << setw(10) << yemekAd << "Adet :" << setw(5) << satilanYemek << endl;
				}
				mmmenu_oku.close();

				cout << "Maliyet :" << Maliyet << endl;
				cout << "kar :" << kar << endl;

			}
			else if (sec == "4")
			{
				int malzemeAdedi;
				string malzemeAd;
				int malzeme_kodu;

				ifstream dosya_oku("gerekliMalzemeler.txt");
				
				cout << left << setw(12) << "malzeme adi" << setw(13) << "malzemeAdedi" << endl;
				while (!dosya_oku.eof())
				{
					dosya_oku >> malzeme_kodu >> malzemeAd >> malzemeAdedi;
					cout << left << setw(12) << malzemeAd << setw(13) << malzemeAdedi << endl;
				}
			}
		}
		else if (sec == "4")
			break;

		cout << "\ndevam etmek istiyormusunuz[e/h] :";
		cin >> sec;
		if (sec != "e" && sec != "E")
			sec = "4";
	} while (sec != "4");
	remove("menu.txt");	
}
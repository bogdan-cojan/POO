#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <Windows.h>

using namespace std;

class lista;
class listao;

class magazin_de_haine
{
	int tip, pret;
	string producator;
	string locatie;
	magazin_de_haine* urm;
	magazin_de_haine* urmo;
public:
	magazin_de_haine(int t, string prod, int pr, string loc)
	{
		tip = t;
		producator = prod;
		pret = pr;
		locatie = loc;
		urm = NULL;
		urmo = NULL;
	}
	virtual void afisare()
	{
		cout << "Producator: " << producator << endl;
		cout << "Pret: " << pret << endl;
		cout << "Locatie: " << locatie << endl;
	}
	friend class lista;
	friend class listao;
};

class hanorac :public magazin_de_haine
{
	string marime;
	int imprimeu;
public:
	hanorac(int t, string prod, int pr, string loc, string m, int imp) :magazin_de_haine(t, prod, pr, loc)
	{
		marime = m;
		imprimeu = imp;
	}
	void afisare()
	{
		magazin_de_haine::afisare();
		cout << "Marime: " << marime << endl;
		cout << "Imprimeu: " << imprimeu << endl;
	}
	friend class lista;
	friend class listao;
};

class sapca :public magazin_de_haine
{
	string material;
	int banda_reglabila;
public:
	sapca(int t, string prod, int pr, string loc, string mat, int b_r) :magazin_de_haine(t, prod, pr, loc)
	{
		material = mat;
		banda_reglabila = b_r;
	}
	void afisare()
	{
		magazin_de_haine::afisare();
		cout << "Material: " << material << endl;
		cout << "Banda reglabila: " << banda_reglabila << endl;
	}
	friend class lista;
	friend class listao;
};

class manusi :public magazin_de_haine
{
	int piele, captusite;
public:
	manusi(int t, string prod, int pr, string loc, int pi, int cap) :magazin_de_haine(t, prod, pr, loc)
	{
		piele = pi;
		captusite = cap;
	}
	void afisare()
	{
		magazin_de_haine::afisare();
		cout << "Piele: " << piele << endl;
		cout << "Captusite: " << captusite << endl;
	}
	friend class lista;
	friend class listao;
};

class sosete :public magazin_de_haine
{
	int numar;
	string culoare;
public:
	sosete(int t, string prod, int pr, string loc, int nr, string cul) :magazin_de_haine(t, prod, pr, loc)
	{
		numar = nr;
		culoare = cul;
	}
	void afisare()
	{
		magazin_de_haine::afisare();
		cout << "Numar: " << numar << endl;
		cout << "Culoare: " << culoare << endl;
	}
	friend class lista;
	friend class listao;
};

class lista
{
public:
	magazin_de_haine* head;
	void adaugare(magazin_de_haine* a);
	void afisare_lista(int alg);
	void citireFisier(lista& l, listao& lo);
	void afisareFisier(lista& l);
	void stergere();
	void actualizare_info(int alg);
};

class MyException1
{
public:
	string str_what;
	string what;
	MyException1() { str_what = "0", what = "0"; }
	MyException1(const string& s, string c)
	{
		str_what = s;
		what = c;
	}
};

class MyException2
{
public:
	string str_what;
	int what;
	MyException2() { str_what = "0", what = 0; }
	MyException2(const string& s, int c)
	{
		str_what = s;
		what = c;
	}
};

int valid(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]) != 0)
		{
			return 0;
		}
	}
	return 1;
}

class listao
{
public:
	magazin_de_haine* heado;
	void adaugareo(magazin_de_haine* a);
	void afisareo();
};

void lista::adaugare(magazin_de_haine* a)
{
	magazin_de_haine* p;
	p = head;
	if (p)
	{
		if (a->producator < p->producator)
		{
			a->urm = head;
			head = a;
		}
		else
		{
			while (p->urm && (p->urm)->producator < a->producator)
			{
				p = p->urm;
			}
			a->urm = p->urm;
			p->urm = a;
		}
	}
	else
	{
		head = a;
	}
}

void listao::adaugareo(magazin_de_haine* a)
{
	magazin_de_haine* p;
	p = heado;
	if (p)
	{
		if (a->pret > p->pret)
		{
			a->urmo = heado;
			heado = a;
		}
		else
		{
			while (p->urmo && (p->urmo)->pret > a->pret)
			{
				p = p->urmo;
			}
			a->urmo = p->urmo;
			p->urmo = a;
		}
	}
	else
	{
		heado = a;
	}
}

void lista::afisare_lista(int alg)
{
	magazin_de_haine* a;
	a = head;
	hanorac* ha;
	sapca* sa;
	manusi* man;
	sosete* sos;
	if (!a)
	{
		cout << "Lista este vida." << endl;
	}
	else
	{
		while (a)
		{
			if (alg == 1)
			{
				a->afisare();
				cout << endl;
			}
			if (alg == 2)
			{
				if (a->tip == 0)
				{
					ha = (hanorac*)a;
					cout << endl;
					cout << "Producator: " << a->producator << endl;
					cout << "Pret: " << a->pret << endl;
					cout << "Locatie: " << a->locatie << endl;
					cout << "Marime: " << ha->marime << endl;
					cout << "Imprimeu: " << ha->imprimeu << endl;
				}
			}
			if (alg == 3)
			{
				if (a->tip == 1)
				{
					sa = (sapca*)a;
					cout << endl;
					cout << "Producator: " << a->producator << endl;
					cout << "Pret: " << a->pret << endl;
					cout << "Locatie: " << a->locatie << endl;
					cout << "Material: " << sa->material << endl;
					cout << "Banda reglabila: " << sa->banda_reglabila << endl;
				}
			}
			if (alg == 4)
			{
				if (a->tip == 2)
				{
					man = (manusi*)a;
					cout << endl;
					cout << "Producator: " << a->producator << endl;
					cout << "Pret: " << a->pret << endl;
					cout << "Locatie: " << a->locatie << endl;
					cout << "Piele: " << man->piele << endl;
					cout << "Captusite: " << man->captusite << endl;
				}
			}
			if (alg == 5)
			{
				if (a->tip == 3)
				{
					sos = (sosete*)a;
					cout << endl;
					cout << "Producator: " << a->producator << endl;
					cout << "Pret: " << a->pret << endl;
					cout << "Locatie: " << a->locatie << endl;
					cout << "Numar: " << sos->numar << endl;
					cout << "Culoare: " << sos->culoare << endl;
				}
			}
			a = a->urm;
		}
	}
}

void listao::afisareo()
{
	magazin_de_haine* a;
	a = heado;
	if (!a)
	{
		cout << "Lista e vida !" << endl;
	}
	else
	{
		while (a)
		{
			a->afisare();
			cout << endl;
			a = a->urmo;
		}
	}
}

class supraincarcare
{
	string producator, locatie;
	int pret;
public:
	friend ostream& operator<<(ostream& out, supraincarcare& s);
	friend istream& operator>>(istream& in, supraincarcare& s);
	string Producator()
	{
		return producator;
	}
	string Locatie()
	{
		return locatie;
	}
	int Pret()
	{
		return pret;
	}
};

ostream& operator<<(ostream& out, supraincarcare& s)
{
	cout << "\nDatele au fost incarcate din fisier." << endl;
	return out;
}

istream& operator>>(istream& in, supraincarcare& s)
{
	do
	{
		try
		{
			cout << "Dati producator: "; cin >> s.producator;
			if (valid(s.producator) == 0)
				throw MyException1("Producatorul trebuie sa fie un cuvant.", s.producator);
		}
		catch (MyException1 e)
		{
			cout << e.str_what << " : ";
			cout << e.what << endl;
		}
	} while (valid(s.producator) == 0);
	do
	{
		try
		{
			cout << "Dati pret: "; cin >> s.pret;
			if (s.pret < 0)
				throw MyException2("Pretul trebuie mai mare ca zero.", s.pret);
		}
		catch (MyException2 e2)
		{
			cout << e2.str_what << " : ";
			cout << e2.what << endl;
		}
	} while (s.pret < 0);
	cout << "Dati locatie: "; cin >> s.locatie;
	return in;
}

void lista::citireFisier(lista& l, listao& lo)
{
	magazin_de_haine* nou;
	hanorac* ha;
	sapca* sa;
	manusi* man;
	sosete* sos;
	supraincarcare supr;
	string producator, marime, material, culoare, locatie;
	int pret, imprimeu, banda_reglabila, piele, captusite, numar, tip;
	ifstream fis("in.txt");
	if (fis.is_open())
	{
		while (!fis.eof())
		{
			fis >> tip >> producator >> pret >> locatie;
			nou = new magazin_de_haine(tip, producator, pret, locatie);
			if (nou->tip == 0)
			{
				fis >> marime >> imprimeu;
				ha = new hanorac(tip, producator, pret, locatie, marime, imprimeu);
				l.adaugare(ha);
				lo.adaugareo(ha);
			}
			if (nou->tip == 1)
			{
				fis >> material >> banda_reglabila;
				sa = new sapca(tip, producator, pret, locatie, material, banda_reglabila);
				l.adaugare(sa);
				lo.adaugareo(sa);
			}
			if (nou->tip == 2)
			{
				fis >> piele >> captusite;
				man = new manusi(tip, producator, pret, locatie, piele, captusite);
				l.adaugare(man);
				lo.adaugareo(man);
			}
			if (nou->tip == 3)
			{
				fis >> numar >> culoare;
				sos = new sosete(tip, producator, pret, locatie, numar, culoare);
				l.adaugare(sos);
				lo.adaugareo(sos);
			}
		}
		if (fis.eof())
		{
			cout << supr;
		}
		else
		{
			cout << "\nDatele nu au fost incarcate din fisier." << endl;
		}
	}
	else
	{
		cout << "\nFisierul nu a fost deschis." << endl;
	}
}

void lista::afisareFisier(lista& l)
{
	magazin_de_haine* a;
	a = head;
	hanorac* ha;
	sapca* sa;
	manusi* man;
	sosete* sos;
	ofstream fiso;
	fiso.open("out.txt");
	if (fiso.is_open())
	{
		if (!a)
		{
			cout << "Lista este vida." << endl;
		}
		else
		{
			while (a)
			{
				if (a->tip == 0)
				{
					ha = (hanorac*)a;
					fiso << endl;
					fiso << "Producator: " << a->producator << endl;
					fiso << "Pret: " << a->pret << endl;
					fiso << "Locatie: " << a->locatie << endl;
					fiso << "Marime: " << ha->marime << endl;
					fiso << "Imprimeu: " << ha->imprimeu << endl << endl;
				}
				if (a->tip == 1)
				{
					sa = (sapca*)a;
					fiso << endl;
					fiso << "Producator: " << a->producator << endl;
					fiso << "Pret: " << a->pret << endl;
					fiso << "Locatie: " << a->locatie << endl;
					fiso << "Material: " << sa->material << endl;
					fiso << "Banda reglabila: " << sa->banda_reglabila << endl << endl;
				}
				if (a->tip == 2)
				{
					man = (manusi*)a;
					fiso << endl;
					fiso << "Producator: " << a->producator << endl;
					fiso << "Pret: " << a->pret << endl;
					fiso << "Locatie: " << a->locatie << endl;
					fiso << "Piele: " << man->piele << endl;
					fiso << "Captusite: " << man->captusite << endl << endl;
				}
				if (a->tip == 3)
				{
					sos = (sosete*)a;
					fiso << endl;
					fiso << "Producator: " << a->producator << endl;
					fiso << "Pret: " << a->pret << endl;
					fiso << "Locatie: " << a->locatie << endl;
					fiso << "Numar: " << sos->numar << endl;
					fiso << "Culoare: " << sos->culoare << endl << endl;
				}
				a = a->urm;
			}
		}
		cout << "\nLista este salvata in fisierul 'out.txt'." << endl;
		fiso.close();
	}
	else
	{
		cout << "Nu s-a putut deschide fisierul." << endl;
	}
	cout << endl;
}

void lista::actualizare_info(int alg)
{
	magazin_de_haine* a;
	a = head;
	hanorac* ha;
	sapca* sa;
	manusi* man;
	sosete* sos;
	supraincarcare supr;
	string producator, marime, material, culoare, locatie;
	int pret, imprimeu, banda_reglabila, piele, captusite, numar, tip;
	string caut;
	cout << "\nDati producatorul care il actualizam: "; cin >> caut; cout << endl;
	while (a)
	{
		if (alg == 0)
		{
			if (a->tip == 0)
			{
				ha = (hanorac*)a;
				if (a->producator == caut)
				{
					cout << "Actualizare" << endl;
					cin >> supr;
					cout << "Dati marime: "; cin >> marime;
					cout << "Dati imprimeu: "; cin >> imprimeu; cout << endl;
					a->producator = supr.Producator();
					a->pret = supr.Pret();
					a->locatie = supr.Locatie();
					ha->marime = marime;
					ha->imprimeu = imprimeu;
					cout << "Actualizare cu succes" << endl;
				}
			}
		}
		if (alg == 1)
		{
			if (a->tip == 1)
			{
				sa = (sapca*)a;
				if (a->producator == caut)
				{
					cout << "Actualizare" << endl;
					cin >> supr;
					cout << "Dati material: "; cin >> material;
					cout << "Dati banda reglabila(0/1): "; cin >> banda_reglabila; cout << endl;
					a->producator = supr.Producator();
					a->pret = supr.Pret();
					a->locatie = supr.Locatie();
					sa->material = material;
					sa->banda_reglabila = banda_reglabila;
					cout << "Actualizare cu succes" << endl;
				}
			}
		}
		if (alg == 2)
		{
			if (a->tip == 2)
			{
				man = (manusi*)a;
				if (a->producator == caut)
				{
					cout << "Actualizare" << endl;
					cin >> supr;
					cout << "Dati piele(0/1): "; cin >> piele;
					cout << "Dati captusite(0/1); "; cin >> captusite; cout << endl;
					a->producator = supr.Producator();
					a->pret = supr.Pret();
					a->locatie = supr.Locatie();
					man->piele = piele;
					man->captusite = captusite;
					cout << "Actualizare cu succes" << endl;
				}
			}
		}
		if (alg == 3)
		{
			if (a->tip == 3)
			{
				sos = (sosete*)a;
				if (a->producator == caut)
				{
					cout << "Actualizare" << endl;
					cin >> supr;
					cout << "Dati numarul: "; cin >> numar;
					cout << "Dati culoarea: "; cin >> culoare; cout << endl;
					a->producator = supr.Producator();
					a->pret = supr.Pret();
					a->locatie = supr.Locatie();
					sos->numar = numar;
					sos->culoare = culoare;
					cout << "Actualizare cu succes" << endl;
				}
			}
		}
		a = a->urm;
	}
}

void lista::stergere()
{
	magazin_de_haine* mh = head, * sterg;
	hanorac* ha;
	sapca* sa;
	manusi* man;
	sosete* sos;
	int sel;
	string produ;
	ofstream f;
	f.open("sterse.txt");
	cout << endl;
	cout << "Hanorac - 0" << endl;
	cout << "Sapca - 1" << endl;
	cout << "Manusi - 2" << endl;
	cout << "Sosete - 3" << endl;
	cout << "Din ce categorie stergem -> "; cin >> sel;
	switch (sel)
	{
	case 0:cout << endl;
		cout << "Care este producatorul: "; cin >> produ;
		if (head)
		{
			if (mh->producator == produ)
			{
				f << "Producator: " << mh->producator << endl;
				f << "Pret: " << mh->pret << endl;
				f << "Locatie: " << mh->locatie << endl;
				if (mh->tip == 0)
				{
					ha = (hanorac*)mh;
					f << "Marime: " << ha->marime << endl;
					f << "Imprimeu: " << ha->imprimeu;
				}
				f << endl;
				sterg = head;
				head = sterg->urm;
				delete sterg;
				cout << "\nProdusul a fost sters din lista si salvat in fisier.\n" << endl;
			}
			else
			{
				while (mh->urm && ((mh->urm)->producator != produ))
				{
					mh = mh->urm;
				}
				if (mh->urm == NULL)
				{
					cout << "Producatorul nu exista." << endl;
				}
				else if (mh->urm->producator == produ)
				{
					f << "Producator: " << mh->urm->producator << endl;
					f << "Pret: " << mh->urm->pret << endl;
					f << "Locatie: " << mh->urm->locatie << endl;
					if (mh->urm->tip == 0)
					{
						ha = (hanorac*)mh->urm;
						f << "Marime: " << ha->marime << endl;
						f << "Imprimeu: " << ha->imprimeu;
					}
					f << endl;
					sterg = mh->urm;
					mh->urm = sterg->urm;
					delete sterg;
					cout << "\nProdusul a fost sters din lista si salvat in fisier.\n" << endl;
				}
			}
		}
		break;
	case 1:cout << endl;
		cout << "Care este producatorul: "; cin >> produ;
		if (head)
		{
			if (mh->producator == produ)
			{
				f << "Producator: " << mh->producator << endl;
				f << "Pret: " << mh->pret << endl;
				f << "Locatie: " << mh->locatie << endl;
				if (mh->tip == 1)
				{
					sa = (sapca*)mh;
					f << "Material: " << sa->material << endl;
					f << "Banda reglabila: " << sa->banda_reglabila;
				}
				f << endl;
				sterg = head;
				head = sterg->urm;
				delete sterg;
				cout << "\nProdusul a fost sters din lista si salvat in fisier.\n" << endl;
			}
			else
			{
				while (mh->urm && ((mh->urm)->producator != produ))
				{
					mh = mh->urm;
				}
				if (mh->urm == NULL)
				{
					cout << "Producatorul nu exista." << endl;
				}
				else if (mh->urm->producator == produ)
				{
					f << "Producator: " << mh->urm->producator << endl;
					f << "Pret: " << mh->urm->pret << endl;
					f << "Locatie: " << mh->urm->locatie << endl;
					if (mh->urm->tip == 1)
					{
						sa = (sapca*)mh->urm;
						f << "Material: " << sa->material << endl;
						f << "Banda reglabila: " << sa->banda_reglabila;
					}
					f << endl;
					sterg = mh->urm;
					mh->urm = sterg->urm;
					delete sterg;
					cout << "\nProdusul a fost sters din lista si salvat in fisier.\n" << endl;
				}
			}
		}
		break;
	case 2:cout << endl;
		cout << "Care este producatorul: "; cin >> produ;
		if (head)
		{
			if (mh->producator == produ)
			{
				f << "Producator: " << mh->producator << endl;
				f << "Pret: " << mh->pret << endl;
				f << "Locatie: " << mh->locatie << endl;
				if (mh->tip == 2)
				{
					man = (manusi*)mh;
					f << "Piele: " << man->piele << endl;
					f << "Captusite: " << man->captusite;
				}
				f << endl;
				sterg = head;
				head = sterg->urm;
				delete sterg;
				cout << "\nProdusul a fost sters din lista si salvat in fisier.\n" << endl;
			}
			else
			{
				while (mh->urm && ((mh->urm)->producator != produ))
				{
					mh = mh->urm;
				}
				if (mh->urm == NULL)
				{
					cout << "Producatorul nu exista." << endl;
				}
				else if (mh->urm->producator == produ)
				{
					f << "Producator: " << mh->urm->producator << endl;
					f << "Pret: " << mh->urm->pret << endl;
					f << "Locatie: " << mh->urm->locatie << endl;
					if (mh->urm->tip == 2)
					{
						man = (manusi*)mh->urm;
						f << "Piele: " << man->piele << endl;
						f << "Captusite: " << man->captusite;
					}
					f << endl;
					sterg = mh->urm;
					mh->urm = sterg->urm;
					delete sterg;
					cout << "\nProdusul a fost sters din lista si salvat in fisier.\n" << endl;
				}
			}
		}
		break;
	case 3:cout << endl;
		cout << "Care este producatorul: "; cin >> produ;
		if (head)
		{
			if (mh->producator == produ)
			{
				f << "Producator: " << mh->producator << endl;
				f << "Pret: " << mh->pret << endl;
				f << "Locatie: " << mh->locatie << endl;
				if (mh->tip == 3)
				{
					sos = (sosete*)mh;
					f << "Numar: " << sos->numar << endl;
					f << "Culoare: " << sos->culoare;
				}
				f << endl;
				sterg = head;
				head = sterg->urm;
				delete sterg;
				cout << "\nProdusul a fost sters din lista si salvat in fisier.\n" << endl;
			}
			else
			{
				while (mh->urm && ((mh->urm)->producator != produ))
				{
					mh = mh->urm;
				}
				if (mh->urm == NULL)
				{
					cout << "Producatorul nu exista." << endl;
				}
				else if (mh->urm->producator == produ)
				{
					f << "Producator: " << mh->urm->producator << endl;
					f << "Pret: " << mh->urm->pret << endl;
					f << "Locatie: " << mh->urm->locatie << endl;
					if (mh->urm->tip == 3)
					{
						sos = (sosete*)mh->urm;
						f << "Numar: " << sos->numar << endl;
						f << "Culoare: " << sos->culoare;
					}
					f << endl;
					sterg = mh->urm;
					mh->urm = sterg->urm;
					delete sterg;
					cout << "\nProdusul a fost sters din lista si salvat in fisier.\n" << endl;
				}
			}
		}
		break;
	}
}

int main()
{
	system("color 3");
	char x = 219;
	int opt;
	int alg;
	int sel;
	lista l;
	listao lo;
	lo.heado = NULL;
	l.head = NULL;
	do
	{
		cout << "   1.Citirea informatiilor din fisier." << endl;
		cout << "   2.Afisare in terminal." << endl;
		cout << "   3.Ordonare descrescatoare dupa pret." << endl;
		cout << "   4.Stergerea unui produs si salvarea acestuia intr-un fisier." << endl;
		cout << "   5.Modificarea informatiilor unui produs." << endl;
		cout << "   6.Salvare lista in fisier." << endl;
		cout << "   0.Iesire" << endl;
		cout << "Dati optiunea dvs: "; cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "	Se incarca..." << endl;
			cout << "    ";
			for (int i = 0; i < 20; i++)
			{
				cout << x;
				Sleep(50);
			}
			l.citireFisier(l, lo);
			cout << endl;
			break;
		case 2:cout << endl;
			cout << "1.Afisare toate produsele." << endl;
			cout << "2.Afisare hanorace." << endl;
			cout << "3.Afisare sepci." << endl;
			cout << "4.Afisare manusi." << endl;
			cout << "5.Afisare sosete." << endl;
			cout << "Dati optiunea dvs: "; cin >> alg; cout << endl;
			l.afisare_lista(alg);
			cout << endl;
			break;
		case 4:l.stergere();
			break;
		case 5:cout << endl;
			cout << "Hanorac - 0" << endl;
			cout << "Sapca - 1" << endl;
			cout << "Manusi - 2" << endl;
			cout << "Sosete - 3" << endl;
			cout << "Dati carui produs schimbati info -> "; cin >> sel;
			l.actualizare_info(sel);
			cout << endl;
			break;
		case 3:cout << endl;
			lo.afisareo();
			break;
		case 6:l.afisareFisier(l);
			break;
		case 0:break;
		default:cout << endl;
			cout << "Comanda gresita." << endl;
			break;
		}
	} while (opt != 0);
	system("pause");
	return 0;
}
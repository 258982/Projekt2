

#include <iostream>
#include <fstream>
#include "sortowania.h"
using namespace std;


int main()
{
	int ile_el;
	cout << "Ile elementow posortować? "<<" ";
	cin >> ile_el;
	
		fstream plik("wyniki.txt", ios::app);
		sortowania a, b, c;
		a.wczytaj(ile_el);

		clock_t start = clock();
		a.szybkie(0, ile_el - 1);
		clock_t end = clock();
		double elapsed = (end - start) ;
		plik << " Szybkie, ilość elementow:" << ile_el << " ;" << elapsed << "; srednia: "<<a.srednia()<<"; mediana:"<< a.mediana() << endl;

		b.wczytaj(ile_el);

		start = clock();
		b.scalanie(0, ile_el - 1);
		end = clock();
		elapsed = double(end - start) ;
		plik << "Przez scalanie, ilość elementow: " << ile_el << " ;" << elapsed << "; srednia:" << a.srednia() << "; mediana:" << a.mediana() << endl;

		c.wczytaj(ile_el);

		start = clock();
		c.kopcowanie();
		end = clock();
		elapsed = double(end - start);
		plik << " Przez kopcowanie, ilość elementow:" << ile_el << " ;" << elapsed << "; srednia:" << a.srednia() << "; mediana:" << a.mediana() << endl;

		plik.close();
	

}


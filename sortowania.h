#pragma once


#include "struktury.h"
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

class sortowania
{
	dane* tab;
	dane* pom;
	int n;
public:
	sortowania()
	{
		tab = nullptr;
		n = 0;
	}
// wyliczenie sredniej
	double srednia()
	{
		double suma = 0;
		for (int i = 0; i < n; i++)
		{
			suma += tab[i].ocena;
		}
		return suma / n;
	}
// wyliczenie mediany 
	double mediana()
	{
		return tab[n / 2].ocena;
	}
//wczytau nie plik
	void wczytaj(int z=INT_MAX )
	{
		fstream plik;
		string dana;
		string tmp;
		plik.open("baza.csv");
		getline(plik, dana);
		while (!plik.eof() && z>n)
		{
			getline(plik, dana);
			tmp = dana.substr(dana.size() - 4, dana.size());

			if(tmp.size()>2)
            {
			if (tmp[0] == ',')
				tmp = dana.substr(dana.size() - 3, dana.size());

			if (tmp[tmp.size() - 1] == '0')
			{
				n++;
				if (tab)
				{
					dane* tmp2 = new dane[n];
					for (int i = 0; i < n-1; i++)
					{
						tmp2[i] = tab[i];

					}
					delete[] tab;
					tab = tmp2;
				}
				else
				{
					tab = new dane[n];
				}
				tab[n - 1].nazwa = dana;
				tab[n - 1].ocena = stod(tmp);

			}
            }
			else
			{
				tab[n - 1].nazwa = dana;
				tab[n - 1].ocena = 0;
			}

		}
		pom = new dane[n];
	}

	//sortowanie przez scalanie
	void scalanie(int p, int k)
	{
		int s, p1, p2;
		s = (p + k + 1) / 2;
		if (s - p > 1)
		{
			scalanie(p, s - 1);
		}
		if (k - s > 0)
		{
			scalanie(s, k);
		}
		p1 = p;
		p2 = s;
		for (int i = p; i < k; i++)
		{
			if (p1 == s || (p2 <= k) && (tab[p1].ocena > tab[p2].ocena))
			{
				pom[i] = tab[p2];
				p2++;
			}
			else
			{
				pom[i] = tab[p1];
				p1++;
			}
		}
		for (int i = p; i < k; i++)
		{
			tab[i] = pom[i];
		}
	}

//sortowanie szybkie 
void szybkie( int l, int p )
{
    int i = l;
	int j = p;
    int x = tab[( l+ p) / 2 ].ocena;
    do
    {
        while( tab[ i ].ocena < x )
             i++;
       
        while( tab[ j ].ocena > x )
             j--;
       
        if( i <= j )
        {
            swap( tab[ i ], tab[ j ] );
           
            i++;
            j--;
        }
    } while( i <= j );
   
    if( l< j ) szybkie(  l, j );
   
    if( p> i ) szybkie(  i, p);
   
}
//sortowanie przez kopcowanie 
	void kopcowanie()
	{
		dane pom;
		dane* tmp;
		tmp = new dane[n + 1];
		for (int i = 0; i < n; i++)
		{
			tmp[i] = tab[i];
		}
		int j,k,m;
		for (int i = 2; i <= n; i++)
		{
			j = i;
			k = j / 2;
			pom = tmp[i];
				while ((k > 0) && tmp[k].ocena < pom.ocena)
				{
					tmp[j] = tmp[k];
					j = k;
					k = j / 2;
				}
				tmp[j] = pom;

		}

		for (int i = n; i > 1; i--)
		{
			swap(tmp[1], tmp[i]);
			j = 1;
			k = 2;
			while (k < i)
			{
				if (k + 1 < i && tmp[k + 1].ocena > tmp[k].ocena)
				{
					m = k + 1;
				}
				else
				{
					m = k;
				}
				if (tmp[m].ocena <= tmp[j].ocena)
				{
					break;
				}
				swap(tmp[j], tmp[m]);
				j = m;
				k = j + j;
			}
		}

	}

};

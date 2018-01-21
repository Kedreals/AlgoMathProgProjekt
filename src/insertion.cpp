#include "sorting.hpp"
#include <iostream>
using namespace std;

/*Funktion, die die Position im Array ausgibt,
in welcher der Wert "key" eingefügt werden soll.*/                                                                            
int BinarySearch(int a[], int key, int Laenge)
{
	int links = 0;
	int rechts = Laenge-1;
	
	while (links<=rechts)
	{
		int mitte = links + ((rechts-links)/2);
		
		//Zuerst wird in der Mitte des Arrays gesucht.
		if (a[mitte]==key)
			return mitte;
		else
			/*Falls "key" kleiner bzw. größer ist als der Mittelwert,kann der 
			Teil rechts bzw. links vom Mittelwert ignoriert werden.*/
			if (a[mitte]>key)
				rechts=mitte-1;
			else
				links=mitte+1;
	}
	/*Falls links>rechts, muss das Element an der Stelle
	"links" eingefügt werden.*/ 
	return links;
}

/*Funktion, die einen Array durch Einfügen mittels binärer
Suche sortiert.*/
void InsertionSort(int Laenge, int a[])
{
    int i, position, j, key;
 
    for (i = 1; i < Laenge; i++)
    {
        
        key = a[i];
        
        /*Als Wert für die Länge wird hier i, beginnend bei 1 eingesetzt,
        da die binäre Suche nur mit sortierten Arrays funktioniert.
		Es soll die Position des Elementes "key" ermittelt werden.*/
        position = BinarySearch(a, key, i);
 		
 		//Die for-schleife fügt das "key"-Element an der gefundenen Position ein.
        for (j=i;j>position;j--)
        {
            a[j] = a[j-1];
        }
        a[position]=key;
    }
}

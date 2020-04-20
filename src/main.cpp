#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej

  
  cout << endl << " Start programu " << endl << endl;
  cin>>UklRown;
  cout<<UklRown;
  if(UklRown.Oblicz())
  {
    cout<<"wynik :"<<endl;
    cout<<UklRown.zwroc_wynik()<<endl;
    UklRown.blad();
  }
}

#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"
#include <cmath>
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {
  Macierz Mac;
  Wektor Wek;
  Wektor wynik;
  public:
  void blad();
 Wektor zwroc_wynik() const
  {
    return wynik;
  }

  Macierz zwroc_mac() const
  {
    return Mac;
  }

  Macierz & ustaw_mac() 
  {
    return Mac;
  }

  Wektor zwroc_Wektor() const
  {
    return Wek;
  }

  Wektor & ustaw_Wektor() 
  {
    return Wek;
  }
  bool Oblicz();
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream                  &Strm, 
                            const UkladRownanLiniowych    &UklRown
                          );


#endif

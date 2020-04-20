#include "UkladRownanLiniowych.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

std::istream &operator>>(std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Strm >> UklRown.ustaw_mac() >> UklRown.ustaw_Wektor();
    return Strm;
}

std::ostream &operator<<(std::ostream &Strm, const UkladRownanLiniowych &UklRown)
{
    Strm << "M^T" << std::endl;
    Strm << UklRown.zwroc_mac() << std::endl;
    Strm << "Wektor wyrazow wolnych" << std::endl;
    Strm << UklRown.zwroc_Wektor() << std::endl;
    return Strm;
}

void UkladRownanLiniowych::blad()
{
    std::cout<<"wektor bledu "<<Mac*wynik-Wek<<std::endl;
    std::cout<<"Dl wekotra bledu "<<sqrt((Mac*wynik-Wek)*(Mac*wynik-Wek))<<std::endl;
}
 bool UkladRownanLiniowych::Oblicz()
 {
    double Wyz;
    Macierz tmp;
    Mac.wyznacznik_Gauss();
    Wyz=Mac.zwroc_wyzn();
    if(Wyz==0)
    {
        for(int i=0; i<ROZMIAR; i++)
        {
            tmp=Mac;
            tmp[i]=Wek;
            tmp.wyznacznik_Gauss();
            if(tmp.zwroc_wyzn()==0)
            {
            std::cout<<"uklad nieoznaczony"<<std::endl;
            return false;
            }

        }

            std::cout<<"brak rozwiazan"<<std::endl;
            return false;
    }


        for(int i=0; i<ROZMIAR; i++)
        {
            tmp=Mac;
            tmp[i]=Wek;
            tmp.wyznacznik_Gauss();
            wynik[i]=tmp.zwroc_wyzn()/Mac.zwroc_wyzn();
        }
        return true;
 }
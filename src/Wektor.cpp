#include "Wektor.hh"

Wektor Wektor::operator+(Wektor Skl)
{
    Wektor wynik;
    for (int i = 0; i < ROZMIAR; i++)
    {
        wynik[i] = Tablica[i] + Skl[i];
    }
    return wynik;
}

Wektor Wektor::operator-(Wektor Skl)
{
    Wektor wynik;
    for (int i = 0; i < ROZMIAR; i++)
    {
        wynik[i] = Tablica[i] - Skl[i];
    }
    return wynik;
}

double Wektor::operator*(Wektor Skl)
{
    double wynik = 0;
    for (int i = 0; i < ROZMIAR; i++)
    {
        wynik = wynik + Tablica[i] * Skl[i];
    }
    return wynik;
}

Wektor Wektor::operator*(double Skl)
{

    Wektor wynik;
    for (int i = 0; i < ROZMIAR; i++)
    {
        wynik[i] = Tablica[i] * Skl;
    }
    return wynik;
}
Wektor Wektor::operator/(double Skl)
{
    Wektor wynik;
    for (int i = 0; i < ROZMIAR; i++)
    {
        wynik[i] = Tablica[i] / Skl;
    }
    return wynik;
}

std::istream &operator>>(std::istream &Strm, Wektor &Wek)
{
    for (int i = 0; i < ROZMIAR; i++)
        Strm >> Wek[i];

    return Strm;
}

std::ostream &operator<<(std::ostream &Strm, const Wektor &Wek)
{
    for (int i = 0; i < ROZMIAR; i++)
        Strm << Wek[i] << "\t";

    return Strm;
}
#include "Macierz.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
std::istream &operator>>(std::istream &Strm, Macierz &Mac)
{
    for (int i = 0; i < ROZMIAR; i++)
        Strm >> Mac[i];

    return Strm;
}

std::ostream &operator<<(std::ostream &Strm, const Macierz &Mac)
{
    for (int i = 0; i < ROZMIAR; i++)
        Strm << Mac[i] << std::endl;

    return Strm;
}
Wektor Macierz::operator*(Wektor Skl)
{
    Wektor wynik;
    for (int i = 0; i < ROZMIAR; i++)
        wynik[i] = 0;
    for (int i = 0; i < ROZMIAR; i++)
        for (int j = 0; j < ROZMIAR; j++)
            wynik[i] = wynik[i] + Tablica[j][i] * Skl[j];

    return wynik;
}
void Macierz::wyznacznik_Gauss()
{
    Macierz tmp = *this;
    for (int i = 0; i < ROZMIAR; i++) // przejscie po wszystkich wierszach macierzy
    {
        for (int j = i + 1; j < ROZMIAR; j++) // przejscie i spradzenie czy na przekontnej jest 0 jesli tak to zamiana wierszy
        {
            if (tmp[i][i] == 0)
                std::swap(tmp[i], tmp[j]);
        }
        if (tmp[i][i] == 0) // jesli nadal po zamainach na przekatnej ejst 0 wzynacznik jest rowny 0
        {
            wyznacznik = 0;
            return;
        }
        /**
         * 2 3 4
         * 1 3 1
         * 2 1 5

         */
        for (int j = i + 1; j < ROZMIAR; j++) // zerowanie itej kolumny
        {
            tmp[j] = tmp[j] - tmp[i] * (tmp[j][i] / tmp[i][i]);
        }
    }

    wyznacznik = 1;
    for (int i = 0; i < ROZMIAR; i++)
        wyznacznik = wyznacznik * tmp[i][i];
}
//TODO
// 1. Zrobic funkcje liczaca argument podanej liczby zespolonej -- DONE
// 2. Zrobic menu wyboru (moge zrobic to na while(true) i prosic o to co chce zrobic uzytkownik i na koncu danego if-a dac break;) -- DONE
// 3. Ogarnac zeby losowalo tez ujemne

#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
#include <cmath>

struct Lzespolona
{
    float Re;
    float Im;
    float liczba;
};

void wypelnij(Lzespolona tzespolone[], int rozmiar)
{
    float lzespolonaRe;
    float lzespolonaIm;

    for (int i = 0; i < rozmiar; i++)
    {
        lzespolonaRe = rand() % 100 + 1;
        lzespolonaIm = rand() % 100 + 1;
        
        Lzespolona zesp;
        zesp.Re = lzespolonaRe;
        zesp.Im = lzespolonaIm;

        tzespolone[i] = zesp;
    }
}
void wczytaj(Lzespolona tzespolone[], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << "Podaj czesc rzeczywista i urojona liczby zespolonej" << std::endl << std::endl;

        float lzespolonaRe;
        float lzespolonaIm;

        std::cin >> lzespolonaRe;
        std::cin >> lzespolonaIm;

        tzespolone[i] = { lzespolonaRe, lzespolonaIm };
    }
}
void wydrukuj(const Lzespolona tzespolone[], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << "[ " << tzespolone[i].Re << " + " << tzespolone[i].Im << "i ] ";
    }
}
float modul(const Lzespolona & liczba)
{
    float wynik = sqrt((float)liczba.Re * liczba.Re + liczba.Im * liczba.Im);
    return wynik;
}
float argument(const Lzespolona & liczba)
{
    float modul = sqrt((float)liczba.Re * liczba.Re + liczba.Im * liczba.Im);
    float sinus = (float)liczba.Im / modul;
    float cosinus = (float)liczba.Re / modul;
    float kat = asin(sinus);
    return kat;
}
Lzespolona suma(const Lzespolona& licz1, const Lzespolona &licz2)
{
    Lzespolona wynik = { licz1.Re + licz2.Re, licz1.Im + licz2.Im };
    return wynik;
}

Lzespolona iloczyn(const Lzespolona& licz1, const Lzespolona& licz2)
{
    Lzespolona iloczyn = { licz1.Re * licz2.Re, licz1.Im * licz2.Im };
    return iloczyn;
}


int main()
{
    std::string czyLosowane, wybor, wyborZ{"T"};
    const int n = 10;
    srand(time(NULL));
    Lzespolona tab[n]{0};
    int liczba, pozycja1, pozycja2;
    bool hasGenerated{false};

    std::cout << "Czy chcesz uzyskac nowy zbior liczb zespolonych?" << std::endl;
    std::cout << "T/N" << std::endl;
    std::cin >> wybor;
    std::cout << std::endl;

    if (wybor == "T" or wybor == "t")
    {
        std::cout << "Chcesz wylosowac czy wpisac do tablicy recznie?" << std::endl;
        std::cout << "losuj/wpisz" << std::endl;
        std::cin >> wybor;

        if (wybor == "losuj")
        {
            wypelnij(tab, n);
            wydrukuj(tab, n);
            hasGenerated = true;
        }
        else if (wybor == "wpisz")
        {
            wczytaj(tab, n);
            wydrukuj(tab, n);
            hasGenerated = true;
        }
        else
        {
            std::cout << "We no sluchaj co sie do ciebie mowi, nie ma liczb zespolonych" << std::endl;
        }
    }

    while (wyborZ == "T" or wyborZ == "t")
    {

        if (hasGenerated == false)
        {
            std::cout << "Czy chcesz uzyskac nowy zbior liczb zespolonych?" << std::endl;
            std::cout << "T/N" << std::endl;
            std::cin >> wybor;
            std::cout << std::endl;

            if (wybor == "T" or wybor == "t")
            {
                std::cout << "Chcesz wylosowac czy wpisac do tablicy recznie?" << std::endl;
                std::cout << "losuj/wpisz" << std::endl;
                std::cin >> wybor;

                if (wybor == "losuj")
                {
                    wypelnij(tab, n);
                    wydrukuj(tab, n);
                    hasGenerated = true;

                }
                else if (wybor == "wpisz")
                {
                    wczytaj(tab, n);
                    wydrukuj(tab, n);
                    hasGenerated = true;
                }
                else
                {
                    std::cout << "We no sluchaj co sie do ciebie mowi, nie ma liczb zespolonych" << std::endl;
                }
            }
        }

        if (hasGenerated == true)
        {
            std::cout << std::endl << "Pytanie mam szefie, co chcesz zrobic?" << std::endl;
            std::cout << "modul/suma/iloczyn/argument" << std::endl;
            std::cin >> wybor;


            if (wybor == "modul")
            {
                std::cout << std::endl;
                std::cout << "Podaj liczbe ktorej modul chcialbys poznac" << std::endl;
                std::cin >> liczba;
                std::cout << modul(tab[liczba - 1]);

            }

            if (wybor == "suma")
            {
                std::cout << std::endl;
                std::cout << "Podaj 2 pozycje tablicy by obliczyc sume liczb tam zapisanych" << std::endl;
                std::cin >> pozycja1 >> pozycja2;

                std::cout << suma(tab[pozycja1 - 1], tab[pozycja2 - 1]).Re << " + " << suma(tab[pozycja1 - 1], tab[pozycja2 - 1]).Im << "i";

            }

            if (wybor == "iloczyn")
            {
                std::cout << std::endl;
                std::cout << "Podaj 2 pozycje tablicy by obliczyc iloczyn liczb tam zapisanych" << std::endl;
                std::cin >> pozycja1 >> pozycja2;

                std::cout << iloczyn(tab[pozycja1 - 1], tab[pozycja2 - 1]).Re << " + " << iloczyn(tab[pozycja1 - 1], tab[pozycja2 - 1]).Im << "i";

            }

            if (wybor == "argument")
            {
                std::cout << std::endl;
                std::cout << "Podaj liczbe ktorej argument chcialbys poznac" << std::endl;
                std::cin >> liczba;
                std::cout << argument(tab[liczba - 1]);
            }
        }

        std::cout << std::endl << "Czy chcesz kontynuowac i wykonac inna operacje?" << std::endl;
        std::cout << "T/N" << std::endl;
        std::cin >> wyborZ;
        hasGenerated = false;
        
    }
}


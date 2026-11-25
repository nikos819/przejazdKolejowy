
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

enum Stan
{
    OTWARTY,
    ZAMYKANIE,
    ZAMKNIETY,
    POCIAG,
    OTWIERANIE
};

Stan stan = OTWARTY;

bool samochod = false;
bool pociag = false;
bool alarm = false;

int mandaty = 0;

DWORD czas;

void pokazStan()
{
    cout << "\n----------------------\n";

    switch(stan)
    {
        case OTWARTY:
            cout << "ROGATKI OTWARTE\n";
            break;

        case ZAMYKANIE:
            cout << "ZAMYKANIE ROGATEK\n";
            break;

        case ZAMKNIETY:
            cout << "ROGATKI ZAMKNIETE\n";
            break;

        case POCIAG:
            cout << "POCIAG PRZEJEZDZA\n";
            break;

        case OTWIERANIE:
            cout << "OTWIERANIE ROGATEK\n";
            break;
    }

    cout << "Samochod na torach: " << (samochod ? "TAK" : "NIE") << endl;
    cout << "Alarm: " << (alarm ? "TAK" : "NIE") << endl;
    cout << "Mandaty: " << mandaty << endl;

    cout << "----------------------\n";
}


// Wykrycie pociagu

void wykryjPociag()
{
    if(pociag)
    {
        cout << "Pociag jest juz obslugiwany!\n";
        return;
    }

    if(stan == OTWARTY)
    {
        pociag = true;

        stan = ZAMYKANIE;
        czas = GetTickCount() + 3000;

        cout << "WYKRYTO POCIAG!\n";
        cout << "Rogatki zaczynaja sie zamykac.\n";
    }
    else if(stan == ZAMKNIETY)
    {
        pociag = true;

        czas = GetTickCount() + 10000;

        cout << "WYKRYTO POCIAG!\n";
        cout << "Rogatki sa juz zamkniete.\n";
        cout << "Rozpoczeto odliczanie 10 sekund.\n";
    }
    else
    {
        cout << "Nie mozna teraz wykryc kolejnego pociagu!\n";
    }
}



// Wykrycie samochodu
void wykryjSamochod()
{
    if(samochod)
    {
        cout << "Samochod juz jest na torach!\n";
        return;
    }

    samochod = true;

    cout << "WYKRYTO SAMOCHOD!\n";

    if(stan != OTWARTY)
    {
        alarm = true;
        mandaty++;

        cout << "!!! ALARM !!!\n";
        cout << "Wystawiono mandat!\n";
    }
    else
    {
        cout << "Samochod przejezdza prawidlowo.\n";
    }
}


// Samochod opuszcza przejazd
void wyjazdSamochodu()
{
    if(!samochod)
    {
        cout << "Nie ma samochodu na torach.\n";
        return;
    }

    samochod = false;

    cout << "Samochod opuscil przejazd.\n";
}


// Przycisk droznika
void przyciskDroznika()
{
    if(pociag)
    {
        cout << "Nie mozna otworzyc rogatek podczas przejazdu pociagu!\n";
        return;
    }

    if(samochod)
    {
        cout << "Na torach znajduje sie samochod!\n";
        return;
    }

    if(stan == OTWARTY)
    {
        stan = ZAMYKANIE;
        czas = GetTickCount() + 3000;

        cout << "Droznik zamyka rogatki.\n";
    }
    else if(stan == ZAMKNIETY)
    {
        stan = OTWIERANIE;
        czas = GetTickCount() + 3000;

        cout << "Droznik otwiera rogatki.\n";
    }
    else
    {
        cout << "Rogatki sa w ruchu!\n";
    }
}


// Automatyczna obsluga czasu
void aktualizuj()
{
    DWORD teraz = GetTickCount();

    if((LONG)(teraz - czas) >= 0)
    {
        if(stan == ZAMYKANIE)
        {
            stan = ZAMKNIETY;

            if(pociag)
            {
                cout << "Rogatki zamkniete. Oczekiwanie 10 sekund.\n";
                czas = teraz + 10000;
            }
            else
            {
                cout << "Rogatki zamkniete.\n";
            }
        }

        else if(stan == ZAMKNIETY && pociag)
        {
            if(samochod)
            {
                alarm = true;
                cout << "ALARM! Samochod na torach!\n";
                cout << "Pociag oczekuje na opuszczenie przejazdu.\n";
                czas = teraz + 1000;
            }
            else
            {
                cout << "POCIAG PRZEJEZDZA!\n";
                stan = POCIAG;
                czas = teraz + 5000;
            }
        }

        else if(stan == POCIAG)
        {
            cout << "Pociag przejechal.\n";
            pociag = false;

            stan = OTWIERANIE;
            czas = teraz + 3000;
        }

        else if(stan == OTWIERANIE)
        {
            stan = OTWARTY;
            cout << "ROGATKI OTWARTE!\n";
        }
    }
}


int main()
{
    cout << "SYSTEM PRZEJAZDU KOLEJOWEGO\n";

    cout << "\n1 - Wykryj pociag";
    cout << "\n2 - Przycisk droznika";
    cout << "\n3 - Wykryj samochod";
    cout << "\n4 - Samochod opuszcza tory";
    cout << "\n0 - Wyjscie\n";

    pokazStan();

    bool dziala = true;

    while(dziala)
    {
        aktualizuj();

        if(kbhit())
        {
            char wybor = getch();

            switch(wybor)
            {
                case '1':
                    wykryjPociag();
                    break;

                case '2':
                    przyciskDroznika();
                    break;

                case '3':
                    wykryjSamochod();
                    break;

                case '4':
                    wyjazdSamochodu();
                    break;

                case '0':
                    dziala = false;
                    break;
            }
        }

        Sleep(50);
    }

    cout << "Koniec programu.\n";

    return 0;
}


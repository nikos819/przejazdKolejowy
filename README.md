# SYSTEM PRZEJAZDU KOLEJOWEGO

## Opis programu

Program symuluje działanie automatycznego przejazdu kolejowego z rogatkami. Umożliwia wykrywanie pociągu i samochodu, sterowanie rogatkami za pomocą przycisku dróżnika oraz obsługę alarmów i mandatów.

Program działa w konsoli i wykorzystuje automatyczną obsługę czasu do symulowania poszczególnych etapów działania przejazdu.

## Funkcje programu

- Wykrywanie nadjeżdżającego pociągu.
- Automatyczne zamykanie rogatek po wykryciu pociągu.
- Automatyczne otwieranie rogatek po przejeździe pociągu.
- Symulacja przejazdu pociągu.
- Wykrywanie samochodu znajdującego się na torach.
- Wykrywanie niebezpiecznych sytuacji i uruchamianie alarmu.
- Naliczanie mandatów za nieprawidłowe zachowanie kierowców.
- Możliwość ręcznego sterowania rogatkami przez dróżnika.
- Wyświetlanie aktualnego stanu przejazdu.

## Dostępne stany przejazdu

- **OTWARTY** – rogatki są otwarte.
- **ZAMYKANIE** – rogatki są w trakcie zamykania.
- **ZAMKNIETY** – rogatki są zamknięte.
- **POCIAG** – pociąg przejeżdża przez przejazd.
- **OTWIERANIE** – rogatki są w trakcie otwierania.

## Sterowanie programem

- **1** – Wykryj pociąg.
- **2** – Przycisk dróżnika (zamykanie lub otwieranie rogatek).
- **3** – Wykryj samochód.
- **4** – Samochód opuszcza tory.
- **0** – Wyjście z programu.

## Czasy działania

- Zamykanie rogatek – 3 sekundy.
- Oczekiwanie na przejazd pociągu po zamknięciu rogatek – 10 sekund.
- Przejazd pociągu – 5 sekund.
- Otwieranie rogatek – 3 sekundy.

## Zasady działania

Po wykryciu pociągu program rozpoczyna zamykanie rogatek. Po ich zamknięciu następuje odliczanie 10 sekund, a następnie symulowany jest przejazd pociągu.

Jeżeli na torach znajduje się samochód, uruchamiany jest alarm, a przejazd pociągu zostaje wstrzymany do momentu opuszczenia torów przez samochód.

Wykrycie samochodu przy zamkniętych lub poruszających się rogatkach powoduje uruchomienie alarmu i naliczenie mandatu.

Po przejeździe pociągu rogatki automatycznie się otwierają.

Dróżnik może również ręcznie sterować rogatkami, jednak nie może ich otworzyć podczas obsługi pociągu ani wtedy, gdy na torach znajduje się samochód.

## Wymagania

- System operacyjny Windows.
- Kompilator obsługujący język C++.
- Obsługa biblioteki `windows.h`.
- Obsługa biblioteki `conio.h`.

## Uruchomienie

1. Zapisz kod źródłowy w pliku z rozszerzeniem `.cpp`.
2. Skompiluj program za pomocą kompilatora C++.
3. Uruchom plik wykonywalny.
4. Steruj programem za pomocą klawiszy przedstawionych w menu.

## Technologie

- C++
- Windows API
- Biblioteka `iostream`
- Biblioteka `windows.h`
- Biblioteka `conio.h`

## Informacja

Program ma charakter edukacyjny i służy do symulacji działania przejazdu kolejowego. Nie jest przeznaczony do sterowania rzeczywistą infrastrukturą kolejową.

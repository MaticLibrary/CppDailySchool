#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Question {
    string questionText;
    vector<string> options;
    int correctOption;
};

void displayQuestion(const Question& q) {
    cout << q.questionText << endl;
    for (size_t i = 0; i < q.options.size(); ++i) {
        cout << i + 1 << ". " << q.options[i] << endl;
    }
}

int main() {
    vector<Question> questions = {
        {"Rozwin skrot HTML:", {"HyperText Markup Language", "Hyperlink Text Management Language", "High-Level Text Machine"}, 1},
        {"Jakim poleceniem instaluje sie zaleznosci aplikacji (np. ReactJS)?", {"npm start", "npm install", "node init"}, 2},
        {"Czym jest protokol HTTP?", {"Protokolem z warstwy aplikacji modelu ISO/OSI", "Formatem komunikacji miedzy klientem a serwerem", "Wszystkie powyzsze"}, 3},
        {"Co oznacza kod odpowiedzi HTTP 401?", {"Nie znaleziono", "Nieautoryzowany dostep", "Blad serwera"}, 2},
        {"Jakim jezykiem jest JavaScript?", {"Kompilowanym", "Interpretowanym", "Zadnym"}, 2},
        {"Co opisuje strukture strony internetowej?", {"CSS", "Obiektowy model dokumentu (DOM)", "JSON"}, 2},
        {"Jaki jest glowny podzial znacznikow w HTML?", {"Liniowe i blokowe", "Otwarte i zamkniete", "Kolorowe i bezbarwne"}, 1},
        {"Number, text, radio, checkbox to typy jakiego znacznika?", {"<div>", "<input>", "<form>"}, 2},
        {"Na czym polega specyficznosc w CSS?", {"Zasada okreslajaca, ktory selektor ma pierwszenstwo", "Szybkosc ladowania stylow", "Wielkosc czcionki"}, 1},
        {"Jakie jest przeznaczenie hooka useEffect w ReactJS?", {"Do stylowania komponentow", "Do wykonywania dzialan po aktualizacji komponentu", "Do tworzenia stanu"}, 2},
        {"Za pomoca jakiego mechanizmu mozna przechwycic zdarzenia w JavaScript?", {"EventEmitter", "EventListener", "FunctionCall"}, 2},
        {"Co mozna zmieniac za pomoca JavaScript na stronach HTML?", {"Style znacznikow", "Zachowania elementow (animacje)", "Wszystkie z powyzszych"}, 3},
        {"Jakie rozszerzenie moze miec komponent ReactJS?", {".html", ".jsx", ".py"}, 2},
        {"Ktorym poleceniem mozna pobrac referencje do obiektu DOM?", {"document.querySelector()", "document.getElementById()", "Wszystkie z powyzszych"}, 3},
        {"Jaki znacznik sluzy do przejscia na inny widok w React Router?", {"<a>", "<Link>", "<Route>"}, 2},
        {"Jak dodac zewnetrzny plik CSS do dokumentu HTML?", {"<style>", "<link rel='stylesheet'>", "<css>"}, 2},
        {"Co oznacza kod odpowiedzi HTTP 304?", {"Nie znaleziono", "Nie zmieniono", "Blad serwera"}, 2},
        {"Ile razy na stronie moga zostac uzyte znaczniki div?", {"Tylko raz", "Nie wiecej niz 10", "Nieograniczona ilosc"}, 3},
        {"Czym jest NodeJS?", {"Framework JavaScript", "Srodowisko uruchomieniowe JS poza przegladarka", "Nowy jezyk programowania"}, 2},
        {"Czym jest ExpressJS?", {"Biblioteka do animacji", "Framework do budowy backendu w Node.js", "Narzedzie do testowania"}, 2},
        {"Co to jest CRUD?", {"Metoda optymalizacji kodu", "Zestaw operacji: Create, Read, Update, Delete", "Typ bazy danych"}, 2},
        {"MongoDB to baza...", {"Relacyjna", "Nierelacyjna (NoSQL)", "Plikowa"}, 2},
        {"Jesli let a = '2', to 2 == a bedzie?", {"true", "false", "blad"}, 1},
        {"Jaka jest glowna cecha slowa kluczowego let w JS?", {"Zakres funkcjonalny", "Zakres blokowy", "Zmienna globalna"}, 2},
        {"Jak dodac element na poczatek tablicy w JS?", {"array.push()", "array.unshift()", "array.pop()"}, 2},
        {"W Node.js uzywany jest silnik JavaScript z...", {"Firefox", "Google Chrome (V8)", "Safari"}, 2},
        {"Jak zastosowac funkcje zwrotna (callback) w JS?", {"Tylko w petlach", "Przekazujac ja jako argument", "Wszystkie powyzsze"}, 3},
        {"Jak dodac nowy element HTML za pomoca JS?", {"document.write()", "document.createElement()", "innerHTML=''"}, 2},
        {"Co to jest hoisting w JavaScript?", {"Przenoszenie deklaracji na poczatek zakresu", "Ukrywanie zmiennych", "Nowy operator"}, 1},
        {"Ktora metoda sluzy do laczenia tablic w JS?", {"array.concat()", "array.join()", "array.split()"}, 1},
        {"Co zwraca typeof [] w JavaScript?", {"'array'", "'object'", "'list'"}, 2},
        {"Ktora wlasnosc CSS odpowiada za kolor tekstu?", {"background-color", "color", "font-color"}, 2},
        {"Jakiego znacznika uzywa sie do tworzenia listy numerowanej?", {"<ul>", "<ol>", "<li>"}, 2},
        {"Co oznacza skrot API?", {"Application Programming Interface", "Advanced Programming Instruction", "Automated Process Integration"}, 1},
        {"Ktora metoda HTTP sluzy do wysylania danych do serwera?", {"GET", "POST", "DELETE"}, 2},
        {"Jak zainicjowac nowy projekt npm w terminalu?", {"npm init", "npm start", "npm new"}, 1},
        {"Co oznacza 'S' w skrocie HTTPS?", {"Secure", "Simple", "Standard"}, 1},
        {"Ktora funkcja sluzy do zatrzymania wykonywania kodu na okreslony czas w JS?", {"setInterval()", "setTimeout()", "wait()"}, 2},
        {"Jakiego typu danych nie ma w JavaScript?", {"integer", "string", "boolean"}, 1},
        {"Ktore narzedzie sluzy do sledzenia zmian w kodzie zrodlowym?", {"Git", "Node.js", "Webpack"}, 1},
        {"Jakiego znacznika uzywa sie do osadzania obrazkow w HTML?", {"<img>", "<image>", "<picture>"}, 1},
        {"Ktora wlasnosc CSS okresla przezroczystosc elementu?", {"visibility", "opacity", "transparency"}, 2},
        {"Co oznacza skrot DOM?", {"Document Object Model", "Data Object Management", "Digital Output Mode"}, 1},
        {"Ktora funkcja sluzy do konwersji stringa na liczbe w JS?", {"toString()", "parseInt()", "toNumber()"}, 2},
        {"Jakiego operatora uzywa sie do sprawdzenia typu i wartosci w JS?", {"==", "===", "="}, 2},
        {"Ktora metoda sluzy do usuwania ostatniego elementu tablicy w JS?", {"pop()", "shift()", "remove()"}, 1},
        {"Jakiego znacznika uzywa sie do tworzenia linku w HTML?", {"<a>", "<link>", "<href>"}, 1},
        {"Ktora wlasnosc CSS okresla rozmiar czcionki?", {"text-size", "font-size", "size"}, 2},
        {"Co oznacza skrot JSON?", {"JavaScript Object Notation", "Java Standard Object Naming", "JavaScript Oriented Notation"}, 1},
        {"Ktora funkcja sluzy do zaokraglania liczby w dol w JS?", {"Math.round()", "Math.floor()", "Math.ceil()"}, 2},
        {"Jakiego znacznika uzywa sie do tworzenia tabel w HTML?", {"<table>", "<tab>", "<grid>"}, 1}
    };

    int score = 0;
    char playAgain;

    do {
        score = 0;
        for (size_t i = 0; i < questions.size(); ++i) {
            cout << "\nPytanie " << i + 1 << "/" << questions.size() << ":\n";
            displayQuestion(questions[i]);

            int userAnswer;
            cout << "\nWybierz odpowiedz (1-" << questions[i].options.size() << "): ";
            cin >> userAnswer;

            if (userAnswer == questions[i].correctOption) {
                cout << " Poprawna odpowiedz!\n";
                score++;
            } else {
                cout << "Bledna odpowiedz! Prawidlowa: " << questions[i].correctOption << ". " << questions[i].options[questions[i].correctOption - 1] << "------------------------------------------\n";
            }
        }

        cout << "\n=== Koniec testu ===\n";
        cout << "Twoj wynik: " << score << "/" << questions.size() << " (" << (score * 100 / questions.size()) << "%)\n";
        cout << "Czy chcesz zagrac jeszcze raz? (T/N): ";
        cin >> playAgain;

    } while (toupper(playAgain) == 'T');

    cout << "\nDziekujemy za udzial w quizie!\n";
    return 0;
}

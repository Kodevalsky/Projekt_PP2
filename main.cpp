#include <iostream>
#include <cstring>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <fstream>

using namespace std;

void wyczyscEkran(){
    for(int i = 0; i < 100; i++)
    {
        cout << "\n";
    }
}

struct rekord{
    int indeks;
    char nazwa[256];
    float stezenie;
    float objetosc;
    char wlasciciel[100];
    string dataPobrania;
    string dataBadan;
    string rodzPrep;
};

struct intNode{
    rekord zapis;
    intNode * pierwszy;
    intNode * nastepny;
};

void wyswietlCalosc(intNode * obiekt){
    intNode * temp = obiekt -> pierwszy;
    int i = 0;
    cout << "Oto lista obecnych w programie próbkek: " << endl;
    while (temp)
    {
        cout << i + 1 << ".   ";
        cout << temp -> zapis.indeks << "/";
        for(int g = 0; temp -> zapis.nazwa[g]; g++)
        {
            cout << temp -> zapis.nazwa[g];
        }
        cout << "/" << temp -> zapis.stezenie << "/";
        cout << temp -> zapis.objetosc << "/";
        for(int s = 0; temp -> zapis.wlasciciel[s]; s++)
        {
            cout << temp -> zapis.wlasciciel[s];
        }
        cout << temp -> zapis.dataPobrania << "/";
        cout << temp -> zapis.dataBadan << "/";
        cout << temp -> zapis.rodzPrep << endl;
        temp = temp -> nastepny;
        i++;
    }
    cout.flush();
    sleep(5);
}

void pierwszeSlowa(){
    cout << "Witaj w bazie danych laboratorium SCP, jak? operacje chcesz przeprowadzic? Wpisz cyfre:" << endl;
    cout << "1 - Dodaj probke do bazy danych." << endl;
    cout << "2 - Usun probke z dazy danych." << endl;
    cout << "3 - Zmien dane probki." << endl;
    cout << "4 - Wyszukaj probke po nazwie." << endl;
    cout << "5 - Zapisz baze na dysku" << endl;
    cout << "6 - Wczytaj baze z dysku" << endl;
    cout << "7 - Wyswietl liste probek" << endl;
    cout << "8 - Wyjdz z programu" << endl;
}

void usun(intNode * obiekt, int nr){
    if(nr == 0)
    {
        intNode * temp = obiekt -> pierwszy;
        obiekt -> pierwszy = temp -> nastepny;
        delete temp;
    }
    else if(nr >= 1)
    {
        int j = 0;
        intNode * temp = obiekt -> pierwszy;
        while(temp -> nastepny)
        {
            j++;
            if(j == nr) break;
            temp = temp -> nastepny;
        }
        if(nr > j)
        {
        cout << "Nie ma takiego elementu w liscie";
        }
        else
        {
            cout << "Usuwanie rejestru..." << endl;
        }
        if (temp -> nastepny = nullptr)
        {
           delete temp -> nastepny;
           temp -> nastepny = nullptr;
        }
    }


}

bool checkTable(intNode * rekord, char searchTable[256])
{
    bool foundVar = true;
    if(rekord == nullptr)
    {
        return false;
    }
    else
    {
        for (int m = 0; m < 256 && rekord->zapis.nazwa[m] != 0; m++) {
            if (rekord->zapis.nazwa[m] != searchTable[m] && rekord->nastepny == nullptr) {
                foundVar = false;
                break;
            } else if (rekord->zapis.nazwa[m] != searchTable[m]) {
                rekord = rekord->nastepny;
                m = -1;
            }
        }
        return foundVar;
    }
}

void dodaj(intNode * obiekt){
    intNode * nowy = new intNode;
    float a;
    char checkValidityTable[256];
    cout << "Podaj indeks:" << endl;
    cin >> a;
    nowy -> zapis.indeks = a;
    string c;
    cout << endl << "Wprowadz nazwe preparatu" << endl;
    cin.ignore();
    here:
    getline(cin, c);
    strcpy(checkValidityTable, c.c_str());
    intNode * vad = obiekt -> pierwszy;
    if (checkTable(vad, checkValidityTable))
    {
        wyczyscEkran();
        cout << "Wprowadzona nazwa nie jest unikalna, wprowadz inna nazwe..." << endl;
        goto here;
    }
    strcpy(nowy -> zapis.nazwa, c.c_str());
    cout << endl << "Wprowadz stezenie preparatu" << endl;
    cin >> a;
    while(a <= 0){
        cout.flush();
        wyczyscEkran();
        cout << "Wprowadzono nieprawidlowa wartosc, wartosc musi byc wieksza od 0" << endl;
        cin >> a;
    }
    nowy -> zapis.stezenie = a;
    cout << endl << "Wprowadz objetosc preparatu" << endl;
    cin >> a;
    while(a <= 0){
        cout.flush();
        wyczyscEkran();
        cout << "Wprowadzono nieprawidlowa wartosc, wartosc musi byc wieksza od 0" << endl;
        cin >> a;
    }
    nowy -> zapis.objetosc = a;
    cout << endl << "Wprowadz wlasciciela preparatu" << endl;
    cin.ignore();
    getline(cin, c);
    strcpy(nowy -> zapis.wlasciciel, c.c_str());
    string b;
    cout << endl << "Wprowadz date pobrania preparatu" << endl;
    cin >> b;
    nowy -> zapis.dataPobrania = b;
    cout << endl << "Wprowadz date badan preparatu" << endl;
    cin >> b;
    nowy -> zapis.dataBadan = b;
    cout << endl << "Wybierz rodzaj preparatu poprzez wybranie odpowiedniego numru:" << endl << "1 - staly" << endl << "2 - rozproszony" << endl << "3 - lotny";
    int k;
    cin >> k;
    tu:
    switch(k)
    {
        case 1:
            nowy -> zapis.rodzPrep = "staly";
            break;
        case 2:
            nowy -> zapis.rodzPrep = "rozproszony";
            break;
        case 3:
            nowy -> zapis.rodzPrep = "lotny";
            break;
        default:
            wyczyscEkran();
            cout << "Wprowadzono nieprawidłową wartość! Wybierz cyfrę 1, 2 lub 3";
            cin >> k;
            goto tu;
    }
    if(obiekt -> pierwszy == nullptr){
        obiekt -> pierwszy = nowy;
        obiekt -> nastepny = nullptr;
    }
    else
    {
        intNode * temp = obiekt -> pierwszy;
        while (temp -> nastepny)
        {
            temp = temp -> nastepny;
        }
        temp -> nastepny = nowy;
        nowy -> nastepny = nullptr;
    }
}

void wyswietlJeden(intNode * temp)
{
    cout << temp -> zapis.indeks << "/";
    for(int g = 0; temp -> zapis.nazwa[g]; g++)
    {
        cout << temp -> zapis.nazwa[g];
    }
    cout << "/" << temp -> zapis.stezenie << "/";
    cout << temp -> zapis.objetosc << "/";
    for(int s = 0; temp -> zapis.wlasciciel[s]; s++)
    {
        cout << temp -> zapis.wlasciciel[s];
    }
    cout << temp -> zapis.dataPobrania << "/";
    cout << temp -> zapis.dataBadan << "/";
    cout << temp -> zapis.rodzPrep << endl;
    cout.flush();
    sleep(4);
}

void update(intNode * mainStruct)
{
    int probkaNumer;
    cout << "Podaj numer probki, ktorej parametr chcesz zmodyfikowac." << endl;
    cin >> probkaNumer;
    intNode * temp;
    temp = mainStruct -> pierwszy;
    for (int f = probkaNumer; f != 1; f--)
    {
        temp = temp -> nastepny;
    }
    cout << "Ktory parametr probki chcesz zmienic?";
    cout << "Kliknij:" << endl << "1 - aby zmienic indeks"
    << "2 - aby zmienic nazwe" << endl
    << "3 - aby zmienic stezenie" << endl
    << "4 - aby zmienic objetosc" << endl
    << "5 - aby zmienic wlasciciela" << endl
    << "6 - aby zmienic date pobrania" << endl
    << "7 - aby zmienic date badan" << endl
    << "8 - aby zmienic rodzaj preparatu" << endl;
    int choice;
    cin >> choice;
    cout << endl << "Wprowadz nowa wartosc:" << endl;
    float a;
    string c;
    switch(choice)
    {
        case 1:
            cin >> a;
            temp -> zapis.indeks = a;
            break;
        case 2:
            cin.ignore();
            getline(cin, c);
            strcpy(temp -> zapis.nazwa, c.c_str());
            break;
        case 3:
            cin >> a;
            temp -> zapis.stezenie = a;
            break;
        case 4:
            cin >> a;
            temp -> zapis.objetosc = a;
            break;
        case 5:
            cin.ignore();
            getline(cin, c);
            strcpy(temp -> zapis.wlasciciel, c.c_str());
            break;
        case 6:
            cin >> c;
            temp -> zapis.dataPobrania = c;
            break;
        case 7:
            cin >> c;
            temp -> zapis.dataBadan = c;
            break;
        case 8:
            cin >> c;
            temp -> zapis.rodzPrep = c;
            break;
    }
    cout << endl;
    wyswietlCalosc(mainStruct);
    wyczyscEkran();
}



intNode * wyszukaj(intNode * mainStruct)
{
    cout << "Wprowadz prosze nazwe probki ktora probujesz wyszukac..." << endl;
    string search;
    char searchTable[256];
    cin.ignore();
    getline(cin, search);
    strcpy(searchTable, search.c_str());
    intNode * temp = mainStruct -> pierwszy;
    bool foundVar = checkTable(temp, searchTable);
    if (!foundVar)
    {
        cout << "Nie znaleziono probki o podanej nazwie" << endl;
        return nullptr;
    }
    else
    {
        cout << "Znaleziono nastepujaca probke o podanej nazwie: " << endl;
        return temp;
    }
}

void zapisDanych(intNode * obiekt)
{
    ofstream baza;
    baza.open("dane.txt", ios::out);
    intNode * temp = obiekt -> pierwszy;
    while (temp)
    {
        baza << temp -> zapis.indeks << "/";
        for(int g = 0; temp -> zapis.nazwa[g]; g++)
        {
            baza << temp -> zapis.nazwa[g];
        }
        baza << "/" << temp -> zapis.stezenie << "/";
        baza << temp -> zapis.objetosc << "/";
        for(int s = 0; temp -> zapis.wlasciciel[s]; s++)
        {
            baza << temp -> zapis.wlasciciel[s];
        }
        baza << temp -> zapis.dataPobrania << "/";
        baza << temp -> zapis.dataBadan << "/";
        baza << temp -> zapis.rodzPrep << endl;
        temp = temp -> nastepny;
    }
    baza.close();
}


void loadDatabase(intNode * obiekt) {
    cout << "Podaj nazwę pliku do wczytania (wraz z rozszerzeniem .txt)" << endl;
    string f, t;
    cin.ignore();
    cin >> f;
    fstream baza;
    baza.open(f, ios::in);
    while(getline(baza, f)) {
        intNode *nowy = new intNode;
        getline(baza, t, '/');
        nowy->zapis.indeks = stoi(t);
        getline(baza, t, '/');
        strcpy(nowy->zapis.nazwa, t.c_str());
        getline(baza, t, '/');
        nowy->zapis.stezenie = stof(t);
        getline(baza, t, '/');
        nowy->zapis.objetosc = stof(t);
        getline(baza, t, '/');
        strcpy(nowy->zapis.wlasciciel, t.c_str());
        getline(baza, t, '/');
        nowy->zapis.dataPobrania = t;
        getline(baza, t, '/');
        nowy->zapis.dataBadan = t;
        getline(baza, t, '\n');
        nowy->zapis.rodzPrep = t;
        if (obiekt->pierwszy == nullptr)
        {
            obiekt->pierwszy = nowy;
            obiekt->nastepny = nullptr;
        }
        else
        {
            intNode *temp = obiekt->pierwszy;
            while (temp->nastepny)
            {
                temp = temp->nastepny;
            }
            temp->nastepny = nowy;
            nowy->nastepny = nullptr;
            obiekt = temp;
        }
    }
}




int main() {
    intNode * lista;
    lista = new intNode;
    lista -> nastepny = nullptr;
    lista -> pierwszy = nullptr;
    int wybor;
    while(wybor != 7)
    {
        pierwszeSlowa();
        cin >> wybor;
        switch(wybor)
        {
            case 1:
                wyczyscEkran();
                dodaj(lista);
                wyczyscEkran();
                wyswietlCalosc(lista);
                wyczyscEkran();
                break;
            case 2:
                wyczyscEkran();
                int input;
                cout << "Ktory rejestr z listy chcesz usunac?" << endl;
                cin >> input;
                usun(lista, input - 1);
                break;
            case 3:
                wyczyscEkran();
                update(lista);
                break;
            case 4:
                wyswietlJeden(wyszukaj(lista));
                break;
            case 5:
                zapisDanych(lista);
                wyczyscEkran();
                break;
            case 6:
                loadDatabase(lista);
                break;
            case 7:
                wyswietlCalosc(lista);
                break;
            case 8:
                return 0;
        }
    }
}

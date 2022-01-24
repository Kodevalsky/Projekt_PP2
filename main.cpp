#include <iostream>
#include <string.h>

using namespace std;

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

void wyswietl(intNode * obiekt){
    intNode * temp = obiekt -> pierwszy;
    int i = 0;
    while (temp)
    {
        cout << temp -> zapis.indeks << endl;
        cout << temp -> zapis.nazwa << endl;
        cout << temp -> zapis.wlasciciel << endl;
        cout << temp -> zapis.objetosc << endl;
        cout << temp -> zapis.rodzPrep << endl;
        temp = temp -> nastepny;
        i++;
    }
}

void pierwszeSlowa(){
    cout << "Witaj w bazie danych laboratorium SCP, jak? operacje chcesz przeprowadzic? Wpisz cyfr?:" << endl;
    cout << "1 - Dodaj probke do bazy danych." << endl;
    cout << "2 - Usun probke z dazy danych." << endl;
    cout << "3 - Zmien dane probki." << endl;
    cout << "4 - Wyszukaj probke po nazwie." << endl;
    cout << "5 - Zapisz baze na dysku" << endl;
    cout << "6 - Wczytaj baze z dysku" << endl;
    cout << "7 - Wyjdz z programu" << endl;
};

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
        if (temp -> nastepny = 0)
        {
           delete temp -> nastepny;
           temp -> nastepny = 0;
           obiekt = temp;
        }
    }


}

void dodaj(intNode * obiekt){
    intNode * nowy = new intNode;
    float a;
    cout << "Podaj indeks:" << endl;
    cin >> a;
    nowy -> zapis.indeks = a;
    string c;
    int i = 0;
    cout << endl << "Wprowadz nazwe preparatu" << endl;
    cin.ignore(INT_MAX, '\n');
    getline(cin, c);
    int n = c.length();
    char char_array[n + 1];
    strcpy(nowy -> zapis.nazwa, c.c_str());
    cout << endl << "Wprowadz stezenie preparatu" << endl;
    cin >> a;
    nowy -> zapis.stezenie = a;
    cout << endl << "Wprowadz objetosc preparatu" << endl;
    cin >> a;
    nowy -> zapis.objetosc = a;
    i = 0;
    cout << endl << "Wprowadz wlasciciela preparatu" << endl;
    cin.ignore(INT_MAX, '\n');
    getline(cin, c);
    strcpy(nowy -> zapis.wlasciciel, c.c_str());
    string b;
    cout << endl << "Wprowadz date pobrania preparatu" << endl;
    cin >> b;
    nowy -> zapis.dataPobrania = b;
    cout << endl << "Wprowadz date badan preparatu" << endl;
    cin >> b;
    nowy -> zapis.dataBadan = b;
    cout << endl << "Wprowadz rodzaj preparatu" << endl;
    cin >> b;
    nowy -> zapis.rodzPrep = b;
    if(obiekt -> pierwszy == 0){
        obiekt -> pierwszy = nowy;
        obiekt -> nastepny = 0;
    }
    else
    {
        intNode * temp = obiekt -> pierwszy;
        while (temp -> nastepny)
        {
            temp = temp -> nastepny;
        }
        temp -> nastepny = nowy;
        nowy -> nastepny = 0;
        obiekt = temp;
    }
}

int main() {
    intNode * lista;
    lista = new intNode;
    lista -> nastepny = 0;
    lista -> pierwszy = 0;
    pierwszeSlowa();
    int wybor;
    while(wybor != 7)
    {
        cin >> wybor;
        switch(wybor)
        {
            case 1:
                dodaj(lista);
                wyswietl(lista);
                break;
            case 2:
                int input;
                cout << "Ktory rejestr z listy chcesz usunac?";
                cin >> input;
                usun(lista, input);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }
    }
    return 0;
}

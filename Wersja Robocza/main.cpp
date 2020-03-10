#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Student
{
    string imie, nazwisko, pesel, indeks,nr;
    bool plec ; //0-meżczyzna 1-kobieta
};

struct Baza
{
    Student baza[100];
    int ilosc;
};

int find_student (Baza &baza, string indeks)
{
    int miejsce;
    for (int i=0;baza.ilosc;i++)
    {
        if (baza.baza[i].indeks==indeks){
            miejsce=i;
            return miejsce;
        }
    }
    return miejsce=-1;
}

/*Student wczytaj_student(Baza &baza)
{
    cout << "Podaj imie studenta: ";
    cin >> baza.baza[baza.ilosc].imie;
    cout << ""<<endl;
    cout << "Podaj nazwisko studenta: ";
    cin >> baza.baza[baza.ilosc].nazwisko;
    cout << ""<<endl;
    cout << "Podaj plec studenta (0-meżczyzna 1-kobieta): ";
    cin >> baza.baza[baza.ilosc].plec;
    cout << ""<<endl;
    cout << "Podaj nr pesel studenta: ";
    cin >> baza.baza[baza.ilosc].pesel;
    cout << ""<<endl;
    cout << "Podaj nr ineksu studenta: ";
    cin >> baza.baza[baza.ilosc].indeks;
    cout << ""<<endl;
    return student;
}*/

void add_student (Baza &baza)
{
    if (baza.ilosc>100)
        cout << "Baza studentow pelna!";
    else
    {
        baza.baza[baza.ilosc].nr=baza.ilosc+1;
        cout << "Podaj imie: " << endl;
        cin>>baza.baza[baza.ilosc].imie;
        cout << "Podaj nazwisko: " << endl;
        cin>>baza.baza[baza.ilosc].nazwisko;
        cout << "Podaj plec(0-mezczyzna 1-kobieta): " << endl;
        cin>>baza.baza[baza.ilosc].plec;
        cout << "Podaj pesel: " << endl;
        cin>>baza.baza[baza.ilosc].pesel;
        cout << "Podaj indeks: " << endl;
        cin >> baza.baza[baza.ilosc].indeks;
        baza.ilosc++;
    }


}

/*void load_student (ifstream &file, Baza &baza)
{
    for (int i=0; i<baza.grupa.size();i++)
    {
        int n=0;
        int j=0;
        for (;n==j;n++)
        {
            getline(file, baza.grupa[i].imie);
        }
        for (; n==j+1;n++)
        {
            getline (file, baza.grupa[i].nazwisko);
        }
        for (; n==j+2;n++)
        {
            string plec;
            getline (file, plec);
            if (plec =="Kobieta")
                baza.grupa[i].plec= true;
            if (plec == "Mezczyzna")
                baza.grupa[i].plec= false;
        }
        for (;n==j+3;n++)
        {
            getline (file, baza.grupa[i].pesel );
        }
        for (;n==j+4;n++)
        {
            getline (file, baza.grupa[i].pesel);
        }
        j=j+4;
    }
}*/

void display_student (Baza &baza, int miejsce)
{
    cout << baza.baza[miejsce-1].nr<<"."<<endl;
    cout << "Imie studenta: "<< baza.baza[miejsce-1].imie<<endl;
    cout << "Nazwisko studenta: " << baza.baza[miejsce-1].nazwisko<<endl;
    if (baza.baza[miejsce-1].plec==0)
    {
        cout << "Plec" << "Mezczyzna" << endl;
    }
    else
    {
        cout << "Kobieta" << endl;
    }
    cout << "Nr pesel: " << baza.baza[miejsce-1].pesel<<endl;
    cout << "Nr indeksu: " << baza.baza[miejsce-1].indeks<<endl;
}

void display_all_students (Baza &baza)
{
    for (int i=0;i<baza.ilosc;i++)
    {
        cout << baza.baza[i].nr<<"."<<endl;
        cout << "Imie studenta: "<< baza.baza[i].imie<<endl;
        cout << "Nazwisko studenta: " << baza.baza[i].nazwisko<<endl;
        if (baza.baza[i].plec==0)
        {
            cout << "Plec" << "Mezczyzna" << endl;
        }
        else
        {
            cout << "Kobieta" << endl;
        }
        cout << "Nr pesel: " << baza.baza[i].pesel<<endl;
        cout << "Nr indeksu: " << baza.baza[i].indeks<<endl;
    }
}

/*void save_students(ofstream &file, Baza baza)
{
    for (int i=0; i<baza.grupa.size();i++)
    {
        file << baza.grupa[i].imie <<endl << baza.grupa[i].nazwisko<<endl;
        if (baza.grupa[i].plec==0)
        {
            file << "Mezczyzna"<< endl;
        }
        else
        {
            file << "Kobieta" <<endl;
        }
        file <<baza.grupa[i].pesel << endl << baza.grupa[i].indeks<<endl;
    }
}*/

void remove_student (Baza &baza, string indeks)
{

}

void menu (Baza &baza)
{

}

int main() {
    Student student1, student2, student3;
    //ifstream full;
    //ofstream empty;
    student1.imie="Adam";
    student1.nazwisko="Nowak";
    student1.plec=0;
    student1.pesel = "00256954682";
    student1.indeks = "253068";

    student2.imie="Agnieszka";
    student2.nazwisko="Kowalska";
    student2.plec=1;
    student2.pesel =  "0024654682";
    student2.indeks = "253025";

    student3.imie="Jan";
    student3.nazwisko="Zamek";
    student3.plec=0;
    student3.pesel = "0024165682";
    student3.indeks = "253099";
    vector<Student>grupa = {student1, student2};
    Baza baza;
    baza.grupa.push_back(student1);
    baza.grupa.push_back(student2);
    add_student(student3, baza);
    //save_students(empty, baza);
    //load_student(full, baza);
    display_all_students(baza.grupa, 3);

    return 0;

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Student
{
    string imie, nazwisko, pesel, indeks;
    bool plec ; //0-meżczyzna 1-kobieta
};

struct Baza
{
    vector<Student>grupa;
};

int find_student (Baza grupa1, string indeks)
{
    int miejsce;
    for (int i=0;i<100;i++)
    {
        if (grupa1.grupa[i].indeks==indeks){
            miejsce=i;
            return miejsce;
        }
    }
    return miejsce=-1;
}

void add_student (Student &student, Baza &baza)
{
    baza.grupa.push_back(student);
}

Student wczytaj_student(Student &student, Baza &baza)
{
    cout << "Podaj imie studenta: ";
    cin >> student.imie;
    cout << ""<<endl;
    cout << "Podaj nazwisko studenta: ";
    cin >> student.nazwisko;
    cout << ""<<endl;
    cout << "Podaj plec studenta (0-meżczyzna 1-kobieta): ";
    cin >> student.plec;
    cout << ""<<endl;
    cout << "Podaj nr pesel studenta: ";
    cin >> student.pesel;
    cout << ""<<endl;
    cout << "Podaj nr ineksu studenta: ";
    cin >> student.indeks;
    cout << ""<<endl;
    return student;
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

void display_student (Student &student)
{
    cout << student.imie << endl;
    cout << student.nazwisko << endl;
    if (student.plec==0)
    {
        cout << "Mezczyzna" << endl;
    }
    else
    {
        cout << "Kobieta" << endl;
    }
    cout << student.pesel << endl;
    cout << student.indeks << endl;
}

void display_all_students (vector<Student>&grupa, int n)
{
    for (int i=0;i<n;i++)
    {
        display_student(grupa[i]);
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
    int n=find_student(baza, indeks);
    baza.grupa.erase(baza.grupa.begin()+n);
}

int main() {
    Student student1, student2, student3;
    //ifstream full;
    //ofstream empty;
    student1.imie="Adam";
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
}

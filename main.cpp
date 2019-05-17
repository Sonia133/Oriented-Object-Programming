#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

class Plata
{
protected:
    string data;
    float suma;
public:
    Plata();
    Plata(string,float);
    Plata(Plata&);
    virtual ~Plata();

    void setSuma(float);
    void setData(string);
    string getData();
    float getSuma();
    friend istream& operator >>(istream&, Plata&);
    Plata& operator =(Plata&);

    virtual void afisare()=0;

};

Plata::Plata()
{
    suma=0;
}

Plata::Plata(string s,float f)
{
    data=s;
    suma=f;
}

Plata::Plata(Plata& p)
{
    data=p.data;
    suma=p.suma;
}

Plata::~Plata()
{
    data.erase();
    suma=0;
}

void Plata::setData(string s)
{
    data=s;
}

string Plata::getData()
{
    return data;
}

void Plata::setSuma(float f)
{
    suma=f;
}

float Plata::getSuma()
{
    return suma;
}
Plata& Plata::operator=(Plata& p)
{
    if(this == &p)
        return *this;

    data=p.data;
    suma=p.suma;
    return *this;
}

istream& operator >>(istream& in, Plata& p)
{
    cout << "Data platii?( zi , luna , an )\nExemplu :\n 22.03.2019 " << endl;
    in >> p.data;
    cout<< "Suma platita( x lei si y (de) bani )?\n Exemplu : \n 103.75" << endl;
    in >> p.suma;
    return in;
}
class Numerar : public Plata
{

public:
    Numerar();
    Numerar(string, float);
    Numerar(Numerar&);
    virtual ~Numerar();

    friend istream& operator >>(istream&, Numerar&);
    Numerar& operator =(Numerar&);

    void afisare();
};

Numerar::Numerar() : Plata() {}

Numerar::Numerar(string s, float f) : Plata(s,f) {}

Numerar::Numerar(Numerar& n) : Plata(n.data,n.suma) {}

Numerar::~Numerar() {}

istream& operator >>(istream& in, Numerar& n)
{
    in >> (Plata&)n;

    return in;
}

Numerar& Numerar::operator=(Numerar& n)
{
    if(this == &n)
        return *this;

    static_cast<Plata&>(*this) = (Plata&)n;
    return *this;
}

void Numerar::afisare()
{
    cout << "Plata a fost efectuata in numerar.\n";
    cout << "Data la care a fost efectuata plata : " << data << endl;
    cout << "Suma platita : " << suma << endl;
}

class Card_de_credit : public Plata
{
    string nr_card;
    string sex;
    string nume;
    string prenume;

public:

    Card_de_credit();
    Card_de_credit(string, float,string,string,string,string);
    Card_de_credit(Card_de_credit&);
    virtual ~Card_de_credit();

    friend istream& operator >> (istream&, Card_de_credit&);
    Card_de_credit& operator = (Card_de_credit&);

    void afisare();

};

Card_de_credit::Card_de_credit() : Plata() {}

Card_de_credit::Card_de_credit(string s1, float f, string s2, string s3 ,string s4 ,string s5 ) : Plata(s1,f)
{
    nr_card=s2;
    sex=s3;
    nume=s4;
    prenume=s5;
}

Card_de_credit::Card_de_credit(Card_de_credit& c) : Plata(c.data,c.suma)
{
    nr_card=c.nr_card;
    sex=c.sex;
    nume=c.nume;
    prenume=c.prenume;
}

Card_de_credit::~Card_de_credit()
{
    nr_card.erase();
    sex.erase();
    nume.erase();
    prenume.erase();
}

istream& operator >>(istream& in, Card_de_credit& c)
{
    in >> (Plata&)c;
    cout << "Nr card?\n";
    try
    {
       string input;
       in >> input;
       if((input.size()<13)||(input.size()>16))
         throw 0;
        c.nr_card=input;
    }
    catch (int x)
    {
        cout << "Ati introdus prea putine\multe cifre.";
        return in;
    }

    cout << "Sexul? F sau M\n";
    try
    {
        in >> c.sex;
        if(c.sex.compare("F") != 0 && c.sex.compare("M") != 0)
            throw 0;
    }
    catch(int x)
    {
        cout << "Nu ati introdus F sau M!\n";
        return in;
    }
    cout<<"Numele de familie?\n";
    in >> c.nume;
    cout<<"Prenumele?(in cazul in care aveti mai multe prenume treceti unul singur)\n";
    in >> c.prenume;

    return in;
}

Card_de_credit& Card_de_credit::operator=(Card_de_credit& c)
{
    if(this == &c)
        return *this;

    nr_card=c.nr_card;
    sex=c.sex;
    nume=c.nume;
    prenume=c.prenume;
    return *this;
}

void Card_de_credit::afisare()
{
    cout << "Plata a fost efectuata cu cardul de credit.\n";
    cout << "Data la care a fost efectuata plata : " << data << endl;
    cout << "Suma platita : " << suma << endl;
    cout << "Numele clientului : " << nume << endl;
    cout << "Prenumele clientului : " << prenume << endl;
    cout << "Sexul clientului : " << sex << endl;
    cout << "Numarul cardului de pe care s-a efectuat plata : " << nr_card << endl;
}

class Cec : public Plata
{
    string sex;
    string nume;
    string prenume;

public:

    Cec();
    Cec(string, float,string,string,string);
    Cec(Cec&);
    virtual ~Cec();

    friend istream& operator >>(istream&, Cec&);
    Cec& operator =(Cec&);

    void afisare();

};

Cec::Cec() : Plata() {}

Cec::Cec(string s1, float f, string s3 ,string s4 ,string s5 ) : Plata(s1,f)
{
    sex=s3;
    nume=s4;
    prenume=s5;
}

Cec::Cec(Cec& c) : Plata(c.data,c.suma)
{
    sex=c.sex;
    nume=c.nume;
    prenume=c.prenume;
}

Cec::~Cec()
{
    sex.erase();
    nume.erase();
    prenume.erase();
}

istream& operator >>(istream& in, Cec& c)
{
    in >> (Plata&)c;
    cout << "Sexul? F sau M\n";
    try
    {
        in >> c.sex;
        if(c.sex.compare("F") != 0 && c.sex.compare("M") != 0)
            throw 0;
    }
    catch(int x)
    {
        cout << "Nu ati introdus F sau M!\n";
        return in;
    }
    cout<<"Numele de familie?\n";
    in >> c.nume;
    cout<<"Prenumele?(in cazul in care aveti mai multe prenume treceti unul singur)\n";
    in >> c.prenume;

    return in;
}

Cec& Cec::operator=(Cec& c)
{
    if(this == &c)
        return *this;

    sex=c.sex;
    nume=c.nume;
    prenume=c.prenume;
    return *this;
}

void Cec::afisare()
{
    cout << "Plata a fost efectuata cu un cec.\n";
    cout << "Data la care a fost efectuata plata : " << data << endl;
    cout << "Suma platita : " << suma << endl;
    cout << "Numele clientului : " << nume << endl;
    cout << "Prenumele clientului : " << prenume << endl;
    cout << "Sexul clientului : " << sex << endl;
}

template <class T>
class Gestiune
{
protected:
    static int nr_plati;
    vector<T*> plati;
public:
     Gestiune() {}
    ~Gestiune()
    {
        int i;
        for(i = 0; i < plati.size(); i++)
            delete plati[i];
        nr_plati= 0;
    }
    Gestiune(Gestiune<T> &p)
    {
        plati=p.plati;
    }
    Gestiune<T>& operator +=(T &p)
    {
        plati.push_back(&p);
        nr_plati++;
        return *this;
    }
    static int getNr_plati ()
    {
        return nr_plati;
    }
    void afisare_plati()
    {
        int i;
         for(i = 0; i < plati.size(); i++){
          {

            if ( Numerar *P=dynamic_cast<Numerar*>(plati[i]))
               P->afisare();
            else if ( Card_de_credit *P=dynamic_cast<Card_de_credit*>(plati[i]))
               P->afisare();
            else if ( Cec *P=dynamic_cast<Cec*>(plati[i]))
               P->afisare();


          }
    }

     }
};

template <class T>
int Gestiune<T>::nr_plati=0;

template <>
class Gestiune<char*>
{
    int clienti;
    vector<string>nume_clienti;

public:
    Gestiune()
    {
        clienti = 0;
    }
    ~Gestiune() {}
    Gestiune(Gestiune<char*> &p)
    {
        nume_clienti=p.nume_clienti;
        clienti=p.clienti;
    }
    Gestiune <char*>& operator +=(string s)
    {
        nume_clienti.push_back(s);
        clienti++;
        return *this;
    }
    void afisare_clienti()
    {
        int i;
        try
        {
         if(nume_clienti.size() == 0)
            throw 0;
         cout << "Numarul curent de clienti este : " << clienti << endl;
         for(i = 0; i < nume_clienti.size(); i++)
             cout << nume_clienti[i] << endl;

        }
        catch(int x)
        {
            cout << "Nu a fost inregistrat niciun client(doar pe baza numelui).\n";
        }
    }

};

int main()
{
    int n,out=1;
    Gestiune<Plata> P;
	Gestiune<char*> C;

	 Numerar N;
	 Card_de_credit Cd;
	 Cec K;

    while(out==1)
    {
        cout << "Meniu : \n";
        cout << "Pentru plata numerar apasati tasta 1.\n";
        cout << "Pentru plata cu cardul de credit apasati tasta 2. \n";
        cout << "Pentru plata in cec apasati tasta 3. \n";
        cout << "Pentru a introduce doar numele dumneavoastra in baza de date apasati tasta 4. \n";
        cout << "Pentru a iesi apasati tasta 5.\n";

        cin >> n;
        switch(n)
        {
            case 1 :{
                     cin >> N;
                     P += N;
                     break;
                    }
            case 2 :{
                     cin >> Cd;
                     P += Cd;
                     break;
                    }
            case 3 :{
                     cin >> K;
                     P += K;
                     break;
                    }
            case 4 :{
                     string s;
                     cin >> s;
                     C += s;
                     break;
                    }
            case 5 :{
                     out=0;
                     break;
                    }

        }
    }

    cout << "\nNumarul total de plati efectuate : ";
	cout << P.getNr_plati() << endl;

	P.afisare_plati();
	C.afisare_clienti();

}

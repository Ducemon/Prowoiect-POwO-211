#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <math.h>
#include <string.h>
#include <list>
#include <set>
#include <map>
#include <iterator>
#include<fstream>


using namespace std;

class ReduceriDesu
{
public:

    virtual float PretRedus()=0;
};

class Angajat
{
    const int id;
    char* nume;
    char functie[100];
    double salariu;
    char magazin[100];
    float total_ore;
    int zile_concediu;
    char sex;
    bool concediu;
    int *ore_pe_zi;

public:

    static int nrangajati;

    Angajat():id(0000)
    {
        this->nume=new char[strlen("undeclared")+1];
        strcpy(this->nume,"undeclared");
        strcpy(this->functie,"NuExista");
        this->salariu=0;
        this->total_ore=0;
        this->zile_concediu=21;
        this->sex='O';
        strcpy(this->magazin,"undeclared");
        this->concediu=1;
        this->ore_pe_zi=new int[7];
        for(int i=0;i<7;i++)
        {
            ore_pe_zi[i]=0;

        }


    }

    Angajat(int ID):id(ID)
    {
        this->nume=new char[strlen("undeclared")+1];
        strcpy(this->nume,"undeclared");
        strcpy(this->functie,"NuExista");
        strcpy(this->magazin,"undeclared");
        this->salariu=0;
        this->total_ore=0;
        this->zile_concediu=21;
        this->sex='O';
        this->concediu=1;
        this->ore_pe_zi=new int[7];
        for(int i=0;i<7;i++)
        {
            ore_pe_zi[i]=0;

        }


    }


    ~Angajat()
    {
            if(this->nume!=NULL)
            {
                delete[] this->nume;
            }
            if(this->functie!=NULL)
            {
                delete[] this->functie;
            }
            if(this->ore_pe_zi!=NULL)
            {
                delete[] this->ore_pe_zi;
            }
            if(this->magazin!=NULL)
            {
                delete[] this->magazin;
            }


    }


    Angajat(int ID,char* nume, char functie[100], double salariu,char magazin, float total_ore, int zile_concediu, bool concediu, char sex, int* ore_pe_zi ):id(ID)
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        strcpy(this->functie,functie);
        this->salariu=0;
        this->total_ore=0;
        this->zile_concediu=21;
        this->sex=sex;
        this->concediu=1;
        this->ore_pe_zi=new int[7];
        for(int i=0;i<7;i++)
        {
            ore_pe_zi[i]=0;

        }


    }

    Angajat(const Angajat& ob):id(ob.id)
    {
        this->salariu=ob.salariu;
        this->sex=ob.sex;
        strcpy(this->functie,ob.functie);
        strcpy(this->magazin,ob.magazin);
        this->total_ore=ob.total_ore;
        this->zile_concediu=ob.zile_concediu;
        this->nume=new char[strlen(ob.nume)+1];
        strcpy(this->nume,ob.nume);
        this->ore_pe_zi=new int[7];
        for(int i=0;i<7;i++)
        {
            this->ore_pe_zi[i]=ob.ore_pe_zi[i];
        }
        this->concediu=ob.concediu;
    }


    const int getid()
    {
        return this->id;
    }
    char* getNume()
    {
        return this->nume;
    }
    void setMagazin(char magazin[100])
    {
            Angajat::magazin;
    }
    string getMagazin()
    {
        return this->magazin;
    }
    void setNume(char* nume)
    {
         Angajat::nume;
    }
    string getFunctie()
    {
        return this->functie;
    }

    void setFunctie(char functie[100])
    {
        Angajat::functie;
    }
    double getSalariu()
    {
        return this->salariu;
    }
    void setSalariu(double salariu)
    {
        Angajat::salariu;
    }
    int getZileLibere()
    {
        return this->zile_concediu;
    }
    void setZileLibere(int zile_concediu)
    {
        Angajat::zile_concediu;
    }
    char getSex()
    {
        return this->sex;
    }
    void setSex(char sex)
    {
        Angajat::sex;
    }
    bool getConcediu()
    {
        return this->concediu;
    }
    void setConcediu(bool concediu)
    {
        Angajat::concediu;
    }
    int* getOrePeZi()
    {
        return this->ore_pe_zi;
    }
    void setOrePeZi(int* ore_pe_zi)
    {
        Angajat::ore_pe_zi;
    }
    void setTotalOre(float total_ore)
    {
        Angajat::total_ore;
    }
    float getTotalOre()
    {
            return this->total_ore;
    }

    Angajat& operator =(const Angajat &ang)
    {
        if (this!=&ang)
        {

            this->salariu=ang.salariu;
            this->sex=ang.sex;
            strcpy(this->functie,ang.functie);
            strcpy(this->magazin,ang.magazin);
            this->total_ore=ang.total_ore;
            this->zile_concediu=ang.zile_concediu;
            if(this->nume!=NULL)
            {
                delete[] this->nume;
            }
            this->nume=new char[strlen(ang.nume)+1];
            strcpy(this->nume,ang.nume);
            if(this->ore_pe_zi!=NULL)
            {
                delete[] this->ore_pe_zi;
            }
            this->ore_pe_zi=new int[7];
            for(int i=0;i<7;i++)
            {
                this->ore_pe_zi[i]=ang.ore_pe_zi[i];
            }
            this->concediu=ang.concediu;
        }
    }

    friend ostream& operator<< (ostream& out,  const Angajat ang)
    {

        out<<"\n Angajat: "<<ang.nume<<endl;
        out<<"Functie: "<<ang.functie<<endl;
        out<<"Salariu: "<<ang.salariu<<endl;
        out<<"Magazin: "<<ang.magazin<<endl;
        out<<"Sex: "<<ang.sex<<endl;

        if(ang.concediu==1)
        {
            out<<"Angajatul este momentan in concediu si mai are "<<ang.zile_concediu<<" de zile de concediu ramase"<<endl;
        }
        else
        {
            out<<"Angajatul nu este in concediu si are "<<ang.zile_concediu<<" de zile ramase"<<endl;
        }

        out<<"\n Program: \n Luni: "<<ang.ore_pe_zi[0]<<" ore \n Marti: "<<ang.ore_pe_zi[1]<<" ore \n Miercuri: "<<ang.ore_pe_zi[2]<<" ore \n Joi: "
        <<ang.ore_pe_zi[3]<<" ore \n Vineri: "<<ang.ore_pe_zi[4]<<" ore \n Sambata: "<<ang.ore_pe_zi[5]<<" ore \n Duminica: "<<ang.ore_pe_zi[6]<<" ore \n";

    }

    void AfisareProgram()
    {
        cout<<"\n Total ore saptamana asta: "<<this->total_ore<<endl;
        cout<<"\n Program: \n Luni: "<<this->ore_pe_zi[0]<<" ore \n Marti: "<<this->ore_pe_zi[1]<<" ore \n Miercuri: "<<this->ore_pe_zi[2]<<" ore \n Joi: "
        <<this->ore_pe_zi[3]<<" ore \n Vineri: "<<this->ore_pe_zi[4]<<" ore \n Sambata: "<<this->ore_pe_zi[5]<<" ore \n Duminica: "<<this->ore_pe_zi[6]<<" ore \n";
    }

    friend istream& operator>> (istream& in,  Angajat& ang)
    {

        char aux[100],aux2[100],aux3[100];
        cin.get();
        cout<<"Introdu numele angajatului"<<endl;
        cin.getline(aux,100);
        cout<<"Introdu functia angajatului"<<endl;
        cin.getline(aux2,100);
        cout<<"Introdu magazinul in care lucreaza"<<endl;
        cin.getline(aux3,100);


        if(ang.nume!=NULL)
            delete[] ang.nume;

        ang.nume=new char[strlen(aux)+1];
        strcpy(ang.nume,aux);
        strcpy(ang.functie,aux2);
        strcpy(ang.magazin,aux3);

        cout<<"Introdu salariul angajatului: "<<endl;
        in>>ang.salariu;
        cout<<"Introdu sexul angajatului (o singura litera): "<<endl;
        in>>ang.sex;
        cout<<"Introdu zilele de concediu ramase angajatului: "<<endl;
        in>>ang.zile_concediu;
        cout<<"Daca angajatul este momentan in vacanta, apasati 1. Daca nu, apasati 0"<<endl;
        in>>ang.concediu;
        cout<<"Introdu totalul de ore de saptamana asta ale angajatului"<<endl;
        in>>ang.total_ore;
        cout<<"Introdu nr de ore zilnice pentru ziua corespunzatoare"<<endl;

        if(ang.ore_pe_zi!=NULL)
            delete[] ang.ore_pe_zi;

        ang.ore_pe_zi=new int[7];


        cout<<"\n Luni: ";in>>ang.ore_pe_zi[0];
        cout<<"\n Marti: ";in>>ang.ore_pe_zi[1];
        cout<<"\n Miercuri: ";in>>ang.ore_pe_zi[2];
        cout<<"\n Joi: ";in>>ang.ore_pe_zi[3];
        cout<<"\n Vineri: ";in>>ang.ore_pe_zi[4];
        cout<<"\n Sambata: ";in>>ang.ore_pe_zi[5];
        cout<<"\n Duminica: ";in>>ang.ore_pe_zi[6];

        return in;

    }

    const Angajat operator+(int zile)
    {
        this->zile_concediu=this->zile_concediu+zile;
        return *this;
    }

    const Angajat operator-(int zile)
    {
        this->zile_concediu=this->zile_concediu+zile;
        return *this;
    }

    const Angajat operator++(){
        this->concediu=1;

        return *this;

    }

    const Angajat operator++(int){

        Angajat aux(*this);

        this->concediu=1;

        return aux;


    }
    const Angajat operator--(){
        this->concediu=0;

        return *this;

    }

    const Angajat operator--(int)
    {

        Angajat aux(*this);

        this->concediu=0;

        return aux;


    }
    float operator [](int index)
    {

        if(index<7 && index>0)
            return this->ore_pe_zi[index];
        else {cout<<"Index invalid";
                return -1;

            }
    }
    bool operator ==(Angajat& s1)
    {


        if(s1.salariu == this->salariu && s1.total_ore == this->total_ore && strcmp(this->nume,s1.nume)==0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    bool operator<(const Angajat& s1)const
    {


        if(this->id<s1.id)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }

    bool operator>(const Angajat& s1)const
        {


        if(this->id>s1.id)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }

    Angajat operator +(double a)
    {
        this->salariu=this->salariu+a;
        return *this;
    }
    Angajat operator -(double a)
    {
        this->salariu=this->salariu-a;
        return *this;
    }

    void ModificareProgram()
    {
        cout<<"Introdu numarul de ore saptamanale nou"<<endl;
                    float totalore;
                    this->total_ore=totalore;
                    cout<<"Introdu numarul de ore pe fiecare zi a noii saptamani, astfel incat sa corespunda cu nr de ore"<<endl;
                    cout<<"\n Luni: ";cin>>this->ore_pe_zi[0];
                    cout<<"\n Marti: ";cin>>this->ore_pe_zi[1];
                    cout<<"\n Miercuri: ";cin>>this->ore_pe_zi[2];
                    cout<<"\n Joi: ";cin>>this->ore_pe_zi[3];
                    cout<<"\n Vineri: ";cin>>this->ore_pe_zi[4];
                    cout<<"\n Sambata: ";cin>>this->ore_pe_zi[5];
                    cout<<"\n Duminica: ";cin>>this->ore_pe_zi[6];
    }





};




class carte:public ReduceriDesu
{
    const long isbn;
    float pret;
    char *titlu;
    char tipcoperta;
    char autor[100];
    bool pe_stoc;
    double pagini;
    int reducere;

public:
    static int nrtitluri;

    carte():isbn(rand())
    {
        this->pret=0,00;
        this->titlu=new char[strlen("Coming Soon")+1];
        strcpy(this->titlu,"Coming Soon");
        this->tipcoperta='p';
        strcpy(this->autor,"denis");
        this->pe_stoc=0;
        this->pagini=0;
        this->reducere=0;


    }

    carte(long id,float pret,char *titlu,char tipcoperta,char autor[100], bool pe_stoc, double pagini, int reducere):isbn(id)

    {
        this->pret=pret;
        this->titlu=new char[strlen(titlu)+1];
        strcpy(this->titlu,titlu);
        this->tipcoperta=tipcoperta;
        strcpy(this->autor,autor);
        this->pe_stoc=pe_stoc;
        this->pagini=pagini;
        this->reducere=reducere;




    }

    carte(long id):isbn(id)
    {
        this->pret=0,00;
        this->titlu=new char[strlen("Coming Soon")+1];
        strcpy(this->titlu,"Coming Soon");
        this->tipcoperta='p';
        strcpy(this->autor,"denis");
        this->pe_stoc=0;
        this->pagini=0;
        this->reducere=0;


    }


    const long getISBN()
    {
        return this->isbn;
    }


    float getPret()
    {
        return this->pret;
    }
    char* getTitlu()
    {
        return this->titlu;
    }

    char getTipCoperta()
    {
        return this->tipcoperta;
    }

    string getAutor()
    {
        return this->autor;
    }

    double getPagini()
    {
        return this->pagini;
    }

    bool getPeStoc()
    {
        return this->pe_stoc;
    }
    int getReducere()
    {
        return this->reducere;
    }

    void setPret(float pret)
    {
        carte::pret;
    }
    void setTitlu(char *titlu)
    {
        carte::titlu;
    }
    void setReducere(int reducere)
    {
        carte::reducere;
    }

    void setTipCoperta(char tipcoperta)
    {
        carte::tipcoperta;
    }

    void setAutor(char autor[100])
    {
        carte::autor;
    }
    void setPagini(double pagini)
    {
        carte::pagini;
    }

    void setPeStoc(bool pe_stoc)
    {
        carte::pe_stoc;
    }

    carte(const carte& ob):isbn(ob.isbn)
    {
        this->pret=ob.pret;
        this->tipcoperta=ob.tipcoperta;
        strcpy(this->autor,ob.autor);
        this->pagini=ob.pagini;
        this->pe_stoc=ob.pe_stoc;
        this->titlu=new char[strlen(ob.titlu)+1];
        strcpy(this->titlu,ob.titlu);
        this->reducere=ob.reducere;
    }

    carte& operator =(const carte &ang)
    {
        if (this!=&ang)
        {

            this->pret=ang.pret;
            this->tipcoperta=ang.tipcoperta;
            strcpy(this->autor,ang.autor);
            this->pagini=ang.pagini;
            this->pe_stoc=ang.pe_stoc;
            if(this->titlu!=NULL)
            {
                delete[] this->titlu;
            }
            this->titlu=new char[strlen(ang.titlu)+1];
            strcpy(this->titlu,ang.titlu);

            this->reducere=ang.reducere;
        }
    }






    ~carte()
    {
        if(this->titlu != NULL)
            delete[] this->titlu;
        if(this->autor != NULL)
            delete this->autor;
    }

    float PretRedus()
    {
        int a;
        a=this->reducere;

        if(a!=0)
        {

            float pretred;
            pretred=pret-(pret*a/100);
            pretred=(int)(pretred*100+0.5);
            return float(pretred/100);
        }

    }

    friend ostream& operator<< (ostream& out,  const carte crt)
    {
        out<<"\n"<<crt.titlu<<" de "<<crt.autor<<" - "<<crt.pret<<" lei"<<endl<<"Tipul copertii: ";
        if(crt.tipcoperta=='H')
        {
            out<<"Hardcover"<<endl;
        }
        else
        {
            out<<"Paperback"<<endl;
        }

        if(crt.pe_stoc)
        {
            out<<"Produsul este disponibil"<<endl;
        }
        else
        {
            out<<"Produsul este momentan indisponibil"<<endl;
        }



    }
    friend fstream& operator<< (fstream& out,  const carte crt)
    {
        out<<"\n"<<crt.titlu<<" de "<<crt.autor<<" - "<<crt.pret<<" lei"<<endl<<"Tipul copertii: ";
        if(crt.tipcoperta=='H')
        {
            out<<"Hardcover"<<endl;
        }
        else
        {
            out<<"Paperback"<<endl;
        }

        if(crt.pe_stoc)
        {
            out<<"Produsul este disponibil"<<endl;
        }
        else
        {
            out<<"Produsul este momentan indisponibil"<<endl;
        }



    }

     friend istream& operator>> (istream& in,  carte& crt)

     {

        char aux[100],aux2[100];
        cout<<"Introdu titlul"<<endl;

        in.getline(aux,100);
        cout<<"Introdu autorul"<<endl;
        in.getline(aux2,100);


        if(crt.titlu!=NULL)
            delete[] crt.titlu;

        crt.titlu=new char[strlen(aux)+1];
        strcpy(crt.titlu,aux);
        strcpy(crt.autor,aux2);

        cout<<"Introdu pretul"<<endl;
        in>>crt.pret;
        cout<<"Introdu initiala tipului copertii cu litera mare"<<endl;
        in>>crt.tipcoperta;
        cout<<"Introdu nr. de pagini"<<endl;
        in>>crt.pagini;
        cout<<"Este momentan disponibil? Introduceti 1 daca da si 0 daca nu"<<endl;
        in>>crt.pe_stoc;

        cout<<"Daca produsul este redus, introduceti procentul. Daca nu, introduceti 0"<<endl;

        in>>crt.reducere;

        return in;

    }
    friend fstream& operator>> (fstream& in,  carte& crt)

     {

        char aux[100],aux2[100];


        in.getline(aux,100);

        in.getline(aux2,100);


        if(crt.titlu!=NULL)
            delete[] crt.titlu;

        crt.titlu=new char[strlen(aux)+1];
        strcpy(crt.titlu,aux);
        strcpy(crt.autor,aux2);

        in>>crt.pret;

        in>>crt.tipcoperta;

        in>>crt.pagini;

        in>>crt.pe_stoc;


        in>>crt.reducere;

        return in;

    }


    operator int()
    {

        return (int)this->getPret();

    }

    const carte operator++(){
        this->pe_stoc=1;

        return *this;

    }




    const carte operator++(int){

        carte aux(*this);

        this->pe_stoc=1;

        return aux;


    }
    const carte operator--()
    {
        this->pe_stoc=0;

        return *this;

    }

    const carte operator--(int)
    {

        carte aux(*this);

        this->pe_stoc=0;

        return aux;


    }

    bool operator ==(carte& s1)
    {


        if(strcmp(this->titlu,s1.titlu)==0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    bool operator <(carte& s1)
    {


        if(strcmp(this->titlu,s1.titlu)<0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    bool operator >(carte& s1)
    {


        if(strcmp(this->titlu,s1.titlu)>0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    carte operator +(float a)
    {
        this->pret=this->pret+a;
        return *this;
    }
    carte operator -(float a)
    {
        this->pret=this->pret-a;
        return *this;
    }
};


class Locatie
{

protected:

    const int id;
    char *NumeMag;
    char *Adresa;
    list<Angajat> Lista_Ang_Loc;
    vector<carte> Lista_Produse_Loc;
    int nrangajati;
    float nrcarti;
    bool deschis;
    bool magazinsaudepozit;


public:




    int getID()
    {
        return this->id;
    }


    float getNrTotalCarti()
    {
        return this->nrcarti;
    }

    char* getNumeMag()
    {
        return this->NumeMag;
    }

    char* getAdresa()
    {
        return this->Adresa;
    }

    char* StatusLocatie()
    {
        if(this->deschis==1)
        {
            return "Locatia este deschisa";
        }
        return "Locatia este inchisa";
    }


    Locatie (): id(rand())
    {
        this->nrangajati=0;
        this->nrcarti=0;
        this->NumeMag=new char[strlen("Coming Soon")+1];
        strcpy(this->NumeMag,"Coming Soon");
        this->Adresa=new char[strlen("Coming Soon")+1];
        strcpy(this->Adresa,"Coming Soon");
        list<Angajat> temp1(nrangajati,0);
        this->Lista_Ang_Loc=temp1;
        vector<carte> temp2(nrcarti,0);
        this->Lista_Produse_Loc=temp2;
        this->deschis=0;
        this->magazinsaudepozit=0;


    }
    Locatie (int id2): id(id2)
    {
        this->nrangajati=0;
        this->nrcarti=0;
        this->NumeMag=new char[strlen("Coming Soon")+1];
        strcpy(this->NumeMag,"Coming Soon");
        this->Adresa=new char[strlen("Coming Soon")+1];
        strcpy(this->Adresa,"Coming Soon");
        list<Angajat> temp1(nrangajati,0);
        this->Lista_Ang_Loc=temp1;
        vector<carte> temp2(nrcarti,0);
        this->Lista_Produse_Loc=temp2;
        this->deschis=0;
        this->magazinsaudepozit=0;




    }
    Locatie (int id2, int nrangajati, float nrcarti, char* NumeMag, char* Adresa, vector<carte> denis, list<Angajat> denis2, bool deschis, bool magazinsaudepozit): id(id2)
    {
        this->nrangajati=nrangajati;
        this->nrcarti=nrcarti;
        this->NumeMag=new char[strlen(NumeMag)+1];
        strcpy(this->NumeMag,NumeMag);
        this->Adresa=new char[strlen(Adresa)+1];
        strcpy(this->Adresa,Adresa);

        this->Lista_Ang_Loc=denis2;

        this->Lista_Produse_Loc=denis;
        this->deschis=deschis;
        this->magazinsaudepozit=magazinsaudepozit;



    }

    Locatie& operator =(const Locatie &ang)
    {
        if(this!=&ang)
        {
            this->nrangajati=ang.nrangajati;
            this->nrcarti=ang.nrcarti;
            this->NumeMag=new char[strlen(ang.NumeMag)+1];
            strcpy(this->NumeMag,ang.NumeMag);
            this->Adresa=new char[strlen(ang.Adresa)+1];
            strcpy(this->Adresa,ang.Adresa);

            this->Lista_Ang_Loc=ang.Lista_Ang_Loc;

            this->Lista_Produse_Loc=ang.Lista_Produse_Loc;
            this->deschis=ang.deschis;
                    this->magazinsaudepozit=ang.magazinsaudepozit;


        }
        return *this;


    }

    Locatie(const Locatie& ob):id(ob.id)
    {
        this->nrangajati=ob.nrangajati;
        this->nrcarti=ob.nrcarti;
        this->NumeMag=new char[strlen(ob.NumeMag)+1];
        strcpy(this->NumeMag,ob.NumeMag);
        this->Adresa=new char[strlen(ob.Adresa)+1];
        strcpy(this->Adresa,ob.Adresa);

        this->Lista_Ang_Loc=ob.Lista_Ang_Loc;

        this->Lista_Produse_Loc=ob.Lista_Produse_Loc;

        this->deschis=ob.deschis;
        this->magazinsaudepozit=ob.magazinsaudepozit;

    }

    ~Locatie()
    {
        if(this->NumeMag != NULL)
            delete[] this->NumeMag;
        if(this->Adresa != NULL)
            delete[] this->Adresa;


        this->Lista_Ang_Loc.clear();


        this->Lista_Produse_Loc.clear();
    }

    void AfisareDateStandard()
    {
        cout<<this->id<<" - "<<this->NumeMag<<" - Adresa: "<<this->Adresa<<endl;
    }

    friend ostream& operator<< (ostream& out,  const Locatie crt)
    {
        out<<"\n"<<crt.NumeMag<<"\n Adresa: "<<crt.Adresa;


        out<<"Sunt disponibile "<<crt.nrcarti<<" pe stoc";
        out<<"\n Doriti sa se afiseze lista de produse?"<<endl;
        int a;
        cin>>a;
        if(a!=0)
        {
           for(int i=0;i<crt.nrcarti;i++)
           {

               cout<<crt.Lista_Produse_Loc[i]<<endl<<endl;
           }
        }

        out<<"In gestiune lucreaza "<<crt.nrangajati<<" angajati.";
        out<<"\n Doriti sa se afiseze lista de angajati?"<<endl;
        cin>>a;
        if(a!=0)
        {
            std::list<Angajat> copie(crt.Lista_Ang_Loc);
            list <Angajat> :: iterator i;
           for(i=copie.begin();i!=copie.end();++i)
           {
               Angajat lmao=*i;
               cout<<lmao.getid()<<" - "<<lmao.getNume();
           }
        }
    }
    friend istream& operator>> (istream& in,  Locatie& crt)
    {


        char aux[100],aux2[100];
        cout<<"Introdu numele gestiunii"<<endl;
        in.ignore();
        in.getline(aux,100);
        cout<<"Introdu adresa gestiunii"<<endl;
        in.getline(aux2,100);


        if(crt.NumeMag!=NULL)
            delete[] crt.NumeMag;
        if(crt.NumeMag!=NULL)
            delete[] crt.Adresa;

        crt.NumeMag=new char[strlen(aux)+1];
        strcpy(crt.NumeMag,aux);
        strcpy(crt.Adresa,aux2);

        cout<<"Gestiunea a fost creata"<<endl;

        return in;








    }
    const Locatie operator++(){
        this->deschis=1;

        return *this;

    }




    const Locatie operator++(int){

        Locatie aux(*this);

        this->deschis=1;

        return aux;


    }
    const Locatie operator--()
    {
        this->deschis=0;

        return *this;

    }

    const Locatie operator--(int)
    {

        Locatie aux(*this);

        this->deschis=0;

        return aux;


    }
    Locatie operator +(carte a)
    {
        this->Lista_Produse_Loc.push_back(a);
        this->nrcarti=this->nrcarti+1;
        return *this;
    }
    Locatie operator -(carte a)
    {
        for(int i=0;i<nrcarti;i++)
        {
            if (a.getISBN()==Lista_Produse_Loc[i].getISBN())
            {


                this->Lista_Produse_Loc.erase(Lista_Produse_Loc.begin()+i-1);
                this->nrcarti=this->nrcarti-1;
            }
        }

        return *this;
    }

    Locatie operator +(Angajat a)
    {
        this->Lista_Ang_Loc.push_back(a);
        this->nrangajati=this->nrangajati+1;
        return *this;
    }
    Locatie operator -(Angajat a)
    {

        list <Angajat> :: iterator i;
        for(i=Lista_Ang_Loc.begin();i!=Lista_Ang_Loc.end();i++)
        {
            Angajat jamal;
            jamal=*i;
            if (a.getid()==jamal.getid())
            {


                this->Lista_Ang_Loc.erase(i);
                this->nrangajati=this->nrangajati-1;

            }
        }


        return *this;
    }

    bool operator ==(Locatie& s1)
    {


        if(s1.id == this->id)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    bool operator <(Locatie& s1)
    {
        if (s1.nrangajati<nrangajati)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    carte operator [](int index)
    {

        if(index<nrcarti && index>0)
            return this->Lista_Produse_Loc[index];
        else {cout<<"Index invalid";
                return -1;

            }
    }

    operator int()
    {

        return (int)this->getNrTotalCarti();

    }






};
class LocatieMagazin:public Locatie
{
private:

    int orainchidere;
    int oradeschidere;



public:

    LocatieMagazin():Locatie()
    {


        this->orainchidere=0;
        this->oradeschidere=0;

    }
    LocatieMagazin(int id):Locatie(id)
    {


        this->orainchidere=0;
        this->oradeschidere=0;
                this->magazinsaudepozit=1;


    }

    LocatieMagazin(Locatie p1, int oradeschidere, int orainchidere):Locatie(p1)
    {

        this->orainchidere=orainchidere;
        this->oradeschidere=oradeschidere;
        this->magazinsaudepozit=1;

    }

    LocatieMagazin(const LocatieMagazin& s):Locatie(s)
    {

        this->orainchidere=s.orainchidere;
        this->oradeschidere=s.oradeschidere;
                this->magazinsaudepozit=1;



    }

    LocatieMagazin& operator=(const LocatieMagazin& s)
    {

        if(this!=&s)
        {
            Locatie::operator=(s);
            this->orainchidere=s.orainchidere;
            this->oradeschidere=s.oradeschidere;
                    this->magazinsaudepozit=1;


        }
    return *this;

    }

    char* StatusLocatie()
    {
        if(this->deschis==1)
        {
            cout<<"Magazinul este deschis pana la ora " + this->orainchidere;
        }
        cout<<"Magazinul se deschide maine la ora " + this->oradeschidere;
    }


    friend ostream& operator<< (ostream& out,  const LocatieMagazin crt)
    {
        out<<"\n"<<crt.NumeMag<<"\n Adresa: "<<crt.Adresa;

        if(crt.deschis==1)
        {
            out<<"\n Magazinul este  deschis. Se va inchide astazo la ora "<<crt.orainchidere<<endl;
        }
        else
        {
            out<<"\n Magazinul este inchis. Se va deschide maine la ora "<<crt.oradeschidere<<endl;
        }


        out<<"Sunt disponibile "<<crt.nrcarti<<" pe stoc";
        out<<"\n Doriti sa se afiseze lista de produse? (1 - DA, 0 - NU)"<<endl;
        int a;
        cin>>a;
        if(a!=0)
        {
           for(int i=0;i<crt.nrcarti;i++)
           {
               cout<<crt.Lista_Produse_Loc[i]<<endl<<endl;
           }
        }

        out<<"In magazin lucreaza "<<crt.nrangajati<<" angajati.";
        out<<"\n Doriti sa se afiseze lista de angajati? (1 - DA, 0 - NU)"<<endl;
        cin>>a;
        if(a!=0)
        {
            std::list<Angajat> copie(crt.Lista_Ang_Loc);
            list <Angajat> :: iterator i;
           for(i=copie.begin();i!=copie.end();++i)
           {
               Angajat lmao=*i;
               cout<<lmao.getid()<<" - "<<lmao.getNume();
           }
        }
    }

    friend istream& operator>> (istream& in,  LocatieMagazin& crt)
    {


        char aux[100],aux2[100];
        cout<<"Introdu numele magazinului"<<endl;
        in.getline(aux,100);
        cout<<"Introdu adresa magazinului"<<endl;
        in.getline(aux2,100);


        if(crt.NumeMag!=NULL)
            delete[] crt.NumeMag;
        if(crt.NumeMag!=NULL)
            delete[] crt.Adresa;

        crt.NumeMag=new char[strlen(aux)+1];
        strcpy(crt.NumeMag,aux);
        strcpy(crt.Adresa,aux2);

        cout<<"Gestiunea a fost creata"<<endl;

        return in;








    }



};





class Comanda
{
protected:

    int NRCOMANDA;
    float nrcarti;
    vector<carte> CartiComandate;
    double pretTotal;
    char* nume_client;
    bool procesat;
    bool preluat;
    bool anulat;
    char tipcomanda;

public:
    static int totalcomenzi;
    int getNUMARCOMANDA()
    {
        return this->NRCOMANDA;
    }
    float getPretTotal()
    {
        return this->pretTotal;
    }
    char* getNUMECLIENT()
    {
        return this->nume_client;
    }
    char gettipcomanda()
    {
        return this->tipcomanda;
    }

    virtual double calculeazaPret()=0;

     Comanda():NRCOMANDA(rand())
    {
        this->pretTotal=0,00;
        this->nrcarti=0;
        vector<carte> temp(nrcarti,0);
        this->CartiComandate=temp;
        this->nume_client=new char[strlen("Coming Soon")+1];
        strcpy(this->nume_client,"Coming Soon");
        this->procesat=0;
        this->preluat=0;
        this->anulat=0;



    }

    Comanda(int id,double pretTotal,char *nume_client,float nrcarti, bool procesat, bool preluat, bool anulat, vector<carte> CartiComandate):NRCOMANDA(id)

    {
        this->pretTotal=pretTotal;
        this->nume_client=new char[strlen(nume_client)+1];
        strcpy(this->nume_client,nume_client);
        this->CartiComandate=CartiComandate;
        this->nrcarti=nrcarti;
        this->procesat=procesat;
        this->preluat=preluat;
        this->anulat=anulat;
            }

    Comanda(int id):NRCOMANDA(id)
    {
        this->pretTotal=0,00;
        this->nrcarti=0;
        this->nume_client=new char[strlen("Coming Soon")+1];
        strcpy(this->nume_client,"Coming Soon");
        vector<carte> temp(nrcarti,0);
        this->CartiComandate=temp;
        this->procesat=0;
        this->preluat=0;
        this->anulat=0;

    }

    Comanda& operator =(const Comanda &ang)
    {
        this->NRCOMANDA=ang.NRCOMANDA;
        this->pretTotal=ang.pretTotal;
        this->nrcarti=ang.nrcarti;
        this->nume_client=new char[strlen(ang.nume_client)+1];
        strcpy(this->nume_client,ang.nume_client);
        this->CartiComandate=ang.CartiComandate;
        this->procesat=ang.procesat;
        this->preluat=ang.procesat;
        this->anulat=ang.anulat;

    }

    Comanda(const Comanda& ob):NRCOMANDA(ob.NRCOMANDA)

    {

        this->NRCOMANDA=ob.NRCOMANDA;
        this->pretTotal=ob.pretTotal;
        this->nrcarti=ob.nrcarti;
        this->nume_client=new char[strlen(ob.nume_client)+1];
        strcpy(this->nume_client,ob.nume_client);
        this->CartiComandate=ob.CartiComandate;
        this->procesat=ob.procesat;
        this->preluat=ob.procesat;
        this->anulat=ob.anulat;
    }

    ~Comanda()
    {
        if(this->nume_client != NULL)
            delete[] this->nume_client;


        this->CartiComandate.clear();

    }
    friend ostream& operator<< (ostream& out,  const Comanda& crt)
    {
        return crt.Afisare(out);
    }

    virtual ostream& Afisare (ostream& out) const
    {

        out<<"\n Comanda dumneavoastra "<<this->NRCOMANDA<<" pe numele "<<this->nume_client<<" in valoare de "<<this->pretTotal<<" lei"<<endl;



            if(this->anulat==1)
            {
                out<<"A fost anulata"<<endl;
            }
            else if(this->preluat==1 && this->procesat==0)
            {
                out<<"Comanda dumneavoastra este in curs de procesare"<<endl;
            }
            else if(this->preluat==1 && this->procesat==1)
            {
                /*Locatie rez=crt.Ridicare;
                char* aux,* aux2;
                aux=new char[strlen(rez.getNumeMag())+1];
                aux2=new char[strlen(rez.getAdresa())+1];*/
                out<<"Comanda dumneavoastra este gata."<<endl;
            }
            else
            {
                out<<"Nu a fost inca preluata"<<endl;
            }
            return out;




    }
    friend istream& operator>> (istream& in,  Comanda& crt)
    {
        char aux[100];

        cout<<"Introdu numele pe care se face comanda"<<endl;
        in.getline(aux,100);
        strcpy(crt.nume_client,aux);
        cout<<"Felicitari, esti gata sa adaugi produse in cos pentru comanda"<<endl;
        return in;


    }

    void ProduseComanda()
    {
        cout<<"\n Aveti "<<this->nrcarti<<" produse in comanda"<<endl;

            for(int i=0;i<this->nrcarti;i++)
            {
                cout<<this->CartiComandate[i];
            }
    }
    void StatusComandaAng()
    {

            if(this->anulat==1)
            {
                cout<<"anulat"<<endl;
            }
            else if(this->preluat==1 && this->procesat==0)
            {
                cout<<"procesat"<<endl;
            }
            else if(this->preluat==1 && this->procesat==1)
            {
                cout<<"ridicare"<<endl;
            }
            else
            {
                cout<<"nepreluat"<<endl;
            }
    }

    void StatusComanda()
    {

            if(this->anulat==1)
            {
                cout<<"A fost anulata"<<endl;
            }
            else if(this->preluat==1 && this->procesat==0)
            {
                cout<<"Comanda dumneavoastra este in curs de procesare"<<endl;
            }
            else if(this->preluat==1 && this->procesat==1)
            {
                /*Locatie rez=this->Ridicare;
                char* aux,* aux2;
                aux=new char[strlen(rez.getNumeMag())+1];
                aux2=new char[strlen(rez.getAdresa())+1];
                cout<<"Comanda dumneavoastra este gata de ridicare la magazinul "<<aux<<" situat in "<<aux2<<endl;
                */
                cout<<"Comanda dumneavoastra este gata"<<endl;
            }
    }

    void AfisareProduse()
    {
        float nr;
        nr=this->nrcarti;
        for(int i=0;i<nr;i++)
        {
            cout<<CartiComandate[i].getTitlu()<<" - "<<this->CartiComandate[i].getAutor()<<" ---- "<<this->CartiComandate[i].PretRedus()<<endl;
        }
    }




    operator int()
    {

        return (int)this->getPretTotal();

    }
    /*

    const Comanda operator++()
    {
        if(this->preluat!=1)
        {
            this->preluat=1;
        }
        else
        {
            this->procesat=1;
        }



        return *this;

    }




    const Comanda operator++(int){

        Comanda aux(*this);

        if(this->preluat!=1)
        {
            this->preluat=1;
        }
        else
        {
            this->procesat=1;
        }

        return aux;


    }
    const Comanda operator--()
    {
        this->anulat=1;

        return *this;

    }

    const Comanda operator--(int)
    {

        Comanda aux(*this);

        this->anulat=1;

        return aux;


    }
    */

    bool operator ==(Comanda& s1)
    {


        if(s1.NRCOMANDA == this->NRCOMANDA)
        {
            return true;
        }
        else
        {
            return false;
        }

    }


    bool operator <(Comanda& s1)
    {


        if(this->NRCOMANDA > s1.NRCOMANDA)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    bool operator >(Comanda& s1)
    {
        if(this->NRCOMANDA<s1.NRCOMANDA)
            {
                return true;
            }
            else
            {
                return false;
            }
    }


    /*Comanda operator +(carte a)
    {
        if(a.getReducere()==0)
        {
          this->pretTotal=this->pretTotal+a.getPret();
        }
        else
        {
            this->pretTotal=this->pretTotal+a.PretRedus();
        }
        this->CartiComandate.push_back(a);
        this->nrcarti=this->nrcarti+1;
        return *this;
    }
    Comanda operator -(carte a)
    {
        if(a.getReducere()==0)
        {
          this->pretTotal=this->pretTotal-a.getPret();
        }
        else
        {
            this->pretTotal=this->pretTotal-a.PretRedus();
        }
        for(int i=0;i<nrcarti;i++)
        {
            if (a.getISBN()==CartiComandate[i].getISBN())
            {


                this->CartiComandate.erase(CartiComandate.begin()+i-1);
                this->nrcarti=this->nrcarti-1;
            }
        }

        return *this;
    }
    */

    /*carte operator [](int index)
    {

        if(index<nrcarti && index>0)
            return this->CartiComandate[index];
        else {cout<<"Index invalid";
                return -1;

            }
    }
    */







};

class ComandaStandard:public Comanda
{
private:
    long AWB;
    string Curier;
    float CostLivrare;

public:

    ComandaStandard():Comanda()
    {
        this->AWB=000000;
        this->Curier="Nimeni";
        this->CostLivrare=0;
        this->tipcomanda='s';
    }
    ComandaStandard(int id):Comanda(id)
    {
        this->AWB=000000;
        this->Curier="Nimeni";
        this->CostLivrare=0;
        this->tipcomanda='s';

    }


    ComandaStandard(int id,double pretTotal,char *nume_client,float nrcarti, bool procesat, bool preluat, bool anulat, vector<carte> CartiComandate, long AWB, string Curier, float CostLivrare):Comanda(id,pretTotal,nume_client,nrcarti,procesat,preluat,anulat,CartiComandate)
    {
        this->AWB=AWB;
        this->Curier=Curier;
        this->CostLivrare=CostLivrare;
        this->tipcomanda='s';
    }

    ComandaStandard(const ComandaStandard& s):Comanda(s)
    {

        this->AWB=s.AWB;
        this->Curier=s.Curier;
        this->CostLivrare=s.CostLivrare;
        this->tipcomanda='s';


    }

    ComandaStandard& operator=(const ComandaStandard& s)
    {

        if(this!=&s)
        {
            Comanda::operator=(s);
            this->AWB=s.AWB;
            this->Curier=s.Curier;
            this->CostLivrare=s.CostLivrare;this->tipcomanda='s';

        }
    return *this;

    }


    virtual ostream& operator<<(ostream& out)
     {

         out<<" Aceasta urmeaza sa fie livrata prin"<<this->Curier<<endl<<"Cost livrare: "<<this->CostLivrare<<endl<<"AWB: "<<this->AWB<<endl;
         return out;

     }
    void ProduseComanda()
    {
        Comanda::ProduseComanda();
    }
    void AfisareProduse()
    {
        Comanda::ProduseComanda();
    }
    int getNUMARCOMANDA()
    {
        Comanda::getNUMARCOMANDA();
    }
    char* getNUMECLIENT()
    {
        Comanda::getNUMECLIENT();
    }
    void StatusComandaAng()
    {
        Comanda::StatusComandaAng();
    }

    void StatusComanda()
    {
        Comanda::StatusComanda();
        cout<<" Aceasta urmeaza sa fie livrata prin"<<this->Curier<<endl<<"Cost livrare: "<<this->CostLivrare<<endl<<"AWB: "<<this->AWB<<endl;
    }




    double calculeazaPret()
    {
       return (this->pretTotal+this->CostLivrare);
    }

    ComandaStandard operator +(carte a)
    {
        if(a.getReducere()==0)
        {
          this->pretTotal=this->pretTotal+a.getPret();
        }
        else
        {
            this->pretTotal=this->pretTotal+a.PretRedus();
        }
        this->CartiComandate.push_back(a);
        this->nrcarti=this->nrcarti+1;
        return *this;
    }

    ComandaStandard operator -(carte a)
    {
        if(a.getReducere()==0)
        {
          this->pretTotal=this->pretTotal-a.getPret();
        }
        else
        {
            this->pretTotal=this->pretTotal-a.PretRedus();
        }
        for(int i=0;i<nrcarti;i++)
        {
            if (a.getISBN()==CartiComandate[i].getISBN())
            {


                this->CartiComandate.erase(CartiComandate.begin()+i-1);
                this->nrcarti=this->nrcarti-1;
            }
        }

        return *this;
    }
    const ComandaStandard operator++()
    {
        if(this->preluat!=1)
        {
            this->preluat=1;
        }
        else
        {
            this->procesat=1;
        }



        return *this;

    }




    const ComandaStandard operator++(int){

        ComandaStandard aux(*this);

        if(this->preluat!=1)
        {
            this->preluat=1;
        }
        else
        {
            this->procesat=1;
        }

        return aux;


    }
    const ComandaStandard operator--()
    {
        this->anulat=1;

        return *this;

    }

    const ComandaStandard operator--(int)
    {

        ComandaStandard aux(*this);

        this->anulat=1;

        return aux;


    }
    double calculeazaPretCuRed(int red)
    {
        return (this->pretTotal- (this->pretTotal*red)/10)+this->CostLivrare;
    }




};
class ComandaLocatie:public Comanda
{
private:
    Locatie Ridicare;
public:

    ComandaLocatie():Comanda()
    {
        Locatie Ridicare;
        this->Ridicare=Ridicare;
        this->tipcomanda='l';
    }
    ComandaLocatie(int id):Comanda(id)
    {
        Locatie Ridicare;
        this->Ridicare=Ridicare;
        this->tipcomanda='l';
    }


    ComandaLocatie(int id,double pretTotal,char *nume_client,float nrcarti, bool procesat, bool preluat, bool anulat, vector<carte> CartiComandate, Locatie Ridicare):Comanda(id,pretTotal,nume_client,nrcarti,procesat,preluat,anulat,CartiComandate)
    {
        this->Ridicare=Ridicare;
        this->tipcomanda='l';


    }

    ComandaLocatie(const ComandaLocatie& s):Comanda(s)
    {

        this->Ridicare=s.Ridicare;
        this->tipcomanda='l';



    }

    ComandaLocatie& operator=(const ComandaLocatie& s)
    {

        if(this!=&s)
        {
            Comanda::operator=(s);
            this->Ridicare=s.Ridicare;
            this->tipcomanda='l';


        }
    return *this;

    }
    void AfisareProduse()
    {
        Comanda::ProduseComanda();
    }
    int getNUMARCOMANDA()
    {
        Comanda::getNUMARCOMANDA();
    }
    char* getNUMECLIENT()
    {
        Comanda::getNUMECLIENT();
    }
    void StatusComandaAng()
    {
        Comanda::StatusComandaAng();
    }

    virtual ostream& Afisare(ostream& out)
     {
         Locatie rez=this->Ridicare;
                char* aux,* aux2;
                aux=new char[strlen(rez.getNumeMag())+1];
                aux2=new char[strlen(rez.getAdresa())+1];
         out<<" Aceasta este gata de ridicare in magazinul "<<aux<<" aflat la adresa"<<aux2<<endl;
         return out;

     }

     void ProduseComanda()
    {
        Comanda::ProduseComanda();
    }

    void StatusComanda()
    {
        Comanda::StatusComanda();
        cout<<" Aceasta este gata de ridicare in magazinul "<<this->Ridicare.getNumeMag()<<" aflat la adresa "<<this->Ridicare.getAdresa()<<endl;
    }



    double calculeazaPret()
    {
       return this->pretTotal;
    }

    double calculeazaPretCuRed(int red)
    {
        return (this->pretTotal- (this->pretTotal*red)/10);
    }

    ComandaLocatie operator +(carte a)
    {
        if(a.getReducere()==0)
        {
          this->pretTotal=this->pretTotal+a.getPret();
        }
        else
        {
            this->pretTotal=this->pretTotal+a.PretRedus();
        }
        this->CartiComandate.push_back(a);
        this->nrcarti=this->nrcarti+1;
        return *this;
    }

    ComandaLocatie operator -(carte a)
    {
        if(a.getReducere()==0)
        {
          this->pretTotal=this->pretTotal-a.getPret();
        }
        else
        {
            this->pretTotal=this->pretTotal-a.PretRedus();
        }
        for(int i=0;i<nrcarti;i++)
        {
            if (a.getISBN()==CartiComandate[i].getISBN())
            {


                this->CartiComandate.erase(CartiComandate.begin()+i-1);
                this->nrcarti=this->nrcarti-1;
            }
        }

        return *this;
    }
    const ComandaLocatie operator++()
    {
        if(this->preluat!=1)
        {
            this->preluat=1;
        }
        else
        {
            this->procesat=1;
        }



        return *this;

    }




    const ComandaLocatie operator++(int){

        ComandaLocatie aux(*this);

        if(this->preluat!=1)
        {
            this->preluat=1;
        }
        else
        {
            this->procesat=1;
        }

        return aux;


    }
    const ComandaLocatie operator--()
    {
        this->anulat=1;

        return *this;

    }

    const ComandaLocatie operator--(int)
    {

        ComandaLocatie aux(*this);

        this->anulat=1;

        return aux;


    }


};
int carte::nrtitluri=0;
int Angajat::nrangajati=0;
int Comanda::totalcomenzi=0;

int main()
{
   int a,id;
   float ore;
   char b[100];
   vector<carte> carti;
   set <Angajat> ang;
    std::set<Angajat>::iterator it;
   vector<Comanda*> comm;
   vector<ComandaStandard> comm2;
   vector<ComandaLocatie> comm3;
   vector<Locatie*> gest;
   carte bazat(1);
   int comenzicurente=2;
   int comenzistandard=2;
   int comenziloc=0;
   ofstream f;
    ifstream g;
    g.open("txt2.txt");
    f.open("txt.txt");
    Angajat almol;
    f<<almol;


    carte bazat2(1);
    g>>bazat2;
    cout<<bazat2;




   cout<<"Introdu numele de utilizator: "<<endl;
   cin>>b;
   cout<<"Introdu parola: "<<endl;
   cin>>a;

   if(strcmp(b,"admin")==0 && a==1)
   {
       cout<<"Bine ai venit "<<b;
       int n=1000;
       while(n)
       {
           cout<<" Ce doresti sa faci?"<<endl;
           cout<<"1.Gestioneaza carti"<<endl<<"2.Gestioneaza locatii"<<endl<<"3.Gestioneaza angajati"<<endl<<"4.Gestioneaza comenzi"<<endl;
           cin>>n;;
           int m;
           if(n==1)
           {
               cout<<"Gestiune carti: "<<endl;
               cout<<"1.Vezi lista produse"<<endl<<"2.Adauga in lista produse"<<endl<<"3.Scoate de pe stoc"<<endl<<"4.Vezi detalii produs"<<endl<<"5.Adauga pe stoc"<<endl<<"6.Scoate din lista de produse"<<endl;
               cin>>m;
               while(m)
               {
                   if (m==1)
                   {
                        for(int i=0;i<bazat.nrtitluri;i++)
                        {
                            if(carti[i].getPeStoc())
                            {


                                cout<<carti[i].getISBN()<<endl;
                                cout<<carti[i]<<endl;
                                cout<<carti[i].getReducere()<<endl;
                            }
                        }
                   }
                   if (m==2)
                   {
                        cout<<"Introdu ID-ul cartii"<<endl;
                        cin>>id;
                        carte pdf(id);
                        cin>>pdf;
                        carti.push_back(pdf);
                        pdf.nrtitluri++;
                   }
                   if (m==3)
                   {
                       int delet;
                       cout<<"Introdu ID-ul cartii"<<endl;
                       cin>>delet;
                       for(int i=0;i<bazat.nrtitluri;i++)
                       {
                           if(delet==carti[i].getISBN())
                           {
                               carti[i]--;
                           }
                       }

                   }
                   if(m==4)
                   {
                       int delet;
                       cout<<"Introdu ID-ul cartii"<<endl;
                       cin>>delet;
                       for(int i=0;i<bazat.nrtitluri;i++)
                       {
                           if(delet==carti[i].getISBN())
                           {
                               cout<<carti[i];
                               carte reducere=carti[i];
                               if(carti[i].getReducere()!=0)
                               cout<<"Produsul este momentan redus cu "<<reducere.getReducere()<<"%, ajungand la pretul de "<<reducere.PretRedus();
                           }
                       }

                   }
                   if(m==5)
                   {
                       int delet;
                       cout<<"Introdu ID-ul cartii"<<endl;
                       cin>>delet;
                       for(int i=0;i<bazat.nrtitluri;i++)
                       {
                           if(delet==carti[i].getISBN())
                           {
                               carti[i]++;
                           }
                       }
                   }
                   if(m==6)
                   {
                       int delet;
                       cout<<"Introdu ID-ul cartii"<<endl;
                       cin>>delet;
                       for(int i=0;i<sizeof(carti);i++)
                       {
                           if(delet==carti[i].getISBN())
                           {
                               carti.erase(carti.begin()+bazat.nrtitluri-1);
                               bazat.nrtitluri--;
                           }
                       }
                   }
                   if(m==7)
                   {
                       int delet;
                       cout<<"Introdu ID-ul cartii"<<endl;
                       cin>>delet;
                       for(int i=0;i<sizeof(carti);i++)
                       {
                           if(delet==carti[i].getISBN())
                           {
                               cout<<"Introduceti reducerea de pret (fara procent) pe care doriti sa o aplicati produsului: "<<endl;
                               int red;
                               cin>>red;
                               carti[i].setReducere(red);
                           }
                       }
                   }
                   if(m==8)
                   {
                       int delet;
                       cout<<"Introdu ID-ul cartii"<<endl;
                       cin>>delet;
                       for(int i=0;i<sizeof(carti);i++)
                       {
                           if(delet==carti[i].getISBN())
                           {
                               cout<<"Introduceti noul pret: "<<endl;
                               float prc;
                               cin>>prc;
                               carti[i].setPret(prc);
                           }
                       }
                   }
                   cout<<"Tasteaza 0 ca sa vezi iar meniul principal"<<endl;
                   cin>>m;

               }

           }
           else if(n==2)
           {
               cout<<"1.Vezi lista locatii"<<endl<<"2.Adauga locatie"<<"3.Sterge locatie";
           }
           else if(n==3)
           {
               cout<<"Gestiune angajati: "<<endl;
               cout<<"1.Angajeaza"<<endl<<"2.Concediaza"<<endl<<"3.Vezi lista angajati"<<endl<<"4.Vezi detalii angajat"<<endl<<"5.Modifica program saptamanal"<<endl<<"6.Modifica magazin"<<endl<<"7.Modifica salariu"<<endl<<"8.Modifica functia"<<endl;
               cin>>m;
               while(m)
               {
                if(n==1)
                {
                    Angajat nou(id);
                    cin>>nou;
                    ang.insert(nou);
                }
                else if (n==2)
                {
                    cout<<"Introdu ID-ul angajatului pe care urmeaza sa il concediezi"<<endl;
                    cin>>id;
                    Angajat monky(id);

                    for (it=ang.begin(); it!=ang.end();++it)
                    {
                        Angajat jamal=*it;
                        if(jamal.getid()==id)
                            break;
                    }
                    monky.nrangajati--;
                    ang.erase(monky);

                }
                else if (n==3)
                {

                    for (it=ang.begin(); it!=ang.end();++it)
                    {
                        Angajat jamal=*it;
                        cout<<jamal.getid()<<" - "<<jamal.getNume();
                    }
                }
                else if (n==4)
                {
                    cout<<"Introdu ID-ul angajatului caruia vrei sa il cauti"<<endl;
                    cin>>id;

                    for (it=ang.begin(); it!=ang.end();++it)
                    {
                        Angajat jamal=*it;
                        if(jamal.getid()==id)
                            cout<<jamal;

                    }
                }
                else if (n==5)
                {

                    cout<<"Introdu ID-ul angajatului caruia vrei sa ii modifici programul"<<endl;
                    cin>>id;
                    Angajat monky(id);

                    for (it=ang.begin(); it!=ang.end();++it)
                    {
                        Angajat jamal=*it;
                        if(jamal.getid()==id)
                            monky=jamal;
                            break;
                    }
                    ang.erase(monky);
                    monky.ModificareProgram();
                    ang.insert(monky);

                }
                else if(n==6)
                {
                    cout<<"Introdu ID-ul angajatului pe care vrei sa il muti"<<endl;
                    cin>>id;
                    Angajat monky(id);
                    for (it=ang.begin(); it!=ang.end();++it)
                    {
                        Angajat jamal=*it;
                        if(jamal.getid()==id)
                            monky=jamal;
                            break;
                    }
                    ang.erase(monky);//aici urmeaza o schema in care schimb in lista din angajati din magazine ig
                    cout<<"Introdu noua gestiune a angajatului"<<endl;
                    char mag[100];
                    cin.get(mag,100);

                    monky.setMagazin(mag);
                    ang.insert(monky);



                }
                else if(n==7)
                {
                    cout<<"Introdu ID-ul angajatului caruia vrei sa ii modifici salariul"<<endl;
                    cin>>id;
                    Angajat monky(id);
                    for (it=ang.begin(); it!=ang.end();++it)
                    {
                        Angajat jamal=*it;
                        if(jamal.getid()==id)
                            monky=jamal;
                            break;
                    }
                    ang.erase(monky);
                    double salar;
                    cout<<"Introduceti salariul nou"<<endl;
                    cin>>salar;
                    monky.setSalariu(salar);
                    ang.insert(monky);

                }
                else if(n==8)
                {

                   cout<<"Introdu ID-ul angajatului caruia vrei sa ii modifici functia"<<endl;
                    cin>>id;
                    Angajat monky(id);
                    for (it=ang.begin(); it!=ang.end();++it)
                    {
                        Angajat jamal=*it;
                        if(jamal.getid()==id)
                            monky=jamal;
                            break;
                    }
                    ang.erase(monky);
                    cout<<"Introdu noua functie a angajatului"<<endl;
                    char mag[100];
                    cin.get(mag,100);
                    monky.setFunctie(mag);
                    ang.insert(monky);
                }
                else if(n==9)
                {

                   cout<<"Introdu ID-ul angajatului carui vrei sa ii gestionezi concediul"<<endl;
                    cin>>id;
                    Angajat monky(id);
                    for (it=ang.begin(); it!=ang.end();++it)
                    {
                        Angajat jamal=*it;
                        if(jamal.getid()==id)
                            monky=jamal;
                            break;
                    }
                    ang.erase(monky);
                    if(monky.getConcediu())
                    {
                        cout<<"Angajatul e in vacanta. Trebuie sa revina azi din vacanta? Da/Nu"<<endl;
                        string afirm;
                        cin>>afirm;
                        if(afirm=="Da")
                        {
                            monky--;
                            cout<<"Vacanta e gata. Mai are "<<monky.getZileLibere()<<" zile libere ramase"<<endl;

                        }
                        else
                        {
                            cout<<"OK. Angajatul mai are "<<monky.getZileLibere()<<" zile libere ramase"<<endl;
                        }

                    }
                    else
                    {
                        cout<<"Angajatul nu e in vacanta. Doresti sa il trimiti in concediu? Da/Nu"<<endl;
                        if(monky.getZileLibere()>0)
                        {
                            cout<<"Mai are "<<monky.getZileLibere()<<". Cate zile doresti sa ii dai?"<<endl;
                            int zile;
                            cin>>zile;
                            monky=monky-zile;
                            monky++;
                        }
                        if(monky.getZileLibere()==0)
                        {
                            cout<<"Angajatul nu mai are zile libere. Doresti sa ii adaugi? Daca da, introdu numarul de zile. Daca nu, introdu 0"<<endl;
                            int zile;
                            cin>>zile;
                            monky=monky+zile;
                            cout<<endl<<"Pentru a il trimite acum in concediu, trebuie sa reintri in acest meniu."<<endl;
                        }
                    }
                }

                cout<<"Pentru a revedea meniul initial, apasa 0"<<endl;
                cin>>m;

               }
           }
           else
           {
               cout<<"Gestiune comenzi: "<<endl;
               cout<<"1.Vezi lista comenzi"<<endl<<"2.Vezi detalii comanda"<<endl<<"3.Modifica status comanda"<<endl<<"4.Ridicare Comanda"<<endl;
               cin>>m;
               while(m)
               {


               if(m==1)
               {
                   vector <Comanda*> :: iterator it;

                    for(it = comm.begin(); it != comm.end(); ++it)
                    {
                        cout << '\t' << (*it)->getNUMARCOMANDA()<<" - "<<(*it)->getNUMECLIENT()<<"  ";
                        (*it)->StatusComandaAng();
                        cout<<endl;

                    }



               }
               else if(m==2)
               {
                   cout<<"Introdu numarul comenzii"<<endl;
                   int nrcomlmao;
                   cin>>nrcomlmao;
                    vector <Comanda*> :: iterator it;

                    for(it = comm.begin(); it != comm.end(); ++it)
                   {
                       if((*it)->getNUMARCOMANDA()==nrcomlmao)
                       {
                            cout << '\t' << (*it)->getNUMARCOMANDA()<<" - "<<(*it)->getNUMECLIENT()<<"\t";
                            (*it)->StatusComandaAng();
                            cout<<endl<<endl;
                            (*it)->AfisareProduse();
                            cout<<endl;

                       }
                   }
               }
               else if(m==3)
               {
                   cout<<"Introdu numarul comenzii"<<endl;
                   int nrcomlmao;
                   cin>>nrcomlmao;

                   vector <Comanda*> :: iterator it;

                   for( it = comm.begin(); it != comm.end(); ++it)
                   {
                       if((*it)->getNUMARCOMANDA()==nrcomlmao)
                       {

                            if((*it)->gettipcomanda()=='s')
                            {
                                vector<ComandaStandard> :: iterator pi;
                                for( pi = comm2.begin(); pi != comm2.end(); ++pi)
                                {


                                    if((pi)->getNUMARCOMANDA()==nrcomlmao)
                                    {

                                    ComandaStandard temp;
                                    temp=(*pi);
                                    temp++;
                                    comm2.insert(pi,temp);
                                    comm2.erase(pi);
                                    }


                                }


                            }
                            else
                            {
                                vector<ComandaLocatie> :: iterator li;
                                for( li = comm3.begin();li != comm3.end(); ++li)
                                {
                                    if((li)->getNUMARCOMANDA()==nrcomlmao)
                                    {
                                    ComandaLocatie tempo;
                                    tempo=(*li);
                                    tempo++;
                                    comm3.insert(li,tempo);
                                    comm3.erase(li);
                                    }


                                }

                            }


                       }
                   }

               }
               else
               {
                   cout<<"Introdu numarul comenzii"<<endl;
                   int nrcomlmao;
                   cin>>nrcomlmao;

                   vector <Comanda*> :: iterator it;

                   for( it = comm.begin(); it != comm.end(); ++it)
                   {
                       if((*it)->getNUMARCOMANDA()==nrcomlmao)
                       {

                            if((*it)->gettipcomanda()=='s')
                            {
                                vector<ComandaStandard> :: iterator pi;
                                for( pi = comm2.begin(); pi != comm2.end(); ++pi)
                                {

                                    if((pi)->getNUMARCOMANDA()==nrcomlmao)
                                    {
                                        comm2.erase(pi);
                                    }



                                }


                            }
                            else
                            {
                                vector<ComandaLocatie> :: iterator li;
                                for( li = comm3.begin();li != comm3.end(); ++li)
                                {

                                    if((li)->getNUMARCOMANDA()==nrcomlmao)
                                    {
                                            comm3.erase(li);
                                    }


                                }

                            }


                       }
                       comm.erase(it);
                   }
               }

               cin>>m;
               }
           }
       }
   }
   else
   {
       cout<<"Interfata pentru clienti nu este inca terminata, va rugam reveniti"<<endl;

   }











}



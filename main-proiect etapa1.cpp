#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

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
    void setMagazin(char magazin)
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

        out<<"\n Program: \n Luni: "<<ang.ore_pe_zi[0]<<" ore \n Marti: "<<ang.ore_pe_zi[1]<<" ore \n Miercuri: "<<ang.ore_pe_zi[2]<<" ore \n Marti: "<<ang.ore_pe_zi[3]<<" ore \n Marti: "<<ang.ore_pe_zi[4]<<" ore \n Marti: "<<ang.ore_pe_zi[5]<<" ore \n Marti: "<<ang.ore_pe_zi[6]<<" ore \n";

    }

    void AfisareProgram()
    {
        cout<<"\n Total ore: "<<this->total_ore<<endl;
        cout<<"\n Program: \n Luni: "<<this->ore_pe_zi[0]<<" ore \n Marti: "<<this->ore_pe_zi[1]<<" ore \n Miercuri: "<<this->ore_pe_zi[2]<<" ore \n Marti: "<<this->ore_pe_zi[3]<<" ore \n Marti: "<<this->ore_pe_zi[4]<<" ore \n Marti: "<<this->ore_pe_zi[5]<<" ore \n Marti: "<<this->ore_pe_zi[6]<<" ore \n";
    }

    friend istream& operator>> (istream& in,  Angajat& ang)
    {

        char aux[100],aux2[100],aux3[100];
        cout<<"Introdu numele angajatului"<<endl;
        cin.getline(aux,100);
        cin.get();
        cout<<"Introdu functia angajatului"<<endl;
        cin.getline(aux2,100);
        cin.get();
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
        cout<<"Introdu totalul de ore saptamanale ale angajatului"<<endl;
        in>>ang.total_ore;
        cout<<"Introdu nr de ore zilnice pentru ziua corespunzatoare"<<endl;

        if(ang.ore_pe_zi!=NULL)
            delete[] ang.nume;

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


        if(s1.salariu == this->salariu && s1.total_ore == this->total_ore)
        {
            return true;
        }
        else
        {
            return false;
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






};




class carte
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

     friend istream& operator>> (istream& in,  carte& crt)

     {

        char aux[100],aux2[100];
        cout<<"Introdu titlul"<<endl;
        in.ignore();
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


        if(s1.pret == this->pret)
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


        if(this->pret < s1.pret)
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


        if(this->pret > this->pret)
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


class Locatie //Work in progress inca nu stiu sa folosesc vector cum ar trb deci nu am constructori
{

    const int id;
    char *NumeMag;
    char *Adresa;
    vector<Angajat> Lista_Ang_Loc;
    vector<carte> Lista_Produse_Loc;
    int nrangajati;
    float nrcarti;
    bool deschis;


public:

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
        vector<Angajat> temp1(nrangajati,0);

        this->Lista_Ang_Loc=temp1;
        vector<carte> temp2(nrcarti,0);
        this->Lista_Produse_Loc=temp2;
        this->deschis=0;


    }
    Locatie (int id2): id(id2)
    {
        this->nrangajati=0;
        this->nrcarti=0;
        this->NumeMag=new char[strlen("Coming Soon")+1];
        strcpy(this->NumeMag,"Coming Soon");
        this->Adresa=new char[strlen("Coming Soon")+1];
        strcpy(this->Adresa,"Coming Soon");
        vector<Angajat> temp1(nrangajati,0);

        this->Lista_Ang_Loc=temp1;
        vector<carte> temp2(nrcarti,0);
        this->Lista_Produse_Loc=temp2;
        this->deschis=0;



    }
    Locatie (int id2, int nrangajati, float nrcarti, char* NumeMag, char* Adresa, vector<carte> denis, vector<Angajat> denis2, bool deschis): id(id2)
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



    }

    Locatie& operator =(const Locatie &ang)
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

    friend ostream& operator<< (ostream& out,  const Locatie crt)
    {
        out<<"\n"<<crt.NumeMag<<"\n Adresa: "<<crt.Adresa;

        if(crt.deschis==1)
        {
            out<<"\n Magazinul este  deschis"<<endl;
        }
        else
        {
            out<<"\n Magazinul este inchis"<<endl;
        }


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

        out<<"In magazin lucreaza "<<crt.nrangajati<<" angajati.";
        out<<"\n Doriti sa se afiseze lista de angajati?"<<endl;
        cin>>a;
        if(a!=0)
        {
           for(int i=0;i<crt.nrangajati;i++)
           {
               cout<<crt.Lista_Ang_Loc[i]<<endl<<endl;
           }
        }
    }
    friend istream& operator>> (istream& in,  Locatie& crt)
    {


        char aux[100],aux2[100];
        cout<<"Introdu numele magazinului"<<endl;
        in.ignore();
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
        for(int i=0;i<nrangajati;i++)
        {
            if (a.getid()==Lista_Ang_Loc[i].getid())
            {


                this->Lista_Ang_Loc.erase(Lista_Ang_Loc.begin()+i-1);
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





class Comanda
{
    const int NRCOMANDA;
    float nrcarti;
    vector<carte> CartiComandate;
    double pretTotal;
    char* nume_client;
    Locatie Ridicare;
    bool procesat;
    bool preluat;
    bool anulat;

public:
    static int totalcomenzi;
    float getPretTotal()
    {
        return this->pretTotal;
    }

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
        Locatie l;
        this->Ridicare=l;


    }

    Comanda(int id,double pretTotal,char *nume_client,float nrcarti, bool procesat, bool preluat, bool anulat, vector<carte> CartiComandate, Locatie l):NRCOMANDA(id)

    {
        this->pretTotal=pretTotal;
        this->nume_client=new char[strlen(nume_client)+1];
        strcpy(this->nume_client,nume_client);
        this->CartiComandate=CartiComandate;
        this->nrcarti=nrcarti;
        this->procesat=procesat;
        this->preluat=preluat;
        this->anulat=anulat;
        this->Ridicare=l;
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
        Locatie l;
        this->Ridicare=l;
    }

    Comanda& operator =(const Comanda &ang)
    {
        this->pretTotal=ang.pretTotal;
        this->nrcarti=ang.nrcarti;
        this->nume_client=new char[strlen(ang.nume_client)+1];
        strcpy(this->nume_client,ang.nume_client);
        this->CartiComandate=ang.CartiComandate;
        this->procesat=ang.procesat;
        this->preluat=ang.procesat;
        this->anulat=ang.anulat;
        this->Ridicare=ang.Ridicare;

    }

    Comanda(const Comanda& ob):NRCOMANDA(ob.NRCOMANDA)

    {
        this->pretTotal=ob.pretTotal;
        this->nrcarti=ob.nrcarti;
        this->nume_client=new char[strlen(ob.nume_client)+1];
        strcpy(this->nume_client,ob.nume_client);
        this->CartiComandate=ob.CartiComandate;
        this->procesat=ob.procesat;
        this->preluat=ob.procesat;
        this->anulat=ob.anulat;
        this->Ridicare=ob.Ridicare;
    }

    ~Comanda()
    {
        if(this->nume_client != NULL)
            delete[] this->nume_client;


        this->CartiComandate.clear();

    }


    friend ostream& operator<< (ostream& out,  const Comanda crt)
    {

        out<<"\n Comanda dumneavoastra "<<crt.NRCOMANDA<<" pe numele "<<crt.nume_client<<" in valoare de "<<crt.pretTotal<<endl;

        int n;
        out<<"\n 1. Verificati status comanda \n 2. Verificati produse comanda"<<endl;
        cin>>n;
        if (n==1)
        {
            if(crt.anulat==1)
            {
                out<<"A fost anulata"<<endl;
            }
            else if(crt.preluat==1 && crt.procesat==0)
            {
                out<<"Comanda dumneavoastra este in curs de procesare"<<endl;
            }
            else if(crt.preluat==1 && crt.procesat==1)
            {
                Locatie rez=crt.Ridicare;
                char* aux,* aux2;
                aux=new char[strlen(rez.getNumeMag())+1];
                aux2=new char[strlen(rez.getAdresa())+1];
                out<<"Comanda dumneavoastra este gata de ridicare la magazinul "<<aux<<" situat in "<<aux2<<endl;
            }

        }
        else if(n==2)
        {

            out<<"\n Aveti "<<crt.nrcarti<<" produse in comanda"<<endl;

            for(int i=0;i<crt.nrcarti;i++)
            {
                out<<crt.CartiComandate[i];
            }
        }


    }
    friend istream& operator>> (istream& in,  Comanda& crt)
    {
        char aux[100];

        cout<<"Introdu numele pe care se face comanda"<<endl;
        in.ignore();
        in.getline(aux,100);
        strcpy(crt.nume_client,aux);
        cout<<"Felicitari, esti gata sa adaugi produse in cos pentru comanda"<<endl;
        return in;


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
                Locatie rez=this->Ridicare;
                char* aux,* aux2;
                aux=new char[strlen(rez.getNumeMag())+1];
                aux2=new char[strlen(rez.getAdresa())+1];
                cout<<"Comanda dumneavoastra este gata de ridicare la magazinul "<<aux<<" situat in "<<aux2<<endl;
            }
    }




    operator int()
    {

        return (int)this->getPretTotal();

    }

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


    Comanda operator +(carte a)
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

    carte operator [](int index)
    {

        if(index<nrcarti && index>0)
            return this->CartiComandate[index];
        else {cout<<"Index invalid";
                return -1;

            }
    }






};

int main()
{
   int a,id;
   char b[100];
   vector<carte> carti;
   int titlurilist=0;
   Angajat angajati[100];
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
                        for(int i=0;i<titlurilist;i++)
                        {
                            cout<<carti[i].getReducere()<<endl;
                            cout<<carti[i].getISBN()<<endl;
                            cout<<carti[i]<<endl;
                            cout<<carti[i].getReducere()<<endl;
                        }
                   }
                   if (m==2)
                   {
                        cout<<"Introdu ID-ul cartii"<<endl;
                        cin>>id;
                        carte pdf(id);
                        cin>>pdf;
                        carti.push_back(pdf);
                        titlurilist++;
                   }
                   if (m==3)
                   {
                       int delet;
                       cout<<"Introdu ID-ul cartii"<<endl;
                       cin>>delet;
                       for(int i=0;i<titlurilist;i++)
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
                       for(int i=0;i<titlurilist;i++)
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
                       for(int i=0;i<titlurilist;i++)
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
                               carti.erase(carti.begin()+titlurilist-1);
                               titlurilist--;
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
                   cout<<"Tasteaza 0 ca sa vezi iar meniul"<<endl;
                   cin>>m;

               }

           }
           else if(n==2)
           {
               cout<<"WIP"<<endl;
           }
           else if(n==3)
           {
               cout<<"Gestiune angajati: "<<endl;
               cout<<"1.Angajeaza"<<endl<<"2.Concediaza"<<endl<<"3.Vezi lista angajati"<<endl<<"4.Vezi detalii angajat"<<endl;
           }
           else
           {
               cout<<"Gestiune comenzi: "<<endl;
               cout<<"1.Vezi lista comenzi"<<endl<<"2.Vezi detalii comanda"<<endl<<"3.Modifica status comanda"<<endl;
           }
       }
   }
   else
   {
       cout<<"Interfata pentru clienti nu este inca terminata, va rugam reveniti"<<endl;

   }


}



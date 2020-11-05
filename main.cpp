#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

class carte
{
    static int nrtitluri;
    const long isbn;
    float pret;
    char *titlu;
    char tipcoperta;
    char autor[100];
    bool pe_stoc;
    double pagini;
    int* reducere;

public:
    carte():isbn(rand())
    {
        pret=0,00;
        titlu=new char[strlen("Coming Soon")+1];
        strcpy(this->titlu,"Coming Soon");
        tipcoperta='p';
        strcpy(autor,"denis");
        pe_stoc=0;
        pagini=0;
        reducere=new int[1];
        reducere[0]=0;


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
        this->reducere=new int[1];
        this->reducere[0]=reducere;




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
        this->reducere=new int[1];
        this->reducere[0]=0;


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
        return this->reducere[0];
    }

    void setPret(float pret)
    {
        carte::pret;
    }
    void setTitlu(char *titlu)
    {
        carte::titlu;
    }
    void setReducere(int* reducere)
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
        this->reducere=new int[1];
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
            if(this->reducere!=NULL)
            {
                delete[] this->reducere;
            }
            this->reducere=new int[1];

            this->reducere[0]=ang.reducere[0];
        }
    }






    ~carte()
    {
        if(this->titlu != NULL)
            delete[] this->titlu;
        if(this->autor != NULL)
            delete this->autor;
        if(this->reducere!=NULL)
            delete this->reducere;
    }

    float PretRedus()
    {
        int *a=this->reducere;


        if(reducere[0]!=0)
        {

            float pretred;
            pretred=pret-(pret*a[0])/100;
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

     friend istream& operator>> (istream& in,  carte& crt){

        char aux[100];
        cout<<"Introdu titlul"<<endl;
        in>>aux;
        cout<<"Introdu autorul"<<endl;
        in>>crt.autor;


        if(crt.titlu!=NULL)
            delete[] crt.titlu;

        crt.titlu=new char[strlen(aux)+1];
        strcpy(crt.titlu,aux);

        cout<<"Introdu pretul"<<endl;
        in>>crt.pret;
        cout<<"Introdu initiala tipului copertii cu litera mare"<<endl;
        in>>crt.tipcoperta;
        cout<<"Introdu nr. de pagini"<<endl;
        in>>crt.pagini;

        cout<<"Este momentan disponibil? Introduceti 1 daca da si 0 daca nu"<<endl;
        in>>crt.pe_stoc;

        if(crt.reducere!=NULL)
            delete[] crt.reducere;

        crt.reducere=new int[1];
        cout<<"Daca produsul este redus, introduceti procentul. Daca nu, introduceti 0"<<endl;
        int a;
        in>>a;
        crt.reducere[0]=a;

        return in;

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
    const carte operator--(){
        this->pe_stoc=0;

        return *this;

    }

    const carte operator--(int){

        carte aux(*this);

        this->pe_stoc=0;

        return aux;


    }
};






int main()
{
   int a,id;
   char b[100];
   vector<carte> carti;
   int titlurilist=0;
   //Angajat angajati[100];
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
           cout<<"Ce doresti sa faci?"<<endl;
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
                        cout<<pdf.getReducere()<<endl;
                        cin>>pdf;
                        cout<<pdf.getReducere()<<endl;
                        carti.push_back(pdf);
                        cout<<carti[titlurilist].getReducere()<<endl;
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

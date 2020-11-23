#include <iostream>
#include <vector>

using namespace std;

class Masina
{
protected:
    string marca;
    string model;
    int tipmasina;
public:

    friend ostream& operator<<(ostream &out, const Masina &b)
	{

		return b.Afisare(out);
	}


	virtual ostream& Afisare(ostream& out) const
	{
		out <<"Marca:"<<this->marca<<endl<<"Model: "<<this->model<<endl;
		if(tipmasina==1)
        {
            cout<<"Masina Undercover"<<endl;
        }
        if(tipmasina==2)
        {
            cout<<"Masina de Interventie"<<endl;
        }
        if(tipmasina==3)
        {
            cout<<"Masina de Emisie - Receptie"<<endl;
        }
		return out;
	}



    Masina(string marca, string modelul, int tipmasina)
    {
        this->marca=marca;
        this->model=modelul;
        this->tipmasina=tipmasina;
    }

    Masina()
    {
        this->marca="nedef";
        this->model="nedef";
        this->tipmasina=0;

    }

    Masina (const Masina &m)
    {
        this->marca=m.marca;
        this->model=m.model;
        this->tipmasina=m.tipmasina;

    }


    Masina &operator=(const Masina &m)
    {
        if(this!=&m)
        {
            this->marca=m.marca;
            this->model=m.model;
            this->tipmasina=m.tipmasina;

        }
        return *this;
    }

};

class MasiniUndercover:public Masina
{
private:

    float vimteza;
    int indice_armura;
public:

    MasiniUndercover(string marca, string modelul, int tipmasina, float vimteza, int indice_armura):Masina(marca,modelul,tipmasina)
    {
        this->vimteza=vimteza;
        this->indice_armura=indice_armura;
    }
    virtual ostream& Afisare(ostream& out) const override //are probleme cu const override o sa vad ce are mai tarziu
	{
		out << "Viteza maxima este de "<<this->vimteza<<endl<<"Poate incasa pana la "<<this->indice_armura<<" de gloante"<<endl;
		return out;
	}

};

class MasiniInterventie:public Masina
{
private:
    int cap_persoane;
    bool are_arma;
public:
    MasiniInterventie(string marca, string modelul, int tipmasina, bool arma, int cap_persoane):Masina(marca,modelul,tipmasina)
    {
        this->cap_persoane=cap_persoane;
        this->are_arma=arma;
    }
    virtual ostream& Afisare(ostream& out) const override
	{
		out << "Capacitatea maxima de persoane: "<<this->cap_persoane<<endl<<"Are mitraliera TR-85?: ";
		if(are_arma==true)
        {
            out<<"DA"<<endl;
        }
        else
        {
            out<<"Nu :( "<<endl;
        }
		return out;
	}

};

class MasiniEmisieReceptie:public Masina
{
private:
    int dist_receptie_audio;
    int dist_receptie_video;
public:
    MasiniEmisieReceptie(string marca, string modelul, int tipmasina, int dist_receptie_audio, int dist_receptie_video):Masina(marca,modelul,tipmasina)
    {
        this->dist_receptie_video=dist_receptie_video;
        this->dist_receptie_audio=dist_receptie_audio;
    }
    virtual ostream& Afisare(ostream& out) const override
	{
		out << "Distanta de receptie audio: "<<this->dist_receptie_audio<<endl<<"Distanta de receptie video: "<<this->dist_receptie_video<<endl;
		return out;
	}

};

class ListaMasini
{
private:

    vector<Masina> AutobazaSRI;
    int k;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

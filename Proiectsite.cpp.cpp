#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
ifstream f("site.txt");
struct produs
{
    char denumireProdus[300];
    int pret;
    char specificatii[300];
    int rating;
    char review[500];
};

struct categorie
{
    string numeCategorie;
    produs produse[20];
    int numarProduse;
};

struct adresa
{
    string oras;
    string strada;
    string nr;
};

struct cosCumparaturi
{
    produs produse[20];
    float pretTotal;
    int nrProduse;
    string metodaPlata;
    adresa adresaLivrare;
};

struct site
{
    string denumireSite;
    cosCumparaturi cos;
    categorie categorii[4];
};

site s;
cosCumparaturi cos;
int optiune;

void citireFisier()
{
    f>>s.denumireSite;
    for(int i = 1; i <= 3; i++)
    {
        f>>s.categorii[i].numeCategorie;
        f.get();
        f>>s.categorii[i].numarProduse;

        for(int j = 1; j <= s.categorii[i].numarProduse; j++)
        {
            f.get();
            f.getline(s.categorii[i].produse[j].denumireProdus, 300);
            f.get();
            f>>s.categorii[i].produse[j].pret;
            f.get();
            f.getline(s.categorii[i].produse[j].specificatii, 300);
            f>>s.categorii[i].produse[j].rating;
            f.get();
            f.getline(s.categorii[i].produse[j].review, 500);
            f.get();

        }
    }
}

void afisareCategorii()
{
    int optiune;
    do
    {
        cout<<"1. "<<s.categorii[1].numeCategorie<<endl;
        cout<<"2. "<<s.categorii[2].numeCategorie<<endl;
        cout<<"3. "<<s.categorii[3].numeCategorie<<endl;
        cout<<"4. Pagina anterioara"<<endl;
        cout<<"Alegeti categoria : ";
        cin>>optiune;
        switch(optiune)
        {
        case 1:
            cout<<endl<<"Categorie : "<<s.categorii[1].numeCategorie<<endl;
            cout<<"Numar Articole : "<<s.categorii[1].numarProduse<<endl;

            for(int i = 1; i <= s.categorii[1].numarProduse; i++)
            {
                cout<<i<<" . "<<s.categorii[1].produse[i].denumireProdus<<endl;
                cout<<"Pret : "<<s.categorii[1].produse[i].pret<<"RON"<<endl;
                cout<<"Specificatii : "<<s.categorii[1].produse[i].specificatii<<endl;
                cout<<"Rating : "<<s.categorii[1].produse[i].rating<<"/10"<<endl;
                cout<<"Review : "<<s.categorii[1].produse[i].review<<endl;

            }
            break;
        case 2:

            cout<<endl<<"Categorie : "<<s.categorii[2].numeCategorie<<endl;
            cout<<"Numar Articole : "<<s.categorii[2].numarProduse<<endl;

            for(int i = 1; i <= s.categorii[2].numarProduse; i++)
            {
                cout<<i<<" . "<<s.categorii[2].produse[i].denumireProdus<<endl;
                cout<<"Pret : "<<s.categorii[2].produse[i].pret<<"RON"<<endl;
                cout<<"Specificatii : "<<s.categorii[2].produse[i].specificatii<<endl;
                cout<<"Rating : "<<s.categorii[2].produse[i].rating<<"/10"<<endl;
                cout<<"Review : "<<s.categorii[2].produse[i].review<<endl;


            }
            break;
        case 3:
            cout<<endl<<"Categorie : "<<s.categorii[3].numeCategorie<<endl;
            cout<<"Numar Articole : "<<s.categorii[3].numarProduse<<endl;

            for(int i = 1; i <= s.categorii[3].numarProduse; i++)
            {
                cout<<i<<" . "<<s.categorii[3].produse[i].denumireProdus<<endl;
                cout<<"Pret : "<<s.categorii[3].produse[i].pret<<"RON"<<endl;
                cout<<"Specificatii : "<<s.categorii[3].produse[i].specificatii<<endl;
                cout<<"Rating : "<<s.categorii[3].produse[i].rating<<"/10"<<endl;
                cout<<"Review : "<<s.categorii[3].produse[i].review<<endl;

            }
            break;
        case 4:
            break;
        }
    }
    while(optiune != 4);
}
void adaugaInCos(produs p)
{
    cos.nrProduse++;
    cos.produse[cos.nrProduse] = p;
    cos.pretTotal = cos.pretTotal + p.pret;

}

void finalizareComanda()
{
    cout<<"Introduceti adresa livrare "<<endl;
    cout<<"Oras : ";
    cin>>cos.adresaLivrare.oras;
    cout<<"Strada : ";
    cin>>cos.adresaLivrare.strada;
    cout<<"Numar : ";
    cin>>cos.adresaLivrare.nr;
    cout<<"Metoda de plata: CARD/CASH"<<endl;
    cin>>cos.metodaPlata;
    cout<<"Comanda a fost inregistrata.";
    optiune = 0;
}

void afisareCosCumparaturi()
{
    if(cos.nrProduse == 0)
        cout<<"Cosul este gol."<<endl;
    else
    {


        for(int i = 1; i <= cos.nrProduse; i++)
        {
            cout<<cos.produse[i].denumireProdus<<" - "<<cos.produse[i].pret<<endl;
        }
        cout<<"Total de plata : "<<cos.pretTotal<<endl;
        cout<<"Finalizeaza comanda."<<endl;
        cout<<"DA/NU:";
        string optiune;
        cin>>optiune;
        if(optiune == "DA")
            finalizareComanda();

    }
}
void cautare()
{
    cout<<"Cauta produs dupa nume : ";
    char numeProdus[300];
    cin.get();
    cin.get(numeProdus, 300);
    cin.get();
    int ok = 0;
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= s.categorii[i].numarProduse; j++)
        {
            if(strstr(s.categorii[i].produse[j].denumireProdus, numeProdus))
            {
                cout<<i<<" . "<<s.categorii[i].produse[j].denumireProdus<<endl;
                cout<<"Pret : "<<s.categorii[i].produse[j].pret<<"RON"<<endl;
                cout<<"Specificatii : "<<s.categorii[i].produse[j].specificatii<<endl;
                cout<<"Rating : "<<s.categorii[i].produse[j].rating<<"/10"<<endl;
                cout<<"Review : "<<s.categorii[i].produse[j].review<<endl;
                ok = 1;
                cout<<"Adauga in cos?"<<endl;
                cout<<"DA/NU:";
                string optiune;
                cin>>optiune;
                if(optiune == "DA")
                {
                    adaugaInCos(s.categorii[i].produse[j]);
                }
                break;
            }
        }
    }
    if(ok == 0)
        cout<<"Produsul nu a fost gasit.";
}
int main()
{

    int timpPreparare = 0;
    float pret = 0;
    citireFisier();
    do
    {
        cout<<"1. Afisare Categorii"<<endl;
        cout<<"2. Vezi cosul de cumparaturi"<<endl;
        cout<<"3. Cautare produs"<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"Alegeti optiunea : ";
        cin>>optiune;

        switch(optiune)
        {
        case 1:
            afisareCategorii();
            break;
        case 2:
            afisareCosCumparaturi();
            break;
        case 3:
            cautare();
            break;
        case 0:
            break;
        default:
            cout<<"Optiune invalida";
            cout<<endl;
            break;
        }
    }
    while(optiune != 0);
}

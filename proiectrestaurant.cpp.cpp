#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream f("preparate.txt");

struct adresa
{
    string strada;
    int nr;
    int apartament = 0;
    char scara = '0';
};

struct preparat
{

    int id;
    string denumirePreparat;
    float pret;
    int minutePreparare;
};

struct menu
{
    preparat listaPreparate[30];
    string numeRestaurant;
    int numarPreparate = 0;
};

menu meniuRestaurant;

void citireMeniu()
{
    cout<<"Dati numele restaurantului : ";
    cin>>meniuRestaurant.numeRestaurant;
    cout<<endl;
    preparat p;

    while(f>>p.id)
    {

        f>>p.denumirePreparat;
        f>>p.pret;
        f>>p.minutePreparare;
        meniuRestaurant.numarPreparate++;
        meniuRestaurant.listaPreparate[meniuRestaurant.numarPreparate] = p;

    }
    cout<<"####Am Efectuat Citirea####"<<endl;
}

void afisareMenu()
{
    for(int i = 1; i <= meniuRestaurant.numarPreparate; i++)
        cout<<endl<<"Denumire preparat : "<<meniuRestaurant.listaPreparate[i].denumirePreparat<<endl<<
            "Pret : "<<meniuRestaurant.listaPreparate[i].pret<<" LEI"<<endl<<"Timp de preparare : "<<meniuRestaurant.listaPreparate[i].minutePreparare<<" MINUTE"<<endl;

}

void modificarePretPreparat()
{
    cout<<"Dati id-ul preparatului pe care il doriti modificat : ";
    int id;
    cin>>id;
    for(int i = 1; i <= meniuRestaurant.numarPreparate; i++)
        if(meniuRestaurant.listaPreparate[i].id == id)
        {
            cout<<"Vreti sa modificati pretul pentru : "<<endl;
            cout<<endl<<"Denumire preparat : "<<meniuRestaurant.listaPreparate[i].denumirePreparat<<endl<<
                "Pret : "<<meniuRestaurant.listaPreparate[i].pret<<" LEI"<<endl<<"Timp de preparare : "<<meniuRestaurant.listaPreparate[i].minutePreparare<<" MINUTE"<<endl;

            cout<<"Dati noul pret pentru preparat : ";
            int pret;
            cin>>pret;
            meniuRestaurant.listaPreparate[i].pret = pret;
        }


}

void adaugarePreparat()
{
    preparat p;

    cout<<endl;
    cout<<"Dati denumire preparat : ";
    cin>>p.denumirePreparat;
    cout<<"Dati pret : ";
    cin>>p.pret;
    cout<<"Dati timp de preparare(minute) : ";
    cin>>p.minutePreparare;
    cout<<"Dati identificator : ";
    cin>>p.id;
    meniuRestaurant.numarPreparate++;
    meniuRestaurant.listaPreparate[meniuRestaurant.numarPreparate] = p;

}

void stergerePreparat()
{
    preparat p;
    cout<<"Dati id-ul preparatului pe care il doriti sters : ";
    int id;
    cin>>id;
    for(int i = 1; i <= meniuRestaurant.numarPreparate; i++)
        if(meniuRestaurant.listaPreparate[i].id == id)
        {
            cout<<"Vreti sa stergeti : "<<endl;
            cout<<endl<<"Denumire preparat : "<<meniuRestaurant.listaPreparate[i].denumirePreparat<<endl<<
                "Pret : "<<meniuRestaurant.listaPreparate[i].pret<<" LEI"<<endl<<"Timp de preparare : "<<meniuRestaurant.listaPreparate[i].minutePreparare<<" MINUTE"<<endl;
            cout<<"Continuati ? ";
            string optiune;
            cin>>optiune;
            if(optiune == "Da")
            {
                for(int j = i; j < meniuRestaurant.numarPreparate; j++)
                    meniuRestaurant.listaPreparate[j] = meniuRestaurant.listaPreparate[j+1];
                meniuRestaurant.numarPreparate--;
            }
            else
                break;
        }
}

void comanda(float &pret, int &timpPreparare)
{
    cout<<endl<<"Dati preparatul pe care il doriti comandat : ";
    string denumirePreparat;
    cin>>denumirePreparat;
    for(int i = 1; i <= meniuRestaurant.numarPreparate; i++)
        if(denumirePreparat == meniuRestaurant.listaPreparate[i].denumirePreparat)
        {
            pret += meniuRestaurant.listaPreparate[i].pret;
            timpPreparare += meniuRestaurant.listaPreparate[i].minutePreparare;
        }
    cout<<"Comanda va fi gata in "<<timpPreparare<<" minute"<<endl;
}
void notaPlata(int pret)
{
    cout<<"Nota de plata este "<<pret<<" Lei";
    cout<<endl;
}
int main()
{

    citireMeniu();
    int optiune;
    int timpPreparare = 0;
    float pret = 0;
    do
    {
        cout<<"1. Afisare Meniu"<<endl;
        cout<<"2. Modificare pret preparat"<<endl;
        cout<<"3. Adaugare preparat"<<endl;
        cout<<"4. Stergere preparat"<<endl;
        cout<<"5. Comanda preparat"<<endl;
        cout<<"6. Nota de plata"<<endl;

        cout<<"0. EXIT"<<endl;
        cout<<"Alegeti optiunea : ";
        cin>>optiune;

        switch(optiune)
        {
        case 1:
            afisareMenu();
            break;
        case 2:
            modificarePretPreparat();
            break;
        case 3:
            adaugarePreparat();
            break;
        case 4:
            stergerePreparat();
            break;
        case 5:
            comanda(pret, timpPreparare);
            break;
        case 6:
            notaPlata(pret);
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

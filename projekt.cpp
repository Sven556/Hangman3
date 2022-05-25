#include <stdio.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<ofstream>
#include<ifstream>
#include<fstream>


using namespace std;

int main() {
    // u�itavanje rije�i
    char odgovor[128];
    char abeceda[22] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Z' };
    char kopija_abecede[22] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Z' };
    int br = 6, zastavica = 0;

    cout << "Unesi rijec za pogadanje:";
    fflush(stdout);
    cin >> odgovor;
    system("cls");

    // Postavi pomocno polje - pogodeno[i] je 1 ako
    // je znak odgovor[i] pogoden.
    // Ovo polje inicijaliziramo na 0 jer na pocetku nista nije pogodeno.
    int duljina = strlen(odgovor); //N= duljina odgovora
    int *pogodeno=new int[duljina];
    for (int i = 0; i < duljina; ++i) {
        pogodeno[i] = 0;
    }

    // Svaki prolazak kroz petlju predstavlja jedan krug pogadanja
    int kraj = 0; // varijabla koja nam govori kada je igra gotova (kao zastavica)


    cout<<"*****************************************************************\n";
    cout<<"                             ____                              \n";
    cout<<" ||  ||   //\\\\   ||\\   ||  //____| ||\\    /||   //\\\\   ||\\   ||\n";
    cout<<" ||  ||  //  \\\\  ||\\\\  || ||   __  ||\\\\  //||  //  \\\\  ||\\\\  ||\n";
    cout<<" ||__|| ||____|| || \\\\ || ||  |__| || \\\\// || ||____|| || \\\\ ||\n";
    cout<<" ||--|| ||----|| ||  \\\\|| ||    || ||      || ||----|| ||  \\\\||\n";
    cout<<" ||  || ||    || ||   \\||  \\|||||| ||      || ||    || ||   \\||\n";
    cout<<"\n";
    cout<<"*****************************************************************\n\n";

    cout<<"\n";
    cout<<"\n";
    cout<<"  _______\n";
    cout<<"  |/\n";
    cout<<"  |\n";
    cout<<"  |\n";
    cout<<"  |\n";
    cout<<"  |\n";
    cout<<"__|_________\n\n";

    while (!kraj) {
        // Ispisuje se rije� tako da umjesto slova koja nisu pogodena pisemo -
        cout<<"Rijec glasi:";
        for (int j = 0; j < duljina; ++j) {
            if (pogodeno[j]) {
                cout << odgovor[j];
            }
            else {
                cout<<"-";
            }
        }
        cout<<"\n";

        // Igrac pogada
        char pokusaj;
        int slovo;
        cout<<"Slovo? ";
        fflush(stdout);
        cin >> pokusaj;

        for (int i = 0; i < 22; i++) {
            if (toupper(pokusaj) == abeceda[i])
                slovo = i;
        }
        if (kopija_abecede[slovo] == '-' && pokusaj != '?')
            cout<<"Ovo slovo vec je iskoristeno. Pokusajte ponovo.\n";

        else {

            kopija_abecede[slovo] = '-';

            system("cls");

            //crtamo naslov
            cout<<"*****************************************************************\n";
            cout<<"                             ____                              \n";
            cout<<" ||  ||   //\\\\   ||\\   ||  //____| ||\\    /||   //\\\\   ||\\   ||\n";
            cout<<" ||  ||  //  \\\\  ||\\\\  || ||   __  ||\\\\  //||  //  \\\\  ||\\\\  ||\n";
            cout<<" ||__|| ||____|| || \\\\ || ||  |__| || \\\\// || ||____|| || \\\\ ||\n";
            cout<<" ||--|| ||----|| ||  \\\\|| ||    || ||      || ||----|| ||  \\\\||\n";
            cout<<" ||  || ||    || ||   \\||  \\|||||| ||      || ||    || ||   \\||\n";
            cout<<"\n";
            cout<<"*****************************************************************\n\n";


            if (pokusaj == '?') {
                cout<<"Dostupna slova: "; 
                for (int i = 0; i < 22; i++) {
                    if (kopija_abecede[i] != '-')
                        cout<<"abeceda[i]";
                }
            }

            // U polju pogodeno, oznacavamo jedinicom sve pojave slova koje je igrac unio i smanjujemo broj pokusaja ako nije pogodio ni jedno slovo
            for (int k = 0; k < duljina; ++k) {
                if (odgovor[k] == pokusaj) {
                    pogodeno[k] = 1;
                    zastavica = 1;
                }
            }

            if (zastavica == 0) {
                br--;

                switch (br)
                {
                case 0:
                    kraj = 1;
                    cout<<"Izgubili ste";
                    cout<<"\n";
                    break;
                case 1:
                    cout<<"1\n";
                    break;
                case 2:
                    cout<<"2\n";
                    break;
                case 3:
                    cout<<"3\n";
                    break;
                case 4:
                    cout<<"4\n";
                    break;
                case 5:
                    cout<<"5\n";
                    break;

                }

            }
            else
                cout<<"\n";


            cout<<"\n";

            switch (br)
            {
            case 0:
                cout<<"  _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |   \\|/\n";
                cout<<"  |    | \n";
                cout<<"  |   / \\\n";
                cout<<"__|_________\n\n";
                break;
            case 1:
                cout<<"  _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |   \\|/\n";
                cout<<"  |    | \n";
                cout<<"  |   /\n";
                cout<<"__|_________\n\n";
                break;
            case 2:
                cout<<"  _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |   \\|/\n";
                cout<<"  |    | \n";
                cout<<"  |\n";
                cout<<"__|_________\n\n";
                break;
            case 3:
                cout<<"  _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |   \\|\n";
                cout<<"  |    | \n";
                cout<<"  |\n";
                cout<<"__|_________\n\n";
                break;
            case 4:
                cout<<"  _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |    |\n";
                cout<<"  |    |\n";
                cout<<"  |\n";
                cout<<"__|_________\n\n";
                break;
            case 5:
                cout<<"  _______\n";
                cout<<"  |/   | \n";
                cout<<"  |    O \n";
                cout<<"  |\n";
                cout<<"  |\n";
                cout<<"  |\n";
                cout<<"__|_________\n\n";
                break;
            case 6:
                cout<<"  _______\n";
                cout<<"  |/\n";
                cout<<"  |\n";
                cout<<"  |\n";
                cout<<"  |\n";
                cout<<"  |\n";
                cout<<"__|_________\n\n";
                break;

            }





            zastavica = 0;

            // Odre�ujemo je li igrac pobijedio
            if (br != 0) {
                kraj = 1;
                for (int m = 0; m < duljina; ++m) {
                    if (!pogodeno[m]) {
                        kraj = 0;
                        break;
                    }
                }
            }

        }

    }

    // pobjedni�ka poruka
    if (br != 0)
        cout<< "Pobjeda! Odgovor je:\n" << odgovor;

    return 0;
}

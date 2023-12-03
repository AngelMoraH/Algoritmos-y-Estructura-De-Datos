#include "Blockchain/Blockchain.h"
#include <iostream>

using namespace std;

int INDICE = 1;
#define FILENAME "btc_data_bi_day.csv"
#define DELIM ','

void salir();

void Clear() { cout << "\x1B[2J\x1B[H"; }

void filling_blockchain_test(Blockchain &cryptochain, const string &filename,
                             int dificultad) {
  ifstream file;
  file.open(filename);
  if (file.is_open()) {
    cryptochain.read_and_load_csv(INDICE, filename, DELIM, dificultad);
  } else {
    cerr << "Error opening file" << endl;
  }
}

void add_block_in_blockchain(Blockchain &cryptochain, int dificultad){
    Clear();
    cout << "\n\n Creando Bloque!" << endl;
    cout << "Agregar transaccion " << endl;
    cout << "--------------------"<<endl;
    ForwardList<Transaction> transactions;
    int opcion;
    do {
        Transaction n_transaction;
        n_transaction.crear_transaccion(INDICE);
        transactions.push_back(n_transaction);
        cout << "Agregar otra transaccion?" << endl;
        cout << "0. No" << endl;
        cout << "1. Si" << endl;

        cout << "\nIngresar opcion: ";
        cin >> opcion;
        while(opcion != 0 and opcion != 1){
            cerr << endl << "Opcion invalida";
            cout << "\nIngresar opcion: ";
            cin >> opcion;
        }
    } while(opcion);
    cryptochain.add_block(transactions, dificultad);
}


int insert_difficulty() {
  int dificultad;
  cout << "\n\n        Insert dificulty for block inserting " << endl;
  cout << "--------------------" << endl;
  cout << "1. fastest" << endl;
  cout << "2. fast" << endl;
  cout << "3. normal" << endl;
  cout << "4. slow" << endl;

  cout << "\nIngresar opcion: ";
  cin >> dificultad;

  while (dificultad != 1 and dificultad != 2 and dificultad != 3 and
         dificultad != 4) {
    cerr << endl << "Opcion invalida";
    cout << "\nIngresar opcion: ";
    cin >> dificultad;
  }
  return dificultad;
}

void Criterios_de_busqueda(Blockchain &cryptochain){
    int opcion;
    bool repetir = true;
    do{
        Clear();
        cout << "\n\n        Elija un criterio de busqueda: " << endl;
        cout << "--------------------"<<endl;
        cout << "1. Igual a X" << endl;
        cout << "2. Entre X y Y" << endl;
        cout << "3. Search word" << endl;
        cout << "4. Está contenido en" << endl;
        cout << "5. Máximo valor de" << endl;
        cout << "6. Mínimo valor de" << endl;
        cout << "0. End" << endl;

        cout << "\nIngresar opcion: ";
        cin >> opcion;

        while(opcion != 0 and opcion != 1 and opcion != 2 and opcion != 3 and opcion != 4 and opcion != 5 and opcion != 6){
            cerr << endl << "opcion invalida";
            cout << "\nIngresar opcion: ";
            cin >> opcion;
        }
        if (opcion == 0){
            repetir = false;
        } else {
            switch(opcion){
            case 1:
              cryptochain.igual_a_x();
              salir();
              break;
            case 2:
              cryptochain.entre_x_y();
              salir();
              break;
            case 3:
                cryptochain.inicia_con();
                salir();
                break;
            case 4:
                cryptochain.contenido_en();
                salir();
                break;
            case 5:
              cryptochain.max_valor();
              salir();
              break;
            case 6:
              cryptochain.min_valor();
              salir();
              break;
            default:
              cout << "opcion invalida" << endl;
              break;
            }
        }
    } while(repetir);
}

void Interactive_Menu() {
  Blockchain cryptochain;
  int opcion;
  bool repetir = true;
  int difficulty = insert_difficulty();

  do {
    Clear();
    cout << "\n\n        Menu " << endl;
    cout << "--------------------" << endl;
    cout << "1. Read and load data del .csv" << endl;
    // cout << "2. Add transactions in specific block" << endl;
    cout << "2. Add Block " << endl;
    // cout << "4. Modify transaction" << endl;
    cout << "3. Mostrar Block" << endl;
    cout << "4. Display transactions" << endl;
    cout << "5. Criterios" << endl;
    cout << "6. Cambiar dificultad " << endl;
    cout << "0. End" << endl;

    cout << "\nIngresar opcion: ";
    cin >> opcion;

    while (opcion<0 || opcion>6) {
      cerr << endl << "Opcion invalida";
      cout << "\nIngresar opcion: ";
      cin >> opcion;
    }

    switch (opcion) {
    case 1:
      Clear();
      filling_blockchain_test(cryptochain, FILENAME, difficulty);
      salir();
      break;
    case 2:
      add_block_in_blockchain(cryptochain, difficulty);
      break;

    case 3:
      Clear();
      cryptochain.display();
      salir();
      break;

    case 4:
      Clear();
      int block;
      do {
        cout << "\n there are " << cryptochain.chain.size() << " blocks."
             << endl;
        cout << "\n Select block: ";
        cin >> block;
      } while (block < 1 or block > cryptochain.chain.size());

      cout << "\n\n Displaying all transactions from block " << block << endl;
      cout << "--------------------" << endl;
      cryptochain.chain[block].display_transactions();
      salir();
      break;

    case 5:
      Criterios_de_busqueda(cryptochain);
      break;
    case 6:
      difficulty = insert_difficulty();
      break;
    case 0:
      repetir = false;
      break;
    default:
      cout << "Opcion invalida." << endl;
      break;
    }

    cryptochain.fix();
  } while (repetir);
  cryptochain.display();
}

void salir() {
  int salir;
  do {
    cout << endl << "Ingrese 0 para salir: ";
    cin >> salir;
    Clear();
  } while (salir != 0);
}

int main() { 
  setlocale(LC_ALL, "");
  Interactive_Menu();

  return 0;
}

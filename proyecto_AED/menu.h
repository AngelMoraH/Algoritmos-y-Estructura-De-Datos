#include <iostream>
#include <ctime>
#include <vector>
#include "Block.h"
#include "Blockchain.h"
#include "Transaction.h"

void Menu(Blockchain *block_coin)
{
    int cantidad, block;
    char rpta;
    string emisor, receptor;

    do
    {
        cout << endl
             << "---------------------------" << endl;
        cout << "    block_coin Main Menu" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Crear Bloque" << endl;
        cout << "2. Imprimir Blockchain" << endl;
        cout << "3. Proof Of Work Test" << endl;
        cout << "4. Arreglar Blockchain" << endl;
        cout << "5. Buscar en el Blockchain" << endl;
        cout << "6. Buscar valores maximos" << endl;
        cout << "7. Salir" << endl;

        cout << endl
             << "Ingrese una opcion: ";
        cin >> rpta;
        cout << endl;

    } while (rpta != '1' && rpta != '2' && rpta != '3' && rpta != '4' && rpta != '5' && rpta != '6' && rpta != '7');

    if (rpta == '1')
    { // Creamos y a;adimos el bloque a la blockchain

        cout << "---------------------------" << endl;
        cout << endl
             << "Ingrese Emisor: ";
        cin >> emisor;
        cout << "Ingrese Receptor: ";
        cin >> receptor;
        cout << "Ingrese cantidad de coins a enviar: ";
        cin >> cantidad;
        cout << endl;
        time_t dataTime;
        Transaction *data = new Transaction(cantidad, emisor, receptor, time(&dataTime));
        block_coin->addBlock(data);
        cout << endl
             << "Bloque creado satisfactoriamente." << endl;
        Menu(block_coin);
    }
    else if (rpta == '2')
    {
        block_coin->show_blockchain();
        Menu(block_coin);
    }
    else if (rpta == '3')
    {
        cout << "---------------------------" << endl;
        cout << endl
             << "Ingrese Bloque: ";
        cin >> block;
        block_coin->test_proof_work(block);
        Menu(block_coin);
    }
    else if (rpta == '4')
    {
        cout << "---------------------------" << endl;
        cout << "Arreglando Blockchain..." << endl;
        cout << "---------------------------" << endl;

        block_coin->fix_all();
        cout << endl
             << "Blockchain Arreglada Satisfactoriamente." << endl;
        Menu(block_coin);
    }
    
    else if (rpta == '5')
    {
        block_coin->igual_a_x();
    }

    else if (rpta == '6')
    {
        block_coin->max_valor();
    }

    else if (rpta == '7')
    {
        cout << endl << "Gracias por usar la plataforma. " << endl;
    }
}

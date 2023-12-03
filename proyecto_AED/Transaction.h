#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <ctime>
#include <string>
using namespace std; // Evita poner std:: en el codigo.

struct Transaction
{
    string amount;      // almacena la cantidad de la transaccion.
    string senderKey;   // Almacena la llave del emisor en la transaccion.
    string recieverKey; // Almacena la llave del receptor en la transaccion.
    string timestamp;   // time_t Almacena valores de tiempo en la transaccion.

    Transaction() {}

    // Aqui Se usa valores como "amt" en lugar de amount, para poder diferenciar. si     esto no fuera asi, abajo pondriamos amount = amount, lo que podria ser confuso.

    Transaction(double amt, string sender, string reciever, time_t time)
    {
        amount = to_string(amt);
        senderKey = sender;
        recieverKey = reciever;
        timestamp = ctime(&time);
    }
    
    string get_amount()
    {
        return this->amount;
    }

    string get_sender_key()
    {
        return this->senderKey;
    }

    string get_timestamp(){
        return this->timestamp;
    }

    string get_data()
    {
        string result = "";
        result += this->amount;
        result += this->senderKey;
        result += this->recieverKey;
        result += this->timestamp;
        return result;
    }
};

#endif

#include <iostream>
#include <string>
#include <cmath>
#include "pila.h"
#include "circularlist.h"
using namespace std;

struct Result
{
    double result;
    bool error;
};

int convertNumber(string str){
    int num = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9' || str[i] == '0')
        {
            num = num*10 + (str[i] - '0');
        }
    }
    return num;

}
bool isNumber(string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9' || str[i] == '0')
        {
            return true;
        }
    }
    return false;
}

double operacion(int first, int second, char caracter)
{

    switch (caracter)
    {
    case '+':
        return first + second;
        break;
    case '-':
        return first - second;
        break;
    case '*':
        return first * second;
        break;
    case '/':
        return first / (double)second;
        break;
    default:
        return false;
        break;
    }
}

int priority(string alpha)
{
    if (alpha == "+" || alpha == "-")
        return 1;

    if (alpha == "*" || alpha == "/")
        return 2;

    return 0;
}

Result evaluate(string input)
{
    // 1- descomponer el input y validar
    char temp_list[input.length()];
    Result result = Result();
    int cant_parentesis_1 = 0;
    int cant_parentesis_2 = 0;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ')
        {
            temp_list[i] = input[i];
        }
    }

    for (size_t i = 0; i < input.length(); i++)
    {
        if (temp_list[i] == '(')
        {
            cant_parentesis_1++;
        }
        else if (temp_list[i] == ')')
        {
            cant_parentesis_2++;
        }
    }
    if (cant_parentesis_1 != cant_parentesis_2)
    {
        result.error = true;
        return result;
    }

    for (size_t i = 0; i < input.length(); i++)
    {
        if (temp_list[i] == '+' || temp_list[i] == '-' || temp_list[i] == '*' || temp_list[i] == '/')
        {
            if (i == input.length() - 1)
            {
                result.error = true;
                return result;
            }
            else if (i == 0)
            {
                result.error = true;
                return result;
            }
            if (temp_list[i + 1] == '+' || temp_list[i + 1] == '-' || temp_list[i + 1] == '*' || temp_list[i + 1] == '/' || (temp_list[i + 1] == '(' && temp_list[i - 1] == '(') || temp_list[i + 1] == ')')
            {
                result.error = true;
                return result;
            }
        }
    }
    // 2- convertir de Infijo a Postfijo
    CircularList *numbers = new CircularList();
    Pila operations = Pila(input.length());
    string nums= "";
    int tam = 0;
    int tmp_tam = 0;
    int k=0;
    for (size_t i = 0; i < input.length(); i++){
        if(input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != '(' && input[i] != ')'&& input[i] != ' '){
            if(i<input.length()-1&&isNumber(string(1,input[i+1]))){
                string temp =""; 
                temp+=input[i];
                temp += input[i+1];
                nums+=",";
                nums+=temp;
                i++;
            }else if(i<input.length()-1&&isNumber(string(1,input[i+1]))==false){
                nums+=",";
                nums+=input[i];
            }else{
                nums+=",";
                nums+=input[i];
            }
        }else if(input[i] == ' '){
            continue;
        }
        else{
            nums+=",";
            nums+=input[i];
        }
    }
    string input2[nums.length()];
    for (size_t i = 0; i < nums.length(); i++){
        if(nums[i] != ','){
            input2[k]+=nums[i];
        }else{
            k++;
        }
    }
    
    for (int i = 0; i < nums.length(); i++){
        if (isNumber(input2[i]))
        {
            numbers->push_back(input2[i]);
        }
        else if (input2[i] == "(")
        {
            operations.push(input2[i]);
        }
        else if (input2[i] == ")")
        {
            string data = operations.pop();
            while (data != "(")
            {
                numbers->push_back(data);
                data = operations.pop();
            }
        }
        else
        {
            while (!operations.isEmpty() && priority(input2[i]) <= priority(operations.peek()))
            {
                numbers->push_back(operations.pop());
            }
            operations.push(input2[i]);
        }
    }
    while (!operations.isEmpty())
    {
        numbers->push_back(operations.pop());
    }
    
    // 3- resolver la expresion
    /*
    Node *temp = numbers->getHead()->next;
    numbers->setNode(k);
    cout<<"size: "<< numbers->size() <<endl;
    for (size_t i = 0; i < numbers->size(); i++){
        if(numbers->size()==1){
            cout<<"result "<<temp->data<<endl;
            result.result = stod(numbers->getHead()->next->data);
            return result;
        }else if(!isNumber(temp->data)){
            int second = stoi(temp->prev->data);
            cout<<"second "<<second<<endl;
            int first = stoi(temp->prev->prev->data);
            cout<<"first "<<first<<endl;
            string res = to_string(operacion(first,second,temp->data[0]));
            bool entero=true;
            for(int i=res.find('.')+1; i<res.length();i++){
                if(res[i] != '0')
                    entero=false;
                    break;
                entero=true;
            }
            if(entero){
                res= res.substr(0, res.find('.'));
            }
            temp->prev->prev->data = res;
            temp->prev->prev->next = temp->next;
            temp->next->prev = temp->prev->prev;
            temp = numbers->getHead();
            //numbers->setNode(numbers->size()-2);
        }
        temp = temp->next;
        
        cout<<"numbers "<<numbers->size()<<endl;
        numbers->print();
    }
    
    */



    numbers->clean();


    // Si no cumple la validacion retornar Result.error = true;
    return result;
}

/*
for (int i = 0; i < len; i++)
    {
        int cont = 0;
        for (int j = 0; j < len; j++)
        {   
            if (isNumber(temp->data))
            {
                cont++;
                temp = temp->next;
            }
            else
            {
                break;
            }
        }
        cout<<"count 1 "<<cont<<endl;
        temp = numbers->getHead()->next;

        if (cont == 2) {
            cout<<"entra al cont == 2"<<endl;
            int first = stoi(numbers->pop_front());
            int second = stoi(numbers->pop_front());
            char caracter = numbers->pop_front()[0];
            double result = operacion(first, second, caracter);
            string res = to_string(result);
            bool entero=true;
            for(int i=res.find('.')+1; i<res.length();i++){
                if(res[i] != '0')
                    entero=false;
                    break;
                entero=true;
            }
            if(entero){
                res= res.substr(0, res.find('.'));
            }
            numbers->push_front(res);
            cout<<"result: "<<result<<endl;
        }else if (cont == 3){
            cout<<"entra al cont == 3"<<endl;
            string extra = numbers->pop_front();
            int first = stoi(numbers->pop_front());
            int second = stoi(numbers->pop_front());
            char caracter = numbers->pop_front()[0];
            double result = operacion(first, second, caracter);
            string res = to_string(result);
            bool entero=true;
            for(int i=res.find('.')+1; i<res.length();i++){
                if(res[i] != '0')
                    entero=false;
                    break;
                entero=true;
            }
            if(entero){
                res= res.substr(0, res.find('.'));
            }
            numbers->push_front(res);
            numbers->push_front(extra);
            numbers->print();
        }
    }





    while (temp != numbers->getHead()){
        if(!isNumber(temp->data)){
            int second;
            from_chars(temp->prev->data.c_str(), temp->prev->data.c_str() + temp->prev->data.length(), second);
            int first;
            from_chars(temp->prev->prev->data.c_str(), temp->prev->prev->data.c_str() + temp->prev->prev->data.length(), first);
            cout<<"first: "<<first<<endl;
            cout<<"second: "<<second<<endl;
            double result = operacion(first, second, temp->data[0]);
            string res = to_string(result);
            bool entero=true;
            for(int i=res.find('.')+1; i<res.length();i++){
                if(res[i] != '0')
                    entero=false;
                    break;
                entero=true;
            }
            if(entero){
                res= res.substr(0, res.find('.'));
            }
            numbers->push_front(""+res);
            cout<<"result: "<<numbers->front()<<endl;
            temp->prev->prev->data = res;
            temp->prev->prev->next = temp->next;
            temp->next->prev = temp->prev->prev;
            temp = temp->next;
        }
        temp = temp->next;
    }

*/
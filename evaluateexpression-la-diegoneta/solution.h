#include <iostream>
#include <string.h>
#include <algorithm>
#include "pila.h"
#include "circularlist.h"
using namespace std;

struct Result
{
    double result;
    bool error;
};

bool isNumber(string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '0')
        {
            return false;
        }
        
    }
    return true;
}

bool isOperator(string str){
    if (str == "+" || str == "-" || str == "*" || str == "/")
    {
        return true;
    }
    return false;
}

template<typename T>
void convertNumber(T &n,string str){
    if(str!=""||str!=" "){
        for(size_t i = 0; i < str.length(); i++){
            n = n*10 + (str[i] - '0');
        }
    }
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
    int tam = 0;
    int tmp_tam = 0;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            continue;
        }
        else if (isNumber(string(1,input[i])))
        {
            numbers->push_back(string(1,input[i]));
        }
        else if (input[i] == '(')
        {
            operations.push(string(1,input[i]));
        }
        else if (input[i] == ')')
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
            while (!operations.isEmpty() && priority(string(1,input[i])) <= priority(operations.peek()))
            {
                numbers->push_back(operations.pop());
            }
            operations.push(string(1,input[i]));
        }
    }
    while (!operations.isEmpty())
    {
        numbers->push_back(operations.pop());
    }


    //cout<<"numbers: "<<endl;
    //numbers->print();



    // 3- resolver la expresion
    //cout<<"size: "<<numbers->size()<<endl;
    for (int i = 0; i < numbers->size(); i++) {
        int cont = 0;
        for (int j = 0; j < numbers->size(); j++)
        {   
            //cout<<"numbers->operator[](j): "<<numbers->operator[](j)<<" - "<<isNumber(numbers->operator[](j))<<endl;
            if (isNumber(numbers->operator[](j)))
            {
                cont++;
            }
            else
            {
                break;
            }
        }
        //cout<<"cont: "<<cont<<endl;
        if(isOperator(numbers->operator[](i))) {
            if(cont==2){
                int first=0;int second=0;
                convertNumber(first,numbers->pop_front());
                convertNumber(second,numbers->pop_front());
                //cout<<"first: "<<first<<endl;
                //cout<<"second: "<<second<<endl;
                char op=numbers->pop_front()[0];
                double result= operacion(first,second,op);
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
                //cout<<"tam2"<<endl;
                //numbers->print();
            }
            if(cont==3){
                //cout<<"cont = 3"<<endl;
                string tmp=numbers->pop_front();
                int first=0;int second=0;
                convertNumber(first,numbers->pop_front());
                convertNumber(second,numbers->pop_front());
                char op=numbers->pop_front()[0];
                double result= operacion(first,second,op);
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
                numbers->push_front(tmp);
                //cout<<"tam3"<<endl;
                //numbers->print();
            }
        } 
    }
    for(int i=0; i<numbers->size();i++){
        if(!isNumber(numbers->operator[](i))){
            int first=0;int second=0;
            convertNumber(first,numbers->pop_front());
            convertNumber(second,numbers->pop_front());
            //cout<<"first: "<<first<<endl;
            //cout<<"second: "<<second<<endl;
            char op=numbers->pop_front()[0];
            double result= operacion(first,second,op);
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
        }
    }
    result.result = stod(numbers->pop_front());
    return result;
}


/*
Node *temp = numbers->getHead();
    temp = temp->next;

    for (int i = 0; i < numbers->size(); i++)
    {
        int cont = 0;
        for (int j = 0; j < numbers->size(); j++)
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

        temp = numbers->getHead()->next;

        if (cont == 2) {
            cout<<"entra al cont == 2"<<endl;
            int first = stoi(numbers->pop_front());
            int second = stoi(numbers->pop_front());
            char caracter = numbers->pop_front()[0];
            double result = operacion(first, second, caracter);
            string res = to_string(result);
            bool entero=true;
            cout<<res<<endl;
            for(int i=res.find('.')+1; i<res.length();i++){
                cout<<res[i]<<endl;
                if(res[i] != '0')
                    entero=false;
                    break;
                entero=true;
            }
            if(entero){
                res= res.substr(0, res.find('.'));
            }
            numbers->push_front(res);
            cout<<result<<endl;
            numbers->print();
        }
        cout << "cont: " << cont << endl;
        if (cont == 3)
        {
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

    result.result = stof(numbers->pop_front());
    cout << result.result << endl;






##########################################
##########################################
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
        if(numbers->size()==k){
            cout<<numbers->size()<<" : "<<k<<endl;
            cout<<"entra al break"<<endl;
            break;
        }
        if (isNumber(input2[i])){
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
            cout<<"operation 1"<<endl;
            while (!operations.isEmpty() && priority(input2[i]) <= priority(operations.peek()))
            {
                if (isOperator(operations.peek()) ){
                    numbers->push_back(operations.pop());
                }
            }
            operations.push(input2[i]);
            cout<<"operation 2"<<endl;
            operations.print();
        }
        numbers->print();
    }
    while (!operations.isEmpty())
    {   
        if(isOperator(operations.peek())){
            numbers->push_back(operations.pop());
        }
    }


*/


#include <iostream>
#include <string>

using namespace std;

bool validarBinario(string valor){
    string binarioValidos = "01";
    bool eValido = true;
    for(int i=0; i<valor.length(); i++){
        bool achou = false;
        for(int j=0; j<2; j++){
            if(valor[i] == binarioValidos[j]){
                achou = true;
                break;
            }
        }
        if(!achou){
            return false;
        }
    }
    return true;
}
bool validarOctal(string valor){
    string octalValidos = "01234567";
    bool eValido = true;
    for(int i=0; i<valor.length(); i++){
        bool achou = false;
        for(int j=0; j<8; j++){
            if(valor[i] == octalValidos[j]){
                achou = true;
                break;
            }
        }
        if(!achou){
            return false;
        }
    }
    return true;
}
bool validarDecimal(string valor){
    string decimalValidos = "0123456789";
    bool eValido = true;
    for(int i=0; i<valor.length(); i++){
        bool achou = false;
        for(int j=0; j<10; j++){
            if(valor[i] == decimalValidos[j]){
                achou = true;
                break;
            }
        }
        if(!achou){
            return false;
        }
    }
    return true;
}
bool validarHexaDecimal(string valor){
    string hexaDecimalValidos = "0123456789ABCDEFabcdef";
    bool eValido = true;
    for(int i=0; i<valor.length(); i++){
        bool achou = false;
        for(int j=0; j<hexaDecimalValidos.length(); j++){
            if(valor[i] == hexaDecimalValidos[j]){
                achou = true;
                break;
            }
        }
        if(!achou){
            return false;
        }
    }
    return true;
}


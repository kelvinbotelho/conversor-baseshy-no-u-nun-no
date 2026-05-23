
#include "parser.h"
#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// REQUISITO F5: VALIDAÇÃO DE ENTRADAS DE ACORDO COM A BASE
// ============================================================================

// //f5 //f6 - Valida se a string contém apenas dígitos binários (0, 1) e até um separador (. ou ,)
bool validarBinario(string valor){
    string binarioValidos = "01";
    int qntPontos = 0;
    if (valor.empty()) return false;
    for(int i=0; i<valor.length(); i++){
        bool achou = false;
        if(valor[i] == '.' || valor[i] == ','){
            qntPontos += 1;
            achou = true;
        }
        if(qntPontos > 1){
            return false;
        }
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
    if (qntPontos == 1 && valor.length() == 1) {
        return false;
    }
    return true;
}

// //f5 //f6 - Valida se a string contém apenas dígitos octais (0 a 7) e até um separador (. ou ,)
bool validarOctal(string valor){
    string octalValidos = "01234567";
    int qntPontos = 0;
    if (valor.empty()) return false;
    for(int i=0; i<valor.length(); i++){
        bool achou = false;
        if(valor[i] == '.' || valor[i] == ','){
            qntPontos += 1;
            achou = true;
        }
        if(qntPontos > 1){
            return false;
        }
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
    if (qntPontos == 1 && valor.length() == 1) {
        return false;
    }
    return true;
}

// //f5 //f6 - Valida se a string contém apenas dígitos decimais (0 a 9) e até um separador (. ou ,)
bool validarDecimal(string valor){
    string decimalValidos = "0123456789";
    int qntPontos = 0;
    if (valor.empty()) return false;
    for(int i=0; i<valor.length(); i++){
        bool achou = false;
        if(valor[i] == '.' || valor[i] == ','){
            qntPontos += 1;
            achou = true;
        }
        if(qntPontos > 1){
            return false;
        }
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
    if (qntPontos == 1 && valor.length() == 1) {
        return false;
    }
    return true;
}

// //f5 //f6 - Valida se a string contém apenas dígitos hexadecimais (0-9, A-F) e até um separador (. ou ,)
bool validarHexaDecimal(string valor){
    string hexaDecimalValidos = "0123456789ABCDEFabcdef";
    int qntPontos = 0;
    if (valor.empty()) return false;
    for(int i=0; i<valor.length(); i++){
        bool achou = false;
        if(valor[i] == '.' || valor[i] == ','){
            qntPontos += 1;
            achou = true;
        }
        if(qntPontos > 1){
            return false;
        }
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
    if (qntPontos == 1 && valor.length() == 1) {
        return false;
    }
    return true;
}
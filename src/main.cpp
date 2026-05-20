#include <iostream>
#include <string>
using namespace std;

// declarando as funcoes
string decimalparaBinarioOctalHexa(string n, int b);
long long inteiroBinarioparadecimal(string s);
long long inteiroOctalparadecimal(string s);
long long inteiroHexaparadecimal(string s);
double binarioOctalHexaParaDecimal(string s, int b);
string binarioParaOctal(string s);
string binarioParaHexaDecimal(string s);
string octalParaBinario(string s);
string hexaParaBinario(string s);
bool validarBinario(string s);
bool validarOctal(string s);
bool validarDecimal(string s);
bool validarHexaDecimal(string s);

int main() {
    // testando F1
    cout << "10,625 em binario: " << decimalparaBinarioOctalHexa("10,625", 2) << endl;
    cout << "13.625 em octal: " << decimalparaBinarioOctalHexa("13.625", 8) << endl;
    cout << "0.7 em hexa: " << decimalparaBinarioOctalHexa("0.7", 16) << endl;
    //adicionar prop truncou para a funcao decimalparaBinarioOctalHexa por referencia, para logar se truncou ou não

    // testando F2
    cout << "1010.101 binario em decimal: " << binarioOctalHexaParaDecimal("1010.101", 2) << endl;
    cout << "15.5 octal em decimal: " << binarioOctalHexaParaDecimal("15.5", 8) << endl;
    cout << "0.B333333333333 hexa em decimal: " << binarioOctalHexaParaDecimal("0.B333333333333", 16) << endl;

    // testando F3
    cout << "11111 binario para octal " << binarioParaOctal("11111")<<endl;
    cout << "37 octal para binario " << octalParaBinario("37")<<endl;
    cout << "11111 binario para hexadecimal " << binarioParaHexaDecimal("11111")<<endl;
    cout << "1F hexadecimal para binario " << hexaParaBinario("1F")<<endl;
    
    //testando F4
    cout << "37 octal para hexadecimal usando binario como intermediario " << binarioParaHexaDecimal(octalParaBinario("37"))<<endl;

    //testando F6
    if(validarBinario("1111")){
        cout << "Binario digitado valido. "<< endl;
    }else{
        cout << "Binario digitado invalido. "<< endl;
    }
    if(validarOctal("42")){
        cout << "Octal digitado valido. "<< endl;
    }else{
        cout << "Octal digitado invalido. "<< endl;
    }
    if(validarDecimal("4289")){
        cout << "Decimal digitado valido. "<< endl;
    }else{
        cout << "Decimal digitado invalido. "<< endl;
    }
    if(validarHexaDecimal("49ABc")){
        cout << "Hexadecimal digitado valido. "<< endl;
    }else{
        cout << "Hexadecimal digitado invalido. "<< endl;
    }
    return 0;
}

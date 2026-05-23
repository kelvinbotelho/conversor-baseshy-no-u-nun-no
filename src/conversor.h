#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <string>

using namespace std;

// funções de conversão (F1, F2, F3 e F4)
string decimalparaBinarioOctalHexa(string n, int b);
long long inteiroBinarioparadecimal(string s);
long long inteiroOctalparadecimal(string s);
long long inteiroHexaparadecimal(string s);
double binarioOctalHexaParaDecimal(string s, int b);
string binarioParaOctal(string s);
string binarioParaHexaDecimal(string s);
string octalParaBinario(string s);
string hexaParaBinario(string s);

#endif // CONVERSOR_H

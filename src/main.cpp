#include <iostream>
#include <string>
using namespace std;

// declarando as funcoes
string decimalparabinario(long long n);
string decimalparaoctal(long long n);
string decimalparahexa(long long n);
long long binarioparadecimal(string s);
long long octalparadecimal(string s);
long long hexaparadecimal(string s);
string binarioParaOctal(string s);
string binarioParaHexaDecimal(string s);
string octalParaBinario(string s);
string hexaParaBinario(string s);

int main() {
    // testando F1
    cout << "13 em binario: " << decimalparabinario(13) << endl;
    cout << "13 em octal: " << decimalparaoctal(13) << endl;
    cout << "13 em hexa: " << decimalparahexa(13) << endl;

    // testando F2
    cout << "1101 binario em decimal: " << binarioparadecimal("1101") << endl;
    cout << "15 octal em decimal: " << octalparadecimal("15") << endl;
    cout << "D hexa em decimal: " << hexaparadecimal("D") << endl;

    // testando F3
    cout << "11111 binario para octal " << binarioParaOctal("11111")<<endl;
    cout << "37 octal para binario " << octalParaBinario("37")<<endl;
    cout << "11111 binario para hexadecimal " << binarioParaHexaDecimal("11111")<<endl;
    cout << "1F hexadecimal para binario " << hexaParaBinario("1F")<<endl;
    cout << "37 octal para hexadecimal usando binario como intermediario " << binarioParaHexaDecimal(octalParaBinario("37"))<<endl;
    return 0;
}

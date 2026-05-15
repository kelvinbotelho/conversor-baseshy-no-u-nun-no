#include <iostream>
#include <string>

using namespace std;

string decimalparabinario(long long n){
    if(n == 0) return "0";
    string resultado ="";
while (n >0) {
    char digito = '0' + (n % 2);
    resultado = digito + resultado;
    n=n/2;
}
return resultado;
}

string decimalparaoctal(long long n){
    if(n == 0) return "0";
    string resultado ="";
while (n >0) {
    char digito = '0' + (n % 8);
    resultado = digito + resultado;
     n = n / 8;
}
return resultado;
    }

string decimalparahexa(long long n){
if (n==0) return "0";
    string resultado = "";
    string digitos = "0123456789ABCDEF";
while (n>0){
    resultado = digitos[n%16] + resultado;
    n=n/16;
    }
return resultado;
    }
long long binarioparadecimal (string s){
    long long resultado = 0;
    long long potencia =1;
    for(int i = s.length() -1; i>=0; i--){
        resultado += (s[i] - '0') * potencia;
        potencia *= 2;
    }
    return resultado;
    }

long long octalparadecimal (string s){
    long long resultado = 0;
    long long potencia =1;
    for(int i = s.length() -1; i>=0; i--){
        resultado += (s[i] - '0') * potencia;
        potencia *=8;
    }
    return resultado;
}

long long hexaparadecimal (string s){
    long long resultado =0;
    long long potencia =1;
    string digitos ="0123456789ABCDEF";
    for (int i= s.length()-1; i>=0; i--){
        int valor= digitos.find(s[i]);
        resultado += valor*potencia;
        potencia *=16;
    }
    return resultado;
}


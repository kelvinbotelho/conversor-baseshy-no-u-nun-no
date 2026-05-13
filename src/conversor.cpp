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
    n=n/8;
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




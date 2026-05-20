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

char blocoParaOctal(string bloco) {
    while (bloco.length() < 3) {
        bloco = "0" + bloco;
    }
    int valor = (bloco[0] - '0') * 4 + (bloco[1] - '0') * 2 + (bloco[2] - '0') * 1;
    
    return valor + '0';
}

string binarioParaOctal(string binario) {
    string octal = "", bloco = "";
    for(int i = binario.length()-1; i>=0; i--){
        bloco = binario[i] + bloco;
        if(bloco.length() == 3){
            octal = blocoParaOctal(bloco) + octal;
            bloco = "";
        }
    }
    if (bloco.length() > 0) {
        octal = blocoParaOctal(bloco) + octal;
    }
    return octal;
}
char blocoParaHexaDecimal(string bloco) {
    while (bloco.length() < 4) {
        bloco = "0" + bloco;
    }
    int valor = (bloco[0] - '0') * 8 + (bloco[1] - '0') * 4 + (bloco[2] - '0') * 2 + (bloco[3] - '0') * 1;
    
    if (valor >= 0 && valor <= 9) {
        return valor + '0';
    } else {
        return (valor - 10) + 'A'; 
    }
}

string binarioParaHexaDecimal(string binario) {
    string hexa = "", bloco = "";
    for(int i = binario.length()-1; i>=0; i--){
        bloco = binario[i] + bloco;
        if(bloco.length() == 4){
            hexa = blocoParaHexaDecimal(bloco) + hexa;
            bloco = "";
        }
    }
    if (bloco.length() > 0) {
        hexa = blocoParaHexaDecimal(bloco) + hexa;
    }
    return hexa;
}

string octalParaBinario(char octal) {
    switch (octal) {
        case '0': return "000";
        case '1': return "001";
        case '2': return "010";
        case '3': return "011";
        case '4': return "100";
        case '5': return "101";
        case '6': return "110";
        case '7': return "111";
        default: return "";
    }
}

string octalParaBinario(string octal) {
    string binario = "";
    for (int i = 0; i < octal.length(); i++) {
        binario += octalParaBinario(octal[i]);
    }
    return binario;
}

string digitoHexaParaBinario(char hexa) {
    switch (hexa) {
        case '0': return "0000"; case '1': return "0001";
        case '2': return "0010"; case '3': return "0011";
        case '4': return "0100"; case '5': return "0101";
        case '6': return "0110"; case '7': return "0111";
        case '8': return "1000"; case '9': return "1001";
        case 'A': case 'a': return "1010";
        case 'B': case 'b': return "1011";
        case 'C': case 'c': return "1100";
        case 'D': case 'd': return "1101";
        case 'E': case 'e': return "1110";
        case 'F': case 'f': return "1111";
        default: return "";
    }
}

string hexaParaBinario(string hexa) {
    string binario = "";
    for (int i = 0; i < hexa.length(); i++) {
        binario += digitoHexaParaBinario(hexa[i]);
    }
    
    return binario;
}

void PassoDecimalParaBinario(long long n){
    cout<< "PASSO A PASSO: Decimal para Binario" << endl;
    if(n==0){
        cout<< "Resultado: 0"<<endl;
        return;
    }
string resultado="";
while(n > 0){
    cout<< n << " /2 = " <<n/2 << " Resto " << n%2 << endl;
    char digito = '0' + (n % 2);
    resultado= digito + resultado;
    n = n/2;
}
cout<< "Lendo os resultados de baixo para cima:" <<resultado <<endl;
cout<< "Resultado: " << resultado << endl;
}

void PassoDecimalParaOctal(long long n){
   cout << "PASSO A PASSO: Decimal para Octal" << endl;
   if(n==0){
    cout<< "Resultado:0"<<endl;
    return;
   }
   string resultado="";
   while ( n>0){
    cout<< n << "/8 = " << n/8 << " Resto " << n%8 << endl;
    char digito = '0' + (n % 8);
    resultado = digito + resultado;
    n = n/8;
   }
   cout << "Lendo os resultados de baixo para cima" << resultado << endl;
   cout << "Resultado:" << resultado << endl;
   }

void PassoDecimalParaHexa(long long n){
    cout<< "PASSO A PASSO: Decimal para Hexadecimal" << endl;
    if( n==0){
    cout<< "Resultado: 0"<< endl;
    return;
    }
string resultado="";
string digitos = "0123456789ABCDEF";

while (n>0){
    cout<< n<< " / 16 =" << n/16 << " Resto " << n%16 << " = " <<digitos[n%16] << endl;
    resultado = digitos[n%16]+ resultado;
    n= n/16;
}
cout << "Lendo os resultados de baixo para cima: " << resultado << endl;
cout << "Resultado:" << resultado << endl;
}
void PassoBinarioParaDecimal(string s){
    cout << "PASSO A PASSO: Binario para Decimal" << endl;
    long long resultado =0;
    long long potencia =1;

for(int i= s.length()-1; i>=0; i--){
    int digito = s[i] - '0';
    
cout<< digito << " * " << potencia << " = " << digito*potencia << endl;
    resultado += digito * potencia;
    potencia *=2;
}
cout<< "Somando tudo:" << resultado << endl;
cout<< "Resultado: "<< resultado << endl;
}
void PassoOctalParaDecimal(string s){
    cout << "PASSO A PASSO: Octal para Decimal" << endl;
    long long resultado =0;
    long long potencia =1;

for(int i= s.length()-1; i>=0; i--){
    int digito = s[i] - '0':

cout<< digito <<" * "<<potencia << " = " << digito*potencia << endl;
    resultado += digito * potencia;
    potencia *=8;
}
cout<< "Somando tudo: " << resultado << endl;
cout<< "Resultado: " << resultado << endl;
}

void PassoHexaParaDecimal(string s){
    cout << "PASSO A PASSO: Hexadecimal para Decimal" << endl;
    long long resultado =0;
    long long potencia =1;
    string digitos = "0123456789ABCDEF";
for(int i= s.length()-1; i>=0; i--){
    int valor = digitos.find(s[i]);
    cout<< valor << " * " << potencia << " = " << valor*potencia
    resultado += valor * potencia;
    potencia *=16;
}
cout<< "Somando tudo: " << resultado << endl;
cout<< "Resultado: " << resultado << endl;
}

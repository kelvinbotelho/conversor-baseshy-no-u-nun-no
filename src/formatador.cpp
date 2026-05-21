#include "formatador.h"
#include <iostream>
#include <string>

using namespace std;


void PassoDecimalParaBinario(long long n)
{
    cout << "PASSO A PASSO: Decimal para Binario" << endl;
    if (n == 0)
    {
        cout << "Resultado: 0" << endl;
        return;
    }
    
    cout << "---------------------------------------" << endl;
    cout << "| Dividendo | Divisor | Quociente | Resto |" << endl;
    cout << "---------------------------------------" << endl;
    
    string resultado = "";
    while (n > 0)
    {
        long long quociente = n / 2;
        int resto = n % 2;
        
        // Imprime no formato de tabela simples
        cout << "| " << n << " \t| 2 \t| " << quociente << " \t| " << resto << " \t|" << endl;
        
        char digito = '0' + resto;
        resultado = digito + resultado;
        n = quociente;
    }
    cout << "---------------------------------------" << endl;
    cout << "Lendo os resultados de baixo para cima: " << resultado << endl;
    cout << "Resultado: " << resultado << endl;
}

void PassoDecimalParaOctal(long long n)
{
    cout << "PASSO A PASSO: Decimal para Octal" << endl;
    if (n == 0)
    {
        cout << "Resultado:0" << endl;
        return;
    }
    
    cout << "---------------------------------------" << endl;
    cout << "| Dividendo | Divisor | Quociente | Resto |" << endl;
    cout << "---------------------------------------" << endl;
    
    string resultado = "";
    while (n > 0)
    {
        long long quociente = n / 8;
        int resto = n % 8;
        
        cout << "| " << n << " \t| 8 \t| " << quociente << " \t| " << resto << " \t|" << endl;
        
        char digito = '0' + resto;
        resultado = digito + resultado;
        n = quociente;
    }
    cout << "---------------------------------------" << endl;
    cout << "Lendo os resultados de baixo para cima: " << resultado << endl;
    cout << "Resultado:" << resultado << endl;
}

void PassoDecimalParaHexa(long long n)
{
    cout << "PASSO A PASSO: Decimal para Hexadecimal" << endl;
    if (n == 0)
    {
        cout << "Resultado: 0" << endl;
        return;
    }
    
    cout << "-----------------------------------------------" << endl;
    cout << "| Dividendo | Divisor | Quociente | Resto | Digito |" << endl;
    cout << "-----------------------------------------------" << endl;
    
    string resultado = "";
    string digitos = "0123456789ABCDEF";

    while (n > 0)
    {
        long long quociente = n / 16;
        int resto = n % 16;
        char digitoHexa = digitos[resto];
        
        cout << "| " << n << " \t| 16 \t| " << quociente << " \t| " << resto << " \t| " << digitoHexa << " \t|" << endl;
        
        resultado = digitoHexa + resultado;
        n = quociente;
    }
    cout << "-----------------------------------------------" << endl;
    cout << "Lendo os resultados de baixo para cima: " << resultado << endl;
    cout << "Resultado:" << resultado << endl;
}



void PassoBinarioParaDecimal(string s)
{
    cout << "PASSO A PASSO: Binario para Decimal" << endl;
    
    cout << "-----------------------------------------" << endl;
    cout << "| Digito | * | Potencia | = |   Parcial |" << endl;
    cout << "-----------------------------------------" << endl;

    long long resultado = 0;
    long long potencia = 1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        int digito = s[i] - '0';
        long long parcial = digito * potencia;

        cout << "| " << digito << " \t | * | " << potencia << " \t| = | " << parcial << " \t|" << endl;
        
        resultado += parcial;
        potencia *= 2;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Somando tudo: " << resultado << endl;
    cout << "Resultado: " << resultado << endl;
}

void PassoOctalParaDecimal(string s)
{
    cout << "PASSO A PASSO: Octal para Decimal" << endl;
    
    cout << "-----------------------------------------" << endl;
    cout << "| Digito | * | Potencia | = |   Parcial |" << endl;
    cout << "-----------------------------------------" << endl;

    long long resultado = 0;
    long long potencia = 1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        int digito = s[i] - '0';
        long long parcial = digito * potencia;

        cout << "| " << digito << " \t | * | " << potencia << " \t| = | " << parcial << " \t|" << endl;
        
        resultado += parcial;
        potencia *= 8;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Somando tudo: " << resultado << endl;
    cout << "Resultado: " << resultado << endl;
}

void PassoHexaParaDecimal(string s)
{
    cout << "PASSO A PASSO: Hexadecimal para Decimal" << endl;
    
    cout << "---------------------------------------------------" << endl;
    cout << "| Caractere | Valor | * | Potencia | = |  Parcial |" << endl;
    cout << "---------------------------------------------------" << endl;

    long long resultado = 0;
    long long potencia = 1;
    string digitos = "0123456789ABCDEF";
    
    for (int i = s.length() - 1; i >= 0; i--)
    {
        int valor = digitos.find(s[i]);
        long long parcial = valor * potencia;
        
        cout << "| " << s[i] << " \t    | " << valor << " \t| * | " << potencia << " \t| = | " << parcial << " \t|" << endl;
        
        resultado += parcial;
        potencia *= 16;
    }
    cout << "---------------------------------------------------" << endl;
    cout << "Somando tudo: " << resultado << endl;
    cout << "Resultado: " << resultado << endl;
}


void PassoBinarioParaOctalDireto(string parteInteira, string parteFracionaria)
{
    cout << "PASSO A PASSO: Binario para Octal (Agrupamento de 3 bits)" << endl;
    
    cout << "1. Separando a parte inteira (da direita para a esquerda):" << endl;
    string bloco = "";
    for (int i = parteInteira.length() - 1; i >= 0; i--) 
    {
        bloco = parteInteira[i] + bloco;
        if (bloco.length() == 3 || i == 0) 
        {
            string blocoPronto = bloco;
            while (blocoPronto.length() < 3) 
            {
                blocoPronto = "0" + blocoPronto;
            }
            cout << "   Bloco original: [" << bloco << "] -> Ajustado: [" << blocoPronto << "]" << endl;
            bloco = "";
        }
    }

    if (parteFracionaria.length() > 0) 
    {
        cout << "2. Separando a parte fracionaria (da esquerda para a direita):" << endl;
        bloco = "";
        for (size_t i = 0; i < parteFracionaria.length(); i++) 
        {
            bloco += parteFracionaria[i];
            if (bloco.length() == 3 || i == parteFracionaria.length() - 1) 
            {
                string blocoPronto = bloco;
                while (blocoPronto.length() < 3) 
                {
                    blocoPronto = blocoPronto + "0";
                }
                cout << "   Bloco original: [" << bloco << "] -> Ajustado: [" << blocoPronto << "]" << endl;
                bloco = "";
            }
        }
    }
}

void PassoBinarioParaHexaDireto(string parteInteira, string parteFracionaria)
{
    cout << "PASSO A PASSO: Binario para Hexadecimal (Agrupamento de 4 bits)" << endl;
    
    cout << "1. Separando a parte inteira (da direita para a esquerda):" << endl;
    string bloco = "";
    for (int i = parteInteira.length() - 1; i >= 0; i--) 
    {
        bloco = parteInteira[i] + bloco;
        if (bloco.length() == 4 || i == 0) 
        {
            string blocoPronto = bloco;
            while (blocoPronto.length() < 4) 
            {
                blocoPronto = "0" + blocoPronto;
            }
            cout << "   Bloco original: [" << bloco << "] -> Ajustado: [" << blocoPronto << "]" << endl;
            bloco = "";
        }
    }

    if (parteFracionaria.length() > 0) 
    {
        cout << "2. Separando a parte fracionaria (da esquerda para a direita):" << endl;
        bloco = "";
        for (size_t i = 0; i < parteFracionaria.length(); i++) 
        {
            bloco += parteFracionaria[i];
            if (bloco.length() == 4 || i == parteFracionaria.length() - 1) 
            {
                string blocoPronto = bloco;
                while (blocoPronto.length() < 4) 
                {
                    blocoPronto = blocoPronto + "0";
                }
                cout << "   Bloco original: [" << bloco << "] -> Ajustado: [" << blocoPronto << "]" << endl;
                bloco = "";
            }
        }
    }
}


void PassoFracionarioDecimalParaQualquer(double n, int base) 
{
    cout << "PASSO A PASSO FRACIONARIO: Multiplicacoes Sucessivas pela base " << base << endl;
    int casas = 0;
    while (n > 0 && casas < 16) 
    {
        double original = n;
        n = n * base;
        int digito = (int)n;
        cout << original << " * " << base << " = " << n << " -> Extrai Dígito Inteiro: " << digito << endl;
        n = n - digito;
        casas++;
    }
}

void PassoFracionarioQualquerParaDecimal(string s, int base) 
{
    cout << "PASSO A PASSO FRACIONARIO: Potencias Negativas da base " << base << endl;
    double peso = 1.0 / base;
    for (size_t i = 0; i < s.length(); i++) 
    {
        cout << "Posicao -" << (i + 1) << ": Digito '" << s[i] << "' * (" << base << "^-" << (i + 1) << ") -> Peso: " << peso << endl;
        peso /= base;
    }
}
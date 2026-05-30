#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// AUXILIARES DE SUPORTE (PARSER MANUAL E LIMPEZA)
// ============================================================================

double converterStringParaDouble(string s) {
    double inteiro = 0.0;
    double fracionario = 0.0;
    double divisorFracionario = 10.0;
    bool naParteFracionaria = false;

    for (char c : s) {
        if (c == '.') {
            naParteFracionaria = true;
            continue;
        }
        if (!naParteFracionaria) {
            inteiro = inteiro * 10.0 + (c - '0');
        } else {
            fracionario = fracionario + (c - '0') / divisorFracionario;
            divisorFracionario *= 10.0;
        }
    }
    return inteiro + fracionario;
}

// Remove os zeros à esquerda da parte inteira para manter as saídas limpas
string limparZerosEsquerda(string s) {
    int posPonto = s.find('.');
    string parteInteira = (posPonto == string::npos) ? s : s.substr(0, posPonto);
    string parteFrac = (posPonto == string::npos) ? "" : s.substr(posPonto);

    int i = 0;
    while (i < parteInteira.length() - 1 && parteInteira[i] == '0') {
        i++;
    }
    return parteInteira.substr(i) + parteFrac;
}


// ============================================================================
// REQUISITO F1: DECIMAL -> BINÁRIO / OCTAL / HEXADECIMAL (INTEIROS)
// ============================================================================

// //f1 - Parte Inteira: Decimal para Binário
string inteiroDecimalparabinario(long long n)
{
    if (n == 0)
        return "0";
    string resultado = "";
    while (n > 0)
    {
        char digito = '0' + (n % 2);
        resultado = digito + resultado;
        n = n / 2;
    }
    return resultado;
}

// //f1 - Parte Inteira: Decimal para Octal
string inteiroDecimalparaoctal(long long n)
{
    if (n == 0)
        return "0";
    string resultado = "";
    while (n > 0)
    {
        char digito = '0' + (n % 8);
        resultado = digito + resultado;
        n = n / 8;
    }
    return resultado;
}

// //f1 - Parte Inteira: Decimal para Hexadecimalc
string inteiroDecimalparahexa(long long n)
{
    if (n == 0)
        return "0";
    string resultado = "";
    string digitos = "0123456789ABCDEF";
    while (n > 0)
    {
        resultado = digitos[n % 16] + resultado;
        n = n / 16;
    }
    return resultado;
}


// ============================================================================
// REQUISITO F2: BINÁRIO / OCTAL / HEXADECIMAL -> DECIMAL (INTEIROS)
// ============================================================================

// //f2 - Parte Inteira: Binário para Decimal
long long inteiroBinarioparadecimal(string s)
{
    long long resultado = 0;
    long long potencia = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        resultado += (s[i] - '0') * potencia;
        potencia *= 2;
    }
    return resultado;
}

// //f2 - Parte Inteira: Octal para Decimal
long long inteiroOctalparadecimal(string s)
{
    long long resultado = 0;
    long long potencia = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        resultado += (s[i] - '0') * potencia;
        potencia *= 8;
    }
    return resultado;
}

// //f2 - Parte Inteira: Hexadecimal para Decimal
long long inteiroHexaparadecimal(string s)
{
    long long resultado = 0;
    long long potencia = 1;
    string digitos = "0123456789ABCDEF";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        int valor = digitos.find(s[i]);
        resultado += valor * potencia;
        potencia *= 16;
    }
    return resultado;
}


// ============================================================================
// REQUISITO F3: CONVERSÃO DIRETA POR AGRUPAMENTO DE BITS (INTEIROS E FRACIONÁRIOS)
// ============================================================================

// //f3 - Mapeia trios de bits para um dígito Octal
char blocoParaOctal(string bloco)
{
    int valor = (bloco[0] - '0') * 4 + (bloco[1] - '0') * 2 + (bloco[2] - '0') * 1;
    return valor + '0';
}

// //f3 - Mapeia quartetos de bits para um dígito Hexadecimal
char blocoParaHexaDecimal(string bloco)
{
    while (bloco.length() < 4)
    {
        bloco = "0" + bloco;
    }
    int valor = (bloco[0] - '0') * 8 + (bloco[1] - '0') * 4 + (bloco[2] - '0') * 2 + (bloco[3] - '0') * 1;

    if (valor >= 0 && valor <= 9)
    {
        return valor + '0';
    }
    else
    {
        return (valor - 10) + 'A';
    }
}

// //f3 - Conversão Binário para Octal via Agrupamento de 3 bits
string binarioParaOctal(string binario)
{
    string octalInteiro = "", blocoInteiro = "", octalFracionario = "", blocoFracionario = "", octalFinal = "", parteInteiraStr = "", parteFracionariaStr = "";
    int posicaoPonto = -1;
    bool truncou = false;
    
    for (int i = 0; i < binario.length(); i++)
    {
        if (binario[i] == ',' || binario[i] == '.')
        {
            binario[i] = '.';
            posicaoPonto = i;
            break;
        }
    }
    if (posicaoPonto == -1)
    {
        parteInteiraStr = binario;
        parteFracionariaStr = "";
    }
    else
    {
        parteInteiraStr = binario.substr(0, posicaoPonto);
        parteFracionariaStr = binario.substr(posicaoPonto + 1);
    }
    
    for (int i = parteInteiraStr.length() - 1; i >= 0; i--)
    {
        blocoInteiro = parteInteiraStr[i] + blocoInteiro;
        if (blocoInteiro.length() == 3)
        {
            octalInteiro = blocoParaOctal(blocoInteiro) + octalInteiro;
            blocoInteiro = "";
        }
    }
    
    for (int i = 0; i < parteFracionariaStr.length(); i++)
    {
        blocoFracionario = blocoFracionario + parteFracionariaStr[i];
        if (blocoFracionario.length() == 3)
        {
            octalFracionario = octalFracionario + blocoParaOctal(blocoFracionario);
            blocoFracionario = "";
        }
    }
    if (blocoInteiro.length() > 0)
    {
        while (blocoInteiro.length() < 3)
        {
            blocoInteiro = "0" + blocoInteiro;
        }
        octalInteiro = blocoParaOctal(blocoInteiro) + octalInteiro;
    }

    if (blocoFracionario.length() > 0)
    {
        while (blocoFracionario.length() < 3)
        {
            blocoFracionario = blocoFracionario + "0";
        }
        octalFracionario = octalFracionario + blocoParaOctal(blocoFracionario);
    }
    if (octalFracionario.length() > 16)
    {
        truncou = true;
        octalFracionario = octalFracionario.substr(0, 16);
    }
    
    octalFinal = octalInteiro;
    if (octalFracionario != "") {
        octalFinal += '.' + octalFracionario;
    }
    return limparZerosEsquerda(octalFinal);
}

// //f3 - Conversão Binário para Hexadecimal via Agrupamento de 4 bits
string binarioParaHexaDecimal(string binario)
{
    string hexaInteiro = "", blocoInteiro = "", hexaFracionario = "", blocoFracionario = "", hexaFinal = "", parteInteiraStr = "", parteFracionariaStr = "";
    int posicaoPonto = -1;
    bool truncou = false;
    
    for (int i = 0; i < binario.length(); i++)
    {
        if (binario[i] == ',' || binario[i] == '.')
        {
            binario[i] = '.';
            posicaoPonto = i;
            break;
        }
    }
    if (posicaoPonto == -1)
    {
        parteInteiraStr = binario;
        parteFracionariaStr = "";
    }
    else
    {
        parteInteiraStr = binario.substr(0, posicaoPonto);
        parteFracionariaStr = binario.substr(posicaoPonto + 1);
    }
    
    for (int i = parteInteiraStr.length() - 1; i >= 0; i--)
    {
        blocoInteiro = parteInteiraStr[i] + blocoInteiro;
        if (blocoInteiro.length() == 4)
        {
            hexaInteiro = blocoParaHexaDecimal(blocoInteiro) + hexaInteiro;
            blocoInteiro = "";
        }
    }
    
    for (int i = 0; i < parteFracionariaStr.length(); i++)
    {
        blocoFracionario = blocoFracionario + parteFracionariaStr[i];
        if (blocoFracionario.length() == 4)
        {
            hexaFracionario = hexaFracionario + blocoParaHexaDecimal(blocoFracionario);
            blocoFracionario = "";
        }
    }
    if (blocoInteiro.length() > 0)
    {
        while (blocoInteiro.length() < 4)
        {
            blocoInteiro = "0" + blocoInteiro;
        }
        hexaInteiro = blocoParaHexaDecimal(blocoInteiro) + hexaInteiro;
    }

    if (blocoFracionario.length() > 0)
    {
        while (blocoFracionario.length() < 4)
        {
            blocoFracionario = blocoFracionario + "0";
        }
        hexaFracionario = hexaFracionario + blocoParaHexaDecimal(blocoFracionario);
    }
    if (hexaFracionario.length() > 16)
    {
        truncou = true;
        hexaFracionario = hexaFracionario.substr(0, 16);
    }
    
    hexaFinal = hexaInteiro;
    if (hexaFracionario != "") {
        hexaFinal += '.' + hexaFracionario;
    }
    return limparZerosEsquerda(hexaFinal);
}

// //f3 - Traduz um dígito Octal direto para 3 bits
string digitoOctalParaBinario(char octal)
{
    switch (octal)
    {
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

// //f3 - Traduz um dígito Hexa direto para 4 bits
string digitoHexaParaBinario(char hexa)
{
    switch (hexa)
    {
    case '0': return "0000";
    case '1': return "0001";
    case '2': return "0010";
    case '3': return "0011";
    case '4': return "0100";
    case '5': return "0101";
    case '6': return "0110";
    case '7': return "0111";
    case '8': return "1000";
    case '9': return "1001";
    case 'A': case 'a': return "1010";
    case 'B': case 'b': return "1011";
    case 'C': case 'c': return "1100";
    case 'D': case 'd': return "1101";
    case 'E': case 'e': return "1110";
    case 'F': case 'f': return "1111";
    default: return "";
    }
}

// //f3 - Conversor Hexadecimal para Binário direto
string hexaParaBinario(string hexa)
{
    string binario = "";
    int indicePonto = -1;

    for (int i = 0; i < hexa.length(); i++)
    {
        if (hexa[i] == '.' || hexa[i] == ',')
        {
            binario += '.';
            indicePonto = binario.length() - 1;
        }
        else
        {
            binario += digitoHexaParaBinario(hexa[i]);
            if (indicePonto != -1)
            {
                int tamanhoFracionario = binario.length() - 1 - indicePonto;
                if (tamanhoFracionario >= 16)
                {
                    binario = binario.substr(0, indicePonto + 1 + 16);
                    break;
                }
            }
        }
    }
    return limparZerosEsquerda(binario);
}


// ============================================================================
// REQUISITO F4: CONVERSÃO ENTRE OUTRAS BASES VIA BINÁRIO
// ============================================================================

// //f4 - Conversor de Octal para Binário (Intermediário obrigatório de F4)
string octalParaBinario(string octal)
{
    string binario = "";
    int indicePonto = -1;

    for (int i = 0; i < octal.length(); i++)
    {
        if (octal[i] == '.' || octal[i] == ',')
        {
            binario += '.';
            indicePonto = binario.length() - 1;
        }
        else
        {
            binario += digitoOctalParaBinario(octal[i]);
            if (indicePonto != -1)
            {
                int tamanhoFracionario = binario.length() - 1 - indicePonto;
                if (tamanhoFracionario >= 16)
                {
                    binario = binario.substr(0, indicePonto + 1 + 16);
                    break;
                }
            }
        }
    }
    return limparZerosEsquerda(binario);
}


// ============================================================================
// REQUISITO F6: SUPORTE A NÚMEROS FRACIONÁRIOS (ETAPAS COMPLEMENTARES)
// ============================================================================

// //f6 - Parte Fracionária: Decimal para Binário (Multiplicações Sucessivas)
string fracionarioDecimalParaBinario(double n, bool &houveTruncamento)
{
    std::string resultado = "";
    int contadorCasas = 0;
    houveTruncamento = false;

    while (n > 1e-9 && contadorCasas < 16)
    {
        n = n * 2;
        if (n >= 1.0)
        {
            resultado += "1";
            n = n - 1.0;
        }
        else
        {
            resultado += "0";
        }
        contadorCasas++;
    }
    if (n > 1e-9 && contadorCasas == 16)
    {
        houveTruncamento = true;
    }
    return resultado;
}

// //f6 - Parte Fracionária: Decimal para Octal (Multiplicações Sucessivas)
string fracionarioDecimalParaOctal(double n, bool &houveTruncamento)
{
    string resultado = "";
    int contadorCasas = 0;
    houveTruncamento = false;

    while (n > 1e-9 && contadorCasas < 16)
    {
        n = n * 8;
        int digito = (int)n;
        resultado += (digito + '0');
        n = n - digito;
        contadorCasas++;
    }
    if (n > 1e-9 && contadorCasas == 16)
    {
        houveTruncamento = true;
    }
    return resultado;
}

// //f6 - Parte Fracionária: Decimal para Hexadecimal (Multiplicações Sucessivas)
string fracionarioDecimalParaHexa(double n, bool &houveTruncamento)
{
    string resultado = "";
    int contadorCasas = 0;
    houveTruncamento = false;

    while (n > 1e-9 && contadorCasas < 16)
    {
        n = n * 16;
        int digito = (int)n;
        if (digito >= 0 && digito <= 9)
        {
            resultado += (digito + '0');
        }
        else
        {
            resultado += ((digito - 10) + 'A');
        }
        n = n - digito;
        contadorCasas++;
    }
    if (n > 1e-9 && contadorCasas == 16)
    {
        houveTruncamento = true;
    }
    return resultado;
}

// //f6 - Parte Fracionária: Binário para Decimal (Pesos de Potências Negativas)
double fracionarioBinarioparadecimal(string s)
{
    double resultado = 0.0;
    double peso = 0.5;
    for (int i = 0; i < s.length(); i++)
    {
        resultado += (s[i] - '0') * peso;
        peso = peso / 2.0;
    }
    return resultado;
}

// //f6 - Parte Fracionária: Octal para Decimal (Pesos de Potências Negativas)
double fracionarioOctalparadecimal(string s)
{
    double resultado = 0.0;
    double peso = 1.0 / 8.0;
    for (int i = 0; i < s.length(); i++)
    {
        resultado += (s[i] - '0') * peso;
        peso = peso / 8.0;
    }
    return resultado;
}

// //f6 - Parte Fracionária: Hexadecimal para Decimal (Pesos de Potências Negativas)
double fracionarioHexaparadecimal(string s)
{
    double resultado = 0.0;
    double peso = 1.0 / 16.0;

    for (int i = 0; i < s.length(); i++)
    {
        int valorDigito = 0;
        if (s[i] >= '0' && s[i] <= '9')
        {
            valorDigito = s[i] - '0';
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            valorDigito = s[i] - 'A' + 10;
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            valorDigito = s[i] - 'a' + 10;
        }

        resultado += valorDigito * peso;
        peso = peso / 16.0;
    }
    return resultado;
}


// ============================================================================
// CONCENTRADORES GERAIS DE DESPACHO DE ENTRADAS (F1 + F2 + F6)
// ============================================================================

// Concentrador de conversão Decimal para as demais bases (F1 + F6)
string decimalparaBinarioOctalHexa(string numero, int base)
{
    for (int i = 0; i < numero.length(); i++)
    {
        if (numero[i] == ',')
        {
            numero[i] = '.'; 
        }
    }
    
    double n = converterStringParaDouble(numero); 
    
    if (n == 0)
        return "0";
        
    string resultado = "", resultadoInteiro, resultadoFracionario;
    bool truncou = false;
    long long parteInteira = (long long)n;
    double parteFracionaria = n - parteInteira;
    
    if (base == 2)
    {
        resultadoInteiro = inteiroDecimalparabinario(parteInteira);
        resultadoFracionario = fracionarioDecimalParaBinario(parteFracionaria, truncou);
    }
    else if (base == 8)
    {
        resultadoInteiro = inteiroDecimalparaoctal(parteInteira);
        resultadoFracionario = fracionarioDecimalParaOctal(parteFracionaria, truncou);
    }
    else
    {
        resultadoInteiro = inteiroDecimalparahexa(parteInteira);
        resultadoFracionario = fracionarioDecimalParaHexa(parteFracionaria, truncou);
    }
    
    resultado = resultadoInteiro;
    if (resultadoFracionario != "")
    {
        resultado += "." + resultadoFracionario;
    }
    
    if (truncou)
    {
        cout << "AVISO: O numero foi truncado em 16 casas decimais!" << std::endl; 
    }
    return resultado;
}

// Concentrador da conversão de Outras Bases para Decimal (F2 + F6)
double binarioOctalHexaParaDecimal(string numero, int base)
{
    int posicaoPonto = 0;
    for (int i = 0; i < numero.length(); i++)
    {
        if (numero[i] == ',' || numero[i] == '.')
        {
            numero[i] = '.';
            posicaoPonto = i;
        }
    }
    if (numero == "0")
        return 0;

    string parteInteiraStr, parteFracionariaStr;
    double resultado, resultadoFracionario;
    long long resultadoInteiro;
    bool truncou = false;
    
    if (posicaoPonto == 0)
    {
        parteInteiraStr = numero;
        parteFracionariaStr = "";
    }
    else
    {
        parteInteiraStr = numero.substr(0, posicaoPonto);
        parteFracionariaStr = numero.substr(posicaoPonto + 1);
    }
    
    if (parteFracionariaStr.length() > 16)
    {
        truncou = true;
        parteFracionariaStr = parteFracionariaStr.substr(0, 16);
    }
    
    if (base == 2)
    {
        resultadoInteiro = inteiroBinarioparadecimal(parteInteiraStr);
        resultadoFracionario = fracionarioBinarioparadecimal(parteFracionariaStr);
    }
    else if (base == 8)
    {
        resultadoInteiro = inteiroOctalparadecimal(parteInteiraStr);
        resultadoFracionario = fracionarioOctalparadecimal(parteFracionariaStr);
    }
    else
    {
        resultadoInteiro = inteiroHexaparadecimal(parteInteiraStr);
        resultadoFracionario = fracionarioHexaparadecimal(parteFracionariaStr);
    }
    
    resultado = resultadoInteiro + resultadoFracionario;
    if (truncou)
    {
        cout << "AVISO: O numero foi truncado em 16 casas decimais!" << std::endl;
    }
    return resultado;
}
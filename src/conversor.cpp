#include <iostream>
#include <string>

using namespace std;

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
string fracionarioDecimalParaBinario(double n, bool &houveTruncamento)
{
    std::string resultado = "";
    int contadorCasas = 0;
    houveTruncamento = false;

    while (n > 0 && contadorCasas < 16)
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
    if (n > 0 && contadorCasas == 16)
    {
        houveTruncamento = true;
    }

    return resultado;
}

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

string fracionarioDecimalParaOctal(double n, bool &houveTruncamento)
{
    string resultado = "";
    int contadorCasas = 0;
    houveTruncamento = false;

    while (n > 0 && contadorCasas < 16)
    {
        n = n * 8;

        int digito = (int)n;
        resultado += (digito + '0');

        n = n - digito;
        contadorCasas++;
    }
    if (n > 0 && contadorCasas == 16)
    {
        houveTruncamento = true;
    }

    return resultado;
}

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

string fracionarioDecimalParaHexa(double n, bool &houveTruncamento)
{
    string resultado = "";
    int contadorCasas = 0;
    houveTruncamento = false;

    while (n > 0 && contadorCasas < 16)
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
    if (n > 0 && contadorCasas == 16)
    {
        houveTruncamento = true;
    }

    return resultado;
}

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

double fracionarioHexaparadecimal(string s)
{
    double resultado = 0.0;
    double peso = 1.0 / 16.0;

    for (int i = 0; i < s.length(); i++)
    {
        int valorDigito;

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

string decimalparaBinarioOctalHexa(string numero, int base)
{
    for (int i = 0; i < numero.length(); i++)
    {
        if (numero[i] == ',')
        {
            numero[i] = '.';
        }
    }
    double n = std::stod(numero);
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

char blocoParaOctal(string bloco)
{
    int valor = (bloco[0] - '0') * 4 + (bloco[1] - '0') * 2 + (bloco[2] - '0') * 1;

    return valor + '0';
}

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
    // calcula parte inteira
    for (int i = parteInteiraStr.length() - 1; i >= 0; i--)
    {
        blocoInteiro = parteInteiraStr[i] + blocoInteiro;
        if (blocoInteiro.length() == 3)
        {
            octalInteiro = blocoParaOctal(blocoInteiro) + octalInteiro;
            blocoInteiro = "";
        }
    }
    // calcula parte fracionaria
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
        // truncamento
        truncou = true;
        octalFracionario = octalFracionario.substr(0, 16);
    }
    octalFinal = octalInteiro + '.' + octalFracionario;
    return octalFinal;
}
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
    // calcula parte inteira
    for (int i = parteInteiraStr.length() - 1; i >= 0; i--)
    {
        blocoInteiro = parteInteiraStr[i] + blocoInteiro;
        if (blocoInteiro.length() == 4)
        {
            hexaInteiro = blocoParaHexaDecimal(blocoInteiro) + hexaInteiro;
            blocoInteiro = "";
        }
    }
    // calcula parte fracionaria
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
        // truncamento
        truncou = true;
        hexaFracionario = hexaFracionario.substr(0, 16);
    }
    hexaFinal = hexaInteiro + '.' + hexaFracionario;
    return hexaFinal;
}

string digitoOctalParaBinario(char octal)
{
    switch (octal)
    {
    case '0':
        return "000";
    case '1':
        return "001";
    case '2':
        return "010";
    case '3':
        return "011";
    case '4':
        return "100";
    case '5':
        return "101";
    case '6':
        return "110";
    case '7':
        return "111";
    default:
        return "";
    }
}

string octalParaBinario(string octal)
{
    string binario = "";
    bool truncou = false;

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
                    truncou = true;

                    binario = binario.substr(0, indicePonto + 1 + 16);
                    break;
                }
            }
        }
    }
    return binario;
}

string digitoHexaParaBinario(char hexa)
{
    switch (hexa)
    {
    case '0':
        return "0000";
    case '1':
        return "0001";
    case '2':
        return "0010";
    case '3':
        return "0011";
    case '4':
        return "0100";
    case '5':
        return "0101";
    case '6':
        return "0110";
    case '7':
        return "0111";
    case '8':
        return "1000";
    case '9':
        return "1001";
    case 'A':
    case 'a':
        return "1010";
    case 'B':
    case 'b':
        return "1011";
    case 'C':
    case 'c':
        return "1100";
    case 'D':
    case 'd':
        return "1101";
    case 'E':
    case 'e':
        return "1110";
    case 'F':
    case 'f':
        return "1111";
    default:
        return "";
    }
}

string hexaParaBinario(string hexa)
{
    string binario = "";
    bool truncou = false;

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
                    truncou = true;

                    binario = binario.substr(0, indicePonto + 1 + 16);
                    break;
                }
            }
        }
    }

    return binario;
}

void PassoDecimalParaBinario(long long n)
{
    cout << "PASSO A PASSO: Decimal para Binario" << endl;
    if (n == 0)
    {
        cout << "Resultado: 0" << endl;
        return;
    }
    string resultado = "";
    while (n > 0)
    {
        cout << n << " /2 = " << n / 2 << " Resto " << n % 2 << endl;
        char digito = '0' + (n % 2);
        resultado = digito + resultado;
        n = n / 2;
    }
    cout << "Lendo os resultados de baixo para cima:" << resultado << endl;
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
    string resultado = "";
    while (n > 0)
    {
        cout << n << "/8 = " << n / 8 << " Resto " << n % 8 << endl;
        char digito = '0' + (n % 8);
        resultado = digito + resultado;
        n = n / 8;
    }
    cout << "Lendo os resultados de baixo para cima" << resultado << endl;
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
    string resultado = "";
    string digitos = "0123456789ABCDEF";

    while (n > 0)
    {
        cout << n << " / 16 =" << n / 16 << " Resto " << n % 16 << " = " << digitos[n % 16] << endl;
        resultado = digitos[n % 16] + resultado;
        n = n / 16;
    }
    cout << "Lendo os resultados de baixo para cima: " << resultado << endl;
    cout << "Resultado:" << resultado << endl;
}
void PassoBinarioParaDecimal(string s)
{
    cout << "PASSO A PASSO: Binario para Decimal" << endl;
    long long resultado = 0;
    long long potencia = 1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        int digito = s[i] - '0';

        cout << digito << " * " << potencia << " = " << digito * potencia << endl;
        resultado += digito * potencia;
        potencia *= 2;
    }
    cout << "Somando tudo:" << resultado << endl;
    cout << "Resultado: " << resultado << endl;
}
void PassoOctalParaDecimal(string s)
{
    cout << "PASSO A PASSO: Octal para Decimal" << endl;
    long long resultado = 0;
    long long potencia = 1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        int digito = s[i] - '0';

        cout << digito << " * " << potencia << " = " << digito * potencia << endl;
        resultado += digito * potencia;
        potencia *= 8;
    }
    cout << "Somando tudo: " << resultado << endl;
    cout << "Resultado: " << resultado << endl;
}

void PassoHexaParaDecimal(string s)
{
    cout << "PASSO A PASSO: Hexadecimal para Decimal" << endl;
    long long resultado = 0;
    long long potencia = 1;
    string digitos = "0123456789ABCDEF";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        int valor = digitos.find(s[i]);
        cout << valor << " * " << potencia << " = " << valor * potencia;
        resultado += valor * potencia;
        potencia *= 16;
    }
    cout << "Somando tudo: " << resultado << endl;
    cout << "Resultado: " << resultado << endl;
}

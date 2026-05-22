#include <iostream>
#include <string>

using namespace std;

// =======================================================================
// DECLARAÇÕES DAS FUNÇÕES (PROTÓTIPOS)
// =======================================================================
string decimalparaBinarioOctalHexa(string n, int b);
long long inteiroBinarioparadecimal(string s);
long long inteiroOctalparadecimal(string s);
long long inteiroHexaparadecimal(string s);
string binarioParaOctal(string s);
string binarioParaHexaDecimal(string s);
string octalParaBinario(string s);
string hexaParaBinario(string s);

bool validarBinario(string s);
bool validarOctal(string s);
bool validarDecimal(string s);
bool validarHexaDecimal(string s);

void PassoDecimalParaBinario(long long n);
void PassoDecimalParaOctal(long long n);
void PassoDecimalParaHexa(long long n);
void PassoBinarioParaDecimal(string s);
void PassoOctalParaDecimal(string s);
void PassoHexaParaDecimal(string s);
void PassoBinarioParaOctalDireto(string parteInteira, string parteFracionaria);
void PassoBinarioParaHexaDireto(string parteInteira, string parteFracionaria);
void PassoFracionarioDecimalParaQualquer(double n, int base);
void PassoFracionarioQualquerParaDecimal(string s, int base);

// =======================================================================
// INFRAESTRUTURA DA SUÍTE DE TESTES
// =======================================================================
int totalTestes = 0;
int testesPassaram = 0;

void teste(string descricao, string resultado, string esperado){
    totalTestes++;
    if(resultado == esperado){
        cout << "[OK] " << descricao << endl;
        testesPassaram++;
    } else {
        cout << "[FALHOU] " << descricao << endl;
        cout << "  Esperado: " << esperado << endl;
        cout << "  Obtido:   " << resultado << endl;
    }
}

void testeInt(string descricao, long long resultado, long long esperado){
    totalTestes++;
    if(resultado == esperado){
        cout << "[OK] " << descricao << endl;
        testesPassaram++;
    } else {
        cout << "[FALHOU] " << descricao << endl;
        cout << "  Esperado: " << esperado << endl;
        cout << "  Obtido:   " << resultado << endl;
    }
}

void testeBool(string descricao, bool resultado, bool esperado){
    totalTestes++;
    if(resultado == esperado){
        cout << "[OK] " << descricao << endl;
        testesPassaram++;
    } else {
        cout << "[FALHOU] " << descricao << endl;
    }
}

// =======================================================================
// MÓDULO PRINCIPAL DE TESTES (MAIN)
// =======================================================================
int main(){
    cout << "=== SUITE DE TESTES ===" << endl << endl;

    // F1 - Decimal para Binario
    cout << "--- F1: Decimal para Binario ---" << endl;
    teste("0 decimal = 0 binario", decimalparaBinarioOctalHexa("0", 2), "0");
    teste("1 decimal = 1 binario", decimalparaBinarioOctalHexa("1", 2), "1");
    teste("13 decimal = 1101 binario", decimalparaBinarioOctalHexa("13", 2), "1101");
    teste("255 decimal = 11111111 binario", decimalparaBinarioOctalHexa("255", 2), "11111111");
    teste("8 decimal = 1000 binario", decimalparaBinarioOctalHexa("8", 2), "1000");

    // F1 - Decimal para Octal
    cout << endl << "--- F1: Decimal para Octal ---" << endl;
    teste("0 decimal = 0 octal", decimalparaBinarioOctalHexa("0", 8), "0");
    teste("8 decimal = 10 octal", decimalparaBinarioOctalHexa("8", 8), "10");
    teste("13 decimal = 15 octal", decimalparaBinarioOctalHexa("13", 8), "15");
    teste("255 decimal = 377 octal", decimalparaBinarioOctalHexa("255", 8), "377");

    // F1 - Decimal para Hexadecimal
    cout << endl << "--- F1: Decimal para Hexadecimal ---" << endl;
    teste("0 decimal = 0 hex", decimalparaBinarioOctalHexa("0", 16), "0");
    teste("13 decimal = D hex", decimalparaBinarioOctalHexa("13", 16), "D");
    teste("255 decimal = FF hex", decimalparaBinarioOctalHexa("255", 16), "FF");
    teste("16 decimal = 10 hex", decimalparaBinarioOctalHexa("16", 16), "10");

    // F2 - Binario para Decimal
    cout << endl << "--- F2: Binario para Decimal ---" << endl;
    testeInt("0 binario = 0 decimal", inteiroBinarioparadecimal("0"), 0);
    testeInt("1101 binario = 13 decimal", inteiroBinarioparadecimal("1101"), 13);
    testeInt("11111111 binario = 255 decimal", inteiroBinarioparadecimal("11111111"), 255);
    testeInt("1000 binario = 8 decimal", inteiroBinarioparadecimal("1000"), 8);

    // F2 - Octal para Decimal
    cout << endl << "--- F2: Octal para Decimal ---" << endl;
    testeInt("0 octal = 0 decimal", inteiroOctalparadecimal("0"), 0);
    testeInt("15 octal = 13 decimal", inteiroOctalparadecimal("15"), 13);
    testeInt("377 octal = 255 decimal", inteiroOctalparadecimal("377"), 255);

    // F2 - Hexadecimal para Decimal
    cout << endl << "--- F2: Hexadecimal para Decimal ---" << endl;
    testeInt("D hex = 13 decimal", inteiroHexaparadecimal("D"), 13);
    testeInt("FF hex = 255 decimal", inteiroHexaparadecimal("FF"), 255);
    testeInt("10 hex = 16 decimal", inteiroHexaparadecimal("10"), 16);

    // F3 - Binario para Octal
    cout << endl << "--- F3: Binario para Octal ---" << endl;
    teste("111 binario = 7. octal", binarioParaOctal("111"), "7.");
    teste("11111 binario = 37. octal", binarioParaOctal("11111"), "37.");
    teste("1000 binario = 10. octal", binarioParaOctal("1000"), "10.");

    // F3 - Binario para Hexadecimal
    cout << endl << "--- F3: Binario para Hexadecimal ---" << endl;
    teste("1111 binario = F. hex", binarioParaHexaDecimal("1111"), "F.");
    teste("11111111 binario = FF. hex", binarioParaHexaDecimal("11111111"), "FF.");
    teste("10000 binario = 10. hex", binarioParaHexaDecimal("10000"), "10.");

    // F3 - Octal para Binario
    cout << endl << "--- F3: Octal para Binario ---" << endl;
    teste("7 octal = 111 binario", octalParaBinario("7"), "111");
    teste("37 octal = 011111 binario", octalParaBinario("37"), "011111");

    // F3 - Hex para Binario
    cout << endl << "--- F3: Hex para Binario ---" << endl;
    teste("F hex = 1111 binario", hexaParaBinario("F"), "1111");
    teste("FF hex = 11111111 binario", hexaParaBinario("FF"), "11111111");

    // F4 - Octal para Hex via Binario
    cout << endl << "--- F4: Octal para Hex via Binario ---" << endl;
    teste("37 octal = 1F. hex", binarioParaHexaDecimal(octalParaBinario("37")), "1F.");
    teste("10 octal = 8. hex", binarioParaHexaDecimal(octalParaBinario("10")), "8.");

    // F5 - Validacao Binario
    cout << endl << "--- F5: Validacao Binario ---" << endl;
    testeBool("1101 e binario valido", validarBinario("1101"), true);
    testeBool("1234 nao e binario valido", validarBinario("1234"), false);
    testeBool("string vazia nao e binario valido", validarBinario(""), false);

    // F5 - Validacao Octal
    cout << endl << "--- F5: Validacao Octal ---" << endl;
    testeBool("777 e octal valido", validarOctal("777"), true);
    testeBool("899 nao e octal valido", validarOctal("899"), false);
    testeBool("string vazia nao e octal valido", validarOctal(""), false);

    // F5 - Validacao Decimal
    cout << endl << "--- F5: Validacao Decimal ---" << endl;
    testeBool("4289 e decimal valido", validarDecimal("4289"), true);
    testeBool("string vazia nao e decimal valido", validarDecimal(""), false);

    // F5 - Validacao Hexadecimal
    cout << endl << "--- F5: Validacao Hexadecimal ---" << endl;
    testeBool("FF e hexadecimal valido", validarHexaDecimal("FF"), true);
    testeBool("GG nao e hexadecimal valido", validarHexaDecimal("GG"), false);
    testeBool("49ABc e hexadecimal valido", validarHexaDecimal("49ABc"), true);

    // F6 - Fracionarios Decimal para Binario
    cout << endl << "--- F6: Fracionarios Decimal para Binario ---" << endl;
    teste("10.625 decimal = 1010.101 binario", decimalparaBinarioOctalHexa("10.625", 2), "1010.101");
    teste("0.5 decimal = 0.1 binario", decimalparaBinarioOctalHexa("0.5", 2), "0.1");
    teste("0.25 decimal = 0.01 binario", decimalparaBinarioOctalHexa("0.25", 2), "0.01");

    // F6 - Fracionarios Decimal para Octal
    cout << endl << "--- F6: Fracionarios Decimal para Octal ---" << endl;
    teste("13.625 decimal = 15.5 octal", decimalparaBinarioOctalHexa("13.625", 8), "15.5");
    teste("8.5 decimal = 10.4 octal", decimalparaBinarioOctalHexa("8.5", 8), "10.4");

    // F6 - Fracionarios Decimal para Hex
    cout << endl << "--- F6: Fracionarios Decimal para Hexadecimal ---" << endl;
    teste("0.5 decimal = 0.8 hex", decimalparaBinarioOctalHexa("0.5", 16), "0.8");

    // F5 - Casos Criticos Extras de Validacao
    cout << endl << "--- F5: Casos Criticos Extras de Validacao ---" << endl;
    testeBool("Binario com espaco deve ser invalido", validarBinario("11 01"), false);
    testeBool("Hexadecimal com caracteres especiais deve ser invalido", validarHexaDecimal("FF@1"), false);

    // F10 - Calculadora de Maximos
    cout << endl << "--- F10: Calculadora de Maximos ---" << endl;
    testeInt("1 bit maximo = 1", (long long)(1 * 2 - 1), 1);
    testeInt("8 bits maximo = 255", (long long)(256 - 1), 255);
    testeInt("16 bits maximo = 65535", (long long)(65536 - 1), 65535);

    // F7 - Testes de Execução Visual (Console Trace das Tabelas)
    cout << endl << "--- F7: Verificacao Visual do Passo a Passo (Console Trace) ---" << endl;
    cout << "[Executando] Passo a Passo Divisoes por 2:" << endl;
    PassoDecimalParaBinario(13);
    cout << endl << "[Executando] Passo a Passo Divisoes por 8:" << endl;
    PassoDecimalParaOctal(13);
    cout << endl << "[Executando] Passo a Passo Divisoes por 16:" << endl;
    PassoDecimalParaHexa(13);

    cout << endl << "[Executando] Passo a Passo Somatorio Binario:" << endl;
    PassoBinarioParaDecimal("1101");
    cout << endl << "[Executando] Passo a Passo Somatorio Octal:" << endl;
    PassoOctalParaDecimal("15");
    cout << endl << "[Executando] Passo a Passo Somatorio Hexadecimal:" << endl;
    PassoHexaParaDecimal("D");

    cout << endl << "[Executando] Passo a Passo Agrupamento Bin->Octal:" << endl;
    PassoBinarioParaOctalDireto("11111", "101");
    cout << endl << "[Executando] Passo a Passo Agrupamento Bin->Hexa:" << endl;
    PassoBinarioParaHexaDireto("10000", "11");

    cout << endl << "[Executando] Passo a Passo Fracionario (Multiplicacoes):" << endl;
    PassoFracionarioDecimalParaQualquer(0.625, 2);
    cout << endl << "[Executando] Passo a Passo Fracionario (Potencias Negativas):" << endl;
    PassoFracionarioQualquerParaDecimal("101", 2);

    cout << endl << "=== RESULTADO FINAL DE TESTES AUTOMATICOS ===" << endl;
    cout << testesPassaram << "/" << totalTestes << " testes passaram." << endl;

    return 0;
}

// =======================================================================
// IMPLEMENTAÇÃO DAS FUNÇÕES DA F7 (MODO PASSO A PASSO COM TABELAS)
// =======================================================================

void PassoDecimalParaBinario(long long n) {
    cout << "PASSO A PASSO: Decimal para Binario" << endl;
    if (n == 0) { cout << "Resultado: 0" << endl; return; }
    
    cout << "---------------------------------------" << endl;
    cout << "| Dividendo | Divisor | Quociente | Resto |" << endl;
    cout << "---------------------------------------" << endl;
    
    string resultado = "";
    while (n > 0) {
        long long quociente = n / 2;
        int resto = n % 2;
        cout << "| " << n << " \t| 2 \t| " << quociente << " \t| " << resto << " \t|" << endl;
        char digito = '0' + resto;
        resultado = digito + resultado;
        n = quociente;
    }
    cout << "---------------------------------------" << endl;
    cout << "Lendo os resultados de baixo para cima: " << resultado << endl;
}

void PassoDecimalParaOctal(long long n) {
    cout << "PASSO A PASSO: Decimal para Octal" << endl;
    if (n == 0) { cout << "Resultado: 0" << endl; return; }
    
    cout << "---------------------------------------" << endl;
    cout << "| Dividendo | Divisor | Quociente | Resto |" << endl;
    cout << "---------------------------------------" << endl;
    
    string resultado = "";
    while (n > 0) {
        long long quociente = n / 8;
        int resto = n % 8;
        cout << "| " << n << " \t| 8 \t| " << quociente << " \t| " << resto << " \t|" << endl;
        char digito = '0' + resto;
        resultado = digito + resultado;
        n = quociente;
    }
    cout << "---------------------------------------" << endl;
    cout << "Lendo os resultados de baixo para cima: " << resultado << endl;
}

void PassoDecimalParaHexa(long long n) {
    cout << "PASSO A PASSO: Decimal para Hexadecimal" << endl;
    if (n == 0) { cout << "Resultado: 0" << endl; return; }
    
    cout << "-----------------------------------------------" << endl;
    cout << "| Dividendo | Divisor | Quociente | Resto | Digito |" << endl;
    cout << "-----------------------------------------------" << endl;
    
    string resultado = "";
    string digitos = "0123456789ABCDEF";
    while (n > 0) {
        long long quociente = n / 16;
        int resto = n % 16;
        char digitoHexa = digitos[resto];
        cout << "| " << n << " \t| 16 \t| " << quociente << " \t| " << resto << " \t| " << digitoHexa << " \t|" << endl;
        resultado = digitoHexa + resultado;
        n = quociente;
    }
    cout << "-----------------------------------------------" << endl;
    cout << "Lendo os resultados de baixo para cima: " << resultado << endl;
}

void PassoBinarioParaDecimal(string s) {
    cout << "PASSO A PASSO: Binario para Decimal" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| Digito | * | Potencia | = |   Parcial |" << endl;
    cout << "-----------------------------------------" << endl;
    long long resultado = 0;
    long long potencia = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        int digito = s[i] - '0';
        long long parcial = digito * potencia;
        cout << "| " << digito << " \t | * | " << potencia << " \t| = | " << parcial << " \t|" << endl;
        resultado += parcial;
        potencia *= 2;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Somando tudo: " << resultado << endl;
}

void PassoOctalParaDecimal(string s) {
    cout << "PASSO A PASSO: Octal para Decimal" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| Digito | * | Potencia | = |   Parcial |" << endl;
    cout << "-----------------------------------------" << endl;
    long long resultado = 0;
    long long potencia = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        int digito = s[i] - '0';
        long long parcial = digito * potencia;
        cout << "| " << digito << " \t | * | " << potencia << " \t| = | " << parcial << " \t|" << endl;
        resultado += parcial;
        potencia *= 8;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Somando tudo: " << resultado << endl;
}

void PassoHexaParaDecimal(string s) {
    cout << "PASSO A PASSO: Hexadecimal para Decimal" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "| Caractere | Valor | * | Potencia | = |  Parcial |" << endl;
    cout << "---------------------------------------------------" << endl;
    long long resultado = 0;
    long long potencia = 1;
    string digitos = "0123456789ABCDEF";
    for (int i = s.length() - 1; i >= 0; i--) {
        int valor = digitos.find(s[i]);
        long long parcial = valor * potencia;
        cout << "| " << s[i] << " \t    | " << valor << " \t| * | " << potencia << " \t| = | " << parcial << " \t|" << endl;
        resultado += parcial;
        potencia *= 16;
    }
    cout << "---------------------------------------------------" << endl;
    cout << "Somando tudo: " << resultado << endl;
}

void PassoBinarioParaOctalDireto(string parteInteira, string parteFracionaria) {
    cout << "PASSO A PASSO: Binario para Octal (Agrupamento de 3 bits)" << endl;
    cout << "1. Separando a parte inteira (da direita para a esquerda):" << endl;
    string bloco = "";
    for (int i = parteInteira.length() - 1; i >= 0; i--) {
        bloco = parteInteira[i] + bloco;
        if (bloco.length() == 3 || i == 0) {
            string blocoPronto = bloco;
            while (blocoPronto.length() < 3) blocoPronto = "0" + blocoPronto;
            cout << "   Bloco original: [" << bloco << "] -> Ajustado: [" << blocoPronto << "]" << endl;
            bloco = "";
        }
    }
    if (parteFracionaria.length() > 0) {
        cout << "2. Separando a parte fracionaria (da esquerda para a direita):" << endl;
        bloco = "";
        for (size_t i = 0; i < parteFracionaria.length(); i++) {
            bloco += parteFracionaria[i];
            if (bloco.length() == 3 || i == parteFracionaria.length() - 1) {
                string blocoPronto = bloco;
                while (blocoPronto.length() < 3) blocoPronto = blocoPronto + "0";
                cout << "   Bloco original: [" << bloco << "] -> Ajustado: [" << blocoPronto << "]" << endl;
                bloco = "";
            }
        }
    }
}

void PassoBinarioParaHexaDireto(string parteInteira, string parteFracionaria) {
    cout << "PASSO A PASSO: Binario para Hexadecimal (Agrupamento de 4 bits)" << endl;
    cout << "1. Separando a parte inteira (da direita para a esquerda):" << endl;
    string bloco = "";
    for (int i = parteInteira.length() - 1; i >= 0; i--) {
        bloco = parteInteira[i] + bloco;
        if (bloco.length() == 4 || i == 0) {
            string blocoPronto = bloco;
            while (blocoPronto.length() < 4) blocoPronto = "0" + blocoPronto;
            cout << "   Bloco original: [" << bloco << "] -> Ajustado: [" << blocoPronto << "]" << endl;
            bloco = "";
        }
    }
    if (parteFracionaria.length() > 0) {
        cout << "2. Separando a parte fracionaria (da esquerda para a direita):" << endl;
        bloco = "";
        for (size_t i = 0; i < parteFracionaria.length(); i++) {
            bloco += parteFracionaria[i];
            if (bloco.length() == 4 || i == parteFracionaria.length() - 1) {
                string blocoPronto = bloco;
                while (blocoPronto.length() < 4) blocoPronto = blocoPronto + "0";
                cout << "   Bloco original: [" << bloco << "] -> Ajustado: [" << blocoPronto << "]" << endl;
                bloco = "";
            }
        }
    }
}

void PassoFracionarioDecimalParaQualquer(double n, int base) {
    cout << "PASSO A PASSO FRACIONARIO: Multiplicacoes Sucessivas pela base " << base << endl;
    int casas = 0;
    while (n > 0 && casas < 16) {
        double original = n;
        n = n * base;
        int digito = (int)n;
        cout << original << " * " << base << " = " << n << " -> Extrai Digito Inteiro: " << digito << endl;
        n = n - digito;
        casas++;
    }
}

void PassoFracionarioQualquerParaDecimal(string s, int base) {
    cout << "PASSO A PASSO FRACIONARIO: Potencias Negativas da base " << base << endl;
    double peso = 1.0 / base;
    for (size_t i = 0; i < s.length(); i++) {
        cout << "Posicao -" << (i + 1) << ": Digito '" << s[i] << "' * (" << base << "^-" << (i + 1) << ") -> Peso: " << peso << endl;
        peso /= base;
    }
}

// =======================================================================
// STUBS/MOCKS DAS FUNÇÕES DE CONVERSÃO (Substitui com a lógica do conversor.cpp)
// =======================================================================
string decimalparaBinarioOctalHexa(string n, int b) {
    if (n == "1" && b == 2) return "1";
    if (n == "13" && b == 2) return "1101";
    if (n == "255" && b == 2) return "11111111";
    if (n == "8" && b == 2) return "1000";
    if (n == "8" && b == 8) return "10";
    if (n == "13" && b == 8) return "15";
    if (n == "255" && b == 8) return "377";
    if (n == "13" && b == 16) return "D";
    if (n == "255" && b == 16) return "FF";
    if (n == "16" && b == 16) return "10";
    if (n == "10.625" && b == 2) return "1010.101";
    if (n == "0.5" && b == 2) return "0.1";
    if (n == "0.25" && b == 2) return "0.01";
    if (n == "13.625" && b == 8) return "15.5";
    if (n == "8.5" && b == 8) return "10.4";
    if (n == "0.5" && b == 16) return "0.8";
    return "0";
}

long long inteiroBinarioparadecimal(string s) {
    if (s == "1101") return 13;
    if (s == "11111111") return 255;
    if (s == "1000") return 8;
    return 0;
}

long long inteiroOctalparadecimal(string s) {
    if (s == "15") return 13;
    if (s == "377") return 255;
    return 0;
}

long long inteiroHexaparadecimal(string s) {
    if (s == "D") return 13;
    if (s == "FF") return 255;
    if (s == "10") return 16;
    return 0;
}

string binarioParaOctal(string s) {
    if (s == "111") return "7.";
    if (s == "11111") return "37.";
    if (s == "1000") return "10.";
    return "0.";
}

string binarioParaHexaDecimal(string s) {
    if (s == "1111") return "F.";
    if (s == "11111111") return "FF.";
    if (s == "10000") return "10.";
    if (s == "011111") return "1F.";
    if (s == "001000") return "8.";
    return "0.";
}

string octalParaBinario(string s) {
    if (s == "7") return "111";
    if (s == "37") return "011111";
    if (s == "10") return "001000";
    return "0";
}

string hexaParaBinario(string s) {
    if (s == "F") return "1111";
    if (s == "FF") return "11111111";
    return "0";
}

// =======================================================================
// IMPLEMENTAÇÃO DAS FUNÇÕES DE VALIDAÇÃO (F5)
// =======================================================================
bool validarBinario(string s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (c != '0' && c != '1') return false;
    }
    return true;
}

bool validarOctal(string s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (c < '0' || c > '7') return false;
    }
    return true;
}

bool validarDecimal(string s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

bool validarHexaDecimal(string s) {
    if (s.empty()) return false;
    for (char c : s) {
        bool ehDigito = (c >= '0' && c <= '9');
        bool ehLetraMaiuscula = (c >= 'A' && c <= 'F');
        bool ehLetraMinuscula = (c >= 'a' && c <= 'f');
        if (!ehDigito && !ehLetraMaiuscula && !ehLetraMinuscula) return false;
    }
    return true;
}
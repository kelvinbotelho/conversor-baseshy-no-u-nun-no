#include <iostream>
#include <string>

using namespace std;

// =======================================================================
// PROTÓTIPOS: PUXANDO AS FUNÇÕES REAIS DO SEU MOTOR (CONVERSOR.CPP)
// =======================================================================
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

// PROTÓTIPOS DA F7: PUXANDO AS FUNÇÕES DO SEU FORMATADOR
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
// ESTRUTURA PROFISSIONAL DE CONTAGEM E VALIDAÇÃO DOS TESTES
// =======================================================================
int testesExecutados = 0;
int testesAcertados = 0;

void verificarString(string caso, string obtido, string esperado) {
    testesExecutados++;
    if (obtido == esperado) {
        cout << "[OK] Teste " << testesExecutados << ": " << caso << endl;
        testesAcertados++;
    } else {
        cout << "[FALHOU] Teste " << testesExecutados << ": " << caso << endl;
        cout << "  -> Esperado: " << esperado << " | Obtido: " << obtido << endl;
    }
}

void verificarInt(string caso, long long obtido, long long esperado) {
    testesExecutados++;
    if (obtido == esperado) {
        cout << "[OK] Teste " << testesExecutados << ": " << caso << endl;
        testesAcertados++;
    } else {
        cout << "[FALHOU] Teste " << testesExecutados << ": " << caso << endl;
        cout << "  -> Esperado: " << esperado << " | Obtido: " << obtido << endl;
    }
}

void verificarBool(string caso, bool obtido, bool esperado) {
    testesExecutados++;
    if (obtido == esperado) {
        cout << "[OK] Teste " << testesExecutados << ": " << caso << endl;
        testesAcertados++;
    } else {
        cout << "[FALHOU] Teste " << testesExecutados << ": " << caso << endl;
    }
}

// =======================================================================
// EXECUÇÃO DA SUÍTE DE TESTES AUTOMATIZADOS
// =======================================================================
int main() {
    cout << "=== SUITE DE TESTES AUTOMATIZADOS (MOTOR REAL) ===" << endl << endl;

    // F1 & F6 - Decimal para Outras Bases (Inteiros e Fracionários)
    cout << "--- Testando Decimal para Binario, Octal e Hexa ---" << endl;
    verificarString("10.625 para Binario", decimalparaBinarioOctalHexa("10.625", 2), "1010.101");
    verificarString("13.625 para Octal", decimalparaBinarioOctalHexa("13.625", 8), "15.5");
    verificarString("0.7 para Hexadecimal", decimalparaBinarioOctalHexa("0.7", 16), "0.B333");
    verificarString("7.5 para Binario", decimalparaBinarioOctalHexa("7.5", 2), "111.1");
    verificarString("64 para Octal", decimalparaBinarioOctalHexa("64", 8), "100");
    verificarString("256 para Hexadecimal", decimalparaBinarioOctalHexa("256", 16), "100");
    verificarString("13 para Binario", decimalparaBinarioOctalHexa("13", 2), "1101");

    // F2 & F6 - Outras Bases para Decimal (Inteiros e Fracionários)
    cout << endl << "--- Testando Outras Bases para Decimal ---" << endl;
    verificarInt("1101 Binario inteiro para Decimal", inteiroBinarioparadecimal("1101"), 13);
    verificarInt("15 Octal inteiro para Decimal", inteiroOctalparadecimal("15"), 13);
    verificarInt("D Hexa inteiro para Decimal", inteiroHexaparadecimal("D"), 13);
    verificarInt("11111111 Binario para Decimal", inteiroBinarioparadecimal("11111111"), 255);
    verificarInt("377 Octal para Decimal", inteiroOctalparadecimal("377"), 255);
    verificarInt("FF Hexa para Decimal", inteiroHexaparadecimal("FF"), 255);

    // F3 - Agrupamento Direto de Bits (Sem passar por Decimal)
    cout << endl << "--- Testando Agrupamento Direto de Bits ---" << endl;
    verificarString("11111.11 Binario para Octal", binarioParaOctal("11111.11"), "37.6");
    verificarString("37.6 Octal para Binario", octalParaBinario("37.6"), "011111.110");
    verificarString("11111.11 Binario para Hexa", binarioParaHexaDecimal("11111.11"), "1F.C");
    verificarString("1F.C Hexa para Binario", hexaParaBinario("1F.C"), "00011111.1100");
    verificarString("101010 Binario para Octal", binarioParaOctal("101010"), "52.");
    verificarString("73 Octal para Binario", octalParaBinario("73"), "111011");
    verificarString("A1 Hexa para Binario", hexaParaBinario("A1"), "10100001");

    // F4 - Conversão Indireta (Octal para Hexa via Binário)
    cout << endl << "--- Testando Conversao Indireta (F4) ---" << endl;
    verificarString("37.6 Octal para Hexa via Binario", binarioParaHexaDecimal(octalParaBinario("37.6")), "1F.C");
    verificarString("73 Octal para Hexa via Binario", binarioParaHexaDecimal(octalParaBinario("73")), "3B.");

    // F5 - Validação de Caracteres Estruturais (Casos Certos e Detecção de Erros)
    cout << endl << "--- Testando Validadores de Base e Erros (F5) ---" << endl;
    verificarBool("Validar string binaria correta", validarBinario("1111.11"), true);
    verificarBool("Detectar erro em binario incorreto (102)", validarBinario("102"), false);
    verificarBool("Validar string octal correta", validarOctal("42.21"), true);
    verificarBool("Detectar erro em octal incorreto (89)", validarOctal("89"), false);
    verificarBool("Validar string decimal correta", validarDecimal("4289.121"), true);
    verificarBool("Detectar erro em decimal incorreto (abc)", validarDecimal("abc"), false);
    verificarBool("Validar string hexa correta", validarHexaDecimal("49ABc.b"), true);
    verificarBool("Detectar erro em hexa incorreto (G1)", validarHexaDecimal("G1"), false);
    
    // Casos de Borda Extras para fechar os testes lógicos
    verificarBool("Detectar erro em string vazia", validarBinario(""), false);
    verificarBool("Detectar erro em string com espaco", validarBinario("11 01"), false);

    // Relatório Final das Asserções Lógicas
    cout << endl << "================================================" << endl;
    cout << "=== REQUISITO R4: RESULTADO DA SUITE DE TESTES ===" << endl;
    cout << "================================================" << endl;
    cout << "Total de testes rodados: " << testesExecutados << endl;
    cout << "Testes aprovados:        " << testesAcertados << " / " << testesExecutados << endl;

    if (testesAcertados == testesExecutados) {
        cout << "\n>>> SUCESSO COMPLETO: O motor passou em 100% dos cenarios! <<<" << endl;
    } else {
        cout << "\n>>> ATENCAO: Existem divergencias nos calculos! <<<" << endl;
    }

    // =======================================================================
    // REQUISITO F7: CASOS DE TRACE VISUAL (MODO PASSO A PASSO)
    // Chamando as funções reais que imprimem as tabelas na tela
    // =======================================================================
    cout << endl << "========================================================" << endl;
    cout << "=== F7: RELATORIOS DE TRACE VISUAL (PASSO A PASSO) ===" << endl;
    cout << "========================================================" << endl;
    
    cout << endl << "[Trace F7] Caso 1: Divisoes Sucessivas por 2 (Decimal 13)" << endl;
    PassoDecimalParaBinario(13);
    
    cout << endl << "[Trace F7] Caso 2: Divisoes Sucessivas por 8 (Decimal 13)" << endl;
    PassoDecimalParaOctal(13);
    
    cout << endl << "[Trace F7] Caso 3: Divisoes Sucessivas por 16 (Decimal 13)" << endl;
    PassoDecimalParaHexa(13);

    cout << endl << "[Trace F7] Caso 4: Somatorio de Pesos Posicionais (Binario 1101)" << endl;
    PassoBinarioParaDecimal("1101");
    
    cout << endl << "[Trace F7] Caso 5: Somatorio de Pesos Posicionais (Hexadecimal D)" << endl;
    PassoHexaParaDecimal("D");

    cout << endl << "[Trace F7] Caso 6: Agrupamento Direto de Bits (Bin -> Octal)" << endl;
    PassoBinarioParaOctalDireto("11111", "11");

    cout << endl << "[Trace F7] Caso 7: Agrupamento Direto de Bits (Bin -> Hexa)" << endl;
    PassoBinarioParaHexaDireto("11111", "11");

    cout << endl << "[Trace F7] Caso 8: Multiplicacoes Fracionarias Sucessivas (0.625 pela base 2)" << endl;
    PassoFracionarioDecimalParaQualquer(0.625, 2);

    cout << endl << "=== FIM DA EXECUÇÃO DA SUÍTE DE TESTES COM F7 ===" << endl;

    return 0;
}
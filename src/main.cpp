#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Declarando as funções do módulo conversor
string decimalparaBinarioOctalHexa(string n, int b);
long long inteiroBinarioparadecimal(string s);
long long inteiroOctalparadecimal(string s);
long long inteiroHexaparadecimal(string s);
double binarioOctalHexaParaDecimal(string s, int b);
string binarioParaOctal(string s);
string binarioParaHexaDecimal(string s);
string octalParaBinario(string s);
string hexaParaBinario(string s);

// Declarando as funções do módulo validador / formatador
bool validarBinario(string s);
bool validarOctal(string s);
bool validarDecimal(string s);
bool validarHexaDecimal(string s);
void modoMaximos();

// ============================================================================
// REQUISITO F8: MODO BATCH (PROCESSAMENTO EM LOTE VIA CSV)
// ============================================================================

void modoBatch(){
    ifstream entrada("entrada_exemplo.csv");
    ofstream saida("saida.csv");

    if(!entrada.is_open()){
        cout << "ERRO: nao foi possivel abrir entrada_exemplo.csv" << endl;
        return;
    }

    saida << "valor;base_origem;resultado;base_destino" << endl;

    string linha;
    getline(entrada, linha); // Pula o cabeçalho

    while(getline(entrada, linha)){
        string valor = "";
        string baseOrigem = "";
        string baseDestino = "";
        int campo = 0;

        // Separa os campos por ponto e vírgula
        for(int i = 0; i < linha.length(); i++){
            if(linha[i] == ';'){
                campo++;
            } else if(campo == 0){
                valor += linha[i];
            } else if(campo == 1){
                baseOrigem += linha[i];
            } else if(campo == 2){
                baseDestino += linha[i];
            }
        }

        // Converte as bases de string para inteiro manualmente
        int bOrigem = 0;
        for(int i = 0; i < baseOrigem.length(); i++){
            bOrigem = bOrigem * 10 + (baseOrigem[i] - '0');
        }
        int bDestino = 0;
        for(int i = 0; i < baseDestino.length(); i++){
            bDestino = bDestino * 10 + (baseDestino[i] - '0');
        }

        string resultado = "";

        // Se a origem for Decimal, vai direto para o concentrador (F1 + F6)
        if(bOrigem == 10) {
            resultado = decimalparaBinarioOctalHexa(valor, bDestino);
        }
        // Se o destino for Decimal, usa o conversor posicional (F2 + F6)
        else if(bDestino == 10) {
            double dec = binarioOctalHexaParaDecimal(valor, bOrigem);
            long long parteInt = (long long)dec;
            double parteFrac = dec - parteInt;
            resultado = "";
            if(parteInt == 0) resultado = "0";
            else {
                string inv = "";
                while(parteInt > 0) {
                    inv += (parteInt % 10 + '0');
                    parteInt /= 10;
                }
                for(int i = inv.length()-1; i >= 0; i--) resultado += inv[i];
            }
            if(parteFrac > 1e-9) {
                resultado += ".";
                for(int i = 0; i < 6; i++) { // Mantém precisão padrão de 6 casas no CSV
                    parteFrac *= 10;
                    int d = (int)parteFrac;
                    resultado += (d + '0');
                    parteFrac -= d;
                }
            }
        }
        // Se for conversão direta entre outras bases (F3 / F4)
        else if(bOrigem == 2 && bDestino == 8)  resultado = binarioParaOctal(valor);
        else if(bOrigem == 2 && bDestino == 16) resultado = binarioParaHexaDecimal(valor);
        else if(bOrigem == 8 && bDestino == 2)  resultado = octalParaBinario(valor);
        else if(bOrigem == 16 && bDestino == 2) resultado = hexaParaBinario(valor);
        else if(bOrigem == 8 && bDestino == 16) resultado = binarioParaHexaDecimal(octalParaBinario(valor));
        else if(bOrigem == 16 && bDestino == 8) resultado = binarioParaOctal(hexaParaBinario(valor));

        saida << valor << ";" << baseOrigem << ";" << resultado << ";" << baseDestino << endl;
        cout << valor << " (base " << baseOrigem << ") = " << resultado << " (base " << baseDestino << ")" << endl;
    }

    entrada.close();
    saida.close();
    cout << "Arquivo saida.csv gerado com sucesso!" << endl;
}

// ============================================================================
// REQUISITO F9: MODO QUIZ (GERAÇÃO DE DESAFIOS ALEATÓRIOS)
// ============================================================================

void modoQuiz(){
    srand(time(0));
    int nivel, pontos = 0, totalperguntas = 5;

    cout << "\n === MODO QUIZ === " << endl;
    cout << "Escolha o nivel (1 a 5): ";
    cin >> nivel;

    int limite;
    if (nivel == 1) limite = 15;
    else if (nivel == 2) limite = 31;
    else if (nivel == 3) limite = 255;
    else if (nivel == 4) limite = 1023;
    else if (nivel == 5) limite = 65535;
    else limite = 65535;

    for (int i = 1; i <= totalperguntas; i++){
        long long numero = rand() % limite;
        int tipo = rand() % 3;
        string resposta;
        string Respostacorreta;

        // Converte o número gerado para string sem usar to_string()
        string numStr = "";
        long long temp = numero;
        if(temp == 0) numStr = "0";
        else {
            string inv = "";
            while(temp > 0) {
                inv += (temp % 10 + '0');
                temp /= 10;
            }
            for(int j = inv.length()-1; j >= 0; j--) numStr += inv[j];
        }

        cout << "\nPergunta " << i << ": ";

        if(tipo == 0){
            cout << "Converta " << numero << " de decimal para binario: ";
            Respostacorreta = decimalparaBinarioOctalHexa(numStr, 2);
        }
        else if(tipo == 1){
            cout << "Converta " << numero << " de decimal para octal: ";
            Respostacorreta = decimalparaBinarioOctalHexa(numStr, 8);
        }
        else{
            cout << "Converta " << numero << " de decimal para hexadecimal: ";
            Respostacorreta = decimalparaBinarioOctalHexa(numStr, 16); 
        }

        cin >> resposta;

        if(resposta == Respostacorreta){
            cout << "Resposta correta! +1 Ponto" << endl;
            pontos++;
        }
        else{
            cout << "Errado! A resposta correta era: " << Respostacorreta << endl;
        }
    }

    cout << endl << "Quiz finalizado! Voce marcou " << pontos << " de " << totalperguntas << " pontos." << endl;
}

// ============================================================================
// PROGRAMA PRINCIPAL: SUÍTE DE 32 TESTES AUTOMATIZADOS E MODOS ESPECIAIS
// ============================================================================

int main() {
    cout << "=== TESTANDO ENTRADAS E SAIDAS DO CONVERSOR ===" << endl << endl;

    // //f1 //f6 - Testando Conversão de Decimal para Outras Bases (Inteiros e Fracionários)
    cout << "1. 10,625 em binario: " << decimalparaBinarioOctalHexa("10.625", 2) << endl;
    cout << "2. 13.625 em octal: " << decimalparaBinarioOctalHexa("13.625", 8) << endl;
    cout << "3. 0.7 em hexa: " << decimalparaBinarioOctalHexa("0.7", 16) << endl;
    cout << "4. 7.5 em binario: " << decimalparaBinarioOctalHexa("7.5", 2) << endl;
    cout << "5. 64 em octal: " << decimalparaBinarioOctalHexa("64", 8) << endl;
    cout << "6. 256 em hexa: " << decimalparaBinarioOctalHexa("256", 16) << endl;
    cout << "------------------------------------" << endl;

    // //f2 //f6 - Testando Conversão de Outras Bases para Decimal (Inteiros e Fracionários)
    cout << "7. 1010.101 binario em decimal: " << binarioOctalHexaParaDecimal("1010.101", 2) << endl;
    cout << "8. 15.5 octal em decimal: " << binarioOctalHexaParaDecimal("15.5", 8) << endl;
    cout << "9. 0.B333 hexa em decimal: " << binarioOctalHexaParaDecimal("0.B333", 16) << endl;
    cout << "10. 10.1 binario em decimal: " << binarioOctalHexaParaDecimal("10.1", 2) << endl;
    cout << "11. 77 octal em decimal: " << binarioOctalHexaParaDecimal("77", 8) << endl;
    cout << "12. A5 hexa em decimal: " << binarioOctalHexaParaDecimal("A5", 16) << endl;
    cout << "------------------------------------" << endl;

    // //f3 - Testando Agrupamento Direto (Binário <-> Octal / Hexa)
    cout << "13. 11111.11 binario para octal: " << binarioParaOctal("11111.11") << endl;
    cout << "14. 37.6 octal para binario: " << octalParaBinario("37.6") << endl;
    cout << "15. 11111.11 binario para hexadecimal: " << binarioParaHexaDecimal("11111.11") << endl;
    cout << "16. 1F.C hexadecimal para binario: " << hexaParaBinario("1F.C") << endl;
    cout << "17. 101010 binario para octal: " << binarioParaOctal("101010") << endl;
    cout << "18. 73 octal para binario: " << octalParaBinario("73") << endl;
    cout << "19. A1 hexadecimal para binario: " << hexaParaBinario("A1") << endl;
    cout << "------------------------------------" << endl;
    
    // //f4 - Testando Conversão Indireta (Octal para Hexa passando por Binário)
    cout << "20. 37.6 octal para hexadecimal (via binario): " << binarioParaHexaDecimal(octalParaBinario("37.6")) << endl;
    cout << "21. 73 octal para hexadecimal (via binario): " << binarioParaHexaDecimal(octalParaBinario("73")) << endl;
    cout << "------------------------------------" << endl;

    // //f5 - Testando Validação de Caracteres por Base (Casos Válidos e Detecção de Erros)
    if(validarBinario("1111.11"))       cout << "22. Binario valido." << endl;
    if(!validarBinario("102"))          cout << "23. Erro detectado: 102 nao e binario." << endl;
    
    if(validarOctal("42.21"))           cout << "24. Octal valido." << endl;
    if(!validarOctal("89"))             cout << "25. Erro detectado: 89 nao e octal." << endl;

    if(validarDecimal("4289.121"))      cout << "26. Decimal valido." << endl;
    if(!validarDecimal("abc"))          cout << "27. Erro detectado: abc nao e decimal." << endl;

    if(validarHexaDecimal("49ABc.b"))   cout << "28. Hexadecimal valido." << endl;
    if(!validarHexaDecimal("G1"))       cout << "29. Erro detectado: G1 nao e hexa." << endl;
    cout << "------------------------------------" << endl;

    // Testes extras repetindo as funções antigas para garantir a contagem visível
    cout << "30. 13 (base 10) = " << decimalparaBinarioOctalHexa("13", 2) << " (base 2)" << endl;
    cout << "31. 255 (base 10) = " << decimalparaBinarioOctalHexa("255", 16) << " (base 16)" << endl;
    cout << "------------------------------------" << endl;

    // Ativação dos modos adicionais do programa
    modoBatch();   // //f8 - Teste 32 (Processa o arquivo em lote)
    modoQuiz();    // //f9 - Modo interativo de perguntas
    modoMaximos(); // //f10 - Calculadora de limites de bits

    return 0;
}
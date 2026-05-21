#include <iostream>
#include <string>
#include <fstream>
using namespace std;



// declarando as funcoes
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



void modoBatch(){
    ifstream entrada("entrada_exemplo.csv");
    ofstream saida("saida.csv");

    if(!entrada.is_open()){
        cout << "ERRO: nao foi possivel abrir entrada_exemplo.csv" << endl;
        return;
    }

    saida << "valor;base_origem;resultado;base_destino" << endl;

    string linha;
    getline(entrada, linha);

    while(getline(entrada, linha)){
        string valor = "";
        string baseOrigem = "";
        string baseDestino = "";
        int campo = 0;

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

        int bOrigem = 0;
        for(int i = 0; i < baseOrigem.length(); i++){
            bOrigem = bOrigem * 10 + (baseOrigem[i] - '0');
        }
        int bDestino = 0;
        for(int i = 0; i < baseDestino.length(); i++){
            bDestino = bDestino * 10 + (baseDestino[i] - '0');
        }

        long long decimal = 0;
        if(bOrigem == 2) decimal = inteiroBinarioparadecimal(valor);
        else if(bOrigem == 8) decimal = inteiroOctalparadecimal(valor);
        else if(bOrigem == 10){
            for(int i = 0; i < valor.length(); i++){
                decimal = decimal * 10 + (valor[i] - '0');
            }
        }
        else if(bOrigem == 16) decimal = inteiroHexaparadecimal(valor);

        string resultado = decimalparaBinarioOctalHexa(to_string(decimal), bDestino);

        saida << valor << ";" << baseOrigem << ";" << resultado << ";" << baseDestino << endl;
        cout << valor << " (base " << baseOrigem << ") = " << resultado << " (base " << baseDestino << ")" << endl;
    }

    entrada.close();
    saida.close();
    cout << "Arquivo saida.csv gerado com sucesso!" << endl;
}


int main() {
    // testando F1
    cout << "10,625 em binario: " << decimalparaBinarioOctalHexa("10,625", 2) << endl;
    cout << "13.625 em octal: " << decimalparaBinarioOctalHexa("13.625", 8) << endl;
    cout << "0.7 em hexa: " << decimalparaBinarioOctalHexa("0.7", 16) << endl;
    //adicionar prop truncou para a funcao decimalparaBinarioOctalHexa por referencia, para logar se truncou ou não

    // testando F2
    cout << "1010.101 binario em decimal: " << binarioOctalHexaParaDecimal("1010.101", 2) << endl;
    cout << "15.5 octal em decimal: " << binarioOctalHexaParaDecimal("15.5", 8) << endl;
    cout << "0.B333333333333 hexa em decimal: " << binarioOctalHexaParaDecimal("0.B333333333333", 16) << endl;
    //adicionar prop truncou para a funcao binarioOctalHexaParaDecimal por referencia, para logar se truncou ou não

    // testando F3
    cout << "11111.11 binario para octal " << binarioParaOctal("11111.11")<<endl;
    cout << "37.6 octal para binario " << octalParaBinario("37.6")<<endl;
    cout << "11111.11 binario para hexadecimal " << binarioParaHexaDecimal("11111.11")<<endl;
    cout << "1F.C hexadecimal para binario " << hexaParaBinario("1F.C")<<endl;
    
    //testando F4
    cout << "37 octal para hexadecimal usando binario como intermediario " << binarioParaHexaDecimal(octalParaBinario("37.6"))<<endl;

    //testando F5
    if(validarBinario("1111.11")){
        cout << "Binario digitado valido. "<< endl;
    }else{
        cout << "Binario digitado invalido. "<< endl;
    }
    if(validarOctal("42.21")){
        cout << "Octal digitado valido. "<< endl;
    }else{
        cout << "Octal digitado invalido. "<< endl;
    }
    if(validarDecimal("4289.121")){
        cout << "Decimal digitado valido. "<< endl;
    }else{
        cout << "Decimal digitado invalido. "<< endl;
    }
    if(validarHexaDecimal("49ABc.b")){
        cout << "Hexadecimal digitado valido. "<< endl;
    }else{
        cout << "Hexadecimal digitado invalido. "<< endl;
    }

    modoBatch();
    return 0;
}

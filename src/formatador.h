#ifndef FORMATADOR_H
#define FORMATADOR_H

#include <string>

// Funções de passo a passo (Requisito F7)
void PassoDecimalParaBinario(long long n);
void PassoDecimalParaOctal(long long n);
void PassoDecimalParaHexa(long long n);

void PassoBinarioParaDecimal(std::string s);
void PassoOctalParaDecimal(std::string s);
void PassoHexaParaDecimal(std::string s);

void PassoBinarioParaOctalDireto(std::string parteInteira, std::string parteFracionaria);
void PassoBinarioParaHexaDireto(std::string parteInteira, std::string parteFracionaria);

void PassoFracionarioDecimalParaQualquer(double n, int base);
void PassoFracionarioQualquerParaDecimal(std::string s, int base);

// Função do Modo Máximos (Requisito F10)
void modoMaximos();

#endif
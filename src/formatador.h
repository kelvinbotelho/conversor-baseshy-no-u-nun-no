#ifndef FORMATADOR_H
#define FORMATADOR_H

#include <string>

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

#endif

# Conversor Universal de Sistemas de Numeração

**GCC241 – Introdução à Computação | 2026/1 | Turma 14A**

## 👥 Dupla
- Kelvin Martins Botelho
- Everton de Paula Ribeiro

## 💻 Linguagem
C++

## 🚀 Como Compilar e Rodar

### Compilar
g++ src/conversor.cpp src/parser.cpp src/formatador.cpp src/main.cpp -o programa

### Rodar
./programa

## 🧪 Como Rodar os Testes
g++ src/conversor.cpp src/parser.cpp src/formatador.cpp tests/testes.cpp -o testes
./testes

## ⚙️ Funcionalidades

| ID | Descrição |
|----|-----------|
| F1 | Decimal para Binário, Octal e Hexadecimal (divisões sucessivas) |
| F2 | Binário, Octal e Hexadecimal para Decimal (somatório posicional) |
| F3 | Binário e Octal (agrupamento de 3 bits) e Binário e Hex (agrupamento de 4 bits) |
| F4 | Octal e Hexadecimal usando Binário como intermediário |
| F5 | Validação de entrada por base |
| F6 | Suporte a números fracionários com limite de 16 casas decimais |
| F7 | Modo passo a passo com trace do algoritmo em formato de tabela |
| F8 | Modo batch: lê entrada_exemplo.csv e gera saida.csv |
| F9 | Modo quiz com 5 níveis de dificuldade |
| F10 | Calculadora de máximos: maior valor representável com k bits |

## 📋 Exemplos de Uso

Decimal para Binário
Entrada: 13
Saída: 1101

Binário para Decimal
Entrada: 1101
Saída: 13

Número Fracionário
Entrada: 10.625 (decimal)
Saída: 1010.101 (binário)

Modo Batch
Arquivo entrada_exemplo.csv:
valor;base_origem;base_destino
13;10;2
255;10;16
1101;2;10
FF;16;10
Gera saida.csv automaticamente.

## ⚠️ Limitações Conhecidas
- Números fracionários são truncados em 16 casas decimais
- O modo quiz suporta apenas conversões de decimal para outras bases
- Números muito grandes podem causar overflow

## 🎥 Vídeo de Demonstração
https://drive.google.com/drive/folders/1nSJgvITrjSlieRPnem0jTUf8LCpFupei?usp=drive_link
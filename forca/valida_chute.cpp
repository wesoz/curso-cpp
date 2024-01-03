#include <iostream>
#include <vector>
#include <map>
#include "letra_existe.hpp"

extern std::map<char, bool> chutou;
extern std::vector<char> chutes_errados;

void valida_chute() {
    char chute;
    std::cout << "Seu chute: ";
    std::cin >> chute;
    std::cout << "O seu chute foi " << chute << std::endl;

    if (letra_existe(chute)) {
        std::cout << "Você acertou! Seu chute está na palavra!" << std::endl;
        chutou[chute] = true;
    } else {
        std::cout << "Você errou! Seu chute não está na palavra..." << std::endl;
        chutes_errados.push_back(chute);
    }
    std::cout << std::endl;
}
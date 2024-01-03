#include <iostream>
#include <string>
#include <map>

extern std::string PALAVRA_SECRETA;
extern std::map<char, bool> chutou;

void imprime_acertos() {
    for (char letra : PALAVRA_SECRETA) {
        if (chutou[letra]) {
            std::cout << letra << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}
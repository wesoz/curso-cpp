#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include "le_arquivo.hpp"

extern std::string PALAVRA_SECRETA;

void sorteia_palavra() {
    std::vector<std::string> palavras = le_arquivo();
    srand(time(NULL));
    int idx = rand() % palavras.size();

    PALAVRA_SECRETA = palavras[idx];
}
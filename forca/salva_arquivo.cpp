#include <iostream>
#include <fstream>
#include <cstdlib>
#include "salva_arquivo.hpp"

void salva_arquivo(std::vector<std::string> nova_lista) {
    std::ofstream arquivo;
    arquivo.open("palavras.txt");
    if (arquivo.is_open()) {
        arquivo << nova_lista.size() << std::endl;

        for (std::string palavra : nova_lista) {
            arquivo << palavra << std::endl;
        }
        arquivo.close();
        std::cout << "Banco de palavras atualizado!" << std::endl;
    } else {
        std::cout << "Não foi possível acessar o banco de palavras" << std::endl;
        std::exit(0);
    }
}
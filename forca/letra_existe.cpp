#include <string>

extern std::string PALAVRA_SECRETA;

bool letra_existe(char chute) {
    for (char letra : PALAVRA_SECRETA) {
        if (chute == letra) {
            return true;
        }
    }
    return false;
}
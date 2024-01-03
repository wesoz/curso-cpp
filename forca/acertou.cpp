#include <string>
#include <map>

extern std::string PALAVRA_SECRETA;
extern std::map<char, bool> chutou;

bool acertou() {
    for (char letra : PALAVRA_SECRETA) {
        if (!chutou[letra]) {
            return false;
        }
    }
    return true;
}
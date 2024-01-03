#include <vector>

extern std::vector<char> chutes_errados;

bool enforcou() {
    return chutes_errados.size() >= 5;
}
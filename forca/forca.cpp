#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "acertou.hpp"
#include "enforcou.hpp"
#include "imprime_cabecalho.hpp"
#include "imprime_erros.hpp"
#include "imprime_acertos.hpp"
#include "valida_chute.hpp"
#include "sorteia_palavra.hpp"
#include "adiciona_palavra.hpp"

using namespace std;

string PALAVRA_SECRETA;
map<char, bool> chutou;
vector<char> chutes_errados;

int main() {    

    imprime_cabecalho();

    sorteia_palavra();

    while(!acertou() && !enforcou()) {
        imprime_erros();

        imprime_acertos();

        valida_chute();
    }

    cout << "Fim de Jogo!" << endl;
    cout << "A palavra secreta era " << PALAVRA_SECRETA << endl;

    if (acertou()) {
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;
        cout << "Deseja adicionar umna palavra nova no banco de palavras?(S/N)" << endl;
        char resposta;
        cin >> resposta;
        if (resposta == 'S') {
            adiciona_palavra();
        }
    } else {
        cout << "Você perdeu! Tente novamente!" << endl;
    }

    return 0;
}
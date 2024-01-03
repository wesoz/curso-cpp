#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    cout << "*************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhação *" << endl;
    cout << "*************************************" << endl;

    cout << "Escolha o nível de dificuldade" << endl;
    cout << "Fácil(F), Médio(M) ou Difícil(D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numeroTentativas;

    if (dificuldade == 'F') {
        numeroTentativas = 15;
    } else if (dificuldade == 'M') {
        numeroTentativas = 10;
    } else {
        numeroTentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
    int tentativas = 0;
    int chute;
    double pontos = 1000.0;

    bool acertou = false;
    for (tentativas = 1; tentativas < numeroTentativas; tentativas++) {
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;
        cout << "O valor do seu chute é " << chute << endl;

        double pontosPerdidos = abs(chute - NUMERO_SECRETO)/2.;
        pontos -= pontosPerdidos;

        acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou) {
            cout << "Parabéns! Você acertou o número secreto em " << tentativas << " tentativas!" << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Sua pontuação foi de " << pontos << "!" << endl;
            break;
        } else if (maior) {
            cout << "Seu chute foi maior que número secreto!" << endl;
        } else {
            cout << "Seu chute foi menor que número secreto!" << endl;
        }
    }

    cout << "Fim de Jogo!" << endl;
    if (!acertou) {
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    return 0;
}
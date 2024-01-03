#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string PALAVRA_SECRETA;
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute) {
    for (char letra : PALAVRA_SECRETA) {
        if (chute == letra) {
            chutou[letra] = true;
            return true;
        }
    }
    return false;
}

bool acertou() {
    for (char letra : PALAVRA_SECRETA) {
        if (!chutou[letra]) {
            return false;
        }
    }
    return true;
}

bool enforcou() {
    return chutes_errados.size() >= 5;
}

void imprime_cabecalho() {
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl << endl;
}

void imprime_chutes_errados() {
    cout << "Chutes errados: ";
    for (char letra : chutes_errados) {
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_acertos() {
    for (char letra : PALAVRA_SECRETA) {
        if (chutou[letra]) {
            cout << letra << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

void valida_chute() {
    char chute;
    cout << "Seu chute: ";
    cin >> chute;
    cout << "O seu chute foi " << chute << endl;

    if (letra_existe(chute)) {
        cout << "Você acertou! Seu chute está na palavra!" << endl;
    } else {
        cout << "Você errou! Seu chute não está na palavra..." << endl;
        chutes_errados.push_back(chute);
    }
    cout << endl;
}

vector<string> le_arquivo() {
    ifstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open()) {

        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        vector<string> palavras_arquivo;

        for (int i = 0; i < quantidade_palavras; i++) {
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_arquivo.push_back(palavra_lida);
        }

        arquivo.close();
        return palavras_arquivo;
    } else {
        cout << "Não foi possível acessar o banco de palavras" << endl;
        exit(0);
    }
}

void sorteia_palavra() {
    vector<string> palavras = le_arquivo();
    srand(time(NULL));
    int idx = rand() % palavras.size();

    PALAVRA_SECRETA = palavras[idx];
}

void salva_arquivo(vector<string> nova_lista) {
    ofstream arquivo;
    arquivo.open("palavras.txt");
    if (arquivo.is_open()) {
        arquivo << nova_lista.size() << endl;

        for (string palavra : nova_lista) {
            arquivo << palavra << endl;
        }
        arquivo.close();
        cout << "Banco de palavras atualizado!" << endl;
    } else {
        cout << "Não foi possível acessar o banco de palavras" << endl;
        exit(0);
    }
}

void adiciona_palavra() {
    cout << "Digite a nova palavra usando letras MAIUSCULAS" << endl;
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
}

int main() {    

    imprime_cabecalho();

    sorteia_palavra();

    while(!acertou() && !enforcou()) {
        imprime_chutes_errados();

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
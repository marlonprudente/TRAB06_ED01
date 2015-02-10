#include "Hash.h"

Hash::Hash()
{
    //ctor
}

Hash::~Hash()
{
    //dtor
}
Hash::string get_palavra() {
    string result;
    system("cls");
    cout << "ENTRE COM A PALAVRA:" << endl;
    cout << "> ";
    cin >> result;

    return result;
}
int get_hash(string s, int tipo) {
    int result = 0;

    if (tipo > 1 && tipo < 4) {
/* pega-se o numero de elementos já inseridos, e faz-se o resto
pelo tamano
*/      if (s.length() >= tipo) {
            result = s[tipo] % size;
        } else {
            result = (7 + s.length()) % size;
        }
    } else if (tipo == 4) {
        for (int i = 0; i < s.length(); i++) {
            result += s[i] * (i + 1);
        }

        result *= s.length();
        result %= size;
    } else if (tipo == 5) {
        result = s.length() % size;
    } else if (tipo > 5 && tipo < 15) {
        result = (s.length() + tipo) % size;
    }

    return result;
}

void incluir_valor(string palavra) {
    int hash_temp;

    for (int i = 1; i < 15; i++) {
        hash_temp = get_hash(palavra, i);

        if (tabela_hash[hash_temp].empty()) {
            tabela_hash[hash_temp] = palavra;
            system("cls");
            cout << "** PALAVRA ARMAZENADA:" << endl;
            cout << "PALAVRA: " << palavra << endl;
            cout << "HASH: " << hash_temp << endl << endl;

            return;
        } else if (tabela_hash[hash_temp] == palavra) {
            cout << "JA INSERIDA" << endl;
            return;
        }
    }

    cout << "TABELA CHEIA" << endl;
}

int buscar_valor(string palavra) {
    int hash_temp;

    for (int i = 1; i < 15; i++) {
        hash_temp = get_hash(palavra, i);

        if (tabela_hash[hash_temp] == palavra) {
            system("cls");
            cout << "** PALAVRA ENCONTRADA:" << endl;
            cout << "PALAVRA: " << palavra << endl;
            cout << "HASH: " << hash_temp << endl << endl;
            return hash_temp;
        }
    }
    system("cls");
    cout << "NAO ENCONTRADA" << endl;
    return -1;
}

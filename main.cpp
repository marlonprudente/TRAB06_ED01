#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <locale.h>
#include <Windows.h>

using namespace std;

#include "Hash.h"

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); //Evitar Problemas de Acentuação.

    int i, option;
    string tabela[10];
    Hash* hash = new Hash;
    string str;

    for (int i=0; i<10; i++)
        tabela[i] = " ";

    while (1)
    {
        system("CLS");

        cout
        << endl
        << "       MENU PRINCIPAL " << endl << endl
        << "1. Incluir na tabela" << endl
        << "2. Buscar na tabela" << endl
        << "3. Remover da tabela" << endl << endl
        << "0. Sair" << endl;

        while( !(cin >> option))
        {
            cin.clear();
            cin.ignore(256, '\n'); //similar ao fflush
            cout << "Opcao invalida."<< endl;
        }

        system("CLS");

        switch (option)
        {
        case 0:
            return 0;
            break;

        case 1:
              cout << "Insira uma string." << endl;

            while( !(cin >> str))
                cout << "Erro na leitura." << endl;

            hash->inserir(str);

            cout << "Indice obtido para a string: " << hash->indice +1 << endl << endl;
            //cout << "Indice obtido: " << hash->indice << endl;


            if(tabela[hash->indice].compare(str)==0)
                {
                    cout << "Já inseriu" << endl;
                }
            else if (tabela[hash->indice]==" ")
            {
                tabela[hash->indice] = str;
                cout << "'" << str << "' foi inserido no indice " << hash->indice +1 << endl;
            }
            else
            {
                cout << "Houve colisão" << endl;
                for (i=0; i<10; i++)
                    if(tabela[i]==" ")
                    {
                        tabela[i] = str;
                        cout << "'" << str << "' foi inserido no indice " << i +1 << endl;
                        break;
                    }
                if(i>=10) cout << "Tabela cheia." << endl;
            }

            cout << "Pressione qualquer tecla para voltar." << endl;
            getch();

            break;

        case 4:
            cout << endl << "| ";
            for(int j=0; j<10; j++)
            {
                if (tabela[j]== " ")
                    cout << " | ";
                else
                {
                    cout << " | " << tabela[j];
                }
            }

            cout << endl << endl;

            cout << "Pressione qualquer tecla para voltar." << endl;
            getch();
            break;

        case 2:
            cout << "Insira uma string." << endl;

            while( !(cin >> str))
                cout << "Erro na leitura." << endl;

            for(i=0; i<10; i++)
            {
                if(str.compare(tabela[i])==0)
                {
                    cout << "String '" << str << "' encontrada no indice " << i+1 << endl;
                    break;
                }
            }
            if(i>=10)
                cout << "Não encontrado" << endl;

            cout << "Pressione qualquer tecla para voltar." << endl;
            getch();

            break;

        case 3:
            cout << "Insira uma string." << endl;

            while( !(cin >> str))
                cout << "Erro na leitura." << endl;

            for(i=0; i<10; i++)
            {
                if(str.compare(tabela[i])==0)
                {
                    cout << "String '" << str << "' encontrada no indice " << i+1 << endl;
                    tabela[i] = " ";
                    cout << "Removido." << endl;
                    break;
                }
            }
            if(i>=10)
                cout << "Não encontrado" << endl;

            cout << "Pressione qualquer tecla para voltar." << endl;
            getch();
            break;

        default:
            cout << "Opcao Invalida" << endl
                << "1. Voltar" << endl << endl
                << "0. Sair" << endl;
            while( !(cin >> option))
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Opcao invalida."<< endl;
            }
            break;
        }
    }

    return 0;
}

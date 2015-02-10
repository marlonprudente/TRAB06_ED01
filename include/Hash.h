#ifndef HASH_H
#define HASH_H


class Hash
{
    public:
        int tam = 10;
        Hash();
        string get_palavra();
        int get_hash(string s, int tipo);
        void incluir_valor(string palavra);
        int buscar_valor(string palavra);
        void remover_valor(string palavra);
        void mostrar_tabela_hash();


        virtual ~Hash();
    protected:
    private:
};

#endif // HASH_H

#include<iostream>
using namespace std;


struct Tries
{
    /// se crea una matriz de adyacencia para generar los nodos del trie
    /// an adjacency matrix is ​​created to generate the trie nodes
    /// el espacio sera estatico deficiencia: memoria
    /// space will be static deficiency: memory
    int trie[50][100002];
    bool exist[100002]; ///verifica si el nodo existe / check if the node exists
    bool last[100002]; /// marca el ultimo nodo que se ingreso, asi el prefijo se contiene totalmente
                       /// mark the last node that was entered, so the prefix is ​​fully contained

    int ultnod; /// ultimo nodo / last node


    /// la idea principal es generar un grafo
    /// the main idea is to generate a graph

    void push(string &a)
    {
        int y = 0;
        for(int c = 0; c<a.size(); c++)
        {
            int x = 0;
            x = int( a[c] ) - 97;
            if(!exist[trie[x][y]]) /// se verifica el nodo / check  node
            {
               trie[x][y] = ++ultnod; /// guarda el nodo / save node
               exist[trie[x][y]] = true;
              // cout<<ultnod<<"\n";
            }
            y = trie[x][y];
        }
        last[y] = true ;
    }

    bool find(string &a)
    {
        int y = 0;
        for(int c = 0; c<a.size(); c++)
        {
            int x;
            x = int( a[c] ) - 97;
            if(!exist[trie[x][y]])
                return false;
            y = trie[x][y];
        }
        return last[y];
    }

};

Tries trie; /// crea un trie de Tries /// make a trie of Tries

main ()
{
    /// example
    string cases[] = {"no", "using", "stl", "hello", "here" };

    string query[] = {"hell", "ereh", "stl", "yes", "no", "sans"};

    int n = sizeof(cases) / sizeof (cases[0]);
    for(int c = 0; c<n; c++)
        trie.push(cases[c]);
    string res[] = {"Nop", "Yes"};

    int m = sizeof(query) / sizeof (query[0]);

    for(int c = 0; c<m; c++)
        cout<<res[trie.find(query[c])]<<"\n";

}

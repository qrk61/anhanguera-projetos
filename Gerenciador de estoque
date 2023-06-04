#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definição da classe Produto
class Produto {
public:
    string nome;
    int quantidade;

    // Construtor da classe Produto
    Produto(string nome, int quantidade) {
        this->nome = nome;
        this->quantidade = quantidade;
    }
};

// Função para adicionar um novo produto ao estoque
void adicionarProduto(vector<Produto>& estoque, string nome, int quantidade) {
    Produto novoProduto(nome, quantidade);
    estoque.push_back(novoProduto);
    cout << "Produto adicionado ao estoque." << endl;
}

// Função para remover um produto do estoque
void removerProduto(vector<Produto>& estoque, string nome) {
    for (int i = 0; i < estoque.size(); i++) {
        if (estoque[i].nome == nome) {
            estoque.erase(estoque.begin() + i);
            cout << "Produto removido do estoque." << endl;
            return;
        }
    }
    cout << "Produto não encontrado no estoque." << endl;
}

// Função para exibir todos os produtos no estoque
void exibirEstoque(vector<Produto>& estoque) {
    cout << "Estoque:" << endl;
    for (const Produto& produto : estoque) {
        cout << "Nome: " << produto.nome << ", Quantidade: " << produto.quantidade << endl;
    }
}

int main() {
    vector<Produto> estoque;  // vetor para armazenar os produtos do estoque

    // Exemplo de uso do gerenciador de estoque
    adicionarProduto(estoque, "Camiseta", 10);
    adicionarProduto(estoque, "Calça", 5);
    adicionarProduto(estoque, "Sapato", 3);

    exibirEstoque(estoque);

    removerProduto(estoque, "Calça");

    exibirEstoque(estoque);

    return 0;
}

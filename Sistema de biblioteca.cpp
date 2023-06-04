#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Livro {
public:
    string titulo;
    string autor;
    bool emprestado;
    int quantidade; // Nova adição: controla a quantidade de livros no estoque

    Livro(string titulo, string autor, int quantidade = 1) {
        this->titulo = titulo;
        this->autor = autor;
        this->emprestado = false;
        this->quantidade = quantidade;
    }
};

class SistemaBiblioteca {
private:
    vector<Livro> estoque;

public:
    void adicionarLivro(string titulo, string autor, int quantidade = 1) {
        // Verifica se o livro já existe no estoque
        for (Livro& livro : estoque) {
            if (livro.titulo == titulo && livro.autor == autor) {
                livro.quantidade += quantidade;
                cout << "Livro atualizado com sucesso." << endl;
                return;
            }
        }

        // Se o livro não existir, adiciona um novo ao estoque
        Livro livro(titulo, autor, quantidade);
        estoque.push_back(livro);
        cout << "Livro adicionado com sucesso." << endl;
    }

    void emprestarLivro(string titulo) {
        for (Livro& livro : estoque) {
            if (livro.titulo == titulo) {
                if (livro.emprestado) {
                    cout << "O livro já está emprestado." << endl;
                } else if (livro.quantidade == 0) {
                    cout << "O livro não está disponível no momento." << endl;
                } else {
                    livro.emprestado = true;
                    livro.quantidade--;
                    cout << "Livro emprestado com sucesso." << endl;
                }
                return;
            }
        }
        cout << "Livro não encontrado no estoque." << endl;
    }

    void devolverLivro(string titulo) {
        for (Livro& livro : estoque) {
            if (livro.titulo == titulo) {
                if (livro.emprestado) {
                    livro.emprestado = false;
                    livro.quantidade++;
                    cout << "Livro devolvido com sucesso." << endl;
                } else {
                    cout << "O livro não está emprestado." << endl;
                }
                return;
            }
        }
        cout << "Livro não encontrado no estoque." << endl;
    }

    void mostrarEstoque() {
        cout << "Estoque de livros:" << endl;
        for (const Livro& livro : estoque) {
            cout << "Título: " << livro.titulo << endl;
            cout << "Autor: " << livro.autor << endl;
            cout << "Quantidade disponível: " << livro.quantidade << endl;
            cout << "Status: " << (livro.emprestado ? "Emprestado" : "Disponível") << endl;
            cout << "----------------------------" << endl;
        }
    }

    // Novo método: pesquisar livro por título
    void pesquisarLivroPorTitulo(string titulo) {
        bool encontrado = false;
        cout << "Resultados da pesquisa por título: " << titulo << endl;
        for (const Livro& livro : estoque) {
            if (livro.titulo == titulo) {
                cout << "Título: " << livro.titulo << endl;
                cout << "Autor: " << livro.autor << endl;
                cout << "Quantidade disponível: " << livro.quantidade << endl;
                cout << "Status: " << (livro.emprestado ? "Emprestado" : "Disponível") << endl;
                cout << "----------------------------" << endl;
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "Nenhum livro encontrado com o título: " << titulo << endl;
        }
    }

    // Novo método: pesquisar livro por autor
    void pesquisarLivroPorAutor(string autor) {
        bool encontrado = false;
        cout << "Resultados da pesquisa por autor: " << autor << endl;
        for (const Livro& livro : estoque) {
            if (livro.autor == autor) {
                cout << "Título: " << livro.titulo << endl;
                cout << "Autor: " << livro.autor << endl;
                cout << "Quantidade disponível: " << livro.quantidade << endl;
                cout << "Status: " << (livro.emprestado ? "Emprestado" : "Disponível") << endl;
                cout << "----------------------------" << endl;
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "Nenhum livro encontrado com o autor: " << autor << endl;
        }
    }
};

int main() {
    SistemaBiblioteca sistema;

    sistema.adicionarLivro("Livro 1", "Autor 1");
    sistema.adicionarLivro("Livro 2", "Autor 2", 3);
    sistema.adicionarLivro("Livro 3", "Autor 3");

    sistema.mostrarEstoque();

    sistema.emprestarLivro("Livro 2");

    sistema.mostrarEstoque();

    sistema.devolverLivro("Livro 2");

    sistema.mostrarEstoque();

    sistema.pesquisarLivroPorTitulo("Livro 1");
    sistema.pesquisarLivroPorAutor("Autor 2");

    return 0;
}

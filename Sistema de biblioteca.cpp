#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Classe para representar um livro
class Livro {
public:
    string titulo;
    string autor;
    bool emprestado;

    Livro(string titulo, string autor) {
        this->titulo = titulo;
        this->autor = autor;
        this->emprestado = false;
    }
};

// Classe para representar o sistema de biblioteca
class SistemaBiblioteca {
private:
    vector<Livro> estoque;

public:
    // Adicionar um novo livro ao estoque
    void adicionarLivro(string titulo, string autor) {
        Livro livro(titulo, autor);
        estoque.push_back(livro);
    }

    // Emprestar um livro para um usuário
    void emprestarLivro(string titulo) {
        for (Livro& livro : estoque) {
            if (livro.titulo == titulo) {
                if (livro.emprestado) {
                    cout << "O livro já está emprestado." << endl;
                } else {
                    livro.emprestado = true;
                    cout << "Livro emprestado com sucesso." << endl;
                }
                return;
            }
        }
        cout << "Livro não encontrado no estoque." << endl;
    }

    // Devolver um livro ao estoque
    void devolverLivro(string titulo) {
        for (Livro& livro : estoque) {
            if (livro.titulo == titulo) {
                if (livro.emprestado) {
                    livro.emprestado = false;
                    cout << "Livro devolvido com sucesso." << endl;
                } else {
                    cout << "O livro não está emprestado." << endl;
                }
                return;
            }
        }
        cout << "Livro não encontrado no estoque." << endl;
    }

    // Mostrar informações sobre o estoque de livros
    void mostrarEstoque() {
        cout << "Estoque de livros:" << endl;
        for (const Livro& livro : estoque) {
            cout << "Título: " << livro.titulo << endl;
            cout << "Autor: " << livro.autor << endl;
            cout << "Status: " << (livro.emprestado ? "Emprestado" : "Disponível") << endl;
            cout << "----------------------------" << endl;
        }
    }
};

int main() {
    SistemaBiblioteca sistema;

    sistema.adicionarLivro("Livro 1", "Autor 1");
    sistema.adicionarLivro("Livro 2", "Autor 2");
    sistema.adicionarLivro("Livro 3", "Autor 3");

    sistema.mostrarEstoque();

    sistema.emprestarLivro("Livro 2");

    sistema.mostrarEstoque();

    sistema.devolverLivro("Livro 2");

    sistema.mostrarEstoque();

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Paciente {
    string nome;
    int idade;
    string historico;
};

struct Consulta {
    string paciente;
    string data;
    string horario;
    string medico;
    bool realizada;
};

class Clinica {
private:
    vector<Paciente> pacientes;
    vector<Consulta> consultas;

public:
    void cadastrarPaciente(const Paciente& paciente) {
        pacientes.push_back(paciente);
        cout << "Paciente cadastrado com sucesso!" << endl;
    }

    void agendarConsulta(const Consulta& consulta) {
        consultas.push_back(consulta);
        cout << "Consulta agendada com sucesso!" << endl;
    }

    void marcarConsultaRealizada(const string& paciente, const string& data, const string& horario) {
        for (auto& consulta : consultas) {
            if (consulta.paciente == paciente && consulta.data == data && consulta.horario == horario) {
                consulta.realizada = true;
                cout << "Consulta marcada como realizada!" << endl;
                return;
            }
        }
        cout << "Consulta não encontrada!" << endl;
    }

    void exibirRelatorioConsultas() {
        cout << "Relatório de Consultas:" << endl;
        for (const auto& consulta : consultas) {
            cout << "Paciente: " << consulta.paciente << endl;
            cout << "Data: " << consulta.data << endl;
            cout << "Horário: " << consulta.horario << endl;
            cout << "Médico: " << consulta.medico << endl;
            cout << "Realizada: " << (consulta.realizada ? "Sim" : "Não") << endl;
            cout << "-----------------------------------" << endl;
        }
    }
};

int main() {
    Clinica clinica;

    // Exemplo de utilização:
    Paciente paciente1 = { "João", 30, "Hipertensão" };
    clinica.cadastrarPaciente(paciente1);

    Consulta consulta1 = { "João", "01/06/2023", "14:30", "Dr. Silva", false };
    clinica.agendarConsulta(consulta1);

    clinica.marcarConsultaRealizada("João", "01/06/2023", "14:30");

    clinica.exibirRelatorioConsultas();

    return 0;
}

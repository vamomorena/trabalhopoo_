#include <iostream>

using namespace std;

class Empregado {
  public:
    Empregado(string nm, float val) {
      setNome(nm);
      setSalario(val);
    }
    string toString() {
      return "O salário do " + getNome() + " é de R$ " + to_string(getSalario());
    };
  protected:
    float salario;
    string nome;
    void setNome(string nm) {
      nome = nm;
    }
    string getNome() {
      return nome;
    }
    void setSalario(float sal) {
      salario = sal;
    }
    float getSalario() {
      return salario;
    }
};

class Gerente: public Empregado {
  public:
    Gerente(string nm, float val, string dpt) : Empregado(nm, val) {
      setDepartamento(dpt);
    }
    string toString() {
      return "O salário do " + getNome() + " é de R$ " + to_string(getSalario()) + " e ele faz parte do departamento " + getDepartamento();
    };
  protected:
    string departamento;
    void setDepartamento(string dep) {
      departamento = dep;
    }
    string getDepartamento() {
      return departamento;
    }
};

class Vendedor: public Empregado {
  public:
    Vendedor(string nm, float val, float per) : Empregado(nm, val) {
      setPercentualComissao(per);
    }
    string toString() {
      return "O salário do " + getNome() + " é de R$ " + to_string(getSalario()) + ", adicionando a comissao de " + to_string(getPercentualComissao()) + "%, o salário fica de R$ " + to_string(calcularSalario());
    };
  protected:
    float percentualComissao;
    void setPercentualComissao(float per) {
      percentualComissao = per;
    }
    float getPercentualComissao() {
      return percentualComissao;
    }
    float calcularSalario() {
      return getSalario() * (1 + (getPercentualComissao() / 100));
    };
};

int main() {
  Empregado e("Alice", 2000);
  Vendedor v("Jefferson", 3000, 10);
  Gerente g("Edina", 10000, "Diretoria");

  cout << e.toString() << endl;
  cout << v.toString() << endl;
  cout << g.toString();

  return 0;
}
/*
Titulo: Manipulação de Struct
Autor: Estefani
Data: 11/10/2024
  */

//Espaço reservado para declaração de biblioteca
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

//espaço reservado para construção da struct
struct Pessoa{
  int codigo;
  string nome;
  float altura;
};

//espaço reservado para prototipação de funções
int menu();
int lerCodigoValido(const string &mensagem);
void limparBuffer();
void exibirMsgErro(const string &mensagem);
void mostrarArray(Pessoa array[], int tamanho);
void esperarEnter();
void zerarArray(Pessoa array[], int tamanho);
void preencherArray(Pessoa array[], int tamanho);
string lerStringValida(const string &mensagem);
float lerAlturaValida(const string &mensagem);
void editarArray(Pessoa array[], int tamanho);
void verificarPessoa(Pessoa array[], int tamanho);
void ordenar(Pessoa array[], int tamanho);



//função principal
int main() {
  const int TAMANHO = 3;//define o tamanho do array de pessoas
  Pessoa array [TAMANHO];//declara o array para armazenar TAMANHO registros de pessoas 
  int opcao;

  do{
    opcao = menu();
    switch(opcao){
      case 1: mostrarArray(array, TAMANHO);break;
      case 2: zerarArray(array, TAMANHO);break;
      case 3: preencherArray(array, TAMANHO);break;
      case 4: editarArray(array, TAMANHO);break;
      case 5: verificarPessoa(array, TAMANHO);break;
      case 6: ordenar(array, TAMANHO);break;
      case 0: cout<< "Encerrar programa..."<<endl;break;
      default: exibirMsgErro("Opção Inválida! Escolha uma opção válida.");break;
    }
  }while(opcao!=0);
  
  return 0;
}

//função que exibe o menu e retorna a escolha do usuario
int menu(){
  cout<< "\nEscolha uma opção: \n";
  cout<< "1 - Mostrar array de pessoas\n";
  cout<< "2 - Zerar array de pessoas\n";
  cout<< "3 - Preencher array de pessoas\n";
  cout<< "4 - Editar pessoa no array\n";
  cout<< "5 - Verificar pessoa no array\n";
  cout<< "6 - Ordenar array de pessoas por código\n";
  cout<< "0 - Sair\n";
  return lerCodigoValido("Opção: ");
}

//função para ler um n ingeriro valido
int lerCodigoValido(const string &mensagem){
  int numero;
  while(true){
    cout<<mensagem;
    cin>>numero;
    if (cin.fail()){
      limparBuffer();
      exibirMsgErro("Entrada Inválida! Por favor, insira um número inteiro.");
    }else{
      limparBuffer();
      return numero;
    }
  }
}

//função paa limpar o buffer de entrada/sujeira
void limparBuffer(){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignora entradas inválidas no buffer
}

//função para exibir mensagem de erro 
void exibirMsgErro(const string &mensagem){
  cout<<mensagem<<endl;
}

//função para mostrar o array de pessoas
void mostrarArray(Pessoa array[], int tamanho){
  cout<<left<<setw(10)<<"Código"<<"\t"
      <<left<<setw(20)<<"Nome"<<"\t"
      <<left<<setw(10)<<"Altura"<<endl;
  cout<<string(50,'-')<<endl;
    for(int i=0;i<tamanho;i++){
      cout<<left<<setw(10)<<array[i].codigo<<"\t"
        <<left<<setw(20)<<array[i].nome<<"\t"
        <<left<<setw(10)<<array[i].altura<<endl;
    }
}

//fução para esperar o usuario pressi0on0a0r Enter
void esperarEnter(){
  cout<<"\nPressione Enter para continuar...";
  cin.get();
}

//função para zerar o array de pessoas
void zerarArray(Pessoa array[], int tamanho){
  for (int i=0;i<tamanho;i++){
    array[i].codigo = 0;
    array[i].nome = "";
    array[i].altura = 0.0;
  }
  cout<<"Array de pessoas zerado!";
  esperarEnter();
}

//função para preencher o array de pessoas
void preencherArray(Pessoa array[], int tamanho){
  for (int i=0;i<tamanho;i++){
    array[i].codigo = lerCodigoValido("Digite o Código da Pessoa ["+to_string(i)+"]: ");
    array[i].nome = lerStringValida("Digite o nome da Pessoa ["+to_string(i)+"]: ");
    array[i].altura = lerAlturaValida("Digite a Altura da Pessoa["+to_string(i)+"]: ");
    
  }
  cout<<"Array de pessoas preenchido com sucesso";
  esperarEnter();
}

//função para ler uma string válida
string lerStringValida(const string &mensagem){
  string entrada;
  cout<<mensagem;
  getline(cin, entrada);
  return entrada;
}

//função para ler altra valida
float lerAlturaValida(const string &mensagem){
  float altura;
  while(true){
    cout<<mensagem;
    cin>>altura;
    if (cin.fail() || altura <=0){
      limparBuffer();
      exibirMsgErro("Entrada inválida! Por favor, insira uma altura válida.");
    }else{
      limparBuffer();
      return altura;
    }
  }
}

//função para editar pessoa especifica no array
void editarArray(Pessoa array[], int tamanho){
  int posicao = lerCodigoValido("Digite a posição que deseja editar (0 a "+to_string(tamanho-1)+"): ");
  while (posicao<0 || posicao>=tamanho){
    exibirMsgErro("Posição Inválida! Tente Novamente.");
    posicao = lerCodigoValido("Digite uma Posição Válida: ");
  }
  array[posicao].codigo = lerCodigoValido("Digite o novo Código para a posição ["+to_string(posicao)+"]: ");
limparBuffer();
array[posicao].nome = lerStringValida("Digite o novo nome da Pessoa ["+to_string(posicao)+"]: ");
 array[posicao].altura = lerAlturaValida("Digite a nova Altura da Pessoa["+to_string(posicao)+"]: ");
  cout<<"Pessoa Editada com Sucesso!";
  esperarEnter();
}

//função para verificar pessoa no array
void verificarPessoa(Pessoa array[], int tamanho){
  int codigo = lerCodigoValido("Digite o código da pessoa que deseja verificar: ");
  bool encontrado = false;
  for (int i=0;i<tamanho;i++){
    if(array[i].codigo == codigo){
      cout<<"Pessoa com o Código"<<codigo<<"encontrada!<<endl";
      cout<<"Nome: "<<array[i].nome<<endl;
      cout<<"Altura: "<<array[i].altura<<endl;
      encontrado = true;
      break;
    }
  }
  if(!encontrado){
    cout<<"Pessoa com o código "<<codigo<<" não encontrada!"<<endl;
  }
  esperarEnter();
}

//função para ordenar o array por código
void ordenar(Pessoa array[], int tamanho){
  sort(array, array+tamanho, [](Pessoa a, Pessoa b){
    return a.codigo <b.codigo;
  });
cout<<"Array de pessoas ordenado por código!";
  esperarEnter();
}
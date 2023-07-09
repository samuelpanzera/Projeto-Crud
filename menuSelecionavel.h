/*
Modificações feitas por: Samuel Panzera,

Arquivo totalmente baseado no video: https://www.youtube.com/watch?v=OegTA6QrbDw

Foram feitas melhorias no codigo
*/

#include <conio.h>
#include <windows.h>

using namespace std;

void corDaSelecao(int cor){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),cor); //Seleciona a cord
}

void posicaoDoMenu(int x, int y){
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); // recursos da bliblioteca windows.h teoricamente nao funciona em linux
}

int menu(){
    int setColor[] = {12,7,7,7,7,7}; // Primeira cor vermelha e o resto Cor padrao
    int itemSelecionado = 1;
    char teclaSelecionada;

    system("cls");

     while(true){
        posicaoDoMenu(40,1); //Seta proxima saida ser na posição x e y
        cout << "Utilize as setas do teclado para navegar";

        posicaoDoMenu(10,5); //Seta proxima saida ser na posição x e y
        corDaSelecao(setColor[0]); //Seta a cor do array de acordo com a posicao definida
        cout << "1.Listar todos os veiculos"; // auto explicativo

        posicaoDoMenu(10,6);
        corDaSelecao(setColor[1]);
        cout << "2.Pesquisar um veiculo";

        posicaoDoMenu(10,7);
        corDaSelecao(setColor[2]);
        cout << "3.Cadastrar um veiculo";

        posicaoDoMenu(10,8);
        corDaSelecao(setColor[3]);
        cout << "4.Editar um veiculo";

        posicaoDoMenu(10,9);
        corDaSelecao(setColor[4]);
        cout << "5.Excluir um veiculo";

        posicaoDoMenu(10,10);
        corDaSelecao(setColor[5]);
        cout << "6.Sair" << endl;

        teclaSelecionada = _getch();

        if(teclaSelecionada == 72 && (itemSelecionado >= 1 && itemSelecionado <=6)){ // Seta pra Cima
            itemSelecionado --;

            if (itemSelecionado < 1) {
                    itemSelecionado = 6; // Caso a pessoa clique seta para cima ja estando na primeira posicao, vai para a ultima
            }
        }
        if(teclaSelecionada == 80 && (itemSelecionado >= 1 && itemSelecionado <=6)){ // Seta pra Baixo
            itemSelecionado ++;

            if (itemSelecionado > 6) {
                    itemSelecionado = 1; // caso pessoa clique seta para baixo ja estando na ultiam posicao, vai para a primeira
            }
        }

        printf("%d", itemSelecionado); // DEBUG -> --> RETIRAR <--

        if(teclaSelecionada == '\r'){ //Tecla enter
            if(itemSelecionado == 6){
              SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7); //Corrigindo um bug que deixa tudo vermelho ao clicar em "SAIR"
            }
            return itemSelecionado; // Sai do loop infinito, e retorna o item que foi selecionado
        }

        for (int i = 0; i < 6; i++ ){
          setColor[i] = 7; //Padroniza todas as cores de volta para o padrao
        }

        setColor[itemSelecionado - 1] = 12; //Cor selecionada vermelha o menos 1 é porcausa que array primeira posição é 0 etc...
    }
}

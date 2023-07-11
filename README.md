# Projeto Crud 

Projeto crud feito para um trabalho pratico final da materia de Algoritimos, feito para PUC Minas

Todo projeto consiste em um CRUD de veiculos que salva informações de placas, modelo, ano, marca, tipo e observações do veiculo em cada linha de arquivo,
o codigo tem como objetivo escrever (quando cadastra) e ler as informações.

## Alguns criterios de avaliação
  - Utilização de classes ou Structs em C++
  - Organização e a formatação do código seriam avaliadas 

## Menu
  - Listar todos os veículos
  - Pesquisar um veículo
  - Cadastrar um veículo
  - Editar um veículo
  - Excluir um veículo
  - Sair do programa

![image](https://github.com/samuelpanzera/Projeto-Crud/assets/94841496/e58463d9-3510-4921-884a-4286c7c516d4)

## Especificações do projeto
  - Menu feito utilizando bliblioteca do <windows.h>
  - Navegação é feita pelas Setas do teclado e ENTER
  - IDE utilizada Code Blocks

### Listagem de veiculos

![image](https://github.com/samuelpanzera/Projeto-Crud/assets/94841496/4dce3834-fd7a-4952-a8bc-a6dc9181f83c)

### Busca de veiculos

![image](https://github.com/samuelpanzera/Projeto-Crud/assets/94841496/8637b73d-7d31-4c54-a245-650e4de948a8)

### Edição e exclusão utilizam do mesmo sistema de busca

Veiculo é buscado, após isso a linha é retirada, numero de veiculos cadastrado é novamente calculado para assim ser editado/excluido

![image](https://github.com/samuelpanzera/Projeto-Crud/assets/94841496/5a27d702-991e-4944-86a6-ba5a67e15351)

### Cadastro 

No cadastro é feita a validação de todos os itens, verificado principalmente a nomenclatura da placa, tamanho e caso tenha algo de diferente
como por exemplo placa maior que 7 digitos, ou placa fora do padrão mercosul é lançada uma exceção que é tratada no codigo para que repita a 
parte digitada erroneamente.

Caso todos os dados estejam corretos, O veiculo é cadastrado e o programa volta para o menu

![image](https://github.com/samuelpanzera/Projeto-Crud/assets/94841496/207eaf52-fb49-455b-95e1-587e26fde6f4)




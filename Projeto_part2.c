#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1

typedef struct {
  int aluno;
  int faltas;
  int codigo;
  char nome[80];
  double nota1;
  double nota2;
  double nota3;
  double nota4;
  double media;
} Classe;

void trocar(Classe alunos[], int posicao, int posicao2);
void selectionsort_matricula(Classe aluno[], int n); 
void selectionsort_nome(Classe aluno[], int n);
void selectionsort_media(Classe aluno[], int n);
void selectionsort_faltas(Classe aluno[], int n);
void cadastrarAluno();
void escreverAlunoArquivo(Classe turma);
void lerAluno(int *qt, Classe turma[]);
void remocao();
void atualizar();
void listarCadastrados();
void listarAprovados();
void reprovadosMedia();
void reprovadosFalta();
void ordenar();

int qt = 0;
Classe turma[N];

int main() {

  int opcao, i;

  for (i = 0; i < N; i++) { 
    turma[i].codigo = 0;
    strcpy(turma[i].nome, "NULL");
    turma[i].aluno = 0;
    turma[i].faltas = 0;
    turma[i].media = 0;
    turma[i].nota1 = 0;
    turma[i].nota2 = 0;
    turma[i].nota3 = 0;
    turma[i].nota4 = 0;
  }

  do {
    printf("\nEscolha uma opção abaixo:\n\n");
    printf("[1] Cadastro\n");
    printf("[2] Remoção\n");
    printf("[3] Atualizar dados\n");
    printf("[4] Listar cadastrados\n");
    printf("[5] Listar aprovados\n");
    printf("[6] Reprovados por média\n");
    printf("[7] Reprovados por falta\n");
    printf("[8] Ordenar dados\n");
    printf("[9] Exit\n\n");

    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        for (i = 0; i < N; i++) {
          printf("\n\nInsira o código da turma: ");
          scanf("%d", &turma[i].codigo);
          printf("\n\nInsira o nome do aluno: ");
          scanf("%s", turma[i].nome);
          printf("\n\nInsira a matrícula do aluno: ");
          scanf("%d", &turma[i].aluno);
          printf("\n\nInsira as faltas do aluno: ");
          scanf("%d", &turma[i].faltas);
          printf("\n\nInsira a 1º nota: ");
          scanf("%lf", &turma[i].nota1);
          printf("\n\nInsira a 2º nota: ");
          scanf("%lf", &turma[i].nota2);
          printf("\n\nInsira a 3º nota: ");
          scanf("%lf", &turma[i].nota3);
          printf("\n\nInsira a 4º nota: ");
          scanf("%lf", &turma[i].nota4);
          printf("\nAluno cadastrado!!!\n");
        }
        cadastrarAluno();
        break;
  
      case 2:
        remocao();
        break;
        
  
      case 3:
        atualizar();
        break;
        
  
      case 4:
        listarCadastrados();
        break;
      
  
      case 5:
        listarAprovados();
        break;
        
  
      case 6:
        reprovadosMedia();
        break;
      
  
      case 7:
        reprovadosFalta();
        break;
        
  
      case 8:
        ordenar();
        break;
        
  
      case 9:
        printf("\nEscolheu sair!");
        break;
        
      default:
				printf("\nValor invalido!\n\n");
      }
  } while (opcao != 9);
}

void trocar(Classe alunos[], int posicao, int posicao2) {

  Classe ordem;

  ordem.codigo = alunos[posicao].codigo;
  ordem.aluno = alunos[posicao].aluno;
  ordem.faltas = alunos[posicao].faltas;
  ordem.nota1 = alunos[posicao].nota1;
  ordem.nota2 = alunos[posicao].nota2;
  ordem.nota3 = alunos[posicao].nota3;
  ordem.nota4 = alunos[posicao].nota4;
  strcpy(ordem.nome, alunos[posicao].nome);
  ordem.media = alunos[posicao].media;

  alunos[posicao].codigo = alunos[posicao2].codigo;
  alunos[posicao].aluno = alunos[posicao2].aluno;
  alunos[posicao].faltas = alunos[posicao2].faltas;
  alunos[posicao].nota1 = alunos[posicao2].nota1;
  alunos[posicao].nota2 = alunos[posicao2].nota2;
  alunos[posicao].nota3 = alunos[posicao2].nota3;
  alunos[posicao].nota4 = alunos[posicao2].nota4;
  strcpy(alunos[posicao].nome, alunos[posicao2].nome);
  alunos[posicao].media = alunos[posicao2].media;

  alunos[posicao2].codigo = ordem.codigo;
  alunos[posicao2].aluno = ordem.aluno;
  alunos[posicao2].faltas = ordem.faltas;
  alunos[posicao2].nota1 = ordem.nota1;
  alunos[posicao2].nota2 = ordem.nota2;
  alunos[posicao2].nota3 = ordem.nota3;
  alunos[posicao2].nota4 = ordem.nota4;
  strcpy(alunos[posicao2].nome, ordem.nome);
  alunos[posicao2].media = ordem.media;
}

void selectionsort_matricula(Classe aluno[], int n) {
  int i, j;
  int posicao;

  for (i = 0; i < n - 1; i++) {
    posicao = 0;
    for (j = 1; j < n - 1; j++)
      if (aluno[j].aluno > aluno[posicao].aluno) {
        posicao = j;
      }
    trocar(aluno, posicao, n - 1 - i);
  }
}

void selectionsort_nome(Classe aluno[], int n) {
  int i, j;
  int posicao;

  for (i = 0; i < n - 1; i++) {
    posicao = 0;
    for (j = 1; j < n - 1; j++)
      if (strcmp(aluno[j].nome, aluno[posicao].nome) > 0) {
        posicao = j;
      }

    trocar(aluno, posicao, n - 1 - i);
  }
}

void selectionsort_media(Classe aluno[], int n) {
  int i, j;
  int posicao;

  for (i = 0; i < n - 1; i++) {
    posicao = 0;
    for (j = 1; j < n - 1; j++)
      if (aluno[j].media > aluno[posicao].media) {
        posicao = j;
      }
    trocar(aluno, posicao, n - 1 - i);
  }
}

void selectionsort_faltas(Classe aluno[], int n) {
  int i, j;
  int posicao;

  for (i = 0; i < n - 1; i++) {
    posicao = 0;
    for (j = 1; j < n - 1; j++)
      if (aluno[j].faltas > aluno[posicao].faltas) {
        posicao = j;
      }
    trocar(aluno, posicao, n - 1 - i);
  }
}

void lerAluno(int *qt, Classe turma[]){
  FILE *arquivo;
  int i = 0;
  arquivo = fopen("alunos.txt", "r");

  if (arquivo == NULL)
    printf("Não foi possível abrir arquivo!\n");
  else{
    while(fscanf(arquivo,"%d %d %lf %lf %lf %lf %lf %s\n", &turma[i].aluno, &turma[i].faltas, &turma[i].nota1, &turma[i].nota2, &turma[i].nota3, &turma[i].nota4, &turma[i].media, turma[i].nome) != EOF)
			i++;
			
		fclose(arquivo);
  }
  *qt = i;
}

void escreverAlunoArquivo(Classe t){
  FILE *arquivo;
	arquivo = fopen("alunos.txt", "a");
	fprintf(arquivo,"%d\n %d\n %.2lf\n %.2lf\n %.2lf\n %.2lf\n %.2lf\n %s\n", t.aluno, t.faltas, t.nota1, t.nota2, t.nota3, t.nota4, t.media, t.nome);
	fclose(arquivo);
}

void cadastrarAluno(){
  Classe alunoNovo;
    for (int i = 0; i < N; i++) {
      turma[i].media = (turma[i].nota1 + turma[i].nota2 + turma[i].nota3 + turma[i].nota4) /4.0;
    }
    for (int i = 0; i < N; i++) {
        for (int x = i + 1; x < N; x++) {
          if (turma[i].aluno == turma[x].aluno) {
            printf("\nMatriculas iguais\n");
            for (i = 0; i < N; i++) {
              turma[i].aluno = 0;
            }
          }
        }
    }
  
  escreverAlunoArquivo(alunoNovo);
}

void remocao(){
  int flag1 = 0, m, flag, cod, mat, falta, cd;
  double n1, n2, n3, n4;
  char nome[80];
  
  lerAluno(&qt, turma);
	if(qt == 0)
		printf("Não existem alunos cadastrados!");
	else{
    printf("\nInsira a turma: ");
    scanf("%d", &cd);
  
    for (int i = 0; i < qt; i++) {
      if (turma[i].codigo == cd) {
          flag1 = 1;
      }
      else {
        printf("\nNenhuma turma encontrada!\n");
      }
    }
    if (flag1 == 1) {
            printf("\nInsira a matrícula que deseja remover: ");
            scanf("%d", &m);
  
            for (int i = 0; i < qt; i++) {
              if (turma[i].aluno == m) {
                flag = 1;
              }
            }
            if (flag == 1) {
              for (int i = 0; i < qt; i++) {
                if (m == turma[i].aluno) {
                  strcpy(turma[i].nome, "NULL");
                  turma[i].codigo = 0;
                  turma[i].aluno = 0;
                  turma[i].nota1 = 0;
                  turma[i].nota2 = 0;
                  turma[i].nota3 = 0;
                  turma[i].nota4 = 0;
                  turma[i].media = 0;
                  turma[i].faltas = 0;
  
                  printf("\nInsira a turma que deseja cadastrar a nova matrícula: ");
                  scanf("%d", &cod);
                  printf("\nInsira o nome do aluno: ");
                  scanf("%s", nome); 
                  printf("\nInforme a matricula: ");
                  scanf("%d", &mat);
                  printf("\nInsira as faltas: ");
                  scanf("%d", &falta);
                  printf("\nInsira a 1º nota: ");
                  scanf("%lf", &n1);
                  printf("\nInsira a 2º nota: ");
                  scanf("%lf", &n2);
                  printf("\nInsira a 3º nota: ");
                  scanf("%lf", &n3);
                  printf("\nInsira a 4º nota: ");
                  scanf("%lf", &n4);
  
                  strcpy(turma[i].nome, nome);
                  turma[i].codigo = cod;
                  turma[i].aluno = mat;
                  turma[i].faltas = falta;
                  turma[i].nota1 = n1;
                  turma[i].nota2 = n2;
                  turma[i].nota3 = n3;
                  turma[i].nota4 = n4;
  
                  for (i = 0; i < qt; i++) {
                    for (int x = i + 1; x < qt; x++) {
                      if (turma[i].aluno == turma[x].aluno) {
                        printf("Matriculas iguais\n");
                      }
                    }
                  }
                }
              }
            }
          } else {
            printf("Matricula não foi localizada\n");
          }
  }
}

void atualizar(){
  int ma, flag1 = 0, j, flag = 0;
  
  lerAluno(&qt, turma);
	if(qt == 0)
		printf("Não existem alunos cadastrados!");
	else{
    printf("\nInsira a matrícula: ");
    scanf("%d", &ma);
    
    for (int i = 0; i < qt; i++) {
          if (turma[i].aluno == ma) {
            flag = 1;
            j = i;
          }
        }
        if (flag == 1) {
          printf("Digite a 1º nota: \n");
          scanf("%lf", &turma[j].nota1);
          if (turma[j].nota1 < 0 || turma[j].nota1 > 10) {
            printf("Nota inválida!\n");
          }
          printf("Digite a 2º nota: \n");
          scanf("%lf", &turma[j].nota2);
          if (turma[j].nota2 < 0 || turma[j].nota2 > 10) {
            printf("Nota inválida!\n");
          }
          printf("Digite a 3º nota: \n");
          scanf("%lf", &turma[j].nota3);
          if (turma[j].nota3 < 0 || turma[j].nota3 > 10) {
            printf("Nota inválida!\n");
          }
          printf("Digite a 4º nota: \n");
          scanf("%lf", &turma[j].nota4);
          if (turma[j].nota4 < 0 || turma[j].nota4 > 10) {
            printf("Nota inválida!\n");
          }
          printf("Insira as faltas: \n");
          scanf("%d", &turma[j].faltas);
          if (turma[j].faltas > 36 || turma[j].faltas < 0) {
            printf("\nValor de faltas inválido!\n");
          }
        }
  
        else {
          printf("\nMatricula não localizada\n");
        }
  }
}

void listarCadastrados(){
  int flag1 = 0;
  
  lerAluno(&qt, turma);
	if(qt == 0)
		printf("Não existem alunos cadastrados!");
	else{
    printf("\nAlunos cadastrados nesta turma:\n");
    for (int i = 0; i < qt; i++) {
      printf("\nCódigo da turma: %d\n", turma[i].codigo);
      printf("Nome: %s\n", turma[i].nome);
      printf("Matrícula: %d\n", turma[i].aluno);
      printf("Faltas: %d\n", turma[i].faltas);
      printf("Nota 1: %.2lf\n", turma[i].nota1);
      printf("Nota 2: %.2lf\n", turma[i].nota2);
      printf("Nota 3: %.2lf\n", turma[i].nota3);
      printf("Nota 4: %.2lf\n", turma[i].nota4);
      printf("Média: %.2lf\n\n", turma[i].media);
    }
  }
}

void listarAprovados(){
  int flag1 = 0, flag = 0, cd;
  lerAluno(&qt, turma);
	if(qt == 0)
		printf("Não existem alunos cadastrados!");
	else{
    printf("\nInsira a turma: ");
    scanf("%d", &cd);
  
    for (int i = 0; i < qt; i++) {
      if (turma[i].codigo == cd) {
          flag1 = 1;
      }
      else {
        printf("\nNenhuma turma encontrada!\n");
      }
    }
    if (flag1 == 1) {
      for (int i = 0; i < qt; i++) {
        turma[i].media = (turma[i].nota1 + turma[i].nota2 + turma[i].nota3 + turma[i].nota4) /4.0;
        if (turma[i].media >= 7.0 && turma[i].faltas < 14) {
          printf("\nAluno %s com matrícula: %d, aprovado.\n", turma[i].nome, turma[i].aluno);
          flag = 1;
        }
      }
        if (flag != 1) {
          printf("\nNenhum aluno aprovado\n");
        }
    }
  }  
}

void reprovadosMedia(){
  int flag1 = 0, flag = 0, cd;

  lerAluno(&qt, turma);
	if(qt == 0)
		printf("Não existem alunos cadastrados!");
	else{
    printf("\nInsira a turma: ");
    scanf("%d", &cd);
    
    for (int i = 0; i < qt; i++) {
      if (turma[i].codigo == cd) {
          flag1 = 1;
      }
      else {
        printf("\nNenhuma turma encontrada!\n");
      }
    }
    if (flag1 == 1) {
      for (int i = 0; i < qt; i++) {
        if (turma[i].media < 7.0) {
          printf("\nMédia do aluno: %.2lf\n\n", turma[i].media);
          printf("Aluno %s com matrícula %d, reprovado por não atingir a média 7.0.\n", turma[i].nome, turma[i].aluno);
          flag = 1;
        }
      if (flag != 1) {
        printf("\nNenhum aluno reprovado!\n");
      }
      }
    }
  }  
}

void reprovadosFalta(){
  int flag1 = 0, flag = 0, cd;
  
  lerAluno(&qt, turma);
	if(qt == 0)
		printf("Não existem alunos cadastrados!");
	else{
    printf("\nInsira a turma: ");
    scanf("%d", &cd);
    
    for (int i = 0; i < qt; i++) {
      if (turma[i].codigo == cd) {
          flag1 = 1;
      }
      else {
        printf("\nNenhuma turma encontrada!\n");
      }
    }
    if (flag1 == 1) {
      for (int i = 0; i < qt; i++) {
        if (turma[i].faltas > 14) {
          printf("\nAluno %s com matrícula %d, reprovado por ter %d faltas\n", turma[i].nome, turma[i].aluno, turma[i].faltas);
          flag = 1;
        } 
        else {
          printf("\nNenhum aluno reprovado por falta!\n");
        }
      }
    }
  }
}

void ordenar(){
  int opcao1, opcao2, opcao3, i;
  
  lerAluno(&qt, turma);
	if(qt == 0)
		printf("Não existem alunos cadastrados!");
	else{
    printf("\nEscolha uma opção abaixo:\n\n");
        printf("[1] Ordenar por matrícula\n");
        printf("[2] Ordenar por nome\n");
        printf("[3] Ordenar por média\n");
        printf("[4] Ordenar por faltas\n\n");
  
        scanf("%d", &opcao1);
  
        if (opcao1 == 1) {
          selectionsort_matricula(turma, qt);
            for (i = 0; i < qt; i++) {
              printf("\nCódigo da turma: %d\n", turma[i].codigo);
              printf("Nome: %s\n", turma[i].nome);
              printf("Matrícula: %d\n", turma[i].aluno);
              printf("Faltas: %d\n", turma[i].faltas);
              printf("Nota 1: %.2lf\n", turma[i].nota1);
              printf("Nota 2: %.2lf\n", turma[i].nota2);
              printf("Nota 3: %.2lf\n", turma[i].nota3);
              printf("Nota 4: %.2lf\n", turma[i].nota4);
              printf("Média: %.2lf\n", turma[i].media);
            }
        }
  
        if (opcao1 == 2) {
          selectionsort_nome(turma, qt);
            for (i = 0; i < qt; i++) {
              printf("\nCódigo da turma: %d\n", turma[i].codigo);
              printf("Nome: %s\n", turma[i].nome);
              printf("Matrícula: %d\n", turma[i].aluno);
              printf("Faltas: %d\n", turma[i].faltas);
              printf("Nota 1: %.2lf\n", turma[i].nota1);
              printf("Nota 2: %.2lf\n", turma[i].nota2);
              printf("Nota 3: %.2lf\n", turma[i].nota3);
              printf("Nota 4: %.2lf\n", turma[i].nota4);
              printf("Média: %.2lf\n", turma[i].media);
            }
          }
  
        if (opcao1 == 3) {
          selectionsort_media(turma, qt);
            for (i = 0; i < qt; i++) {
              printf("\nCódigo da turma: %d\n", turma[i].codigo);
              printf("Nome: %s\n", turma[i].nome);
              printf("Matrícula: %d\n", turma[i].aluno);
              printf("Faltas: %d\n", turma[i].faltas);
              printf("Nota 1: %.2lf\n", turma[i].nota1);
              printf("Nota 2: %.2lf\n", turma[i].nota2);
              printf("Nota 3: %.2lf\n", turma[i].nota3);
              printf("Nota 4: %.2lf\n", turma[i].nota4);
              printf("Média: %.2lf\n", turma[i].media);
            }
        }
  
        else {
          selectionsort_faltas(turma, qt);
            for (i = 0; i < qt; i++) {
              printf("\nCódigo da turma: %d\n", turma[i].codigo);
              printf("Nome: %s\n", turma[i].nome);
              printf("Matrícula: %d\n", turma[i].aluno);
              printf("Faltas: %d\n", turma[i].faltas);
              printf("Nota 1: %.2lf\n", turma[i].nota1);
              printf("Nota 2: %.2lf\n", turma[i].nota2);
              printf("Nota 3: %.2lf\n", turma[i].nota3);
              printf("Nota 4: %.2lf\n", turma[i].nota4);
              printf("Média: %.2lf\n", turma[i].media);
            }
        }
  }
}

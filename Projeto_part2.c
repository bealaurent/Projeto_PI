#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 4

typedef struct{
  int aluno;
  int faltas;
  int codigo;
  char nome[80];
  double nota1;
  double nota2;
  double nota3;
  double nota4;
  double media;
}Classe;

void trocar(Classe alunos[], int posicao, int posicao2){
	
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

void selectionsort_matricula(Classe aluno[], int n){
	int i, j;
	int posicao;

	for(i = 0; i < n - 1; i++){
	posicao = 0;
		for(j = 1; j < n - 1; j++)
			if(aluno[j].aluno > aluno[posicao].aluno){
				posicao = j;
			}
		trocar(aluno, posicao, n - 1 - i);
	}
}

void selectionsort_nome(Classe aluno[], int n){
	int i, j;
	int posicao;

	for(i = 0; i < n - 1; i++){
	posicao = 0;
		for(j = 1; j < n - 1; j++)
			if(strcmp(aluno[j].nome, aluno[posicao].nome) > 0){
				posicao = j;
			}
    
		trocar(aluno, posicao, n - 1 - i);
	}
}

void selectionsort_media(Classe aluno[], int n){
	int i, j;
	int posicao;

	for(i = 0; i < n - 1; i++){
	posicao = 0;
		for(j = 1; j < n - 1; j++)
			if(aluno[j].media > aluno[posicao].media){
				posicao = j;
			}
		trocar(aluno, posicao, n - 1 - i);
	}
}

void selectionsort_faltas(Classe aluno[], int n){
	int i, j;
	int posicao;

	for(i = 0; i < n - 1; i++){
	posicao = 0;
		for(j = 1; j < n - 1; j++)
			if(aluno[j].faltas > aluno[posicao].faltas){
				posicao = j;
			}
		trocar(aluno, posicao, n - 1 - i);
	}
}

int main(){

  FILE *arquivo;

  arquivo = fopen("alunos.txt", "arquivo");
  
  int opcao, i, m = 0, ma = 0, mat = 0, armazena = 0, x, flag = 0, flag1 = 0, falta, j, opcao1, n, cd, cod;
  char nome[200];
  double n1, n2, n3, n4;

  Classe turma[N];

  for (i = 0; i < N; i++){
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

  do{
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

  if ((opcao < 1) || (opcao > 9)) {
    printf("\nValor inválido!!!\n\n");
    fprintf(arquivo, "\nValor inválido!!!\n\n");
  }

  switch(opcao){
  case 1:
    for (i = 0; i < N; i++) {
      if (turma[i].aluno != 0){
        armazena++;
      }
    }
    if (armazena == N){
      printf("\nNúmero máximo de matrículas atingido!\n");
      fprintf(arquivo, "\nNúmero máximo de matrículas atingido!\n");
      break;
    }
    
    for(i = 0; i < N; i++){
    printf("\n\nInsira o código da turma: ");
    scanf("%d", &turma[i].codigo);
    printf("\nInsira o nome do aluno: ");
    scanf("%s", &turma[i].nome);
    printf("\nInsira a matrícula do aluno: ");
    scanf("%d", &turma[i].aluno);
    printf("\nInsira as faltas do aluno: ");
    scanf("%d", &turma[i].faltas);
    printf("\nInsira a 1º nota: ");
    scanf("%lf", &turma[i].nota1);
    printf("\nInsira a 2º nota: ");
    scanf("%lf", &turma[i].nota2);
    printf("\nInsira a 3º nota: ");
    scanf("%lf", &turma[i].nota3);
    printf("\nInsira a 4º nota: ");
    scanf("%lf", &turma[i].nota4);
    printf("\nAluno cadastrado!!!\n");
    }

    for(i = 0; i < N; i++){
    turma[i].media = (turma[i].nota1 + turma[i].nota2 + turma[i].nota3 + turma[i].nota4) / 4.0;
    }
    
    for (i = 0; i < N; i++){      
      for (x = i + 1; x < N; x++){
        if (turma[i].aluno == turma[x].aluno){
          printf("\nMatriculas iguais\n");
          fprintf(arquivo, "\nMatriculas iguais\n");
          for (i = 0; i < N; i++){
              turma[i].aluno = 0;
            }
          }
        }
      }
      break;

  case 2:
    for (i = 0; i < N; i++){
      if (turma[i].aluno == 0){
          armazena++;
      }
    }
    if (armazena == N){
      printf("Nenhum matrícula ou turma cadastrada\n");
      fprintf(arquivo, "Nenhum matrícula ou turma cadastrada\n");
      break;
    }

    else{
      printf("\nInsira a turma: ");
      scanf("%d", &cd);
    
      for(i = 0; i < N; i++){
        if (turma[i].codigo == cd){
          flag1 = 1;
        }
      }
      if (flag1 == 1){
    printf("\nInsira a matrícula que deseja remover: ");
    scanf("%d", &m);
    
        for (i = 0; i < N; i++){
            if (turma[i].aluno == m){
              flag = 1;
            }
          }
        if (flag == 1){
            for (i = 0; i < N; i++){
              if (m == turma[i].aluno){
                strcpy (turma[i].nome, "NULL");
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
                scanf("%s", &nome);
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
                
                strcpy (turma[i].nome, nome);
                turma[i].codigo = cod;
                turma[i].aluno = mat;
                turma[i].faltas = falta;
                turma[i].nota1 = n1;
                turma[i].nota2 = n2;
                turma[i].nota3 = n3;
                turma[i].nota4 = n4;
                
                for (i = 0; i < N; i++){
                  for (x = i + 1; x < N; x++){
                    if (turma[i].aluno == turma[x].aluno){
                      printf("Matriculas iguais\n");
                      fprintf(arquivo, "Matriculas iguais\n");
                      break;
                    }
                  }
                }
              }
            }
          }
      }
      else{
        printf("Matricula não foi localizada\n");
        fprintf(arquivo, "Matricula não foi localizada\n");
        break;
      }
    }
    break;

  case 3:
    for (i = 0; i < N; i++){
      if (turma[i].aluno == 0){
          armazena++;
      }
    }
    if (armazena == N){
      printf("Nenhuma matrícula cadastrada\n");
      fprintf(arquivo, "Nenhuma matrícula cadastrada\n");
      break;
    }
    
    printf("\nInsira a matrícula: ");
    scanf("%d", &ma);
    
    for(i = 0; i < N; i++){
      if (turma[i].aluno == ma){
        flag1 = 1;
        j = i;
      }
    }    
    if (flag == 1){
      printf("Digite a 1º nota: \n");
        scanf("%lf", &turma[j].nota1);
        if (turma[j].nota1 < 0 || turma[j].nota1 > 10){
          printf("Nota inválida\n");
          fprintf(arquivo, "Nota inválida\n");
        }
      printf("Digite a 2º nota: \n");
      scanf("%lf", &turma[j].nota2);
        if (turma[j].nota2 < 0 || turma[j].nota2 > 10){
          printf("Nota inválida\n");
          fprintf(arquivo, "Nota inválida\n");
        }
      printf("Digite a 3º nota: \n");
      scanf("%lf", &turma[j].nota3);
        if (turma[j].nota3 < 0 || turma[j].nota3 > 10){
          printf("Nota inválida\n");
          fprintf(arquivo, "Nota inválida\n");
        }
      printf("Digite a 4º nota: \n");
      scanf("%lf", &turma[j].nota4);
        if (turma[j].nota4 < 0 || turma[j].nota4 > 10){
          printf("Nota inválida\n");
          fprintf(arquivo, "Nota inválida\n");
        }
        printf("Insira as faltas");
        scanf("%d", &turma[j].faltas);
        if (turma[j].faltas > 36 || turma[j].faltas < 0){
          printf("Valor de faltas inválido\n");
          fprintf(arquivo, "Valor de faltas inválido\n");
        }
      }
    
    else{
        printf("Matricula não localizada\n");
        fprintf(arquivo, "Matricula não localizada\n");
        break;
      }
      
    break;
  
  case 4:
    for (i = 0; i < N; i++){
      if (turma[i].aluno == 0){
          armazena++;
      }
    }
    if (armazena == N){
      printf("\nNenhuma matrícula cadastrada\n");
      fprintf(arquivo, "\nNenhuma matrícula cadastrada\n");
      break;
    }
    
    else{
      printf("\nInsira a turma: ");
      scanf("%d", &cd);
    
      for(i = 0; i < N; i++){
        if (turma[i].codigo == cd){
          flag1 = 1;
        }
      }
      if (flag1 == 1){
        printf("\nAlunos cadastrados na turma %d\n", cd);
        fprintf(arquivo, "\nAlunos cadastrados na turma %d\n", cd);
        for (i = 0; i < N; i++){
          printf("\nCódigo da turma: %d\n", turma[i].codigo);
          fprintf(arquivo, "Código da turma: %d\n", turma[i].codigo);
          printf("Nome: %s\n", turma[i].nome);
          fprintf(arquivo, "Nome: %s\n", turma[i].nome);
          printf("Matrícula: %d\n", turma[i].aluno);
          fprintf(arquivo, "Matrícula: %d\n", turma[i].aluno);
          printf("Faltas: %d\n", turma[i].faltas);
          fprintf(arquivo, "Faltas: %d\n", turma[i].faltas);
          printf("Nota 1: %.2lf\n", turma[i].nota1);
          fprintf(arquivo, "Nota 1: %.1lf\n", turma[i].nota1);
          printf("Nota 2: %.2lf\n", turma[i].nota2);
          fprintf(arquivo, "Nota 2: %.1lf\n", turma[i].nota2);
          printf("Nota 3: %.2lf\n", turma[i].nota3);
          fprintf(arquivo, "Nota 3: %.1lf\n", turma[i].nota3);
          printf("Nota 4: %.2lf\n", turma[i].nota4);
          fprintf(arquivo, "Nota 4: %.1lf\n", turma[i].nota4);
          printf("Média: %.2lf\n\n", turma[i].media);
          fprintf(arquivo, "Média: %.2lf\n\n", turma[i].media);
        }
      }
      else{
        printf("\nTurma não localizada\n");
        fprintf(arquivo, "\nTurma não localizada\n");
        break;
      }
    
    break;
    
  case 5:
    for (i = 0; i < N; i++){
      if (turma[i].aluno == 0){
          armazena++;
      }
    }
    
    if (armazena == N){
      printf("\nNenhuma matrícula cadastrada\n");
      fprintf(arquivo, "\nNenhuma matrícula cadastrada\n");
      break;
    }
    
    else{
      printf("\nInsira a turma: ");
      scanf("%d", &cd);
    
      for(i = 0; i < N; i++){
        if (turma[i].codigo == cd){
          flag1 = 1;
        }
      }
      
      if (flag1 == 1){
        for (i = 0; i < N; i++){
          turma[i].media = (turma[i].nota1 + turma[i].nota2 + turma[i].nota3 + turma[i].nota4) / 4.0;
          if (turma[i].media >= 7.0 && turma[i].faltas < 14) {
            printf("\nAluno %s com matrícula: %d, aprovado.\n", turma[i].nome, turma[i].aluno);
            fprintf(arquivo, "\nAluno %s com matrícula: %d, aprovado.\n", turma[i].nome, turma[i].aluno);
            flag = 1;
          }
        }
        if (flag != 1){
          printf("\nNenhum aluno aprovado\n");
          fprintf(arquivo, "\nNenhum aluno aprovado\n");
        }
      }
    }
    
    break;

  case 6:
    for (i = 0; i < N; i++){
      if (turma[i].aluno == 0){
          armazena++;
      }
    }
    if (armazena == N){
      printf("\nNenhuma matrícula cadastrada\n");
      fprintf(arquivo, "\nNenhuma matrícula cadastrada\n");
      break;
    }
    
    else{
      printf("\nInsira a turma: ");
      scanf("%d", &cd);
    
      for(i = 0; i < N; i++){
        if (turma[i].codigo == cd){
          flag1 = 1;
        }
      }
      
      if (flag1 == 1){    
        for (i = 0; i < N; i++) {
          if (turma[i].media < 7.0) {
            printf("\nMédia do aluno: %.2lf\n\n", turma[i].media);
            printf("Aluno %s com matrícula %d, reprovado por não atingir a média 7.0.\n", turma[i].nome, turma[i].aluno);
            fprintf(arquivo, "Aluno %s com matrícula %d, reprovado por não atingir a média 7.0.\n", turma[i].nome, turma[i].aluno);
            flag = 1;
          }
        }
      }
      break;
      
      if (flag != 1){
        printf("\nNenhum aluno reprovado!\n");
        fprintf(arquivo, "\nNenhum aluno reprovado!\n");
      }
    }
    
    break;  

  case 7:
    for (i = 0; i < N; i++) { 
      if (turma[i].aluno == 0) {
          armazena++;
        }
      }
    if (armazena == N) {
        printf("\nNenhuma matrícula cadastrada\n");
        fprintf(arquivo, "\nNenhuma matrícula cadastrada\n");
        break;
      }
        
    else{
        printf("\nInsira a turma: ");
        scanf("%d", &cd);
      
        for(i = 0; i < N; i++){
          if (turma[i].codigo == cd){
            flag1 = 1;
          }
        }
        if (flag1 == 1){
          for (i = 0; i < N; i++) {
            if (turma[i].faltas > 14) {
              printf("\nAluno %s com matrícula %d, reprovado por ter %d faltas\n", turma[i].nome, turma[i].aluno, turma[i].faltas);
            fprintf(arquivo, "\nAluno %s com matrícula %d, reprovado por ter %d faltas\n", turma[i].nome, turma[i].aluno, turma[i].faltas);
            flag = 1;
            }
          }
        break;
        }
    
        else{
        printf("\nNenhum aluno reprovado por falta!\n");
        fprintf(arquivo, "\nNenhum aluno reprovado por falta!\n");
        }
      }    
    
    break;

  case 8:
    for (i = 0; i < N; i++){
      if (turma[i].aluno == 0){
          armazena++;
      }
    }
    if (armazena == N){
      printf("\nNenhuma matrícula cadastrada\n");
      fprintf(arquivo, "\nNenhuma matrícula cadastrada\n");
      break;
    }
    
    else{
      printf("\nEscolha uma opção abaixo:\n\n");
      printf("[1] Ordenar por matrícula\n");
      printf("[2] Ordenar por nome\n");
      printf("[3] Ordenar por média\n");
      printf("[4] Ordenar por faltas\n\n");

      scanf("%d", &opcao1);
    
      if (opcao1 == 1){
        selectionsort_matricula(turma, N);
          for (i = 0; i < N; i++){
            printf("\nCódigo da turma: %d\n", turma[i].codigo);
            fprintf(arquivo, "\nCódigo da turma: %d\n", turma[i].codigo);
            printf("Nome: %s\n", turma[i].nome);
            fprintf(arquivo, "Nome: %s\n", turma[i].nome);
            printf("Matrícula: %d\n", turma[i].aluno);
            fprintf(arquivo, "Matrícula: %d\n", turma[i].aluno);
            printf("Faltas: %d\n", turma[i].faltas);
            fprintf(arquivo, "Faltas: %d\n", turma[i].faltas);
            printf("Nota 1: %.2lf\n", turma[i].nota1);
            fprintf(arquivo, "Nota 1: %.1lf\n", turma[i].nota1);
            printf("Nota 2: %.2lf\n", turma[i].nota2);
            fprintf(arquivo, "Nota 2: %.1lf\n", turma[i].nota2);
            printf("Nota 3: %.2lf\n", turma[i].nota3);
            fprintf(arquivo, "Nota 3: %.1lf\n", turma[i].nota3);
            printf("Nota 4: %.2lf\n", turma[i].nota4);
            fprintf(arquivo, "Nota 4: %.1lf\n", turma[i].nota4);
            printf("Média: %.2lf\n", turma[i].media);
            fprintf(arquivo, "Média: %.2lf\n", turma[i].media);
          }
      }

      if (opcao1 == 2){
        selectionsort_nome(turma, N);
          for (i = 0; i < N; i++){
            printf("\nCódigo da turma: %d\n", turma[i].codigo);
            fprintf(arquivo, "\nCódigo da turma: %d\n", turma[i].codigo);
            printf("Nome: %s\n", turma[i].nome);
            fprintf(arquivo, "Nome: %s\n", turma[i].nome);
            printf("Matrícula: %d\n", turma[i].aluno);
            fprintf(arquivo, "Matrícula: %d\n", turma[i].aluno);
            printf("Faltas: %d\n", turma[i].faltas);
            fprintf(arquivo, "Faltas: %d\n", turma[i].faltas);
            printf("Nota 1: %.2lf\n", turma[i].nota1);
            fprintf(arquivo, "Nota 1: %.1lf\n", turma[i].nota1);
            printf("Nota 2: %.2lf\n", turma[i].nota2);
            fprintf(arquivo, "Nota 2: %.1lf\n", turma[i].nota2);
            printf("Nota 3: %.2lf\n", turma[i].nota3);
            fprintf(arquivo, "Nota 3: %.1lf\n", turma[i].nota3);
            printf("Nota 4: %.2lf\n", turma[i].nota4);
            fprintf(arquivo, "Nota 4: %.1lf\n", turma[i].nota4);
            printf("Média: %.2lf\n", turma[i].media);
            fprintf(arquivo, "Média: %.2lf\n", turma[i].media);
        }
      }
    
      if (opcao1 == 3){
        selectionsort_media(turma, N);
          for (i = 0; i < N; i++){
            printf("\nCódigo da turma: %d\n", turma[i].codigo);
            fprintf(arquivo, "\nCódigo da turma: %d\n", turma[i].codigo);
            printf("Nome: %s\n", turma[i].nome);
            fprintf(arquivo, "Nome: %s\n", turma[i].nome);
            printf("Matrícula: %d\n", turma[i].aluno);
            fprintf(arquivo, "Matrícula: %d\n", turma[i].aluno);
            printf("Faltas: %d\n", turma[i].faltas);
            fprintf(arquivo, "Faltas: %d\n", turma[i].faltas);
            printf("Nota 1: %.2lf\n", turma[i].nota1);
            fprintf(arquivo, "Nota 1: %.1lf\n", turma[i].nota1);
            printf("Nota 2: %.2lf\n", turma[i].nota2);
            fprintf(arquivo, "Nota 2: %.1lf\n", turma[i].nota2);
            printf("Nota 3: %.2lf\n", turma[i].nota3);
            fprintf(arquivo, "Nota 3: %.1lf\n", turma[i].nota3);
            printf("Nota 4: %.2lf\n", turma[i].nota4);
            fprintf(arquivo, "Nota 4: %.1lf\n", turma[i].nota4);
            printf("Média: %.2lf\n", turma[i].media);
            fprintf(arquivo, "Média: %.2lf\n", turma[i].media);
          }
      }
      
      else{
        selectionsort_faltas(turma, N);
          for (i = 0; i < N; i++){
            printf("\nCódigo da turma: %d\n", turma[i].codigo);
            fprintf(arquivo, "\nCódigo da turma: %d\n", turma[i].codigo);
            printf("Nome: %s\n", turma[i].nome);
            fprintf(arquivo, "Nome: %s\n", turma[i].nome);
            printf("Matrícula: %d\n", turma[i].aluno);
            fprintf(arquivo, "Matrícula: %d\n", turma[i].aluno);
            printf("Faltas: %d\n", turma[i].faltas);
            fprintf(arquivo, "Faltas: %d\n", turma[i].faltas);
            printf("Nota 1: %.2lf\n", turma[i].nota1);
            fprintf(arquivo, "Nota 1: %.1lf\n", turma[i].nota1);
            printf("Nota 2: %.2lf\n", turma[i].nota2);
            fprintf(arquivo, "Nota 2: %.1lf\n", turma[i].nota2);
            printf("Nota 3: %.2lf\n", turma[i].nota3);
            fprintf(arquivo, "Nota 3: %.1lf\n", turma[i].nota3);
            printf("Nota 4: %.2lf\n", turma[i].nota4);
            fprintf(arquivo, "Nota 4: %.1lf\n", turma[i].nota4);
            printf("Média: %.2lf\n", turma[i].media);
            fprintf(arquivo,"Média: %.2lf\n", turma[i].media);
          }
      }
    }
    
    break;
    
  case 9:
    printf("\nEscolheu sair!");
    fprintf(arquivo, "\nEscolheu sair!");
    break;
        
  }}}while (opcao != 9);
  fclose(arquivo);
  return 0;
}
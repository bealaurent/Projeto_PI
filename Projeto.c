//Projeto de Beathriz Laurent Carlos Muniz
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int N = 2;

int main() {

  int opcao, i, m = 0, ma = 0, mat = 0, armazena = 0, x, flag = 0, flag1 = 0, falta, j;
  int aluno[N], faltas[N];
  double nota[N][4], media[N], nota1, nota2, nota3, nota4;

  for (i = 0; i < N; i++){
    aluno[i] = 0;
    faltas[i] = 0;
    media[i] = 0;
    nota[i][0] = 0;
    nota[i][1] = 0;
    nota[i][2] = 0;
    nota[i][3] = 0;
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
  printf("[8] Exit\n\n");

  scanf("%d", &opcao);

  if ((opcao < 1) || (opcao > 8)) {
    printf("\n""Valor inválido!!!\n\n");
  }

  switch(opcao){
  case 1:
    for (i = 0; i < N; i++) {
      if (aluno[i] != 0){
        armazena++;
      }
    }
    if (armazena == N){
      printf("\nNúmero máximo de matrículas atingido!\n");
      break;
    }
    
    for(i = 0; i < N; i++){
    printf("\nInsira a Matrícula: ");
    scanf("%d", &aluno[i]);
    printf("Insira as faltas: ");
    scanf("%d", &faltas[i]);
    printf("Insira a 1º nota: ");
    scanf("%lf", &nota[i][0]);
    printf("Insira a 2º nota: ");
    scanf("%lf", &nota[i][1]);
    printf("Insira a 3º nota: ");
    scanf("%lf", &nota[i][2]);
    printf("Insira a 4º nota: ");
    scanf("%lf", &nota[i][3]);
    }
    
    for(i = 0; i < N; i++){
    media[i] = (nota[i][0] + nota[i][1] + nota[i][2] + nota[i][3]) / 4.0;}
    
    for (i = 0; i < N; i++){      
      for (x = i + 1; x < N; x++){
        if (aluno[i] == aluno[x]){
          printf("\nMatriculas iguais\n"); 
          for (i = 0; i < N; i++){
              aluno[i] = 0;
            }
          }
        }
      }
      break;
    break;

  case 2:
    for (i = 0; i < N; i++){
      if (aluno[i] == 0){
          armazena++;
      }
    }
    if (armazena == N){
      printf("Nenhuma matrícula cadastrada\n");
      break;
    }
    
    printf("\nInsira a matrícula que deseja remover: ");
    scanf("%d", &m);
    
    for (i = 0; i < N; i++){
        if (aluno[i] == m){
          flag = 1;
        }
      }
    
      if (flag == 1){
        for (i = 0; i < N; i++){
          if (m == aluno[i])
          {
            aluno[i] = 0;
			media[i] = 0;
            faltas[i] = 0;
            nota[i][0] = 0;
            nota[i][1] = 0;
            nota[i][2] = 0;
            nota[i][3] = 0;
            
            
            printf("Informe nova matricula que deseja cadastrar: \n");
            scanf("%d", &mat);
            printf("Insira as faltas: ");
            scanf("%d", &falta);
            printf("Insira a 1º nota: ");
            scanf("%lf", &nota1);
            printf("Insira a 2º nota: ");
            scanf("%lf", &nota2);
            printf("Insira a 3º nota: ");
            scanf("%lf", &nota3);
            printf("Insira a 4º nota: ");
            scanf("%lf", &nota4);
            
            aluno[i] = mat;
            faltas[i] = falta;
            nota[i][0] = nota1;
            nota[i][1] = nota2;
            nota[i][2] = nota3;
            nota[i][3] = nota4;
            
            for (i = 0; i < N; i++){
              for (x = i + 1; x < N; x++){
                if (aluno[i] == aluno[x]){
                  printf("Matriculas iguais\n");
                  break;
                }
              }
            }
          }
        }
      }
      else{
        printf("Matricula não foi localizada\n");
        break;
      }
    break;

  case 3:
    for (i = 0; i < N; i++){
      if (aluno[i] == 0){
          armazena++;
      }
    }
    if (armazena == N){
      printf("Nenhuma matrícula cadastrada\n");
      break;
    }
    printf("\nInsira a matrícula: ");
    scanf("%d", &ma);
    
    for(i = 0; i < N; i++){
      if (aluno[i] == ma){
        flag1 = 1;
        j = i;
      }
    }    
    if (flag == 1){
      printf("Digite a 1º nota: \n");
        scanf("%lf", &nota[j][0]);
        if (nota[j][0] < 0 || nota[j][0] > 10){
          printf("Nota inválida\n");
        }
      printf("Digite a 2º nota: \n");
      scanf("%lf", &nota[j][1]);
        if (nota[j][1] < 0 || nota[j][1] > 10){
          printf("Nota inválida\n");
        }
      printf("Digite a 3º nota: \n");
      scanf("%lf", &nota[j][2]);
        if (nota[j][2] < 0 || nota[j][2] > 10){
          printf("Nota inválida\n");
        }
      printf("Digite a 4º nota: \n");
      scanf("%lf", &nota[j][3]);
        if (nota[j][3] < 0 || nota[j][3] > 10){
          printf("Nota inválida\n");
        }
        printf("Insira as faltas");
        scanf("%d", &faltas[j]);
        if (faltas[j] > 36 || faltas[j] < 0){
          printf("Valor de faltas inválido\n");
        }
      }
      else{
        printf("Matricula não localizada\n");
        break;
      }
      
    break;
  
  case 4:
    for (i = 0; i < N; i++){
      if (aluno[i] == 0){
          armazena++;
      }
    }
    if (armazena == N){
      printf("\nNenhuma matrícula cadastrada\n");
      break;
    }
    else
      {
        printf("\nMatriculas cadastradas\n");
        for (i = 0; i < N; i++)
        {
          printf("Aluno com matrícula: %d\n", aluno[i]);
          printf("Faltas: %d\n", faltas[i]);
          printf("Nota 1: %.2lf\n", nota[i][0]);
          printf("Nota 2: %.2lf\n", nota[i][1]);
          printf("Nota 3: %.2lf\n", nota[i][2]);
          printf("Nota 4: %.2lf\n", nota[i][3]);
          printf("Média: %.2lf\n", media[i]);
        }
      }
    break;
    
  case 5:
    for (i = 0; i < N; i++){
      if (aluno[i] == 0){
          armazena++;
      }
    }
    if (armazena == N){
      printf("\nNenhuma matrícula cadastrada\n");
    }
      break;
    
    for (i = 0; i < N; i++){
      media[i] = (nota[i][0] + nota[i][1] + nota[i][2] + nota[i][3]) / 4.0;
      if (media[i] >= 7.0 && faltas[i] < 14) {
        printf("Aluno com matrícula: %d, aprovado com média %.2lf.\n", aluno[i], media[i]);
        flag = 1;
      }
    }
    if (flag != 1){
      printf("\nNenhum aluno aprovado\n");
    }
    break;

  case 6:
    for (i = 0; i < N; i++){
      if (aluno[i] == 0){
          armazena++;
      }
    }
    if (armazena == N){
      printf("\nNenhuma matrícula cadastrada\n");
    }
    
    for (i = 0; i < N; i++) {
      if (media[i] < 7.0) {
        printf("\nMédia: %.2lf\n", media[i]);
        printf("Aluno com matrícula: %d, reprovado por não atingir a média 7.0.\n", aluno[i]);
        flag = 1;
      }
    }
    break;
      if (flag != 1){
      printf("\nNenhum aluno reprovado!\n");}
    break;

  case 7:
    for (i = 0; i < N; i++) { 
      if (aluno[i] == 0) {
          armazena++;
        }
      }
      if (armazena == N) { 
        printf("\nNenhuma matrícula cadastrada\n");
      }
      break;
    
    for (i = 0; i < N; i++) {
      if (faltas[i] > 14) {
        printf("\nAluno com matrícula: %d, reprovado por ter %d faltas\n", aluno[i], faltas[i]);
        flag = 1;
      }
    }
    break;
    
    if (flag != 1){
      printf("\nNenhum aluno reprovado por falta!\n");
    }
    
    break;

  case 8:
    printf("\nEscolheu sair!");
    break;
    } 
  } while (opcao != 8);
  return 0;
}

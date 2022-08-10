#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int N = 2;

int main() {

  int opcao, i, m = 0, ma = 0, mat = 0, armazena = 0, x, checar = 0, checar1 = 0, falta, indice;
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
    
    media[i] = (nota[i][0] + nota[i][1] + nota[i][2] + nota[i][3]) / 4.0;
    
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
          checar = 1;
        }
      }
    
      if (checar == 1){
        for (i = 0; i < N; i++){
          if (m == aluno[i])
          {
            aluno[i] = 0;
            nota[i][0] = 0;
            nota[i][1] = 0;
            nota[i][2] = 0;
            nota[i][3] = 0;
            media[i] = 0;
            faltas[i] = 0;
            
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
        checar1 = 1;
        indice = i;
      }
    }    
    if (checar == 1){
      printf("Digite a 1º nota: \n");
        scanf("%lf", &nota[indice][0]);
        if (nota[indice][0] < 0 || nota[indice][0] > 10){
          printf("Nota inválida - Exemplo: 0 < nota < 10\n");
        }
      printf("Digite a 2º nota: \n");
      scanf("%lf", &nota[indice][1]);
        if (nota[indice][1] < 0 || nota[indice][1] > 10){
          printf("Nota inválida - Exemplo: 0 < nota < 10\n");
        }
      printf("Digite a 3º nota: \n");
      scanf("%lf", &nota[indice][2]);
        if (nota[indice][2] < 0 || nota[indice][2] > 10){
          printf("Nota inválida - Exemplo: 0 < nota < 10\n");
        }
      printf("Digite a 4º nota: \n");
      scanf("%lf", &nota[indice][3]);
        if (nota[indice][3] < 0 || nota[indice][3] > 10){
          printf("Nota inválida - Exemplo: 0 < nota < 10\n");
        }
        printf("Insira as faltas");
        scanf("%d", &faltas[indice]);
        if (faltas[indice] > 36 || faltas[indice] < 0){
          printf("Valor de faltas inválido - Exemplo: 0 < faltas < 36\n");
        }
        media[indice] = (nota[indice][0] + nota[indice][1] + nota[indice][2] + nota[indice][3]) / 4.0;
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
          printf("%d\n", aluno[i]);
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
    
    for (i = 0; i < N; i++) {
      if (media[i] >= 7.0 && faltas[i] < 14) {
        printf("%d\n", aluno[i]);
        printf("%d\n", faltas[i]);
        printf("%lf\n", media[i]);
        checar = 1;
      }
    }
    if (checar != 1){
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
        printf("%d\n", aluno[i]);
        printf("%lf\n", media[i]);
        checar = 1;
      }
    }
    break;
      if (checar != 1){
      printf("\nNenhum aluno reprovado!\n");}
    break;

  case 7:
    
    for (i = 0; i < N; i++) {
      if (faltas[i] > 14) {
        printf("\n%d\n", aluno[i]);
        printf("\n%d\n", faltas[i]);
        checar = 1;
      }
    }
    
    break;
    
    if (checar != 1){
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

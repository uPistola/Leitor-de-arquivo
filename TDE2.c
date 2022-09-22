#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

  char arquivo_padrao[100];
  char caso[100];

  puts("Escolha uma Operação seguido pelo nome do arquivo:\nContaLetras\nConverteLetras ");

  scanf("%s %s", caso, arquivo_padrao);
  FILE *texto = fopen(arquivo_padrao, "r");

  printf("%s , %s \n", caso, arquivo_padrao);

  if(strcmp(caso, "ContaLetras") == 0){

    int contador[256] = { 0 };
    int k, c;

    while(c=fgetc(texto)) {
    if(c == EOF) break;

    contador[c]+=1;
  }

    for(k=96; k<122; k++) {
      if(contador[k] > 0) {
        printf("letra %c: %d vezes\n", k, contador[k]);
      }
    }
  }

  else if(strcmp(caso, "ConverteLetras") == 0) {

    char ch;
    char arquivo_maiuscula[40];

    puts("Insira o nome do novo arquivo");
    printf("> ConverteLetras %s ",arquivo_padrao);
    scanf_s("%s",&arquivo_maiuscula);

    FILE *fp_uppercase = fopen(arquivo_maiuscula, "w");

    if (texto == NULL)
    {
        puts("Erro ao ver o Arquivo");
    } else {
        while (ch != EOF) {
            ch = fgetc(texto);
            if((ch >= 'a') && (ch <= 'z')){
                 ch = ch - 32;
                fprintf(fp_uppercase, "%c",ch);
            }
            else if(ch > 0){
              fprintf(fp_uppercase, "%c",ch);
            }
        }
    }
    printf("%s Foi criado com Sucesso!",arquivo_maiuscula);
    fclose(fp_uppercase);
  }
  fclose(texto);
  return 0;
}
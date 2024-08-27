#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

int main() {
   char* palavra;

   FILE* arquivo = fopen("fundo_do_menu.txt", "r");
   fgets(palavra, 10, arquivo);
   fclose(arquivo);
   printf("%c\n", palavra[6]);
    if (palavra[7] == 4) {
      printf("É azul");
   }
}
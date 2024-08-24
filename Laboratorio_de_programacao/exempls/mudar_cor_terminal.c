#include <stdio.h>

// Referencia: https://en.wikipedia.org/wiki/ANSI_escape_code
int main() {
    int i, j;

    printf("\e[48;5;0m");  // Muda a cor de fundo para preto
    printf(" PRETO ");
    printf("\e[48;5;1m");  // Muda a cor de fundo para vermelho
    printf(" VERMELHO ");
    printf("\e[48;5;2m");  // Muda a cor de fundo para verde
    printf(" VERDE ");
    printf("\e[48;5;3m");  // Muda a cor de fundo para amarelo
    printf(" AMARELO ");
    printf("\e[48;5;208m");  // Muda a cor de fundo para laranja
    printf(" LARANJA ");
    printf("\e[m");         // Muda a cor para a cor padrão do terminal
    printf("\n");

    printf("\e[38;5;0m");  // Muda a cor da fonte para preto
    printf(" PRETO ");
    printf("\e[38;5;1m");  // Muda a cor da fonte para vermelho
    printf(" VERMELHO ");
    printf("\e[38;5;2m");  // Muda a cor da fonte para verde
    printf(" VERDE ");
    printf("\e[38;5;3m");  // Muda a cor da fonte para amarelo
    printf(" AMARELO ");
    printf("\e[38;5;208m");  // Muda a cor da fonte para laranja
    printf(" LARANJA ");
    printf("\e[m");         // Muda a cor para a cor padrão do terminal
    printf("\n\n");

    printf("OUTROS EXEMPLOS\n");
    printf("\\e\[38;5;13m  -> \e[38;5;13m FONTE ROSA \e[m\n");
    printf("\\e\[38;5;20m  -> \e[38;5;20m FONTE AZUL \e[m\n");
    printf("\\e\[48;5;51m\\e\[38;5;162m   -> \e[48;5;51m\e[38;5;162m FUNDO AZUL + FONTE ROSA \e[m\n");

    printf("\n\n");
    printf(">> Background <<\n\n");

    printf("Standard colors\n");
    
    for (i = 0; i <= 7; i++) {
        printf("\e[48;5;%dm", i); //muda background
        printf("%4d", i);
        printf("\e[m"); //reset no background
    }
    printf("\n\n");
    
    printf("High-intensity colors\n");
    
    for (i = 8; i <= 15; i++) {
        printf("\e[48;5;%dm", i);
        printf("%4d", i);
        printf("\e[m"); //reset 
    }
    printf("\n\n");
    
    printf("216 colors\n");
    
    for (i = 16; i <= 231; i++) {
        printf("\e[48;5;%dm", i);
        printf("%4d", i);
        printf("\e[m"); //reset  
        
        if ((i-15) % 6 == 0)
            printf("\n");
    }
    printf("\n\n");
    
    printf("Grayscale colors\n");
    
    for (i = 232; i <= 255; i++) {
        printf("\e[48;5;%dm", i);
        printf("%4d", i);
        printf("\e[m"); //reset 
    }
    printf("\n\n");
    
    printf(">> Cores de foreground <<\n\n");
    
    printf("Standard colors\n");
    
    for (i = 0; i <= 7; i++) {
        printf("\e[38;5;%dm", i); //muda foregound
        printf("%4d", i);
        printf("\e[m"); //reset no foregound
    }
    printf("\n\n");
    
    printf("High-intensity colors\n");
    
    for (i = 8; i <= 15; i++) {
        printf("\e[38;5;%dm", i);
        printf("%4d", i);
        printf("\e[m"); //reset 
    }
    printf("\n\n");
    
    printf("216 colors\n");
    
    for (i = 16; i <= 231; i++) {
        printf("\e[38;5;%dm",i); 
        printf("%4d", i);
        printf("\e[m"); //reset 

        if ((i-15) % 6 == 0)
            printf("\n");
    }
    printf("\n");
    
    printf("Grayscale colors\n");
    
    for (i = 232; i <= 255; i++) {
        printf("\e[38;5;%dm", i);
        printf("%4d", i);
        printf("\e[m"); //reset 
    }
    printf("\n");
    
    return 0;
}

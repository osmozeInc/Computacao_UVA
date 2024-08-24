#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {

        char tecla = _getch();
        if (tecla == 0)
        {
            tecla = _getch();
        }
        
    printf("%d", tecla);
}



/*   descobrir o codigo da tecla
    char tecla =  _getch();
    printf("%s", tecla);

    return 0;
*/
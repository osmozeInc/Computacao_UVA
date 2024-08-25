#include <stdio.h>

const char* CorDeFundo()
{
return "\033[44m"; 
} 

const char* CorDoTexto()
{
return "\033[90m";
}

const char* reset()
{
return "\033[0m";
} 

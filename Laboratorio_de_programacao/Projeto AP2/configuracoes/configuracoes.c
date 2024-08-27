#include <stdio.h>

const char* CorDeDestaqueMenu()
{
return "\033[44m"; 
} 

const char* CorDoTextoMenu()
{
return "\033[90m";
}

const char* reset()
{
return "\033[0m";
}
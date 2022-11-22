// Marcos Filipe Capella - PGB - Faculdade Damas
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void print_array(char *entrada)
{
    int i = 0;
    while( entrada[i] != '\0')
    {
        printf("%c",entrada[i]);
        i++;
    }
    printf("\n");
}

void encriptar(char *texto, int chave)
{
    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (islower(texto[i]))
        {
            texto[i] = (texto[i] - 97 + chave) % 26 + 97;
        }
        if (isupper(texto[i]))
        {
            texto[i] = (texto[i] - 65 + chave) % 26 + 97;
        }
        if (isdigit(texto[i]))
        {
            texto[i] = (texto[i] - 48 + chave) % 10 + 48;
        }
    }
}

int main(int argc, char const *argv[])
{
    char *frase = (char*) malloc(sizeof(char));
    int ch;

    printf("Mensagem para encriptar: ");
    scanf("%s", frase);
    print_array(frase);
    printf("Digite sua chave: ");
    scanf("%d", &ch);
    encriptar(frase, ch);
    print_array(frase);
    system("pause");
    return 0;
}

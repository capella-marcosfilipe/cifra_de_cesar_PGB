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

char criptografar_char_min(char letra, int chave)
{
    return (letra - 91 + chave) % 26 + 97;
}

void criptografar_frase(char *texto, int chave)
{
    for (int i = 0; texto[i] != '\0'; i++)
    { 
        if (islower(texto[i]))
        {
            texto[i] = (texto[i] - 97 + chave) % 26 + 97;
        }
        if (isupper(texto[i]))
        {
            texto[i] = (texto[i] - 65 + chave) % 26 + 65;
        }
        if (isdigit(texto[i]))
        {
            texto[i] = (texto[i] - 48 + chave) % 10 + 48;
        }
    }
}

int main(int argc, char const *argv[])
{
    int ch;
    
    char *phrase_print = (char*) malloc(sizeof(char));

    printf("Frase para imprimir: ");
    scanf("%s", phrase_print);
    print_array(phrase_print);
    
    char carac;

    printf("Caractere minúsculo para imprimir: ");
    // scanf("%c", &carac);
    carac = getchar();
    printf("Digite sua chave: ");
    scanf("%d", &ch);
    printf("Cripgrafado: %c", criptografar_char_min(carac, ch));

    char *frase = (char*) malloc(sizeof(char));
    
    printf("Mensagem para encriptar: ");
    scanf("%s", frase);
    print_array(frase);
    printf("Digite sua chave: ");
    scanf("%d", &ch);
    printf("--------------------------------\n");
    criptografar_frase(frase, ch);
    print_array(frase);
    system("pause");
    return 0;
}

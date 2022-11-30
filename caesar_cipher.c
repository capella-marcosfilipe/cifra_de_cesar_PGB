// Marcos Filipe Capella - PGB - Faculdade Damas
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void print_string(char *entrada)
{
    while (*entrada != '\0')
    {
        printf("%c", *entrada++);
    }
    printf("\n");
}

char criptografar_char_min(char letra, int chave)
{
    int cifra_char = letra + chave;
    if (cifra_char > 'z')
    {
        cifra_char = cifra_char - 26;
    }
    return cifra_char;
}

char descriptografar_char_min(char letra, int chave)
{
    int cifra_char = letra - chave;
    if (cifra_char < 'a')
    {
        cifra_char = cifra_char + 26;
    }
    return cifra_char;
}

char criptografar_char_mai(char letra, int chave)
{
    int cifra_char = letra + chave;
    if (cifra_char > 'Z')
    {
        cifra_char = cifra_char - 26;
    }
    return cifra_char;
}

char descriptografar_char_mai(char letra, int chave)
{
    int cifra_char = letra - chave;
    if (cifra_char < 'A')
    {
        cifra_char = cifra_char + 26;
    }
    return cifra_char;
}

char criptografar_char(char letra, int chave)
{
    if (islower(letra))
    {
        return criptografar_char_min(letra, chave);
    }
    if (isupper(letra))
    {
        return criptografar_char_mai(letra, chave);
    }
}

char descriptografar_char(char letra, int chave)
{
    if (islower(letra))
    {
        return descriptografar_char_min(letra, chave);
    }
    if (isupper(letra))
    {
        return descriptografar_char_mai(letra, chave);
    }
}

char *criptografar_frase(char *texto, int chave)
{
    for (char* quotePtr = texto; *quotePtr != '\0'; quotePtr++)
    {
        *quotePtr = criptografar_char(*quotePtr, chave);
    }
    return texto;
}

char *descriptografar_frase(char *texto, int chave)
{
    for (char* quotePtr = texto; *quotePtr != '\0'; quotePtr++)
    {
        *quotePtr = descriptografar_char(*quotePtr, chave);
    }
    return texto;
}

int main(int argc, char const *argv[])
{
    int ch;

    char *phrase_print = (char *)malloc(sizeof(char));

    printf("\033[44m Marcos Capella - PGB - Faculdade Damas \033[m\n\n");

    printf("Frase para imprimir: ");
    gets(phrase_print);
    printf("Frase digitada: ");
    print_string(phrase_print);

    char carac;

    printf("Caractere minúsculo para criptografar: ");
    fflush(stdin);
    carac = getchar();
    printf("Digite sua chave: ");
    scanf("%d", &ch);

    carac = criptografar_char_min(carac, ch);
    printf("Cripgrafado: %c\n", carac);

    carac = descriptografar_char_min(carac, ch);
    printf("Descriptografado: %c\n", carac);

    printf("Caractere maiúsculo para criptografar: ");
    fflush(stdin);
    carac = getchar();
    printf("Digite sua chave: ");
    scanf("%d", &ch);

    carac = criptografar_char_mai(carac, ch);
    printf("Criptografado: %c\n", carac);

    carac = descriptografar_char_mai(carac, ch);
    printf("Descriptografado: %c\n", carac);

    printf("Caractere maiúsculo ou minúsculo: ");
    fflush(stdin);
    carac = getchar();
    printf("Digite sua chave: ");
    scanf("%d", &ch);

    carac = criptografar_char(carac, ch);
    printf("Criptografado: %c\n", carac);

    carac = descriptografar_char(carac, ch);
    printf("Descriptografado: %c\n", carac);

    char *frase = (char *)malloc(sizeof(char));

    printf("Mensagem para criptografar: ");
    gets(frase);
    print_string(frase);
    printf("Digite sua chave: ");
    scanf("%d", &ch);
    frase = criptografar_frase(frase, ch);
    printf("Frase criptografada: %s", frase);
    printf("\n");

    frase = descriptografar_frase(frase, ch);
    printf("Frase descriptografada: %s", frase);
    printf("\n");

    printf("\033[41m FIM DO PROGRAMA \033[m\n");

    system("pause");
    return 0;
}

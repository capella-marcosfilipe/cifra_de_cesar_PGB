#include <stdio.h>
#include <ctype.h>
/*
void encriptar(char *texto[], int chave)
{
    for (int i = 0; texto[i] != "\0"; ++i)
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
*/
int main(int argc, char const *argv[])
{
    char frase[500];
    char *frasePtr = frase;
    int ch;

    printf("Mensagem para encriptar: ");
    fflush(stdin);
    scanf("%s", frasePtr);
    
    printf("Digite sua chave: ");
    fflush(stdin);
    scanf("%d", &ch);

    //encriptar(*frase, ch);
    printf("%s", frasePtr);
    return 0;
}

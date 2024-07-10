
#include <stdio.h>
#include <stdlib.h>

void write(char document_name[], char text[]) {
    FILE *file = fopen(document_name, "w");

    if (!file) {
        perror("Algo deu errado ao tentar escrever neste documento!");
        EXIT_FAILURE;
    }

    fprintf(file, text);
    fclose(file);
}

void append(char document_name[], char text[]) {

    FILE *file = fopen(document_name, "a");

    if (!file) {
        perror("Algo deu errado ao tentar incrementar textos neste documento!");
        EXIT_FAILURE;
    }

    fprintf(file, text);
    fclose(file);
}

char * read(char document_name[]) {

    FILE *file = fopen(document_name, "r");

    if (!malloc(100 * sizeof(char))) {
        perror("Algo deu errado ao tentar alocar memória para esta função!");
        EXIT_FAILURE;
    }

    if (!file) {
        perror("Algo deu errado ao tentar ler o conteúdo neste documento!");
        EXIT_FAILURE;
    }

    char * result = malloc(100 * sizeof(char));

    fgets(result, 100, file);

    fclose(file);

    return result;
}

int main() {

    write("documentação.txt", "O DanRayy gosta de Banana,");
    append("documentação.txt", " mas só a do TioStitch.");

    char * result = read("documentação.txt");

    for (int i = 0; i < 100 && result[i] != '\0'; i++) {
       printf("%c", result[i]);
    }

    free(result);

    return EXIT_SUCCESS;
}

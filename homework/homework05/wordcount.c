#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("cannot open '%s'\n", argv[1]);
        return 1;
    }

    int word_count = 0;
    int inside_word = 0;
    int current_character;

    while ((current_character = fgetc(input_file)) != EOF) {
        int is_whitespace =
            current_character == ' '  ||
            current_character == '\t' ||
            current_character == '\n' ||
            current_character == '\r' ||
            current_character == '\f' ||
            current_character == '\v';

        if (is_whitespace) {
            inside_word = 0;
        } else if (!inside_word) {
            word_count++;
            inside_word = 1;
        }
    }

    if (ferror(input_file)) {
        printf("read error while processing '%s'\n", argv[1]);
        fclose(input_file);
        return 1;
    }

    fclose(input_file);
    printf("%d\n", word_count);
}

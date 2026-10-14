#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_brainfuck(const char *code, const char *input_str) {
    unsigned char tape[2048] = {0};
    int ptr = 0;
    const char *pc = code;
    int input_idx = 0;

    while (*pc) {
        switch (*pc) {
            case '>':
                ptr = (ptr + 1) % 2048;
                break;
            case '<':
                ptr = (ptr - 1 + 2048) % 2048;
                break;
            case '+':
                tape[ptr]++;
                break;
            case '-':
                tape[ptr]--;
                break;
            case '.':
                putchar(tape[ptr]);
                break;
            case ',':
                if (input_str && input_str[input_idx] != '\0') {
                    tape[ptr] = (unsigned char)input_str[input_idx++];
                } else {
                    tape[ptr] = 0; // EOF
                }
                break;
            case '[':
                if (tape[ptr] == 0) {
                    int loop = 1;
                    while (loop > 0) {
                        pc++;
                        if (*pc == '\0') break;
                        if (*pc == '[') loop++;
                        if (*pc == ']') loop--;
                    }
                }
                break;
            case ']':
                if (tape[ptr] != 0) {
                    int loop = 1;
                    while (loop > 0) {
                        pc--;
                        if (*pc == ']') loop++;
                        if (*pc == '[') loop--;
                    }
                }
                break;
        }
        pc++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:\n");
        printf("  1) Executer code direct : %s \"<bf_code>\" [input]\n", argv[0]);
        printf("  2) Executer fichier .bf : %s -f <filename> [input]\n", argv[0]);
        return 1;
    }

    const char *code = NULL;
    const char *input_str = NULL;

    // Mode fichier (-f filename)
    if (strcmp(argv[1], "-f") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Error: missing filename after -f\n");
            return 1;
        }
        FILE *file = fopen(argv[2], "r");
        if (!file) {
            perror("Error opening file");
            return 1;
        }
        fseek(file, 0, SEEK_END);
        long length = ftell(file);
        fseek(file, 0, SEEK_SET);

        char *buffer = malloc(length + 1);
        if (buffer) {
            fread(buffer, 1, length, file);
            buffer[length] = '\0';
            code = buffer;
        }
        fclose(file);
        
        if (argc >= 4) input_str = argv[3];
    } else {
        // Mode code direct
        code = argv[1];
        if (argc >= 3) input_str = argv[2];
    }

    if (code) {
        run_brainfuck(code, input_str);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

void show_help() {
    printf("calculator shell help\n");
    printf("=====================\n");
    printf("usage:\n");
    printf("  number operator number\n\n");
    printf("operators:\n");
    printf("  +   addition\n");
    printf("  -   subtraction\n");
    printf("  *   multiplication\n");
    printf("  /   division\n\n");
    printf("commands:\n");
    printf("  --help, help   show this help message\n");
    printf("  exit, quit     exit the calculator\n\n");
    printf("examples:\n");
    printf("  3 + 4\n");
    printf("  10 / 2\n");
}

int main() {
    char line[100];
    double a, b, result;
    char op;

    printf("simple calculator shell\n");
    printf("type --help for usage\n\n");

    while (1) {
        printf("CalcSh:");

        if (!fgets(line, sizeof(line), stdin)) {
            break;
        }
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "exit") == 0 || strcmp(line, "quit") == 0) {
            printf("bye!\n");
            break;
        }

        if (strcmp(line, "--help") == 0 || strcmp(line, "help") == 0) {
            show_help();
            continue;
        }

        if (sscanf(line, "%lf %c %lf", &a, &op, &b) != 3) {
            printf("invalid command (try --help)\n");
            continue;
        }

        switch (op) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                if (b == 0) {
                    printf("error: division by zero\n");
                    continue;
                }
                result = a / b;
                break;
            default:
                printf("unknown operator (try --help)\n");
                continue;
        }

        printf("%.2f\n", result);
    }

    return 0;
}

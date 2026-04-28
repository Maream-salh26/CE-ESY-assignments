
#include <stdio.h>
#include <string.h>

#define LIMIT 25

struct AppData {
    char info[LIMIT];
    int p1;
    int p2;
    int total;
};

void start_storage(struct AppData *a) {
    a->p1 = 0;
    a->p2 = 0;
    a->total = 0;
}

void push_val(struct AppData *a, char v) {
    if (a->total < LIMIT) {
        a->info[a->p2] = v;
        a->p2 = (a->p2 + 1) % LIMIT;
        a->total++;
    }
}

char pull_val(struct AppData *a) {
    if (a->total == 0) return '\0';
    char v = a->info[a->p1];
    a->p1 = (a->p1 + 1) % LIMIT;
    a->total--;
    return v;
}

int main() {
    struct AppData my_data;
    start_storage(&my_data);

    char str_input[30];
    printf("Enter name: ");
    scanf("%s", str_input);

    strcat(str_input, "-CE-ESY");

    for (int i = 0; i < strlen(str_input); i++) {
        push_val(&my_data, str_input[i]);
    }

    printf("Output: ");
    while (my_data.total > 0) {
        printf("%c", pull_val(&my_data));
    }
    printf("\n");

    return 0;
}

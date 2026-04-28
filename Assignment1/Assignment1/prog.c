#include <stdio.h>
#include <string.h>

#define N 15

struct myBuffer {
    char data[N];
    int s;
    int e;
    int count;
};

void init(struct myBuffer *b) {
    b->s = 0;
    b->e = 0;
    b->count = 0;
}

void add(struct myBuffer *b, char c) {
    if (b->count < N) {
        b->data[b->e] = c;
        b->e = (b->e + 1) % N;
        b->count++;
    }
}

char get(struct myBuffer *b) {
    if (b->count > 0) {
        char v = b->data[b->s];
        b->s = (b->s + 1) % N;
        b->count--;
        return v;
    }
    return '\0';
}

int main() {
    struct myBuffer b;
    init(&b);
    
    char txt[] = "Maryam-CE-ESY";
    int i;
    
    for(i = 0; i < strlen(txt); i++) {
        add(&b, txt[i]);
    }
    
    printf("Result: ");
    while(b.count > 0) {
        printf("%c", get(&b));
    }
    printf("\n");
    
    return 0;
}

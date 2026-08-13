#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* covert_into_text();
size_t file_len(FILE *fp);
unsigned char* read_file_bytes(FILE *fp);

int main() {
    FILE *file = fopen("../Makefile-1", "r");

    unsigned char* buffer = read_file_bytes(file);

    size_t len = strlen(buffer);
    for (size_t i = 0; i < len;i++ ) {
        printf("%02X ", (unsigned char)buffer[i]);
    }

    scanf("No format");
    fclose(file);

    free(buffer);
    return 0;
}

unsigned char* read_file_bytes(FILE *fp) {
    const unsigned long long fl = file_len(fp);
    unsigned char* buffer = malloc(fl);
    int c;
    unsigned long long i = 0;
    while ((c=getc(fp)) != EOF) {
        buffer[i] = c;
        i++;
    }
    rewind(fp);
    return buffer;
}

size_t file_len(FILE *fp) {
    fseek(fp,0,SEEK_END);
    const size_t size = ftell(fp);
    rewind(fp);
    return size;
}
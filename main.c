#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define byte unsigned char
#define ull unsigned long long

char* covert_into_text();
size_t file_len(FILE *fp);
byte* read_file_bytes(FILE *fp);

int main() {
    FILE *file = fopen("../Makefile-1", "r");
    if (!file) {
        perror("Error when opening file");
        return 1;
    }

    byte* buffer = read_file_bytes(file);
    size_t len = strlen((char*)buffer);

    for (size_t i = 0; i < len;i++ ) {
        printf("%02X ", buffer[i]);
    }

    scanf("No format");
    fclose(file);

    free(buffer);
    return 0;
}



byte* read_file_bytes(FILE *fp) {
    const ull fl = file_len(fp);
    byte* buffer = malloc(fl + 1);
    int c; ull i = 0;
    while ((c=getc(fp)) != EOF) {
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    rewind(fp);
    return buffer;
}

size_t file_len(FILE *fp) {
    fseek(fp,0,SEEK_END);
    const size_t size = ftell(fp);
    rewind(fp);
    return size;
}
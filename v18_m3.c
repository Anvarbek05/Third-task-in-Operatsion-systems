#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    FILE *fin = fopen("input1.txt", "r");
    if (fin == NULL) {
        perror("input1.txt ochilmadi");
        return 1;
    }
    char buf[256];
    char **lines = NULL;
    int count = 0;
    while (fgets(buf, sizeof(buf), fin) != NULL) {
        buf[strcspn(buf, "\n")] = '\0';
        char **tmp = realloc(lines, (count + 1) * sizeof(char *));
        if (tmp == NULL) {
            printf("Xotira yetarli emas\n");
            break;
        }
        lines = tmp;
        lines[count] = malloc(strlen(buf) + 1);
        if (lines[count] == NULL) {
            printf("Xotira yetarli emas\n");
            break;
        }
        strcpy(lines[count], buf);
        count++;
    }
    fclose(fin);
    FILE *fout = fopen("reversed_lines.txt", "w");
    if (fout == NULL) {
        perror("reversed_lines.txt ochilmadi");
        for (int i = 0; i < count; i++) free(lines[i]);
        free(lines);
        return 1;
    }
    for (int i = count - 1; i >= 0; i--) {
        fprintf(fout, "%s\n", lines[i]);
    }
    fclose(fout);
    for (int i = 0; i < count; i++) free(lines[i]);
    free(lines);
    printf("%d ta qator teskari tartibda yozildi.\n", count);
    return 0;
}
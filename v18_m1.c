#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *ikkiMarta(const char *s) {
    size_t n = strlen(s);
    char *res = malloc(2 * n + 1);
    if (res == NULL) return NULL;
    for (size_t i = 0; i < n; i++) {
        res[2 * i] = s[i];
        res[2 * i + 1] = s[i];
    }
    res[2 * n] = '\0';
    return res;
}
int main(void) {
    char buf[256];
    printf("Satrni kiriting: ");
    if (fgets(buf, sizeof(buf), stdin) == NULL) return 1;
    buf[strcspn(buf, "\n")] = '\0';
    char *res = ikkiMarta(buf);
    if (res == NULL) {
        printf("Xotira yetarli emas\n");
        return 1;
    }
    printf("Natija: %s\n", res);
    free(res);
    return 0;
}
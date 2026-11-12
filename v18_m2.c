#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char buf[256];
    int n;
    printf("N ni kiriting: ");
    if (fgets(buf, sizeof(buf), stdin) == NULL || sscanf(buf, "%d", &n) != 1 || n <= 0) {
        printf("N noto'g'ri\n");
        return 1;
    }
    char **a = malloc(n * sizeof(char *));
    if (a == NULL) {
        printf("Xotira yetarli emas\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%d-satr: ", i + 1);
        if (fgets(buf, sizeof(buf), stdin) == NULL) buf[0] = '\0';
        buf[strcspn(buf, "\n")] = '\0';
        a[i] = malloc(strlen(buf) + 1);
        if (a[i] == NULL) {
            printf("Xotira yetarli emas\n");
            for (int j = 0; j < i; j++) free(a[j]);
            free(a);
            return 1;
        }
        strcpy(a[i], buf);
    }
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (strlen(a[i]) > strlen(a[maxIdx])) maxIdx = i;
    }
    printf("Eng uzun satr: %s (uzunligi: %zu)\n", a[maxIdx], strlen(a[maxIdx]));
    for (int i = 0; i < n; i++) free(a[i]);
    free(a);
    return 0;
}
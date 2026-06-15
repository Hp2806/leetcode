#include <stdio.h>
#include <string.h>
int f(char *s) {
    int m = 0, l = 0, v[256];
    memset(v, -1, sizeof(v));
    for (int i = 0; s[i]; i++) {
        if (v[(unsigned char)s[i]] >= l) 
            l = v[(unsigned char)s[i]] + 1;
        
        v[(unsigned char)s[i]] = i;
        int d = i - l + 1;
        if (d > m) m = d;
    }
    return m;
}
int main() {
    char s[1000];
    printf("Enter string: ");
    scanf("%s", s);
    
    printf("Length: %d\n", f(s));
    return 0;
}

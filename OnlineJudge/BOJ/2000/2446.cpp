#include <stdio.h>

int main() {
    int a;
    int i, j;

    scanf("%d", &a);
    for(i=1 ; i<=a ; i++) {
        for(j=1 ; j<=i-1 ; j++) printf(" ");
        for(j=1 ; j<=2*(a-i)+1 ; j++) printf("*");
        printf("\n");
    }
    for(i=a-1 ; i>=1 ; i--) {
        for(j=1 ; j<=i-1 ; j++) printf(" ");
        for(j=1 ; j<=2*(a-i)+1 ; j++) printf("*");
        printf("\n");
    }
}
#include <stdio.h>

main()
{
    int n, i, count=0;
    scanf("%d", &n);
    for(i=1; i<n; i++)
        if(n%i==0)
            count++;    
    printf("%d\n", count);
}

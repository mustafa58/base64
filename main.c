#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   unsigned int w : 6;
   unsigned int x : 6;
   unsigned int y : 6;
   unsigned int z : 6;
} ptr;

void yazdir(unsigned int x) {
    if(x<=25)
        printf("%c", x+'A');
    else if(x<=51)
        printf("%c", x-26+'a');
    else if(x<=61)
        printf("%c", x-52+'0');
    else if(x==62)
        printf("+");
    else if(x==63)
        printf("/");
    else printf("\0");
}

int main()
{
    int i,j,k;
    char temp;
    char buff[100];
    for(i=0;i<100;i++) buff[i]=0;
    printf("gir:");
    scanf("%s", buff);
    i = strlen(buff);
    k = 3 - i%3;
    i = k + i;
    for(j=i-1;j>=i/2;j--) {
        temp = buff[i-j-1];
        buff[i-j-1] = buff[j];
        buff[j] = temp;
    }
    ptr *bs64;
    for(j=i-3;j>0;j-=3) {
        bs64 = buff+j;
        yazdir(bs64->z);
        yazdir(bs64->y);
        yazdir(bs64->x);
        yazdir(bs64->w);
    }
    bs64 = buff+j;
    switch(k) {
    case 0:
        yazdir(bs64->z);
        yazdir(bs64->y);
        yazdir(bs64->x);
        yazdir(bs64->w);
        break;
    case 1:
        yazdir(bs64->z);
        yazdir(bs64->y);
        yazdir(bs64->x);
        printf("=");
        break;
    case 2:
        yazdir(bs64->z);
        yazdir(bs64->y);
        printf("=");
        printf("=");
        break;
    default:break;
    }
    return 0;
}

#include <stdio.h>
 
int main() {
 
    int i,m,p,n,j;
    scanf("%d",&n);
    int x[n];
    for(j=0;j<n;j++){
        scanf("%d",&x[j]);
    }
    m = x[0];
    for(i=0; i <= n; i++){
        if(x[i] < m){
            m = x[i];
            p = i;
        }
        
        
    }
    printf("Menor valor: %d\n",m);
    printf("Posicao: %d\n",p);
 
    return 0;
}
#include <cstdio>

int T;

char broj1[501];
char broj2[501];
char rez[1010];
char parc[501][501];
char parc_sz[501];
int sz1,sz2,sz_rez;
int cnt;
void obradi_broj(){
    char c;
    char znak;
    scanf("%c",&c);
    for ( int i=0;i<501;i++){
        broj1[i]=broj2[i]=0;
    }
    for ( int i=0;i<1010;i++){
        rez[i]=0;
    }
    while ( c<'0' || c>'9'){
        scanf("%c",&c);
    }
    broj1[0]=c-'0';sz1=1;
    while ( scanf("%c",&c)!=EOF && c>='0' && c<='9')
        broj1[sz1++]=c-'0';
    znak=c;
    sz2=0;
    while ( scanf("%c",&c)!=EOF && c>='0' && c<='9')
        broj2[sz2++]=c-'0';

    // invertujemo brojeve

    for ( int i=0;2*i<sz1;i++){
        char tmp=broj1[i];
        broj1[i]=broj1[sz1-1-i];
        broj1[sz1-1-i]=tmp;
    }
    for ( int i=0;2*i<sz2;i++){
        char tmp=broj2[i];
        broj2[i]=broj2[sz2-1-i];
        broj2[sz2-1-i]=tmp;
    }
    int szmax=sz1;
    if ( sz2>szmax) szmax=sz2;
    if ( znak=='+' || znak=='-'){
        char zn=1;
        char prenos=0;
        if ( znak=='-')
            zn=-1;
        for ( int i=0;i<szmax;i++){
            rez[i]=broj1[i]+zn*broj2[i]+prenos;
            prenos=0;
            if ( rez[i]>9 ){
                prenos=rez[i]/10;
                rez[i]%=10;
            }
        }
        if ( prenos!=0 || sz2>=sz1){
            rez[szmax++]=prenos;
        }
        for ( int i=0;i<szmax-sz1;i++){
            printf(" ");
        }
        for ( int i=0;i<sz1;i++){
            printf("%d",broj1[sz1-1-i]);
        }
        printf("\n");
        for ( int i=0;i<szmax-sz2-1;i++){
            printf(" ");
        }
        printf("%c",znak);
        for ( int i=0;i<sz2;i++){
            printf("%d",broj2[sz2-1-i]);
        }
        printf("\n");
        for ( int i=0;i<szmax;i++)
            printf("-");
        printf("\n");
        int prek=0;
        for ( int i=0;i<szmax;i++){
            if ( prek==0 && rez[szmax-1-i]==0 && i<szmax-1)
                printf(" ");
            else{
                printf("%d",rez[szmax-1-i]);
                prek=1;
            }
        }
        if ( cnt<T)
            printf("\n\n");
    }
    else{
        char prenos;
        for ( int i=0;i<sz2;i++){
            prenos=0;
            if ( broj2[i]==0){
                parc[i][0]=0;
                parc_sz[i]=1;
                continue;
            }
            for ( int j=0;j<sz1;j++){
                parc[i][j]=broj1[j]*broj2[i]+prenos;
                prenos=0;
                if ( parc[i][j]>9 ){
                prenos=parc[i][j]/10;
                parc[i][j]%=10;
                }
                if ( prenos!=0){
                    parc[i][sz1]=prenos;
                    parc_sz[i]=sz1+1;
                }
                else
                    parc_sz[i]=sz1;
            }
        }
        for ( int i=0;i<sz2;i++){
            /*dodajemo broj na odgovarajucu poziciju */
            char prenos=0;
            for ( int j=0;j<parc_sz[i];j++){
                rez[i+j]+=parc[i][j]+prenos;
                prenos=0;
                if ( rez[i+j]>9 ){
                    prenos=rez[i+j]/10;
                    rez[i+j]%=10;
                }
            }
            int c=0;
            while ( prenos!=0){
                rez[i+parc_sz[i]+c]+=prenos;
                prenos=0;
                if ( rez[i+parc_sz[i]+c]>9 ){
                    prenos=rez[i+parc_sz[i]+c]/10;
                    rez[i+parc_sz[i]+c]%=10;
                }
                c++;
            }
        }
        int szmax=sz1+sz2+10;
        while ( szmax>=0 && rez[szmax]==0 ){
            szmax--;
        }
        szmax++;
        if ( szmax==0){
            szmax=sz1;
            if ( szmax<=sz2)
                szmax=sz2+1;
        }

        if ( szmax==sz2)
            szmax++;
        /// ispis
        for ( int i=0;i<szmax-sz1;i++){
            printf(" ");
        }
        for ( int i=0;i<sz1;i++){
            printf("%d",broj1[sz1-1-i]);
        }
        printf("\n");
        for ( int i=0;i<szmax-sz2-1;i++){
            printf(" ");
        }
        printf("*");
        for ( int i=0;i<sz2;i++){
            printf("%d",broj2[sz2-1-i]);
        }
        printf("\n");
        for ( int i=0;i<szmax;i++)
            printf("-");
        printf("\n");
        int prek=0;
        if ( sz2>1){
        for ( int i=0;i<sz2;i++){
            for ( int j=0;j<szmax-parc_sz[i]-i;j++)
                printf(" ");
            for ( int j=0;j<parc_sz[i];j++){
                printf("%d",parc[i][parc_sz[i]-j-1]);
            }
            printf("\n");
        }
        for ( int i=0;i<szmax;i++)
            printf("-");
        printf("\n");
        }
        for ( int i=0;i<szmax;i++){
            if ( prek==0 && rez[szmax-1-i]==0 && i<szmax-1)
                printf(" ");
            else{
                prek=1;
                printf("%d",rez[szmax-1-i]);
            }
        }
        if ( cnt<T)
            printf("\n\n");
    }
}
int main(){
    scanf("%d",&T);
    for ( cnt=1;cnt<=T;cnt++){
        obradi_broj();
    }
    return 0;
}

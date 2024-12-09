#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[1001];
    long long kode;
    long long harga;
    long long stok;
}eat;


    eat kantin[1001];
    int idx = 0;
    long long earning = 0;
void add(){
        long long kode, harga, stok;
        char name[1001];
        scanf("%lld %[^\n] %lld %lld", &kode, name, &harga, &stok);
        for(int i = 0; i < idx; i++){
            if(kode == kantin[i].kode){
                printf("Menu is already exists\n");
                return;
            } 
        }

        strcpy(kantin[idx].nama, name);
        kantin[idx].kode = kode;
        kantin[idx].harga = harga;
        kantin[idx].stok = stok;

        printf("Menu added\n");
        idx++;
        return;
}

void rem(){
    long long kode;
    scanf("%lld", &kode);
    for(int i = 0; i < idx; i++){
        if(kode == kantin[i].kode){
            for(int j = i; j < idx - 1; j++){
                kantin[j] = kantin[j+1];
            }
            idx--;
            printf("Menu removed\n");
            return;
        }
    }
    printf("Menu does not exist\n");
}

void info(){
    long long kode;
    scanf("%lld", &kode);
    for(int i = 0; i<idx; i++){
        if(kode == kantin[i].kode){
            printf("#%lld %s\nPrice : Rp%lld\nStock : %lldx\n", kantin[i].kode, kantin[i].nama, kantin[i].harga, kantin[i].stok);
            return;
        }
    }

    printf("Menu does not exist\n");
    return;
} 

void order(){
    long long kode, jumlah;
    scanf("%lld %lld", &kode, &jumlah);
    if(jumlah == 0){
        printf("So you want to order or what\n");
        return;
    }
    for(int i = 0; i < idx; i++){
        if(kode == kantin[i].kode){
            if(kantin[i].stok >= jumlah){
                printf("Ordered %lldx %s for Rp%lld\n", jumlah, kantin[i].nama, kantin[i].harga * jumlah);
                earning += kantin[i].harga * jumlah;
                kantin[i].stok -= jumlah;
                return;
            } else{
                printf("Apologize, the stock is not enough\n");
                return;
            }
        }
    }
    printf("Menu does not exist\n");
    return;
}



int main()
{
    char key[10];


    while(1){
        scanf("%s", key);

        if(strcmp(key, "ADD") == 0){
            add();
        } else if(strcmp(key, "REMOVE") == 0){
            rem();
        } else if(strcmp(key, "INFO") == 0){
            info();
        } else if(strcmp(key, "ORDER") == 0){
            order();
        } else if(strcmp(key, "CLOSE") == 0){
            printf("Earnings: Rp%lld\nInformatics canteen is closing... thanks for the visit!\n", earning);
            return 0;
        }
    }
}

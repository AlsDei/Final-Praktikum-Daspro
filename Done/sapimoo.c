#include <stdio.h>
#define tagret_max 20
#define target_min 10

int main () {
    int n;

    printf("FP PROGRESS CHECKER\n");
    printf("Jumlah AC saat ini : ");
    scanf("%d", &n);

    if(n > tagret_max) {
        printf("Menuju tak teratas dan melampauinya");
    } else if (n == tagret_max) {
        printf("Wow, sepuh daspro yang sebenarnya sudah hadir nihh. CONGRATSS!!!");
    } else if (n < tagret_max && n > target_min) {
        printf("Congrats! Kamu sudah melebihi target minimal! Yuk kamu pasti bisa lanjut sampai AC semua");
    } else if (n == target_min) {
        printf("Congrats! Kamu sudah bisa menyelesaikan sampai target nilai 100. Apakah kamu akan lanjut?");
    } else if (n < target_min && n > (target_min / 2)) {
        printf("Sebentar lagi, yuk semangat!! Kamu pasti bisaa");
    } else if (n == (target_min / 2)) {
        printf("Setengah jalan!! Jangan menyerah, semangattt");
    } else if (n < (target_min / 2) && n > 0) {
        printf("Perjalananmu baru dimulai, yuk kamu pasti bisa sampai ke target nilai 100!!");
    } else if (n == 0) {
        printf("Ayo dong, teman-temanmu udah mulai. Sekarang saatnya giliranmu!!");
    } else if (n < 0) {
        printf("Inputmu yang error atau memang otakmu yang error?");
    }
    return 0;
}
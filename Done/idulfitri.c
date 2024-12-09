#include <stdio.h>
#include <math.h>

int main() {
    int code;
    int price, shipment = 50000;
    float discCode[5] = {0.35, 0.45, 0.50, 0.55, 0.40};

    scanf("%d %d", &code, &price);

    int priceAfterDisc = round(price*(discCode[code-1]));
    if(priceAfterDisc >= 50000 && priceAfterDisc < 150000) {
        shipment *= (1-0.25);
    }
    else if(priceAfterDisc >= 150000 && priceAfterDisc < 250000) {
        shipment *= (1-0.50);
    }
    else if(priceAfterDisc >= 250000) {
        shipment = 0;
    }

    int total = priceAfterDisc + shipment;
    if(total < 300000) {
        printf("WOHHHH uangku sisa %d\nMamaa Surip bisa kasi THR ke adek adek, tadi totalnya %d", 300000-total, total);
    }
    else if(total > 300000) {
        printf("Mamaa minta uang, uangku kurang %d :((\nTotalnya tadi %d", total-300000, total);
    }
    else {
        printf("Yeyyy totalnya pas 300000\nMamaa, Surip udah gede ga jadi minta uang :)");
    }
    return 0;
}
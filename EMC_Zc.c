#include <stdio.h>
#include <math.h>

#define PI 3.14159265
double angle = 0.40, result;
//result = tanh(angle);

int main()
{
    int option = 0;
    float w = 0, s = 0, epxilon = 0, h = 0;
    float Zc = 0;
    float L = 0, C = 0;
    printf("**********************************************\n");
    printf("*********       Source Vietdz        *********\n");
    printf("1: mach in nhieu lop phu dat\n");
    printf("2: Tin hieu + dat phu tren 2 mat doi dien\n");
    printf("3: Mach in di day 1 mat\n");
    printf("4: Mach in di day 2 mat\n\n");
    
    printf("Nhap de chon option: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("Nhap w: ");
        scanf("%f",&w);
        printf("Nhap s: ");
        scanf("%f", &s);
        printf("Nhap epxilon: ");
        scanf("%f", &epxilon);
        
        float We = 0;
        if ((w/s) > 0.35) {
            We = w/s;
            printf("=> We/s = %f\n", We);
        } else {
            We = (w/s) - pow((0.35-(w/s)), 2);
        }

        printf("=> We/s = %f\n", We);
        Zc = (30 * PI) / sqrt(epxilon) / (We + 0.441);
        printf("=> Zc = %f\n", Zc);
        L = Zc*sqrt(epxilon)/3;
        printf("=> L = Zc/v = Zc * sqrt(epxilon)/ Vo = %f //chia chia 10^8\n", L);
        C = L / pow(Zc, 2);
        printf("=> C = L/(Zc ^ 2) = %f //chia chia 10^8\n", C);
    }

    if (option == 2) {
        printf("Nhap w: ");
        scanf("%f",&w);
        printf("Nhap h: ");
        scanf("%f", &h);
        printf("Nhap epxilon: ");
        scanf("%f", &epxilon);

        float epxilon_phay = 0;
        epxilon_phay = (epxilon + 1) / 2 + (epxilon - 1) / 2 / sqrt(1 + 10*h/w);
        printf("=> epxilon phay = %f\n", epxilon_phay);
        if ((w/h) < 1 || (w/h) == 1) {
            Zc = 60 / sqrt(epxilon_phay) * log(8*h/w + w / 4 /h);
        } else {
            Zc = 120 *PI / sqrt(epxilon_phay) * (w/h + 1.393 + 0.667 * log(w/h + 1.4444));
        }
        printf("=> Zc = %f\n", Zc);
        L = Zc*sqrt(epxilon_phay)/3;
        printf("=> L = Zc/v = Zc * sqrt(epxilon_phay)/ Vo = %f //chua chia 10^8\n", L);
        C = L / pow(Zc, 2);
        printf("=> C = L/(Zc ^ 2) = %f //chua chia 10^8\n", C);
    }

    if (option == 3) {
        printf("Nhap w: ");
        scanf("%f",&w);
        printf("Nhap h: ");
        scanf("%f", &h);
        printf("Nhap s: ");
        scanf("%f", &s);
        printf("Nhap epxilon: ");
        scanf("%f", &epxilon);

        float k = 0, k_phay = 0;
        float epxilon_phay = 0;
        k = s / (s + 2*w);
        printf("=> k = %f \n", k);
        k_phay = sqrt(1 - pow(k, 2));
        printf("=> k_phay = %f \n", k_phay);
        epxilon_phay = (epxilon + 1 ) / 2 *((tanh(0.775 * log(h/w) + 1.75)) + (k *w) /h *(0.04 -0.7 * k + 0.01 * (1 - 0.1 *epxilon)* (0.25 + k)));
        printf("=> epxilon_phay = %f\n", epxilon_phay);
        if (k < 1 && k > sqrt(2)) {
            Zc = 120 / sqrt(epxilon_phay) * log(2 *(1 + sqrt(k)) / (1 - sqrt(k)));
        } else {
            Zc = 377 * PI / sqrt(epxilon_phay) / log(2 *(1 + sqrt(k_phay)) / (1 - sqrt(k_phay)));
        }
        printf("=> Zc = %f\n", Zc);
        L = Zc*sqrt(epxilon_phay)/3;
        printf("=> L = Zc/v = Zc * sqrt(epxilon_phay)/ Vo = %f //chua chia 10^8\n", L);
        C = L / pow(Zc, 2);
        printf("=> C = L/(Zc ^ 2) = %f //chua chia 10^8\n", C);
    }

    if (option == 4) {
        printf("Nhap w: ");
        scanf("%f",&w);
        printf("Nhap h: ");
        scanf("%f", &h);
        printf("Nhap epxilon: ");
        scanf("%f", &epxilon);  

        printf("Del tu dong hoa\n");     
    }


    return 0;
}
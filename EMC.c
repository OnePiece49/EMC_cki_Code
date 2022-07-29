#include <stdio.h>

#define SOLANLAP    11

int main()
{
    float heSoPhanXaDauDay = 0, heSoPhanXaCuoiDay = 0;
    float Vinit = 0;
    float V2 = 0;
    int option = 0;
    float heSoKhucXa = 0;

    printf("Nhap 1 de chon de 1234, Nhap 5 de chon de 5: ");
    scanf("%d", &option);
    
    printf("Nhap he so phan xa dau day: ");
    scanf("%f", &heSoPhanXaDauDay);
    printf("Nhap he so phan xa cuoi day: ");
    scanf("%f", &heSoPhanXaCuoiDay);
    if (option == 5) {
        printf("Nhap he so khuc xa truyen tu duong day 1: ");
        scanf("%f", &heSoKhucXa);
    }
    printf("Nhap Vinit: ");
    scanf("%f", &Vinit);
    printf("\n");

    if(option == 1) {     
        for (int i = 0; i < SOLANLAP; i++) {
            if (i % 2 == 0) {
                printf("+, %dTd < T < %dTd\n", i, i + 1);
                if (i == 0) {
                    printf("V2+ = Vinit = %f\n", Vinit);
                    printf(" => V2- = V2+ * nL =  %f\n", Vinit * heSoPhanXaCuoiDay);
                    V2 = V2 + Vinit + Vinit * heSoPhanXaCuoiDay;
                    Vinit = Vinit * heSoPhanXaCuoiDay;
                    printf("=> V2 = v2 + v2+ + V2- = %f\n\n\n", V2);
                }
                
                if (i != 0) {
                    printf("=> V2+ = V1- = %f\n", Vinit);
                    printf(" => V2- = %f\n", Vinit * heSoPhanXaCuoiDay);
                    V2 = V2 + Vinit + Vinit * heSoPhanXaCuoiDay;
                    Vinit = Vinit * heSoPhanXaCuoiDay;
                    printf("=> V2 = v2 + v2+ + V2- = %f\n\n\n", V2);
                }
            }   

            if (i % 2 == 1) {
                printf("+, %dTd < T < %dTd\n", i, i + 1);
                printf("V1+ = V2- = %f\n", Vinit);
                Vinit = Vinit * heSoPhanXaDauDay;
                printf("V1- = V1+ * nS = %f\n\n\n", Vinit);
            }

        }
    }

    if (option == 5) {
        for (int i = 0; i < SOLANLAP; i++) {
            if (i == 0) {
                printf("+, 0 < t < Td1\n");
                printf("Song ap %dV tre 1ns de truyen toi A(tuy de ma co the ko phai 1ns)\n", Vinit);
                printf("Tai dau duong day 1, nguon hoa hop day => he so phan xa = 0\n");
                printf(" Song Ap toi tai A: Vi1 = Vinit = %f\n\n", Vinit);
                continue;
            }

            if (i == 1) {
                printf("+, Td1 + %dTd < t < Td1 + %dTd \n", i, i + 1);
                Vinit =  Vinit * heSoKhucXa;
                printf("VC+ = Vt2 = Vi1 * T12 = %f\n", Vinit);
                if (heSoPhanXaCuoiDay == 1) {
                    printf("Vi cuoi day 2 ho mach => phan xa toan phan cuoi day.\n");
                    printf(" => VC- = VC+ =  %f\n", Vinit * heSoPhanXaCuoiDay);
                } else {
                    printf("Vc- = Vc+ * nL = %f\n", Vinit * heSoPhanXaCuoiDay);
                }

                V2 = V2 + Vinit + Vinit * heSoPhanXaCuoiDay;
                Vinit = Vinit * heSoPhanXaCuoiDay;
                printf("=> VC = VC + VC+ + VC- = %f\n\n\n", V2);       
                continue;                 
            }

            if (i % 2 == 1) {
                printf("+, Td1 + %dTd < t < Td1 + %dTd \n", i, i + 1);
                printf("VC+ = Vr2 = %f\n", Vinit);
                if (heSoPhanXaCuoiDay == 1)
                    printf(" => VC- = VC+ =  %f\n", Vinit * heSoPhanXaCuoiDay);
                else {
                    printf("Vc- = Vc+ * nL = %f\n", Vinit * heSoPhanXaCuoiDay);
                }
                V2 = V2 + Vinit + Vinit * heSoPhanXaCuoiDay;
                Vinit = Vinit * heSoPhanXaCuoiDay;
                printf("=> VC = VC + VC+ + VC- = %f\n\n\n", V2);
            }
            

            if (i % 2 == 0) {
                printf("+, Td1 + %dTd < t < Td1 + %dTd \n", i, i + 1);
                printf("=> Vi2 = VC- = %f\n", Vinit);
                Vinit = Vinit * heSoPhanXaDauDay;
                printf(" => Vr2 = Vi2 * n21 = %f\n\n\n", Vinit);
            }

        }        
    }
}
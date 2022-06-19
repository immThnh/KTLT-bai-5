#include<stdio.h>
#include<iostream>
#include<string.h>
#define MAX 100
struct SINHVIEN
{
    char name[21];
    char mssv[11];
    char lop[11];
} SV;

void Nhap(SV &sv)
{
    printf("Ten: ");
    gets(sv.name);

    printf("MS: ");
    gets(sv.mssv);

    printf("Lop: ");
    gets(sv.lop);
}

void Nhap_ds(SV sv[], int n)
{
    printf("\t\t\tNHAP THONG TIN CHO DANH SACH SINH VIEN\n");
    for(int i = 0; i < n; i++)
    {
        printf("\tSINH VIEN THU %d\n", i + 1);
        Nhap(sv[i]);
    }
}

void Xuat(SV sv)
{
    printf("%-20s %-10s %-15s\n", sv.name, sv.mssv, sv.lop);
}

void Xuat_ds(SV sv[], int n)
{
    printf("\t\t\tXUAT DANH SACH SINH VIEN\n");
    printf("%-20s %-10s %-15s\n", "Ten", "Ma So", "Lop");
    for(int i = 0; i < n; i++)
    {
        Xuat(sv[i]);
    }
}
void luu_File_TXT(SV sv[], int n, FILE *f)
{
    if(f != NULL)
    {
        fprintf(f, "So luong sinh vien: %d\n", n);
        fprintf(f, "%-20s %-10s %-15s\n", "Ten", "Ma So", "Lop");
        for(int i = 0; i < n; i++)
        {
            fprintf(f, "%-20s %-10s %-15s\n", sv[i].name, sv[i].mssv, sv[i].lop);     
        }
    }
}

void Luu_File_DAT(SV sv[], int n, FILE *f)
{
    if(f != NULL)
    {
        for(int i = 0; i < n; i++)
            fread(&sv[i], sizeof(sv[i]), 1, f);
    }
}

void sap_xep_theo_ma(SV sv[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strcmp(sv[i].mssv, sv[j].mssv) > 0)
            {
                SV c = sv[i];
                sv[i] = sv[j];
                sv[j] = c;
            }
        }
    }
}

// void Tim_Kiem_Nhi_Phan(SV sv[], int n)
// {
//     while()
// }
int main()
{
    int n;
    SV sv[MAX];
    FILE* f, *f1;
    f = fopen("dssv.txt", "w+");
    f1 = fopen("dssv.dat", "a + b");
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    fflush(stdin);

    Nhap_ds(sv, n);
    Xuat_ds(sv, n);
    luu_File_TXT(sv, n, f);

    printf("\t\t\tDANH SACH SAU KHI SAP XEP THEO MA!\n");

    Xuat_ds(sv, n);


    return 0;
}

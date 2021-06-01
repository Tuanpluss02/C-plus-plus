#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int maSV;
  char ten[20], ns[20];
  float monA, monB, monC;
  float tong;
} SV;

int n;
SV arr[50];

void TongDiem(SV *sv);      //Hàm tính tổng điểm 3 môn
void nhap(SV *sv);          //Hàm nhập thông tin của 1 sinh viên
void nhapN(SV a[], int n);  //Hàm nhập thông tin của n sinh viên
void SapXep(SV a[], int n); //Hàm sắp xếp tổng điểm tăng dần của n sinh viên
void xuat(SV sv);           //Hàm xuất thông tin của 1 sinh viên
void xuatN(SV a[], int n);  //Hàm xuất thông tin của n sinh viên

int main()
{
  scanf("%d", &n);
  nhapN(arr, n);
  SapXep(arr, n);
  xuatN(arr, n);
  system("pause");
}
void TongDiem(SV *sv)
{
  sv->tong = sv->monA + sv->monB + sv->monC;
}

void nhap(SV *sv)
{
  fflush(stdin);
  gets(sv->ten);
  fflush(stdin);
  gets(sv->ns);
  fflush(stdin);
  scanf("%f%f%f", &sv->monA, &sv->monB, &sv->monC);
  TongDiem(sv);
}

void nhapN(SV a[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    a[i].maSV = i + 1;
    nhap(a + i);
  }
}

void SapXep(SV a[], int n)
{
  SV temp;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (a[i].tong < a[j].tong)
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}

void xuat(SV sv)
{
  printf("%s ", sv.ten);
  printf("%s ", sv.ns);
  fflush(stdin);
  printf("%.1f", sv.tong);
}

void xuatN(SV a[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    if (a[i].tong == a[0].tong)
    {
      printf("%d ", a[i].maSV);
      xuat(a[i]);
      printf("\n");
    }
  }
}

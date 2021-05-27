#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int maSV;
  char ten[20];
  float monA, monB, monC;
  float tong;
} SV;

int n;
int vitri;
int funtion;
SV arr[20];

void TongDiem(SV *sv);      //Hàm tính tổng điểm 3 môn
void nhap(SV *sv);          //Hàm nhập thông tin của 1 sinh viên
void nhapN(SV a[], int n);  //Hàm nhập thông tin của n sinh viên
void SapXep(SV a[], int n); //Hàm sắp xếp tổng điểm tăng dần của n sinh viên
void xuat(SV sv);           //Hàm xuất thông tin của 1 sinh viên
void xuatN(SV a[], int n);  //Hàm xuất thông tin của n sinh viên
void capnhat(int vitri);    //Hàm cập nhật thông tin của 1 sinh viên
int main()
{
  int funtion;
  while (1)
  {
    scanf("%d", &funtion);
    switch (funtion)
    {
    case 1:
      scanf("%d", &n);
      nhapN(arr, n);
      printf("%d\n", n);
      break;
    case 2:
      scanf("%d", &vitri);
      capnhat(vitri);
      printf("%d\n", vitri);
      break;
    case 3:
      SapXep(arr, n);
      xuatN(arr, n);
      break;
      system("pause");
      return 0;
    }
  }
}

void TongDiem(SV *sv)
{
  sv->tong = sv->monA + sv->monB + sv->monC;
}

void nhap(SV *sv)
{
  fflush(stdin);
  fgets(sv->ten, 19, stdin);
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
      if (a[i].tong > a[j].tong)
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
  printf("%.1f %.1f %.1f ", sv.monA, sv.monB, sv.monC);
}

void xuatN(SV a[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    printf("%d ", a[i].maSV);
    xuat(a[i]);
    printf("\n");
  }
}
void capnhat(int vitri)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i].maSV == vitri)
    {
      nhap(arr + i);
      break;
    }
  }
}

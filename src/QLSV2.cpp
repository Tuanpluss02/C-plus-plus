#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int maSV;
  char ten[20];
  float monA, monB, monC;
  int key;

} SV;

int n;
int vitri;
int funtion;
SV arr[20];

void nhap(SV *sv);          //Hàm nhập thông tin của 1 sinh viên
void SapXep(SV a[], int n); //Hàm sắp xếp tổng điểm tăng dần của n sinh viên
void xuat(SV sv);           //Hàm xuất thông tin của 1 sinh viên
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
      for (int i = 0; i < n; ++i)
      {
        arr[i].maSV = i + 1;
        nhap(arr + i);
      }
      printf("%d\n", n);
      break;

    case 2:
      scanf("%d", &vitri);
      capnhat(vitri);
      printf("%d\n", vitri);
      break;

    case 3:
      for (int i = 0; i < n; ++i)
      {
        if (arr[i].key == 1)
        {
          printf("%d ", arr[i].maSV);
          xuat(arr[i]);
          printf("\n");
        }
      }
      break;

      return 0;
    }
    if (funtion == 3)
      break;
  }
  system("pause");
}

void nhap(SV *sv)
{
  char s[100];
  gets(s);
  fflush(stdin);
  gets(sv->ten);
  scanf("%f%f%f", &sv->monA, &sv->monB, &sv->monC);
  if (sv->monA < sv->monB && sv->monB < sv->monC)
  {
    sv->key = 1;
  }
  else
  {
    sv->key = 0;
  }
}

void xuat(SV sv)
{
  printf("%s ", sv.ten);
  printf("%.1f %.1f %.1f ", sv.monA, sv.monB, sv.monC);
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
// 1
// 2
// nguyen van hai
// 8.5 5.5 7.5
// tran van tuan
// 8.5 .50 9.0
// 2
// 2
// tran van nam
// 5.5 6.0 8.0
// 3
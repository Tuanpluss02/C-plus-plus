#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int mahang;
  char ten[50], nhom[20];
  float giamua, giaban;
  float loinhuan;
} MH;

int n;
MH arr[50];

void nhap(MH *mh);
void nhapN(MH a[], int n);
void SapXep(MH a[], int n);
void xuat(MH mh);
void xuatN(MH a[], int n);

int main()
{
  scanf("%d", &n);
  nhapN(arr, n);
  SapXep(arr, n);
  xuatN(arr, n);
  system("pause");
}

void nhap(MH *mh)
{
  char s[100];
  gets(s);
  fflush(stdin);
  gets(mh->ten);
  fflush(stdin);
  gets(mh->nhom);
  scanf("%f%f", &mh->giamua, &mh->giaban);
  mh->loinhuan = mh->giaban - mh->giamua;
}

void nhapN(MH a[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    a[i].mahang = i + 1;
    nhap(a + i);
  }
}

void SapXep(MH a[], int n)
{
  MH temp;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (a[i].loinhuan < a[j].loinhuan)
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}

void xuat(MH mh)
{
  // fflush(stdin);
  printf("%d %s %s %.2f", mh.mahang, mh.ten, mh.nhom, mh.loinhuan);
}

void xuatN(MH a[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    xuat(a[i]);
    printf("\n");
  }
}
// 3
// May tinh SONY VAIO
// Dien tu
// 16400
// 17699
// Tu lanh Side by Side
// Dien lanh
// 18300
// 25999
// Banh Chocopie
// Tieu dung
// 27.5
// 37
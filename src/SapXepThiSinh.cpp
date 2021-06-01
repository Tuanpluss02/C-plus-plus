#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int maSV;
  char ten[20], ns[20];
  float mon1, mon2, mon3, tong;
} SV;

int sort(const void *a, const void *b)
{
  SV *data_1 = (SV *)a;
  SV *data_2 = (SV *)b;
  return (data_1->tong - data_2->tong);
}
void SapXep(SV a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (a[i].tong < a[j].tong)
      {
        SV temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}

void nhap(SV *p)
{
  fflush(stdin);
  gets(p->ten);
  fflush(stdin);
  gets(p->ns);
  scanf("%f%f%f", &p->mon1, &p->mon2, &p->mon3);
  p->tong = p->mon1 + p->mon2 + p->mon3;
}
void xuat(SV p)
{
  printf("%d %s %s %.1f", p.maSV, p.ten, p.ns, p.tong);
}
int main()
{
  SV arr[50];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    arr[i].maSV = i + 1;
    nhap(arr + i);
  }
  // qsort(arr, n, sizeof(SV), sort);
  SapXep(arr, n);
  for (int i = 0; i < n; i++)
  {
    xuat(arr[i]);
    printf("\n");
  }
  system("pause");
  return 0;
}
// 3
// Nguyen Van A
// 12/12/1994
// 3.5
// 7.0
// 5.5
// Nguyen Van B
// 1/9/1994
// 7.5
// 9.5
// 9.5
// Nguyen Van C
// 6/7/1994
// 4.5
// 4.5
// 5.0
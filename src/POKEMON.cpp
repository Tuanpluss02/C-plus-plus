#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char ten[20];
  int da1, da2, dem;
} POKEMON;

int n, tong = 0;
POKEMON arr[50];

int TienHoa(int a, int b)
{
  int solan = 0;
  while (b - a >= 0)
  {
    solan++;
    tong++;
    b = b - a + 2;
  }
  return solan;
}

void nhap(POKEMON *p)
{
  char s[20];
  gets(s);
  fflush(stdin);
  gets(p->ten);
  fflush(stdin);
  scanf("%d%d", &p->da1, &p->da2);
  p->dem = TienHoa(p->da1, p->da2);
}

void TimMax(POKEMON arr[], int n)
{
  int max = -1;
  int key = -1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i].dem > max)
    {
      max = arr[i].dem;
      key = i;
    }
  }
  printf("%d\n", tong);
  printf("%s", arr[key].ten);
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    nhap(arr + i);
  }
  TimMax(arr, n);
  system("pause");
  return 0;
}
// 5
// Pidgey
// 12 36
// Ivysaur
// 10 63
// Charmander
// 35 96
// Pikachu
// 12 32
// Squirtle
// 15 10
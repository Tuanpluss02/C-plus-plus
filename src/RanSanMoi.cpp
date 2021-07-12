#include <bits/stdc++.h>
#include <stdlib.h>
#include "mylib.h"
#include <vector>
using namespace std;

struct ToaDo
{
  int x;
  int y;
};

int tocdo1 = 150;
int tocdo2 = 100;
int dodai = 4;
vector<ToaDo> ran;
ToaDo moi;
int score = 0;

void VeTuong();
void TaoRan();
void TaoMoi();
void VeRan();
void Choi();
void DiChuyen(int x, int y);
void RanAnMoi();
int EndGame();

int main()
{
  srand(time(NULL));
  ShowCur(0);
  Choi();
  int i = 2;
  while (i < 200)
  {
    int x = rand() % (110 - 6 + 1) + 6;
    int y = rand() % (26 - 3 + 1) + 3;
    ShowCur(0);
    gotoXY(x, y);
    SetColor(i++);
    cout << "Non";
    Sleep(10);
  }
  _getch();
  return 0;
}

void Choi()
{
  VeTuong();
  TaoRan();
  TaoMoi();
  int event = 4;
  int x = ran[0].x;
  int y = ran[0].y;
  while (true)
  {
    gotoXY(ran[dodai].x, ran[dodai].y);
    cout << " ";
    gotoXY(55, 1);
    SetColor(6);
    cout <<" Score: " <<score;
    VeRan();
    //------- Di chuyen----------
    if (_kbhit())
    {
      char c = _getch();
      if (c == -32)
      {
        c = _getch();
      }
      if (c == 72 && event != 2) // lên
      {
        event = 1;
      }
      else if (c == 80 && event != 1) // xuống
      {
        event = 2;
      }
      else if (c == 75 && event != 4) // sang trái
      {
        event = 3;
      }
      else if (c == 77 && event != 3) // sang phải
      {
        event = 4;
      }
    }
    if (event == 1)
    {
      y--;
    }
    else if (event == 2)
    {
      y++;
    }
    else if (event == 3)
    {
      x--;
    }
    else if (event == 4)
    {
      x++;
    }

    //------ Bien ----------
    if (x == 110)
    {
      x = 7;
    }
    else if (x == 7)
    {
      x = 110;
    }

    if (y == 27)
    {
      y = 3;
    }
    else if (y == 3)
    {
      y = 26;
    }

    if (EndGame())
    {
      system("cls");
      return;
    }

    RanAnMoi();
    DiChuyen(x, y);
    //------ Toc do ---------
    if (event == 3 || event == 4)
    {
      Sleep(tocdo2);
    }
    else
    {
      Sleep(tocdo1);
    }
  }
}

void TaoMoi()
{
  SetColor(6);
  moi.x = rand() % (109 - 7 + 1) + 7;
  moi.y = rand() % (24 - 4 + 1) + 4;
  gotoXY(moi.x, moi.y);
  cout << "$";
}

void RanAnMoi()
{
  if (ran[0].x == moi.x && ran[0].y == moi.y)
  {
    score += 5;
    tocdo1 -= 5;
    tocdo2 -= 5;
    dodai++;
    TaoMoi();
  }
}

int EndGame()
{
  for (int i = 1; i <= dodai; i++)
  {
    if (ran[i].x == ran[0].x && ran[i].y == ran[0].y)
    {
      return 1;
    }
  }
  return 0;
}

void DiChuyen(int x, int y)
{
  for (int i = dodai; i > 0; i--)
  {
    ran[i].x = ran[i - 1].x;
    ran[i].y = ran[i - 1].y;
  }
  ran[0].x = x;
  ran[0].y = y;
}

void VeTuong()
{
  SetColor(11);
  for (int i = 6; i <= 111; i++)
  {
    gotoXY(i, 2);
    cout << "+";
    gotoXY(i, 27);
    cout << "+";
  }
  for (int i = 3; i <= 26; i++)
  {
    gotoXY(6, i);
    cout << "+";
    gotoXY(111, i);
    cout << "+";
  }
}

void TaoRan()
{
  int x = 58;
  for (int i = 0; i < dodai; i++)
  {
    ran.push_back(ToaDo());
    ran[i].x = x--;
    ran[i].y = 14;
  }
}
void VeRan()
{
  SetColor(5);
  for (int i = 0; i < dodai; i++)
  {
    gotoXY(ran[i].x, ran[i].y);
    if (i == 0)
    {
      cout << "@";
    }
    else
    {
      cout << "+";
    }
  }
}

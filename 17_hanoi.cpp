#include <stdio.h>
#include <cmath>

void hanoi(short, short, short, short);
short calcTmpStand(short, short);

long unsigned steps = 0;
int** ans;

int main() {

   short disks, begStand, tmpStand, endStand;
   disks = 8; begStand = 2, endStand = 3;
   int STEPS = std::pow(2,disks)-1;

   // int** ans = new int*[STEPS];
   // for (int i = 0; i < 2; ++i)
   //    ans[i] = new int[STEPS];

   tmpStand = calcTmpStand(begStand, endStand);
   hanoi(disks, begStand, tmpStand, endStand);
   printf("\n");

   // int* tmp = ans[0];
   // while (tmp) {
   //    printf("%d -> %d \n", tmp[0], tmp[1]);
   //    tmp++;
   // }

   return 0;
}

short calcTmpStand(short begStand, short endStand) {

   for (int i = 1; i < 4; i++)
      if (i != begStand and i != endStand) return i;
   
   // if (( begStand == 1 && endStand == 2) || (begStand == 2 && endStand == 1))
   //    return 3;

   // if ((begStand == 2 && endStand == 3) || (begStand == 3 && endStand == 2))
   //    return 1;

   // if ((begStand == 1 && endStand == 3) || (begStand == 3 && endStand == 1))
   //    return 2;
}

void hanoi(short disks, short from, short tmp, short to) 
{
   if (disks == 0) return;
   hanoi(disks-1, from, to, tmp);
   // ans[steps][0] = from; ans[steps][1] = to;
   printf("[%hd,%hd],", from, to);
   steps++;
   hanoi(disks-1, tmp, from, to);
}

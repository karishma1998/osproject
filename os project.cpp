#include<stdio.h>
#include<conio.h>

void scandisk_algorithm(int L[], int R[], int count, int limit)
{
      int array[20];
      int a = count - 1, y = count + 1, c = 0, d = 0, j;
      while(a > -1)
      { 
            printf("\na:\t%d", a);
            printf("\l[a]:\t%d", L[a]);
            array[d] = L[a];
            a--;
            d++;
      }
      array[d] = 0;
      while(y <limit + 1)
      {
            array[y] = R[c];
            c++;
            y++;
      }
      printf("\nScanning Order:\n");
      for(j = 0; j < limit + 1; j++)
      {
            printf("\n%d", array[j]);
      }
}

void division(int elements[], int limit, int disk)
{
      int count = 0, w, z, m, a;
      int L[20], R[20];
      for(count = 0; count < limit; count++)
      {
            if(elements[count] > disk)
            {
                  printf("\nBreak Position:\t%d\n", elements[count]);
                  break;
            }
      }
      printf("\nValue:\t%d\n", count);
      z = 1;
      w = 0;
      m = limit;
      L[0] = elements[0];
      printf("\nL:\t%d", L[0]);
      while(z < count)
      {
            printf("\nElement[l] value:\t%d" , elements[z]);
            L[z] = elements[z];
            printf("\nL:\t%d", L[z]);
            z++;
            printf("\nl:\t%d", z);
      }
      a = count;
      while(a < m)
      {
            R[w] = elements[a];
            printf("\nR:\t%d", R[w]);
            printf("\nElement:\t%d", elements[a]);
            w++;
            a++;
      }
      scandisk_algorithm(L, R, count, limit);
}

void sorting(int elements[], int limit)
{
      int loc, count, j, temp, small;
      for(count = 0; count < limit - 1; count++)
      {
            small = elements[count];
            loc = count;
            for(j = count + 1; j < limit; j++)
            {
                  if(small > elements[j])
                  {
                        small = elements[j];
                        loc = j;
                  }
            }
            temp = elements[loc];
            elements[loc] = elements[count];
            elements[count] = temp;
      }
}

int main()
{
      int count, disk, elements[20], limit;
      printf("Enter total number of loc:\t");
      scanf("%d", &limit);
      printf("\nEnter position of disk:\t");
      scanf("%d", &disk);
      printf("\nEnter elements of disk  queue\n");
      for(count = 0; count < limit; count++)
      {
            printf("Element[%d]:\t", count + 1);
            scanf("%d", &elements[count]);
      }
      sorting(elements, limit);
      division(elements, limit, disk);
      getch();
      return 0;
  }

#include <stdio.h>
#include <conio.h>

void main()
{
  int n;
  char A ='A',B='B',C='C';
  void hanoi (int , char ,char,char);
  printf("Enter number of disks");
  scanf("%d",&n);
  printf ("this is tower of hanoi is %d disks\n",n);
  printf("seqence is:" );
  hanoi(n,A,B,C);
  printf("\n");
  getch();
}
void hanoi (int n,char A ,char B ,char C)
{
  if(n!=0);
  {
    hanoi(n-1,A,C,B);
    printf("Move disk %d from %c to %c",n,A,C);
    hanoi(n-1,B,A,C);
  }
}

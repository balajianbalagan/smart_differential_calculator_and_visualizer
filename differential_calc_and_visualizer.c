#include <stdio.h>
#include <string.h>
#include "stack.h"

int derivativeVal(stack poly, int val)
{
  long int ans = 0;

  return ans;
}

stack parse(char str[200])
{
  char tempstr[100];
  printf("%s\n", str);
  for (int i = 0; i < strlen(str); i++)
  {
    printf("%c\n", str[i]);
    char one=str[i];
    if (one=='+' || one=='-')
    {
      // input.push(tempstr);
      // char tempstr[100] = "\0";
    }
    else
    {
      strcat(tempstr, &str[i]);
      printf("%s\n", tempstr);
    }
  }
}

int main()
{
  char str[200]="2x+3x";
//   scanf("%[^\n]%*c", str);
  parse(str);
  stack input = create();
  stack output = create();

  return 0;
}
#include <stdio.h>
#include <string.h>
#include "stack.h"

int derivativeVal(stack poly, int val)
{
  long int ans = 0;

  return ans;
}

stack parse2(char str[200])
{
  stack input;
  char *token = strtok(str, "+");
  // loop through the string to extract all other tokens
  while (token != NULL)
  {
    // printf("pushing element %s\n", token);
    push(input, token);
    token = strtok(NULL, "+");
  }
  return input;
}

int main()
{
  char str[200];
  scanf("%[^\n]%*c", str);

  stack input = create();
  stack output = create();

  input = parse2(str);
  displaystack(input);

  return 0;
}
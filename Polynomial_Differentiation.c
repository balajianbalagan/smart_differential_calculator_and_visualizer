#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "stack.h"

long long int derivative_value = 0;

void derivativeVal(int val)
{
  derivative_value += val;
}
char *differentiateterm(char *cstr)
{
  // printf("%s", cstr);
  char dstr[] = "\0";
  char dcoeffs[20], dpowers[20], cstrc[100];
  strcpy(cstrc, cstr);
  int coeff, power, dcoeff, dpower;
  char *coeffs = strtok(cstr, "x");
  coeff = atoi(coeffs);
  char *powers = strtok(cstrc, "^");
  while (powers != 0)
  {
    power = atoi(powers);
    powers = strtok(NULL, "^");
  }

  //differentiation
  dcoeff = (coeff * power);
  dpower = power - 1;
  sprintf(dcoeffs, "%d", dcoeff);
  sprintf(dpowers, "%d", dpower);
  strcat(dstr, dcoeffs);
  strcat(dstr, "x^");
  strcat(dstr, dpowers);
  // printf("\nccoeff : %d power : %d dcoeff : %s dpower : %s ", coeff, power, dcoeffs, dpowers);
  // printf("\n%s ", dstr);
  return strdup(dstr);
}

stack parse2(char str[200])
{
  stack input = create();
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
  printf("parsed stack : ");
  displaystack(input);

  while (!isEmpty(input))
  {
    // printf("\nbefore diff : %s\nafter diff : %s\n", top(input), differentiateterm(top(input)));
    // printf("\ndata entered : %s\n", );
    push(output, differentiateterm(top(input)));

    pop(input);
  }
  printf("\ndiferentiated stack : ");
  displaystack(output);
  // printf("\n%s ", differentiateterm(str));
  return 0;
}
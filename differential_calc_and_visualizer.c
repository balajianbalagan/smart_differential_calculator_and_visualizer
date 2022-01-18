#include <stdio.h>
#include "stack.h"
int main()
{
  stack s = createstack(5);
  push(s, 10);
  push(s, 20);
  displaystack(s);

  return 0;
}

#include <stdio.h>
#include <io_utils.h>

int main() {
  int a;
  int b;
  int *p = &a;
  PRINT_HEX(p);
  PRINT_HEX(&a);

  PRINT_INT(sizeof(int *));

  PRINT_INT(*p);
  PRINT_INT(a);

  int **pp = &p;
  // *pp => p;

  *p = 20;  //  <=> a = 20;
  PRINT_INT(*p);
  PRINT_INT(a);

  // 只读的指针变量 与 只读的变量的只读指针
  int *const cp = &a;
  *cp = 2; // OK
  //cp = &b; ERROR

  int const *const ccp = &a;
  // ccp = &b; ERROR
  //*ccp = 2; ERROR

  // 只读的变量指针
  int const *cp2 = &a;
  cp2 = &b; // OK
  //  *cp2 = 2 ERROR
  return 0;
}

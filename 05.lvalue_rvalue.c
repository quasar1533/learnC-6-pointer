#include <stdio.h>
#include <io_utils.h>

int main() {
  // 简单了解一下左值与右值两个术语
  // left: storage space
  // right: value
  // 编译器对于左值与右值的操作是不一样的
  // 对于左值，定位内存空间（存在例外）；对于右值，则求表达式的值
  int a;
  a = 1;

  int *p = &a;
  *p = 2;  // lvalue

  int b;
  b = *p;  // rvalue

  //exception
//  &a = 3; ERROR  &a会直接求值
//  *p + 1 = 3;  ERROR  左边也会直接求值
  int array[5] = {0};
  int *p1 = array;
  *p1++ = 3;  // ++的优先级比*要高
  PRINT_INT_ARRAY(array,5);
  *(p1 + 2) = 4;
  PRINT_INT_ARRAY(array,5);

  return 0;
}

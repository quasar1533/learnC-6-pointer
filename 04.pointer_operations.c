#include <stdio.h>
#include <io_utils.h>

int main() {
  int a = 1;
  int *p = &a;
  PRINT_INT(p);
  PRINT_INT(p + 1);
  PRINT_INT(sizeof(int));
  // 说明 指针+1 代表内存地址向后加相应的字节长度  这里int长为4

  // 升级版实验
  double b = 1;
  double *p1 = &b;
  double **pp1 = &p1;
  PRINT_INT(p1);
  PRINT_INT(p1 + 1);
  PRINT_INT(sizeof(double));
  PRINT_INT(pp1);
  PRINT_INT(pp1 + 1);
  PRINT_INT(sizeof(double *));

  // 指针的作用  在C数组上可以得到很好的体现
  int array[] = {0, 1, 2, 3, 4};
  int *p2 = array; // array就是一个指向数组首元素地址的指针，只是多了一些功能和限制  如下 ↓
  int *const array_p = array;

  PRINT_INT(*p2);
  PRINT_INT(p2[2]);
  PRINT_INT(array[2]);  // recommend
  PRINT_INT(*(p2 + 2));  // recommend
  PRINT_INT(*(2 + p2));
  PRINT_INT(2[array]);  // not recommend
  PRINT_INT(*(array + 2));

  // of course 在连续的内存中，指针是递增的
  PRINT_BOOL(p2 + 1 > p2);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io_utils.h>

// 通过swap函数例子加深对一些列体系的理解

// msvc C++ decltype(a)

// 使用指针来交换两个变量的值
void SwapInt(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// 使用string.h头文件中的 memcpy函数 配合动态内存分配来完成
void Swap(void *first, void *second, size_t size) {
  void *temp = malloc(size);
  if (temp) {
    memcpy(temp, first, size);
    memcpy(first, second, size);
    memcpy(second, temp, size);

    free(temp);
  } else {
    // code....
  }
}

// 上面的方法过于繁琐，C语言虽然不支持泛型，但可以有类似的解决办法，就是利用宏
#define SWAP(a, b, type) { type temp = a; a = b; b = temp; }

int main() {
  int a = 1, b = 0;
  SwapInt(&a, &b);
  PRINT_INT(a);
  PRINT_INT(b);
  // 如果交换两个double类型的指针,将不会奏效， 调试即可看见
  double x = 3.0, y = 4.0;
  SwapInt(&x, &y);
  PRINT_DOUBLE(x);
  PRINT_DOUBLE(y);

  // 可以使用通用类型指针来解决上述问题
  PRINT_INT(sizeof(void *));
  double x1 = 3.0, y1 = 4.0;
  Swap(&x1, &y1, sizeof(double *));
  PRINT_DOUBLE(x1);
  PRINT_DOUBLE(y1);

  // 使用宏
  SWAP(a, b, int);
  PRINT_INT(a);
  PRINT_INT(b);
  SWAP(x1, y1, double);
  PRINT_DOUBLE(x1);
  PRINT_DOUBLE(y1);

  // 使用gcc typeof运算符  typeof运算符会被替换为声明关键字！
  // 不具备可移植性
  // trick 为了避免宏替换时，和其他语句发生冲突，可以用do-while循环包装一下
#define SWAP_EXT(a, b) do { typeof(a) temp = a; a = b; b = temp; }while(0)
  a = 1;
  if (a) {
    SWAP(a, b, int)
  } else {
    puts("no swap!");
  }

  SWAP_EXT(a,b); // gcc OK  msvc ERROR
  return 0;
}

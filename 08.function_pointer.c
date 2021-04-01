#include <stdio.h>
#include <stdlib.h>
#include <io_utils.h>

// 了解函数指针与typedef
// 一些函数指针使用的例子

// 1.
int *f1(int, double);  //由于优先级 相当于 int *(f(int, double))

// 2.
int (*f2)(int, double);

// 3.
int *(*f3)(int, double);

// 4.
//int (*f4)(int ,double)[]; // ERROR

// 5.
//int (*f5)[](int, double); // ERROR  int f5[](int, double)
//int (*f5[])(int, double); // OK
// C语言每一个函数都是独一无二的，无法组成数组

// 6. 使用typedef简化定义函数指针的操作
typedef int (*Func)(int, double);

int Add(int left, double right) {
  return (int) (left + right);
}

// 7. 其他例子操作
typedef int Boolean;
typedef int (*Intptr);


void InitPointer(int **ptr, int length, int default_value) {
  *ptr = malloc(sizeof(int) * length);
  for (int i = 0; i < length; ++i) {
    (*ptr)[i] = default_value;
  }
}

int main() {
  // 查看一下函数的地址
  PRINT_HEX(&main);
  PRINT_HEX(&InitPointer);

  int a;
  int *p;
  // 定义一个函数指针，要确定类型
  void (*func)(int **ptr, int length, int default_value) = &InitPointer;

  func(&p, 10, 0); // same as (*func)(&p, 10, 0) also ↓
//  (*InitPointer)(&p, 10, 0);  // redundant

  PRINT_INT_ARRAY(p, 10);

  free(p);

  // 简化声明函数指针的操作
  Func func1 = Add;
  int result = func1(2, 3.9);
  PRINT_INT(result);

  // 其他例子
  Boolean aaa = 1;
  Intptr b = &aaa;

  // 例子，理解各种声明的意义
  // 核心，C语言，一切数据基本都有对应的指针
  {
    int aaa = 1;
    int (*(*foo)(void))[3];
    int (*a)[3];
    // declare a as pointer to array 3 of int

    // to explain above explanation see ↓
    int b = 2;
    int *p;
    p = &b;
    // declare p as a pointer to int & assigned it with address of variable b

    int ccc[3];
    int (*c)[3];
    c = &ccc;
    // now, we declare c as a pointer to an array 3 of int, and then we assigned it with address of array 3 ccc.
  }

  return 0;
}

// 例子
int (*(*foo)(void))[3];
//declare foo as pointer to function (void) returning pointer to array 3 of int
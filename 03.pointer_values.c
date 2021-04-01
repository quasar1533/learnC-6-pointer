#include <stdio.h>
#include <io_utils.h>

int *point_at_global;

// 规避野指针的出现，可以在其无用时设为NULL
void DangerousPoint() {
  int a = 1;
  point_at_global = &a;
  // code....
//  point_at_global = NULL;
}

int main() {
//  整形与整形指针是不同类的
//  int *p = 100;  Warning

//  //强制类型转换
//  int *p = (int *) 100;  // 危险操作
//  PRINT_INT(*p); // 100 不在当前程序进程内存空间范围

// 危险操作 DANGEROUS !
  int *p = (int *)0x764cd550;
  PRINT_INT(0x764cd550);
  PRINT_INT(p);
  PRINT_HEX(&p);
//  PRINT_INT(*p); // Linux下gcc编译器，每次都会变换地址空间，所以会报错，取不到

  // 空指针  未初始化指针
  int *p1 = NULL;
  if (p1) {
    // code...
  }

  // 野指针    DANGEROUS!!!  比如已经销毁的内存空间的地址指针！
  DangerousPoint();
  PRINT_INT(*point_at_global);
  return 0;
}

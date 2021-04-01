#include <stdio.h>
#include <io_utils.h>

// 一种数据类型  独立的数据类型   是数据

//int main() {
//  int a;
//  scanf("%d", &a);
//
//  int *p = &a;
//  PRINT_HEX(p);
//
//  PRINT_INT(sizeof(int *));  // 这里使用memory view查看一下即可
//
//  // 访问指针所在的地址   *是运算符，在定义时作为关键字
//  PRINT_INT(*p);
//  PRINT_INT(a);
//
//  // 套娃操作
//  int **pp = &p;
//  // *pp <=> p;
//
//  return 0;
//}



//int Add(int left, int right) {
//  return (left + right);
//}
//
//int main(void) {
//  int a = 1, b = 2;
//  Add(a, b);
//  return 0;
//}

#include <stdio.h>

int main(void) {
  int c;

  printf("EOF: %d", EOF);
  while((c = getchar()) != EOF) {
    printf("%c", c);
  }
  printf("%c - at EOF\n", c);

  return 0;
}


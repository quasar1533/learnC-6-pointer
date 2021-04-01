#include <stdio.h>
#include <stdlib.h>
#include <io_utils.h>

// 学习动态内存分配  C语言本质是静态强类型语言  变长数组一但确定，将不可再修改   不够灵活
// C语言提供了可用于动态分配内存的灵活方法  malloc函数，可以在堆区（heap）开辟内存使用
#define PLAYER_COUNT 10

// 封装动态内存分配操作
void InitPointer(int **ptr, int length, int init_value) {
  *ptr = malloc(sizeof(int) * length);
  for (int i = 0; i < length; ++i) {
    (*ptr)[i] = init_value;   // 关键点  优先级问题！！！  不要写成 *ptr[i]
  }
}

int main() {
  // 普通的数组是分配在栈区   在函数调用栈上
  // 用malloc函数开辟一块内存，存放数组
  // 使用malloc分配内存，要初始化
  int *players = malloc(sizeof(int) * PLAYER_COUNT);
  for (int i = 0; i < PLAYER_COUNT; ++i) {
    players[i] = i;
  }
  PRINT_INT_ARRAY(players, PLAYER_COUNT);
  // 堆内存不会随着函数执行完毕而释放，必须手动进行释放！
  free(players);

  // 我们来将动态分配内存操作封装一下
  int *players2;
  InitPointer(&players2, PLAYER_COUNT, 0);
  for (int i = 0; i < PLAYER_COUNT; ++i) {
    players2[i] = i;
  }
  PRINT_INT_ARRAY(players2, PLAYER_COUNT);

  // 若仅需将动态分配的内存空间置0，可以用更方便的函数calloc.
  int *players3;
  players3 = calloc(PLAYER_COUNT, sizeof(int));
  for (int i = 0; i < PLAYER_COUNT; ++i) {
    PRINT_INT(players3[i]);
  }
  free(players3);

  // 动态分配内存的目的就是动态，realloc函数可以实现这一点，随时根据需要改变分配的内存空间大小
  players2 = realloc(players2, PLAYER_COUNT * 2 * sizeof(int));
  PRINT_INT_ARRAY(players2, PLAYER_COUNT * 2);
  // 注意realloc并不会自动清零   gcc可能会做一些事
  free(players2);

  // 需要留意的细节，在机器的内存很局限时， 使用alloc家族的内存分配函数，很有可能分配到NULL空指针，因此在使用前最好先判定一下。
//  if (players) {
//    // code...
//    free(players);
//  } else {
//    //.....
//  }

  return 0;
}

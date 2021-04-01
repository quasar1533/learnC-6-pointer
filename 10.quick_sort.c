#include <stdio.h>
#include "io_utils.h"
#include <stdlib.h>
#include <time.h>

// 使用指针进行快速排序，快速排序有两种经典切分方式  快捷干练
// Lomuto partition scheme    第一次使用的
// Hoare partition scheme     这一次使用的
#define PLAYER_COUNT 20

void Swap(int *first, int *second) {
  int temp = *first;
  *first = *second;
  *second = temp;
}

void Shuffle(int *array, int length) { // 参数int *array 与 int array[]完全等价
  srand(time(NULL));

  for (int i = length - 1; i > 0; --i) {
    int random_number = rand() % i;
    Swap(array + i, array + random_number);
  }
}

int *Partition(int *low, int *high) {
  int pivot = *(low + (high - low) / 2); // to prevent overflow
  int *p = low;
  int *q = high;

  while (1) {
    while (*p < pivot) p++;
    while (*q > pivot) q--;

    if (p >= q) break;
    Swap(p++, q--);  // 交换后的移位是重要的！
  }

  return q;
}

void QuickSort(int *low, int *high) {
  if (low >= high) return;

  int *partition = Partition(low, high);
  QuickSort(low, partition);
  QuickSort(partition + 1, high);
}

int main() {
  int *players = malloc(PLAYER_COUNT * sizeof(int));
  for (int i = 0; i < PLAYER_COUNT; ++i) {
    players[i] = i;
  }
  Shuffle(players, PLAYER_COUNT);
  PRINT_INT_ARRAY(players, PLAYER_COUNT);

  QuickSort(players, players + PLAYER_COUNT - 1);
  PRINT_INT_ARRAY(players, PLAYER_COUNT);
  return 0;
}

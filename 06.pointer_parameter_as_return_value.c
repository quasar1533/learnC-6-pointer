#include <stdio.h>
#include <io_utils.h>

// use assembly to see mechanism of return value
// 使用GDB   info registers rbp 查看对应的内存地址

int SumIntArray(int array[], int length) {
  int sum = 0;
  for (int i = 0; i < length; ++i) {
    sum += array[i];
  }
  return sum;
}

// move eax [rbp-4]    eax表示32位寄存器
// 更详细的    rax/rdx表示我们通用的64位寄存器  eax/edx是其低32位 ；  rbx/rcx is same
//
// 试一试128位的寄存器
__int128 TestBigInt() {
  return 0;
}

// 看一看结构体
typedef struct {
  char *name;
  int gender;
  int age;
  char *school_name;
} Student;

Student TestStruct() {
  Student student = {"jky", 1, 24, "aaa"};
  return student;
}

// 主要目的是，可以提供函数一个指针参数，来存放所需要的函数的返回值，这样可以节约性能开销,    查看汇编指令即可发现
// 同时C语言的返回值只能有一个，有事不能满足需求，但传指针参数则可以满足这样的需求.
void SumIntArrayPro(int array[], int length, int *sum) {
  *sum = 0;
  for (int i = 0; i < length; ++i) {
    *sum += array[i];
  }
}


int main() {
  int array[] = {0, 1, 2, 3, 4};
  int sum = SumIntArray(array, 5);

  PRINT_INT(sum);

  __int128 big_int = TestBigInt();

  Student student = TestStruct();

  int sum2;
  SumIntArrayPro(array, 5, &sum2);
  return 0;
}

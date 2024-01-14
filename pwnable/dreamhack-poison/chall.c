// Name: chall.c
// Compile: gcc -o chall chall.c -no-pie -Wl,-z,relro,-z,now

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  void *chunk = NULL;
  unsigned int size;
  int idx;

  setvbuf(stdin, 0, 2, 0);
  setvbuf(stdout, 0, 2, 0);

  while (1) {
    printf("1. allocate chunk\n");
    printf("2. free chunk\n");
    printf("3. print data\n");
    printf("4. edit data\n");
    printf("> ");
    scanf("%d%*c", &idx);

    switch (idx) {
      case 1:
        printf("size: ");
        scanf("%d%*c", &size);
        chunk = malloc(size * 0x10);
        printf("data: ");
        read(0, chunk, size * 0x10 - 1);
        break;
      case 2:
        free(chunk);
        break;
      case 3:
        printf("data: %s", chunk);
        break;
      case 4:
        printf("edit: ");
        read(0, chunk, size * 0x10 - 1);
        break;
      default:
        break;
    }
  }
  
  return 0;
}

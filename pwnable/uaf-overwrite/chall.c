// Name: chall.c
// Compile: gcc chall.c -o chall -no-pie -fno-stack-protector

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Human {
  char name[0x400];
  int weight;
  long age;
  
};

struct Robot {
  char name[0x400];
  int weight;
  void (*fptr)();
};

struct Human *human;
struct Robot *robot;

void print_name() { printf("Name: %s\n", robot->name); }

void menu() {
  printf("1. Allocate Human\n");
  printf("2. View Human\n");
  printf("3. Free Human\n");
  printf("4. Allocate Robot\n");
  printf("5. View Robot\n");
  printf("6. Free Robot\n");
  printf("> ");
}

void allocate_human() {
  int sel;

  human = (struct Human *)malloc(sizeof(struct Human));

  strcpy(human->name, "Human");
  printf("Human Weight: ");
  scanf("%d", &human->weight);

  printf("Human Age: ");
  scanf("%ld", &human->age);
}

void view_human() {
  if (human == NULL)
    return;
    
  puts(" << Info - Human >>");
  printf("Name: %s\n", human->name);
  printf("Weight: %d\n", human->weight);
  printf("Age: %ld\n", human->age);
}

void free_human() {
  if (human != NULL)
    free(human);
}

void allocate_robot() {
  int sel;

  robot = (struct Robot *)malloc(sizeof(struct Robot));

  strcpy(robot->name, "Robot");
  printf("Robot Weight: ");
  scanf("%d", &robot->weight);

  if (robot->fptr == NULL)
    robot->fptr = print_name;
}

void view_robot() {
  if (robot == NULL)
    return;

  puts(" << Info - Robot >>");
  robot->fptr();
  printf("Human Weight: %d\n", robot->weight);
}

void free_robot() {
  if (robot != NULL)
    free(robot);
}

int main() {
  int idx;
  char *ptr;
  
  setvbuf(stdin, 0, 2, 0);
  setvbuf(stdout, 0, 2, 0);

  while (1) {
    menu();
    scanf("%d", &idx);
    switch (idx) {
      case 1:
        allocate_human();
        break;
      case 2:
        view_human();
        break;
      case 3:
        free_human();
        break;
      case 4:
        allocate_robot();
        break;
      case 5:
        view_robot();
        break;
      case 6:
        free_robot();
    }
  }
}

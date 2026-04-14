/*
Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to something (e.g., 100).
What value is the variable in the child process?
Answer: The value is the same as in the parent i.e 100;
What happens to the variable when both the child and parent change the value of x?
Answer: Both the parent and the child will modify the values of x in thier own stack; x is 0 in child and 9000 in parent;
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

main(int argc, char* argv[]){
  int x = 100;
  pid_t pid = fork();
  if(pid<0) {
    fprintf(stderr,"Fork failed\n");
    return;
  }
  if(pid == 0){
    printf("The value of x in child is : %d\n",x  );
    x= 0;
    printf("The value of x in child after changing is : %d\n",x  );
  }
  else {
    printf("The value of x in parent is : %d\n",x  );
    x = 9000;
    printf("The value of x in parent after changing is : %d\n",x  );
  }
}
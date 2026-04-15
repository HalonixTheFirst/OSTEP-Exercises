/*
Now write a program that uses wait() to wait for the child process to finish in the parent.
What does wait() return?
Answer: The pid of the terminated child process.
What happens if you use wait() in the child?
Answer: Wait fails and returns -1 ; Because the child has no body to wait for :(
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
  int pid = fork();
  if(pid<0){
    fprintf(stderr,"Fork Failed\n");
    exit(1);
  }
  if(pid==0){
    printf("I'm jst a kid\n");
    int k = wait(NULL);
    printf("wait returned %d in the child \n",k);
  }
  else{
    int k = wait(NULL);
    printf("wait returned %d in the parent \n",k);
  }
}
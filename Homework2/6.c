/*
Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be useful?
Answer: Waitpid(pid_t *pid , int status, int options); 
pid : of the child 
status: Stores info about the child. To know how it ended.
options : How to wait;
	0: Wait for child with this pid
	1: Wait for any child
	2: Wait for children in the same process group;
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
    sleep(2);
    printf("I'm jst a kid\n");
    int k = wait(NULL);
    printf("wait returned %d in the child \n",k);
  }
  else{
		int status;
    int k = waitpid(getpid()+1,&status,0);
    printf("wait returned %d in the parent \n",k);
  }
}
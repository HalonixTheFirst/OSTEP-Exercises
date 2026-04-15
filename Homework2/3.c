/*
Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first;
Can you do this without calling wait() in the parent?
Answer: Yes, using sleep, we can somewhat guarantee that the child will run before the parent . keyword:"somewhat";
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int done = 0;

int main(int argc, char* argv[]){
  int pid = fork();
  if(pid<0){
    fprintf(stderr,"Fork Failed\n");
    exit(1);
  }
  if(pid==0){
    printf("Hello\n");
    done=1;
  }
  else{
    sleep(1);
    printf("GoodBye\n");
  }
}
/*
Write a program that calls fork() and then calls some form of exec() to run the program /bin/ls. See if you can try all of the
variants of exec(),
including
execl(), ("Source file full path",args[]);
execle(),
execlp(), ("Source file",args[0],args[1],NULL);
execv(),
execvp(), ("Source file",args[]); args[] is a NULL terminated character array;
execvP().
Why do you think there are so many variants of the same basic call?
Answer: Some need the full file path to be specified while others just need the name of the command. Very slight differences.
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
    printf("execlp\n");
    execlp("ls","ls",NULL);
  }
  else{
    wait(NULL);
  }
  pid = fork();
  if(pid<0){
    fprintf(stderr,"Fork Failed\n");
    exit(1);
  }
  if(pid==0){
    char* args []={"ls",NULL};
    printf("execl\n");
    execl("/bin/ls",args);
  }
  else{
    wait(NULL);
  }
  pid = fork();
  if(pid<0){
    fprintf(stderr,"Fork Failed\n");
    exit(1);
  }
  if(pid==0){
    char* const args[] ={"ls",NULL};
    printf("execvp\n");
    execvp("/bin/ls",args);
  }
  else{
    wait(NULL);
  }
}
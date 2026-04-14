/*
Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process.
Can both the child and parent access the file descriptor returned by open()? Yes.
What happens when they are writing to the file concurrently, i.e., at the same time?
Answer: Both the parent and child can write concurrently.
WriteTest.txt:
Hi,This is the parent
Hi,This is the child
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
main(int argc, char* argv[]){
  int file = open("WriteTest.txt",O_CREAT | O_WRONLY | O_TRUNC ,0644);
  if(file<0) {
    fprintf(stderr,"Failed to open\n");
    exit(1);
  }
  pid_t pid = fork();
  if(pid<0){
    fprintf(stderr,"Fork Failed\n");
    exit(1);
  }
  if(pid==0){
    char* text = "Hi,This is the child\n";
    write(file,text,strlen(text));
  }
  else{
    char* text = "Hi,This is the parent\n";
    write(file,text,strlen(text));
  }
}
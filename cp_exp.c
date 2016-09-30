#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
  int fd_src,fd_des;
  char buf[128];
  int num;
//When argument num isnot 3
  if(argc!=3)
  {
    printf("The format must be:cp file_src,file_des");
    exit(EXIT_FAILURE);
  }
//ReadOnly
  if((fd_src=open(argv[1],O_RDONLY))==-1)
  {
    perror("open1");
    exit(EXIT_FAILURE);
  }
//Creat,Only Write,Cover
  if((fd_des=open(argv[2],O_CREAT|O_EXCL|O_WRONLY,0644))==-1)
  {
    perror("open2");
    exit(EXIT_FAILURE);
  }
  while((num=read(fd_src,buf,128))>0)
  {
    write(fd_des,buf,num);
  }
  close(fd_src);
  close(fd_des);
}

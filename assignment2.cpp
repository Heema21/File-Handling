#include<iostream>
using namespace std;
#include<unistd.h>
#include<fcntl.h>
#include<cstring>
#include<stdlib.h>
#include<sys/stat.h>


//module for namedpipe

int Read(char* argv[])
{ int fd1;
	
  mkfifo(argv[1],0666);
  char arr1[80],arr2[80];
  while(1)
  {
    fd1=open(argv[1],O_RDONLY);
    read(fd1,arr1,80);
    cout<<"user:"<<arr1;
    close(fd1);
    //now open to write
 /* fd1 =open(argv[1],O_WRONLY);
  fgets(arr2,80,stdin);
  write(fd1,arr2,strlen(arr2)+1);
  close(fd1);*/ 
  }
  return 0;

}

//DRIVER CODE
/*
int main(int argc,char* argv[])
{

cout<<"4,5,7 no. of arguments are valid!";
cout<<"you have entered "<<argc<<"no. of arguments"<<endl;
 if(argc==4)
{ if(strcmp(argv[2],"namedpipe")==0)
	{
		if(strcmp(argv[3],"manipulate")==0)
				{
       	int retype=namedReadfirst(argv);}
	}
	}
else if(argc==5 || argc==7)
	cout<<"compile assignment.cpp for arguments 5 and 7";
else cout<<"invalid";
 return 0;
}*/
	

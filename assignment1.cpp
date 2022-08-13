#include<iostream>
using namespace std;
#include<unistd.h>
#include<fcntl.h>
#include<cstring>
#include<stdlib.h>
#include<sys/stat.h>
/**/
int Write(char* argv[])//argv[1]=pipe name argv[2]=command argv[3]=manipulate
{
	int fd1;
	mkfifo(argv[1],0666);
	char arr1[80],arr2[80];
	while(1)
	{
		fd1=open(argv[1],O_WRONLY);
		cout<<"give ur input:";
		fgets(arr2,80,stdin);
		write(fd1,arr2,strlen(arr2)+1);
		close(fd1);
		/*fd1=open(argv[1],O_RDONLY);
		read(fd1,arr1,sizeof(arr1));
		cout<<"user1:"<<arr1;
		close(fd1);*/
	}
 return 0;
}





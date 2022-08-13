#include<iostream>
using namespace std;
#include<unistd.h>
#include<fcntl.h>
#include<cstring>
#include<stdlib.h>
#include<sys/stat.h>
#include<fstream>
int Write(char* argv[]);
int Read(char*  argv[]);
//stat 
void stat(char* f1)
{ if(strcmp(f1,"-")==0)
     {
	     cout<<"file name required";
	     exit(1);
     }
     
     struct stat sfile;
     int retype= stat(f1,&sfile);
      if(retype==-1)
      {
	      cout<<"An error occurred,system call failed"<<endl;
	      exit(1);
      }
    cout<<"file type and mode  "<<sfile.st_mode<<endl;
    cout<<"i-node no.  "<<sfile.st_ino<<endl;
    cout<<"device number  "<<sfile.st_dev<<endl;
    cout<<"no. of links   "<<sfile.st_nlink<<endl;
    cout<<"user id of the owner  "<<sfile.st_uid<<endl;
    cout<<"group id of the owner "<<sfile.st_gid<<endl;
    cout<<"size in bytes:  "<<sfile.st_size<<endl;
    cout<<"no. of disk block allocated  "<<sfile.st_blocks<<endl;
}    
//module to check file exists or not
int file_exist(char* argv[])
{   ifstream myfile;
	myfile.open(argv[1]);
	if(myfile)
             return 1;
     else return 0;
       

}
//module for unnamed pipe
   void unamedPipe(char* fname,char* fmod)
{
	char buf[512];
	char input[80],output[80];
	int ch;
	int fds[2];
	int fd1=pipe(fds);
	if(fd1==-1)
	{cout<<"error: unnamed pipe cannot be created"<<endl;
		exit(1);
	}
        else cout<<"unnamed pipe created"<<endl;    
    do{
	cout<<"write in the pipe"<<endl;
	cin>>input;
	write(fds[1],input,sizeof(input));
	read(fds[0],output,sizeof(output));
	cout<<"output   : "<<output;
	cout<<"do u want to write,if yes--1"<<endl;
    cin>>ch;
	}while(ch==1);
}
//module for creating a file
void create_file(char* argv[])
{//regular file creation
int fd1;
int ch;
if(strcmp(argv[1],"-")==0){
	cout<<"valid file name required"<<endl;
        exit(1);}

if(strcmp(argv[2],"Regular")==0)
{int fd=file_exist(argv);
	if(fd==0)
		{	
   if(strcmp(argv[4],"rdmod")==0){
	   fd1=creat(argv[1],0644);
   if(fd1==-1)
	   cout<<"error in creation:"<<endl;
   else cout<<"your new file created in read mod"<<endl;}
   else if(strcmp(argv[4],"wrmod")==0){
	   fd1=creat(argv[1],0622);
   if(fd1==-1)
	   cout<<"error in creating:"<<endl;
   else cout<<"your new file created in write mod"<<endl;}
   else if(strcmp(argv[4],"rdwrmod")==0){
	   fd1=creat(argv[1],0666);
   if(fd1==-1)
	   cout<<"error in creation";
   else cout<<"your new file created in read/write mod"<<endl;}
   else cout<<"regular file not created"<<endl;
}


else if(fd==1)
{	cout<<"file already exist,do u want to:"<<endl;
        cout<< " 1. Replace the existing file"<<endl;
	cout<<" 2. Rename the new file"<<endl;
	cin>>ch;
	if(ch==1)
{
	//unlink(argv[1]);
	int f;
	f=open(argv[1]," ");
	f.truncate(0);
	f.close();

}
       else if(ch==2)
     { 
 	cout<<"enter new name"<<endl;
	cin>>argv[1];
	fd1=creat(argv[1],0644);
        if(fd1==-1)
	   cout<<"error in creating:"<<endl;
  	 
	else cout<<"your new file created "<<endl;
	
       }	

}
}
//Named pipe creation
/*else if(strcmp(argv[2],"namedpipe")==0)
{  if(strcmp(argv[4],"null")==0)
	{
	if(mknod(argv[1],010666,0))
	{	cout<<"namedpipe created";}
	else
	{	cout<<"pipe not created";}
	}
  else cout<<"invalid arguments!!";
}
*/

//unnamed pipe
else if(strcmp(argv[2],"unnamedpipe")==0)
{ if(strcmp(argv[4],"null")==0){
     char* fmod=(char*)argv[4];
     char* fname= (char*)argv[1];
      	unamedPipe(fname,fmod);}
else cout<<"invalid arguments!!";
}
else cout<<"error in creation command";
}

//module for READING a regular file

int read_file(char* argv[])
{  int fd1;
	int fd=file_exist(argv);
	if(fd==1){
		 fd1=open(argv[1],0664);
		char* buf=new char[atoi(argv[4])];
       if(strcmp(argv[2],"Regular")==0)
       {
        if(strcmp(argv[6],"st")==0)
		lseek(fd1,atoi(argv[5]),0);
	else if(strcmp(argv[6],"cur")==0)
		lseek(fd1,atoi(argv[5]),1);
	else if(strcmp(argv[6],"end")==0)
		lseek(fd1,atoi(argv[5]),2);
	else cout<<"unsatisfied input";
     int temp = read(fd1,buf,atoi(argv[4]));
     cout<<"Temp"<<temp<<endl;
     cout<<"you read:";
     for(int i=0;i<atoi(argv[4]);i++)
     {
     		
	     cout<<buf[i];
	    // cout<<endl;
	    
     }
       }
       else cout<<"error:these arguments are not  for regular file"<<endl;
	}
       	else cout<<"file do not exist,that u want to read"<<endl;
	return fd1;
 }
  

//module for WRITING in a regular file
void write_file(char* argv[])
{
	if(strcmp(argv[2],"Regular")==0)
{	
 int fd=file_exist(argv);
 if(fd==1)
 {char* buf=new char[atoi(argv[4]) + 1];
 int fd1=open(argv[1],0622);
  cout<<"write here:"<<endl;
  cin.getline(buf, atoi(argv[4]) + 1, '@');


 if(strcmp(argv[6],"st")==0)
      lseek(fd1,atoi(argv[5]),SEEK_SET);
 else if(strcmp(argv[6],"cur")==0)
      lseek(fd1,atoi(argv[5]),SEEK_CUR);
  else if(strcmp(argv[6],"end")==0)
      lseek(fd1,atoi(argv[5]),SEEK_END);
  else cout<<"invalid input";
  write(fd1,buf,sizeof(buf));
  close(fd1);
  }
  else cout<<"error: file does not exist";
  }
else cout<<"error:these arguments are for regular only";
}



//DRIVER CODE
int main(int argc,char* argv[])
{
cout<<"4,5,7 no of arguments are valid"<<endl;	
cout<<"you have entered "<<argc<<"no. of arguments"<<endl;
 if(argc==5)  //argv[1]=fname, argv[2]=ftype, argv[3]=command, argv[4]=fmod(for named and unnamed pipe it is null).
{
 if(strcmp(argv[3],"create")==0)
    create_file(argv);}
    //read and write for regular file

 else if(argc==7) //argv[1]=fname, argv[2]=ftype, argv[3]=command ,argv[4]=no. of bits want to read ,argv[5]=position from were u want to read ,argv[6]=reference
{	    
      if(strcmp(argv[3],"read")==0)
          { int fd= read_file(argv);
             if(fd)
	     {cout<<endl;     
        	cout<<"file opened in read mod  ";}
             else cout<<"file cannot be opened in read mod  ";
 }
      else if(strcmp(argv[3],"write")==0)//argv[1]=fname,argv[2]=ftype,argv[3]=command,argv[4]=no. of bits want to write,argv[5]=from where argv[6]=reference
	      write_file(argv);
    }
else if(argc==4)
{int retype,retype2;
  int op;	
       	if(strcmp(argv[2],"namedpipe")==0)
	{
		if(strcmp(argv[3],"manipulate")==0)
				{
        cout<<"what do want to do?"<<endl;
        cout<<"	1 for write";
	cout<<"2 for read";
	cin>>op;
	if(op==1)
	{	
  	retype=Write(argv);
	if(retype!=0)
		cout<<"no write happened"<<endl;
	}
	else if(op==2){
		retype2=Read(argv);
		if(retype2!=0)
			cout<<"no read happened"<<endl;
	}
	else cout<<"choose 1 or 2"<<endl;
	}

	}
}
	
else if(argc==3)
              {
	      if(strcmp(argv[2],"stat")==0)
	      { stat(argv[1]);}
	      }	      
else cout<<"invalid arguments!";

 return 0;
}
	

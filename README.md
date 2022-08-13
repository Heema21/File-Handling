

FILE:- assignment.cpp file
Modules:
1.	void stat(char* f1):-
no. of arguments= 3
argv[1]=file name
argv[2]=command i.e stat
2.	file_exist(char* argv[])
to check whether file exist or not.
Functions calling this module:- create_file ,read_file,write_file
3.	unamedPipe(char* fname,char* fmod)
                For the manipulation of unnamed pipe.
                 Function calling this module:-create_file
4.	create_file(char* argv[])
               Creating the regular file in read, write and read/write mode.
              Creating named pipe.
              Creating unnamed pipe
             No. of arguments= 5
            argv[1]=fname, argv[2]=ftype, argv[3]=command, 
             argv[4]=fmod(for named and unnamed pipe  it is null)
5.	int read_file(char* argv[])
reading the regular file
No. of arguments:-7
argv[1]=fname, argv[2]=ftype, argv[3]=command ,argv[4]=no. of bits want to read ,argv[5]=position from were u want to read ,argv[6]=reference
6.	void write_file(char* argv[])
writing into the regular file
no. of arguments=7
argv[1]=fname,argv[2]=ftype,argv[3]=command,argv[4]=no. of bits want to write,argv[5]=from where argv[6]=reference
7.	DRIVER CODE
Calling the various modules based on no. of arguments.


FILE NAME= assignment1.cpp
module:
int namedWritefirst(char* argv[]):-
 creating the one end of the file first i.e write end and then read.
No. of arguments=4
//argv[1]=pipe name, argv[2]=command argv[3]=manipulate
 

FILENAME:- assignment2.cpp
Module:
Int namedReadfirst(char* argv[]):-
creating the read end of the pipe first then write.
No. of arguments=4
//argv[1]=pipe name, argv[2]=command argv[3]=manipulate

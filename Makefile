all: task1 task2 task3 part2_1 part2_2 part2_3 part2_4

task1:	hello_Ariel.c hello_Ariel.h main1_1.c
		gcc -o hello1 hello_Ariel.c main1_1.c

task2:	hello_Ariel.h main1_1.c lib
		gcc main1_1.c -L. -l Hello -o hello2

task3: hello_Ariel.h main1_3.c lib
	   gcc main1_3.c -fPIC -ldl -o hello3

lib:	hello_Ariel.h hello_Ariel.c 
		gcc -shared hello_Ariel.c -fPIC -o libHello.so
		
part2_1:    part2_1.o
		    gcc -Wall -g -o part2_1 part2_1.o  

part2_1.o:  part2_1.c
		    gcc -Wall -g -c part2_1.c

part2_2:    part2_2.o
		    gcc -Wall -g -o part2_2 part2_2.o	

part2_2.o:  part2_2.c
		    gcc -Wall -g -c part2_2.c

part2_3:    part2_3.o
		    gcc -Wall -g -o part2_3 part2_3.o

part2_3.o:  part2_3.c
		    gcc -Wall -g -c part2_3.c

part2_4:    part2_4.o
		    gcc -Wall -g -o part2_4 part2_4.o

part2_4.o:  part2_4.c
		    gcc -Wall -g -c part2_4.c	

.PHONY: clean

clean:
		-rm -f *.o hello1 hello2 hello3 libHello.so part2_1 part2_2 part2_3 part2_4	
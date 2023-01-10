.c.o: 
	gcc -c $<

all: pv netp

pv: pv.o csapp.o
	gcc -o pv pv.o csapp.o -lpthread
netp: netp.o csapp.o
	gcc -o netp netp.o csapp.o
clean:
	rm *.o
	rm pv
	rm netp

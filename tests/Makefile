.c.o: 
	gcc -c $<

pv: pv.o csapp.o
	gcc -o pv pv.o csapp.o -lpthread

clean:
	rm *.o
	rm pv

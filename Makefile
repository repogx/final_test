# Set a variable LDFLAGS. Use the variable as $(LDFLAGS)
# On cisc210.cis.udel.edu, add -lcurses to the below line
LDFLAGS := -L ~/lib -lsense -lm

all: compass
compass: project.h input.o output.o main.o
	cc -o compass input.o output.o  main.o -I ~/include $(LDFLAGS)

inputtest: project.h inputtest.o input.o
	cc -o -g inputtest input.o inputtest.o $(LDFLAGS)

outputtest: project.h ouputtest.o output.o
	cc -o -g outputtest output.o outputtest.o $(LDFLAGS)



%.o: %.c project.h
	cc -g -c $< -I ~/include $(LDFLAGS)
run: compass
	./compass
clean:
	rm -f *.o compass inputtest outputtest

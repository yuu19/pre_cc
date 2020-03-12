CFLAGS=-std=c11 -g -static

1st: 1st.c

test: 1st
	./test.sh

clean:
	rm -f 1st *.o *~ tmp*
.PHONY: test clean 



CFLAGS += -std=c99 -pedantic -Wall -Werror -Wextra -D_FORTIFY_SOURCE=2 -O3 -fPIC -fstack-protector-all -pie -s
.PHONY: all clean

all: permutation.a

permutation.a: permutation.o ../input/input.a
	ar cr $@ $^

%.o: %.c %.h
	$(CC) $(CPPFLAGS) -c $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f *.o *.a

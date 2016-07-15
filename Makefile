
test_list : LIST/test_list.o LIST/list.o
	gcc -o test_list LIST/*.o

test_list.o : item.h

list.o : list.h

clean :
	rm -f *.o */*.o
	rm -rf *.dSYM

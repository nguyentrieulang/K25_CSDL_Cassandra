data_gen=main
all:
	g++ nhan_khau_gen.c -o ${data_gen}
clean:
	rm -rf ${data_gen}

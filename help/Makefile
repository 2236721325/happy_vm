ASM=nasm
ASMFLAGS=-f bin
CFLAGS=-S -O0 -mllvm --x86-asm-syntax=intel  -target i386-linux-gnu demo.c


demo.s:
	rm -f demo.s
	clang -S -O0  --x86-asm-syntax=intel -target i386-linux-gnu -nobuiltininc demo.c
demo.o:
	rm -f demo.o
	gcc -m32 -fno-asynchronous-unwind-tables -s -O2 -c -o demo.o demo.c
demo_p.s:
	rm -f demo_p.s
	clang  -O0  -target i386-linux-gnu -nobuiltininc demo.c -o demo.bin
	objdump -M intel -d demo.bin > demo_p.s

.PHONY:demo.asm

demo.asm:
	rm -f demo.o
	rm -f demo.asm
	gcc -m32 -fno-pic -fno-asynchronous-unwind-tables -s -O0 -c -o demo.o demo.c
	objconv -fnasm demo.o demo.asm

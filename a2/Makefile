#This is a hack to pass arguments to the run command and probably only 
#works with gnu make. 
#You can run the fetch program by giving doing the following
# make run arg1 arg2
# where arg1 and arg2 are the arguments to the fetch program
#
ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

all: pipe

CC=gcc
CLIBS=-lc
CFLAGS=-g -Werror-implicit-function-declaration -pedantic -std=c99

SRC=decodeStage.c executeStage.c fetchStage.c instructionSpecifications.c main.c memoryStage.c printInternalReg.c writeBackStage.c
OBJ = $(SRC:.c=.o)



pipe: $(OBJ)
	$(CC) -g -o pipe $(OBJ)

depend: $(SRC)
	makedepend $(SRC)

clean:
	rm -f *.o
	rm -f pipe

.PHONY: run
run: pipe  
	./pipe $(RUN_ARGS)

# DO NOT DELETE

decodeStage.o: decodeStage.h /usr/include/sys/types.h /usr/include/features.h
decodeStage.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
decodeStage.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
decodeStage.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
decodeStage.o: /usr/include/time.h /usr/include/endian.h
decodeStage.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
decodeStage.o: /usr/include/bits/byteswap-16.h /usr/include/sys/select.h
decodeStage.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
decodeStage.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
decodeStage.o: /usr/include/bits/pthreadtypes.h instructionSpecifications.h
decodeStage.o: /usr/include/stdint.h /usr/include/bits/wchar.h executeStage.h
decodeStage.o: /usr/include/stdio.h /usr/include/libio.h
decodeStage.o: /usr/include/_G_config.h /usr/include/wchar.h
decodeStage.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
decodeStage.o: printInternalReg.h
executeStage.o: executeStage.h instructionSpecifications.h
executeStage.o: /usr/include/stdint.h /usr/include/features.h
executeStage.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
executeStage.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
executeStage.o: /usr/include/bits/wchar.h /usr/include/stdio.h
executeStage.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
executeStage.o: /usr/include/libio.h /usr/include/_G_config.h
executeStage.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
executeStage.o: /usr/include/bits/sys_errlist.h memoryStage.h
executeStage.o: printInternalReg.h
fetchStage.o: fetchStage.h /usr/include/stdio.h /usr/include/features.h
fetchStage.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
fetchStage.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
fetchStage.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
fetchStage.o: /usr/include/libio.h /usr/include/_G_config.h
fetchStage.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
fetchStage.o: /usr/include/bits/sys_errlist.h /usr/include/fcntl.h
fetchStage.o: /usr/include/bits/fcntl.h /usr/include/bits/fcntl-linux.h
fetchStage.o: /usr/include/time.h /usr/include/bits/stat.h
fetchStage.o: /usr/include/sys/types.h /usr/include/endian.h
fetchStage.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
fetchStage.o: /usr/include/bits/byteswap-16.h /usr/include/sys/select.h
fetchStage.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
fetchStage.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
fetchStage.o: /usr/include/bits/pthreadtypes.h /usr/include/sys/uio.h
fetchStage.o: /usr/include/bits/uio.h /usr/include/unistd.h
fetchStage.o: /usr/include/bits/posix_opt.h /usr/include/bits/environments.h
fetchStage.o: /usr/include/bits/confname.h /usr/include/getopt.h
fetchStage.o: /usr/include/inttypes.h /usr/include/stdint.h
fetchStage.o: /usr/include/bits/wchar.h /usr/include/stdlib.h
fetchStage.o: /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h
fetchStage.o: /usr/include/alloca.h /usr/include/bits/stdlib-float.h
fetchStage.o: /usr/include/errno.h /usr/include/bits/errno.h
fetchStage.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
fetchStage.o: /usr/include/asm-generic/errno.h
fetchStage.o: /usr/include/asm-generic/errno-base.h printInternalReg.h
fetchStage.o: instructionSpecifications.h /usr/include/sys/stat.h
fetchStage.o: /usr/include/sys/mman.h /usr/include/bits/mman.h
fetchStage.o: /usr/include/bits/mman-linux.h decodeStage.h
instructionSpecifications.o: instructionSpecifications.h
instructionSpecifications.o: /usr/include/stdint.h /usr/include/features.h
instructionSpecifications.o: /usr/include/stdc-predef.h
instructionSpecifications.o: /usr/include/sys/cdefs.h
instructionSpecifications.o: /usr/include/bits/wordsize.h
instructionSpecifications.o: /usr/include/gnu/stubs.h
instructionSpecifications.o: /usr/include/bits/wchar.h /usr/include/unistd.h
instructionSpecifications.o: /usr/include/bits/posix_opt.h
instructionSpecifications.o: /usr/include/bits/environments.h
instructionSpecifications.o: /usr/include/bits/types.h
instructionSpecifications.o: /usr/include/bits/typesizes.h
instructionSpecifications.o: /usr/include/bits/confname.h
instructionSpecifications.o: /usr/include/getopt.h
main.o: /usr/include/stdio.h /usr/include/features.h
main.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
main.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
main.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
main.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
main.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
main.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h
main.o: /usr/include/bits/fcntl-linux.h /usr/include/time.h
main.o: /usr/include/bits/stat.h /usr/include/sys/types.h
main.o: /usr/include/endian.h /usr/include/bits/endian.h
main.o: /usr/include/bits/byteswap.h /usr/include/bits/byteswap-16.h
main.o: /usr/include/sys/select.h /usr/include/bits/select.h
main.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
main.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
main.o: /usr/include/sys/uio.h /usr/include/bits/uio.h /usr/include/unistd.h
main.o: /usr/include/bits/posix_opt.h /usr/include/bits/environments.h
main.o: /usr/include/bits/confname.h /usr/include/getopt.h
main.o: /usr/include/inttypes.h /usr/include/stdint.h
main.o: /usr/include/bits/wchar.h /usr/include/stdlib.h
main.o: /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h
main.o: /usr/include/alloca.h /usr/include/bits/stdlib-float.h
main.o: /usr/include/errno.h /usr/include/bits/errno.h
main.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
main.o: /usr/include/asm-generic/errno.h
main.o: /usr/include/asm-generic/errno-base.h /usr/include/sys/stat.h
main.o: /usr/include/sys/mman.h /usr/include/bits/mman.h
main.o: /usr/include/bits/mman-linux.h printInternalReg.h
main.o: instructionSpecifications.h fetchStage.h decodeStage.h executeStage.h
main.o: memoryStage.h writeBackStage.h
memoryStage.o: memoryStage.h /usr/include/stdio.h /usr/include/features.h
memoryStage.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
memoryStage.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
memoryStage.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
memoryStage.o: /usr/include/libio.h /usr/include/_G_config.h
memoryStage.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
memoryStage.o: /usr/include/bits/sys_errlist.h instructionSpecifications.h
memoryStage.o: /usr/include/stdint.h /usr/include/bits/wchar.h
memoryStage.o: writeBackStage.h printInternalReg.h
printInternalReg.o: /usr/include/stdio.h /usr/include/features.h
printInternalReg.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
printInternalReg.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
printInternalReg.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
printInternalReg.o: /usr/include/libio.h /usr/include/_G_config.h
printInternalReg.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
printInternalReg.o: /usr/include/bits/sys_errlist.h /usr/include/unistd.h
printInternalReg.o: /usr/include/bits/posix_opt.h
printInternalReg.o: /usr/include/bits/environments.h
printInternalReg.o: /usr/include/bits/confname.h /usr/include/getopt.h
printInternalReg.o: printInternalReg.h /usr/include/stdint.h
printInternalReg.o: /usr/include/bits/wchar.h instructionSpecifications.h
writeBackStage.o: writeBackStage.h /usr/include/stdio.h
writeBackStage.o: /usr/include/features.h /usr/include/stdc-predef.h
writeBackStage.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
writeBackStage.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
writeBackStage.o: /usr/include/bits/typesizes.h /usr/include/libio.h
writeBackStage.o: /usr/include/_G_config.h /usr/include/wchar.h
writeBackStage.o: /usr/include/bits/stdio_lim.h
writeBackStage.o: /usr/include/bits/sys_errlist.h instructionSpecifications.h
writeBackStage.o: /usr/include/stdint.h /usr/include/bits/wchar.h
writeBackStage.o: printInternalReg.h

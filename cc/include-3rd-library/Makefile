LIBTEST_DIR = Library-test
# -I is the directory where to search
LIBTEST_INC = -I $(LIBTEST_DIR)
CPP = g++ -std=c++11

SRCS_CC = $(wildcard *.cc)
HEAD_H = $(wildcard *.h)
PROJECT = lib-test

# If you want your output to be updated when header files change, then you have to add it to your dependency statement.
# So HEAD_H is put to the left of below section.
$(PROJECT): $(SRCS_CC) $(HEAD_H)
	$(CPP) $(LIBTEST_INC) $(SRCS_CC) -o $@

# Generally all targets in your Makefile which do not produce an output file with the same name as the target name should be PHONY. This typically includes all, install, clean, distclean, and so on.
# If we have one file or directory named clean, 'make' will echo "make: 'clean' is up to date."
.PHONY: clean

clean:
	rm -rf $(wildcard *.o) $(PROJECT)

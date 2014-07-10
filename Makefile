all: main

%: %.c
	gcc $< -o bf.exe -Wall -Werror

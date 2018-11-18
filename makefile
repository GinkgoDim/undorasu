COM=gcc
help:
	@echo 'You can use 3 commands:'
	@echo -e '\tmake install'
	@echo -e '\tmake uninstall'
	@echo -e '\tmake debugger'
install:
	mkdir -v debug release
	$(COM) -g ./main.cpp -o ./debug/dorasuse-debug
	$(COM) ./main.cpp -o ./release/dorasuse
uninstall:
	rm -rv debug/ release/
debugger:
	gdb ./debug/dorasuse-debug -q

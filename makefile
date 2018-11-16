model=./model/*.cpp
view=./view/*.cpp
controller=./controller/*.cpp
help:
	@echo 'You can use 3 commands:'
	@echo -e '\tmake install'
	@echo -e '\tmake uninstall'
	@echo -e '\tmake debugger'
install:
	mkdir -v debug release
	g++ -g $(model) $(view) $(controller) ./main.cpp -o ./debug/dorasuse-debug
	g++ $(model) $(view) $(controller) ./main.cpp -o ./release/dorasuse
uninstall:
	rm -rv debug/ release/
debugger:
	gdb ./debug/dorasuse-debug -q

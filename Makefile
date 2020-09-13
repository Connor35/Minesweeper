CC = g++
exe_file = minesweeper

# compile: $(exe_file)

$(exe_file): main.o
	$(CC) main.o -o $(exe_file)
	@clear
	@./$(exe_file)

# Game.o: Game.cpp
# 	$(CC) -c Game.cpp

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	@echo
	@echo "Cleaning..."
	rm -f *.out *.o $(exe_file)
	@echo
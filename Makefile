.PHONY: clean run

angle_finder: angle_finder.cpp
	c++ -Os angle_finder.cpp -o angle_finder

clean:
	rm angle_finder

run: angle_finder
	./angle_finder

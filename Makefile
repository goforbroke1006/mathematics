build:
	g++ -std=c++11 -o mathematics main.cpp

run:
	./mathematics

test:
	g++ -std=c++11 -o tests_parser_test tests/parser-test.cpp && ./tests_parser_test && rm -f ./tests_parser_test
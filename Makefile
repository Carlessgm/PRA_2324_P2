compile: monedas.cpp
	g++ -o testCambio monedas.cpp

testCambio: compile
	./testCambio

clean:
	rm -f testCambio

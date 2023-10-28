compile_monedas: monedas.cpp
	g++ -o testCambio monedas.cpp

testCambio: compile_monedas
	./testCambio

compile_mochila: mochila.cpp
	g++ -o testMochila mochila.cpp

testMochila: compile_mochila
	./testMochila

clean:
	rm -f testCambio testMochila

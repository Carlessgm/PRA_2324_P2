compile_monedas: monedas.cpp
	g++ -o testCambio monedas.cpp

testCambio: compile_monedas
	./testCambio

compile_mochila: mochila.cpp
	g++ -o testMochila mochila.cpp

testMochila: compile_mochila
	./testMochila

compile_mochila_recurs: mochila_Recursivo.cpp
	g++ -o testMochila_Recursivo mochila_Recursivo.cpp

testMochila_Recursivo: compile_mochila_recurs
	./testMochila_Recursivo

clean:
	rm -f testCambio testMochila testMochila_Recursivo

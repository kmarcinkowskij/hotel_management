// Plik: main.cpp
// Autor: Antoni Maciejewski 4E
// Data: 12 grudnia 2024
// Opis: Zawiera glowna petle aplikacji i laczy ze soba pozostale pliki.

#include "Classes/App.h"

int main()
{
	const auto app = new App();
	app->run();
	delete(app);

	return 0;
}

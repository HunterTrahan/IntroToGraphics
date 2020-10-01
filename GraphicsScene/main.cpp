#include "GraphicsApp.h"

int main()
{
	GraphicsApp* app = new GraphicsApp(1280, 720, "Computer Graphics");

	app->run();

	delete app;

	return 0;
}
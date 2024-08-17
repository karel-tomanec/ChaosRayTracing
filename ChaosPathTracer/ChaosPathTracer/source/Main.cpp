#include <iostream>

#include "Renderer.hpp"

int main(int argc, char** argv)
{        
	if (argc < 2) 
	{
		std::cerr << "Usage: " << argv[0] << " <scene-file>" << std::endl;
		return 1;
	}

	try
	{
		std::string sceneFile = argv[1];
		std::unique_ptr<Scene> scene = std::make_unique<Scene>(sceneFile);

		Renderer renderer(*scene);

		auto start = std::chrono::high_resolution_clock::now();

		renderer.renderImage();

		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> duration = end - start;
		std::cout << scene->settings.sceneName + " rendering time: " << duration.count() << " seconds" << std::endl;
	} 
	catch (const std::runtime_error& e) 
	{
		std::cerr << "Runtime error: " << e.what() << std::endl;
		return 1;
	} 
	catch (const std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return 1;
	} 
	catch (...) 
	{
		std::cerr << "An unknown error occurred." << std::endl;
		return 1;
	}

	return 0;
}

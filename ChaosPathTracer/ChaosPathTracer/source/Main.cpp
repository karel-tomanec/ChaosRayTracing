#include <iostream>

#include "Renderer.hpp"

int main(int argc, char** argv)
{        
	if (argc < 2) 
	{
		std::cerr << "Usage: " << argv[0] << " <scene-file>" << std::endl;
		return 1;
	}

	std::string sceneFile = argv[1];
	std::unique_ptr<Scene> scene = std::make_unique<Scene>(sceneFile);

	Renderer renderer(*scene);

	auto start = std::chrono::high_resolution_clock::now();

	renderer.renderImage();

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;
	std::cout << scene->settings.sceneName + " rendering time: " << duration.count() << " seconds" << std::endl;

	return 0;
}

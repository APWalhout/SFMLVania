#include <iostream>
#include <SFML/Graphics.hpp>
#include <pugixml.hpp>
#include <pugiconfig.hpp>

int main()
{
	//array of resolutions to be referenced in setting xml
	const unsigned int settingResolution[8] = { 1024,576,1152,648,1280,720,1920,1080 };
	unsigned int setRes;
	//setRes = 0;

	//set up and load settings xml doc
	pugi::xml_document settingsXML;
	pugi::xml_parse_result settingsResult = settingsXML.load_file("../SFMLVania/include/Settings.xml");
	if (settingsResult)
	{
		std::cout << "File found\n";
	}
	else
		std::cout << "File not found\n";
	if (!settingsResult)
	{
		std::cout << "File also not found\n";
	}

	if (settingsXML.empty())
		std::cout << "file is empty\n";
	else
		std::cout << "file is NOT empty\n";

	//std::cout << "setRes: " << setRes << std::endl;
	std::cout << "Child_value(): " << settingsXML.child_value() << std::endl;
	std::cout << "Child 'options': " << settingsXML.child("options") << std::endl;
	std::cout << "Child 'options' name: " << settingsXML.child("options").name() << std::endl;
	std::cout << "Child 'options' value: " << settingsXML.child("options").value() << std::endl;
	std::cout << "Doc element: " << settingsXML.document_element() << std::endl;
	std::cout << "Doc element value: " << settingsXML.document_element().value() << std::endl;
	//returns "settings"
	std::cout << "Doc element name: " << settingsXML.document_element().name() << std::endl;
	//returns a non NULL address
	std::cout << "Doc element last attr: " << settingsXML.document_element().last_attribute() << std::endl;
	std::cout << "Doc element attr 'description': " << settingsXML.document_element().attribute("description") << std::endl;
	std::cout << "Doc element attr 'description' as string: " << settingsXML.document_element().attribute("description").as_string() << std::endl;

	std::cout << "Doc element child 'options' child 'resolution': " << settingsXML.document_element().child("options").child("resolution") << std::endl;
	std::cout << "Doc element by path settings/options/resolution attr description as string: " << settingsXML.first_element_by_path("settings/options/resolution").attribute("description").as_string() << std::endl;
	std::cout << std::endl;
	std::cout << "Doc element by path settings/options/resolution child value: " << settingsXML.first_element_by_path("settings/options/resolution").child_value() << std::endl;

	//std::string testStr = settingsXML.first_element_by_path("settings/options/resolution").child_value();

	//setRes = std::stoi(testStr);

	setRes = std::stoi(settingsXML.first_element_by_path("settings/options/resolution").child_value());

	sf::RenderWindow window(sf::VideoMode(settingResolution[setRes], settingResolution[setRes + 1]), "SFML works!");
	//sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::CircleShape  shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
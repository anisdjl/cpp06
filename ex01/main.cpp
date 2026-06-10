#include "Serializer.hpp"

int main(void)
{
	Data *test = new Data;
	test->age = 20;
	
	std::cout << "adresse de test: " << test << std::endl;
	
	uintptr_t ptr = Serializer::serialize(test);
	std::cout << "adresse de ptr apres serialize " << ptr << std::endl;
	

	Data *de_serialize = Serializer::deserialize(ptr);
	std::cout << "adresse apres desirialize " << de_serialize << std::endl;

	delete test;
	return (0);
}

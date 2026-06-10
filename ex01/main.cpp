#include "Serializer.hpp"

int main(void)
{
	Data *test = new Data;
	uintptr_t ptr;
	std::cout << test << std::endl;
	//ptr = Serializer::serialize(test);
	std::cout << Serializer::serialize(test) << std::endl;
	// test = Serializer::deserialize(ptr);
	std::cout << Serializer::deserialize(ptr) << std::endl;

	return (0);
}

#include "Base.hpp"

int main(void)
{
	srand(time(0));
	Base	*ptr_test = generate();
	identify(ptr_test);
	Base	*ptr_ref = generate();
	identify(ptr_ref);
	return (0);
}

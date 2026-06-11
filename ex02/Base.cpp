#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
    std::cout << "Base destructor called" << std::endl;
}

Base *generate(void)
{
	srand(time(0));
	int random_num;

	random_num = rand() % 3;
	switch (random_num)
	{
		case 0:
			// std::cout << "j'ai renvoye A\n";
			return (new A());
			break;
		case 1:
			// std::cout << "j'ai renvoye B\n";
			return (new B());
			break;
		case 2:
			// std::cout << "j'ai renvoye C\n";
			return (new C());
			break;
		default:
			return NULL;
	}
}

void	identify(Base *p)
{
	A	*ptr_a;
	B	*ptr_b;
	C	*ptr_c;

	ptr_a = dynamic_cast<A*>(p);
	if (ptr_a)
	{
		std::cout << "The actual type of the pointer is an A class pointer" << std::endl;
		return ;
	}
	ptr_b = dynamic_cast<B*>(p);
	if (ptr_b)
	{
		std::cout << "The actual type of the pointer is an B class pointer" << std::endl;
		return ;
	}
	ptr_c = dynamic_cast<C*>(p);
	if (ptr_c)
	{
		std::cout << "The actual type of the pointer is an C class pointer" << std::endl;
		return ;
	}
}

void	identify(Base &p)
{	try
	{
		A &ref_a = dynamic_cast<A&>(p);
		std::cout << "The actual type of the pointer is an A class pointer" << std::endl;
		(void)ref_a;
		return;
	}
	catch (std::exception &a)
	{
		
	}
	try
	{
		B &ref_b = dynamic_cast<B&>(p);
		std::cout << "The actual type of the pointer is an B class pointer" << std::endl;
		(void)ref_b;
		return ;
	}
	catch (std::exception &a)
	{

	}
	try
	{
		C &ref_c = dynamic_cast<C&>(p);
		std::cout << "The actual type of the pointer is an c class pointer" << std::endl;
		(void)ref_c;
		return ;
	}
	catch (std::exception &a)
	{

	}
}


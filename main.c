#include "function.h"

int main(void)
{
	srand((unsigned int)time(NULL));

	int option = 0;
	double bal = 0.0;

	do
	{
		option = validate_menu_option();
		

		bal = process_option(option,bal);
	} while (option != EXIT);

	
	return 0;
}
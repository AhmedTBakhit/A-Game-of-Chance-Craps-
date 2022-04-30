#include "function.h"



void display_menu(void)
{

	printf("1. Display rules.\n ");
	printf("2. Play craps.\n ");
	printf("3. Exit\n ");

}

//precondition : promt must be displayed

int get_option(void)
{

	int option = 0;

	scanf("%d", &option);

	return option;
}

int validate_menu_option(void)           
{
	int option = 0;

	do

	{
		display_menu();
		option = get_option(); // we have user input
		// need to check and validate user input
		//condition should go here

	} while (option < DISPLAY_RULES || option > EXIT); //input validation loop

	return option;


}
//precondition option must be valid
double process_option(int option, double bal)
{
	double balance = 0.0;

	switch (option)
	{
	case DISPLAY_RULES: print_game_rules();
		break;
	case PLAY: balance = play_game(bal);
		break;
	case EXIT: printf("exit game.\n");
		break;
	default: printf("invalid option.\n");
		break;

	}
	return balance;
}





/*
* Name:  print_game_rules()
* Description: displays the games rules
* History:
* Input: none
* Outputs: a printf statement
* Returns: void
* Precondition: 
* Postcondition:
*/

void print_game_rules(void)
{
	printf("GAME RULES: \n");
	printf("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.\n");
	printf("After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n");
	printf("If the sum is 7 or 11 on the first throw, the player wins.\n");
	printf("If the sum is 2, 3, or 12 on the first throw (called craps), the player loses (i.e. the house wins)\n");
	printf(" If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point.\n");
	printf("To win, you must continue rolling the dice until you make your point.\n");
	printf("The player loses by rolling a 7 before making the point\n");
}

/*
* Name:  get_bank_balance()
* Description: get the users bank balance
* History:
* Input: none
* Outputs: bank balance
* Returns: double
* Precondition: 
* Postcondition:
*/

double get_bank_balance(void)
{
	double balance = 0.0;
	printf("Enter your bank balance that you will use in the game in dollars\n");
	scanf("%lf", &balance);
	return balance;
}

/*
* Name:  get_wager_amount()
* Description: get the wager the users going to use on a Particular roll
* History:
* Input: none
* Outputs: wager
* Returns: double
* Precondition:
* Postcondition:
*/
double get_wager_amount(void)
{
	double wager = 0.0;
	printf("How much would you like to wager in this roll ? \n");
	scanf("%lf", &wager);
	return wager;
}

/*
* Name:  check_wager_amount()
* Description: checks if the wager is within limits of player available balance
* History:
* Input: player's wager and bank balance
* Outputs: 1 0r 0
* Returns: integer
* Precondition:
* Postcondition:
*/
int check_wager_amount(double wager, double balance)
{
	if (wager > balance)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/*
* Name:  roll_die()
* Description: rolss one die
* History:
* Input: void
* Outputs: a random value from 1 to 6
* Returns: integer
* Precondition:
* Postcondition:
*/

int roll_die(void)
{
	int random = 0;
	random = rand() % 6 + 1;
	return random;
}



/*
* Name: calculate_sum_dice()
* Description: calculates the sum of the 2 rolled dice
* History:
* Input: 2 dice roll numbers
* Outputs: a sum of the 2 values
* Returns: integer
* Precondition:
* Postcondition:
*/

int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum = 0;
	sum = die1_value + die2_value;
	return sum;
}

/*
* Name: is_win_loss_or_point()
* Description: determines if the player wins or losses or gets points
* History:
* Input: 2 dice roll numbers
* Outputs: 1 or 0 or -1
* Returns: integer
* Precondition:
* Postcondition:
*/

int is_win_loss_or_point(int sum_dice)
{
	if ((sum_dice == 7) || (sum_dice == 11))
	{
		return 1;
	}
	else if ((sum_dice == 2) || (sum_dice == 3) || (sum_dice == 12))
	{
		return 0;
	}
	else if (sum_dice == 4 || sum_dice == 5 || sum_dice == 6 || sum_dice == 8 || sum_dice == 9 || sum_dice == 10)
	{
		return -1;
	}
}

/*
* Name: is_point_loss_or_neither()
* Description: determines the result of any successive rolls
* History:
* Input: sum of dice rolls and point value
* Outputs: 1 or 0 or -1
* Returns: integer
* Precondition:
* Postcondition:
*/

int is_point_loss_or_neither(int sum_dice, int point_value)
{
	if (sum_dice == point_value)
	{
		return 1;
	}
	else if (sum_dice == 7)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
* Name: adjust_bank_balance()
* Description: determines what changes happen to the bank balance
* History:
* Input: bank balance,wager and add or subtract result
* Outputs: bank balance
* Returns: double
* Precondition:
* Postcondition:
*/

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	if (add_or_subtract == 1)
	{
		bank_balance += wager_amount;
		return bank_balance;
	}
	else if (add_or_subtract == 0)
	{
		bank_balance -= wager_amount;
		return bank_balance;
	}
	else
	{
		return bank_balance;
	}
}

/*
* Name: chatter_messages()
* Description: determines what changes happen to the bank balance
* History:
* Input: bank balance,wager and add or subtract result
* Outputs: bank balance
* Returns: double
* Precondition:
* Postcondition:
*/

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
	int output = 0;
	output = rand() % 6 + 1;
	if (output == 1)
	{
		if (current_bank_balance > initial_bank_balance)
		{
			printf("bag alert majooor baag alert\n");
		}
	}

	else if (output == 2)
	{
		if (current_bank_balance < initial_bank_balance)
		{
			printf("Oh no You're getting broke NiKO\n");
		}
	}

	else if (output == 3)
	{
		if (number_rolls > 2)
		{
			printf("i think youve taken a lot of rolls\n");
		}
	}

	else if (output == 4)
	{
		if (win_loss_neither == 1)
		{
			printf("yaaay GO GET THAT DUB\n");
		}
	}

	else if (output == 5)
	{
		if (win_loss_neither == 0)
		{
			printf("Unlucky today sir\n");
		}
	}

	else if (output == 6)
	{
		if (win_loss_neither == -1)
		{
			printf("common keep trying you got this!\n");
		}
	}
}

double play_game(double bal)
{
	double wager = 0.0, balance = bal, temp_wager = 0.0;
	int check_wager = 0, roll_1 = 0, roll_2 = 0, sum = 0, result = 0;
	if (balance <=0)
	{

		balance = get_bank_balance();
	}
	printf("Your balance is %lf\n", balance);
	wager = get_wager_amount();
	check_wager = check_wager_amount(wager, balance);
	if (check_wager == 1)
	{
		roll_1 = roll_die();
		roll_2 = roll_die();
		printf("die1: %d\n", roll_1);
		printf("die2: %d\n", roll_2);
		sum = calculate_sum_dice(roll_1, roll_2);
		printf("your sum is: %d\n", sum);
		result = is_win_loss_or_point(sum);


		if (result == -1)
		{
			int point_value = sum, rolls = 1, check_wager2 = 0;
			printf("yout point value is: %d\n", point_value);
			do
			{
				//srand((unsigned int)time(NULL));
				//wager +=change_wager();
				
					temp_wager = wager;

					temp_wager += change_wager();
					
				while(check_wager_amount(temp_wager, balance) == 0)
				{ 
					printf(" Please choose a wager within your bank balance\n");
					scanf("%lf", &temp_wager);
					temp_wager += wager;
					
				}
				wager = temp_wager;
				
				
				roll_1 = roll_die();
				roll_2 = roll_die();
				printf("die1: %d\n", roll_1);
				printf("die2: %d\n", roll_2);

				sum = calculate_sum_dice(roll_1, roll_2);
				printf("your sum is: %d\n", sum);
				result = is_point_loss_or_neither(sum, point_value);
				rolls++;
				chatter_messages(rolls, result, balance,(balance-wager));
			} while (result == -1);

		}


		 if (result == 1)
		{
			printf("YOU WON THE GAME,SINCE YOU GOT: %d \n ", sum);
			balance += wager;
			chatter_messages(0, result, (balance - wager), balance);
		}

		 else if (result == 0)
		{
			printf("CRAPS! YOU LOST, since you got: %d\n", sum);
			balance -= wager;
			chatter_messages(0, result, (balance + wager),balance);
		}
	}

		else
		{
			printf("Error your wage is more than your bank_balance\n");
		}
	return balance;
	}


double change_wager(void)
{
	int ans = 0;
	printf("do you want to change wager? enter Y for yes or N for no\n");
	scanf(" %c", &ans);
	if (ans =='Y' || ans == 'y')
	{
		double wager = 0;
		printf("enter your new wager\n");
		scanf("%lf", &wager);

		return wager;

	}
	

	return 0;
}
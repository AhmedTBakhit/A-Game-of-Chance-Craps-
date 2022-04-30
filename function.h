#ifndef function_h  
#define function_h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h> //rand() , scrand()
#include <time.h> //srand  --> time()

#define DISPLAY_RULES 1
#define PLAY 2
#define EXIT 3

//function declarations
double process_option(int option, double bal);
void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);
double play_game(double bal);
double change_wager(void);
#endif 


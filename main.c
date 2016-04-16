#include <stdio.h>
#include <stdlib.h>
#include "our_functs.h"

void user_interface(void);
void find_word_home(void);

int main(void)
{
	int choice;
		printf("WELCOME OT BIBLE-READING SOFTWARE\n");
		printf("Powered by Rouvem Pishchik and Vitaliy Kuleshov\n");
	user_interface();
	while((scanf("%d", &choice)) == 1){
		if(choice == 1){
			find_word_home();
			user_interface();
		}else if(choice == 0){
			printf("Thank You, Bye Bye\n");
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}

void find_word_home(void)
{
	char searched_word[250];
	char ch;
	int num;
	int valid;
	char che;
	do{
      		printf("Enter the word that you are searching for:\n");
      		getchar();
    		valid = my_input_func(searched_word);
 			printf("Do you want to disregard capitalization:\n");
 			ch = getchar();
  			if(ch == 'Y' || ch == 'y'){
  				system("cls");
   				num = word_search(searched_word, 1, strlen(searched_word));
   				printf("%d words\n", num);
   				getchar();
  			}else if(ch == 'N' || ch == 'n'){
  				system("cls");
   				num = word_search(searched_word, 0, strlen(searched_word));
   				printf("%d words\n", num);
   				getchar();
  			}
  			printf("Return to main menu, Y/N?\n");
  			che = getchar();
  			if(che == 'y' || che == 'Y'){
  				break;
			}
 }while(valid == 1);
}

void user_interface(void)
{
	printf("Enter...\n");
	printf("Digit (1) to find a searched phrase in the Bible!\n");
	printf("Digit (0) to quit!\n");
}


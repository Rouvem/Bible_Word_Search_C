#include <stdio.h>
#include <stdlib.h>
#include "our_functs.h"

void user_interface(void);
void find_word_home(char *file_name, int file_name_len);

int main(void)
{
	int choice;
		printf("WELCOME OT BIBLE-READING SOFTWARE\n");
		printf("Powered by Rouvem Pishchik and Vitaliy Kuleshov\n");
	user_interface();
	while((scanf("%d", &choice)) == 1){
		if(choice == 1){
            char name_of_file[100];
            printf("Enter name of file: \n");
            scanf("%s", name_of_file);
            name_of_file[99] = '\0';
            int len_file_name = strlen(name_of_file);
			find_word_home(name_of_file, len_file_name);
			user_interface();
		}else if(choice == 0){
			printf("Thank You, Bye Bye\n");
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}

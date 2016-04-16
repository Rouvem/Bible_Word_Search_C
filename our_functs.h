//This is my own, better input function
//Work done by Vitaliy Kuleshov and Rouvem Pishchik!!
//get read to get blown!

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#define MYMAX 2500

 //functions that gets rid of \n
 void cookie_monster(void);
 void new_line();

 // header for word_search
 int word_search(char *file_name, char *word, bool capital, int word_len);

int my_input_func(char array[])
{
	int success = 1; //assume successful
	int len = 0;
	int var;
	scanf("%s", array);
	//printf("var: %d\narray: %s\n", var, array);
	if(var == 0){
		success = 0;
	}

	len = strlen(array);
	if((array[len - 1]) == '\n'){
		array[len - 1] = '\0'; //terminate string
		len -= 1;
	}else{
		cookie_monster();
	}
	//fputs(input_array, stdout);
	return success;
}

 void cookie_monster(void)
 {
 	while(getchar() != '\n'){
 		; //do nothing!!!!
	 }
 }

 //end of function that accepts input
int word_search(char *file_name, char *word,  bool capital, int word_len)
{
	int count = 0;
    register int i;
    int j;
	FILE *fp;
    fp = fopen(file_name, "r");
    if(fp == NULL){
        perror(fp);
    }
    char reader;
    char c_array[word_len];

	if(!capital){
		for(j = 0; j < word_len; ++j){
	    		if(toupper(word[j])){
        			word[j] = tolower(word[j]);
			}//if
		}
	}
	printf("word: %s\n", word);
    while(fscanf(fp, "%s", c_array) == 1){

        printf("%s\n", c_array);
	    if(!capital){
       		for(i = 0; i < strlen(c_array); ++i){
        		if(toupper(c_array[i])){
        			c_array[i] = tolower(c_array[i]);
					}//if
				}//for
			}//if
        if(strcmp(word, c_array) == 0){
           count += 1;
        }
    }
    fclose(fp);
    return count;
}


void find_word_home(char *file_name, int file_name_len)
{
	char searched_word[250];
	char ch;
	int num;
	int valid;
	char che;

	do{
      		printf("Enter the word that you are searching for:\n");
    		valid = my_input_func(searched_word);
    		do{
                	printf("Do you care about capitalization?\n");
        	 	ch = getchar();
                	if(ch == 'Y' || ch == 'y'){
                    		system("cls");
                    		num = word_search(file_name, searched_word, 1, strlen(searched_word));
                		printf("%d words\n", num);
                    		cookie_monster();
                	}
                	else if(ch == 'N' || ch == 'n'){
                    		system("cls");
                    		num = word_search(file_name, searched_word, 0, strlen(searched_word));
                    		printf("%d words\n", num);
                    		cookie_monster();
                	}
                	else{
                    		cookie_monster();
                	}
    		}while(ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
  			int main = 0;
  			while(!main){
                		printf("Return to main menu, Y/N?\n");
                		scanf("%c", &che);
                		cookie_monster();
                		if(che == 'y' || che == 'Y'){
                    			main = 1;
                		}
                		else if(che == 'N' || che == 'n'){
                    			break;
                		}
                		else{
                		}
  			}
            	if(main){
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

void new_line()
{
    char symbol;
    do{
        scanf("%c", &symbol);
    }while(symbol != '\n');
}

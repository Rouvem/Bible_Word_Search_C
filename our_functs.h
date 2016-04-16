//This is my own, better input function
//Work done by Vitaliy Kuleshov and Rouvem Pishchik!!
//get read to get blown!

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#define MYMAX 2500

 //function that inputs into a string AND gets rid of \n
 void cookie_monster(void);
 int word_search(char *word, bool capital, int word_len);

int my_input_func(char array[])
{
	int success = 1; //assume succesful
	int len = 0;
	char *var;
	var = fgets(array, MYMAX, stdin);
	if(var == NULL){
		success = 0;
	}

	len = strlen(array);
	if((array[len -1]) == '\n'){
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
int word_search(char *word,  bool capital, int word_len)
{
	int count = 0;
    FILE *fp;
    register int i;
    int j;
    fp = fopen("test.txt", "r");
    if(fp == NULL){
        perror(fp);
    }
    char reader;
    char c_array[word_len];

	if(capital){
		for(j = 0; j < word_len; ++j){
	    		if(toupper(word[j])){
        			word[j] = tolower(word[j]);
        			break;
			}//if
		}
	}
    printf("%s\n", word);
    do{
        reader = fscanf(fp, "%s", c_array);

	    if(capital){
       		for(i = 0; i < strlen(c_array); ++i){
        		if(toupper(c_array[i])){
        			c_array[i] = tolower(c_array[i]);
					}//if
				}//for
			}//if
        if(strcmp(word, c_array) == 0){
           count += 1;
        }
    }while(reader != EOF);

    fclose(fp);
    return count;
}





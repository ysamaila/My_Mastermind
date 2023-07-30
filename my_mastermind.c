#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAXIMUM_ATTEMPTS 10 /*A constant definition. Here we define the maximum number of tries a user has.*/
#define CODE_LENGTH 4 /*Here we define a constant named CODE_LENGTH to hold the number of the code digit which is 4*/
#define BUFFER_SIZE 5 /*the size of the buffer that will hold the guess made by the player*/

/*The function "generate_random_code" generate a random code of size CODE_LENGTH and keeps it in the array variable named `code`*/
void generateRandomCode(char *code){
    int a;
    for(a=0; a<CODE_LENGTH; a++){
        code[a]=rand()%9 + '0';
    }
}

/*
    The function checkGuess will check the players guess against four digit code
    The function updates wellPlaced if the entry is right, or updates wrong placed if entry is wrong.
    An integer is returned by the function, 1 if guess is correct, and 0 if the guess is wrong.
*/
int checkGuess (const char *guess, const char *code, int *wellPlaced, int *misplaced){
    int i,j;

    *wellPlaced =0;
    *misplaced =0;

    for(i=0; i<CODE_LENGTH; i++){
        if(guess[i] == code[i]){
            (*wellPlaced)++;
        }else{
            for(j=0; j<CODE_LENGTH; j++){
                if(guess[i] == code[j]){
                    (*misplaced)++;
                    break;
                }
            }
        }
    }
    return *wellPlaced == CODE_LENGTH;
}



int main (int argc, char **argv){
    char code[CODE_LENGTH+1] = {0};
    int attempts = MAXIMUM_ATTEMPTS;
    int i;
    srand(time(NULL));

    /* Check command line arguments for user defined code and attempts */
    for(i=1; i<argc; i++){
        if(strcmp(argv[i], "-c") == 0 && i + 1 < argc){
            strncpy(code, argv[i+1], CODE_LENGTH);
            i++;
        }else if (strcmp(argv[i], "-t") ==0 && i+1 < argc){
            attempts = atoi(argv[i+1]);
            i++;
        }
    }

    /* Generate a new random code if no code is provided***/

    if(code[0]==0){
        generateRandomCode(code);
    }

    /*Initiate the game by sending prompt to the console for the user to provide inputs*/
    printf("Please enter a valid guess");
    for(i=0; i<attempts; i++){
        char guess[BUFFER_SIZE] = {0};
        int wellPlaced, misplaced;
        printf("\nRound %d\n", i);
 if(read(0, guess, BUFFER_SIZE) <= 0 ){
            printf("Program is Exiting... Ctrl + D command entered!");
            break;
        }

        if(((guess[i] >= 'a' && guess[i] <= 'z') || (guess[i] >= 'A' && guess[i] <= 'Z'))){
            printf("Program exiting... Invalid character entered!");
            break;
        }

        if(checkGuess(guess, code, &wellPlaced, &misplaced)){
            printf("Congratz! You did it!\n");
            break;
        } else {
            printf("Well placed pieces: %d \n Misplaced pieces: %d \n", wellPlaced, misplaced);
        }
    }
    return 0;
}

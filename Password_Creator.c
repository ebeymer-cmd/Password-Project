#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int length;

//This is a bank for us to pull from
char lower[]   = "abcdefghijklmnopqrstuvwxyz";
char capitals[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char special[] = "!@#$%&?";
char numbers[] = "0123456789";

int main(void)
{
    int upper_count = 0, special_count = 0, number_count = 0;
    char upper_q, special_q, number_q;

    srand(time(NULL));

    //This asks the minimum length of a password
    printf("Please enter a minimum length for the password: ");
    scanf("%d", &length);

    if (length <= 0) {
        printf("Error. Incorrect Password Length.\n");
        return 1;
    }

    //This asks how many uppercase letters a password should contain
    printf("Should the password have uppercase letters? (Y/N): ");
    scanf(" %c", &upper_q);

    if (upper_q == 'Y' || upper_q == 'y') {
        printf("Please enter how many uppercase letters: ");
        scanf("%d", &upper_count);

        if (upper_count <= 0) {
            printf("Error. Invalid Amount.\n");
            return 1;
        }
    } else if (upper_q != 'N' && upper_q != 'n') {
        printf("Error. Invalid Input.\n");
        return 1;
    }

    //Most passwords have the funny special characters like &, %, and #, so this asks if it should contain them
    printf("Should the password have special characters? (Y/N): ");
    scanf(" %c", &special_q);

    if (special_q == 'Y' || special_q == 'y') {
        printf("Please enter how many special characters: ");
        scanf("%d", &special_count);

        if (special_count <= 0) {
            printf("Error. Invalid Amount.\n");
            return 1;
        }
    } else if (special_q != 'N' && special_q != 'n') {
        printf("Error. Invalid Input.\n");
        return 1;
    }

    //This asks if the password should contain numbers
    printf("Should the password have numbers? (Y/N): ");
    scanf(" %c", &number_q);

    if (number_q == 'Y' || number_q == 'y') {
        printf("Please enter how many numbers: ");
        scanf("%d", &number_count);

        if (number_count <= 0) {
            printf("Error. Invalid Amount.\n");
            return 1;
        }
    } else if (number_q != 'N' && number_q != 'n') {
        printf("Error. Invalid Input.\n");
        return 1;
    }

    //This part generates the actual password
    char password[length + 1];
    int i = 0;

    while (i < upper_count) {
        password[i] = capitals[rand() % 26];
        i++;
    }

    while (i < upper_count + special_count) {
        password[i] = special[rand() % 7];
        i++;
    }

    while (i < upper_count + special_count + number_count) {
        password[i] = numbers[rand() % 10];
        i++;
    }

    while (i < length) {
        password[i] = lower[rand() % 26];
        i++;
    }

    password[length] = '\0';

    //Lastly, this randomizes the password. Hopefully.
    for (int j = length - 1; j > 0; j--) {
            int k = rand() % (j+1);
            char temp = password[j];
            password[j] = password[k];
            password[k] = temp;
    }
    printf("Generated Password: %s\n", password);

    return 0;
}
//Congrats! You've made a password :D
//lol

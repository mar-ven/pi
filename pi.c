#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayHelp();
void calc_and_print(int numb, char c);

int main(int argc, char **argv) {
    int n = 0;
    char c = ' ';
    
    //checking arguments
    if(argc < 2) {
        displayHelp();
        return 1;
    }
    
    //checking arguments
    if(strcmp(argv[1], "-l") == 0) {
        c = '\n';
        n = atoi(argv[2]);
    } else {
        n = atoi(argv[1]);
    }
    
    //Everything is done here!
    calc_and_print(n, c);


    return 0;
}

//Text displayed if no argument is given to the program.
void displayHelp() {
    printf("Pi software v1.0\n"
    "This software is freely distributed by his unique developer, mar-ven.\n"
    "I hope you enjoy this software as much as I did developing it. You're encouraged to spread this software and to help me reaching popularity.\n"
    "(Did I seem to selfish? I hope not! Ahahah)"
    "\n\n\n"
    "[SYNOPSIS]: pi [-l] n\n"
    "where -l separates results with line separators\n"
    "      n is the argument of pi.\n"
    "\n\n\n"
    "pi return the first n prime numbers, starting from 1.\n"
    "Any comments are welcome.\n"
    "Thank you for your support!\n");
}

/* This functions works like this:
*  Until the numb-est prime number is calculated,
*  it goes through the first i/2 numbers (except 1),
*  to see if these are divisors of i.
*  If so, i is NOT a prime number. Otherwise, it IS.
*/
void calc_and_print(int numb, char c) {
    int i = 1, times = 0, isPrime = 1;

    while(times < numb) {
        for(int j = 2; j <= (i/2); j++) {
            if(i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if(isPrime) {
            if(times == numb - 1)
                c = '\n';
            printf("%d%c", i, c);
            times++;
        } else {
            isPrime = 1;
        }

        i++;
    }
}


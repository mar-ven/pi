#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayHelp();
void calc_and_print(int numb, char c, int err_out);
void calc_M_alg(int numb, int *results, char c, int err_out);

int main(int argc, char **argv) {
    int n = 0, err_out = 0, wantsMem = 0, *mem = NULL;
    char c = ' ';
    
    //checking arguments
    if(argc < 2) {
        displayHelp();
        return 1;
    }
    
    //checking arguments
    for(int i = 1; i < argc - 1; i++) {
        if(strcmp(argv[i], "-l") == 0) {
            c = '\n';
        }else if(strcmp(argv[i], "-c") == 0) {
            c = argv[i + 1][0];
        } else if(strcmp(argv[i], "-e") == 0) {
            err_out = atoi(argv[i+1]);
        } else if(strcmp(argv[i], "-m") == 0) {
            wantsMem = 1;
        }
    }

    n = atoi(argv[argc - 1]);
    //If users wants to use memory algorithm...
    if(wantsMem)
        mem = malloc(sizeof(int) * n);

    //Everything is done here!
    if(mem)
        calc_M_alg(n, mem, c, err_out);
    else
        calc_and_print(n, c, err_out);

    free(mem);

    return 0;
}

//Text displayed if no argument is given to the program.
void displayHelp() {
    printf("Pi software v1.2\n"
    "This software is freely distributed by his unique developer, mar-ven.\n"
    "I hope you enjoy this software as much as I did developing it. You're encouraged to spread this software and to help me reaching popularity.\n"
    "(Did I seem to selfish? I hope not! Ahahah)"
    "\n\n"
    "pi return the first n prime numbers, starting from 1.\n"
    "\n\n"
    "[SYNOPSIS]: pi [OPTION] ... NUMBER\n"
    "OPTIONS:\n"
    "     -l separates results with line separators\n"
    "     -c separates result with the character tat is given in the next parameter.\n"
    "     -e prints on stderr the nth reached prime number.\n"
    "        It needs as argument the multiple to keep track.\n"
    "        For example: -e 1000 prints 'pi: reached 1000th', '2000th', '3000th' and so on.\n"
    "        It could be useful if the output is passed to a file, and a great quantity of prime numbers is requested.\n"
    "     -m Uses the M-algorithm. It calculates prime numbers going through the previously calculated ones.\n"
    "        It seems to be slower, and so I don't suggest to use it.\n"
    "NUMBER is the quantity of prime numbers needed.\n"
    "        It needs to be the last argument.\n"
    "        For example: 'pi 5 prints the first 5 prime numbers, starting from 1:\n"
    "        1 2 3 5 7\n"
    "\n\n"
    "Any comments are welcome.\n"
    "Thank you for your support!\n");
}

/* This functions works like this:
*  Until the numb-est prime number is calculated,
*  it goes through the first i/2 numbers (except 1),
*  to see if these are divisors of i.
*  If so, i is NOT a prime number. Otherwise, it IS.
*/
void calc_and_print(int numb, char c, int err_out) {
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
            if(err_out && (times + 1) % err_out == 0) {
                fflush(stdout);
                fprintf(stderr, "\npi: reached %dth\n", times + 1);
            }
            times++;
        } else {
            isPrime = 1;
        }

        i++;
    }
}

/*
*   This algorithm records the prime numbers and finds new prime numbers going through these. 
*   In order to use this algorithm, use -m option.
*   It seems to be really slower than the traditional one.
*   It needs as much memory as prime numbers user asks.
*/

void calc_M_alg(int numb, int *results, char c, int err_out) {
    int i = 3, times = 2, isPrime = 1;
    if(numb == 0)
        return;
    results[0] = 1;
    results[1] = 2;

    while(times < numb) {
        for(int j = 1; j < times - 1; j++) {
            if(i % results[j] == 0)
                isPrime = 0;
        }

        if(isPrime) {
            results[times - 1] = i; 
            if(times == numb - 1)
                c = '\n';
            printf("%d%c", i, c);
            if(err_out && (times + 1) % err_out == 0) {
                fflush(stdout);
                fprintf(stderr, "\npi: reached %dth\n", times + 1);
            }
            times++;
        } else {
            isPrime = 1;
        }

        i++;

    }
}


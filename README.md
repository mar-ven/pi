# Pi software v1.2

This software is freely distributed by his developer, mar-ven.

pi return the first n prime numbers, starting from 1.
It can use two different algorithms.
User can customize output, and get useful information in the standard error stream.
See the OPTIONS section for further informations.

[SYNOPSIS]: pi [OPTION] ... NUMBER
OPTIONS:
     -l separates results with line separators
     -c separates result with the character tat is given in the next parameter.
     -e prints on stderr the nth reached prime number.
        It needs as argument the multiple to keep track.
        For example: -e 1000 prints 'pi: reached 1000th', '2000th', '3000th' and so on.
        It could be useful if the output is passed to a file, and a great quantity of prime numbers is requested.
     -m Uses the M-algorithm. It calculates prime numbers going through the previously calculated ones.
        It seems to be slower, and so I don't suggest to use it.
NUMBER is the quantity of prime numbers needed.
        It needs to be the last argument.
        For example: 'pi 5 prints the first 5 prime numbers, starting from 1:
        1 2 3 5 7


Any comments are welcome.
Thank you for your support!

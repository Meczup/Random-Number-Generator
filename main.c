#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define COUNT 100

int main()
{
    int i, value;
    float  rndno;

    srand( time( NULL ) );
    printf( "SAMPLE C file\nDemonstrates generation of RANDOM INTEGERS...\n\n");
    printf( "RAND_MAX=%d\n", RAND_MAX );
    printf( "Value of [(2^15)-1] = %8.1f\n", pow(2,15)-1 );
    printf( "Size-of-int= %d Bytes", sizeof(int) );
    printf( "rand(): uses only 2 Bytes to generate a random integer.\n");
    printf( "It can generate random integers in the range 0 to RAND_MAX\n");
    printf( "SIGNED integer uses HALF of the max_range of 16 bits: \n" );
    printf( "i.e. it uses 15 bits. This gives 0 to [(2^15)-1] which is %d\n",
            RAND_MAX );
    printf( "\nSome compilers use 4 Bytes of integers for rand().\n" );
    printf( "Hence, they can generate a larger sequence of random integers: \n");
    printf( "Size_of_int=%d --> ", sizeof(int) );
    printf( "Value of [(2^31)-1] = %12.1f\n", pow(2.,31.)-1.0 );

    printf( "\nPlease note that if one divides each random integer generated \n");
    printf( "by the method above by RAND_MAX, one gets a UNIFORMLY distributed \n" );
    printf( "random number in the range 0 to 1.0; i.e. U(0,1)\n" );

    printf( "\nPress any key to generate random INTEGERS.....\n" );
    getchar();

    int randnumbers[COUNT];

    for( i=1; i<=COUNT; i++ ) {
        value = rand();
        randnumbers[i-1] = value;
        printf("%5d, ", value);
        if( i%10 == 0 ) printf("\n");
    }

    printf( "\nPress any key to generate random NUMBERS U(0,1)...\n" );
    getchar();

    for (int j = 1; j <= COUNT; j++) {
        rndno = randnumbers[j-1];
        rndno = rndno / RAND_MAX;
        printf("%f, ", rndno);
        if( j%10 == 0 ) printf("\n");
    }

    system( "PAUSE" );
    return 0;
}
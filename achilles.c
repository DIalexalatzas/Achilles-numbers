#include <stdio.h>
#include <time.h>                                               /* Header file for time function */
#include <stdlib.h>                                             /* Header file for srand and rand functions */
#define COMPUTATIONS 10000000                                   /* Amount of numbers to check */

int main(void) {
	int cnt=0, i;
	long curtime=time(NULL);                                    /* Current time (in seconds since 1/1/1970) */
        printf("Current time is %ld\n\n", curtime);
	srand((unsigned int) curtime);                              /* Seed for random number generator */
	for(i=1; i<=COMPUTATIONS; i++){                             /* Search for achillles numbers in [1,COMPUTATIONS] */
		int gcd, m, power2=0, power3=0, factor1, factor2, large, small, rem, flag=0, y, z;
		long x;
		y=rand();                                               /* Select 1st random number */
		z=rand();                                               /* Select 2nd random number */
		x=((y%32768)+1)*((z%32768)+1)+1;                        /* The number to be checked whether is achilles or not */
		m=x;
		while(m%2==0){                                          /* Check if 2 is a factor */
        	m/=2;
			power2++;
		}
		if(power2==1) continue;                                 /* If the factor's power is 1, x is not powerful. Go to next number. */
	 	while(m%3==0){                                          /* Check if 3 is a factor */
	    	m/=3;
			power3++;
		}
		if(power3==1) continue;                                 /* If the factor's power is 1, x is not powerful. Go to next number. */
		if(power2>power3){                                      /* Which power is larger? */
			large=power2;                                       /* Larger is power2 */
			small=power3;
		}
		else{
			large=power3;                                       /* Larger is power3 */
			small=power2;
		}
		while(small){                                           /* Procedure to find GCD */		
			rem=large%small;
			large=small;
			small=rem;
		}
		gcd=large;                                              /* GCD of power2 and power3 equals to final value of large */
	 	for(factor1=5; factor1*factor1<=m; factor1=factor1+6){  /* For prime factors greater than or equal to 5 check only until the number's square root */
         	long power1=0, power2=0;
			factor2=factor1+2;
         	while(m%factor1==0){                                /* Check if factor1 is prime factor of x */
           		m/=factor1;
           		power1++;
			}
			if(power1==1){                                      /* If the factor's power is 1 then x is not powerful*/
				flag=1;                                         /* My flag is up */
				break;                                          /* No need to check for more prime factors, therefore break the loop */	
			}
			if(gcd>power1){                                     /* Procedure to find the GCD of last prime factor's power and last gcd */	
				large=gcd;
				small=power1;
			}
			else{
				large=power1;
				small=gcd;
			}
			while(small){
				rem=large%small;
				large=small;
				small=rem;
			}
			gcd=large;
         	while(m%factor2==0){                                /* Check if factor2 is prime factor of x*/
           		m/=factor2;
           		power2++;
			}
			if(power2==1){                                      /* If the factor's power is 1 then x is not powerful */
				flag=1;                                         /* My flag is up */
				break;                                          /* No need to check for more prime factors, therefore break the loop*/
			}
			if(power2>gcd){                                     /* Procedure to find the GCD of last prime factor's power and last gcd */
				large=power2;
				small=gcd;
			}
			else{
				large=gcd;
				small=power2;
			}
			while(small){
				rem=large%small;
				large=small;
				small=rem;
			}
			gcd=large;
		}
		if(m>2) flag=1;                                         /* Special case if x is prime number, he can't be achilles therefore my flag is up */
		if(gcd==1 && flag==0) {                                 /* Condition for x to be achilles number */
			printf("%ld is achilles number\n", x);
			cnt++;                                              /* Achilles numbers counter */
		}
	}
	printf("Found %d achilles numbers out of %d tested numbers", cnt, COMPUTATIONS);
	return 0;
}

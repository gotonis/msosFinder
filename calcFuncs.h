#ifndef CALCFUNCS_H_INCLUDED
#define CALCFUNCS_H_INCLUDED
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <assert.h>

int nMatchesI(int f1, int g1, int f2, int g2){
    /*A reminder on the math:
    after the x2 rotation, A+-B = (f1+-g1)^2, same with C and f2/g2
    2A = 2(f^2+g^2)
    A+B+C = A+2f1g1 + 2f2g2 (side boxes)
    This function returns the number of side boxes that are perfect squares after the x2 rotation.
    */

    int A = f1*f1+g1*g1;
    //printf("A = %i\n",A);
    assert(f2*f2+g2*g2 == A);
    int count = 0;
    int B = 2*f1*g1;
    int C = 2*f2*g2;
    //printf("B = %i\nC = %i\n",B,C);
    int signs1[4] = {-1,1,-1,1};
    int signs2[4] = {-1,-1,1,1};
    for(int i=0;i<4;i++){
        //printf("%i,%i\n",signs1[i],signs2[i]);
        int D = A+(signs1[i]*B)+(signs2[i]*C);
        float val = sqrt(D);
        //printf("%i\n",D);
        if(val == floor(val))
            count++;
    }
    return count;
}

#endif // CALCFUNCS_H_INCLUDED

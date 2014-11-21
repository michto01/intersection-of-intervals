//
//  main.c
//  intersection
//
//  Created by Tomas Michalek on 21/11/14.
//  Copyright (c) 2014 CRE8IV.EU. All rights reserved.
//

#include <stdio.h>
#include "prunik.h"

int main(int argc, const char** argv) {
    
    double   a_begin,   a_end;
    double   b_begin,   b_end;
    double res_begin, res_end;
    
    /*
    //=> TEST VALUES: 
    a_begin = 1.5;
    a_end   = 2.8;
    
    b_begin = 1.6;
    b_end   = 2.0;
    */
    
    printf("Zadejte hranicni body intervalu oddelene mezerami [4x double]:");
    scanf("%lf %lf %lf %lf", &a_begin, &b_begin, &a_end, &b_end);
    getchar();
    
    int result = intersection(a_begin, b_begin, a_end, b_end, &res_begin, &res_end);
    
    if (result)
        printf("Vysledny interval: (%f, %f)\n", res_begin, res_end);
    else
        printf("Fail hlaska");
    
    return 0;
}

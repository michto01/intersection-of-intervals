//
//  main.c
//  intersection
//
//  Created by Tomas Michalek on 21/11/14.
//  Copyright (c) 2014 CRE8IV.EU. All rights reserved.
//

// Conditions in Homework ( for simplicity ):
//    + a_begin <= b_begin
//    + a_begin <= b_end
//    + ?

#include <stdio.h>
#include <assert.h>
#include "prunik.h" // Definition if TYPE, insersion(), insertion_test()

int main(int argc, const char** argv) {
    
    TYPE   a_begin,   a_end;
    TYPE   b_begin,   b_end;
    TYPE res_begin, res_end;
    
    insertion_test(); // Test the cases specyfied in document ( fails on error )
    
    printf( "Input endpoints of intervals separated by whitespace\n"
            "----------------------------------------------------\n"
            "[4x double = a1 a2 b1 b2]: " );
    scanf(
          "%lf %lf %lf %lf",
          &a_begin,
          &a_end,
          &b_begin,
          &b_end
    );
    getchar();
    
    
    /*
     * We want to recieve answer from function as result -> we pass reference =>
     * address of out prepared memory spaces { &res_begin }
     */
    int result = intersection(
                               a_begin, a_end,
                               b_begin, b_end,
                               &res_begin, &res_end
                              );
    
    if ( result )
        printf("Vysledny interval: (%.2f, %.2f)\n", res_begin, res_end);
    else
        printf("Fail hlaska");
    
    //To stop app while running as stand-alone app
    getchar();
    return 0;
}

//
//  prunik.c
//  intersection
//
//  Created by Tomas Michalek on 21/11/14.
//  Copyright (c) 2014 CRE8IV.EU. All rights reserved.
//

#include "prunik.h"
#include <assert.h>


/**
 * Find if the number is inside interval
 *
 * @param a_begin start of the interval
 * @param a_end end of the interval
 * @param part number to find in interval
 */
int isPartOfInterval(TYPE a_begin, TYPE a_end , TYPE part )
{
    return a_begin <= part && a_end >= part;
}

/**
 * Find intersection of two number intervals
 *
 * @param a_begin Start of the interval { A }
 * @param a_end End of the interval { A }
 * @param b_begin Start of the interval { B }
 * @param b_end End of the interval { B }
 * @param result_begin Start of the interval { result }
 * @param result_end End of the interval { result }
 */
int intersection (
                  TYPE       a_begin, TYPE       a_end,
                  TYPE       b_begin, TYPE       b_end,
                  TYPE* result_begin, TYPE* result_end
                  )
{
    //Pokud je pocatek B soucasti intervalu ... Postav navrat na  b_begin
    if ( isPartOfInterval( a_begin, a_end, b_begin ) )
    {
        *result_begin = b_begin;
        
        /* Check if the end is in the interval
         *  GURU ON ELINE VERSION:
         *   *result_end = ( isPartOfInterval(b_begin, a_end, b_end) ? b_end : a_end );
         *
         *  MORTAL VERSION:
         */
        
        // Pokud je konec B soucasti a tak vrat konec B; jinak vrat konec A
        if ( isPartOfInterval(b_begin, a_end, b_end) )
        {
            *result_end = b_end;
        }
        else
        {
            *result_end = a_end;
        }
        
        // Funkce byla uspesna a nasla pozadovany vysledek
        return 1;
    }
    else
        return 0;
}

void insertion_test()
{
    TYPE   a_begin,   a_end;
    TYPE   b_begin,   b_end;
    TYPE res_begin, res_end;
    
    // Test case 1:
    
    a_begin = 1.5;
    a_end   = 2.8;
    
    b_begin = 1.6;
    b_end   = 2.0;
    
    int result = intersection( a_begin, a_end, b_begin, b_end, &res_begin, &res_end );
    
    assert( result );
    assert( res_begin == 1.6 );
    assert( res_end   == 2.0 );
    
    // Test case 1:
    a_begin = 1.5;
    a_end   = 2.8;
    
    b_begin = 3.6;
    b_end   = 6.0;
    
    result = intersection( a_begin, a_end, b_begin, b_end, &res_begin, &res_end );
    
    assert( !result );
    
    // Test case 3:
    a_begin = 1.5;
    a_end   = 2.8;
    
    b_begin = 1.6;
    b_end   = 6.0;
    
    result = intersection( a_begin, a_end, b_begin, b_end, &res_begin, &res_end );
    
    assert( result );
    assert( res_begin == 1.6 );
    assert( res_end   == 2.8 );
}
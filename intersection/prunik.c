//
//  prunik.c
//  intersection
//
//  Created by Tomas Michalek on 21/11/14.
//  Copyright (c) 2014 CRE8IV.EU. All rights reserved.
//

#include "prunik.h"


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

int intersection (
                  TYPE a_begin, TYPE a_end,
                  TYPE b_begin, TYPE b_end,
                  TYPE* result_begin, TYPE* result_end
                  )
{
    //Pokud je pocatek B soucasti intervalu ... Postav navrat na  b_begin
    if ( isPartOfInterval( a_begin, a_end, b_begin ) )
    {
        *result_begin = b_begin;
        
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
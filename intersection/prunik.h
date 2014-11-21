//
//  prunik.h
//  intersection
//
//  Created by Tomas Michalek on 21/11/14.
//  Copyright (c) 2014 CRE8IV.EU. All rights reserved.
//

#ifndef __intersection__prunik__
#define __intersection__prunik__

#include <stdio.h>

#define TYPE double

/**
 * Find if the number is inside interval
 *
 * @param a_begin start of the interval
 * @param a_end end of the interval
 * @param part number to find in interval
 */
extern int isPartOfInterval(TYPE a_begin, TYPE a_end , TYPE part );

#pragma mark Intersection
#pragma mark -
extern int intersection (
                  TYPE a_begin, TYPE a_end,
                  TYPE b_begin, TYPE b_end,
                  TYPE* result_begin, TYPE* result_end
                  );

extern void insertion_test();

#endif /* defined(__intersection__prunik__) */

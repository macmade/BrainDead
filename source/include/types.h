/*******************************************************************************
 * Copyright (c) 2010, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/* $Id$ */

/*!
 * @header      types.h
 * @copyright   eosgarden 2010 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    Program's type definitions
 */

#ifndef _BD_TYPES_H_
#define _BD_TYPES_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*! Defines the bool data type if not available (below ISO-C99) */
#ifndef __bool_true_false_are_defined
    #define bool                            _Bool
    #define true                            1
    #define false                           0
    #define __bool_true_false_are_defined   1
#endif

/*!
 * @typedef     hexprint_cli_args
 * @abstract    Structure representing the program's possible command line arguments
 * @field       version         Prints the program's version number
 * @field       license         Prints the program's license terms
 * @field       help            Prints the program's help screen
 * @field       debug           Enables the debug mode
 * @field       break_points    Enables break points
 * @field       stack_debug     Enables stack debug
 * @field       stack_reset     Enables stack reset
 * @field       alloc           Number of stack cells to allocate at a time
 * @field       read            Number of bytes to read from the input file at a time
 * @field       file            File to interpret, if not in interactive mode
 */
typedef struct _bd_cli_args
{
    bool         version;
    bool         license;
    bool         help;
    bool         debug;
    bool         break_points;
    bool         stack_debug;
    bool         stack_reset;
    unsigned int alloc;
    unsigned int read;
    char       * file;
}
bd_cli_args;

/*!
 * @typedef     bd_stack
 * @abstract    A BrainFuck stack cell
 * @field       The cell value
 * @field       The cell index
 * @field       A pointer to the previous cell in the stack
 * @field       A pointer to the next cell in the stack
 */
typedef struct _bd_cell
{
    int               value;
    unsigned int      index;
    struct _bd_cell * prev;
    struct _bd_cell * next;
}
bd_cell;

/*!
 * @typedef     bd_stack
 * @abstract    A BrainFuck stack
 * @field       A pointer to the curnnet cell
 * @field       A pointer to the first cell
 * @field       A pointer to the last cell
 * @field       The number of cells in the stack
 * @field       The number of used cells in the stack
 * @field       The number of cells to allocate at a time
 */
typedef struct _bd_stack
{
    bd_cell    * cell;
    bd_cell    * start;
    bd_cell    * end;
    unsigned int length;
    unsigned int used;
    unsigned int xalloc;
}
bd_stack;

#ifdef __cplusplus
}
#endif

#endif /* _BD_TYPES_H_ */
    
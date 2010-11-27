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
 * @header      args.c
 * @copyright   eosgarden 2010 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    CLI arguments parsing
 */

#include "braindead.h"

/*!
 * @function    bd_get_cli_args
 * @abstract    Processes the command line parameters passed to this program
 * @param       argc    The number of command line arguments
 * @param       argv    A pointer to the command line arguments
 * @param       args    A pointer to the structure in which to store the arguments values
 * @result      void
 */
void bd_get_cli_args( int argc, char ** argv, bd_cli_args * args )
{
    int    i;
    char * option;
    
    args->version       = false;
    args->license       = false;
    args->help          = false;
    args->debug         = false;
    args->break_points  = false;
    args->stack_debug   = false;
    args->stack_reset   = false;
    args->alloc         = 85;
    args->read          = 1024;
    args->file          = NULL;
    
    i = 0;
    
    while( ++i < argc && ( ( char * )*( ++argv ) )[ 0 ] == '-' )
    {
        switch( ( ( char * )*( argv ) )[ 1 ] )
        {
            case 'v': args->version      = true; break;
            case 'l': args->license      = true; break;
            case 'h': args->help         = true; break;
            case 'd': args->debug        = true; break;
            case 'b': args->break_points = true; break;
            case 's': args->stack_debug  = true; break;
            case 'z': args->stack_reset  = true; break;
            
            case 'm':
                
                if( i < argc - 1 )
                {
                    args->alloc = atoi( *( ++argv ) );
                    
                    if( args->alloc == 0 )
                    {
                        args->alloc = 1024;
                    }
                }
                break;
            
            case 'r':
                
                if( i < argc - 1 )
                {
                    args->read = atoi( *( ++argv ) );
                    
                    if( args->read == 0 )
                    {
                        args->read = 1024;
                    }
                }
                break;
            
            case '-':
                
                option = *( argv ) + 1;
                
                if( strcmp( option, "version" ) == 0 )
                {
                    args->version = true;
                }
                else if( strcmp( option, "license" ) == 0 )
                {
                    args->license = true;
                }
                else if( strcmp( option, "help" ) == 0 )
                {
                    args->help = true;
                }
                else if( strcmp( option, "malloc" ) == 0 )
                {
                    if( i < argc - 1 )
                    {
                        args->alloc = atoi( *( ++argv ) );
                        
                        if( args->alloc == 0 )
                        {
                            args->alloc = 85;
                        }
                    }
                }
                else if( strcmp( option, "read" ) == 0 )
                {
                    if( i < argc - 1 )
                    {
                        args->read = atoi( *( ++argv ) );
                        
                        if( args->read == 0 )
                        {
                            args->read = 1024;
                        }
                    }
                }
                else if( strcmp( option, "debug" ) == 0 )
                {
                    args->debug = true;
                }
                else if( strcmp( option, "enable-breakpoints" ) == 0 )
                {
                    args->break_points = true;
                }
                else if( strcmp( option, "enable-stack-debug" ) == 0 )
                {
                    args->stack_debug = true;
                }
                else if( strcmp( option, "enable-stack-reset" ) == 0 )
                {
                    args->stack_reset = true;
                }
                
                break;
            
            default:
                
                break;
        }
    }
    
    if( i++ < argc )
    {
        args->file = *( argv );
    }
}
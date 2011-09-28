/* emacs edit mode for this file is -*- C++ -*- */
/* $Id: test_install.cc 12231 2009-11-02 10:12:22Z hannes $ */

//{{{ docu
//
// test_install.cc - test factory installation.
//
//}}}

#include <factory.h>

int
main ()
{
    // this will try to locate the GF(q) tables
    setCharacteristic( 2, 3, 'Z' );
    printf( "%s\n", factoryVersion );
    printf( "%s\n", factoryConfiguration );
    printf( "Factory lives!!" );
    return 0;
}

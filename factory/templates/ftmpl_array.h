/* emacs edit mode for this file is -*- C++ -*- */
/* $Id: ftmpl_array.h 13210 2010-09-17 13:36:19Z seelisch $ */

#ifndef INCL_ARRAY_H
#define INCL_ARRAY_H

#include <factory/factoryconf.h>

#ifndef NOSTREAMIO
#ifdef HAVE_IOSTREAM
#include <iostream>
#define OSTREAM std::ostream
#elif defined(HAVE_IOSTREAM_H)
#include <iostream.h>
#define OSTREAM ostream
#endif
#endif /* NOSTREAMIO */

template <class T>
class Array {
private:
    T * data;
    int _min;
    int _max;
    int _size;
public:
    Array();
    Array( const Array<T>& );
    Array( int size );
    Array( int min, int max );
    ~Array();
    Array<T>& operator= ( const Array<T>& );
    T& operator[] ( int i ) const;
    int size() const;
    int min() const;
    int max() const;
#ifndef NOSTREAMIO
    void print ( OSTREAM& ) const;
#endif /* NOSTREAMIO */
};

#ifndef NOSTREAMIO
template <class T>
OSTREAM& operator<< ( OSTREAM & os, const Array<T> & a );
#endif /* NOSTREAMIO */

#endif /* ! INCL_ARRAY_H */

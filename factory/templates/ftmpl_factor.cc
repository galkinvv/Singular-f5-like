/* emacs edit mode for this file is -*- C++ -*- */
/* $Id: ftmpl_factor.cc,v 1.7 1998-03-10 14:51:26 schmidt Exp $ */

#include <factoryconf.h>

#ifdef macintosh
#include <:templates:ftmpl_factor.h>
#else
#include <templates/ftmpl_factor.h>
#endif

template <class T>
Factor<T>& Factor<T>::operator= ( const Factor<T>& f )
{
    if ( this != &f ) {
	_factor = f._factor;
	_exp = f._exp;
    }
    return *this;
}

template <class T>
Factor<T>& Factor<T>::operator= ( const T & f )
{
    _factor = f;
    _exp = 1;
    return *this;
}

template <class T>
int operator== ( const Factor<T> &f1, const Factor<T> &f2 )
{
    return (f1.exp() == f2.exp()) && (f1.factor() == f2.factor());
}

#ifndef NOSTREAMIO
template <class T>
void Factor<T>::print ( ostream& s ) const
{
    if ( exp() == 1 )
	s << factor();
    else
	s << "(" << factor() << ")^" << exp();
}

template <class T>
ostream& operator<< ( ostream & os, const Factor<T> & f )
{
    f.print( os );
    return os;
}
#endif /* NOSTREAMIO */

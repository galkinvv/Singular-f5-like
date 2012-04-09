#!/bin/sh
GMP_H_T="gen_cf_gmp.o: gen_cf_gmp.cc /usr/include/gmp.h \ "
GMP_H=`echo $GMP_H_T| sed -e 's/^.*gmp.cc//' -e 's/ .$//'`
echo generating cf_gmp.h from $GMP_H
cat $GMP_H | grep -v __GMP_DECLSPEC_XX |grep -v std::FILE > cf_gmp.h

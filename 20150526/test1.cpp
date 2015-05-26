/*!
 * \file   test1.cpp
 * \brief  
 * \author Larry-o <nu11p0.6477@gmail.com>
 * \date   2015/05/26
 * C++ version: C++14
 */
#include "crc32_literal.hpp"
#include <iostream>

using namespace	std;

/*
 * とりあえずベーシックにいく。
 * 衝突の恐れあり
 */
void		hashTest1(const char *str)
{
	using	nu11p0::literals::operator""_crc32;

	switch(nu11p0::crc32(str)) {
		case	"hello"_crc32:
			cout << "hashTest1(): hello" << endl;
			break;
		case	"world"_crc32:
			cout << "hashTest1(): world" << endl;
			break;
		case	"plumless"_crc32:
			cout << "hashTest1(): plumless" << endl;
			break;
		default:
			cout << "hashTest1(): (default"
				<< ", str=" << str
				<< ", hash=" << std::hex << nu11p0::crc32(str) << std::dec
				<< ')' << endl;
	} // switch(nu11p0::crc32(str))
}

int			main()
{
	hashTest1("hello");
	hashTest1("world");
	hashTest1("other");
	hashTest1("plumless");
	hashTest1("buckeroo");

	return	0;
}

/*
output:

hashTest1(): hello
hashTest1(): world
hashTest1(): (default, str=other, hash=d9583520)
hashTest1(): plumless
hashTest1(): plumless
*/

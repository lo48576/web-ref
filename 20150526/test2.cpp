/*!
 * \file   test2.cpp
 * \brief  
 * \author Larry-o <nu11p0.6477@gmail.com>
 * \date   2015/05/26
 * C++ version: C++14
 */
#include "crc32_literal.hpp"
#include <iostream>
#include <cstring>

using namespace	std;

/*
 * 同じハッシュの異なる文字列をチェックする
 */
void		hashTest2(const char *str)
{
	using	nu11p0::literals::operator""_crc32;

	switch(nu11p0::crc32(str)) {
		case	"hello"_crc32: if(!std::strcmp(str, "hello")) {
			cout << "hashTest2(): hello" << endl;
		}
			break;
		case	"world"_crc32: if(!std::strcmp(str, "world")) {
			cout << "hashTest2(): world" << endl;
		}
			break;
		case	"plumless"_crc32: if(!std::strcmp(str, "plumless")) {
			cout << "hashTest2(): plumless" << endl;
		}
			break;
		default:
			cout << "hashTest2(): (default"
				<< ", str=" << str
				<< ", hash=" << std::hex << nu11p0::crc32(str) << std::dec
				<< ')' << endl;
	} // switch(nu11p0::crc32(str))
}


int			main()
{
	for(const auto &str : {"hello", "world", "other", "plumless", "buckeroo"}) {
		hashTest2(str);
	}

	return	0;
}

/*
output:

hashTest2(): hello
hashTest2(): world
hashTest2(): (default, str=other, hash=d9583520)
hashTest2(): plumless
*/

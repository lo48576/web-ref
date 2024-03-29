/*!
 * \file   test3.cpp
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
 * マクロを使って楽する
 */
void		hashTest3(const char *str)
{
	using	nu11p0::literals::operator""_crc32;

	// strがconst char *でなくstd::stringなら、if(str==s_)にする。
	// string_viewを使えるとしあわせ。
#define	CASE(s_)	case s_ ##_crc32: if(!std::strcmp(str, s_))
	switch(nu11p0::crc32(str)) {
		CASE("hello") {
			cout << "hashTest3(): hello" << endl;
		}
			break;
		CASE("world") {
			cout << "hashTest3(): world" << endl;
		}
			break;
		CASE("plumless") {
			cout << "hashTest3(): plumless" << endl;
		}
			break;
		default:
			cout << "hashTest3(): (default"
				<< ", str=" << str
				<< ", hash=" << std::hex << nu11p0::crc32(str) << std::dec
				<< ')' << endl;
	} // switch(nu11p0::crc32(str))
	// 後ろにゴミを残さない
#undef	CASE
}

int			main()
{
	for(const auto &str : {"hello", "world", "other", "plumless", "buckeroo"}) {
		hashTest3(str);
	}

	return	0;
}

/*
output:

hashTest3(): hello
hashTest3(): world
hashTest3(): (default, str=other, hash=d9583520)
hashTest3(): plumless
*/

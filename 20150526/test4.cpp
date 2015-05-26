/*!
 * \file   test4.cpp
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

	bool		found = false;
	// strがconst char *でなくstd::stringなら、if(str==s_)にする。
	// string_viewを使えるとしあわせ。
	// if内の括弧を二重にしたのは、「代入=と比較==を間違えてるんじゃね？」警告を出さないため
#define	CASE(s_)	case s_ ##_crc32: if((found=!std::strcmp(str, s_)))
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
	} // switch(nu11p0::crc32(str))
	// 後ろにゴミを残さない
#undef	CASE
	// defaultの代わりにフラグを使う
	if(!found) {
		// 上のswitchでcaseに引っ掛からなかった
		cout << "hashTest3(): (default"
			<< ", str=" << str
			<< ", hash=" << std::hex << nu11p0::crc32(str) << std::dec
			<< ')' << endl;
	}
}

int			main()
{
	hashTest3("hello");
	hashTest3("world");
	hashTest3("other");
	hashTest3("plumless");
	hashTest3("buckeroo");

	return	0;
}

/*
output:

hashTest3(): hello
hashTest3(): world
hashTest3(): (default, str=other, hash=d9583520)
hashTest3(): plumless
hashTest3(): (default, str=buckeroo, hash=4ddb0c25)
*/

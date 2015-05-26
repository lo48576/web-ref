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
void		hashTest4(const char *str)
{
	using	nu11p0::literals::operator""_crc32;

	bool		found = false;
	// strがconst char *でなくstd::stringなら、if(str==s_)にする。
	// string_viewを使えるとしあわせ。
	// if内の括弧を二重にしたのは、「代入=と比較==を間違えてるんじゃね？」警告を出さないため
#define	CASE(s_)	case s_ ##_crc32: if((found=!std::strcmp(str, s_)))
	switch(nu11p0::crc32(str)) {
		CASE("hello") {
			cout << "hashTest4(): hello" << endl;
		}
			break;
		CASE("world") {
			cout << "hashTest4(): world" << endl;
		}
			break;
		CASE("plumless") {
			cout << "hashTest4(): plumless" << endl;
		}
			break;
	} // switch(nu11p0::crc32(str))
	// 後ろにゴミを残さない
#undef	CASE
	// defaultの代わりにフラグを使う
	if(!found) {
		// 上のswitchでcaseに引っ掛からなかった
		cout << "hashTest4(): (default"
			<< ", str=" << str
			<< ", hash=" << std::hex << nu11p0::crc32(str) << std::dec
			<< ')' << endl;
	}
}

int			main()
{
	for(const auto &str : {"hello", "world", "other", "plumless", "buckeroo"}) {
		hashTest4(str);
	}

	return	0;
}

/*
output:

hashTest4(): hello
hashTest4(): world
hashTest4(): (default, str=other, hash=d9583520)
hashTest4(): plumless
hashTest4(): (default, str=buckeroo, hash=4ddb0c25)
*/

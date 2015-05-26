/*!
 * \file   test_error1.cpp
 * \brief  
 * \author Larry-o <nu11p0.6477@gmail.com>
 * \date   2015/05/26
 * C++ version: C++14
 */
#include "crc32_literal.hpp"
#include <iostream>

using namespace	std;

/*
 * 衝突があるとコンパイルエラーになる
 */
void		hashTest_error1(const char *str)
{
	using	nu11p0::literals::operator""_crc32;

	switch(nu11p0::crc32(str)) {
		case	"plumless"_crc32:
			cout << "hashTest_error1(): plumless" << endl;
			break;
		case	"buckeroo"_crc32:
			cout << "buckeroo_error1(): plumless" << endl;
			break;
		default:
			cout << "hashTest_error1(): (default"
				<< ", str=" << str
				<< ", hash=" << std::hex << nu11p0::crc32(str) << std::dec
				<< ')' << endl;
	} // switch(nu11p0::crc32(str))
}

int			main()
{
	for(const auto &str : {"hello", "world", "other", "plumless", "buckeroo"}) {
		hashTest_error1(str);
	}

	return	0;
}

/*
compile error (The message below is clang++-3.6.0):

test_error1.cpp:24:8: error: duplicate case value '1306201125'
                case    "buckeroo"_crc32:
                        ^
test_error1.cpp:21:8: note: previous case defined here
                case    "plumless"_crc32:
                        ^
1 error generated.
*/

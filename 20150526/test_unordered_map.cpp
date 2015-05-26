/*!
 * \file   test_unordered_map.hpp
 * \brief  
 * \author Larry-o <nu11p0.6477@gmail.com>
 * \date   2015/05/26
 * C++ version: C++11
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

/*
 * unordered_mapやその内部のstringは実行時に構築されるし、あまり効率は...
 */
void		test(const char *str)
{
	static const std::unordered_map<std::string, std::function<void(const char *)>>	cases = {
		{
			"hello",
			[](const char *) {
				std::cout << "test(): hello" << std::endl;
			}
		}, {
			"world",
			[](const char *) {
				std::cout << "test(): world" << std::endl;
			}
		}, {
			"plumless",
			[](const char *s) {
				std::cout << "test(): plumless" << std::endl;
				std::cout << "    " << s << " is not buckeroo." << std::endl;
			}
		}, {
			"buckeroo",
			[](const char *) {
				std::cout << "test(): buckeroo" << std::endl;
				std::cout << "    No conflict!" << std::endl;
			}
		}
	};

	auto		result = cases.find(str);
	if(result != cases.end()) {
		// found!
		result->second(str);
	} else {
		// not found.
		std::cout << "test(): (default"
			<< ", str=" << str
			<< ')' << std::endl;
	}
}

int			main()
{
	test("hello");
	test("world");
	test("other");
	test("plumless");
	test("buckeroo");

	return	0;
}

/*
output:

test(): hello
test(): world
test(): (default, str=other)
test(): plumless
    plumless is not buckeroo.
test(): buckeroo
    No conflict!
*/

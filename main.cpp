#include "Problem.hpp"
#include <cmath>
#include <cstdio>

void test_1();

void test_2();

void test_3();

int main() {
	test_1();
	test_2();
	test_3();
}

void test_1() {
	Problem p(
		1,
		{0, 2},
		{0, 3},
		{[](int) { return 1; }, [](int) { return 1; }},
		{{}, {}},
		{{}, {}},
		{{}, {}},
		{{}, {}}
	);
	assert(p.solve() == 1);
	puts("pass test 1");
}

void test_2() {
	Problem p(
		2,
		{0, -2, -2},
		{0, +2, +2},
		{[](int) { return 1; }, [](int x) { return -x; }, [](int x) { return +x; }},
		{{}, {2}, {}},
		{{}, {-4}, {}},
		{{}, {+4}, {}},
		{{}, {[](int x) { return (x - 3) * (x - 3); }}, {}}
	);
	Data ans = INFINITY;
	for (int i = -2; i <= 2; i++)
		for (int j = -2; j <= 2; j++)
		for (int k = -4; k <= 4; k++)
		if (i - j <= k)
		ans = std::min(
			ans,
			Data(-i + j + (k - 3) * (k - 3))
		);
	assert(p.solve() == ans);
	puts("pass test 2");
}

void test_3() {
	Problem p(
		2,
		{0, -2, -2},
		{0, +2, +2},
		{[](int) { return 1; }, [](int x) { return -x; }, [](int x) { return +x; }},
		{{}, {2}, {}},
		{{}, {-4}, {}},
		{{}, {+4}, {}},
		{{}, {[](int x) { return (x + 3) * (x + 3); }}, {}}
	);
	Data ans = INFINITY;
	for (int i = -2; i <= 2; i++)
		for (int j = -2; j <= 2; j++)
		for (int k = -4; k <= 4; k++)
		if (i - j <= k)
		ans = std::min(
			ans,
			Data(-i + j + (k + 3) * (k + 3))
		);
	assert(p.solve() == ans);
	puts("pass test 3");
}

#include <iostream>
#include <forward_list>
using namespace std;

#include "Myforward_list.h"

int main(int argc, char* argv[]) {
	forward_list<int> lst;

	lst.push_front(3123);
	lst.push_front(33);
	lst.push_front(33);

	system("pause");
	return 0;
}
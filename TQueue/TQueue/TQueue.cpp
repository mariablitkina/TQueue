#include <iostream>
#include "TQueue.h"

using namespace std;

int main()
{
	TQueue<int> q(1);
	cout << "Queue is:";
	cin >> q;
	cout << q;
	return 0;
}
#include "hugeint.h"
using namespace std;

int main(){
	hugeint x;
	hugeint y(28825252);
	hugeint z("314159265358979323846");
	hugeint result;

	cin >> x;
	result = x + y;
	cout << x << "+" << y << "=" << result << endl;

	result = z-x;
	cout << result << endl;

	return 0;
}

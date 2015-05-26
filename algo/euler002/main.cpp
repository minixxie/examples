#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	unsigned T = 0;
	cin >> T;

	for ( unsigned t = 0 ; t < T ; t++ )
	{

	double N = 0;
	cin >> N;

	unsigned long long prev = 1;
	unsigned long long sum = 2;
	unsigned long long evenValueSum = 2;
	for ( unsigned i = 2 ; i < N ; i++ )
	{
		unsigned long long tmpSum = prev + sum;
		//cout << "i=" << i << ":" << prev << " + " << sum << " = " << tmpSum << endl;
		if ( tmpSum % 2 == 0 )
		{
			if ( tmpSum <= N )
			{
				evenValueSum += tmpSum;
			}
			else
			{
				break;
			}
		}
		prev = sum;
		sum = tmpSum;
	}
	cout << evenValueSum << endl;

	}

    return 0;
}


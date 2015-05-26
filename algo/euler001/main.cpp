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
        unsigned int N = 0;
        cin >> N;
        
        if ( N <= 3 )
        {
            cout << 0 << endl;
	    continue;
        }
        if ( N < 5 && N > 3 )
        {
		cout << 3 << endl;
            continue;
        }
        
    	unsigned long long nFor3 = N / 3;
//cout << "nFor3 = " << nFor3 << endl;
    	if ( N % 3 == 0 )
	{
    		nFor3 = N / 3 - 1;
//cout << "N % 3 == 0: " << nFor3 << endl; 
	}
    	unsigned long long nFor5 = N / 5;
    	if ( N % 5 == 0 )
    		nFor5 = N / 5 - 1;
    	unsigned long long nFor15 = N / 15;
    	if ( N % 15 == 0 )
    		nFor15 = N / 15 - 1;
    		
    	unsigned long long sumFor3 = 3 *  nFor3 * ( nFor3 + 1 ) / 2;
//cout << "sumFor3 = 3 * " << nFor3 << " * ( " << nFor3 << " + 1 ) / 2" << endl;
//cout << "sumFor3 = " << sumFor3 << endl;
    	unsigned long long sumFor5 = 5 *  nFor5 * ( nFor5 + 1 ) / 2;
//cout << "sumFor5 = " << sumFor5 << endl;
    	unsigned long long sumFor15 = 0;
    	if ( N > 15 )
    		sumFor15 = 15 *  nFor15 * ( nFor15 + 1 ) / 2;
//cout << "sumFor15 = " << sumFor15 << endl;
    	
    	unsigned long long sum = sumFor3 + sumFor5 - sumFor15;
        

        cout << sum << endl;
    }
    return 0;
}

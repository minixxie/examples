#include <iostream>

using namespace std;

int main()
{
	int N = 100;
	cin >> N;

	//initialize all true
	unsigned char *nums = new unsigned char [N];
	for ( unsigned int i = 0 ; i < N ; i++ )
	{
		nums[i] = 1;
	}

	for ( unsigned long long f = 2 ; f < N ; f++ )
	{
		//cout << "f = " << f << endl;
		unsigned long long multiple = 1;
		while ( f * multiple <= N )
		{
			unsigned long num = f * multiple;
			//cout << "num (" << num << ") is not prime" << endl;
			if ( multiple > 1 )
			{
				nums[num - 1] = 0;//not primes
			}
			multiple++;
		}
	}

	for ( unsigned long long i = 0 ; i < N ; i++ )
	{
		if ( nums[i] == 1 )
		{
			cout << "[" << i+1 << "] ";
		}
		else
		{
			cout << " " << i+1 << "  ";
		}

		if ( (i+1) % 10 == 0 )
		{
			cout << endl;
		}
	}
	


	delete [] nums;
	nums = 0;

	return 0;
}

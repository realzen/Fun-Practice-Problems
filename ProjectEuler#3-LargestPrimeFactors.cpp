#include<iostream>
#include<cmath>
#include<string>

using namespace std;

void LargestPrimeFactors(long int  x)
{
	
	int i=2;
	cout << "Here " <<endl;
	long int limit = x/4;

	while(i<=limit)
	{
		if(x%i==0)
		{	

			int flag=0;
			int j=2;
			while(j<=i)
			{
				if(i%j==0)
				{
					flag=1;	
					break;	
				}
				j++;
			}
			if(flag==1)
			{
				cout << j <<endl;
			}
		}
		i++;
	}

}


int main()
{

	LargestPrimeFactors(600851475143);
	return 0;
}

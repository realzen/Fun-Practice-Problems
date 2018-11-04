#include<iostream>
/*
 * 2520 is the smallest number that can be divided by each of the 
 * numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible
 * by all of the numbers from 1 to 20?
 */
using namespace std;

int smallestMultiple()
{
	int smallestnum=20;
	int flag=0;

		int n=1;
	while(flag==0)
	{
		n=1;	
		//cout << "Smallest: "<<smallestnum<<endl;
		int flag2=0;
		while( n<=20)
		{
			//cout << "CHECK " << smallestnum << "%" << n << "==" << smallestnum%n <<endl;
			if(smallestnum %n!=0)
			{
				//cout << "BREAK" <<endl;
				flag2=1;
				break;
			}
			if(n==20)
			{
					break;
			}
			n++;
		}
		if(n==20)
		{
				flag=1;
				break;
		}
		smallestnum++;
	}
	return smallestnum;
}
int main()
{
	cout << smallestMultiple();	
	return 0;
}


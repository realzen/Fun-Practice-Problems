#include<iostream>
using namespace std;

/*
 By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

 What is the 10 001st prime number?

*/
bool isItPrime(int x, int i)
{
	if(i==1 )
	{
		return true;
	}
	else 
	{
		if( x%i==0)
		{
			return false;
		}
		else
		{
			return isItPrime(x,i-1);
		}
	}
	
}
int kThPrime(int Pnumber,int itr)
{
	
	
	//BASE CASE TO STOP AT 10,001
	if(itr>=10001)
	{	
		cout << Pnumber <<endl;
	}
	else
	{
		bool flag=isItPrime(Pnumber,itr);
		if(flag==true)
		{
			kThPrime(Pnumber+1,itr+1);
		}
		if(flag==false)
		{
			kThPrime(Pnumber+1,itr);
		}
	}

}
int main()
{
	
	cout << kThPrime(1,2)<<endl;
	return 0;
}



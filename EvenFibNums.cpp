#include<iostream>

using namespace std;
int EvenFibNums(long int x)
{
	//BASE CASE
	if(x==1 || x==0)
	{
			return 1;
	}
	else
	{

		return ((EvenFibNums(x-1)+EvenFibNums(x-2)));
	}
}
int main()
{
	long int i=0;
	long int x=4000000;
	long int sumEven=0;
	while(i<x)
	{
		int num=EvenFibNums(i);
		if(num>x)
		{
				break;
		}
		if(num%2==0)
		{
			cout << num <<endl;
			sumEven+=num;

		}
		
		i++;
	}
	cout<<"THIS IS THE SUM "<<sumEven <<endl;
	return 0;
}

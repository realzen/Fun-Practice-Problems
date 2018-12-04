#include<iostream>

using namespace std;
//FUNCTION TAKES AN INTERGER AND RETURN THE NUMBER OF
//DIGITS THAT INTEGER HAS
int sizeofDigit(int x)
{
	int num=0;
	int n=x;
	while (n!=0)
	{
		num++;
		n=n/10;
	}
	return num;
}
// FUNCTION TAKES AN INTEGER AND RETURNS IF ITS 
// A PALINDROME (T/F)
bool isPalindrome(int x)
{
	
	int n=sizeofDigit(x);
	int arr[n];
	int l=0;
	while(l<n)
	{
		arr[l]=x%10;
		x=x/10;
		l++;
	}
	int end=0;
	if(n%2!=0&& n>3)
	{
		end=n;
		n=n-1;
	}
	else
	{
		end=n-1;
	}
	for(int i=0;i<n;i++)
	{

		if(arr[i]!=arr[end])
		{

				return false;
				break;
		}
		end--;
	}
	return true;
}
int two3DigitPalindrome()
{
	int num1=100;
	int num2=100;
	int check;
	int max=0;
	while(num1 <999)
	{
		num2=100;
		while(num2<999)
		{
			check=num1*num2;
			bool flag=isPalindrome(check);
			if(flag==true && check>max)
			{
				max=check;
			}
			num2++;
		}
		num1++;
	}	
	return max;
}

int main()
{
	cout<< two3DigitPalindrome() <<endl;
	return 0;
	
}

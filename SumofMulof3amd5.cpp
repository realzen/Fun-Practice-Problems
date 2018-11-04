#include<iostream>
using namespace std;
// TAKES AN INTERGER AND FINDS THE SUM OF THE MUTIPLES 
// OF 3 AND FIVE UNDER THAT NUMBER IE(10 HAS 9,5,6,3 WHICH EQUALS 23)
int SumofMultof3and5(int x)
{
	/*
	//x=x-1;
	
	// INITIALIZE IT TO 8 BECAUSE OUR LOOP WHILE STOP
	// AT 3 AND 5 NOT ADDING THOSE TWO NUMBERS INTO THE SUM
	int sum=3+5;
	
	//COULD ALSO MAKE THE WHILE LOOP GO UNTIL IT HITS 2
	while(x !=3 && x!=5)
	{	
			// FLAG IS TO MAKE SURE WE DODN'T DOUBLE NUMBERS 
			// IN THE SUM VARIABLE.
			int flag=0;
			if(x%3==0)
			{
				flag=1;
				sum+=x;		
			}
			if(x%5==0 && flag!=1)
			{
					sum+=x;
			}
		//DECREASE THE NUMBER 
		x--;
	}*/
	//TRY TO USE RECURSION TO GET THE SAME ANSWER
	//BASE CASE	
	x=x-1;
	if(x==3)
	{
		return 3;
	}
	else 
	{
			if((x%3==0 || x%5==0))
			{
				cout << "This is x->" <<x <<endl;
				return 	x + (SumofMultof3and5(x));
			}
			else
			{
					return SumofMultof3and5(x);
			}
	}
	//RETURN THE SUM
		
	
}

int main()
{
	cout << SumofMultof3and5(1000)<<endl;
		return 0;
}

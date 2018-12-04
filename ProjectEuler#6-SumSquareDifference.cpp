#include<iostream>
using namespace std;
/*The sum of the squares of the first ten natural numbers is,
 *
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 *
 * (1 + 2 + ... + 10)^2 = 552 = 3025
 * Hence the difference between the sum of the squares of the 
 * first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first
 * one hundred natural numbers and the square of the sum.
 * 
 */
// CALCULATES THE SUM OF THE SQUARES OF THE FIRST 100 NUMBERS
int sumOfSquares()
{
	int sum=0;
	for(int i=0;i<=100;i++)
	{
		sum+=i*i;

	}
	return sum;	
}
// CALCULATES THE SQUARE OF THE SUM OF THE FIRST 100 NUMBERS
int squareOfSums()
{

	int sum=0;				
	for(int i=0;i<=100;i++)
	{
		sum+=i;
	}
	return sum*sum;
	

}

int main()
{

	int sumSquares=sumOfSquares();
	int squareSums=squareOfSums();
	int difference = squareSums-sumSquares;
	cout << difference << endl;
	return 0;
}

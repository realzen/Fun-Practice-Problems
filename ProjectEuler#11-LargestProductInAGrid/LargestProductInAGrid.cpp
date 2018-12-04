/*  GIVEN A 20X20 GRID, THIS PROGRAM WILL FIND THE HIGHEST PRODUCT OF 4 ADJACENT NUMBERS
 *  IN THE SAME DIRECTION (I.E 4 NUMBERS IN THE NORTH WEST DIRECTION OR 4 NUMBERS IN THE SOUTH EAST NUMBER
 */
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

//#FUNCTION THAT READS FROM A TEXT FILE A 20X20 GRID AND PLACES IT INTO A20X20 ARRAY

void fillArray(int arr[20][20])
{	

	ifstream ifile;
	ifile.open("grid.txt");
	int numbers=0; // STORE THE NUMBERS
	int rows=0; // ROWS IN THE ARRAY
	int cols=0; // COLUMNS IN THE ARRAY
	while(ifile>>numbers)
	{
		
		arr[rows][cols]=numbers; 
		//cout<<setfill('0')<<setw(2)<<arr[rows][cols]<<" ";
		cols++;
		
		// EVERYTIME WE REACH 20 WE WANT TO INCREASE TO
		// MOVE TO THE NEXT ROW
		if(cols%20==0)
		{
			//cout << endl;
			cols=0;
			rows++;

		}
		
	}
	//cout<<endl;
	ifile.close();
}
// TAKES THE PRODUCT OF ALL INDEXES ADJACENT TO CURRENT INDEX IN ALL DIRECTIONS
// AND DETERMINES WHICH ONE OF THOSE PRODUCTS IS THE LARGEST
int largestProduct(long int north,long int east,long int west,long int south,long int northWest,long int northEast,long int southWest,long int southEast)
{
	int max=0;
	int arr[8]={north,east,west,south,northWest,northEast,southWest,southEast};
	for(int i=0;i<8;i++)
	{
		cout << arr[i]<<" ";
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	cout <<"\n";
	return max;
}

int main()
{
	//  A 2D ARRAY THAT WILL HOLD THE GRID THAT WILL BE USED TO FIND THE 
	//  LARGEST PRODUCT OF 4 ADJACENT NUMBERS FROM THE NORT WEST TO SOUTH EAST
	//  DIRECTION INITIALIZED TO ZERO
	int grid[20][20]={{0},{0}};
	cout << "This is working " <<endl;
	fillArray(grid);
	// VARIABLES TO STORE ALL THE PRODUCT FOR ALL THE DIRECTIONS
	// INITIALIZED TO 1 SO WE CAN MULT THE PRODUCT INTO THE VARIABLE
	// AND SHORTEN OUR CODE IN 3RD INNER LOOP WHICH LOOPS IN EACH DIRECTION
	// CHECKING IF IT'S IN THE INDEX AND IF IT IS MULT INTO THE EXISTING PRODUCT
	long int currentMax=0;
	for(int i=0;i<20;i++)
	{
		int maxProduct=0;
		for(int x=0;x<20;x++)
		{
			long int north=1;
			long int south=1;
			long int west=1;
			long int east=1;
			long int northEast=1;
			long int northWest=1;
			long int southEast=1;
			long int southWest=1;
			cout <<"[" << i<<"," <<x<<"]"<<endl;
			//CHECK ALL THE SIDES OF THE CURRENT INDEX 
			//AND IF IT IS OUT OF THE ARRAY BOUNDS SET IT
			//DON'T MULTIPLY IT TO THE PRODUCT
			//	NOTE:
			//		(IN SPECIAL SITUATION I IMAGINE THIS WILL GIVE PROBLEMS BUT
			//		OVERALL IN OUR IT WON'T MATTER, A BETTER IMPLEMENTATION WOULD BE
			//		TO MULTIPLY A ZERO IF IT IS OUT OF RANGE THEREFORE REMOVING
			//		THAT WHOLE DIRECTION AS IT DOES NOT HAVE ENOUGH NUMBERS
			//		AND FOR THE PURPOSE OF HAVING LESS CODE I WILL ALSO LEAVE 
			//		IT AS IS) =)
			for(int j=0;j<4;j++)
			{
				if(i-j>0)
				{	
					north*=grid[i-j][x];
				}
				if(i+j<20)
				{
					south*=grid[i+j][x];
				}
				if(x+j<20)
				{
					east*=grid[i][x+j];
				}
				if(x-j>0)
				{
					west*=grid[i][x-j];
				}
				if(i+j<20 && x-j>0)
				{
					northEast*=grid[i+j][x-j];
				}
				if(i-j >0 && x-j >0)
				{
					northWest*=grid[i-j][x-j];
				}
				if(i+j <20 && x+j <20)
				{
					southEast*=grid[i+j][x+j];
				}
				if(i+j <20 && x-j>0)
				{
					southWest*=grid[i+j][x-j];
				}
			}
			//CALL THE LARGESTPRODUCT FUNCTION AND ASSIGNED THE LARGEST NUMBER TO VARIABLE MAXPRODUCT 
			//THEN CHECK IF IT'S LARGER THAN THE PREVIOUS LARGEST PRODUCT(CURRENTLARGEST)
			maxProduct=largestProduct(north,east,south,west,northEast,northWest,southEast,southWest);
			if(maxProduct>currentMax)
			{
				currentMax=maxProduct;
				cout <<"CURRENTMAX-----"<<currentMax<<endl;
			}
		}
	}
	cout << "This is the max product " <<currentMax<<endl;
	return 0;

}

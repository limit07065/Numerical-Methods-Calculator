#include <iostream>
using namespace std;

// parameter is reference object and decimal place.
void round(double &x, int dp)
		{
			int temp; bool round=false; double y = 1;
			for(int i=0;i<=dp;i++)
			{
				x*=10;
			}
			temp = x;
			
			if(temp%10>=5)
				round = true;
			temp/=10;
			
			x = temp;
			for(int i=0;i<dp;i++)
			{
				x/=10;
			}
			if(round)
				{
					for(int i=0;i<dp;i++)
						y/=10;
					
					x+=y;
				}
								
		}
		


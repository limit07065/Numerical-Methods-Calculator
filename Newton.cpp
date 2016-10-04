#include <iostream>
#include <iomanip>


using namespace std;

class Newton
{
	private:
		
		double a;
		double fa2;
		double c;
		double fa;
		
		double fc;
		double check;
		int dp;
		double error;
		string line;
		
		
		
		double setF( double x )
		{
		//		Enter f(x) here			//
		
		      return (x*x*x-6*x*x+11*x-6); 
		
		//		Enter f(x) here			//
		}
		
		double setFa2(double x)
		{
		//		Enter f'(x) here		//
		
				return (3*x*x-12*x+11);
			
		//		Enter f'(x) here		//
		}
	
		void setC()
		{
			c = a-(fa/fa2);
			round(c);
			fc=setF(c);
			round(fc);
		}
		
		void round(double &x)
		{
			int temp; bool round=false; double y = 1;
			for(int i=0;i<=dp+1;i++)
			{
				x*=10;
			}
			temp = x;
			
			if(temp%10>=5)
				round = true;
			temp/=10;
			
			x = temp;
			for(int i=0;i<=dp;i++)
			{
				x/=10;
			}
			if(round)
				{
					for(int i=0;i<=dp;i++)
						y/=10;
					
					x+=y;
				}
					
				
			
		}
	
	
	public:
		
		Newton(double a,int dp):a(a),check(1),line("__________________________________________________________________________"),dp(dp)
		{
			error = 0.5;
			for(int i=0;i<dp;i++)
			{
				error /=10;
			}
		}
		
	
		
		void print()		
		{
			cout<<setw(12)<<fixed<<a<<" "<<" "<<setw(12)<<fa<<setw(12)<<fa2<<" "<<setw(12)<<c<<" "<<setw(12)<<fc<<" "<<endl;
			cout<<line<<endl;
		}
		
		double process()
		{
			fa = setF(a);
			fa2 = setFa2(a);
			
			cout<<left<<setw(12)<<"x"<<setw(12)<<"f(x)"<<setw(13)<<"f'(x)"<<setw(12)<<"x2"<<setw(12)<<"f(x2)"<<""<<endl;
			cout<<line<<endl;
			
			while(check>=error)
			{
				fa = setF(a);
				fa2 = setFa2(a);
				setC();
				print();
				
				if(fc>0)
					check = fc;
				else
					check = -fc;
					
				
				
				a = c;
				 
				
				
				
				
			}
			
		}
		
};

int main()
{
	//Set a, b, and decimal places
	
	Newton test(3.8,1);
	
	//string line(10,'A');
	test.process();
	cin.get();
	cin.get();
	return 0;
}



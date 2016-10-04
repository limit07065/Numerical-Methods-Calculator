#include <iostream>
#include <iomanip>


using namespace std;

class FPM
{
	private:
		
		double a;
		double b;
		double c;
		double fa;
		double fb;
		double fc;
		double check;
		int dp;
		
		double error;
		string line;
		
		
		
		double setF( double x )
		{
		//		Enter f(x) here			//
		
		      return (x*x*x+4*x*x-10); 
	
		}
	
		void setC()
		{
			c = (a*fb-b*fa)/(fb-fa);
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
		
		FPM(double a,double b,int dp):a(a),b(b),check(1),line("__________________________________________________________________________"),dp(dp)
		{
			error = 0.5;
			for(int i=0;i<dp;i++)
			{
				error /=10;
			}
		}
		
	
		
		void print()		
		{
			cout<<setw(12)<<fixed<<a<<" "<<setw(12)<<b<<" "<<setw(12)<<fa<<setw(12)<<fb<<" "<<setw(12)<<c<<" "<<setw(12)<<fc<<" "<<endl;
			cout<<line<<endl;
		}
		
		double process()
		{
			fa = setF(a);
			fb = setF(b);
			
			cout<<left<<setw(12)<<"a"<<setw(14)<<"b"<<setw(12)<<"f(a)"<<setw(13)<<"f(b)"<<setw(12)<<"c"<<setw(12)<<"f(c)"<<""<<endl;
			cout<<line<<endl;
			
			while(check>=error)
			{
				setC();
				print();
				
				if(fc>0)
				{
					check=fc;
					b = c;
					fb = fc;
				}
				else
				{
					check =-fc;
					a = c;
					fa = fc;
				}
				
				
				
				
			}
			
		}
		
};

int main()
{
	//Set a, b, and decimal places
	
	FPM test(1,2,4);
	
	//string line(10,'A');
	test.process();
	cin.get();
	cin.get();
	return 0;
}



#include <cmath>
#include <iostream>

using namespace std;

bool isInteger(double a)
{
	if(a - (int)a == 0)
		return true;
	return false;

}

int main()
{
	
		int T3 = (pow(pow(10,10),(double)1/3));
		int T4 = (pow(pow(10,10),(double)1/4));
		int T = 0;
		bool FL = false; 
		int A = 0, B = 0, C = 0, D = 0, E = 0;
		int P = 0;
		int Answer = 0;

		cin>>T;

			for(int i = 0; i < T; i++)
			{
				cin>>A>>B>>C>>D>>E>>P;
				FL = false;
				if(A == 0)							
				{
					for(int i = 0 ; i <= T3; ++i)
						{
							int s = B * i * i * i + C * i * i + D * i + E - P; 
							if(s == 0 )
							{
								Answer = i;
								FL = true;
								break;
							}
						}
				}
				else if(A == 0 && B == 0)							
				{

				if(C == 0) 
				{
					if(D==0)
					{
						if(E == P)
						{
						Answer = 0;
						FL = true;} 
						else {FL = false;}}
					else
					{
					if(P-E < 0) {FL = false;}
					else 
					{
					if((P-E) % D == 0) {Answer = (P-E)/D;
										FL = true;}
					else {
							
							FL = false;}
					}
					}
				}
				else
				{
					for(int i = 0 ; i <= 10001; ++i)
						{
							int s = C * i * i + D * i + E - P; 
							if(s == 0 )
							{
								Answer = i;
								FL = true;
								break;
							}
						}
				}




					/*int	Ds = (D * D) - (4 * C * (E - P));
					if ( Ds < 0 )
					{ 
						FL = false;	
					}
					if ( Ds = 0 )
					{
						double temp =  - ((double)D / 2 * C);
						if(temp > 0)
						{
							if(isInteger(temp))
							{
								Answer = temp;
								FL = true;
							}
						}
					}
					if ( Ds > 0 )
					{
						double x1 = 0.0, x2 = 0.0;
						x1 = (- D + sqrt((double)Ds))/ (2 * C);
						x2 = (- D - sqrt((double)Ds))/ (2 * C);
						if(x1 > 0 && isInteger(x1))
						{
							Answer = x1;
							FL = true;
						}
						else if(x2 > 0 && isInteger(x2))
						{ 
							Answer = x2;
							FL = true;
						}
						else 
							FL = false;
						
					}*/
				}
				else if(A == 0 && B == 0 && C == 0)					
				{
					if (D == 0)
					{
						if(P == E)
						{
						Answer = 0;
						FL = true;
						}
					}
					else 
					{
						double temp = ((double)P - E) / D;
						if(isInteger(temp))
						{
						Answer = temp;
						FL = true;
						}
						else 
							FL = false;
					}
				}
				else									
				{
					for(int i = 0 ; i <= T4; ++i)
					{
						int s = (A * i * i * i * i) + (B * i * i * i) + (C * i * i) + (D * i) + E - P;
						if( s == 0 )
						{
								Answer = i;
								FL = true;
								break;
						}
					}

				}										
				if(FL)
				{
					cout<<Answer<<endl;
				}
				else 
				{
					cout<<"Nope"<<endl;
				}
			}
				
	return 0;
}




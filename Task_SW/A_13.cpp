#include <iostream> 
#include <cmath>
int main() 
{ 
 
	int  k,countCube = 0;
	int* list;

	std::cin >> k;
	
	list = new int[k];
	
	for(int i = 0; i < k; ++i)
	{ 
		int e;
		std::cin >> e;
		list[i] = e;	
	}

	for(int i = 1, j = 0; i < k; ++i, ++j )
	{ 
		int dif = std::abs(list[j] - (list[i]));
		if (dif > 1)
		{
			dif--;
			if (list[j] > list[i])
			{
				list[j] = list[j] - dif;
				countCube = countCube + dif;
			   int r = j;
				while(r > 0)						
				{
					int dif = std::abs(list[r-1] - (list[r]));
					if (dif > 1)
					{
						dif--;
						list[r-1] = list[r-1] - dif;
						countCube = countCube + dif;
						r--;
					}
					else 
						break;
				}
						
			}
			else if (list[j] < list[i])
			{
				list[i] = list[i] - dif;
				countCube = countCube + dif;
			}

		}
	}
/*	for(int i = k-3, j = k-2; i >= 0; --i, --j)
	{
		int dif = std::abs(list[j] - (list[i]));
		if (dif > 1)
		{
			dif--;
			list[i] = list[i] - dif;
			countCube = countCube + dif;
		}	
	
	}
/*		if (j > 0)
		{
			int dif = std::abs(list[j-1] - (list[i-1]));
			if (dif > 1)
			{
				dif--;
				if (list[j-1] > list[i-1])
				{
					list[j-1] = list[j-1] - dif;
					countCube = countCube + dif;
				}
				else if (list[j-1] < list[i-1])
				{
				list[i-1] = list[i-1] - dif;
				countCube = countCube + dif;
				}
			}
		}
	}

/*	for(int i = 1, j = 0; i < k; ++i, ++j )
	{ 
		while(std::abs(list[j] - (list[i])) > 1)
		{
			if (list[j] > list[i])
			{
				list[j]--;
				countCube++;
			}
			else if (list[j] < list[i])
			{
				list[i]--;
				countCube++;
			}
		}*/







		/*if (std::abs(list[j] - (list[i])) > 1)
		{
			if (list[j] > list[i])
				 list[j]--; 
			else list[i]--;
					//list[i] = list[j];
			//++f;*/
		
	std::cout<<countCube;
	
	return 0;
}

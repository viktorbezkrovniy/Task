#include <iostream>
#include <string>


using namespace std;

int decod(string);

int main()
{
	string s;
	cin >> s;
	cout << decod(s);

	return 0;
};

int decod(string s)
{
	int sum = 0;
	for(int i = s.size() - 1; i >= 0; --i)
	{
			if(s[i] == 'I')
			{
				if(i != 0)
				{
					if(s[i - 1] == 'I')
					{
						if(i != 1)
						{
							if (s[i - 2] == 'I')
							{
								sum += 3; 
								i -= 2;
							}
							else { sum += 2; i -= 1;	}
						}
						else {return 2;}
		
					}
					else { sum += 1; }
				}
				else {return 1;}
			}								// end I
			else if(s[i] == 'V')
			{
				if(i != 0)
				{
					if(s[i - 1] == 'I')
					{
						sum += 4;
						i -= 1;
					}
					else {sum += 5;}
					
				}
				else {sum += 5; break;}

			}							// end V
			else if(s[i] == 'X')
			{
				if(i != 0)
				{
					if(s[i - 1] == 'I')
					{
						sum += 9;
						i -= 1;
					}
					else if(s[i - 1] == 'X')
					{
						if(i != 1)
						{
							if(s[i - 2] == 'X')
							{
								sum += 30;
								i -= 2;
							}
							else { sum += 20; i -= 1;}
						
						}
						else {sum += 20; break;}
						
					}
					else {sum += 10;}
					
				}
				else {sum += 10; break;}
			}									// end X
			else if(s[i] == 'L')
			{
				if(i != 0)
				{
					if(s[i - 1] == 'X')
					{
						sum += 40;
						i -= 1;
					}
					else {sum += 50;}
					
				}
				else {sum += 50; break;}
			}									// end L
			else if(s[i] == 'C')
			{
				if(i != 0)
				{
					if(s[i - 1] == 'X')
					{
						sum += 90;
						i -= 1;
					}
					else if(s[i - 1] == 'C')
					{
						if(i != 1)
						{
							if(s[i - 2] == 'C')
							{
								sum += 300;
								i -= 2;
							}
							else { sum += 200; i -= 1;}
						
						}
						else {sum += 200; break;}
						
					}
					else {sum += 100;}
					
				}
				else {sum += 100; break;}
			}									// end C
			else if(s[i] == 'D')
			{
				if(i != 0)
				{
					if(s[i - 1] == 'C')
					{
						sum += 400;
						i -= 1;
					}
					else {sum += 500;}
					
				}
				else {sum += 500; break;}
			}								//  end D
			else if(s[i] == 'M')
			{
				if(i != 0)
				{
					if(s[i - 1] == 'C')
					{
						sum += 900;
						i -= 1;
					}
					else if(s[i - 1] == 'M')
					{
						if(i != 1)
						{
							if(s[i - 2] == 'M')
							{
								sum += 3000;
								i -= 2;
							}
							else { sum += 2000; i -= 1;}
						
						}
						else {sum += 2000; break;}
						
					}
					else {sum += 1000;}
					
				}
				else {sum += 1000; break;}
			}									// end M
	}

	return sum;
};
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Node
{
	public:
		vector <Node *> neighbors;
		int current;
		int index;
		bool isValid;
		
		Node():
			index(0),
			current(0),
			isValid(false)
		{
		};
		Node(int i, int c, bool v):
			index(i),
			current(c),
			isValid(v)

		{};


};




void func(vector<Node*> &all, stack<Node *> &path);
int main()
{
	vector <Node *> all;
	int countN = 0, next = 0, n = 0;
	
	cin>>n;
	for(int i = 0; i <= n; ++i)
	{
		all.push_back(new Node(i, 0, false));
	}


	for(int i = 0; i <= n; ++i)
	{
		cin >> countN;
		
		for(int j = 0; j < countN; ++j)
		{	
			cin >> next;
			all[i]->neighbors.push_back(all[next]);	
		}
	}

	stack<Node *> path;
	path.push(all[0]);
	all[0]->isValid = true;
	int j = 0;
	func(all, path);
	while (path.size() != 0)
	{
		cout << path.top()->index <<" ";
		path.pop();
	}
	

return 0;
}
void func(vector<Node*> &all, stack<Node *> &path)
{
	int n = all.size();
	while(1)
	{
		Node * tmp = path.top();
		if(tmp->current > tmp->neighbors.size())
		{
			tmp->current = 0;
			tmp->isValid = false;
			path.pop();
			continue;
		}
		for(int i = tmp->current; i < tmp->neighbors.size(); ++i)
		{
			if(tmp->neighbors[i]->index == 0)
			{
				if(path.size() == n)
				{
					path.push(all[0]);
					return;
				}
			}
			else if(tmp->neighbors[i]->isValid == false)
			{
				tmp->current = i + 1;
				path.push(tmp->neighbors[i]);
				tmp->neighbors[i]->isValid = true;
				break;
			}
			else if(tmp->neighbors[i]->isValid == true)	
			{
				if(i == tmp->neighbors.size() - 1)
				{
					tmp->current = 0;
					tmp->isValid = false;
					path.pop();
				}
			}
		}
	};
}
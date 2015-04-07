/*
В пятницу вечером, когда все уже разошлись, а MyAttendance всё ещё показывал 37:43 вместо желаемых 40:00,
инженер Гаврюша сидел на рабочем месте и мечтал об отпуске. Да так мечтал, что сам не понял,
как зашёл на сайт онлайн-резервирования авиабилетов, который ему когда-то советовал главный инженер Степан.
Особенностью этого сайта были разные акции от авиаперевозчиков и в этот день Гаврюша попал именно на одну из них. 
Акция гласила, что при одновременной покупке билетов на множество последовательных рейсов между разными городами
необходимо будет заплатить не за все перелёты в сумме, а только за 2 из них, а все остальные билеты достаются в подарок. 
«Хм» - подумал Гаврюша, - «давно я хотел слетать на Ямайку, а прямых рейсов-то нет и не будет... 
Может таки взять побольше билетов, заодно и мир по дороге посмотреть?» 
Конечно же, Гаврюша внимательно иследовал весь сайт, и нашёл маленькую сноску о том,
что заплатить нужно будет за два самых дорогих билета на пути. Помогите Гаврюше посчитать сколько ему придётся заплатить за перелёты,
чтобы слетать из Киева в Кингстон (столицу Ямайки) по самому экономному варианту.

Input format
В первой строке записаны числа N и M (3 ≤ N ≤ 50, N-1 ≤ M ≤ N*(N-1)-1) - количество разных городов с аэропортами и количество доступных авиарейсов соответственно. 

В следующих N строчках записаны строки ci – названия городов, состоящих не более чем из 20 латинских символов. 

Далее в M строчках записаны строки si и fi, а также число wi (1 ≤ wi ≤ 109) – название города вылета, название города прибытия и стоимость билета на рейс между городами соответственно. 

Гарантируется, что «Kiev» и «Kingston» всегда присутствуют в списке городов и между ними нет прямого рейса.

Output format
Выведите одно число – минимальную сумму, которую нужно будет заплатить Гаврюше. 

*/


#include <iostream>
#include <vector>
#include <map>
#include <string>
//#include <random>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>




using namespace std;

class City
{
public:
	vector < pair<City *, int> > neibs;
	string Name;

	City(): 
		Name("")
	{};

	City(string s): 
		Name(s)
	{};
};

int func(map <string, City*> &M);

int main()
{
	map <string, City*> graph;
	int M, N, value;
	string s, s1;
	
	cin >> N >> M;

	for(int i = 0; i < N; ++i)
	{
		cin >> s;
		graph.insert(pair<string, City*>(s, new City(s)));
	};

	for (int i = 0; i < M; ++i)
	{
		cin >> s >> s1 >> value;
		graph[s]->neibs.push_back(pair<City *, int> (graph[s1], value));
	};
	
	cout << func(graph) << endl;



return 0;

};

int func(map <string, City*> &M)
{
	vector <pair<int,int> > temp;
	vector <int> result;
	for(int i = 0; i < 979; ++i)
	{
		temp.push_back(pair <int, int> (0, 0));
	}
	
	string start = "Kiev";
	string end = "Kingston";
	srand ((unsigned) time(NULL));
		for(int i = 0; i < 979; ++i)
		{
			
			start = "Kiev";
			/*random_device rd;
    		mt19937 gen(rd());
			uniform_int_distribution<> dis(1, M[start]->neibs.size());
			int j = dis(gen);*/
			
			int j = rand() % M[start]->neibs.size() + 1;

			do
			{
				if(M[start]->neibs[j - 1].second > temp[i].first)
				{
					temp[i].second = temp[i].first;
					temp[i].first = M[start]->neibs[j - 1].second;
				}
				else if (M[start]->neibs[j - 1].second > temp[i].second)
				{
					temp[i].second = M[start]->neibs[j - 1].second;
				}

				start = M[start]->neibs[j - 1].first->Name;

				//srand (time(NULL));
				j = rand() % M[start]->neibs.size() + 1;
				
			}while((start == end) == 0); //M[start]->neibs[j - 1].first->Name

		}
	
	for(int i = 0; i < 979; ++i)
	{
		result.push_back(temp[i].first + temp[i].second);
	};
	
	sort(result.begin(),result.end());
	
	return result[0];
}
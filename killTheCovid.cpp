#include<bits/stdc++.h>
using namespace std;
class Hexagon
{
public:
	string nameOfHexagon;
	vector<Hexagon*>neighbors;
	Hexagon(string name)
	{
		nameOfHexagon = name;
		for (int i = 0; i < 6; i++)
			neighbors.push_back(NULL);
	}
};
void addHexagon(string name , vector<pair<int, string> >&border, unordered_map<string, Hexagon*>&m)
{
	Hexagon * tempHexagon = new Hexagon(name);
	int i;
	for (i = 0; i < border.size(); i++)
	{
    	(tempHexagon->neighbors)[border[i].first] = m[border[i].second];
		if( (m[border[i].second]->neighbors)[(border[i].first + 3) % 6] == NULL)
		{
     		(m[border[i].second]->neighbors)[(border[i].first + 3) % 6] = tempHexagon;
		}
		else
		{
			cout << "An edge can be shared by two Hexagons only. Invalid Input" << endl;
		}
	}
	m[name] = tempHexagon;
}
void getNeighbors(string name, unordered_map<string, Hexagon*>&m)
{
	Hexagon * requiredHexagon = NULL;
	if (m.count(name) != 0)
		requiredHexagon = m[name];
	else
	{
		cout << "No such Hexagon present" << endl;
		return;
	}
	int i, flag = 0;
	for (i = 0; i < 6; i++)
	{
		if (requiredHexagon->neighbors[i] != NULL)
		{
			if (flag == 0)
			{
				flag = 1;
				cout << "[(" << i << "," << (requiredHexagon->neighbors[i])->nameOfHexagon << ")";
			}
			else
				cout << ", (" << i <<","<< (requiredHexagon->neighbors[i])->nameOfHexagon << ")";
		}
	}
	if (flag == 1)
		cout << "]" << endl;
	else
		cout << "It does not have any neighbors" << endl;
}
void removeHexagon(string name, unordered_map<string, Hexagon*>&m)
{
	Hexagon * requiredHexagon;
	if (m.count(name) != 0)
		requiredHexagon = m[name];
	else
	{
		cout << "No such Hexagon present" << endl;
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		if (requiredHexagon->neighbors[i] != NULL)
		{
			Hexagon * tempHexagon = requiredHexagon->neighbors[i];
			tempHexagon->neighbors[(i + 3) % 6] = NULL;
			requiredHexagon->neighbors[i] = NULL;
		}
	}
	m.erase(name);
	delete (requiredHexagon);
}
int main()
{
	unordered_map<string, Hexagon*>m;
	int temp;
	temp = 1;
	while (temp)
	{
		cout<<endl;
		cout << "1. Enter 1 to find the neighbors of the Hexagon" << endl;
		cout << "2. Enter 2 to add a Hexagon to the cluster" << endl;
		cout << "3. Enter 3 to delete a Hexagon from the cluster" << endl;
		cout << "4. Enter 4 to exit" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			string name;
			cout << "Enter Hexagon name: ";
			cin >> name;
			getNeighbors(name, m);
			break;
		}
		case 2:
		{
			string name;
			cout << "Enter Hexagon name which is to be added: ";
			cin >> name;
			cout << "Enter the number of Hexagons with which it shares its borders: ";
			int num;
			cin >> num;
			int i;
			vector<pair<int, string> >border;
			for (i = 0; i < num; i++)
			{
				cout << "Enter the border number and name of hexagon respectively ";
				string nameOfNeighbor;
				int edge;
				cin >> edge >> nameOfNeighbor;
				border.push_back({edge, nameOfNeighbor});
			}
			addHexagon(name, border, m);
			break;
		}
		case 3:
		{
			string name;
			cout << "Enter Hexagon name which is to be removed: ";
			cin >> name;
			removeHexagon(name, m);
			break;
		}
		case 4:
		{
			temp = 0;
			break;
		}
		default:
			cout << "Invalid Input" << endl;
			break;
		}
	}
	return 0;
}

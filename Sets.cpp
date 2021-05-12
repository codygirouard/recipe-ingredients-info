#include "Sets.h"
using namespace std;

// all functions assume same size vectors (two different lists of ingredients in same order)

// return the union of vectors a & b
vector<bool> Union(vector<bool> a, vector<bool> b)
{
	vector<bool> temp;
	temp.resize(a.size(), 0);
	for (int i = 0; i < a.size(); i++)
	{
		temp[i] = (a[i] || b[i]); // if a[i] or b[i] is true, then temp[i] should be true
	}

	return temp;
}

// return the intersection of vectors a & b
vector<bool> Intersect(vector<bool> a, vector<bool> b)
{
	vector<bool> temp;
	temp.resize(a.size(), 0);
	for (int i = 0; i < a.size(); i++)
	{
		temp[i] = (a[i] && b[i]); // temp[i] should only be true when a[i] and b[i] are true
	}

	return temp;
}

// return the difference between vectors a & b
vector<bool> Difference(vector<bool> a, vector<bool> b)
{
	vector<bool> temp;
	temp.resize(a.size(), 0);
	for (int i = 0; i < a.size(); i++)
	{
		temp[i] = (a[i] - b[i] == 1); // temp[i] is true when b[i] is false and a[i] is true
	}

	return temp;
}

// return symmetric difference of vectors a & b
vector<bool> SymDifference(vector<bool> a, vector<bool> b)
{
	vector<bool> temp;
	temp.resize(a.size(), 0);
	for (int i = 0; i < a.size(); i++)
	{
		if ((a[i] && !(b[i])) || (!(a[i]) && b[i]))
		{
			// temp[i] should be true when exactly one is true and one is false from a[i] and b[i]
			temp[i] = true;
		}
	}

	return temp;
}

// return the complement of a vector
vector<bool> Complement(vector<bool> a)
{
	vector<bool> temp;
	temp.resize(a.size(), 0);
	for (int i = 0; i < a.size(); i++)
	{
		temp[i] = !(a[i]); // temp[i] is the opposite of a[i]
	}

	return temp;
}
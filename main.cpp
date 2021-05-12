/* Cody Girouard

	This program reads in input from a file which contains: available ingredients, dish names, and the dish recipes.
	The available ingredients are comma separated (no spaces unless multiple word ingredient) on the first line of the
	input file. Every line after the first contains the dish name, followed by a colon, followed by the ingredients
	(once again comma separated). This program uses classes and objects in C++ along with set theory implementations.
*/

#include "Dish.h"
using namespace std;

int main()
{
	// hold all dishes in this vector
	vector<Dish> dishes;
	ifstream file;
	char fileName[33];

	// acquire input file from user
	do 
	{
		cout << "Input the file name: ";
		cin >> fileName;
		
		file.open(fileName);

		if (file.fail())
		{
			cout << "Failed to open file.\n";
			cout << "Try again.\n";
		}
	} while (file.fail());

	string line; 
	string ingredient;
	vector<string> uIngredients;
	
	// read in the first line which contains the universal ingredients (ingredients available in the pantry)
	getline(file, line);
	istringstream sStream(line);
	while (getline(sStream, ingredient, ','))
	{
		uIngredients.push_back(ingredient);
	}

	// read in each dish recipe
	while (getline(file, line))
	{
		sStream.clear();
		sStream.str(line);
		vector<string> ingredients;
		
		string food;
		getline(sStream, food, ':');
		while (getline(sStream, ingredient, ','))
		{
			ingredients.push_back(ingredient);
		}

		Dish dish(food, uIngredients);
		if (dish.SetIngredients(ingredients))
		{
			dishes.push_back(dish);
		}
	}

	file.close();
	
	// print out all dishes and the ingredients they use (only dishes that we have all ingredients for)

	printf("%15s:", "Dish Name");

	for (int i = 0; i < uIngredients.size(); i++)
	{
		printf("%10s", uIngredients[i].c_str());
	}
	cout << endl;

	for (int i = 0; i < dishes.size(); i++)
	{
		printf("%15s:", dishes[i].GetName().c_str());
		for (int j = 0; j < uIngredients.size(); j++)
		{
			printf("%10d", dishes[i].Contains(uIngredients[j]));
		}
		cout << endl;
	}

	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";

	// show which ingredients are not used in any of the recipes
	printf("%15s:", "Not Used");

	// set all ingredients to 'used'
	vector<bool> all;
	all.resize(uIngredients.size(), true);
	for (int i = 0; i < dishes.size(); i++)
	{
		// if the ingredient is used, then we set that index to 0 or 'not used'
		all = Difference(all, dishes[i].GetIngredients());
	}
	for (int i = 0; i < all.size(); i++)
	{
		bool temp = all[i];
		printf("%10d", temp);
	}


	cout << endl;

	// display all ingredients that are used at least once in any recipe/dish
	printf("%15s:", "At Least One");

	// get the complement of the 'not used' result from the last section, which gives us the used at least once
	all = Complement(all);
	for (int i = 0; i < all.size(); i++)
	{
		bool temp = all[i];
		printf("%10d", temp);
	}

	cout << endl;

	// display all ingredients that are strictly used more than once
	printf("%15s:", "More Than One");
	vector< vector<bool> > intersections;
	for (int i = 0; i < dishes.size(); i++)
	{
		for (int j = 0; j < dishes.size(); j++)
		{
			if (j != i)
			{
				// find all ingredients that are used in more than one dish
				vector<bool> intersection = Intersect(dishes[i].GetIngredients(), dishes[j].GetIngredients());
				intersections.push_back(intersection);
			}
		}
	}
	
	// make another vector assuming all ingredients are not used
	vector<bool> newAll;
	newAll.resize(uIngredients.size(), 0);
	// for every intersection done, union it with the new vector we made. this results in all ingredients used more than once
	for (int i = 0; i < intersections.size(); i++)
	{
		newAll = Union(newAll, intersections[i]);
	}
	for (int i = 0; i < newAll.size(); i++)
	{
		bool temp = newAll[i];
		printf("%10d", temp);
	}

	cout << endl;

	// display all ingredients that are only used once (no more or less)
	printf("%15s:", "Exactly One");
	
	// we find the set theory difference between all and newAll which gives used the exactly used once ingredients
	all = Difference(all, newAll);
	for (int i = 0; i < all.size(); i++)
	{
		bool temp = all[i];
		printf("%10d", temp);
	}

	cout << endl;

	return 0;
}
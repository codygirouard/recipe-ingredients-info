#include "Dish.h"
using namespace std;

// constructor for dish
Dish::Dish(string name, vector<string> ingredientNames)
{
	food = name;
	this->ingredientNames = ingredientNames;
	ingredients.resize(ingredientNames.size(), 0);

	return;
}

// sets the ingredients for a dish based on list of ingredient names,
// returns false if the dish contains an ingredient not in the pantry
bool Dish::SetIngredients(vector<string> list)
{
	bool haveIngredients = true;
	for (int i = 0; i < list.size(); i++)
	{
		if (UniversalContains(list[i]))
		{
			Insert(list[i]);
		}
		else
		{
			cout << "The dish " << food << " contains " << list[i] << " which is not something we have.\n";
			haveIngredients = false;
		}
	}

	return haveIngredients;
}

// returns true if the ingredient exists in our pantry, false if not
bool Dish::UniversalContains(string ingredient)
{
	for (int i = 0; i < ingredientNames.size(); i++)
	{
		if (ingredientNames[i] == ingredient)
		{
			return true;
		}
	}

	return false;
}

// returns true if the dish contains an ingredient, false if not
bool Dish::Contains(string ingredient)
{
	for (int i = 0; i < ingredientNames.size(); i++)
	{
		if (ingredientNames[i] == ingredient && ingredients[i])
		{
			return true;
		}
	}

	return false;
}

// sets the ingredient to true in the dish recipe, returns false on not found
bool Dish::Insert(string ingredient)
{
	for (int i = 0; i < ingredientNames.size(); i++)
	{
		if (ingredientNames[i] == ingredient)
		{
			ingredients[i] = true;
			return true;
		}
	}

	return false;
}
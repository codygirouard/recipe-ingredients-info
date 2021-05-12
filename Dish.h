#include "Sets.h"

class Dish
{
	public:
		// constructor for dish
		Dish(std::string name, std::vector<std::string> uIngredients);
		
		// sets the ingredients for a dish based on list of ingredient names,
		// returns false if the dish contains an ingredient not in the pantry
		bool SetIngredients(std::vector<std::string> list);
		
		// returns name of the dish
		std::string GetName() {return food;}
		
		// returns list of ingredients to make dish
		std::vector<bool> GetIngredients() {return ingredients;}
		
		// returns true if the dish contains an ingredient, false if not
		bool Contains(std::string ingredient);
	private:
	
		// returns true if the ingredient exists in our pantry, false if not
		bool UniversalContains(std::string ingredient);
		
		// sets the ingredient to true in the dish recipe, returns false on not found
		bool Insert(std::string ingredient);
		
		// dish name
		std::string food;
		
		// list of ingredient names
		std::vector<std::string> ingredientNames;
		
		// list of ingredients used/not used
		std::vector<bool> ingredients;
};
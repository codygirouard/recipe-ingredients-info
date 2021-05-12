#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>

// all functions assume same size vectors (two different lists of ingredients in same order)

// return the union of vectors a & b
std::vector<bool> Union(std::vector<bool> a, std::vector<bool> b);

// return the intersection of vectors a & b
std::vector<bool> Intersect(std::vector<bool> a, std::vector<bool> b);

// return the difference between vectors a & b
std::vector<bool> Difference(std::vector<bool> a, std::vector<bool> b);

// return symmetric difference of vectors a & b
std::vector<bool> SymDifference(std::vector<bool> a, std::vector<bool> b);

// return the complement of a vector
std::vector<bool> Complement(std::vector<bool> a);
#pragma once

#include "string"
#include "iostream"
#include <list>
#include <vector>



using namespace std;


std::vector<std::vector<std::vector<string>>> getCarData(list<string>midList); //gets the car data as an array of 2d arrays ([0] is designation [1] is the value)

std::vector<std::vector<std::vector<string>>> compareCarData(std::vector<std::vector<std::vector<string>>> carData); //compares the array values and eliminates the similarities and gets the car data as 2d array ([0] is designation [1] is the value)

	list<string> getMid_hsn_tsn(string hsn, string tsn);//gets mid list

	list<string> getWamFromMid(string mid);//gets the wheel alignment number from mid

	std::vector<std::vector<string> > getWamData(string wam);//gets the wheel alignment data

	list<string> getMid_manuf_model(string manuf, string model);//gets mid list

	list<string> getManuf(); //gets all manufacturers as list

	list<string> getModel(string manuf);//gets all models from manufacturers as list

	list<string> getWamVariants(string mid);//gets all Variants for the same mid

	void setLanguage(string lang);

	
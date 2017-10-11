
#include "stdafx.h"
#include "string"
#include "iostream"
#include "WAD.h"
#include <clocale>


void coutList(list<string> list_) {
	int count = 1;
	for (auto i : list_) {
		cout << " " << count << " : " << i << endl;
		count++;
	};

}//cout a list of strings

void coutWamData(std::vector<std::vector<string> > wamDataArray) {

	cout << "----------------------------------array-----------------------------------" << endl;
	for (int i = 0; i < wamDataArray.size(); i++) {

		std::cout << " ID : " << i << " : " << wamDataArray[i][0] << " : " << wamDataArray[i][1] << " : " << wamDataArray[i][2] << endl;

	}

}//cout the wheel alignment data array of 2d arrays[0] strings

void coutCarData(std::vector<std::vector<std::vector<string>>> compData) {


	if (compData.size() < 2) {

		cout << compData[0][11][0] << "=" << compData[0][11][1] << endl;

	}
	else {

		for (int car = 0; car < compData.size(); car++) {

			cout << car + 1 << endl;
			for (int carData = 0; carData < compData[0].size(); carData++) {
				if (compData[car][carData][0] != "")
					cout << compData[car][carData][0] << "=" << compData[car][carData][1] << endl;

			}
			cout << endl << endl;
		}

	}


}// couts the cardata array of strings

string selectString(list<string> list_) {
	int count = 1;
	int select = 1;
	cin >> select;
	string selectedString;
	for (auto x : list_) {

		if (select == count)
			selectedString = x;
		count++;

	}
	return selectedString;
}// returns one selected string in a list


int main()
{
	

	setLanguage("english");//sets language only "german" and "english"

	std::setlocale(LC_ALL, "");//setsLocal for right char and symbol consoleoutput

	std::vector<std::vector<string> > wamDataArray(53, std::vector<string>(3));//array for wheel alignment data(53 Ids with 1 textleft 1 value and 1 textright) 
	string mid, wam;

	int option;//two searchoptions over manufacturer and model ore over hsn and tsn numbers
	cout << "Search by manufacturer and vehicle type(1) or hsn and tsn(2) ?" << endl;
	cin >> option;

	if (option == 1)
	{
		cout << "-----------search by manufacturer and model-------------- " << endl;

		string manuf, model;
		list<string> manufList = getManuf();//gets the manufacturer list
		cout << "---------------------------------------------" << endl;
		cout << "Please select manufacturer:" << endl;

		coutList(manufList);//lists all manufacturers on console
		manuf = selectString(manufList); //selects one manufacturer

		list<string> midList;
		list<string> modelList = getModel(manuf);

		cout << "Please enter model:" << endl;
		coutList(modelList);
		model = selectString(modelList);

		midList = getMid_manuf_model(manuf, model);//searches all mids with the same manufacturer and model

		if (midList.front() == "")// no mid found
			return 0;

		list<string> wamList;



		if (midList.size() < 2) {
			wamList = getWamFromMid(midList.front());//searches the wheel alignemt number from the mid
			mid = midList.front();
		}
		else {

			std::vector<std::vector<std::vector<string>>> carData = getCarData(midList);//gets the cardata array(

			std::vector<std::vector<std::vector<string>>> compData = compareCarData(carData);

			coutCarData(compData);

			cout << "------------------------- " << endl;
			cout << "There are more variants please chose one(1-9):" << endl;

			coutList(midList);
			mid = selectString(midList);
			cout << mid << endl;
			wamList = getWamFromMid(mid);

		}
		list<string> wamVariants = getWamVariants(mid);// lists all Variants from the wheel alignemt 
		if (wamList.front() == "")// no wheel alignemt number found
			return 0;

		if (wamList.size()<2)
			wamDataArray = getWamData(wamList.front());//gets the wheel alignemt data from the wam number
		else {

			cout << "------------------------- " << endl;
			cout << "There are more variants please chose one(1-9):" << endl;

			coutList(wamVariants);
			//coutList(wamList);
			wam = selectString(wamList);
			wamDataArray = getWamData(wam);

		}

	}

	if (option == 2)
	{
		std::cout << "-----------search by hsn and tsn-------------- " << endl;
		string hsn, tsn;
		cout << "Please enter hsn number:" << endl;
		cin >> hsn;
		cout << "Please enter tsn number:" << endl;
		cin >> tsn;

		list<string> midList, dataList, wamList;
		midList = getMid_hsn_tsn(hsn, tsn);
		std::vector<std::vector<std::vector<string>>> carData = getCarData(midList);//gets the cardata array(

		std::vector<std::vector<std::vector<string>>> compData = compareCarData(carData);

		coutCarData(compData);

		if (midList.front() == "")
			return 0;


		if (midList.size() < 2) {
			wamList = getWamFromMid(midList.front());
			mid = midList.front();


		}
		else {
			cout << "------------------------- " << endl;
			cout << "There are more variants please chose one(1-9):" << endl;

			coutList(midList);
			mid = selectString(midList);
			cout << mid << endl;
			wamList = getWamFromMid(mid);

		}

		if (wamList.front() == "")
			return 0;


		if (wamList.size()<2)
			wamDataArray = getWamData(wamList.front());
		else {
			list<string> wamVariants = getWamVariants(mid);
			cout << "------------------------- " << endl;
			cout << "There are more variants please chose one(1-9):" << endl;
			coutList(wamVariants);
			//coutList(wamList);

			wam = selectString(wamList);
			wamDataArray = getWamData(wam);

		}

	}


	coutWamData(wamDataArray);

	cout << "enter 0 for exit";
	string ende;
	cin >> ende;
	return 0;
}



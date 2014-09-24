/*
 *Challenge #173[Easy] Unit Calculator
--------------------------------------------------------------------------------
 *You have a 30-centimetre ruler. Or is it a 11.8-inch ruler?
 *Or is it even a 9.7-attoparsec ruler? It means the same thing,
 *of course, but no-one can quite decide which one is the standard. 
 *To help people with this often-frustrating situation you've been
 *tasked with creating a calculator to do the nasty conversion work for you.
 *Your calculator must be able to convert between metres, inches, miles and
 *attoparsecs. It must also be able to convert between kilograms, pounds, 
 *ounces and hogsheads of Beryllium.
---------------------------------------------------------------------------------
 * @uthor Scott Thelemann
 * 
 * @version 1.0 08/14/14 
 *
 */



#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
	//variables set to the different time of lengths/weights that can be converted
	const string meters = "meters", meter = "meter";
	const string centimeters = "centimeters", centimeter = "centimeter";
	const string inches = "inches", inch = "inch";
	const string miles = "miles", mile = "mile";
	const string attoparsecs = "attoparsecs", attoparsec = "attoparsec";

	const string kilograms = "kilograms", kilogram = "kilogram";
	const string pounds = "pounds", pound = "pound";
	const string ounces = "ounces", ounce = "ounce";
	const string hogsheads = "hogsheads", hogshead = "hogshead";

	//vector that holds conversions from meters to centimeters/inches/miles/attoparsecs
	vector<double> conversion_length = {100, 39.3701, 0.000621371, 32.4077929};
	//vector that holds conversion from kilograms to pounds/ounces/hogsheads
	vector<double> conversion_weight = {2.20462, 35.274, 0.0034915};

	//variables used to hold various inputs/conversions
	string input;
	string unit_from;
	string unit_to;
	string to;
	double amount;
	double in_meters;
	double in_kilograms;
	double new_amount;
	bool is_length = false;
	bool is_weight = false;
	bool incorrect_conversion = true;

	//loop that runs through the 4 string inputed by user and stores them to correct variable
	for(int i = 1; i <= 4; ++i) {
		switch(i) {
			case 1:
				cin >> amount;
				break;
			case 2:
				cin >> unit_from;
				break;
			case 3:
				cin >> to;
				break;
			case 4:
				cin >> unit_to;
				break;
		}
	}

	//vector that holds the various lengths that can be converted
	vector<string> lengths = {"meter", "meters", "centimeter", "centimeters", "inch", "inches"
							  "mile", "miles", "attoparsec", "attoparsecs"};

	//vector that holds the various weights that can be converted
	vector<string> weights = {"kilogram", "kilograms", "pound", "pounds", "ounce", "ounces", "hogshead", "hogsheads"};

	//loop that tests if unit_from & unit_to are lengths or not
	for(auto beg = lengths.begin(); beg != lengths.end(); ++beg) {
		if(*beg == unit_from) {
			is_length = true;
		}
		else if(*beg == unit_to) {
			incorrect_conversion = false;
		}
	}

	//if statment returns message that units can not be converted if user inputs length and weight to be converted
	if(incorrect_conversion == true) {
		cout << amount << " " << unit_from << " can't be converted to " << unit_to << endl;
		return -1;
	}
	
	//loop that tests if unit_from & unit_to are weights or not
	for(auto beg = weights.begin(); beg != weights.end(); ++beg) {
		if(*beg == unit_from) {
			is_weight = true;
		}
		else if(*beg == unit_to) {
			incorrect_conversion = false;
		}
	}

	//if statment returns message that units can not be converted if user inputs length and weight to be converted
	if(incorrect_conversion == true) {
		cout << amount << " " << unit_from << " can't be converted to " << unit_to << endl;
		return -1;
	}

	//if statments used to convert lengths if unit_to & unit_from are lengths
	if(is_length == true) {
		if(unit_from == centimeter || unit_from == centimeters) {
			in_meters = (amount / conversion_length[0]);
		}
		else if(unit_from == inch || unit_from == inches) {
			in_meters = (amount / conversion_length[1]);
		}
		else if(unit_from == mile || unit_from == miles) {
			in_meters = (amount / conversion_length[2]);
		}
		else if(unit_from == attoparsec || unit_from == attoparsecs) {
			in_meters = (amount / conversion_length[3]);
		}
		else {
			in_meters = amount;
		}

		if(unit_to == centimeter || unit_to == centimeters) {
			new_amount = (in_meters * conversion_length[0]);
		}
		else if(unit_to == inch || unit_to == inches) {
			new_amount = (in_meters * conversion_length[1]);
		}
		else if(unit_to == mile || unit_to == miles) {
			new_amount = (in_meters * conversion_length[2]);
		}
		else if(unit_to == attoparsec || unit_to == attoparsecs) {
			new_amount = (in_meters * conversion_length[3]);
		}
		else {
			new_amount = in_meters;
		}
	}
	
	//if statments used to convert weights if unit_to & unit_from are weights
	if(is_weight == true) {
		if(unit_from == pound || unit_from == pounds) {
			in_kilograms = (amount / conversion_weight[0]);
		}
		else if(unit_from == ounce || unit_from == ounces) {
			in_kilograms = (amount / conversion_weight[1]);
		}
		else if(unit_from == hogshead || unit_from == hogsheads) {
			in_kilograms = (amount / conversion_weight[2]);
		}
		else {
			in_kilograms = amount;
		}

		if(unit_to == pound || unit_to == pounds) {
			new_amount = (in_kilograms * conversion_weight[0]);
		}
		else if(unit_to == ounce || unit_to == ounces) {
			new_amount = (in_kilograms * conversion_weight[1]);
		}
		else if(unit_to == hogshead || unit_to == hogsheads) {
			new_amount = (in_kilograms * conversion_weight[2]);
		}
		else {
			new_amount = in_kilograms;
		}
	}	

	//prints the conversion to the screen
	cout << amount << " " << unit_from << " is " << new_amount << " " << unit_to << endl;
	return 0; 

}
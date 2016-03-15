#include <iostream>	//library for input/output 
#include <string>	//library for strings
#include <fstream>	//for the file opening
#include <iomanip>	//library for setw
using namespace std;
//Identifiers for void and value returning functions
void evaluate_cholesterol(int, int, string&, string&);
void evaluate_blood_pressure(int, int, string&, string&);
float ratio_value(int, int , string& );

int main()
{
	char patient_type;	//declaring character values
	int numVisit, hdl, ldl, systolic, diastolic, num_of_patient; //declaring interger values
	float ratio;
	string name, hdl_evaluation = "", ldl_evaluation = "", evaluateCholesterol, ratio_evaluation = "";
	string systolic_evaluation = "", diastolic_evalution = "";
	ifstream myfile;	//file into code
	myfile.open("infile.txt"); // opens the file
	cout << "Please enter the number of patient's records: "; //display for user to enter number of patient
	cin >> num_of_patient; // stores the number of patient
	cout << "\n" << endl;
	for (int x = 0; x < num_of_patient; x++) //for statement to loop the number of patient
	{
		myfile >> name >> patient_type >> numVisit;
		if (patient_type == 'C')
			cout << "Current Patient's Name- " << name << "\n" << endl;
		else if (patient_type == 'N')
			cout << "New Patient's Name- " << name << "\n" << endl;
		else if (patient_type == 'F')
			cout << "Referral Patient's Name- " << name << "\n" << endl;
		else 
			cout << "Returning Patient's Name- " << name << "\n" << endl;
		for (int y = 0; y < numVisit; y++) //nested for loop statement to loop the the number of visit
		{
			myfile >> hdl >> ldl >> systolic >> diastolic;
			evaluate_cholesterol(hdl, ldl, hdl_evaluation, ldl_evaluation);
			evaluate_blood_pressure(systolic, diastolic, systolic_evaluation, diastolic_evalution);
			cout << "DATA SET " << y + 1 << "\nCholesterol Profile" << endl;
			cout << " HDL: " << hdl << " LDL: " << ldl << endl;
			cout << " Ratio: " << fixed << setprecision(4) << ratio_value(hdl, ldl, ratio_evaluation) << endl;
			cout << " HDL is " << hdl_evaluation << endl;
			cout << " LDL is " << ldl_evaluation << endl;;
			cout << " Ratio of HDL to LDL " << ratio_evaluation << endl;
			cout << "Blood Pressure Profile" << endl;
			cout << " Systolic: " << systolic << " Diastolic: " << diastolic << endl;
			cout << " Systolic reading is " << systolic_evaluation << endl;
			cout << " Diastolic reading is " << diastolic_evalution << endl;
			cout << "\n" << endl;
		}

	
	}
	system("pause");
}

void evaluate_cholesterol(int hdl, int ldl, string& hdl_evaluation, string& ldl_evaluation) //void function to evaluate the cholestrol
{
	if (hdl >= 60)
		hdl_evaluation = "Excellent";
		else if (hdl >= 40)
			hdl_evaluation = "Is Okay";
			else
				hdl_evaluation = "Too Low";
	if (ldl >= 190)
		ldl_evaluation = "Very High";
		else if (ldl >= 160)
			ldl_evaluation = "High";
			else if (ldl >= 130)
				ldl_evaluation = "Borderline high";
				else if (ldl >= 100)
					ldl_evaluation = "Near Optimal";
					else 
						ldl_evaluation = "Optimal";
	

}

void evaluate_blood_pressure(int systolic, int diastolic, string& systolic_evaluation, string& diastolic_evalution)
{
	if (systolic < 120)
		systolic_evaluation = "Optimal";
		else if (systolic < 130)
			systolic_evaluation = "Normal";
			else if (systolic < 140)
				systolic_evaluation = "Normal high";
				else if (systolic < 160)
					systolic_evaluation = "Stage 1 hypertension";
					else if (systolic < 180)
						systolic_evaluation = "Stage 2 hypertension";
						else
							systolic_evaluation = "Stage 3 hypertension";
	if (diastolic < 80)
		diastolic_evalution = "Optimal";
		else if (diastolic < 85)
			diastolic_evalution = "Normal";
			else if (diastolic < 90)
				diastolic_evalution = "Normal high";
				else if (diastolic < 100)
					diastolic_evalution = "Stage 1 hypertension";
					else if (diastolic < 110)
						diastolic_evalution = "stage 2 hypertension";
						else 
							diastolic_evalution = "Stage 3 hypertension";

}

float ratio_value(int hdl, int ldl, string& ratio_evaluation) //value returning function for ratio and for reference
{
	float ratio;
	ratio = float (hdl) / float (ldl);
	
	if (ratio > 0.3)
		ratio_evaluation = "is good";
	else
		ratio_evaluation = "is not good";
	return ratio;
}

/*
Please enter the number of patient's records: 4


Current Patient's Name- Jones

DATA SET 1
Cholesterol Profile
HDL: 60 LDL: 124
Ratio: 0.4839
HDL is Excellent
LDL is Near Optimal
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 130 Diastolic: 84
Systolic reading is Normal high
Diastolic reading is Normal


DATA SET 2
Cholesterol Profile
HDL: 65 LDL: 121
Ratio: 0.5372
HDL is Excellent
LDL is Near Optimal
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 133 Diastolic: 80
Systolic reading is Normal high
Diastolic reading is Normal


DATA SET 3
Cholesterol Profile
HDL: 70 LDL: 120
Ratio: 0.5833
HDL is Excellent
LDL is Near Optimal
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 130 Diastolic: 81
Systolic reading is Normal high
Diastolic reading is Normal


New Patient's Name- Smith

DATA SET 1
Cholesterol Profile
HDL: 30 LDL: 195
Ratio: 0.1538
HDL is Too Low
LDL is Very High
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 120 Diastolic: 85
Systolic reading is Normal
Diastolic reading is Normal high


Referral Patient's Name- Williams

DATA SET 1
Cholesterol Profile
HDL: 45 LDL: 185
Ratio: 0.2432
HDL is Is Okay
LDL is High
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 190 Diastolic: 112
Systolic reading is Stage 3 hypertension
Diastolic reading is Stage 3 hypertension


DATA SET 2
Cholesterol Profile
HDL: 50 LDL: 181
Ratio: 0.2762
HDL is Is Okay
LDL is High
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 193 Diastolic: 115
Systolic reading is Stage 3 hypertension
Diastolic reading is Stage 3 hypertension


Returning Patient's Name- Foster

DATA SET 1
Cholesterol Profile
HDL: 55 LDL: 165
Ratio: 0.3333
HDL is Is Okay
LDL is High
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 163 Diastolic: 115
Systolic reading is Stage 2 hypertension
Diastolic reading is Stage 3 hypertension


DATA SET 2
Cholesterol Profile
HDL: 65 LDL: 145
Ratio: 0.4483
HDL is Excellent
LDL is Borderline high
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 167 Diastolic: 95
Systolic reading is Stage 2 hypertension
Diastolic reading is Stage 1 hypertension


DATA SET 3
Cholesterol Profile
HDL: 57 LDL: 165
Ratio: 0.3455
HDL is Is Okay
LDL is High
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 163 Diastolic: 105
Systolic reading is Stage 2 hypertension
Diastolic reading is stage 2 hypertension


DATA SET 4
Cholesterol Profile
HDL: 59 LDL: 163
Ratio: 0.3620
HDL is Is Okay
LDL is High
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 165 Diastolic: 108
Systolic reading is Stage 2 hypertension
Diastolic reading is stage 2 hypertension

*/
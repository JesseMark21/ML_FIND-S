#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>
#include <ostream>
using namespace std;

vector<string> splitString(string splitStr, string token){
        vector<string>result;
    while(splitStr.size()){
        int i = splitStr.find(token);
        if(i!=string::npos){
            result.push_back(splitStr.substr(0,i));
            splitStr = splitStr.substr(i+token.size());
            if(splitStr.size()==0)result.push_back(splitStr);
        }else{
            result.push_back(splitStr);
            splitStr = "";
        }
    }
    return result;
}

int main(int argc, char** argv)
{
    ifstream input("data.txt");
    string line;

    ofstream myfile;
    myfile.open("Output.txt");

    string attributes[6][2];
    //Sky
    attributes[0][0] = "Sunny";
    attributes[0][1] = "Rainy";
    //AirTemp
    attributes[1][0] = "Warm";
    attributes[1][1] = "Cold";
    //Humidity
    attributes[2][0] = "Normal";
    attributes[2][1] = "High";
    //Wind
    attributes[3][0] = "Strong";
    attributes[3][1] = "Weak";
    //Water
    attributes[4][0] = "Warm";
    attributes[4][1] = "Cool";
    //Forecast
    attributes[5][0] = "Same";
    attributes[5][1] = "Change";

    
    // <Sunny, Warm, ?, ?, ?, ?>
    vector<string> targetConcept = {attributes[0][0], attributes[1][0], "?", "?", "?","?"};
    myfile<<"Target Concept: <"<< targetConcept[0] << ", " << targetConcept[1] << ", "<< targetConcept[2]<< ", " <<  targetConcept[3]<< ", " << targetConcept[4]<< ", " << targetConcept[5] << ">" << endl;
    
    vector<string> compare;
    vector<string> hypothesis = {"0", "0", "0", "0", "0", "0"};
    myfile<<"Hypothesis: "<< "<" << hypothesis[0]<< ", " << hypothesis[1]<< ", " << hypothesis[2]<< ", " << hypothesis[3]<< ", " << hypothesis[4]<< ", " << hypothesis[5] << ">" << endl;
    myfile<<endl;
    int count = 0;
    while(!input.eof()){
        getline(input, line);
        compare = split(line, " ");
        

        for(int i = 0; i<hypothesis.size(); i++){
            if(compare[6] == "Yes"){
                if(compare[i]!=hypothesis[i]){
                    if(count == 0){
                        hypothesis[i] = compare[i];
                    }
                    else{
                        hypothesis[i] = "?";
                    }
                }

            }
        }
        count ++;
        myfile<<"Training Example "<< count << ": <" << compare[0] << ", " << compare[1] << ", "<< compare[2]<< ", " <<  compare[3]<< ", " << compare[4]<< ", " << compare[5] << ">" << " EnjoySport: " << compare[6] << endl;
        myfile<<"Hypothesis: "<< "<" << hypothesis[0]<< ", " << hypothesis[1]<< ", " << hypothesis[2]<< ", " << hypothesis[3]<< ", " << hypothesis[4]<< ", " << hypothesis[5] << ">" << endl;
        myfile << endl;
 
    }

    vector<string> trainingEx = {"Sunny", "Warm", "High", "Weak", "Cool", "Change", "Yes"};
    myfile<<"Additional Training Example: "<< " <" << trainingEx[0] << ", " << trainingEx[1] << ", "<< trainingEx[2]<< ", " <<  trainingEx[3]<< ", " << trainingEx[4]<< ", " << trainingEx[5] << ">" << " EnjoySport: " << compare[6] << endl;
    for(int i = 0; i<hypothesis.size(); i++){
            if(trainingEx[6] == "Yes"){
                if(trainingEx[i]!=hypothesis[i]){
                    hypothesis[i] = "?";
                }

            }
        }

    
    myfile<<"Hypothesis: "<< "<" << hypothesis[0]<< ", " << hypothesis[1]<< ", " << hypothesis[2]<< ", " << hypothesis[3]<< ", " << hypothesis[4]<< ", " << hypothesis[5] << ">" << endl;
    myfile<<endl;
    myfile<<"Q1: 1 additional example";


}
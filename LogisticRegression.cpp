// Francisco Trejo FDT200000
// CS4375.004 with Karen Mazidi
// Portfolio Component 3:
#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <algorithm>
#include <math.h>
#include <cmath>

using namespace std;



int main(int argc, char** argv)
{
    ifstream inFS; // Input file stream 
    string line;
    string idX, survivedX, sexX, ageX, pclassX;
    const int MAX_LEN = 1100;
    vector<double> survived(MAX_LEN);
    vector<double> sex(MAX_LEN);
    vector<double> age(MAX_LEN);
    vector<double> pclass(MAX_LEN);
    
    vector<double> survivedt(MAX_LEN);
    vector<double> sext(MAX_LEN);
    vector<double> aget(MAX_LEN);
    vector<double> pclasst(MAX_LEN);


    cout << "Opening titanic_project.csv." << endl;

    inFS.open("titanic_project.csv"); // Open file
    if (!inFS.is_open()) {
        cout << "Could not open file titanic_project.csv." << endl;
        return 1;
    }

    cout << "Reading line 1" << endl;
    getline(inFS, line);
    // echo heading 
    cout << "heading: " << line << endl;

    int numObservations = 0;

    while (inFS.good()) {
        getline(inFS, idX, ',');
        getline(inFS, pclassX, ',');
        getline(inFS, survivedX, ',');
        getline(inFS, sexX, ',');
        getline(inFS, ageX, '\n');

        pclass.at(numObservations) = stof(pclassX);
        survived.at(numObservations) = stof(survivedX);
        sex.at(numObservations) = stof(sexX);
        age.at(numObservations) = stof(ageX);
        numObservations++;
        if (numObservations == 800)
            break;
    }

    
    pclass.resize(numObservations);
    survived.resize(numObservations);
    sex.resize(numObservations);
    age.resize(numObservations);

    

    numObservations = 0;
    while (inFS.good()) {
        getline(inFS, idX, ',');
        getline(inFS, pclassX, ',');
        getline(inFS, survivedX, ',');
        getline(inFS, sexX, ',');
        getline(inFS, ageX, '\n');

        pclasst.at(numObservations) = stof(pclassX);
        survivedt.at(numObservations) = stof(survivedX);
        sext.at(numObservations) = stof(sexX);
        aget.at(numObservations) = stof(ageX);
        numObservations++;
        
    }

    pclasst.resize(numObservations);
    survivedt.resize(numObservations);
    sext.resize(numObservations);
    aget.resize(numObservations);

    double msur = 0;
    double mm = 0;
    double wsur = 0;
    double ww = 0;

    for (int i = 0; i <= 799;i++) {
        if (survived[i] == 1 && sex[i] == 1)
            msur++;
        if (sex[i] == 1)
            mm++;
    }
    for (int i = 0; i <= 799;i++) {
        if (survived[i] == 1 && sex[i] == 0)
            wsur++;
        if (sex[i] == 0)
            ww++;
    }
    double mp = msur / mm;
    double logm = log10(mp / (1 - mp));
    cout << "Intercept: " << logm <<"\n";

    double wp = wsur / ww;
    double logw = log10((wp / (1 - wp))/mp);

    cout << "Female: " << logw;


  

    return 0;

}

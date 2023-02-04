// Francisco Trejo FDT200000
// CS4375.004 with Karen Mazidi
// Portfolio Component 1: Data Exploration 
#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <algorithm>
#include <math.h>

using namespace std;

void print_stats(vector <double> vec) { // Print mean, median, sum, and range of the vector
    double count = 0;
    double sum = 0;
    double mean = 0;
    double median = 0;

    for (int i = 0;i < vec.size();i++) { // Calculate the sum
        sum = sum + vec[i];
        count++;

    }
    mean = sum / count; //Calculate the mean 

    sort(vec.begin(), vec.end()); // Sort vector

    if((vec.size() % 2) == 0) { // If the size is even then find the average of the two medians 

        median = (vec[(count / 2)-1] + vec[((count / 2) + 1)-1]) / 2;

    }

    else { // If the size is odd find the median 
        median = vec[((count+1)/2)+1];
    }

    cout << "The sum is: " << sum << endl; // Print

    cout << "The mean is: " << mean << endl;

    cout << "The range is: " << vec[0] << " - " << vec[count-1] << endl; // With vector sorted find the max and min of vector aka the range
    
    cout << "The median is: " << median << endl;
   
}

double covar(vector<double> RM, vector<double> MEDV) { //Find the covariance of the two vectors
    double cov = 0;
    double sumRM = 0;
    double sumMEDV = 0;
    double meanRM = 0;
    double meanMEDV = 0;

    for (int i = 0;i < RM.size();i++) { // Calculate sum and mean of both vectors
        sumRM = sumRM + RM[i];
       
    }
    meanRM =  sumRM/ RM.size();

    for (int i = 0;i < MEDV.size();i++) {
        sumMEDV = sumMEDV + MEDV[i];

    }
    meanMEDV = sumMEDV / MEDV.size();

    for (int i = 0;i < RM.size();i++) { // Begin calculating coveriance with formaula 
        cov = cov + ((RM[i] - meanRM)*(MEDV[i] - meanMEDV)); // Sum of (Xi - XBar) * (Yi - YBar)
    }
    cov = cov / (RM.size() - 1); // Then divide by n-1 to get final result
    return cov; 
}

double cor(vector<double> RM, vector<double> MEDV) { // Find the correlation between both vectors
    double COV = 0;
    double COR = 0;
    double sigmaRM = 0;
    double sigmaMEDV = 0;
    double sumRM = 0;
    double sumMEDV = 0;
    double meanRM = 0;
    double meanMEDV = 0;
    COV = covar(RM, MEDV); // Call on covar to find covariance of the 2 vectors and pass them as parameters

    for (int i = 0;i < RM.size();i++) { // Find sum and mean of the first vector 

        sumRM = sumRM + RM[i];

    }
    meanRM = sumRM / RM.size();
    
    for (int i = 0;i < RM.size();i++) {

        sigmaRM = sigmaRM + pow((RM[i] - meanRM), 2);

    }
    sigmaRM = sqrt((sigmaRM)/(RM.size()-1)); // Find the variance of the first vector 

    for (int i = 0;i < MEDV.size();i++) { // Find sum and mean of the second vector

        sumMEDV = sumMEDV + MEDV[i];

    }
    meanMEDV = sumMEDV / MEDV.size();

    for (int i = 0;i < MEDV.size();i++) {

        sigmaMEDV = sigmaMEDV + pow((MEDV[i] - meanMEDV), 2);

    }
    sigmaMEDV = sqrt((sigmaMEDV) / (MEDV.size() - 1)); // Find the variance of the second vector 

    COR = COV / (sigmaRM * sigmaMEDV); // Calculate final result of correlation using formula Cov(x,y)/ (SigmaX * Sigma)Y
    return COR;

}

int main(int argc, char** argv)
{
    ifstream inFS; // Input file stream 
    string line;
    string rm_in, medv_in;
    const int MAX_LEN = 1000;
    vector<double> rm(MAX_LEN);
    vector<double> medv(MAX_LEN);

    cout << "Opening file Boston.csv." << endl;
    
    inFS.open("Boston.csv"); // Open file
    if(!inFS.is_open()){
        cout << "Could not open file Boston.csv." << endl;
        return 1;
    }

    cout << "Reading line 1" << endl;
    getline(inFS, line);
    // echo heading 
    cout << "heading: " << line << endl;

    int numObservations = 0;
    while (inFS.good()) {
        getline(inFS, rm_in, ',');
        getline(inFS, medv_in, '\n');

        rm.at(numObservations) = stof(rm_in);
        medv.at(numObservations) = stof(medv_in);
        numObservations++;
    }

    rm.resize(numObservations);
    medv.resize(numObservations);

    cout << "new length " << rm.size() << endl;

    cout << "Closing file Boston.csv." << endl;
    inFS.close(); // Close file

    cout << "Number of records: " << numObservations << endl;

    cout << "\nStats for rm" << endl;
    print_stats(rm);

    cout << "\nStats for medv" << endl;
    print_stats(medv);

    cout << "\n Covariance = " << covar(rm, medv) << endl;

    cout << "\n Correlation = " << cor(rm, medv) << endl;

    cout << "\nProgram terminated.";

    return 0;

}






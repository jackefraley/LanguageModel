#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


//int numProbability[9][9] = {};
string modelString;

int main(){
float numProbability[10][10] = {};
ifstream myfile ("langModel.txt");
myfile >> modelString;
//cout << modelString;


for(int i = 0; i < modelString.size() - 1; i++){
    char currentChar = modelString[i];
    char nextChar = modelString[i+1];
    int currentDigit = stoi(string(1, currentChar));
    int nextDigit = stoi(string(1, nextChar));
    //cout << "the " << i << "th number of the string is: " << modelString[i] << "\n";
    numProbability[currentDigit][nextDigit]++;
    //cout << numProbability[currentDigit][nextDigit];
}
    for (int i = 0; i < 10; i++) {
        int total = 0;
        for (int j = 0; j < 10; j++) {
            total += numProbability[i][j];
        }
        if (total > 0) {
            for (int j = 0; j < 10; j++) {
                numProbability[i][j] /= total;
                //numProbability[i][j] *= 100;
            }
        }
    }
        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << "Probability for [" << i << "][" << j << "]: " << numProbability[i][j] << "\n";
        }
    }


    //random seed
    srand(static_cast<unsigned int>(time(nullptr)));
    //new string
    string generatedString;
    //randomly select a new digit
    int initialDigit = rand() % 10;
    generatedString += to_string(initialDigit);

    for (int i = 1; i < 1000; i++) {
        char previousChar = generatedString[i-1];
        int previousDigit = stoi(string(1, previousChar));

        double cumulativeProb = 0.0;
        double currentProb = 0.0;
        double randomValue = static_cast<double>(rand()) / RAND_MAX;

            for (int nextDigit = 0; nextDigit < 10; nextDigit++) {
            currentProb = numProbability[previousDigit][nextDigit];
            cumulativeProb += numProbability[previousDigit][nextDigit];
            if (randomValue <= cumulativeProb) {
                generatedString += to_string(nextDigit);
                break;
            }
        }
    }
    
  /*  srand(static_cast<unsigned int>(time(nullptr)));
    string generatedString;
    int initialDigit = rand() % 10;
    generatedString += to_string(initialDigit);

    for(int n = 0; n < 1000; n++){
        double val = (double)rand() / RAND_MAX;
        for(int nextDigit = 0; nextDigit < 10; nextDigit++){
            int previousDigit = generatedString[n - 1];
            //int currentCol = k;
            //int prevRow = n - 1;
            //int prevCol = k - 1;
            //int nextVal;
            if (numProbability[previousDigit][nextDigit - 1] < val < numProbability[previousDigit][nextDigit]){
                generatedString += to_string(nextDigit);
                break;
            }     
        }
    }
*/

    std::cout << "Generated string: " << generatedString << std::endl;

return 0;
};
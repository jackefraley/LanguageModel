#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string modelString;

int main(){
float numProbability[10][10] = {};
ifstream myfile ("langModel.txt");
myfile >> modelString;

for(int i = 0; i < modelString.size() - 1; i++){
    char currentChar = modelString[i];
    char nextChar = modelString[i+1];
    int currentDigit = stoi(string(1, currentChar));
    int nextDigit = stoi(string(1, nextChar));
    numProbability[currentDigit][nextDigit]++;
}
    for (int i = 0; i < 10; i++) {
        int total = 0;
        for (int j = 0; j < 10; j++) {
            total += numProbability[i][j];
        }
        if (total > 0) {
            for (int j = 0; j < 10; j++) {
                numProbability[i][j] /= total;
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
 
    std::cout << "Generated string: " << generatedString << std::endl;

return 0;
};
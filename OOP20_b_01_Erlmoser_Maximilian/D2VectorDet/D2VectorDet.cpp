#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
using namespace std;

vector<vector<double>> readFile(string fpath) {
    vector<vector<double>> matrix;
    ifstream myfile(fpath);
    if (myfile.is_open()) {
            for (int i = 0; i < 3; i++) {
                string line;
                vector<double> tempVec;
                for (int j = 0; j < 3; j++) {
                    getline(myfile, line, ','); //Funktioniert nur, wenn vor \n ein Komma steht
                    tempVec.push_back(stod(line));
                }
                matrix.push_back(tempVec);
            }
            myfile.close();
    }
    return matrix;
}

double calcDeterminant(vector<vector<double>> vec) {
    double diag1, diag2, diag3; 
    double diag4, diag5, diag6;

    diag1 = vec[0][0] * vec[1][1] * vec[2][2];
    diag2 = vec[0][1] * vec[1][2] * vec[2][0];
    diag3 = vec[0][2] * vec[1][0] * vec[2][1];

    diag4 = vec[0][2] * vec[1][1] * vec[2][0];
    diag5 = vec[0][0] * vec[1][2] * vec[2][1];
    diag6 = vec[0][1] * vec[1][0] * vec[2][2];

    double diagPos = diag1 + diag2 + diag3;
    double diagNeg = diag4 + diag5 + diag6;

    double det = diagPos - diagNeg;

    return det;
}

void coutDet(vector<vector<double>> v, double det){
    cout << "\t" << "[" << v[0][0] << "\t" << v[0][1] << "\t" << v[0][2] << "\t]\n";
    cout << "det" << "\t" << "[" << v[1][0] << "\t" << v[1][1] << "\t" << v[1][2] << "\t] = " << det << "\n";
    cout << "\t" << "[" << v[2][0] << "\t" << v[2][1] << "\t" << v[2][2] << "\t]\n";
}

int main(int argc, const char* argv[])
{
    if (argc != 2)
        return -1;

    string path = argv[1];
    vector<vector<double>>matrix = readFile(path);
    coutDet(matrix, calcDeterminant(matrix));
}

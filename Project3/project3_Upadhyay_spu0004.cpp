/** File: project3_Upadhyay_spu0004.cpp
  * Author: Shanti Upadhyay
  * Auburn ID: 903998817
  * IDE: jGrasp, Compiled with g++
  **Important!: Unable to upload to AU Server. Asked TA Tian Liu for solutions but
  *             they did not work. 
  * No help received on Project 3. 
  *
  **/

#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

bool check_file(string); // Checks to see if file exists
vector<int> read_file(string); // Reads file and stores values
void write_file(string, vector<int>); // Output file for vectors
vector<int> merge(vector<int>, vector<int>); // Merge Sorting
void to_string(string, vector<int>);

int main() {

    // Variables
    ifstream inStream1;
    string file1, file2, file3;
    vector<int> numbers1, numbers2, numbers3;
    int file1_size = 0;
    int file2_size = 0;
     
    // Gets File 1 input
    do {
        cout << "*** Welcome to Shanti's sorting program ***";
        cout << "\nEnter the first input file name: ";
        cin >> file1;
    } while (cin.fail() || !check_file(file1));

    numbers1 = read_file(file1);
    file1_size = numbers1.size();


    // Stores as an array
    int arr1[file1_size];
    for (int i = 0; i < file1_size; ++i) {
        arr1[i] = numbers1[i];
    }

    cout << "The list of 6 numbers in the file " << file1 << " is:\n";

    for (int i = 0; i < file1_size; ++i) {
       cout << arr1[i] << "\n";
    }   

    // Gets File 2 input
    do {
        cout << "\nEnter the second input file name: ";
        cin >> file2;
    } while (cin.fail() || !check_file(file2));

    numbers2 = read_file(file2);
    file2_size = numbers2.size();

    int arr2[file2_size];
    for (int i = 0; i < file2_size; ++i) {
        arr2[i] = numbers2[i];
    }

    cout << "The list of 5 numbers in the file " << file2 << " is:\n";

    for (int i = 0; i < file2_size; ++i) {
        cout << arr2[i] << "\n";
    }

    // Merge files 1 and 2 into numbers3
    numbers3 = merge(numbers1, numbers2);

    int arr3[file1_size + file2_size];
    for (int i = 0; i < (file1_size + file2_size); ++i) {
        arr3[i] = numbers3[i];
    }

    cout << "\nThe sorted list of 11 numbers is: ";
    
    for (int i = 0; i < (file1_size + file2_size); ++i) {
        cout << arr3[i] << " ";
    }

    // Gets File 3(output file) input
    do {
        cout << "\nEnter the output file name: "; 
        cin >> file3;
    } while (cin.fail());

    // File 3 displayed
    write_file(file3, numbers3);

    cout << "*** Please check the new file - " << file3 << " ***\n*** Goodbye. ***" << endl;
}

bool check_file(string file) {

    ifstream stream;
    stream.open(file.c_str());

    if (stream.fail()) {
        return false;
    }
    stream.close();
    return true;
}

vector<int> read_file(string file) {

    ifstream stream;
    vector<int> v;
    int i;
    stream.open(file.c_str());
    while (stream.good()) {
        stream >> i;
        v.push_back(i); 
    }

    stream.close();
    return v;
}

void write_file(string file, vector<int> v) {

    int size = v.size();
    int finalArr[size];

    for (int i = 0; i < size; ++i) {
        finalArr[i] = v[i];
    }

    ofstream outputFile(file.c_str());

    for (int i = 0; i < size; ++i) {
        outputFile << finalArr[i];
    }

    outputFile.close();
}

vector<int> merge(vector<int> v1, vector<int> v2) {

    int a = 0; 
    int b = 0; 
    int sizeV1 = v1.size();
    int sizeV2 = v2.size();
    vector<int> v_Merged;

    while (a < sizeV1 && b < sizeV2) {
        if (v1[a] < v2[b]) {
            v_Merged.push_back(v1[a++]);
        }
        else {
            v_Merged.push_back(v2[b++]);    
        }
    }

    while (a < sizeV1) {
        v_Merged.push_back(v1 [a++]);
    }

    while (b < sizeV2) {
        v_Merged.push_back(v2[b++]);
    }
   return v_Merged;
}

void to_string(string file, vector<int> v) {
    unsigned short i;
}
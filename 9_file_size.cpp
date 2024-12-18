#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void countFileContents(string& filename){
    ifstream file(filename);

    if(!file){
        cerr << "Error opening the file" << endl;
        return;
    }

    int letters = 0, words = 0, lines = 0;
    string line;
    while(getline(file, line)){
        words++;
        lines++;
        for(char ch: line){
            if(isalnum(ch)){
                letters++;
            }
            else if(isspace(ch)){
                words++;
            }
        }

    }

    file.close();
    cout << "Letters: " << letters << endl;
    cout << "Words: " << words << endl;
    cout << "Lines: " << lines << endl;
}

void calculateFileSize(string& filename){
    ifstream file(filename, ios::binary | ios::in);
    if(!file){
        //
        return;
    }

    file.seekg(0 , ios::end);
    int size = file.tellg();
    file.close();
    cout << "File size: " << size << " bytes" << endl;
}

int main(){
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    countFileContents(filename);
    calculateFileSize(filename);

    return 0;
}
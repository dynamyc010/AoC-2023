#include <iostream>
#include <fstream>
#include <list>
using namespace std;

/* SAMPLE INPUT
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet

*/

int getFirstDigit(string input);
int getLastDigit(string input);
int combineDigits(int first, int last);

int main() {
    string temp;
    list<int> numbers;
    ifstream file("data.txt");
    if(file.is_open()){
        while(getline(file, temp)){
            int first = getFirstDigit(temp);
            int last = getLastDigit(temp);
            int combined = combineDigits(first, last);
            cout << combined << endl;
            numbers.push_back(combined);
            //cout << combined << endl;
        }
        file.close();
    }
    // cin >> temp;
    // // do{
    //     int first = getFirstDigit(temp);
    //     int last = getLastDigit(temp);
    //     int combined = combineDigits(first, last);
    //     numbers.push_back(combined);
    //     cout << combined << endl;
    //     cin >> temp;
    // // } while (temp != "done");

    int sum = 0;
    for(int i : numbers){
        sum += i;
    }
    cout << "Sum: " << sum << endl;
    return 0;
};

int getFirstDigit(string input){
    //int temp;
    for (int i = 0; i < input.length(); i++){
        if (isdigit(input[i])){
            string str = input.substr(i, 1);
            // while(i <= input.length() && input[i+1]){
            //     str += input.substr(i+1, 1);
            //     i++;
            // }
            return stoi(str);
        }
    }
    return -1;
}

int getLastDigit(string input){
    //int temp;
    for (int i = input.length(); i >= 0; i--){
        if (isdigit(input[i])){
            string str = input.substr(i, 1);
            // while(i < 0 && isdigit(input[i-1])){
            //     str += input.substr(i-1, 1);
            //     i++;
            // }
            return stoi(str);
        }
    }
    return -1;
    // for (int i = input.length(); i > 0; i--){
    //     if (isdigit(input[i])){
    //         return stoi(input.substr(i, 1));
    //     }
    // }
    // return -1;
}

int combineDigits(int first, int last){
    return first * 10 + last;
}
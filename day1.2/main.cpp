#include <iostream>
#include <fstream>
#include <list>
#include <string.h>
using namespace std;

/* SAMPLE INPUT
two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen
*/

const char* numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

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
            return stoi(str);
        }else{
            for (int j = 0; j < 10; j++){
                if (input.substr(i, 5).compare(0, strlen(numbers[j]), numbers[j]) == 0){
                    return j;
                }
            }
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
        else{
            for (int j = 0; j < 10; j++){
                if (input.substr(i, 5).compare(0, strlen(numbers[j]), numbers[j]) == 0){
                    return j;
                }
            }
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
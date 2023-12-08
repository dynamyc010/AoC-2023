#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/* SAMPLE INPUT
    Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
    Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
    Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
    Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
    Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
*/

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

class Round {
    public:
        int red;
        int green;
        int blue;
        Round(int r, int g, int b){
            red = r;
            green = g;
            blue = b;
        }

        bool IsPossible(){
            if(red > 12 || green > 13 || blue > 14){
                return false;
            }
            return true;
        }


};

class Game{
    public:
        list<Round> rounds;
        Game(string input){
            AddRounds(input);
        }

        void AddRounds(string input){
            Round r = Round(0, 0, 0);

            string filtered = split(input, ':')[1];

            vector<string> rounds = split(filtered, ';');

            for(auto round : rounds){
                auto colors = split(round, ',');

                for(auto color : colors){
                    if(color.find("red") != string::npos){
                        //cout << "[Round " << rounds.size() << "] Red: " << stoi(split(color, ' ')[1]) << endl;
                        r.red = stoi(split(color, ' ')[1]);
                    }
                    else if(color.find("green") != string::npos){
                        //cout << "[Round " << rounds.size() << "] Green: " << stoi(split(color, ' ')[1]) << endl;
                        r.green = stoi(split(color, ' ')[1]);
                    }
                    else if(color.find("blue") != string::npos){
                        //cout << "[Round " << rounds.size() << "] Blue: " << stoi(split(color, ' ')[1]) << endl;
                        r.blue = stoi(split(color, ' ')[1]);
                    }
                }
                this->rounds.push_back(r);
                r = Round(0, 0, 0);
            }
            

        }

        bool IsPossible(){
            for(auto round : rounds){
                if(!round.IsPossible()){
                    return false;
                }
            }
            return true;
        }

        /* Day 2.2 */
        Round MinSetOfCubes(){
            int red = 0;
            int green = 0;
            int blue = 0;

            for(auto round : rounds){
                if(round.red > red){
                    red = round.red;
                }
                if(round.green > green){
                    green = round.green;
                }
                if(round.blue > blue){
                    blue = round.blue;
                }
            }

            return Round(red, green, blue);
        }
};

class Match{
    public:
        list<Game> games;
        Match(string filename){
            ifstream file(filename);

            if(file.is_open()){
                string temp;
                while(getline(file, temp)){
                    games.push_back(Game(temp));
                }
                file.close();
            }
        }

        int SumOfPossibleGames(){
            int sum = 0;
            int i = 0;
            for(auto game : games){
                i++;
                if(game.IsPossible()){
                    sum += i;
                }
            }

            return sum;
        }

        /* Day 2.2 */
        int PowerOfSetOfGames(){
            int power = 0;
            for(auto game : games){
                power += game.MinSetOfCubes().red * game.MinSetOfCubes().green * game.MinSetOfCubes().blue;
            }

            return power;
        }
};

int main() {
    Match m = Match("data.txt");

    /* Day 2.1 */
    cout << m.SumOfPossibleGames() << endl;

    /* Day 2.2 */
    cout << m.PowerOfSetOfGames() << endl;

    return 0;
}
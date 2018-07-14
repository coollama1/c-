#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

vector <string> stringToVector(string animals_string)
{
    vector <string> animals_vector;
    string word = "";
    for(size_t c = 0; c < animals_string.length(); c++)
    {
        while(!isspace(animals_string[c]) && c < animals_string.length())
        {
            word+= animals_string[c];
            c++;
        }
        if(word != "")
        {
            animals_vector.push_back(word);;
            word = "";
        }
    }
    return animals_vector;
}

int main ()
{
    string input;
    cout << "Give me a random string and I'll extract the words" << endl;
    getline(cin, input);
    vector <string> list_of_words = stringToVector(input);
    for(size_t c = 0; c < list_of_words.size(); c++)
    {
        cout << list_of_words[c] << " ";
    }
    cout << endl;

}
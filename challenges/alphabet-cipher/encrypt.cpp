#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

static const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

void adjustLength(string& s1, const string& s2) //Postcond: adjusts the length of s1 to
{                                              //the length of s2 (by repitition)
    string adjustedString = "";               
    for(size_t c = 0; c < s2.length(); c++)
    {
        adjustedString+= s1[c % s1.length()];
    }
    s1 = adjustedString;
}

void toLowerString(string& s1) //Postcond: changes all letters to lowercase
{
    for(size_t c = 0; c < s1.length(); c++)
    {
        s1[c] = tolower(s1[c]);
    }
}

char findOutput(char decrypted_char, char key) //Postcond: returns encrypted character
{                               
    return ALPHABET[(key - 'a' + decrypted_char - 'a')% 26];
}

char findInput(char encrypted_char, char key) //Postcond: returns message character
{                                  
    return ALPHABET[(encrypted_char - 'a' + 'z' - key + 1) % 26];
}

string encrypt (string decrypted_message, string key) //Precond: (message) and (key) have the same length
{                                                    //Postcond: encryted output is returned
    string encrypted_message = "";
    toLowerString(decrypted_message);
    toLowerString(key);
    adjustLength(key, decrypted_message);

    for(size_t c = 0; c < decrypted_message.length(); c++)
    {
        if(decrypted_message[c] >= 'a' && decrypted_message[c] <= 'z')
        {
            encrypted_message+= findOutput(decrypted_message[c], key[c]);
        }            
        else
        {
            encrypted_message+= decrypted_message[c];
        }
    }
    return encrypted_message;
}

string decrypt (string encrypted_message, string key) //Precond: (message) and (key) have the same length
{                                                    //Postcond: decryted message is returned
    string decrypted_message = "";
    toLowerString(encrypted_message);
    toLowerString(key);
    adjustLength(key, encrypted_message);

    for(size_t c = 0; c < encrypted_message.length(); c++)
    {
        if(encrypted_message[c] >= 'a' && encrypted_message[c] <= 'z')
        {
            decrypted_message+= findInput(encrypted_message[c],key[c]);
        }
        else
        {
            decrypted_message+= encrypted_message[c];
        }    
    }
       return decrypted_message;
}

int main ()
{
    string message, key, input;
    string prompt = 
    "Enter any of the following [inputs]\n"
    "[encrypt]      Encrypt user input continuously (crtl + d, to exit)\n"
    "[encrypt-file] Encrypt a txt file\n"
    "[decrypt]      Decrypt user input continuously (crtl + d, to exit)\n"
    "[decrypt-file] Decrypt a txt file\n";
    
    cout << endl << prompt << endl;
    toLowerString(input);
    cin >> input;

    if(input == "encrypt" || input == "[encrypt]")
    {
        cout << "Enter a key" << endl;
        cin >> key;
        cout << "Enter decrypted-message";
        while(getline(cin, message))
        {
            cout << encrypt(message, key) << endl;
        }
    }
    else if(input == "encrypt-file" || input == "[encrypt-file]" || input ==  "decrypt-file" || input == "[decrypt-file]")
    {
        string input_file_location, lines_of_file, output_file_location;
        cout << "Enter a key" << endl;
        cin >> key;
        cout << "Enter input file name" << endl;
        cin >> input_file_location;
        cout << "Enter output file name" << endl;
        cin >> output_file_location;

        ifstream input_file(input_file_location.c_str());
        while(getline(input_file,lines_of_file))
        {
            message+=lines_of_file + '\n';
        }

        ofstream output_file(output_file_location.c_str());

        if(input == "encrypt-file" || input == "[encrypt-file]")
        {
            output_file << encrypt(message,key);
        }
        if(input == "decrypt-file" || input == "[decrypt-file]")
        {
            output_file << decrypt(message,key);
        }
        input_file.close();
        output_file.close();
        cout << "Contents have been saved to " << output_file_location << endl;
    }
    else if(input == "decrypt" || input == "[decrypt]")
    {
        cout << "Enter key" << endl;
        cin >> key;
        cout << "Enter encryted-message";
        while(getline(cin, message))
        {
            cout << decrypt(message, key) << endl;
        }
    }
    else
    {
        cout << "Please enter a valid input" << endl;
    }
        
}
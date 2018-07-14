#include <iostream>
#include <string>

std::string kolakoski(int length) //Precond: length >= 2
{
    std::string sequence = "122";
    
    for(size_t index = 3; index < length && sequence.length() < length; index++)
    {
        char value_at_index = sequence[index - 1]; //index of the sequence starts from 1, not 0
        for(char c = '0'; c < value_at_index && sequence.length() < length; c++)
        {
            sequence += ((index % 2 == 1)? '1' : '2');
        }
    }
    return sequence;
}

void printRatio(std::string sequence)
{
    int ones = 0, twos = 0;
    for(size_t c = 0; c < sequence.length(); c++)
    {
        if(sequence[c] == '1')
        {
            ones++;
        }
        else
        {
            twos++;
        }
    }
    std::cout << ones  << ":" << twos << "\n"; 
}

int main()
{
    std::string sequence = "", ratio_of_sequence = "";
    int length;
    std::cout << "Enter the desired length of your Kolakoski sequence\n";
    std::cin >> length;
    sequence = kolakoski(length);
    std::cout << "Here is the sequence: \n" << sequence << "\n";
    std::cout << "Here is the ratio 1s:2s: \n";
    printRatio(sequence);
}
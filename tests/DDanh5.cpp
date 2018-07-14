//=============================================================//
// Name: Diana Danh
// CSc 103
// Project 5 > Matching Game
//=============================================================//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;

void printNBoard(vector<vector<int> > board){
        //prints elements
       for(int i=0;i<board.size(); i++) {
          for (int j=0;j<board[i].size(); j++) {
              
            if(board[i][j] < 10){ //adding spacing so numbers line up
                cout << " ";
            }
            
            if(board[i][j]<65)
            cout << "  " << board[i][j]; //prints what is in the row ONLY IF IT IS A numbers
            
            else
            cout << "   " << (char)board[i][j]; //prints the char in that spot!!
          }
          
          cout << endl;
       }
}

vector<vector<char> > generateMatchs(int rowsInput, int colsInput) {
    //creates CHAR elements and puts into vector
    vector<char> tempChar; 
    vector<vector<char> > boardChar;
    
    for(int w=0; w<rowsInput; w++){ // fills vector with zeros
        for(int i=0; i<colsInput; i++){
            tempChar.push_back('0');
        }
        boardChar.push_back(tempChar);
        tempChar.clear();
    }
    
    srand (time(NULL));
    char insertChar = 'A';
    int randRow, randCol;
    
    for(int d = 0; d < ((rowsInput*colsInput)/2); d++){
        for(int s = 0; s<2; s++){
            randRow = rand()%rowsInput;
            randCol = rand()%colsInput;
            
            if(boardChar[randRow][randCol] == '0'){ // if zero is there, then replace it with letter
                boardChar[randRow][randCol] = insertChar;
            }
            else {
                s--;
            }
        }
        insertChar++;
    }
    
    return boardChar;
}

void printCBoard(vector<vector<char> > board){ // can delete this later
        //prints elements
       for(int i=0;i<board.size(); i++) {
          for (int j=0;j<board[i].size(); j++) {
              
            if(board[i][j] < 10){ //adding spacing so numbers line up
                cout << " ";
            }
            
            cout << " " << board[i][j]; //prints what is in the row
          }
          
          cout << endl;
       }
}

int main() {
    int rowsInput, colsInput;
    do {
        cout << "Size requirement: product of row x col must be between 16 and 64 and be even" << endl;
        cout << "Enter rows: ";
        cin >> rowsInput;
        cout << "Enter columns: ";
        cin >> colsInput; 
    } while(rowsInput*colsInput<16 || rowsInput*colsInput>64 || ((rowsInput*colsInput)%2 == 1));
    
    //creates NUMBER elements and puts into vector
    int positionNum = 0;
    vector<int> tempNum; 
    vector<vector<int> > boardNums;
    
    for(int w=0; w<rowsInput; w++){ 
        for(int i=0; i<colsInput; i++){
            positionNum++;
            tempNum.push_back(positionNum);
        }
        boardNums.push_back(tempNum);
        tempNum.clear();
    }
    
    vector<vector<int> > boardNumsLastCorrect = boardNums; //copy to another vector

    vector<vector<char> > boardChar = generateMatchs(rowsInput, colsInput);
    
    int amountOfPairs = (rowsInput*colsInput)/2;
    
    cout << "\n \n Allowing 30 seconds per pair" 
         << "\n You will have " << ((amountOfPairs*30)/60) << " minutes and " << ((amountOfPairs*30)%30) 
         << " seconds to find the " << amountOfPairs << " pairs."
         << "\n Let's play \n" << endl;

    printNBoard(boardNumsLastCorrect);
    
    cout << "\n \n \n";
    
    int checkSlot1, checkSlot2, checkRow, checkCol, checkRow2, checkCol2, correctTurns = 0, totalTime=0, timeSec=0;
    bool winGame = false;
    
    while ( correctTurns < amountOfPairs) {
        totalTime = 0;
        auto startTime = chrono::steady_clock::now();
    
        do {
        cout << "Enter first slot to view: ";
        cin >> checkSlot1;
        } while(rowsInput*colsInput < checkSlot1 || checkSlot1 < 1); //re-prompts if number is out of bounds
        
        do {
        cout << "Enter second slot to view: ";
        cin >> checkSlot2; 
        } while(rowsInput*colsInput < checkSlot2 || checkSlot2 < 1 || checkSlot2 == checkSlot1); //re-prompts if number is out of bounds or the same as first guess
        
        checkRow = (checkSlot1- 1)/colsInput; //getting rows and columns to check for the guesses
        checkCol = (checkSlot1 - (checkRow*colsInput))- 1;
        
        checkRow2 = (checkSlot2- 1)/colsInput;
        checkCol2 = (checkSlot2 - (checkRow2*colsInput))- 1;
        
        boardNums[checkRow][checkCol] = boardChar[checkRow][checkCol]; //replacing the number with the eltter for the reveal
        boardNums[checkRow2][checkCol2] = boardChar[checkRow2][checkCol2];
        
        printNBoard(boardNums);
        
        if(boardChar[checkRow][checkCol] == boardChar[checkRow2][checkCol2]){ //if matched!
            if(boardNumsLastCorrect == boardNums) { //re-prompts if previously matched
                cout << "Previously matched" << endl;
            }
            
            else {
            cout << "Match" << endl;
            cout << '\a';
            boardNumsLastCorrect = boardNums;
            correctTurns++;
            }
        }
        
        else {
            boardNums = boardNumsLastCorrect;
            cout << "No Match" << endl;
        }
        
        auto endTime = chrono::steady_clock::now();
        totalTime = chrono::duration_cast<chrono::seconds>(endTime-startTime).count();
        timeSec += totalTime;
        
        if(timeSec > (amountOfPairs*30)) { //if overtime, breaks out of loop
            winGame = false;
            break;
        }
        
        if(amountOfPairs = correctTurns){
            winGame = true;
        }
        

    }
    
    //ending game outputs
    if(winGame) {
        cout << "All matched within " << (timeSec/60) << " minutes and " << timeSec%60 << " seconds";
    }
    
    else {
        cout << "Time has expired"
             << "\n You revealed:" << endl;
        printNBoard(boardNumsLastCorrect);
        cout << "\n All the pairs were at:" << endl;
        printCBoard(boardChar);
    }
}
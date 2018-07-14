#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <algorithm>

using namespace std;

void printNBoard(vector<vector<int> > board){
        //prints elements
       for(int i=0;i<board.size(); i++) {
          for (int j=0;j<board[i].size(); j++) {
              
            if(board[i][j] < 10){ //adding spacing so numbers line up
                cout << " ";
            }
            
            cout << "  " << board[i][j]; //prints what is in the row
          }
          
          cout << endl;
       }
}

void printCBoard(vector<vector<char> > board){
        //prints elements
       for(int i=0;i<board.size(); i++) {
          for (int j=0;j<board[i].size(); j++) {
              
            if(board[i][j] < 10){ //adding spacing so numbers line up
                cout << " ";
            }
            
            cout << "  " << board[i][j]; //prints what is in the row
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
    
    for(int w=0; w<colsInput; w++){
        for(int i=0; i<rowsInput; i++){
            positionNum++;
            tempNum.push_back(positionNum);
        }
        boardNums.push_back(tempNum);
        tempNum.clear();
    }
    
    //creates CHAR elements and puts into vector
    vector<char> tempChar; 
    vector<vector<char> > boardChar;
    
    for(int w=0; w<colsInput; w++){
        for(int i=0; i<rowsInput; i++){
            tempChar.push_back(48);
        }
        boardChar.push_back(tempChar);
        tempChar.clear();
    }
    
    srand (time(NULL));
    char insertChar = 65;
    int boardSize = (rowsInput*colsInput)/2;
    
    for(int d = 0; d < boardSize; d++){
        for(int s = 0; s<2; s++){
            
            int randRow = rand()%(rowsInput + 1);
            int randCol = rand()%colsInput;

            if(boardChar[randRow][randCol] == 48){
                boardChar[randRow][randCol] = insertChar;
            }
            else {
                s--;
            }
        }
        insertChar++;
    }
    
    //printNBoard(boardNums);
    printCBoard(boardChar);
}
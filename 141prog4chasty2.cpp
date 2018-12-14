#include <iostream>                     //cin and cout
#include <cctype>                       //type functions
#include <cstdlib>                      //exit function
using namespace std;

//-----------------------------------------------------------------------------

//this function displays identifying information and instructions for playing DoubleDown. Modified from program 2

void displayIdentifyingInformationAndInstructions()
{
    cout << endl;
    cout << "Author: Cody Hasty" << endl;
    cout << "Program: #4, DoubleDown" << endl;
    cout << "TA: HoangMinh  HuynhNguyen, T 12-1250" << endl;
    cout << "Oct 27, 2016"<< endl;
    cout << "Written in Code::Blocks on Windows 10" << endl << endl;

    cout << "Welcome to the game of DoubleDown, where you try to complete a set" <<endl;
    cout << "of four pieces that are alike.  Players take turns making moves." <<endl;
    cout << "On each move your OPPONENT chooses the piece, then YOU get to" <<endl;
    cout << "place it on the board.  If you create a set of four alike when" <<endl;
    cout << "you place your piece, then you win! A set of four alike can be" <<endl;
    cout << "completed by using four upper case characters, four lower-case" <<endl;
    cout << "characters, four vowels (a,e,i,o,u) or four consonants." << endl << endl;

    cout << "The game level determines which positions can be used in completing" <<endl;
    cout << "four alike pieces.  Level one checks for four alike in every row," <<endl;
    cout << "column, and diagonal.  Level two additionally checks for the pieces" <<endl;
    cout << "in the four corners as well as each cluster of four in each corner." << endl << endl;

    cout << "When prompted for piece to use you may also:" << endl;
    cout << "Enter 's' to change program level." << endl;
    cout << "Enter 'x' to exit the program." << endl << endl;


}

//-----------------------------------------------------------------------------

//printBoard displays the current board state as well as the pieces that arent currently being used

void printBoard(char board[], char unusedPieces[])
{

    cout << "|---------|      Square #" << endl;
    cout << "| " << board[0] <<" "<< board[1] <<" "<< board[2] <<" "<< board[3] <<" |     1  2  3  4" << endl;
    cout << "| " << board[4] <<" "<< board[5] <<" "<< board[6] <<" "<< board[7] <<" |     5  6  7  8" << endl;
    cout << "| " << board[8] <<" "<< board[9] <<" "<< board[10] <<" "<< board[11] <<" |     9 10 11 12" << endl;
    cout << "| " << board[12] <<" "<< board[13] <<" "<< board[14] <<" "<< board[15] <<" |    13 14 15 16" << endl;
    cout << "|---------|" << endl;
    cout << "  Pieces: " << unusedPieces << endl << endl;
}

//-----------------------------------------------------------------------------
//isAnUppercaseSet uses booleans and type functions, returning true if each parameter is uppercase

bool isAnUppercaseSet(char s1, char s2, char s3, char s4)
{
    if (isupper(s1) && isupper(s2) && isupper(s3) && isupper(s4)) {
        return true;
    } else {
        return false;
    }
}

//-----------------------------------------------------------------------------
//isALowercaseSet uses booleans and type functions, returning true if each parameter is lowercase

bool isALowercaseSet(char s1, char s2, char s3, char s4)
{
    if (islower(s1) && islower(s2) && islower(s3) && islower(s4)) {
        return true;
    } else {
        return false;
    }
}

//-----------------------------------------------------------------------------
//isAVowelSet is a little different, since there isnt a char type function readily available
//this function loops through an array with each vowel piece, returning booleans for each individual parameter
//if all four parameters return true (ie they are all vowels, the function returns true

bool isAVowelSet(char s1, char s2, char s3, char s4)
{
    //declare array of vowels to compare parameters to, +1 for null char
    char vowels[11] = "AEIOUaeiou";
    //declare booleans for each parameter to determine if each parameter is a vowel
    bool iss1AVowel = false;
    bool iss2AVowel = false;
    bool iss3AVowel = false;
    bool iss4AVowel = false;

    //for loop to compare parameters to vowel array and return true/false for each
    for(int i = 0; i < 11; i++){
        if (vowels[i] == s1) {
            iss1AVowel = true;
        } else if (vowels[i] == s2) {
            iss2AVowel = true;
        } else if (vowels[i] == s3) {
            iss3AVowel = true;
        } else if (vowels[i] == s4) {
            iss4AVowel = true;
        }
    }
    //return true if all four parameters are vowels
     if (iss1AVowel && iss2AVowel && iss3AVowel && iss4AVowel) {
        return true;
    } else {
        return false;
    }
}

//-----------------------------------------------------------------------------
//isAConsonantSet is the same as isAVowelSet, except it uses consonants instead of vowels

bool isAConsonantSet(char s1, char s2, char s3, char s4)
{
    //declare array of vowels to compare parameters to, +1 for null char
    char consonants[9] = "BCDFbcdf";
    //declare booleans for each parameter to determine if each parameter is a vowel
    bool iss1AConsonant = false;
    bool iss2AConsonant = false;
    bool iss3AConsonant = false;
    bool iss4AConsonant = false;

    //for loop to compare parameters to vowel array and return true/false for each
    for(int i = 0; i < 7; i++){
        if (consonants[i] == s1) {
            iss1AConsonant = true;
        } else if (consonants[i] == s2) {
            iss2AConsonant = true;
        } else if (consonants[i] == s3) {
            iss3AConsonant = true;
        } else if (consonants[i] == s4) {
            iss4AConsonant = true;
        }
    }
    //return true if all four parameters are consonants
     if (iss1AConsonant && iss2AConsonant && iss3AConsonant && iss4AConsonant) {
        return true;
    } else {
        return false;
    }
}
//-----------------------------------------------------------------------------
//isASet combines all the possible win conditions together, making checking for
//win conditions use far less code and time coding

bool isASet(char s1, char s2, char s3, char s4)
{
    if (isAnUppercaseSet(s1, s2, s3, s4) ||
        isALowercaseSet(s1, s2, s3, s4)  ||
        isAVowelSet(s1, s2, s3, s4)      ||
        isAConsonantSet(s1, s2, s3, s4)) {
            return true;
        }else{
            return false;
        }
}
//-----------------------------------------------------------------------------
//checkForWinLevelTwo uses isASet, which uses all of the combination checking functions
//to check for a win for the Level two difficulty win conditions (4 in one corner and all 4 corners)

bool checkForWinLevelTwo(char board[])
{
    if (isASet(board[0], board[1], board[4], board[5]) ||               //1 Corner Wincons
        isASet(board[2], board[3], board[6], board[7]) ||
        isASet(board[8], board[9], board[12], board[13]) ||
        isASet(board[10], board[11], board[14], board[15]) ||

        isASet(board[0], board[3], board[12], board[15])) {               //4 Corner Wincon

        return true;
    } else {
        return false;
    }


}

//-----------------------------------------------------------------------------
//checkForWin utilizes isASet to check for win conditions while using a much smaller
//amount of code compared to checking every possible win condition

bool checkForWin(char board[], int difficultyLevel)
{
    if (isASet(board[0], board[1], board[2], board[3])      ||          //Horizontal Wincons
        isASet(board[4], board[5], board[6], board[7])      ||
        isASet(board[8], board[9], board[10], board[11])    ||
        isASet(board[12], board[13], board[14], board[15])  ||

        isASet(board[0], board[4], board[8], board[12])     ||          //Vertical Wincons
        isASet(board[1], board[5], board[9], board[13])     ||
        isASet(board[2], board[6], board[10], board[14])    ||
        isASet(board[3], board[7], board[11], board[15])    ||

        isASet(board[0], board[5], board[10], board[15])    ||          //Diagonal Wincons
        isASet(board[3], board[6], board[9], board[12])) {
        return true;
    } if (difficultyLevel == 2) {
        if(checkForWinLevelTwo(board)) {
            return true;
        }
    }
    //return false if no win conditions are met
    return false;
}
//-----------------------------------------------------------------------------
//setDifficulty determines if the level two conditions will be checked as win conditions
//If level is set to two, the board is checked for a pre-existing win condition
//if this is the case, the level is set back to one. Otherwise, The new win conditions
//will now be checked

void setDifficulty(char board[], int &difficultyLevel)
{
    cout << "What level of play would you like? 1: Normal, 2: Add corners & groups -->";
    cin >> difficultyLevel;

    if ((difficultyLevel ==2) && checkForWinLevelTwo(board)) {
        cout << "Sorry, changing level would lead to a pre-existing win." << endl;
        cout << "Resetting the level to level 1." << endl;
        difficultyLevel = 1;
    }
    cout << endl << "Difficulty level is now " << difficultyLevel << endl << endl;
}


//-----------------------------------------------------------------------------
//inputMove is a piece of the function makeMove. inputMove keeps track of players'
//turns with moveNumber, and prompts players to input their moves. If s is input,
//the user is prompted to set the difficulty, and goto returns user to beginning
//of function. If x is input, the program is exited.

void inputMove(char board[], int &difficultyLevel, char &movePiece, int &moveLocation, int moveNumber)
{
    label: if (moveNumber%2 != 0) {
        cout << moveNumber <<". Player 2 enter piece, and Player 1 enter destination: ";
    } else {
        cout << moveNumber << ". Player 1 enter piece, and Player 2 enter destination: ";
    }
    cin >> movePiece;
    //if difficulty is changed, prompt used to re-enter movePiece
    if (movePiece == 's'){
        setDifficulty(board, difficultyLevel);
        goto label;
    } else if(movePiece == 'x') {
        cout << "Exiting Program..." << endl;
        exit(0);
    }
    cin >> moveLocation;

}

//-----------------------------------------------------------------------------
//isMoveLegal checks for illegal moves specified in the program description

bool isMoveLegal(char board[], char &movePiece, int &moveLocation, int boardSize)
{
    //for loop to check if movePiece is on the board
    for (int i = 0; i < boardSize; i++){
        if (movePiece == board[i]){
            cout << endl << "*** "<< movePiece <<" is an invalid piece selection." << endl;
            cout << "Please retry move." << endl << endl;
            return false;
        }
    }
    //check to see if moveLocation is legal
    if ((moveLocation < 0) || moveLocation > boardSize) {
        cout << endl << "*** " << moveLocation << " is an invalid location." << endl;
        cout << "Please retry move." << endl << endl;
        return false;
    }
    //check to see if moveLocation is not already taken
    if (board[moveLocation-1] != '.') {
        cout << "*** Board square " << moveLocation << " is not empty." << endl;
        cout << "Please retry move." << endl << endl;
        return false;
    }
    //return true if illegal conditions are not met
    return true;
}

//-----------------------------------------------------------------------------
/*makeMove is a very important function to this program. First, inputMove is called.
Next, a while loop utilizes isMoveLegal, exiting the loop only when the input move
is legal. Next, the board array is modified with the legal move. Finally, the piece used
is removed from the unusedPieces array.
*/


void makeMove(char board[],
              char unusedPieces[],
              char &movePiece,
              int &moveLocation,
              int moveNumber,
              int boardSize,
              int unusedPiecesArraySize,
              int &difficultyLevel)
{

    //input move
    inputMove(board, difficultyLevel, movePiece, moveLocation, moveNumber);
    //check legality of move, prompt players to re-input moves if illegal
    while (!isMoveLegal(board, movePiece, moveLocation, boardSize)){
        inputMove(board, difficultyLevel, movePiece, moveLocation, moveNumber);
    }
    //place chosen legal piece in legal position on board
    board[moveLocation - 1] = movePiece;
    //remove piece from unusedPieces array using for loop
    for (int i = 0; i < unusedPiecesArraySize; i++){
        if (unusedPieces[i] == movePiece){
            unusedPieces[i] = ' ';
        }
    }
}
//-----------------------------------------------------------------------------

int main()
{
    //declare variables

    int boardSize = 16;                                                    //size of board
    int unusedPiecesArraySize = 19;                                        //16 pieces + 3 (one space between each set)

    char board[boardSize+1] = "................";                          //array to hold pieces, with each position initially '.' +1 for null character
    char unusedPieces[unusedPiecesArraySize+1] = "AEIO aeio BCDF bcdf";      //array to hold unused pieces, + 1 (null character)
    char movePiece = '\0';                                                 //hold current piece
    int moveLocation = 0;                                                  //hold current move location
    int moveNumber = 1;                                                    //move counter
    bool isGameDone = false;                                               //bool to determine win condition
    int difficultyLevel = 1;                                               //difficulty level

    displayIdentifyingInformationAndInstructions();                        //print name and how to play

   while (!isGameDone) {                                                  //while loop runs, printing board and making moves until there is a winner or draw
        printBoard(board, unusedPieces);
        makeMove(board, unusedPieces, movePiece, moveLocation, moveNumber, boardSize, unusedPiecesArraySize, difficultyLevel);

        //check for win
        if (checkForWin(board, difficultyLevel)) {
            if (moveNumber%2 == 0){
                cout << endl <<"Congratulations!! Player 2 has won!!" << endl;
            }
            else {
                cout << endl <<"Congratulations!! Player 1 has won!!" << endl;
            }
           isGameDone = true;
           break;
        }
        //exit loop if board is full with no win conditions
        if(moveNumber == boardSize +1) {
            cout << endl << "This game is a draw." << endl;
            isGameDone = true;
        }
        //increment moveNumber
        moveNumber++;
    }
    //print final board
    printBoard(board, unusedPieces);

    //exit program
    cout << endl << "Exiting Program...";
    return 0;
    }



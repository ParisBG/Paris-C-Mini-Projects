#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

void initialize(char[3][3]);
void displayBoard(char[3][3]);
void guiDisplayBoard(char[3][3]);
string promptSelection1();
string promptSelection2();
bool checkForQuit(string, char[3][3], int);
bool convertSelection(string, char[3][3], int);
bool isBoardFull(char[3][3]);
bool gameIsWon(char[3][3], char);
bool promptPlayAgain();

int main() {
	char gameBoard[3][3];
	bool gameOver = false;

	initialize(gameBoard);
	displayBoard(gameBoard);
	//guiDisplayBoard(gameBoard);

	while (!gameOver) {
		if (!checkForQuit(promptSelection1(), gameBoard, 1)) {
			if (checkForQuit(promptSelection2(), gameBoard, 2)) {
				gameOver = true;
			}
		} else {
			gameOver = true;
		}
	}

	if (gameOver == true) {
		promptPlayAgain();
	}

	return 0;
}

bool promptPlayAgain(){
	bool exit = true;
	string again = "n";

	cout << endl << "WOULD YOU LIKE TO PLAY AGAIN? (y/n): ";
	cin >> again;

	if (again == "y" || again == "Y" || again == "yes" || again == "YES" || again == "Yes") {
		main();
	} else {
		exit = true;
	}

	return exit;
}

bool checkForQuit(string rawPosition, char gb[3][3], int playerNum){
	if (rawPosition != "NULL") {
			return convertSelection(rawPosition, gb, playerNum);
	} else {

		//RETURN TRUE FOR QUIT/GAME IS OVER
		return true;
	}

}

void initialize(char gb[3][3]) {

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			gb[r][c] = '*';

		}

	}
}

void displayBoard(char gb[3][3]) {
	cout << endl << "~~~~~~~~~~~~TIC TAC TOE BOARD~~~~~~~~~~~~" << endl << endl;

	for (int r = 0; r < 4; r++) {
		if (r > 0){
			cout << r << ". " ;
		}

		for (int c = 0; c < 3; c++) {

			if (r == 0) {
				switch (c) {
				case 0: cout << " A." ;
					break;
				case 1: cout << " B." ;
					break;
				case 2: cout << " C." ;
					break;
				}

				cout << "   ";

			} else {

					cout << gb[r-1][c];
					cout << "     ";
			}

			if (c == 2) {
				cout << endl << endl;
			}
		}
		
	}

}
void guiDisplayBoard(char gb[3][3]) {
	char buff[500];
	char str[500];

	string name = "adfadf";
	sprintf_s(str, "TEST", name.c_str());
	//cout << "LAUNCHING MESSAGE BOX...";
	MessageBox(NULL, buff, "~~~~~~~~~~~~TIC TAC TOE BOARD~~~~~~~~~~~~", MB_OK | MB_ICONQUESTION);

	int it = 0;
	for (int r = 0; r < 4; r++) {
		if (r > 0) {
			//cout << r << ". ";
			buff[it] = '.';
		}
		
		for (int c = 0; c < 3; c++) {

			if (r == 0) {
				switch (c) {
					case 0: //cout << " A.";
						buff[it] = ' A.';
						break;
					case 1: //cout << " B.";
						buff[it] = ' B.';
						break;
					case 2: //cout << " C.";
						buff[it] = ' C.';
						break;
				}

				//cout << "   ";
				buff[it] = '  ';

			} else {

				//cout << gb[r - 1][c];
				buff[it] = gb[r - 1][c];

				//cout << "     ";
				buff[it] = '    ';

			}

			if (c == 2) {
				//cout << endl << endl;
				buff[it] = ' /n';
				buff[it] = ' /n';

			}
		}
		it++;
	}

}
string promptSelection1() {
	int row = 0;
	string col;
	string position;

	cout << "~~~~~~PLAYER ONE~~~~~~" << endl << endl;

	while (cout << "PLAYER ONE: ENTER A ROW NUMBER(Enter 0 to quit): " && !(cin >> row)) {
		cin.clear(); //clear bad input flag
		//cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "INVALID INPUT!! PLEASE ENTER A ROW NUMBER BETWEEN 1 AND 3..." << endl << endl;
	}


	if (row == 0) {
		return "NULL";

	} else if (row < 0 || row > 3) {
		cin.clear(); //clear bad input flag
		//cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "INVALID INPUT!! PLEASE ENTER A ROW NUMBER BETWEEN 1 AND 3..." << endl << endl;

		promptSelection1();

	} else {

		cout << endl << "PLAYER ONE: ENTER A COLUMN(A, B, C, or 0 to Quit): ";
		cin >> col;

		if (col == "0") {
			return "NULL";

		} else if (col == "A" || col == "B" || col == "C" || col == "a" || col == "b" || col == "c") {
				//cout << endl << "SUCCESS! YOUR SELECTION IS: " << "\"" << (to_string(row) + col) << "\"" << endl;
				position = to_string(row) + "." + col;

			} else {
				cin.clear(); //clear bad input flag
				//cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
				cout << endl << "INVALID SELECTION!!! PLEASE TRY AGAIN..." << endl << endl;

				promptSelection1();
			}
		}
	return position;

}

string promptSelection2() {
	int row = 0;
	string col;
	string position;

	cout << "~~~~~~PLAYER TWO~~~~~~" << endl << endl;

	while (cout << "PLAYER TWO: ENTER A ROW NUMBER(Enter 0 to quit): " && !(cin >> row)) {
		cin.clear(); //clear bad input flag
		//cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "INVALID INPUT!! PLEASE ENTER A ROW NUMBER BETWEEN 1 AND 3..." << endl << endl;
	}

	if (row == 0) {
		return "NULL";
	} else {

		if (row < 0 || row > 3) {
			cin.clear(); //clear bad input flag
			//cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << "INVALID INPUT!! PLEASE ENTER A ROW NUMBER BETWEEN 1 AND 3..." << endl << endl;
			promptSelection2();
		}
	}
	cout << endl << "PLAYER TWO: ENTER A COLUMN(A, B, C, or 0 to Quit): ";
	cin >> col;

	if (col == "0") {
		return "NULL";
	} else {

		if (col == "A" || col == "B" || col == "C" || col == "a" || col == "b" || col == "c") {
			//cout << endl << "SUCCESS! YOUR SELECTION IS: " << "\"" << (to_string(row) + col) << "\"" << endl;
			position = to_string(row) + "." + col;
		} else {
			cin.clear(); //clear bad input flag
			//cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << endl << "INVALID SELECTION!!! PLEASE TRY AGAIN..." << endl << endl;
			promptSelection2();
		}
	}

	return position;

}

bool convertSelection(string position, char gameBoard[3][3], int playerNum) {
	bool gameOver = false;
	char mark = '?';
	string delimiter = ".";
	string row = position.substr(0, position.find(delimiter));
	string col = position.substr(2, position.find(delimiter));

	int finalRow = stoi(row) - 1;
	int finalCol = 0;

	if (col == "A" || col == "a") {
		finalCol = 0;
	} else if (col == "B" || col == "b") {
		finalCol = 1;
	} else if (col == "B" || col == "c") {
		finalCol = 2;
	}

	switch (playerNum) {
	case 1: mark = 'X';
		break;
	case 2: mark = 'O';
		break;
	}

	if (gameBoard[finalRow][finalCol] != '*') {
		cout << endl << "THIS POSITION \"" << row << col << "\" HAS ALREADY BEEN SELECTED! TRY AGAIN..." << endl << endl;

		displayBoard(gameBoard);
		//guiDisplayBoard(gameBoard);

		if (playerNum == 1) {

			if (checkForQuit(promptSelection1(), gameBoard, 1)){
				gameOver = true;
			}

		} else if (playerNum == 2) {
			if (checkForQuit(promptSelection2(), gameBoard, 2)) {
				gameOver = true;
			}
		}

	} else {

		gameBoard[finalRow][finalCol] = mark;

		displayBoard(gameBoard);
		//guiDisplayBoard(gameBoard);

		bool isGameWon = false;

		if (gameIsWon(gameBoard, 'X') || gameIsWon(gameBoard, 'O')) {
			isGameWon = true;
			gameOver = true;

		}
			
		if (isBoardFull(gameBoard)) {
			cout << "************ DRAW **************" << endl << endl;
			gameOver = true;

		}


	}

	return gameOver;
}

bool isBoardFull(char gameBoard[3][3]){
	int openSlots = 0;
	bool full = false;

	for (int r = 0; r < 3; r++) {

		for (int c = 0; c < 3; c++) {

			if (gameBoard[r][c] == '*') {
				openSlots++;
			}
		}
	}

	if (openSlots == 0) {
		full = true;
	}

	return full;

}

bool gameIsWon(char gb[3][3],char player){
	string user;
	bool gameIsWon = false;

	if (player == 'X') {
		user = "Player One";
	} else {
		user = "Player Two";
	}

	//Diagonal backwards
	if (gb[0][2] == player && gb[1][1] == player && gb[2][0] == player) {
		cout << "THREE IN A ROW!! \"" << user << "\" WINS!!!!" << endl << endl;
		gameIsWon = true;

	} else if (gb[0][0] == player && gb[1][1] == player && gb[2][2] == player) {
		//Diagonal Frontwards
		cout << "THREE IN A ROW!! \"" << user << "\" WINS!!!!" << endl << endl;
		gameIsWon = true;

	} else if (gb[0][0] == player && gb[1][0] == player && gb[2][0] == player) {
		//Col 1
		cout << "THREE IN A ROW!! \"" << user << "\" WINS!!!!" << endl << endl;
		gameIsWon = true;

	} else if (gb[0][1] == player && gb[1][1] == player && gb[2][1] == player) {
		//Col 2
		cout << "THREE IN A ROW!! \"" << user << "\" WINS!!!!" << endl << endl;
		gameIsWon = true;

	} else if (gb[0][2] == player && gb[1][2] == player && gb[2][2] == player) {
		//Col 3
		cout << "THREE IN A ROW!! \"" << user << "\" WINS!!!!" << endl << endl;
		gameIsWon = true;

	} else if (gb[0][0] == player && gb[0][1] == player && gb[0][2] == player){
		//CHECKS ROW 1
		cout << "THREE IN A ROW!! \"" << user << "\" WINS!!!!" << endl << endl;
		gameIsWon = true;

	} else if (gb[1][0] == player && gb[1][1] == player && gb[1][2] == player) {
		//CHECKS ROW 2
		cout << "THREE IN A ROW!! \"" << user << "\" WINS!!!!" << endl << endl;
		gameIsWon = true;

	} else if (gb[2][0] == player && gb[2][1] == player && gb[2][2] == player) {
		//CHECKS ROW 3
		cout << "THREE IN A ROW!! \"" << user << "\" WINS!!!!" << endl << endl;
		gameIsWon = true;
	}

	return gameIsWon;
	

}

/*
Tic-Tac-Toe Game

Write a modular program that allows two players to play a game of tic-tac-toe.

-Use a two-dimensional char array with three rows and three columns as the game board.
-Each element of the array should be initialized with an asterisk (*).

-The program should display the initial board configuration and then start a loop that does the following:

	+ Have player 1 select a board location for an X by entering a row and column number.
	+ Then re-display the board with an X replacing the * in the chosen location.
	+ If there is no winner yet and the board is not yet full,
	  have player 2 select a board location for an O by entering a row and column number.
	+ Then redisplay the board with an O replacing the * in the chosen location.

-The loop should continue until a player has won or a tie has occurred,
then display a message indicating who won, or reporting that a tie occurred.

-Player 1 wins when there are three Xs in a row, a column, or a diagonal on the game board.
-Player 2 wins when there are three Os in a row, a column, or a diagonal on the game board.
-A tie occurs when all of the locations on the board are full, but there is no winner.
-Input Validation: Only allow legal moves to be entered.
-The row and column must be 1, 2, or 3.
-The selected board location must currently be empty (i.e., still have an asterisk in it).



*/
// NxN tic-tac-toes
#include <iostream>
using namespace std;

// The following 3 functions are helper functions to convert
// between 1D and 2D array indices.  The grid itself is stored
// as a 1D array.  However, for printing, checking who won,
// etc. it may be easier to write loops that generate separate
// row/column indices (i.e. treating the array like a 2D array).
// The functions below should be written using the hints in the
// writeup for performing the appropriate arithmetic conversion
// between 1D- and 2D-indices, and can then be called in any
// of the other functions when you find yourself wanting to 
// convert one to the other.

/**
 * Helper function - Given the grid array and its dimension
 *    as well as a particular row (r) and column (c), this
 *    function performs the arithmetic to convert r and c
 *    to a 1D index and returns that character in the grid.
 *    For example, for dim = 3 and r = 2, c = 1, this function
 *    should compute the corresponding index: 7 and return
 *    grid[7].
 *
 * Use this function wherever you generate, row/column
 *    indices and want to access that element in the grid.
 *    Pass the row/column indices as r and c, respectively.
 *
 */
char getEntryAtRC(char grid[], int dim, int r, int c);

/**
 * Helper function - Given a 1D index returns the row
 * that corresponds to this 1D index.  Use this in
 * conjunction with idxToCol() anytime you have a 1D index
 * and want to convert to 2D indices.
 */
int idxToRow(int idx, int dim);

/**
 * Helper function - Given a 1D index returns the column
 * that corresponds to this 1D index.  Use this in
 * conjunction with idxToRow() anytime you have a 1D index
 * and want to convert to 2D indices.
 */
int idxToCol(int idx, int dim);


/** Should print the tic-tac-toe board in a nice grid
 *  format as shown below:
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O'
 *         (the letter oh), or '?'.
 */
void printTTT(char grid[], int dim);

/** 
 * Should check if any player has won the game yet.
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *
 * Return value:
 *   Should return 1 if 'X' has won, 2 if 'O' has won, or 0 (zero)
 *   if the game is still undecided.
 * 
 */
int checkForWinner(char grid[], int dim);


/** 
 * Should check if there is no possible way any player can win.
 * More specifically, if there does not exist a row, column,
 * or diagonal that can still have 3 of a kind, then the game
 * will be a draw.
 * 
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *
 * Return value:
 *   Return true if no player can win given the current 
 *   game state, false otherwise.
 */
bool checkForDraw(char grid[], int dim);
 

/**********************************************************
 *  Write your implementations for each function prototyped
 *  above in the space below
 **********************************************************/

char getEntryAtRC(char grid[], int dim, int r, int c)
{
    return grid[(dim * r) + c]; // (3 * 2) + 1 = 7 -> grid[7]
}

int idxToRow(int idx, int dim)
{
    return idx / dim; // 4/3 = 1, 4 is in row 1
}

int idxToCol(int idx, int dim)
{
    return idx % dim; // 4 % 3 = 1, 4 is in column 1
}

void printTTT(char grid[], int dim)
{
  cout << "" << endl;
  for (int r = 0; r < dim; r++) {  
    for (int c = 0; c < dim; c++) { 
      cout << " " << getEntryAtRC(grid, dim, r, c);
      if (c < dim - 1) { // to ensure there is no extra | after the last index in the row
      cout << " |";
      }
    }
    cout << endl;

  if (r < dim - 1) { // to ensure there is no extra row of --- after the last index in the column
    for (int i = 0; i < (dim * 4) - 1; i++) {
      cout << "-";
    }
    cout << endl;
  }
    
  }
}

int checkForWinner(char grid[], int dim)
{
for (int r = 0; r < dim; r++) { // checking rows
  for (int c = 1; c < dim; c++) { // iterating through columns
    if ((getEntryAtRC(grid, dim, r, c - 1) != getEntryAtRC(grid, dim, r, c))) { // first check if the values in the row are != to determine that there is no winner and break from inner loop
      break;
    }
    if ((c == dim - 1) && (getEntryAtRC(grid, dim, r, c )) == '?') { // if the values in one row are equal, but they = a '?', break (this is not a winner)
      break;
    }
    if ((c == dim - 1) && (getEntryAtRC(grid, dim, r, c)) == 'X') { // have to check if c got to the last index in the row to make sure we didn't break entirely out of the loop; checking if the values in the winning row = X
      return 1;
    }
    else if ((c == dim - 1) && (getEntryAtRC(grid, dim, r, c) == 'O')) { // checking if the values in the winning row = O
      return 2;
    }
  }
}

for (int c = 0; c < dim; c++) { // checking columns
  for (int r = 1; r < dim; r++) { // iterating through rows
    if ((getEntryAtRC(grid, dim, r - 1, c) != getEntryAtRC(grid, dim, r, c))) { // first check if the values in the column are != to determine that there is no winner and break from inner loop
      break;
    }
    if ((r == dim - 1) && (getEntryAtRC(grid, dim, r, c)) == '?') { // if the values in one column are equal, but they = a '?', break (this is not a winner)
      break;
    }
    if ((r == dim - 1) && (getEntryAtRC(grid, dim, r, c)) == 'X') { // have to check if r got to the last index in the row to make sure we didn't break entirely out of the loop; checking if the values in the winning column = X
      return 1;
    }
    else if ((r == dim - 1) && (getEntryAtRC(grid, dim, r, c) == 'O')) { // checking if the values in the winning column = O
      return 2;
    }
  }
}

// checking TL to BR diagonal
// use boolean to determine whether or not X or O is present 

bool x = false; 
bool y = false;
for (int i = 0; i < dim; i++) {
  if (getEntryAtRC(grid, dim, i, i) != 'X') {
    x = false;
    break;
  }
  else if (getEntryAtRC(grid, dim, i, i) == 'X') {
    x = true;
  }
}
for (int i = 0; i < dim; i++) {
  if (getEntryAtRC(grid, dim, i, i) != 'O') {
    y = false;
    break;
  }
  else if (getEntryAtRC(grid, dim, i, i) == 'O') {
    y = true;
  }
}
  if (x == true) {
    return 1;
  }
  if (y == true) {
    return 2;
  }

// checking TR to BL diagonal
for (int i = 0; i < dim; i++) {
  if (getEntryAtRC(grid, dim, i, dim - i - 1) != 'X') {
    x = false;
    break;
  }
  else if (getEntryAtRC(grid, dim, i, dim - i - 1) == 'X') {
    x = true;
  }
}
for (int i = 0; i < dim; i++) {
  if (getEntryAtRC(grid, dim, i, dim - i - 1) != 'O') {
    y = false;
    break;
  }
  else if (getEntryAtRC(grid, dim, i, dim - i - 1) == 'O') {
    y = true;
  }
}
  if (x == true) {
    return 1;
  }
  if (y == true) {
    return 2;
  }

  return 0;
}
// checking for draws
 bool checkForDraw(char grid[], int dim) 
{
  bool Xpres = false; 
  bool Opres = false;
  for (int r = 0; r < dim; r++) { // checking rows for draws
    for (int c = 0; c < dim; c++) {
      if ( (getEntryAtRC(grid, dim, r, c)) == 'X') {
        Xpres = true;
      }
      if ((getEntryAtRC(grid, dim, r, c)) == 'O') {
        Opres = true;
      }
    }
  if (!Xpres || !Opres) {
    return false;
  }
  //resetting Xpres and Opres to ensure they are not present when first checking the next row
  Xpres = false; 
  Opres = false;
}

Xpres = false;
Opres = false;
for (int c = 0; c < dim; c++) { // checking columns for draws
    for (int r = 0; r < dim; r++) {
      if ((getEntryAtRC(grid, dim, r, c)) == 'X') {
        Xpres = true;
      }
      if ((getEntryAtRC(grid, dim, r, c)) == 'O') {
        Opres = true;
      }
    }
  if (!Xpres || !Opres) {
    return false;
  }
  //resetting Xpres and Opres to ensure they are not present when first checking the next column
  Xpres = false; 
  Opres = false;
}

Xpres = false;
Opres = false;

for (int i = 0; i < dim; i++) { // checking diagonal TL to BR for draws
  if ((getEntryAtRC(grid, dim, i, i)) == 'X') {
    Xpres = true;
  }
  if ((getEntryAtRC(grid, dim, i, i)) == 'O') {
    Opres = true;
  }
  
  //resetting Xpres and Opres to ensure they are not present when first checking the next column
  //Xpres = false; 
 // Opres = false;
}
  if (!Xpres || !Opres) {
      return false;
    }
Xpres = false; 
Opres = false;

for (int i = 0; i < dim; i++) { // checking diagonal TR to BL for draws
  if ((getEntryAtRC(grid, dim, i, dim - i - 1)) == 'X') {
    Xpres = true;
  }
  if ((getEntryAtRC(grid, dim, i, dim - i - 1)) == 'O') {
    Opres = true;
  }
  
  //resetting Xpres and Opres to ensure they are not present when first checking the next column
 // Xpres = false; 
 // Opres = false;
}
if (!Xpres || !Opres) {
    return false;
  }

return true;
}

/**********************************************************
 *  Complete the indicated parts of main(), below. 
 **********************************************************/
int main() 
{
  // This array holds the actual board/grid of X and Os. It is sized 
  // for the biggest possible case (11x11), but you should only 
  // use dim^2 entries (i.e. if dim=3, only use 9 entries: 0 to 8)
  char tttdata[121];
    
  // dim stands for dimension and is the side length of the 
  // tic-tac-toe board i.e. dim x dim (3x3 or 5x5). 
  int dim;
  // Get the dimension from the user
  cin >> dim;
    
  int dim_sq = dim*dim;

  for(int i=0; i < dim_sq; i++) {
    tttdata[i] = '?';
  }

  // Print one of these messages when the game is over
  // and before you quit
  const char xwins_msg[] = "X player wins!";
  const char owins_msg[] = "O player wins!";
  const char draw_msg[] =  "Draw...game over!";
  
  bool done = false;
  //char player = 'X';
  // Show the initial starting board
  printTTT(tttdata, dim);

  int playerType = 0;

  while(!done){

    //**********************************************************
    // Get the current player's input (i.e. the location they want to
    // choose to place their mark [X or O]) and update the tttdata array.
    // Be sure to follow the requirements defined in the guide/writeup
    // for quitting immediately if the user input is out-of-bounds 
    // (i.e. not in the range 0 to dim_sq-1) as well as continuing to 
    // prompt for an input if the user chooses locations that have already
    // been chosen (already marked with an X or O).
    //**********************************************************

    // Add your code here for getting input

    int userInput;
    bool indexCheck = true;

    while (indexCheck) {
      if (playerType % 2 == 0) { // Player X's turn
        cout << "Player X enter your square choice [0-" << dim_sq - 1 << "]: ";
        cin >> userInput;
        if (0 > userInput || userInput > dim_sq - 1) { // check if out of bounds
          return 0;
        }
        else if (tttdata[userInput] == 'X' || tttdata[userInput] == 'O') {
          cout << "Player X enter your square choice [0-" << dim_sq - 1 << "]: ";
        }
        else {
          tttdata[userInput] = 'X';
          indexCheck = false;
        }
      }

      else if (playerType % 2 == 1) { // Player O's turn
        cout << "Player O enter your square choice [0-" << dim_sq - 1 << "]: ";
        cin >> userInput;
        if (0 > userInput || userInput > dim_sq - 1) {
          return 0;
        }
        else if (tttdata[userInput] == 'X' || tttdata[userInput] == 'O') {
          cout << "Player O enter your square choice [0-" << dim_sq - 1 << "]: "; // prompt user to input another value
        }
        else {
          tttdata[userInput] = 'O';
          indexCheck = false;
        }
      }
      
    }

    playerType++;
  

    // Show the updated board if the user eventually chose a valid location
    // (i.e. you should have quit the loop and program by now without any 
    //  other output message if the user chosen an out-of-bounds input).
    printTTT(tttdata, dim);

    //**********************************************************
    // Complete the body of the while loop to process the input that was just
    //  received to check for a winner or draw and update other status, as 
    //  needed. 
    // 
    // To match our automated checkers' expected output, you must output 
    // one of the messages defined above using *one* of the cout commands 
    // (under the appropriate condition) below:
    //   cout << xwins_msg << endl;  OR
    //   cout << owins_msg << endl;  OR
    //   cout << draw_msg << endl;
    //
    // Note: Our automated checkers will examine a specific number of lines
    //  at the end of the program's output and expect to see the updated board
    //  and game status message.  You may certainly add some debug print  
    //  statements during development but they will need to be removed to 
    //  pass the automated checks.
    //**********************************************************

/*
    if (checkForDraw(tttdata, dim) == true) {
      cout << draw_msg << endl;
      done = true;
    }
    else if (checkForWinner(tttdata, dim) == 1) { // r & c not declared
      cout << xwins_msg << endl;
      done = true;
    }
    else if (checkForWinner(tttdata, dim) == 2) {
      cout << owins_msg << endl;
      done = true;
    }
*/

  if (checkForWinner(tttdata, dim) == 1) {
    cout << xwins_msg << endl;
    done = true;
  }

   if (checkForWinner(tttdata, dim) == 2) {
    cout << owins_msg << endl;
    done = true;
  }
  
  if (checkForDraw(tttdata, dim)) {
    cout << draw_msg << endl;
    done = true;
  }
    
  

  } // end while
  return 0;
}
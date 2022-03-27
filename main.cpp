/**
  * This mini project is a text-based Tic-Tac-Toe game.
  * There is a multiplayer and a vs computer mode.
  * The multiplayer is between two human players. Whoever decides to go first,
  * is the Player 1, and then second is Player 2.
  * The vs computer mode has two modes itself. The user can play against
  * the computer in easy mode or hard mode.
  * Easy Mode is beatable, however, Hard mode in unbeatable.
  * Note: To play again, the user has to run the program again.
  *
  * © 2020-2022 Mathavan Pirathaban
  */

//Import all the requirements
#include <iostream>
#include <time.h>

//Don't have to use std everytime.
using namespace std;

//The Tic-Tac-Toe board initially.
char board[3][3] = {{'1','2','3'},{'4','5','6'}, {'7','8','9'}} ;

void drawboard(){
  /**
   * This function will draw the board in a nice format.
   */

  for (int row = 0; row < 3; row++){
   for (int col = 0; col < 3; col++){
     cout << board[row][col] << " | ";
   }
   cout<< endl;
   cout << "-----------" << endl;
 }
 return;
}

void placeMarker(char xo, int place){
  /**
   * This function will place the marker,xo, in the specified placed
   * on the board.
   */

  int r = place % 3;
  int sr = place % 2;
  if (place <= 3){
    if (r == 0){
      board[0][2] = xo;
    }else{
      if (sr == 0){
        board[0][1] = xo;
      }else
        board[0][0] = xo;
    }
  }
  else if (place <= 6){
    if (r == 0){
      board[1][2] = xo;
    }else{
      if (sr == 0){
        board[1][0] = xo;
      }else
        board[1][1] = xo;
    }
  }
  else if (place <= 9){
    if (r == 0){
      board[2][2] = xo;
    }else{
      if (sr == 0){
        board[2][1] = xo;
      }else
        board[2][0] = xo;
    }
  }
  return;
}

bool isItFilled(int num){
  /**
   * This function takes a number, num, as a position. Then, it will check
   * in the board whether the position is taken or not. If the place, num,
   * at the board is taken, then return true. Otherwise, return false.
   */

  int row , col;
  char x = 'X';
  char o = 'O';
  int finder1 = num % 3;
  int finder2 = num - 3;
  if (finder1 == 0){
    col = 2;
  }else if (finder1 == 2){
    col = 1;
  }else if (finder1 == 1){
    col = 0;
  }
  if (finder2 <= 0){
    row = 0;
  }
  else if (finder2 <= 3 && finder2 >= 1){
    row = 1;
  }
  else if (finder2 >= 4){
    row = 2;
  }
  //If the  position is taken.
  if (board[row][col] == x || board[row][col] == o){
    return true;
  }
  //The position is not taken.
  return false;
}

void player1_move(){
  /**
   * This function handles the human player1's move.
   */
  //Player 1's move
  int player1;
  drawboard();
  cout << "Player 1 Enter the number where you want to "
       << "place your marker: " << endl;
  for (int x = 0; x < 1; x++){
    cin >> player1;
    if (isItFilled(player1) == false && player1 >= 1 && player1 <= 9){
      placeMarker('O', player1);
    }else{
      cout << "Try again" << endl;
      drawboard();
      x --;
    }
  }
  return;
}

void player2_move(){
  /**
   * This function handles the human player2's move.
   */
  //Player 2's move
  int player2;
  drawboard();
  cout << "Player 2 Enter the number where you want to "
       << "place your marker: " << endl;
  for (int x = 0; x < 1; x++){
    cin >> player2;
    if (isItFilled(player2) == false && player2 >= 1 && player2 <= 9){
      placeMarker('X', player2);
    }else{
      cout << "Try again" << endl;
      drawboard();
      x --;
    }
  }
  return;
}

bool checkWin(){
  /**
   * This function checks every scenerio and find if there's a winner.
   * If there's a winner, return true, otherwise return false.
   */

  if (board[0][0] == board[0][1] && board[0][0] == board[0][2]){
    return true;
  }
  else if (board[1][0] == board[1][1] && board[1][0] == board[1]  [2]){
    return true;
  }
  else if (board[2][0] == board[2][1] && board[2][0] == board[2][2]){
    return true;
  }
  else if (board[0][0] == board[1][0] && board[0][0] == board[2][0]){
    return true;
  }
  else if (board[0][1] == board[1][1] && board[0][1] == board[2][1]){
    return true;
  }
  else if (board[0][2] == board[1][2] && board[0][2] == board[2] [2]){
    return true;
  }
  else if (board[0][0] == board[1][1] && board[0][0] == board[2][2]){
    return true;
  }
  else if (board[0][2] == board[1][1] && board[0][2] == board[2][0]){
    return true;
  }
  //No winner found.
  return false;
}

void easy_ai(){
  /**
   * This function plays the AI which is in easy mode.
   * The AI picks a random available place to make its mark.
   */

  while (true){
    //Random number between 1-9.
    int place = rand() % 9 + 1;
    if (isItFilled(place) == false){
      placeMarker('X', place);
      break;
    }
  }
  return;
}

int which_AI_won(char xo){
  /**
   * This function checks which AI wins. Closely works with minimax function
   * and see if the AI wins or its nemesis AI wins.
   * The param, xo, takes value 'X' or 'O', and it's the current AI
   * who just placed the marker.
   * If the AI just marked and it won, the function returns 1.
   * If the Enemy AI just marked and it won, the function returns -1.
   * Otherwise, return 0, for neutral.
   */
  //AI's mark and if it wins
  if (xo == 'X' && checkWin() == true){
    return 1;
  //Enemy AI's mark and if it wins
  }else if (xo == 'O' && checkWin() == true){
    return -1;
  }
  //No winner
  return 0;
}

bool isMoveLeft(){
  /**
   * This function will look at the board and see if there's any
   * move left for both 'X' player and 'O' player. If there is a
   * move left, it will return true. Else, return false.
   */
  // Go through the loop and see if spaces available,
  // if so return true.
  for(int row = 0; row<3; row++){
    for(int col = 0; col < 3; col++){
      if (board[row][col] != 'X' && board[row][col] != 'O'){
        return true;
      }
    }
  }
  //No space left.
  return false;
}

int minimax(char xo, bool isMax){
  /**
    * This is the minimax algorithm function.
    * The algorithm runs different scenerios of possible
    * outcomes, and it will calculate a score based on it.
    * The scenerios it run will also have the posibility of
    * it losing, and in each of them it will have a negative
    * score. And for the ones it wins, will have a positive
    * score.
    * The ways in which this algorithm runs the scenerios, is
    * by creating an enemy AI for to play against.
    * The enemy AI have the human player's marker.
    * The best possible scenario in which the AI wins will
    * return. If it cannot win, it will have the best possible
    * scenerio it can draw.
    * Param xo: The current player's marker.
    * Param isMax: true if it is AI turn next.
    *              false if it the enemy AI's turn next.
    */

  //Checks if the AI win, lose, or draw.
  int score = which_AI_won(xo);
  //Win
  if (score == 1){
    return score;
  }
  //Lose
  if (score == -1){
    return score;
  }
  //No place to go, so it's a draw.
  if(isMoveLeft() == false){
    return 0;
  }
  //AI's turn.
  if (isMax){
    int best = -100;
    for (int row = 0; row<3; row++){
      for(int col = 0; col < 3; col++){
        if (board[row][col] != 'X' && board[row][col] != 'O'){
          int tempNum = board[row][col];
          board[row][col] = 'X';
          //Find the maximum between current best and minimax,
          //then store it in best.
          best = max (best , minimax('X', false));
          board[row][col] = tempNum;
        }
      }
    }
    return best;
  }
  //Enemy AI's turn.
  else{
    int best = 100;
    for (int row = 0; row<3; row++){
      for(int col = 0; col < 3; col++){
        if (board[row][col] != 'X' && board[row][col] != 'O'){
          int tempNum = board[row][col];
          board[row][col] = 'O';
          //Find the minimum between current best and minimax,
          //then store it in best.
          best = min (best , minimax('O', true));
          board[row][col] = tempNum;
        }
      }
    }
    return best;
  }
}

void hard_ai(){
  /**
    * This is the function for the hard AI option. Basically,
    * this function uses the minimax algorithm to find the best
    * possible place to put its mark ('X').
    */

  //Initializing it with largest random negative number.
  int bestMove = -1000;
  //The best move row and coloumn is unknown so, initializing it 0 for now.
  int bestMoveRow = 0 , bestMoveCol = 0;

  for (int row = 0; row < 3; row++){
    for (int col = 0; col < 3; col++){
      //If the board value is not taken
      if(board[row][col] != 'X' && board[row][col] != 'O'){
        //The character before it was placed marker with 'X'/'O'.
        char tempNum = board[row][col];
        //Placing the marker with 'X' temporarily.
        board[row][col] = 'X';
        //Find the minimax and store it.
        int currentBest = minimax('X', false);
        //Restore to orginal value instead of 'X' or 'O'.
        board[row][col] = tempNum;
        //If the current one return that was from minimax is the best,
        //then store it in bestMove and also it's row and coloumn.
        if (currentBest > bestMove){
          bestMove = currentBest;
          bestMoveRow = row;
          bestMoveCol = col;
        }
      }
    }
  }
  //The AI make its final move.
  board[bestMoveRow][bestMoveCol] = 'X';
  return;
}


int main(){
  /**
   * The main function, where the program begins.
   */

  //This helps generate the random number.
  srand (time(NULL));
  //Option for Multiplayer or vs Computer
  int user_option_one = 0;
  //If the user pick AI option or not.
  bool AI_option;
  cout << "Do you want to play against the Computer or the multiplayer?"
      <<"\n\nEnter 1. To play against the Computer\n"
      <<"Enter 2. To play Multiplayer." << endl;
  //Run till user pick a valid option.
  while (user_option_one != 1 && user_option_one != 2){
    cin >> user_option_one;
    if (user_option_one == 1){
      AI_option = true;
    }
    else if (user_option_one == 2){
      AI_option = false;
    }
    else{
      cout << "Please try again!" << endl;
    }
  }
  //The turns left for each players left.
  int player1_turns = 5;
  int player2_turns = 4;
  //Game is running
  bool game_running = true;

  //Against the computer.
  if (AI_option == true){
    //Easy vs Hard mode
    int computer_mode = 0;
    cout << "Select Mode\n1. Easy\n2. Hard"<< endl;
    cin >> computer_mode;
    //Easy Mode.
    if (computer_mode == 1){
      while(game_running){
        //If the game draws.
        if (player1_turns == 0 || player2_turns == 0){
          drawboard();
          cout << "It is a draw!" << endl;
          break;
        }
        //Human's turn
        player1_move();
        player1_turns -= 1;
        if (checkWin() == true){
          drawboard();
          cout << "Player 1 wins!" << endl;
          break;
        }
        //AI's turn
        easy_ai();
        player2_turns -= 1;
        if (checkWin() == true){
          drawboard();
          cout << "Computer wins!" << endl;
          break;
        }
      }
    //Hard mode
    }else if (computer_mode == 2){
      while(game_running){
        //Check if the game draws.
        if (player1_turns == 0 || player2_turns == 0){
          drawboard();
          cout << "It is a draw!" << endl;
          break;
        }
        //Human's turn
        player1_move();
        player1_turns -= 1;
        if (checkWin() == true){
          drawboard();
          cout << "Player 1 wins!" << endl;
          break;
        }
        //AI's turn
        hard_ai();
        player2_turns -= 1;
        if (checkWin() == true){
          drawboard();
          cout << "Computer wins!" << endl;
          break;
        }
      }
    }else{
      cout << "Invalid option, run the code again!" << endl;
    }
    // Multiplayer mode.
  }else{
    while (game_running){
      //Check for draw
      if (player1_turns == 0 || player2_turns == 0){
        drawboard();
        cout << "It is a draw!" << endl;
        break;
      }
      //Player 1's move
      player1_move();
      player1_turns -= 1;
      if (checkWin() == true){
        drawboard();
        cout << "Player 1 wins!" << endl;
        break;
      }
      //Player 2's move
      player2_move();
      player2_turns -= 1;
      if (checkWin() == true){
        drawboard();
        cout << "Player 2 wins!" << endl;
        break;
      }
    }
  }
  return 0;
}

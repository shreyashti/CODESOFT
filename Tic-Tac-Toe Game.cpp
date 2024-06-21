#include<iostream>
using namespace std;

void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
bool checkWin(const char board[3][3], char player);
bool checkDraw(const char board[3][3]);

//Here we initialize the game board with empty spaces
void initializeBoard(char board[3][3]){
    for(int i=0; i<3;++i){
        for(int j=0;j<3;++j){
            board[i][j] = ' ';
        }
    }
}

//Display the current state of the board
void displayBoard(const char board[3][3]){
    cout<<"  0 1 2"<<endl;
    for(int i=0;i<3;++i){
        cout<<i<<" ";
        for(int j=0;j<3;++j){
            cout<<board[i][j];
            if(j<2)
            cout<<"|";
        }
        cout<<endl;
        if(i<2)
        cout<<"  -----"<<endl;
    }
}

bool isMoveValid(const char board[3][3],int row,int col){
    return row>=0 && row<3 && col>=0 && col<3 && board[row][col]==' ';
}

bool checkWin(const char board[3][3],char player){
    //firstly we check rows
    for(int i=0;i<3;++i){
        if(board[i][0]==player && board[i][1] == player && board [i][2] == player){
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // now cheking digonals
    if(board[0][0] == player && board [1][1] == player && board[2][2] == player){
        return true;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return true;
    }
    return false;
}

//Now if we check the game is draw
bool checkDraw(const char board[3][3]){
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(board[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char &player){
    player = (player == 'X') ? 'O' : 'X';
}
//main Function
int main(){
    char board[3][3];
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;
    int row, col;
    char playAgain;

    do{
        initializeBoard(board);
        currentPlayer = 'X';
        gameWon = false;
        gameDraw = false;

        while(!gameWon && !gameDraw){
            displayBoard(board);
            cout<< "Player "<<currentPlayer<< ", Enter your move(row and column): ";
            cin>>row>>col;

            while(!isMoveValid(board,row,col)){
                cout<<"Invalid move. Try again: ";
                cin>>row>>col;
            }
            board[row][col] = currentPlayer;
            gameWon = checkWin(board,currentPlayer);
            if(!gameWon){
                gameDraw = checkDraw(board);
                if (!gameDraw) {
                    switchPlayer(currentPlayer);
                }
            }

        }
        displayBoard(board);

        if(gameWon){
            cout<<"Player "<<currentPlayer<<" Wins!"<<endl;
        }
        else if(gameDraw){
            cout<<"The game is a draw!"<<endl;
        }
        cout<<"Do you want to play again? (y/n): ";
        cin>>playAgain;
    }
    while(playAgain == 'y' || playAgain == 'Y');

    return 0;
}

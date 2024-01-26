//This will be an implementation of a simple tic tac toe game
#include <iostream>
#include <random>
using namespace std;

int printGrid(char arr[][3]);
int checkGrid(char arr[][3]);

//x is player 1 and o is player 2
int main () {
    cout<<"Enter 1 to play with computer and 2 to play 2 players: ";
    int player;
    cin>>player;
    bool finished =false;
    random_device rd;
    mt19937 gen(rd());  // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(1, 2);
    int whichPlayer = dis(gen);


    char grid[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int gridNumber;
    if (player==2){
        for (int i=0; i<9; ++i){
            player=i+1;
            char marking;
            printGrid(grid);
            if (player%2==1){
                cout<<"Player 1 (x), type in the number of the grid you want to mark: ";
                marking='x';
            }
            else{
                cout<<"Player 2 (o), type in the number of the grid you want to mark: ";
                marking='o';
            }
            int row, col;
            cin>>gridNumber;
            row=(gridNumber-1/3);
            col=gridNumber-row*3-1;
            grid[row][col]=marking;
    
            if(checkGrid(grid)==1){cout<<"Player 1 won!\n"; return 0;}
            if(checkGrid(grid)==2){cout<<"Player 2 won!\n"; return 0;}
        }
        if(checkGrid(grid)==0){cout<<"It's a draw!\n";}
    }
    else{

    }
    return 0;
}
//Print tic tac toe grid
int printGrid(char arr[][3]){
    cout<<"   |   |   \n";
    cout<<" "<<arr[0][0]<<" | "<<arr[0][1]<<" | "<<arr[0][2]<<endl;
    cout<<"___|___|___\n";
    cout<<"   |   |  \n";
    cout<<" "<<arr[1][0]<<" | "<<arr[1][1]<<" | "<<arr[1][2]<<endl;
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<arr[2][0]<<" | "<<arr[2][1]<<" | "<<arr[2][2]<<endl;
    cout<<"   |   |   \n";
    return 0;
}
//Return 1 or 2 if player 1 or 2 win and 0 if there is no winner yet
int checkGrid(char grid[][3]){
    char whoWon;
    bool gotWin = false;
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            // Horizontal win
            whoWon=grid[i][0];
            gotWin=true;
        }

        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
            // Vertical win
            whoWon=grid[0][i];
            gotWin=true;
        }
    }
    // Check diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        // Diagonal from top-left to bottom-right win
        whoWon=grid[0][0];
        gotWin=true;
    }

    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        // Diagonal from top-right to bottom-left win
        whoWon=grid[0][2];
        gotWin=true;
    }
    if (gotWin){
        if(whoWon=='x'){
            return 1;
        }
        if(whoWon=='o'){
            return 2;
        }
    }

    return 0;
}












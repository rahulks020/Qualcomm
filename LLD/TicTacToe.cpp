#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player{

    string playerName;
    int playerId;
    string playerAddress;
    int playerRank;
    char playerSymbol;

    public:
    Player(string name, int id, string address, int rank, char symbol) : playerName(name), playerId(id), playerAddress(address), playerRank(rank), playerSymbol(symbol)
    {

    }

    string getPlayerName() const
    {
        return playerName;
    }

    char getSymbol() const
    {
        return playerSymbol;
    }

};

class Board
{
      vector<vector<char> >board;
      int boardSize;
      Player * winner;
      vector<Player*>players;

      public:
      Board(int size, vector<Player*>allPlayers)
      {
        this->boardSize = size;
        this->winner = NULL;

        for(int i = 0; i < size; ++i)
        {
            vector<char>v(size, '.');
            board.push_back(v);
        }

        for(auto player : allPlayers)
        {
            players.push_back(player);
        }
      }

      void showBoard()
      {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board.size(); j++)
            {
                
                cout<<board[i][j];
                if(j != boardSize - 1)
                cout<<" | ";
            }

            cout<<"\n";
        }
      }

      bool checkWinner(int row, int col, char symbol)
      {
            int count  = 0;
            for(int i = 0; i < boardSize; i++)
            {
                if(board[i][col] == symbol) count++;
            }

            if(count == boardSize) return true;
            
            count = 0;

            for(int j = 0; j < boardSize; j++)
            {
                if(board[row][j] == symbol) count++;
            }

            if(count == boardSize) return true;

            count = 0;

            for(int i = row, j = col; i >= 0 && j >= 0; i--,j--)
            {
                if(board[i][j] == symbol) count++;
            }

            for(int i = row + 1, j = col + 1; i < boardSize && j < boardSize; i++,j++)
            {
                if(board[i][j] == symbol) count++;
            }

            if(count == boardSize) return true;

            count = 0;

            for(int i = row, j = col; i >= 0 && j < boardSize; i--,j++)
            {
                if(board[i][j] == symbol) count++;
            }

            for(int i = row + 1, j = col + 1; i < boardSize && j >= 0; i++,j--)
            {
                if(board[i][j] == symbol) count++;
            }

            if(count == boardSize) return true;

            return false;
      }

      bool play(int row, int col, int index)
      {
        board[row - 1][col - 1] = players[index]->getSymbol();
        showBoard();
        if(checkWinner(row - 1, col - 1,players[index]->getSymbol()))
        {
            winner = players[index];
            return true;
        }

        return false;
      }
      int getBoardSize()const{
        return boardSize;
      }

      string getCurrentPlayer(int index)
      {
          return players[index]->getPlayerName();
      }

      Player * getWinner()
      {
        return winner;
      }

      int getNumberOfPlayers()
      {
        return players.size();
      }

};

int main()
{
    cout<<"Hello world!\n";

    Player p1("Rahul", 1, "Hyderabad", 1, 'X');
    Player p2("Jaiverr", 2, "Dehradun", 2, 'O');

    vector<Player*>players;

    players.push_back(&p1);
    players.push_back(&p2);

    Board board(3, players);

    cout<<"ByDefault start with 1st player:\n";

    int n = board.getBoardSize();
    int index = 0, count = 0;

    while(1)
    {
       cout<<board.getCurrentPlayer(index)<<" enter row and col :";
       int row, col;
       cin >> row >> col;

       if(board.play(row, col, index)){
        break;
       }

       cout<<"\n";

       index++;

       index = index % board.getNumberOfPlayers();

       count++;

       if(count == n * n ) break;
    }

    if(board.getWinner())
    {
        cout<<"Winner is :"<<board.getWinner()->getPlayerName();
    }
    else{
         cout<<"No one won the game.";
    }

    return 0;
}
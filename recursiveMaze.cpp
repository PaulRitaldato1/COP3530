#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


vector<vector<int>> getInput()
{
    string line;    
    getline(cin, line);

    string token;

    int rowNum=0;
    int colNum=0;
    int size=0;
    int currSize = 0;

    int test;


    //get size
    stringstream lineStream(line);
    while(lineStream >> token)
    {             
        size++;
    }

    //initialize 2D vector
    vector<vector<int>> numbers(size, vector<int>(size, 0));

    //read lines

    for (int k = 0; k<size-1; k++)
    {

        stringstream lineStream2(line);
        currSize = 0;
        while(lineStream2 >> token)
        {       

            test = stoi(token);
            numbers[rowNum][currSize] = test;
            currSize++;
        }
        rowNum++;
        getline(cin, line);

    }
    //do the last line
    stringstream lineStream2(line);
    currSize = 0;
    while(lineStream2 >> token)
    {       
        
        test = stoi(token);
        numbers[rowNum][currSize] = test;
        currSize++;
    }
  
    return numbers;
}

bool solveMaze(vector<vector<int>> maze, int curX, int curY, int x, int y)
{
    if(curX == x && curY == y){// Base Case
        return true;
    }
    if(curX+1 < maze.size()  && maze[curX+1][curY] != 0 && maze[curX+1][curY] != 2){//Down 
        maze[curX][curY] = 2;
        if(solveMaze(maze, curX+1, curY, x,y)){
            return true;
        }
    }
    if(curY+1 < maze.size() && maze[curX][curY+1] != 0 && maze[curX][curY+1] != 2){//Right
        maze[curX][curY] = 2;
        if(solveMaze(maze, curX, curY+1, x,y)){
            return true;
        }
    }
    if(curX-1 >=0  && maze[curX-1][curY] != 0 && maze[curX-1][curY] != 2){//Up
        maze[curX][curY] = 2;
        if(solveMaze(maze,curX - 1,curY,x,y)){
            return true;
        }
    }
    if(curY -1 >=0  && maze[curX][curY -1] != 0 && maze[curX][curY -1] != 2){//Left
        maze[curX][curY] = 2;
        if(solveMaze(maze,curX, curY-1,x,y)){
            return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> maze;
    maze = getInput();
    int x; 
    cin >> x;
    int y;
    cin >> y;
    
    cout << std::boolalpha << solveMaze(maze,0,0, x, y)<< "\n";

    return 0;
}
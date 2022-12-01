#include <bits/stdc++.h> // # is LIVE CELL "AND" space is DEAD CELL
#include <Windows.h> 
using namespace std;

#define print_delay 500
#define MIN 15 // row
// #define MIN 30 // row
#define MAX 50 // col
// #define COUNT 5
#define COUNT 15 // no. of generations

void printVector(vector<vector<int>> &vect);

class GameofLife
{
public:
    GameofLife(vector<vector<int>> &vec)
    {

        // srand(time(0));
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                vec[i][j] = 0;                                   
                // vec[i][j] = rand() % 2;
            }
        }
    }
    void change_Cells(vector<vector<int>> &vect)
    {
        int n, x, key;
        cout << "\nEnter Element ROW no. , COLUMN no. and its new value";
        cout << "\nValue must be 0 or 1 for " << MIN << " * " << MAX << " model.\n";
        cout << "Enter -1 SPACE -1 to finish your input.\n\n";
        while (true)
        {
            cin >> n >> x;
            if (n == -1 && x == -1)
                break;
            if (!((n >= 0 && n <= MIN) && (x >= 0 && x <= MAX)))
            {
                cout << "wrong index\n";
                break;
            }
            cin >> key;
            if (key != 0 && key != 1)
            {
                key = 1;
            }
            vect[n][x] = key;
        }
    }
};

class RulesforGOL
{
public:
    void arrangement_of_cells(vector<vector<int>> &vec, vector<vector<int>> &vec2)
    {
        for (int i = 0; i < vec2.size(); i++)
        {
            for (int j = 0; j < vec2[i].size(); j++)
            {
                vec2[i][j] = 0;
            }
        }
        int i, j;
        for (i = 1; i < vec.size() - 1; i++)
        {
            for (j = 1; j < vec[i].size() - 1; j++)
            {
                int cnt_live = count_live_neighbour_cell(vec, i, j);

                if (vec[i][j] == 1)
                {
                    if (cnt_live < 2) // Any live cell with fewer than two live neighbours dies, as if by underpopulation
                    {
                        vec2[i][j] = 0;
                        continue;
                    }
                    if (cnt_live == 2 || cnt_live == 3) // Any live cell with two or three live neighbours lives on to the next generation
                    {
                        vec2[i][j] = 1;
                        continue;
                    }
                    if (cnt_live > 3) // Any live cell with more than three live neighbours dies, as if by overpopulation
                    {
                        vec2[i][j] = 0;
                        continue;
                    }
                }
                else if (vec[i][j] == 0)
                {
                    if (cnt_live == 3) // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction
                    {
                        vec2[i][j] = 1;
                        continue;
                    }
                    else
                    {
                        vec2[i][j] = vec[i][j];
                        continue;
                    }
                }
            }
        }
    }
    int count_live_neighbour_cell(vector<vector<int>> &vec, int r, int c)
    {
        int i, j, count = 0;
        for (i = r - 1; i <= r + 1; i++)
        {
            for (j = c - 1; j <= c + 1; j++)
            {
                if ((i == r && j == c) || (i < 0 || j < 0) || (i >= MIN || j >= MAX))
                {
                    continue;
                }
                if (vec[i][j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

void printVector(vector<vector<int>> &vect)
{
    string s;
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            if (vect[i][j] == 1)
            {
                s = "#"; // For Live Cell  X O # @ *
                //  s = "▮"; // For Live Cell
            }
            else
            {
                s = "-"; // For Dead Cell 
                //  s = "▯"; // For Dead Cell
            }
            cout << " " << s << " ";
            //  cout <<s;
        }
        cout << endl;
        // cout << endl<< endl;
    }
}

void printStar()
{
    for (int i = 0; i < 3*(MAX) + 5 ; i++)
    {
        cout << "_";
    }
    cout << "\n";
}

int main()
{
    vector<vector<int>> vec(MIN, vector<int>(MAX));
    vector<vector<int>> vec2(MIN, vector<int>(MAX));
    GameofLife g(vec);
    g.change_Cells(vec);
    cout << "\n";
    cout << "\n                       I N I T I A L   S T A G E       \n\n";
    printVector(vec);
    printStar();
    // cout << endl
        //  << endl;
    RulesforGOL rfg;
    for (int i = 1; i <= COUNT; i++)
    {
        if (i % 2 != 0)
        {
            rfg.arrangement_of_cells(vec, vec2);
            cout << "\n                       G E N E R A T I O N    N O .  "<<i<<"       \n\n";
            printVector(vec2);
            printStar();
            Sleep(print_delay);
        }
        else
        {
            rfg.arrangement_of_cells(vec2, vec);
            cout << "\n                       G E N E R A T I O N    N O .  "<<i<<"       \n\n";
            printVector(vec);
            printStar();
            Sleep(print_delay);
        }
    }

    // rfg.arrangement_of_cells(vec, vec2);
    // printVector(vec2);
    cout << "\n";
    // vec[i][j] = 0 -> Dead Cell
    // vec[i][j] = 1 -> Live Cell
    return 0;
} // working




/*
input for glider gun
6 2 1
6 3 1
7 2 1
7 3 1
6 12 1 
7 12 1
8 12 1
9 13 1
5 13 1
10 14 1
10 15 1
4 14 1
4 15 1
7 16 1
5 17 1
9 17 1
6 18 1
7 18 1
8 18 1
7 19 1
4 22 1
5 22 1
6 22 1
4 23 1
5 23 1
6 23 1
3 24 1
7 24 1
2 26 1
3 26 1
7 26 1
8 26 1
4 36 1
5 36 1
4 37 1
5 37 1
-1 -1


***

input for other pattern
6 4 1
6 5 1
5 6 1
6 6 1
7 6 1
7 9 1
5 9 1
6 9 1
6 10 1
6 11 1
6 12 1
6 13 1
6 14 1
5 14 1
7 14 1
6 17 1
5 17 1
7 17 1
6 18 1
6 19 1
-1 -1 
*/

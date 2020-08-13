#include <iostream>
#include <string>
#include <math.h>
#include <conio.h>

using namespace std;

void TABLE_OUTPUT(string TABLE, string CELLS[4][4], int MODE, bool OUTPUT);
string STR_ANALYSE(string INPUT, int *x, int *y, char WHO);
string COMP_TURN(string CELLS[4][4]);
int VAL_CHARS(char CH_digits, char CH_tens);
bool VICTORY_CHECK(string CELLS[4][4], bool VICTORY);

int main() 
{
      int i, j, MOD, c;
      bool FT = false;
      string INPUT, TABLE, turn;
      string cell[4][4] =     
      {
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "},
            {" ", " ", " ", " "}
      };

      while (INPUT != "#quit") 
      {
            cin >> INPUT >> FT;
            cin.get();
            if (INPUT == "#new") 
            {
                  TABLE_OUTPUT(TABLE, cell, 1, false);
                  for (c = 0; !VICTORY_CHECK(cell, false); c++)
                  {
                        if ( (c+(int)FT)%2 != 1)                   // если FT==0, то первый ход человека
                        {
                              getline(cin, turn);
                              INPUT = STR_ANALYSE(turn, &i, &j, 'h');
                              cell[i][j] = INPUT;
                              TABLE_OUTPUT(TABLE, cell, 0, true); cout << endl;
                        }
                        else
                        {
                              INPUT = STR_ANALYSE(COMP_TURN(cell), &i, &j, 'c');
                              cell[i][j] = INPUT;
                              TABLE_OUTPUT(TABLE, cell, 0, true); cout << endl;
                        }
                  }
                  if ( (c+(int)FT)%2 == 1)
                        cout << "YOU WIN!\n\n";
                  else
                        cout << "YOU LOSE!\n\n";
            }
            else if (INPUT == "#options")
            {
                  cout << "Options:\n...\n";
                  cin >> MOD;
            }
            else
                  cout << "WTF?";
      }
      getch();
      return 0;
}


void TABLE_OUTPUT(string TABLE, string CELLS[4][4], int MODE, bool OUTPUT)
{
      if (MODE == 1)
      {
            for (int i = 0; i < 3; i++)
                  for (int j = 0; j < 3; j++)
                        CELLS[i][j] = " ";
      }
      else if (MODE == 2)
      {
            for (int i = 0; i < 3; i++)
                  for (int j = 0; j < 3; j++)
                        CELLS[i][j] = "o";
      }
      else if (MODE == 3)
      {
            for (int i = 0; i < 3; i++)
                  for (int j = 0; j < 3; j++)
                        CELLS[i][j] = "x";
      }

      TABLE = " " + CELLS[0][0] + " | " + CELLS[0][1] + " | " + CELLS[0][2] +
                    "\n-----------\n " + 
                    CELLS[1][0] + " | " + CELLS[1][1] + " | " + CELLS[1][2] + 
                    "\n-----------\n " + 
                    CELLS[2][0] + " | " + CELLS[2][1] + " | " + CELLS[2][2];

      if (OUTPUT)
            cout << TABLE << endl << endl;
}


string COMP_TURN(string CELLS[4][4])
{
      if (CELLS[0][2]!="x" && CELLS[0][2]!="o")
            return "0 2";
      else if (CELLS[0][1]!="x" && CELLS[0][1]!="o" || CELLS[2][1]!="x" && CELLS[2][1]!="o")
            return "0 1";
}


void algor_1(int STEP)
{
      
}


string STR_ANALYSE(string INPUT, int *x, int *y, char WHO)
{
      char ch = INPUT[0], ch2 = INPUT[2];

      if (ch == '#')
            return INPUT;
      else if (isdigit(ch) && isdigit(ch2))
      {
            *x = VAL_CHARS(ch, '0');
            *y = VAL_CHARS(ch2, '0');

            if (WHO == 'h')
                  return "x";
            else if (WHO == 'c')
                  return "o";
            else
                  return " ";
      }            
}


int VAL_CHARS(char CH_digits, char CH_tens) {
      int i1, i2, final;
      char ch = '0';

      i1 = CH_digits - ch;
      i2 = CH_tens - ch;

      final = i1 + i2*10;

      return final;
}


bool VICTORY_CHECK(string CELLS[4][4], bool VICTORY)
{
      for (int i = 0; i < 3; i++)
      {
            for (int j = 0; j < 3; j++)
            {
                  if ( (CELLS[i][j]=="x" && CELLS[i][j+1]=="x" && CELLS[i][j+2]=="x") ||
                       (CELLS[i][j]=="o" && CELLS[i][j+1]=="o" && CELLS[i][j+2]=="o")
                      )
                        return true;
                  if ( (CELLS[i][j]=="x" && CELLS[i+1][j]=="x" && CELLS[i+2][j]=="x") ||
                       (CELLS[i][j]=="o" && CELLS[i+1][j]=="o" && CELLS[i+2][j]=="o")
                      )
                        return true;
                  if ( (CELLS[i][j]=="x" && CELLS[i+1][j+1]=="x" && CELLS[i+2][j+2]=="x") ||
                       (CELLS[i][j]=="o" && CELLS[i+1][j+1]=="o" && CELLS[i+2][j+2]=="o")
                      )
                        return true;
            }
      }
      if ( (CELLS[2][0]=="x" && CELLS[1][1]=="x" && CELLS[0][2]=="x") ||
           (CELLS[2][0]=="o" && CELLS[1][1]=="o" && CELLS[0][2]=="o")
          )
            return true;
      else
            return false;
}






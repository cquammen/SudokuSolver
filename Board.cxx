#include "Board.h"

#include <iostream>


Board
::Board(int* initialBoard)
{
  for (int row = 0; row < 9; row++)
    {
    for (int col = 0; col < 9; col++)
      {
      m_Board[col][row] = initialBoard[row*9 + col];
      }
    }
}


Board
::~Board()
{
}


bool
Board
::IsMoveLegal(int col, int row, int num)
{
  if (m_Board[col][row] > 0 && m_Board[col][row] != num)
    {
    return false;
    }
  else
    {
    // Check if it is already in the same row or column
    for (int i = 0; i < 9; i++)
      {
      if (m_Board[i][row] == num && i != col)
        {
        return false;
        }
      if (m_Board[col][i] == num && i != row)
        {
        return false;
        }
      }

    // Check if it is already in the same block
    int blockCol = (col / 3) * 3;
    int blockRow = (row / 3) * 3;
    for (int i = blockCol; i < blockCol + 3; i++)
      {
      for (int j = blockRow; j < blockRow + 3; j++)
        {
        if (m_Board[i][j] == num && i != col && j != row)
          {
          return false;
          }
        }
      }
    }

  return true;
}

bool
Board
::Solve()
{
  return RecursiveSolve(0, 0, 1);
}


bool
Board
::RecursiveSolve(int col, int row, int num)
{
  if (num > 9)
    {
    return false;
    }
  else if (row > 8) // Everything went well, solved
    {
    return true;
    }
  else if (col > 8)
    {
    return RecursiveSolve(0, row+1, num);
    }
  else if (m_Board[col][row] > 0) // Board entry filled, move on
    {
    return RecursiveSolve(col+1, row, 1);
    }
  else if (IsMoveLegal(col, row, num)) // Legal move, fill in and move on
    {
    m_Board[col][row] = num;
    bool success = RecursiveSolve(col+1, row, 1);
    if (success)
      {
      return true;
      }
    else
      {
      m_Board[col][row] = 0;
      return RecursiveSolve(col, row, num+1);
      }
    }
  else
    {
    return RecursiveSolve(col, row, num+1);
    }

  return false;
}


void
Board
::Print()
{
  for (int row = 0; row < 9; row++)
    {
    for (int col = 0; col < 9; col++)
      {
      std::cout << m_Board[col][row] << ", ";
      }
    std::cout << std::endl;
    }

}

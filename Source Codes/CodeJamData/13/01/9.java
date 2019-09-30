import java.util.*;

class TicTacToeTomek
{
  public static void main(String... args)
  {
    Scanner sc = new Scanner(System.in);

    int tests = sc.nextInt();
    for (int test = 1; test <= tests; ++test)
    {
      Cell[][] grid = new Cell[4][4];
      sc.nextLine();
      boolean full = true;
      for (int i = 0; i < 4; ++i)
      {
        String line = sc.nextLine();
        for (int j = 0; j < 4; ++j)
        {
          char c = line.charAt(j);
          switch (c)
          {
            case 'X':
              grid[i][j] = Cell.X;
              break;
            case 'O':
              grid[i][j] = Cell.O;
              break;
            case 'T':
              grid[i][j] = Cell.T;
              break;
            default:
              grid[i][j] = Cell.EMPTY;
              full = false;
              break;
          }
        }
      }
      Cell winner = findWinner(grid);
      if (winner == Cell.X)
      {
        System.out.println("Case #" + test + ": X won");
      }
      else if (winner == Cell.O)
      {
        System.out.println("Case #" + test + ": O won");
      }
      else if (full)
      {
        System.out.println("Case #" + test + ": Draw");
      }
      else
      {
        System.out.println("Case #" + test + ": Game has not completed");
      }
    }
  }

  public static Cell findWinner(Cell[][] grid)
  {
    for (int i = 0; i < 4; ++i)
    {
      Cell rowWinner = findRowWinner(grid[i][0], grid[i][1], grid[i][2], grid[i][3]);
      if (rowWinner != null)
      {
        return rowWinner;
      }
      Cell colWinner = findRowWinner(grid[0][i], grid[1][i], grid[2][i], grid[3][i]);
      if (colWinner != null)
      {
        return colWinner;
      }
    }
    Cell diagonal1Winner = findRowWinner(grid[0][0], grid[1][1], grid[2][2], grid[3][3]);
    if (diagonal1Winner != null)
    {
      return diagonal1Winner;
    }
    Cell diagonal2Winner = findRowWinner(grid[0][3], grid[1][2], grid[2][1], grid[3][0]);
    if (diagonal2Winner != null)
    {
      return diagonal2Winner;
    }
    return null;
  }
  public static Cell findRowWinner(Cell... row)
  {
    Cell current = Cell.T;
    for (int i = 0; i < 4; ++i)
    {
      if (row[i] == Cell.EMPTY)
      {
        return null;
      }
      else if (row[i] == Cell.X)
      {
        if (current == Cell.O)
        {
          return null;
        }
        if (current == Cell.T)
        {
          current = Cell.X;
        }
      }
      else if (row[i] == Cell.O)
      {
        if (current == Cell.X)
        {
          return null;
        }
        if (current == Cell.T)
        {
          current = Cell.O;
        }
      }
    }
    if (current == Cell.T)
    {
      throw new IllegalArgumentException("Cannot check a row full of 'T's");
    }
    return current;
  }
}

enum Cell
{
  X,
  O,
  T,
  EMPTY
}

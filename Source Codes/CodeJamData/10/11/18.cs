using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Problem1
    {
        static void Main(string[] args)
        {
            int t = ReadInt();
            for (int i = 0; i < t; i++)
            {
                List<int> l1 = ReadListInt();
                int n = l1[0];
                int k = l1[1];
                Color[][] board = new Color[n][];
                for (int j = 0; j < n; j++)
                {
                    string row = Console.ReadLine();
                    board[j] = new Color[n];
                    for (int l = 0; l < n; l++)
                    {
                        if (row[l].ToString().ToLower() == "b")
                        {
                            board[j][l] = Color.Blue;
                        }
                        else if (row[l].ToString().ToLower() == "r")
                        {
                            board[j][l] = Color.Red;
                        }
                        else
                        {
                            board[j][l] = Color.None;
                        }
                    }
                }
                string result = Solve(n, k, board);
                WriteResult(i, result);
            }
            Console.ReadLine();
        }

        static string Solve(int n, int k, Color[][] board)
        {
           // Color[][] left = JamLeft(n, board);
            Color[][] rb = JamRight(n, board);
            HashSet<long> visited = new HashSet<long>();

            HashSet<Color> colors = new HashSet<Color>();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (rb[i][j] != Color.None)
                    {
                        if (CountTheSame(rb, i, j, visited, n, k))
                        {
                            colors.Add(rb[i][j]);
                        }
                    }
                    if (colors.Count == 2)
                    {
                        break;
                    }
                }
                if (colors.Count == 2)
                {
                    break;
                }
            }
            if (colors.Count == 2)
            {
                return "Both";
            }
            else if (colors.Count == 0)
            {
                return "Neither";
            }
            else
            {
                if (colors.Contains(Color.Red))
                {
                    return "Red";
                }
                else
                {
                    return "Blue";
                }
            }

            return "";
        }

        static bool CountTheSame(Color[][] board, int x, int y,HashSet<long> visited, int n, int k)
        {
            Color c = board[x][y];
            int count = 1;
            visited.Add(GetHash(x, y));

            //horiz
            for (int i = 1; i < k; i++)
            {
                if (x - i < 0 || board[x - i][y] != c)
                {
                    break;
                }
                count++;
            }
            for (int i = 1; i < k; i++)
            {
                if (x + i >= n || board[x + i][y] != c)
                {
                    break;
                }
                count++;
            }
            if (count >= k)
            {
                return true;
            }

            //vert
            count = 1;
            for (int i = 1; i < k; i++)
            {
                if (y - i < 0 || board[x][y - i] != c)
                {
                    break;
                }
                count++;
            }
            for (int i = 1; i < k; i++)
            {
                if (y + i >= n || board[x][y + i] != c)
                {
                    break;
                }
                count++;
            }
            if (count >= k)
            {
                return true;
            }

            //diag-1
            count = 1;
            for (int i = 1; i < k; i++)
            {
                if (y - i < 0 || x - i < 0 || board[x - i][y - i] != c)
                {
                    break;
                }
                count++;
            }
            for (int i = 1; i < k; i++)
            {
                if (y + i >= n || x + i >= n || board[x + i][y + i] != c)
                {
                    break;
                }
                count++;
            }
            if (count >= k)
            {
                return true;
            }

            //diag-2
            count = 1;
            for (int i = 1; i < k; i++)
            {
                if (y - i < 0 || x + i >= n || board[x + i][y - i] != c)
                {
                    break;
                }
                count++;
            }
            for (int i = 1; i < k; i++)
            {
                if (y + i >= n || x - i < 0 || board[x - i][y + i] != c)
                {
                    break;
                }
                count++;
            }
            if (count >= k)
            {
                return true;
            }

            return false;
        }

        static long GetHash(int x, int y)
        {
            return x * 10000 + y;
        }

        static Color[][] JamRight(int n, Color[][] board)
        {
            Color[][] newBoard = new Color[n][];
            for (int i = 0; i < n; i++)
            {
                List<Color> line = new List<Color>();

                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] != Color.None)
                    {
                        line.Add(board[i][j]);
                    }
                    newBoard[i] = new Color[n];
                    newBoard[i][j] = Color.None;
                }
                for (int j = 0; j < line.Count; j++)
                {
                    newBoard[i][n - line.Count + j] = line[j];
                }
            }
            return newBoard;
        }

        static Color[][] JamLeft(int n, Color[][] board)
        {
            Color[][] newBoard = new Color[n][];
            for (int i = 0; i < n; i++)
            {
                List<Color> line = new List<Color>();

                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] != Color.None)
                    {
                        line.Add(board[i][j]);
                    }
                    newBoard[i] = new Color[n];
                    newBoard[i][j] = Color.None;
                }
                for (int j = 0; j < line.Count; j++)
                {
                    newBoard[i][j] = line[j];
                }
            }
            return newBoard;
        }

        enum Color
        {
            None,
            Blue,
            Red
        }






        static void WriteResult<T>(int i, T value)
        {
            Console.WriteLine(string.Format("Case #{0}: {1}", i + 1, value.ToString()));
        }

        static int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }

        static List<int> ReadListInt()
        {
            string[] l1 = Console.ReadLine().Split(new char[] { ' ' });
            List<int> result = new List<int>();
            foreach (string s in l1)
            {
                result.Add(int.Parse(s));
            }
            return result;
        }

        static List<long> ReadListLong()
        {
            string[] l1 = Console.ReadLine().Split(new char[] { ' ' });
            List<long> result = new List<long>();
            foreach (string s in l1)
            {
                result.Add(long.Parse(s));
            }
            return result;
        }
    }
}

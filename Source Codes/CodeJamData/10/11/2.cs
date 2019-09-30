using System;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static int[] dr = new int[] { -1, -1, -1, 0, 1, 1, 1, 0 };
        static int[] dc = new int[] { -1, 0, 1, 1, 1, 0, -1, -1 };

        static bool Check(char[,] b, int row, int col, int len)
        {
            for (int i = 0; i < dr.Length; i++)
            {
                for (int j = 1; j < len; j++)
                {
                    int r = row + j * dr[i];
                    int c = col + j * dc[i];
                    if (r < 0 || r >= b.GetLength(0) || c < 0 || c >= b.GetLength(1) || b[row, col] != b[r, c])
                    {
                        break;
                    }
                    if (j + 1 == len)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        static string Solve(string[] s, int k)
        {
            int n = s.Length;
            char[,] b = new char[n, n];
            for (int i = 0; i < n; i++)
            {
                int idx = 0;
                for (int j = 0; j < n; j++)
                {
                    char ch = s[n - i - 1][n - j - 1];
                    if (ch != '.')
                    {
                        b[i, idx] = ch;
                        idx += 1;
                    }
                }
            }

            bool red = false;
            bool blue = false;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (b[i, j] != '.' && Check(b, i, j, k))
                    {
                        if (b[i, j] == 'R')
                        {
                            red = true;
                        }
                        if (b[i, j] == 'B')
                        {
                            blue = true;
                        }
                    }
                }
            }

            if (red && !blue) return "Red";
            if (!red && blue) return "Blue";
            if (red && blue) return "Both";
            return "Neither";
        }

        static void Main(string[] args)
        {
            using (StreamWriter writer = new StreamWriter("..\\..\\output.txt"))
            {
                using (StreamReader reader = new StreamReader("..\\..\\input.txt"))
                {
                    int total = Int32.Parse(reader.ReadLine());
                    for (int i = 0; i < total; i++)
                    {
                        string[] temp = reader.ReadLine().Split();
                        int n = Int32.Parse(temp[0]);
                        int k = Int32.Parse(temp[1]);
                        string[] s = new string[n];
                        for (int j = 0; j < n; j++)
                        {
                            s[j] = reader.ReadLine();
                        }
                        string ans = Solve(s, k);
                        writer.WriteLine("Case #" + (i + 1) + ": " + ans);
                    }
                }
            }
        }
    }
}
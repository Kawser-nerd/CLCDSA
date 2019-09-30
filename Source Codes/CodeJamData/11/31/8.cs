using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ
{
    public class SquareTiles
    {
        public void Solve()
        {
            //var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A.in");
            //var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\A.out");

            //var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A-small-attempt0.in");
            //var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\A-small-attempt0.out");

            //var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A-small-attempt1.in");
            //var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\A-small-attempt1.out");

            //var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A-small-attempt1.in");
            //var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\A-small-attempt1.out");

            var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A-large.in");
            var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\A-large.out");

            Console.SetIn(inputStream);
            Console.SetOut(outputStream);

            int totalCases = int.Parse(Console.ReadLine());
            for (int cs = 1; cs <= totalCases; ++cs)
            {
                var rc = Console.ReadLine().Split(' ');
                int r = int.Parse(rc[0]);
                int c = int.Parse(rc[1]);

                List<string> board = new List<string>();

                for (int i = 0; i < r; ++i)
                {
                    board.Add(Console.ReadLine());
                }

                for (int i = 0; i < r; ++i)
                {
                    for (int j = 0; j < c; ++j)
                    {
                        if (board[i][j] == '#' && IsRedPossible(board, i, j))
                        {
                            board[i] = GetFirstRow(board, i, j);
                            board[i + 1] = GetSecondRow(board, i, j);
                        }
                    }
                }

                bool isGood = true;

                for (int i = 0; i < r; ++i)
                {
                    for (int j = 0; j < c; ++j)
                    {
                        if (board[i][j] == '#')
                            isGood = false;
                    }
                }

                Console.WriteLine("Case #{0}:", cs);

                if (!isGood)
                    Console.WriteLine("Impossible");
                else
                {
                    for (int i = 0; i < r; ++i)
                        Console.WriteLine(board[i]);
                }
            }

            inputStream.Close();
            outputStream.Close();
        }

        public bool IsRedPossible(List<string> board, int i, int j)
        {
            if (i >= board.Count - 1 || j >= board[0].Length - 1)
                return false;

            if (board[i][j] == '#' && board[i + 1][j] == '#' && board[i][j + 1] == '#' && board[i + 1][j + 1] == '#')
                return true;

            return false;
        }

        public string GetFirstRow(List<string> board, int i, int j)
        {
            StringBuilder sb = new StringBuilder(board[i]);
            sb[j] = '/';
            sb[j + 1] = '\\';
            return sb.ToString();
        }

        public string GetSecondRow(List<string> board, int i, int j)
        {
            StringBuilder sb = new StringBuilder(board[i + 1]);
            sb[j] = '\\';
            sb[j + 1] = '/';
            return sb.ToString();
        }
    }
}

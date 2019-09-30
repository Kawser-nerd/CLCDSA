using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{

    class Program
    {

        static void Main(string[] args)
        {

            FileStream output = new FileStream("output.txt", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(output);

            FileStream input = new FileStream("input.txt", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(input);


            int nTestCases = int.Parse(sr.ReadLine());

            for (int t = 1; t <= nTestCases; t++)
            {

                string line = sr.ReadLine();

                string[] splitted = line.Split();
                int R = int.Parse(splitted[0]);
                int C = int.Parse(splitted[1]);

                StringBuilder[] board = new StringBuilder[R];
                for (int i = 0; i < R; i++)
                {
                    board[i] = new StringBuilder(sr.ReadLine());
                }

                for (int i = 0; i < R-1; i++)
                {
                    for (int j = 0; j < C - 1; j++)
                    {
                        if (board[i][j] == '#' && board[i][j + 1] == '#'
                            && board[i+1][j] == '#' && board[i + 1][j + 1] == '#')
                        {
                            board[i][j] = '/';
                            board[i][j + 1] = '\\';
                            board[i + 1][j] = '\\';
                            board[i + 1][j + 1] = '/';
                        }
                    }
                }

                bool ok = true;
                for (int i = 0;ok && i < R; i++)
                {
                    for (int j = 0;ok && j < C; j++)
                    {
                        if (board[i][j] == '#')
                        {
                            ok = false;
                        }
                    }
                }

                sw.WriteLine("Case #" + t.ToString() + ": ");
                if (ok)
                {
                    for (int i = 0; i < R; i++)
                    {
                        sw.WriteLine(board[i].ToString());
                    }
                }
                else
                {
                    sw.WriteLine("Impossible");
                }
                sw.Flush();
            }



        }
    }
}

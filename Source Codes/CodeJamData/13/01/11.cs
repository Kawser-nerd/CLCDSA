using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using System.IO;

namespace CJ
{
    class Program
    {
        static void Main(string[] args)
        {
            TextWriter tw = new StreamWriter(@"C:\output.txt");
            string[] lines = System.IO.File.ReadAllLines(@"C:\input.txt");
            int lineid = 0;
            string line = lines[lineid++];
            int T = int.Parse(line);



            for (int t = 1; t <= T; t++)
            {
                string[] rows = new string[4];
                string[] cols = new string[4];
                string[] diag = new string[2];
                for (int i = 0; i < 4; i++)
                    rows[i] = lines[lineid++];
                lineid++;
                Boolean finished = true;
                Boolean winO = false;
                Boolean winX = false;
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                    {
                        if (rows[i][j] == '.') finished = false;
                        cols[j] += rows[i][j];
                    }
                for (int i = 0; i < 4; i++)
                {
                    diag[0] += rows[i][i];
                    diag[1] += rows[i][3 - i];
                }
                for (int i = 0; i < 4; i++)
                {
                    winO |= testc(rows[i], 'O');
                    winX |= testc(rows[i], 'X');
                    winO |= testc(cols[i], 'O');
                    winX |= testc(cols[i], 'X');
                }
                for (int i = 0; i < 2; i++)
                {
                    winO |= testc(diag[i], 'O');
                    winX |= testc(diag[i], 'X');
                }
                /*
                "X won" (the game is over, and X won)
                "O won" (the game is over, and O won)
                "Draw" (the game is over, and it ended in a draw)
                "Game has not completed" (the game is not over yet)*/
                String ret = "Draw";
                if (winO) ret = "O won";
                else if (winX) ret = "X won";
                else if (!finished) ret = "Game has not completed";

                Console.WriteLine("Case #" + t + ": " + ret);
                tw.WriteLine("Case #" + t + ": " + ret);

            }

            Console.WriteLine("FINE");
            tw.Close();
        }
        static Boolean testc(String s, char c)
        {
            for (int i = 0; i < s.Length; i++)
                if (s[i] != c && s[i] != 'T') return false;
            return true;
        }
    }

}

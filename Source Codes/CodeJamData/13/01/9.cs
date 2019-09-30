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
            string[] lines = File.ReadAllLines(@"A-large.in");

            int cases = Int32.Parse(lines[0]);
            StringBuilder sb = new StringBuilder();

            for (int i = 0, j = 1; i < cases; i++)
            {
                // var b = new string[] { lines[j], lines[j + 1], lines[j + 2], lines[j + 3]};
                bool X = false, O = false, D = false, P = false;


                for (int k = j; k < j + 4; k++)
                {
                    if ((lines[k][0] == 'X' || lines[k][0] == 'T') &&
                        (lines[k][1] == 'X' || lines[k][1] == 'T') &&
                        (lines[k][2] == 'X' || lines[k][2] == 'T') &&
                        (lines[k][3] == 'X' || lines[k][3] == 'T'))
                    {
                        X = true;
                        break;
                    }

                    if ((lines[k][0] == 'O' || lines[k][0] == 'T') &&
                        (lines[k][1] == 'O' || lines[k][1] == 'T') &&
                        (lines[k][2] == 'O' || lines[k][2] == 'T') &&
                        (lines[k][3] == 'O' || lines[k][3] == 'T'))
                    {
                        O = true;
                        break;
                    }
                }

                for (int k = 0; k < 4; k++)
                {
                    if ((lines[j][k] == 'X' || lines[j][k] == 'T') &&
                        (lines[j + 1][k] == 'X' || lines[j + 1][k] == 'T') &&
                        (lines[j + 2][k] == 'X' || lines[j + 2][k] == 'T') &&
                        (lines[j + 3][k] == 'X' || lines[j + 3][k] == 'T'))
                    {
                        X = true;
                        break;
                    }

                    if ((lines[j][k] == 'O' || lines[j][k] == 'T') &&
                        (lines[j + 1][k] == 'O' || lines[j + 1][k] == 'T') &&
                        (lines[j + 2][k] == 'O' || lines[j + 2][k] == 'T') &&
                        (lines[j + 3][k] == 'O' || lines[j + 3][k] == 'T'))
                    {
                        O = true;
                        break;
                    }
                }

                if ((lines[j][0] == 'X' || lines[j][0] == 'T') &&
                    (lines[j + 1][1] == 'X' || lines[j + 1][1] == 'T') &&
                    (lines[j + 2][2] == 'X' || lines[j + 2][2] == 'T') &&
                    (lines[j + 3][3] == 'X' || lines[j + 3][3] == 'T'))
                {
                    X = true;
                }

                if ((lines[j][0] == 'O' || lines[j][0] == 'T') &&
                    (lines[j + 1][1] == 'O' || lines[j + 1][1] == 'T') &&
                    (lines[j + 2][2] == 'O' || lines[j + 2][2] == 'T') &&
                    (lines[j + 3][3] == 'O' || lines[j + 3][3] == 'T'))
                {
                    O = true;
                }

                if ((lines[j + 3][0] == 'X' || lines[j + 3][0] == 'T') &&
                    (lines[j + 2][1] == 'X' || lines[j + 2][1] == 'T') &&
                    (lines[j + 1][2] == 'X' || lines[j + 1][2] == 'T') &&
                    (lines[j][3] == 'X' || lines[j][3] == 'T'))
                {
                    X = true;
                }

                if ((lines[j + 3][0] == 'O' || lines[j + 3][0] == 'T') &&
                    (lines[j + 2][1] == 'O' || lines[j + 2][1] == 'T') &&
                    (lines[j + 1][2] == 'O' || lines[j + 1][2] == 'T') &&
                    (lines[j][3] == 'O' || lines[j][3] == 'T'))
                {
                    O = true;
                }

                for (int k = j; k < j + 4; k++)
                {
                    if (lines[k].Contains("."))
                    {
                        P = true;
                    }
                }
                j += 5;

                if (X)
                {
                    Console.WriteLine("Case #{0}: X won", i + 1);
                    string str = string.Format("Case #{0}: X won", i + 1);
                    sb.AppendLine(str);
                    continue;
                }

                if (O)
                {
                    Console.WriteLine("Case #{0}: O won", i + 1);
                    string str = string.Format("Case #{0}: O won", i + 1);
                    sb.AppendLine(str);
                    continue;
                }

                if (P)
                {
                    Console.WriteLine("Case #{0}: Game has not completed", i + 1);
                    string str = string.Format("Case #{0}: Game has not completed", i + 1);
                    sb.AppendLine(str);
                    continue;
                }

                Console.WriteLine("Case #{0}: Draw", i + 1);
                string str1 = string.Format("Case #{0}: Draw", i + 1);
                sb.AppendLine(str1);

                //XXXT
                //....
                //OO..
                //....
                // for (int i1 = 0; i1 < b)
            }
            //foreach (string line in lines)
            //{
            //    // Use a tab to indent each line of the file.
            //    Console.WriteLine("\t" + line);
            //}
            Console.ReadLine();
        }
    }
}
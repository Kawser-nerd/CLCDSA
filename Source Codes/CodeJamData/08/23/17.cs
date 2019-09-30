using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace C
{
    class Program
    {
        #region Common part

        static StreamReader input;
        static StreamWriter output;

        static void Main(string[] args)
        {
            Console.WriteLine("Opening files...");

            string inputFileName = args[0];
            string outputFileName = Path.ChangeExtension(inputFileName, ".out");

            using (StreamReader input = new StreamReader(inputFileName))
            using (StreamWriter output = new StreamWriter(outputFileName, false))
            {
                Program.input = input;
                Program.output = output;

                Console.WriteLine("Solving problem...");

                Solve();
                output.Flush();

                Console.WriteLine("Problem solved.");
            }
        }

        static int ReadInt()
        {
            return Int32.Parse(input.ReadLine());
        }

        static string[] ReadTokens()
        {
            return input.ReadLine().Split(' ');
        }

        static int[] ReadInts()
        {
            string[] tokens = ReadTokens();
            int[] result = new int[tokens.Length];

            for (int AX = 0; AX < tokens.Length; AX++)
                result[AX] = Int32.Parse(tokens[AX]);

            return result;
        }

        static void Respond(int AX, string text)
        {
            output.WriteLine("Case #" + (AX + 1).ToString() + ": " + text);
        }

        static double Pyth(double a, double b)
        {
            return Math.Sqrt(a * a + b * b);
        }

        #endregion

        static void Solve()
        {
            int n = ReadInt();

            for (int AX = 0; AX < n; AX++)
            {
                Console.WriteLine(AX.ToString());

                int k = ReadInt();
                int[] cs = ReadInts();

                int[] p = new int[k];

                int cp = 0;

                for (int BX = 1; BX <=k; BX++)
                {
                    int CX = 0;

                    while (CX < BX)
                    {
                        if (p[cp] == 0)
                            CX++;

                        if (CX == BX)
                            p[cp] = BX;

                        cp = (cp + 1) % k;
                    }
                }

                string res = "";

                for (int BX = 0; BX < cs[0]; BX++)
                    res += p[cs[BX + 1] - 1].ToString() + " ";

                Respond(AX, res);
            }
        }
    }
}

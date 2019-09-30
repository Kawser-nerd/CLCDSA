using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
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

        static Int64[] ReadInt64s()
        {
            string[] tokens = ReadTokens();
            Int64[] result = new Int64[tokens.Length];

            for (int AX = 0; AX < tokens.Length; AX++)
                result[AX] = Int64.Parse(tokens[AX]);

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
                Int64[] pars = ReadInt64s();

                List<Int64> xs = new List<Int64>();
                List<Int64> ys = new List<Int64>();

                Int64 cx = pars[5];
                Int64 cy = pars[6];

                xs.Add(cx);
                ys.Add(cy);

                for (int BX = 0; BX < pars[0] - 1; BX++)
                {
                    cx = (cx * pars[1] + pars[2]) % pars[7];
                    cy = (cy * pars[3] + pars[4]) % pars[7];

                    xs.Add(cx);
                    ys.Add(cy);
                }

                int found = 0;

                /*while (Find(xs, ys))
                    found++;*/

                for (int CX = 0; CX < xs.Count; CX++)
                    for (int DX = CX + 1; DX < xs.Count; DX++)
                        for (int EX = DX + 1; EX < xs.Count; EX++)
                        {
                            if (((xs[CX] + xs[DX] + xs[EX]) % 3 == 0) && ((ys[CX] + ys[DX] + ys[EX]) % 3) == 0)
                            {
                                found++;
                            }
                        }

                Respond(AX, found.ToString());
            }
        }

        static bool Find(List<Int64> xs, List<Int64> ys)
        {
            for (int CX = 0; CX < xs.Count; CX++)
                for (int DX = CX + 1; DX < xs.Count; DX++)
                    for (int EX = DX + 1; EX < xs.Count; EX++)
                    {
                        if (((xs[CX] + xs[DX] + xs[EX]) % 3 == 0) && ((ys[CX] + ys[DX] + ys[EX]) % 3) == 0)
                        {
                            DX--;
                            EX -= 2;

                            xs.RemoveAt(CX);
                            xs.RemoveAt(DX);
                            xs.RemoveAt(EX);
                            ys.RemoveAt(CX);
                            ys.RemoveAt(DX);
                            ys.RemoveAt(EX);

                            return true;
                        }
                    }

            return false;
        }
    }
}

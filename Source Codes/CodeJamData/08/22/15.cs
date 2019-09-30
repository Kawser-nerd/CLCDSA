using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace B
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

        static long cp;

        static long NextPrime()
        {
            while (true)
            {
                cp++;
                bool isPrime = true;

                for (int BX = 2; BX <= Math.Sqrt(cp); BX++)
                    if (cp % BX == 0)
                    {
                        isPrime = false;
                        break;
                    }

                if (isPrime)
                    return cp;
            }
        }

        static void Solve()
        {
            int n = ReadInt();

            for (int AX = 0; AX < n; AX++)
            {
                Int64[] pars = ReadInt64s();

                cp = pars[2] - 1;

                List<List<Int64>> sets = new List<List<long>>();

                for (long BX = pars[0]; BX <= pars[1]; BX++)
                {
                    List<long> l = new List<long>();
                    l.Add(BX);
                    sets.Add(l);
                }

                while (cp <= pars[1])
                {
                    NextPrime();

                    for (int BX = 0; BX < sets.Count; BX++)
                    {
                        if (sets[BX].Any(i => i % cp == 0))
                        {
                            for (int CX = BX + 1; CX < sets.Count; CX++)
                            {
                                if (sets[CX].Any(i => i % cp == 0))
                                {
                                    sets[BX].AddRange(sets[CX]);
                                    sets.RemoveAt(CX);

                                    CX--;
                                }
                            }
                        }
                    }
                }


                Respond(AX, sets.Count.ToString());
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Qualification
{
    class ProblemA
    {

        public ProblemA()
        {
        }


        public long SolveOne(long n, long A, long B, long C, long D, long x0, long y0, long M)
        {
            long[,] numTriangleTypes = new long[3, 3];

            long X, Y;
            X = x0;
            Y = y0;

            int i;

            for (i = 0; i < n; i++)
            {
                numTriangleTypes[X % 3, Y % 3]++;
                X = (A * X + B) % M;
                Y = (C * Y + D) % M;
            }

            long result = 0;

            int t1, t2, t3;
            long n1, n2, n3;
            for (t1 = 0; t1 <9 ; t1++)
                for (t2 = t1; t2 < 9; t2++)
                    for (t3 = t2; t3 < 9; t3++)
                    {
                        if (((t1 % 3) + (t2 % 3) + (t3 % 3)) % 3 != 0)
                            continue;
                        if (((t1 / 3) + (t2 / 3) + (t3 / 3)) % 3 != 0)
                            continue;
                        n1 = numTriangleTypes[t1 % 3, t1 / 3];
                        n2 = numTriangleTypes[t2 % 3, t2 / 3];
                        n3 = numTriangleTypes[t3 % 3, t3 / 3];
                        // count result increment
                        if (t1 != t2 && t1 != t3 && t2 != t3)
                        {
                            result += n1 * n2 * n3;
                            continue;
                        }

                        if (t1 == t2 && t2 == t3)
                        {
                            result += n1 * (n1 - 1) * (n1 - 2) / 6;
                            continue;
                        }
                        if (t1 == t2)
                        {
                            result += n3 * n1 * (n1 - 1) / 2;
                            continue;
                        }
                        if (t1 == t3)
                        {
                            result += n2 * n1 * (n1 - 1) / 2;
                            continue;
                        }
                        if (t2 == t3)
                        {
                            result += n1 * n2 * (n2 - 1) / 2;
                            continue;
                        }
                    }

            return result;
        }

        public void SolveAll(string inputFN, string outputFN)
        {
            StreamReader reader = new StreamReader(inputFN);
            StreamWriter writer = new StreamWriter(outputFN);

            int numberOfCases = int.Parse(reader.ReadLine());
            Console.Write("Number of cases = ");
            Console.WriteLine(numberOfCases);
            for (int i = 0; i < numberOfCases; i++)
            {
                long n, A, B, C, D, x0, y0, M;
                string[] data = reader.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                n = long.Parse(data[0]);
                A = long.Parse(data[1]);
                B = long.Parse(data[2]);
                C = long.Parse(data[3]);
                D = long.Parse(data[4]);
                x0 = long.Parse(data[5]);
                y0 = long.Parse(data[6]);
                M = long.Parse(data[7]);
                writer.Write("Case #");
                writer.Write(i + 1);
                writer.Write(": ");
                writer.WriteLine(SolveOne(n, A, B, C, D, x0, y0, M));

                Console.Write("Case ");
                Console.Write(i + 1);
                Console.WriteLine(" solved!");
            }

            writer.Close();
            reader.Close();
            
        }

        static void Main(string[] args)
        {
            ProblemA prA = new ProblemA();
            prA.SolveAll("A-small-attempt0.in", "A-small.out");
            Console.WriteLine("Finished!");
            Console.ReadLine();
        }
    }
}

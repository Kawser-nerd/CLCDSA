using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class A
{
    static void Main()
    {
        int T = ReadInt();
        for (int t = 1; t <= T; t++)
        {
            int[] tmp = ReadInts();
            int N = tmp[0];
            int[] judges = new int[N];
            Array.Copy(tmp, 1, judges, 0, N);
            double[] audience = new double[N];
            int[] order = Enumerable.Range(0, N).ToArray();
            Array.Sort(judges, order);
            int X = judges.Sum(), Y = 0;
            bool found = false;
            for (int i = 0; i < N; i++)
            {
                if (judges[i] * i - Y >= X)
                {
                    double z = (X + Y) / (double)i;
                    for (int j = 0; j < i; j++)
                    {
                        audience[j] = (z - judges[j]) / X;
                    }
                    found = true;
                    break;
                }
                else
                {
                    Y += judges[i];
                }
            }
            if (!found)
            {
                double z = 2.0 * X / N;
                for (int j = 0; j < N; j++)
                {
                    audience[j] = (z - judges[j]) / X;
                }
            }
            Console.Write("Case #{0}:", t);
            Array.Sort(order, audience);
            foreach (double d in audience)
            {
                Console.Write(" {0:0.000000}", d * 100);
            }

            Console.WriteLine();
        }
    }

    #region Library

    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }

    static decimal ReadDecimal()
    {
        return decimal.Parse(ReadLine());
    }

    static decimal[] ReadDecimals()
    {
        return Array.ConvertAll(ReadWords(), decimal.Parse);
    }

    #endregion
}

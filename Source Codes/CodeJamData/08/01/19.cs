using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2008.SavingTheUniverse
{
    class Program
    {
        const int INFINITY = 2000;

        static void Main(string[] args)
        {
            int time = System.Environment.TickCount;

            TextReader r = new StreamReader("input.txt");

            int N = int.Parse(r.ReadLine());

            for (int n = 1; n <= N; n++)
            {
                var dict = new Dictionary<string, int>();

                int S = int.Parse(r.ReadLine());

                for (int s = 0; s < S; s++)
                {
                    dict.Add(r.ReadLine(), s);
                }

                int[,] a = new int[S, S];

                for (int i = 0; i < S; i++)
                    for (int j = 0; j < S; j++)
                        a[i, j] = (i != j) ? 0 : INFINITY;


                int Q = int.Parse(r.ReadLine());
                while (Q-- > 0)
                {
                    string request = r.ReadLine();
                    int index = 0;

                    if (dict.TryGetValue(request, out index))
                    {
                        int minimum = INFINITY;
                        for (int i = 0; i < S; i++)
                            if (a[index, i] < minimum) minimum = a[index, i];

                        for (int i = 0; i < S; i++)
                            a[i, index] = (i != index) ? minimum + 1 : INFINITY;
                    }
                }

                int optimum = INFINITY;
                for (int i = 0; i < S; i++)
                    if (a[(i + 1) % S, i] < optimum) optimum = a[(i + 1) % S, i];

                Console.WriteLine("Case #{0}: {1}", n, optimum);
            }

            r.Close();

            //System.Threading.Thread.Sleep(100);

            Console.WriteLine("Time: {0}ms", (System.Environment.TickCount - time));
        }
    }
}

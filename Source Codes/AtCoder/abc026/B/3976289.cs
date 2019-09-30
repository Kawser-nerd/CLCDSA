using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // ????n???
            int n = int.Parse(input);

            // ????
            int[] r = new int[n];

            for(int i = 0; i < n; i++)
            {
                r[i] = int.Parse(Console.ReadLine());
            }

            // ???????????
            Array.Sort(r);
            Array.Reverse(r);

            // ???????????
            double total = 0.0;
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    total += r[i] * r[i];
                }
                else
                {
                    total -= r[i] * r[i];
                }
            }
            double s = total * Math.PI;

            // ???????
            Console.WriteLine(s);
        }
    }
}
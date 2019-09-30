using System;

namespace ABC058B
{
    class Program
    {
        static void Main(string[] args)
        {
            string O = Console.ReadLine();
            string E = Console.ReadLine();
            int curO = 0;
            int curE = 0;
            bool flag = false;

            while (curO < O.Length || curE < E.Length)
            {
                if (flag)
                {
                    Console.Write(E[curE]);
                    curE++;
                }
                else
                {
                    Console.Write(O[curO]);
                    curO++;
                }
                flag = !flag;
            }

            Console.WriteLine();
        }
    }
}
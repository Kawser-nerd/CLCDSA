using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Console.SetIn(new System.IO.StreamReader("in.txt"));
            Console.SetOut(new System.IO.StreamWriter("out.txt") { AutoFlush = true });

            int t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                var ss = Console.ReadLine().Split();
                int ac = int.Parse(ss[0]);
                int aj = int.Parse(ss[1]);

                int result = 0;
                var start = new int[ac + aj];
                var finish = new int[ac + aj];
                for (int j = 0; j < ac + aj; j++)
                {
                    ss = Console.ReadLine().Split();
                    start[j] = int.Parse(ss[0]);
                    finish[j] = int.Parse(ss[1]);
                }
                Array.Sort(start, finish);
                if (ac <= 1 && aj <= 1)
                    result = 2;
                else if (finish[1] - start[0] <= 720 || finish[0] + 1440 - start[1] <= 720)
                    result = 2;
                else result = 4;
                Console.WriteLine($"Case #{i + 1}: {result}");
            }
        }
    }
}
using System;
using System.Linq;

namespace arc047_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            string s = Console.ReadLine();
            int tabu = 1;
            int kurasyu = 0;
            for (int i = 0; i < x[0]; i++)
            {
                if (s[i] == '+')
                {
                    if (tabu == x[1])
                    {
                        kurasyu++;
                        tabu = 1;
                    }
                    else
                    {
                        tabu++;
                    }
                }
                else
                {
                    tabu--;
                }
            }
            Console.WriteLine(kurasyu);
        }
    }
}
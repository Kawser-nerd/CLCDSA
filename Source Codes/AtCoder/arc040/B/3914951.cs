using System;
using System.Linq;

namespace arc040_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            string s = Console.ReadLine(); bool[] ban = new bool[x[0]]; int last = -1;
            for (int i = 0; i < x[0]; i++)
            {
                ban[i] = s[i] == 'o';
                if (s[i] != 'o') last = i + 1;
            }
            int ret = 0;
            for (int i = 0; i <= last - x[1]; i++)
            {
                if (i != 0) ret++;
                if (!ban[i])
                {
                    ret++;
                    for (int j = 0; j < x[1]; j++) { ban[i + j] = true; }
                }
            }
            bool found = false;
            for (int i = 0; i < x[0]; i++)
                if (!ban[i]) found = true;
            if (found) ret++;
            Console.WriteLine(ret);
        }
    }
}
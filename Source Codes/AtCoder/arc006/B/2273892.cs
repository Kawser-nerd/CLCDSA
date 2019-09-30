using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_006_B
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
            char[,] grid = new char[n[1], n[0] * 2 - 1];
            for (int i = 0; i < n[1]; i++)
            {
                string u = Console.ReadLine();
                for (int j = 0; j < n[0] * 2 - 1; j++)
                {
                    grid[i, j] = u[j];
                }
            }
            string ansSTR = Console.ReadLine();
            int now = 0;
            for (int i = 0; i < ansSTR.Length; i += 2)
            {
                if (ansSTR[i] == 'o') { now = i; }
            }
            for (int i = n[1] - 1; i >= 0; i--)
            {
                if (now != n[0] * 2 - 2)
                {
                    if (grid[i, now + 1] == '-')
                    {
                        now += 2;
                        continue;
                    }
                }
                if (now != 0)
                {
                    if (grid[i, now - 1] == '-')
                    {
                        now -= 2;
                    }
                }
            }
            Console.WriteLine(now/2+1);
            Console.ReadLine();
        }
    }
}
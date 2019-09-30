using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc087_b
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split('T');
            int[] n = new int[s.Count()];
            for (int i = 0; i < s.Count(); i++) n[i] = s[i].Length;
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            x[0] -= n[0];
            int xmove = 0; bool[] canx = new bool[100000]; canx[0] = true;
            int ymove = 0; bool[] cany = new bool[100000]; cany[0] = true;
            for (int i = 1; i < s.Count(); i++)
            {
                if (i % 2 == 0)
                {
                    xmove += n[i];
                    for (int j = 9999; j >= 0; j--)
                    {
                        if (canx[j]) canx[j + n[i] * 2] = true;
                    }
                }
                else
                {
                    ymove += n[i];
                    for (int j = 9999; j >= 0; j--)
                    {
                        if (cany[j]) cany[j + n[i] * 2] = true;
                    }
                }
            }
            Console.WriteLine(x[0] + xmove >= 0 && x[1] + ymove >= 0 && canx[x[0] + xmove] && cany[x[1] + ymove] ? "Yes" : "No");
        }
    }
}
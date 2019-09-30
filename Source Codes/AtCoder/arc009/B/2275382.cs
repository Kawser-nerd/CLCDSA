using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_009_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var vB = Console.ReadLine().Split().Select(int.Parse).ToArray();
           var n = int.Parse(Console.ReadLine());
            var Before = new int[n];
            for (int i = 0; i < n; i++)
            {
                string y = Console.ReadLine();
                string u = "";
                for (int i1 = 0; i1 < y.Length; i1++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if (y[i1].ToString() == vB[j].ToString())
                        {
                            u += j.ToString();
                        }
                    }
                }
                Before[i] = int.Parse(u);
            }
            Array.Sort(Before);
            for (int i = 0; i < Before.Length; i++)
            {
                string s = Before[i].ToString();
                for (int j = 0; j < s.Length; j++)
                {
                    Console.Write(vB[int.Parse(s[j].ToString())]);
                }
                Console.WriteLine();
            }
            Console.ReadLine();
        }
    }
}
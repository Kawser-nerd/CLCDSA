using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ08_1A_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int n = int.Parse(Console.ReadLine());
                List<int> v1 = new List<int>();
                List<int> v2 = new List<int>();

                string[] ss = Console.ReadLine().Split(' ');
                foreach (string s in ss) v1.Add(int.Parse(s));

                ss = Console.ReadLine().Split(' ');
                foreach (string s in ss) v2.Add(int.Parse(s));

                v1.Sort();
                v2.Sort();
                v2.Reverse();

                long x = 0;
                for (int j = 0; j < n; j++) x += (long)v1[j] * (long)v2[j];
                
                Console.WriteLine("Case #{0}: {1}", i, x);
            }
        }
    }
}

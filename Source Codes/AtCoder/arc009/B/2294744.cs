using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc009_2
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] x = Console.ReadLine().Split();
            int n = int.Parse(Console.ReadLine());
            string[] ret = new string[n]; int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                string s = Console.ReadLine();
                ret[i] = s;
                for (int j = 0; j < s.Length; j++)
                {
                    a[i] = a[i] * 10 + Array.IndexOf(x,s[j].ToString());
                }
            }
            Array.Sort(a,ret);
            foreach (var item in ret) Console.WriteLine(item);
        }
    }
}
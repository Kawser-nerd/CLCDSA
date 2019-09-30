using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC61_C
{
    class Program
    {
        static void Main(string[] args)
        {

            var s = Console.ReadLine();
            int n = s.Length - 1;
            var bits = new List<string>();
            for (int i = 0; i < Math.Pow(2, n); i++)
            {
                bits.Add(Convert.ToString(i, 2).PadLeft(n, '0'));
            }
            long sum = 0;
            for (int i = 0; i < bits.Count; i++)
            {
                string p = "";
                for (int j = 0; j < s.Length; j++)
                {
                    p += s[j];
                    if (j != s.Length -1 && bits[i][j] == '1')
                    {
                        p += '+';
                    }
                }
  
                sum += p.Split('+').Select(long.Parse).Sum();
            }

            Console.WriteLine(sum);
        }
    }
}
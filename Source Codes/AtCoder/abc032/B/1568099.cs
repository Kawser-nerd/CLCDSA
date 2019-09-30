using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            String s = Console.ReadLine();
            int k = int.Parse(Console.ReadLine());
            if (s.Length < k)
            {
                Console.WriteLine("0");
                return;
            }

            HashSet<String> hs = new HashSet<String>();

            for (int i = 0; i < s.Length - (k-1); i++)
            {
                hs.Add(s.Substring(i, k));
            }

            Console.WriteLine(hs.Count);

        }
    }
}
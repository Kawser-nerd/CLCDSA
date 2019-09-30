using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine();
            var a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            for (int i = 0; i < S.Length; i++)
            {
                for (int j = 0; j < a.Length; j++)
                {
                    if (i == a[j]) { Console.Write('"'); }
                }
                Console.Write(S[i]);
            }
            for (int j = 0; j < a.Length; j++)
            {
                if (S.Length == a[j]) { Console.Write('"'); }
            }
            Console.WriteLine();
        }
    }
}
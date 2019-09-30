using System;
using System.Collections.Generic;
using System.Linq;

namespace Paiza
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC103_B();
        }

        static void ABC103_B()
        {
            var S = Console.ReadLine().ToList();
            var T = Console.ReadLine();
            var len = S.Count;
            while (len > 0)
            {
                if (string.Join("", S) == T)
                {
                    Console.WriteLine("Yes");
                    return;
                }
                S.Insert(0, S.Last());
                S.RemoveAt(S.Count - 1);
                len--;
            }
            Console.WriteLine("No");
        }
    }
}
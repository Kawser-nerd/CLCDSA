using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC114_B();
        }

        static void ABC114_B()
        {
            var S = Console.ReadLine();
            var list = new List<int>();
            for (var i = 0; i < S.Length - 2; i++)
                list.Add(int.Parse($"{S[i]}{S[i + 1]}{S[i + 2]}"));
            Console.WriteLine(list.Select(x => Math.Abs(753 - x)).Min());
        }
    }
}
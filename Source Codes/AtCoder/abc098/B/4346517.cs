using System;
using System.Linq;

namespace B.Cut_and_Count
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var S = Console.ReadLine();
            int cnt = 0;

            for (int i = 0; i < S.Length; i++)
            {
                var SA = S.Substring(0, S.Length - i).Distinct().ToArray();
                var SB = S.Substring(S.Length - i, i).Distinct().ToArray();

                cnt = Math.Max(cnt, SA.Count(x => SB.Contains(x)));
            }

            Console.WriteLine(cnt);
        }
    }
}
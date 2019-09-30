using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace ARC062_D
{
    class Program
    {
        static int ans;
        static void Main(string[] args)
        {
            var S = ReadLine();
            var N = S.Length;

            for (int i = 0; i < N; i++)
            {
                if (i % 2 == 0)
                {
                    if (S[i] == 'p') ans--;
                }
                else
                {
                    if (S[i] == 'g') ans++;
                }
            }
            Console.WriteLine(ans);
        }
    }
}
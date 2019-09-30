using System;
using System.Linq;

namespace ARC071_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var S = new string[n];
            var alphabet = "abcdefghijklmnopqrstuvwxyz";
            var alphabetcnt = new int[alphabet.Length][];

            for (int i = 0; i < alphabet.Length; i++)
            {
                alphabetcnt[i] = new int[n];
            }

            for (int i = 0; i < n; i++)
            {
                S[i] = Console.ReadLine();
                for (int a = 0; a < alphabet.Length; a++)
                {
                    alphabetcnt[a][i] = S[i].Where(x => x == alphabet[a]).Count();
                }
            }

            var result = "";
            for (int a = 0; a < alphabet.Length; a++)
            {
                result += new string(alphabet[a], alphabetcnt[a].Min());
            }

            Console.WriteLine(result);
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            var t = Console.ReadLine();
            var ss = "";
            var tt = "";
            for (char c = 'a'; c <= 'z'; c++)
            {
                for (int i = 0; i < s.Length; i++)
                {
                    if (s[i] == c) ss += c;
                }
            }
            for (char c = 'z'; c >= 'a'; c--)
            {
                for (int i = 0; i < t.Length; i++)
                {
                    if (t[i] == c) tt += c;
                }
            }

            var min = s.Length < t.Length ? s.Length : t.Length;

            for (int i = 0; i < min; i++)
            {
                if (ss[i] < tt[i])
                {
                    Console.WriteLine("Yes");
                    return;
                }else if (ss[i] > tt[i])
                {
                    Console.WriteLine("No");
                    return;
                }
            }

            Console.WriteLine(t.Length > s.Length ? "Yes" : "No");
        }
    }
}
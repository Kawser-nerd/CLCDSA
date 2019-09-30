using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Read();
            var T = Read();
            var ans = new string('z', S.Length);

            for (int i = 0; i <= S.Length - T.Length; i++)
            {
                var tmp = "";
                for (int j = 0; j < S.Length; j++)
                {
                    if (j >= i && j < i + T.Length)
                    {
                        if (S[j] == '?')
                        {
                            tmp += T[j - i];
                        }
                        else if (S[j] == T[j - i])
                        {
                            tmp += S[j];
                        }
                        else
                        {
                            tmp = new string('z', S.Length);
                            break;
                        }
                    }
                    else
                    {
                        if (S[j] == '?') tmp += "a";
                        else tmp += S[j];
                    }
                }
                if (tmp.CompareTo(ans) == -1) ans = tmp;
            }

            Console.WriteLine(ans != new string('z', S.Length) ? ans : "UNRESTORABLE");
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}
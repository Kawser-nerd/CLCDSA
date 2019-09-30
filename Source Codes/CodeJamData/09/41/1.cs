using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ASmall
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            int tst = Console.ReadLine().ToInt();
            for (int cas = 1; cas < tst + 1; cas++)
            {
                int N = Console.ReadLine().ToInt();
                string[] s = new string[N];
                for (int i = 0; i < N; i++)
                {
                    s[i] = Console.ReadLine().Trim();
                }
                int res = 0;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N-i; j++)
                    {
                        bool flag = true;
                        for (int k = i+1; k < N; k++)
                        {
                            if (s[j][k]=='1')
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                        {
                            res += j;
                            List<string> l = new List<string>();
                            for (int k = 0; k < N-i; k++)
                            {
                                if (k==j)
                                {
                                    continue;
                                }
                                l.Add(s[k]);
                            }
                            s = l.ToArray();
                            break;
                        }
                    }
                }
                Console.WriteLine("Case #" + cas + ": "+res);

            }
        }
    }

    internal static class Extensions
    {
        public static int ToInt(this string s)
        {
            return int.Parse(s);
        }

        public static int[] ToIntArray(this string s)
        {
            var tokens = s.Split(" \t".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            return tokens.Select(ob => ob.ToInt()).ToArray();
        }
    }


    
}

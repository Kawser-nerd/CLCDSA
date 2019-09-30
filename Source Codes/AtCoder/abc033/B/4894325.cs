using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using static System.Console;

namespace AtCoder
{
    class AtCoderrrrrr
    {
        static void Main(string[] args)
        {
            int N = int.Parse(ReadLine());
            List<string> Sls = new List<string>();
            List<int> Pls = new List<int>();
            for (int i = 0; i < N; i++)
            {
                string[] s = ReadLine().Split(' ');
                Sls.Add(s[0]);
                Pls.Add(int.Parse(s[1]));
            }
            string ans = "atcoder";
            int hoge = Pls.Sum();
            for (int i = 0; i < N; i++)
            {
                if (hoge / 2 < Pls[i])
                {
                    ans = Sls[i];
                }
            }
            WriteLine(ans);
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{


    class Program
    {


        static void Main(string[] args)
        {

            int N = int.Parse(Console.ReadLine());
            string S = Console.ReadLine();

            int ans = 0;

            for(int i = 1; i < N; i++)
            {
                var left = new Dictionary<char, int>();
                var right = new Dictionary<char, int>();
                int cnt = 0;

                for(int j = 0; j < i; j++)
                {
                    if (!left.ContainsKey(S[j])) left[S[j]] = 1;
                }
                for(int j = i; j < N; j++)
                {
                    if (!right.ContainsKey(S[j])) right[S[j]] = 1;
                }

                foreach(var s in left)
                {
                    if (right.ContainsKey(s.Key)) cnt++;
                }

                if (ans < cnt) ans = cnt;

            }

            Console.WriteLine(ans);

        }
    }
}
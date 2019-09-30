using System;
using System.Collections.Generic;
using System.Linq;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            var dic = new Dictionary<string, int>();

            for(int i = 0; i < N; i++)
            {
                var S = Console.ReadLine();
                if (dic.ContainsKey(S))
                {
                    dic[S]++;
                }
                else
                {
                    dic[S] = 1;
                }
            }
            Console.WriteLine(dic.OrderByDescending(x => x.Value).First().Key);
        }
    }
}
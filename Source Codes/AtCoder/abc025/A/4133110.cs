using System;
using System.Collections.Generic;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string S = Console.ReadLine();
            char[] S2 = S.ToCharArray();
            int N = int.Parse(Console.ReadLine());
            
            var list = new List<string> { };
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    list.Add(S2[i].ToString() + S2[j]);
                }
            }
            Console.WriteLine(list[N-1]);
        }
    }
}
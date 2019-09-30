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
            var dic_blue = new Dictionary<string, int>();
            for(int i = 0; i < N; i++)
            {
                string s = Console.ReadLine();
                if (dic_blue.ContainsKey(s)) dic_blue[s]++;
                else dic_blue[s] = 1;
            }
            int M = int.Parse(Console.ReadLine());
            var dic_red = new Dictionary<string, int>();
            for(int i = 0; i < M; i++)
            {
                string s = Console.ReadLine();
                if (dic_red.ContainsKey(s)) dic_red[s]++;
                else dic_red[s] = 1;
            }

            int point = 0;

            foreach(var s in dic_blue)
            {
                int p = s.Value;
                if (dic_red.ContainsKey(s.Key)) p -= dic_red[s.Key];
                if (point < p) point = p;
            }

            Console.WriteLine(point);

        }
    }
}
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
            var N = int.Parse(Console.ReadLine());
            var W = new Dictionary<string, int>();
            for(var i = 0; i < N; i++)
            {
                var s = Console.ReadLine();
                if (W.ContainsKey(s))
                {
                    W[s]++;
                }else
                {
                    W.Add(s, 1);
                }
            }
            var M = int.Parse(Console.ReadLine());
            for (var i = 0; i < M; i++)
            {
                var s = Console.ReadLine();
                if (W.ContainsKey(s))
                {
                    W[s]--;
                }
            }
            var ans = 0;
            foreach(var val in W.Values)
            {
                if (val > 0 && val > ans) ans = val;
            }

            Console.WriteLine(ans);
        }
    }
}
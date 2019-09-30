using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC081D
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var s1 = Console.ReadLine();
            var s2 = Console.ReadLine();

            List<int> state = new List<int>();
            for(int i = 0; i < N; i++)
            {
                if (s1[i] == s2[i])
                {
                    state.Add(1);
                    continue;
                }
                else
                {
                    state.Add(2);
                    i++;
                    continue;
                }
            }

            long div = 1000000007;
            long ans = 0;
            if (state[0] == 1) ans = 3;
            else ans = 6;
            for(int i = 1; i < state.Count; i++)
            {
                if (state[i - 1] == 1)
                {
                    ans = ans * 2;
                }
                else
                {
                    if (state[i] == 2) ans = ans * 3;
                }
                ans %= div;
            }

            Console.WriteLine(ans);
            Console.ReadKey();
        }
    }
}
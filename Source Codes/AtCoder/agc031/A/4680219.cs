using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CG031A3
{
    class Program
    {
        static void Main(string[] args)
        {
            // ?????
            int N = int.Parse(Console.ReadLine());
            // ???
            string S = Console.ReadLine();
            //?????????????????????
            Dictionary<string, int> dict = new Dictionary<string, int>();
            for (int i = 0; i < S.Length; i++)
            {
                string alpha = S.Substring(i, 1);
                if (dict.ContainsKey(alpha))
                {
                    dict[alpha]++;
                }
                else
                {
                    dict.Add(alpha, 1);
                }
            }
            ulong ans = 1;
            ulong seed = (ulong)Math.Pow(10, 9) + 7;
            foreach(KeyValuePair<string,int> member in dict)
            {
                ans = ans%seed *(ulong) (member.Value + 1)%seed;
            }
            Console.WriteLine((ans-1)%seed);
        }
    }
}
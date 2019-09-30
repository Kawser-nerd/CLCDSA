using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C089
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<char> list = new List<char>();
            List<char> march = new List<char>{ 'M', 'A', 'R', 'C', 'H' };
            for (int i = 0; i < N; i++)
            {
                char c = Console.ReadLine()[0];
                if (march.Contains(c)) list.Add(c);
            }

            Dictionary<char, int> dic = list.ToLookup(x => x).ToDictionary(x => x.Key, x => x.Count());
            int[] cnt = dic.Values.ToArray();

            long count = 0;
            if (dic.Count <= 2)
            {
                count = 0;
            }
            else if (dic.Count == 3)
            {
                count = (long)cnt[0] * cnt[1] * cnt[2];
            }
            else if (dic.Count == 4)
            {
                count += (long)cnt[0] * cnt[1] * cnt[2];
                count += (long)cnt[1] * cnt[2] * cnt[3];
                count += (long)cnt[2] * cnt[3] * cnt[0];
                count += (long)cnt[3] * cnt[0] * cnt[1];
            }
            else
            {
                for(int i = 0; i < 5; i++)
                {
                    for(int j = i + 1; j < 5; j++)
                    {
                        for(int k = j + 1; k < 5; k++)
                        {
                            count += (long)cnt[i] * cnt[j] * cnt[k];
                        }
                    }
                }
            }
            Console.WriteLine(count);
        }
    }
}
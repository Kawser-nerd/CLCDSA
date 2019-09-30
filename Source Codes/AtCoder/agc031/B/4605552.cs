using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC031
{
    class B
    {
        static int _Mod = 1000000007;

        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<int> C = new List<int>();
            for (int i = 0; i < N; i++)
            {
                int c = int.Parse(Console.ReadLine());
                C.Add(c);
            }

            long[] counter = new long[N+1]; counter[0] = 1;
            //???????????
            Dictionary<int, int> dic = new Dictionary<int, int>();

            int kprev = 0;
            for(int i = 0; i < C.Count; i++)
            {
                int k = C[i];
                long count = counter[i];
                if (k != kprev)
                {
                    if (!dic.ContainsKey(k))
                    {
                        dic.Add(k, 0);
                    }
                    else
                    {
                        int index = dic[k];
                        count += counter[index]; count %= _Mod;
                    }
                }
                counter[i + 1] = count;
                dic[k] = i+1;

                kprev = k;
            }
            Console.WriteLine(counter[N]);
        }
    }
}